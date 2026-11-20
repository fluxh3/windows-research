__int64 __fastcall NtUserSetMouseInputRateLimitingTimer(__int64 n0x4E20)
{
  unsigned int n0x4E20_1; // r15d
  __int64 v2; // rsi
  __int64 v3; // rcx
  LARGE_INTEGER *CurrentThreadWin32Thread; // rbx
  __int64 v5; // rax
  struct tagTHREADINFO *gptiTSRequest; // rbx
  struct tagTHREADINFO **v7; // rax
  PVOID CurrentProcess; // rax
  unsigned int n6; // r8d
  __int64 v10; // rax
  int ProcessSessionId; // ebx
  __int64 CurrentThreadProcess; // rax
  struct _KTHREAD *CurrentThread; // rdi
  __int64 v14; // rbx
  __int64 *ThreadWin32Thread; // rax
  __int64 CurrentProcessWin32Process; // rax
  __int64 v17; // rcx
  __int64 *DomainLockRef; // rbx
  __int64 v19; // rcx
  __int64 v20; // rcx
  struct tagKERNELHANDLETABLEENTRY *`?gpducstulHead@@3PEAUtagKERNELHANDLETABLEENTRY@@EA`; // r14
  __int64 v22; // rax
  __int64 v23; // rcx
  __int64 *`?gDomainDummyLock@@3UtagDomLock@@A`; // rdi
  PVOID `?g_pepDwm@@3PEAU_EPROCESS@@EA`; // rax
  __int64 n5; // rcx
  unsigned int v27; // ebx
  __int64 v28; // rcx
  int v30; // [rsp+38h] [rbp-89h] BYREF
  int v31; // [rsp+3Ch] [rbp-85h] BYREF
  int v32; // [rsp+40h] [rbp-81h] BYREF
  unsigned int n0x4E20_2; // [rsp+44h] [rbp-7Dh]
  __int64 v34; // [rsp+48h] [rbp-79h]
  unsigned __int8 v35; // [rsp+50h] [rbp-71h]
  GUID ActivityId; // [rsp+54h] [rbp-6Dh] BYREF
  struct _EVENT_DATA_DESCRIPTOR v37; // [rsp+68h] [rbp-59h] BYREF
  int *v38; // [rsp+88h] [rbp-39h]
  __int64 n4; // [rsp+90h] [rbp-31h]
  struct _EVENT_DATA_DESCRIPTOR v40; // [rsp+98h] [rbp-29h] BYREF
  int *v41; // [rsp+B8h] [rbp-9h]
  __int64 n4_1; // [rsp+C0h] [rbp-1h]
  struct _EVENT_DATA_DESCRIPTOR v43; // [rsp+C8h] [rbp+7h] BYREF
  int *v44; // [rsp+E8h] [rbp+27h]
  __int64 n4_2; // [rsp+F0h] [rbp+2Fh]

  n0x4E20_1 = n0x4E20;
  n0x4E20_2 = n0x4E20;
  v2 = 0;
  CurrentThreadWin32Thread = (LARGE_INTEGER *)PsGetCurrentThreadWin32Thread(a1: n0x4E20);
  if ( CurrentThreadWin32Thread != nullptr )
    CurrentThreadWin32Thread[1] = KeQueryPerformanceCounter(PerformanceFrequency: nullptr);
  ActivityId = 0;
  if ( InputTraceLogging::Perf::s_userCritLoggingEnabled )
  {
    v35 = 1;
    v5 = PsGetCurrentThreadWin32Thread(a1: v3);
    v34 = v5;
    if ( v5 != 0 && (*(int *)(v5 + 24) > 0 || *(_DWORD *)(v34 + 48) != 0) )
    {
      EtwActivityIdControl(ControlCode: 3u, &ActivityId);
      if ( ::n6 > 6u && (unsigned __int8)tlgKeywordOn(a1: &::n6, a2: 0x2000) != 0 )
      {
        v30 = v35;
        n4 = 4;
        v38 = &v30;
        tlgWriteTransfer_EtwWriteTransfer(
          a1: (int)&::n6,
          a2: (int)&byte_1C0213E87,
          a3: (int)&ActivityId,
          a4: 0,
          a5: 3u,
          a6: &v37);
      }
    }
  }
  else
  {
    v34 = 0;
  }
  gptiTSRequest = nullptr;
  while ( 1 )
  {
    v7 = (struct tagTHREADINFO **)ExEnterCriticalRegionAndAcquireResourceExclusive(Resource: gpresUser);
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
    ++gcDITHitTestWaiters;
    ExReleaseResourceAndLeaveCriticalRegion(Resource: gpresUser);
    KeWaitForSingleObject(
      Object: gpsemDITHitTestWaiters,
      WaitReason: UserRequest,
      WaitMode: 0,
      Alertable: 0,
      Timeout: nullptr);
  }
  if ( InputTraceLogging::Perf::s_userCritLoggingEnabled
    && v34 != 0
    && (*(_DWORD *)(v34 + 48) != 0 || *(int *)(v34 + 24) > 0) )
  {
    *(_DWORD *)(v34 + 44) = 1;
    *(GUID *)(v34 + 28) = ActivityId;
    if ( ::n6 > 6u )
    {
      if ( (unsigned __int8)tlgKeywordOn(a1: &::n6, a2: 0x2000) != 0 )
      {
        v31 = v35;
        n4_1 = 4;
        v41 = &v31;
        tlgWriteTransfer_EtwWriteTransfer(
          a1: (int)&::n6,
          a2: (int)&unk_1C0213E30,
          a3: (int)&ActivityId,
          a4: 0,
          a5: 3u,
          a6: &v40);
        n6 = ::n6;
      }
      if ( n6 > 6 && (unsigned __int8)tlgKeywordOn(a1: &::n6, a2: 0x2000) != 0 )
      {
        v32 = v35;
        n4_2 = 4;
        v44 = &v32;
        tlgWriteTransfer_EtwWriteTransfer(
          a1: (int)&::n6,
          a2: (int)&byte_1C0213E5D,
          a3: (int)&ActivityId,
          a4: 0,
          a5: 3u,
          a6: &v43);
      }
    }
  }
  EtwTraceAcquiredExclusiveUserCrit();
  gptiCurrent = gptiTSRequest;
  gbValidateHandleForIL = 1;
  if ( (unsigned __int8)KeIsAttachedProcess() == 0
    || (v10 = PsGetCurrentProcess(),
        ProcessSessionId = PsGetProcessSessionIdEx(a1: v10),
        CurrentThreadProcess = PsGetCurrentThreadProcess(),
        ProcessSessionId == (unsigned int)PsGetProcessSessionIdEx(a1: CurrentThreadProcess)) )
  {
    CurrentThread = KeGetCurrentThread();
    v14 = 0;
    if ( (unsigned int)IsThreadCrossSessionAttached() == 0 )
    {
      ThreadWin32Thread = (__int64 *)PsGetThreadWin32Thread(a1: CurrentThread);
      if ( ThreadWin32Thread != nullptr )
        v14 = *ThreadWin32Thread;
    }
    CurrentProcessWin32Process = PsGetCurrentProcessWin32Process();
    if ( v14 != 0
      && CurrentProcessWin32Process != 0
      && (*(_DWORD *)(v14 + 480) & 0x1000000) != 0
      && (*(_DWORD *)(v14 + 1224) & 0x80u) == 0
      && (*(_DWORD *)(CurrentProcessWin32Process + 12) & 0x8000) != 0 )
    {
      DomainLockRef = (__int64 *)GetDomainLockRef(a1: (DomainLockType)12);
      if ( DomainLockRef == gDomainDummyLock )
        MicrosoftTelemetryAssertTriggeredNoArgsKM(a1: v17);
      if ( ExIsResourceAcquiredExclusiveLite(Resource: (PERESOURCE)*DomainLockRef) == 1 )
        MicrosoftTelemetryAssertTriggeredNoArgsKM(a1: v19);
      ExEnterCriticalRegionAndAcquireResourceExclusive(Resource: (PERESOURCE)*DomainLockRef);
      `?gpducstulHead@@3PEAUtagKERNELHANDLETABLEENTRY@@EA` = gpducstulHead;
      if ( gpducstulHead != nullptr )
      {
        do
        {
          gpducstulHead = *((struct tagKERNELHANDLETABLEENTRY **)`?gpducstulHead@@3PEAUtagKERNELHANDLETABLEENTRY@@EA` + 2);
          v22 = *(_QWORD *)`?gpducstulHead@@3PEAUtagKERNELHANDLETABLEENTRY@@EA`;
          *((_QWORD *)`?gpducstulHead@@3PEAUtagKERNELHANDLETABLEENTRY@@EA` + 2) = 0;
          if ( *(_DWORD *)(v22 + 8) == 0 )
            MicrosoftTelemetryAssertTriggeredNoArgsKM(a1: v20);
          `?gDomainDummyLock@@3UtagDomLock@@A` = (__int64 *)GetDomainLockRef(a1: (DomainLockType)12);
          if ( `?gDomainDummyLock@@3UtagDomLock@@A` == gDomainDummyLock )
            MicrosoftTelemetryAssertTriggeredNoArgsKM(a1: v23);
          ExReleaseResourceAndLeaveCriticalRegion(Resource: (PERESOURCE)*`?gDomainDummyLock@@3UtagDomLock@@A`);
          HMUnlockObject(a1: *(_QWORD *)`?gpducstulHead@@3PEAUtagKERNELHANDLETABLEENTRY@@EA`);
          tagDomLock::LockExclusive(this: (PERESOURCE *)`?gDomainDummyLock@@3UtagDomLock@@A`);
          `?gpducstulHead@@3PEAUtagKERNELHANDLETABLEENTRY@@EA` = gpducstulHead;
        }
        while ( gpducstulHead != nullptr );
        n0x4E20_1 = n0x4E20_2;
      }
      ExReleaseResourceAndLeaveCriticalRegion(Resource: (PERESOURCE)*DomainLockRef);
    }
  }
  `?g_pepDwm@@3PEAU_EPROCESS@@EA` = (PVOID)PsGetCurrentProcess();
  if ( `?g_pepDwm@@3PEAU_EPROCESS@@EA` == nullptr || `?g_pepDwm@@3PEAU_EPROCESS@@EA` != g_pepDwm )
  {
    n5 = 5;
    goto LABEL_59;
  }
  if ( n0x4E20_1 > 0x4E20 )
  {
    n5 = 87;
LABEL_59:
    UserSetLastError(a1: n5);
    goto LABEL_60;
  }
  v27 = ApiSetEditionSetMouseInputRateLimitingTimer(n0x4E20: n0x4E20_1);
  UserSetLastError(a1: v27);
  LOBYTE(v2) = (v27 & 0x80000000) == 0;
LABEL_60:
  UserSessionSwitchLeaveCrit(a1: v28);
  return v2;
}
