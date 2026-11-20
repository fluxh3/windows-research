PVOID ReferenceDwmApiPort()
{
  PVOID `?g_pDwmApiPort@@3PEAXEA`; // rbx
  __int64 v2; // rcx
  __int64 v3; // rcx
  LARGE_INTEGER *CurrentThreadWin32Thread; // rbx
  __int64 v5; // rax
  struct tagTHREADINFO *gptiTSRequest; // rbx
  struct tagTHREADINFO **v7; // rax
  PVOID CurrentProcess; // rax
  __int64 v9; // rcx
  __int64 v10; // rsi
  LARGE_INTEGER PerformanceCounter; // rdi
  signed __int64 `?W32kEtwUserCritAcquireDelayTimeoutQPC@@3_JA`; // rbx
  UserCritTelemetry *Instance; // rax
  int v14; // ecx
  int v15; // r8d
  int v16; // [rsp+38h] [rbp-9h] BYREF
  __int64 v17; // [rsp+40h] [rbp-1h] BYREF
  unsigned __int8 v18; // [rsp+48h] [rbp+7h]
  GUID ActivityId; // [rsp+4Ch] [rbp+Bh] BYREF
  struct _EVENT_DATA_DESCRIPTOR v20; // [rsp+60h] [rbp+1Fh] BYREF
  int *v21; // [rsp+80h] [rbp+3Fh]
  int n4; // [rsp+88h] [rbp+47h]
  int v23; // [rsp+8Ch] [rbp+4Bh]

  if ( ExIsResourceAcquiredExclusiveLite(Resource: gpresUser) == 1
    || ExIsResourceAcquiredSharedLite(Resource: gpresUser) != 0 )
  {
    `?g_pDwmApiPort@@3PEAXEA` = g_pDwmApiPort;
    if ( g_pDwmApiPort != nullptr )
      ObfReferenceObject(Object: g_pDwmApiPort);
  }
  else
  {
    CurrentThreadWin32Thread = (LARGE_INTEGER *)PsGetCurrentThreadWin32Thread(a1: v2);
    if ( CurrentThreadWin32Thread != nullptr )
      CurrentThreadWin32Thread[1] = KeQueryPerformanceCounter(PerformanceFrequency: nullptr);
    ActivityId = 0;
    if ( InputTraceLogging::Perf::s_userCritLoggingEnabled )
    {
      v18 = 0;
      v5 = PsGetCurrentThreadWin32Thread(a1: v3);
      v17 = v5;
      if ( v5 != 0 && (*(int *)(v5 + 24) > 0 || *(_DWORD *)(v17 + 48) != 0) )
      {
        EtwActivityIdControl(ControlCode: 3u, &ActivityId);
        if ( n6 > 6u && (unsigned __int8)tlgKeywordOn(a1: &n6, a2: 0x2000) != 0 )
        {
          v23 = 0;
          v16 = v18;
          n4 = 4;
          v21 = &v16;
          tlgWriteTransfer_EtwWriteTransfer(
            a1: (int)&n6,
            a2: (int)&byte_1C0213E87,
            a3: (int)&ActivityId,
            a4: 0,
            a5: 3u,
            a6: &v20);
        }
      }
    }
    else
    {
      v17 = 0;
    }
    gptiTSRequest = nullptr;
    while ( 1 )
    {
      v7 = (struct tagTHREADINFO **)ExEnterCriticalRegionAndAcquireResourceShared(Resource: gpresUser);
      if ( v7 != nullptr )
        gptiTSRequest = *v7;
      CurrentProcess = (PVOID)PsGetCurrentProcess();
      if ( CurrentProcess != nullptr && CurrentProcess == g_pepDwm )
        break;
      if ( (PVOID)PsGetCurrentProcess() == gpepCSRSS && gptiTSRequest != (struct tagTHREADINFO *)::gptiTSRequest
        || gbDITInHitTest != 1
        || gptiTSRequest == gptiRit )
      {
        break;
      }
      _InterlockedIncrement(&gcDITHitTestWaiters);
      ExReleaseResourceAndLeaveCriticalRegion(Resource: gpresUser);
      KeWaitForSingleObject(
        Object: gpsemDITHitTestWaiters,
        WaitReason: UserRequest,
        WaitMode: 0,
        Alertable: 0,
        Timeout: nullptr);
    }
    InputTraceLogging::Perf::CritAcquire::~CritAcquire(this: (InputTraceLogging::Perf::CritAcquire *)&v17);
    v10 = PsGetCurrentThreadWin32Thread(a1: v9);
    if ( v10 != 0 )
    {
      PerformanceCounter = KeQueryPerformanceCounter(PerformanceFrequency: nullptr);
      `?W32kEtwUserCritAcquireDelayTimeoutQPC@@3_JA` = PerformanceCounter.QuadPart - *(_QWORD *)(v10 + 8);
      Instance = UserCritTelemetry::getInstance();
      UserCritTelemetry::UpdateUserCritInfo(
        this: Instance,
        a2: `?W32kEtwUserCritAcquireDelayTimeoutQPC@@3_JA`,
        a3: (enum UserCritTelemetry::BucketType)1);
      *(LARGE_INTEGER *)(v10 + 8) = PerformanceCounter;
      if ( (W32kEtwEnabledKeyword & 0x200000010000000LL) != 0
        && (unsigned __int8)(byte_1C0245748 - 1) > 2u
        && (qword_1C0245730 & 0x200000010000000LL) != 0
        && (qword_1C0245738 & 0x200000010000000LL) == qword_1C0245738
        && (Microsoft_Windows_Win32kEnableBits & 0x800000) != 0 )
      {
        McTemplateK0xqx_EtwWriteTransfer(
          a1: v14,
          a2: (unsigned int)AcquiredSharedUserCritEvent,
          a3: v15,
          a4: `?W32kEtwUserCritAcquireDelayTimeoutQPC@@3_JA`,
          a5: 0,
          a6: (char)gullUserCritAcquireToken);
      }
      if ( `?W32kEtwUserCritAcquireDelayTimeoutQPC@@3_JA` >= W32kEtwUserCritAcquireDelayTimeoutQPC
        && PerformanceCounter.QuadPart - W32KEtwUserCritAcquireDelayShLastTelemetryQPC >= W32KEtwUserCritTelemetryThrottleQPC )
      {
        if ( (Microsoft_Windows_Win32kEnableBits & 0x1000000000LL) != 0 )
          McTemplateK0xqx_EtwWriteTransfer(
            a1: (_DWORD)gullUserCritAcquireToken,
            a2: (unsigned int)AcquiredSharedUserCritTelemetryEvent,
            a3: v15,
            a4: `?W32kEtwUserCritAcquireDelayTimeoutQPC@@3_JA`,
            a5: 1000000 * `?W32kEtwUserCritAcquireDelayTimeoutQPC@@3_JA` / gliQpcFreq.QuadPart,
            a6: (char)gullUserCritAcquireToken);
        _InterlockedExchange64(&W32KEtwUserCritAcquireDelayShLastTelemetryQPC, PerformanceCounter.QuadPart);
      }
      *(_QWORD *)(v10 + 16) = _InterlockedIncrement64((volatile signed __int64 *)&gullUserCritAcquireToken);
    }
    `?g_pDwmApiPort@@3PEAXEA` = g_pDwmApiPort;
    if ( g_pDwmApiPort != nullptr )
      ObfReferenceObject(Object: g_pDwmApiPort);
    UserSessionSwitchLeaveCrit();
  }
  return `?g_pDwmApiPort@@3PEAXEA`;
}
