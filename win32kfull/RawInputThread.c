void __fastcall RawInputThread(__int64 *a1)
{
  __int64 RemoteContext; // r14
  __int64 v3; // rsi
  InkProcessor *v4; // rax
  InkProcessor *`?s_pInstance@InkProcessor@@0PEAV1@EA`; // rax
  __int64 ProcessWin32Process; // rax
  __int64 v7; // r8
  __int64 v8; // rdx
  struct _KTIMER *__imp_gptmrMaster; // rax
  struct _KEVENT *Object__1; // r8
  ULONG n2; // edi
  struct _KTHREAD *CurrentThread; // rcx
  struct _KEVENT *Event; // rcx
  NTSTATUS v14; // ebx
  unsigned int n2_1; // ebx
  bool v16; // zf
  CBaseInput **__imp_gpHidInput; // rcx
  char DigitizerFlags; // al
  char v19; // bl
  int n4_1; // ebx
  int __imp_gnRetryReadInput; // eax
  unsigned int n2_2; // ebx
  InteractiveControlManager *v23; // rbx
  const _GUID *v24; // r8
  const _GUID *v25; // r9
  int Settings; // eax
  const _GUID *v27; // r8
  const _GUID *v28; // r9
  int Settings_1; // ebx
  int v30; // edx
  const _GUID *v31; // r8
  const _GUID *v32; // r9
  unsigned int v33; // edx
  struct _KTIMER *__imp_gptmrWD; // rax
  const char *Mouse; // rax
  unsigned int v36; // edx
  PVOID *Object; // [rsp+28h] [rbp-E0h]
  LegacyInputDispatcher *v38; // [rsp+48h] [rbp-C0h] BYREF
  unsigned int v39[2]; // [rsp+50h] [rbp-B8h] BYREF
  HANDLE Handle; // [rsp+58h] [rbp-B0h] BYREF
  int v41; // [rsp+60h] [rbp-A8h] BYREF
  int Settings_2; // [rsp+64h] [rbp-A4h] BYREF
  int Settings_3; // [rsp+68h] [rbp-A0h] BYREF
  int v44; // [rsp+6Ch] [rbp-9Ch] BYREF
  PVOID Object_1; // [rsp+70h] [rbp-98h] BYREF
  PRKEVENT Object__2; // [rsp+78h] [rbp-90h]
  PVOID Object_; // [rsp+80h] [rbp-88h] BYREF
  const char *Mouse_1; // [rsp+88h] [rbp-80h] BYREF
  const struct _tlgProvider_t *v49; // [rsp+90h] [rbp-78h] BYREF
  const char *`InteractiveControlManager::GetExternalParameters entry`; // [rsp+98h] [rbp-70h] BYREF
  const char *`Function failed.`; // [rsp+A0h] [rbp-68h] BYREF
  const char *`InteractiveControlManager::GetExternalParameters exit`; // [rsp+A8h] [rbp-60h] BYREF
  __int64 n0x1000000; // [rsp+B0h] [rbp-58h] BYREF
  __m128i SystemInformation_1; // [rsp+B8h] [rbp-50h]
  struct _UNICODE_STRING DestinationString; // [rsp+C8h] [rbp-40h] BYREF
  __m128i SystemInformation; // [rsp+D8h] [rbp-30h] BYREF
  int n16; // [rsp+E8h] [rbp-20h]
  int v58; // [rsp+ECh] [rbp-1Ch]
  struct _UNICODE_STRING DestinationString_; // [rsp+F0h] [rbp-18h] BYREF
  PVOID v60[10]; // [rsp+108h] [rbp+0h] BYREF
  struct _EVENT_DATA_DESCRIPTOR v61; // [rsp+158h] [rbp+50h] BYREF
  int *v62; // [rsp+178h] [rbp+70h]
  __int64 n4; // [rsp+180h] [rbp+78h]

  DestinationString = 0;
  Handle = nullptr;
  Object__2 = nullptr;
  v58 = 0;
  v38 = nullptr;
  RemoteContext = GreGetRemoteContext();
  memset(a1: v60, Val: 0, Size: sizeof(v60));
  SetThreadName(a1: -2, a2: L"Win32k Raw Input Thread");
  v3 = *a1;
  SystemInformation_1.m128i_i64[0] = (__int64)PsGetThreadProcessId(Thread: KeGetCurrentThread());
  n16 = 16;
  SystemInformation_1.m128i_i64[1] = (__int64)PsGetThreadId(Thread: KeGetCurrentThread());
  SystemInformation = SystemInformation_1;
  ZwSetSystemInformation(
    SystemInformationClass: SystemThreadPriorityClientIdInformation,
    &SystemInformation,
    SystemInformationLength: 0x18u);
  RtlInitUnicodeString(&DestinationString, SourceString: L"WinSta0_RIT");
  EnterCrit(a1: 0, a2: 1);
  InitKeyboard();
  gdwPUDFlags &= ~0x1000u;
  gdwGTERMFlags &= ~1u;
  *(_DWORD *)(gpsi + 1972LL) = 0;
  *(_DWORD *)(gpsi + 2068LL) = 0;
  *(_DWORD *)(gpsi + 2196LL) = 0;
  UserSessionSwitchLeaveCrit();
  if ( InkProcessor::s_pInstance == nullptr )
  {
    v4 = (InkProcessor *)Win32AllocPoolZInit(a1: 112, a2: 1349217865);
    `?s_pInstance@InkProcessor@@0PEAV1@EA` = v4 != nullptr ? InkProcessor::InkProcessor(this: v4) : nullptr;
    InkProcessor::s_pInstance = `?s_pInstance@InkProcessor@@0PEAV1@EA`;
    if ( `?s_pInstance@InkProcessor@@0PEAV1@EA` == nullptr && (unsigned int)::n2 > 2 )
    {
      v41 = -1073741801;
      v62 = &v41;
      n4 = 4;
      tlgWriteTransfer_EtwWriteTransfer(a1: (int)&::n2, a2: (int)&dword_1C02F240C, a3: 0, a4: 0, a5: 3u, a6: &v61);
    }
  }
  if ( (int)InitSystemThread(a1: &DestinationString) < 0 )
    goto LABEL_145;
  v60[6] = CRitTimerScanWakeSystem::ritTimerScanWakeEvent;
  ProcessWin32Process = PsGetProcessWin32Process(a1: gpepCSRSS);
  *(_DWORD *)(ProcessWin32Process + 12) |= 0x40010u;
  v7 = *(_QWORD *)(GetDispInfo() + 96);
  *(_DWORD *)(gpsi + 4960LL) = *(_DWORD *)(*(_QWORD *)(v7 + 40) + 36LL) / 2;
  v8 = (unsigned int)(*(int *)(*(_QWORD *)(v7 + 40) + 40LL) >> 31);
  LODWORD(v8) = *(_DWORD *)(*(_QWORD *)(v7 + 40) + 40LL) % 2;
  *(_DWORD *)(gpsi + 4964LL) = *(_DWORD *)(*(_QWORD *)(v7 + 40) + 40LL) / 2;
  gptCursorAsync = *(tagPOINT *const *)(gpsi + 4960LL);
  ClearLogicalCursorPos(a1: gptCursorAsync, a2: v8);
  EnterCrit(a1: 0, a2: 1);
  TransitionCursorSuppressionState(a1: (enum CURSOR_SUPPRESSION_STATE)10);
  UserSessionSwitchLeaveCrit();
  EnterCrit(a1: 0, a2: 1);
  Object = (PVOID *)`<lambda_ee96b6502effcc67d9cd908cd78240cc>::<lambda_invoker_cdecl>`;
  RegisterCoreMsgProviderPreferences(a1: 15, a2: 3, a3: 1);
  if ( gSessionId != gServiceSessionId )
  {
    LODWORD(Object) = 0;
    RegisterHotKey(a1: (struct tagWND *)1, BugCheckParameter2: (ULONG_PTR)Object);
    SetDebugHotKeys();
    SetWinlogonHotKeys();
    SetWindowArrangementHotKeys();
    SetPenHotKeys();
  }
  CInputGlobals::UpdateLastInputTime(
    this: gpInputGlobals,
    a2: (((unsigned __int64)MEMORY[0xFFFFF78000000004] << 32)
   * (unsigned __int128)(unsigned __int64)(MEMORY[0xFFFFF78000000320] << 8)) >> 64,
    a3: (_LINP_SOURCE)14);
  UserSessionSwitchLeaveCrit();
  __imp_gptmrMaster = (struct _KTIMER *)Win32AllocPoolNonPaged(a1: 64, a2: 1951101781);
  gptmrMaster = __imp_gptmrMaster;
  if ( __imp_gptmrMaster == nullptr )
    goto LABEL_145;
  KeInitializeTimer(Timer: __imp_gptmrMaster);
  v60[2] = (PVOID)gptmrMaster;
  if ( gbNonServiceSession == 0 || gbFirstInteractiveSession != 0 )
  {
    __imp_gptmrWD = (struct _KTIMER *)Win32AllocPoolNonPaged(a1: 64, a2: 1951101781);
    gptmrWD = __imp_gptmrWD;
    if ( __imp_gptmrWD == nullptr )
      goto LABEL_145;
    KeInitializeTimerEx(Timer: __imp_gptmrWD, Type: SynchronizationTimer);
  }
  v60[4] = (PVOID)gptmrWD;
  if ( gProtocolType != 0
    && (unsigned int)DrvEscapeRemoteDrivers(
                       a1: *(_QWORD *)(gpDispInfo + 16LL),
                       a2: gProtocolType,
                       a3: *(_QWORD *)(RemoteContext + 40),
                       a4: 2,
                       a5: gptmrWD,
                       a6: 8) == 0 )
  {
    goto LABEL_145;
  }
  if ( gSessionId != gServiceSessionId && gProtocolType == 0 )
  {
    EnterCrit(a1: 0, a2: 1);
    GetWin32kDriverObject();
    UserSessionSwitchLeaveCrit();
  }
  if ( gSessionId == gServiceSessionId )
    gbFirstConnectionDone = 1;
  if ( gSessionId != 0 )
  {
    if ( CreateShutdownEvent(a1: L"EventShutDownCSRSS", a2: 0, a3: &Handle) < 0 )
      goto LABEL_145;
    Object_ = nullptr;
    ObReferenceObjectByHandle(
      Handle,
      DesiredAccess: 0x1F0003u,
      ObjectType: (POBJECT_TYPE)ExEventObjectType,
      AccessMode: 0,
      Object: &Object_,
      HandleInformation: nullptr);
    Object__1 = (struct _KEVENT *)Object_;
    n2 = 2;
    v60[8] = Object_;
    Object__2 = (PRKEVENT)Object_;
  }
  else
  {
    n2 = 1;
    if ( PoRequestShutdownEvent(Event: &v60[8]) < STATUS_SUCCESS )
      goto LABEL_145;
    Object__1 = (struct _KEVENT *)v60[8];
  }
  if ( gSessionId != gServiceSessionId )
  {
    CreatePointerDeviceProcessEvents();
    Object__1 = (struct _KEVENT *)v60[8];
  }
  if ( Object__1 != nullptr )
  {
    CurrentThread = KeGetCurrentThread();
    gpkeRITEvent = Object__1;
    gptiRit = W32GetThreadWin32Thread(a1: CurrentThread);
    gdwHydraHint |= 0x2000u;
    *(_DWORD *)(gptiRit + 480LL) |= 0x80u;
    Event = (struct _KEVENT *)a1[1];
    v60[0] = *(PVOID *)(gptiRit + 1408LL);
    KeSetEvent(Event, Increment: 1, Wait: 0);
    Object_1 = *(PVOID *)(v3 + 56);
    ObReferenceObjectByPointer(
      Object: Object_1,
      DesiredAccess: 0x1F0003u,
      ObjectType: (POBJECT_TYPE)ExEventObjectType,
      AccessMode: 0);
    do
      v14 = KeWaitForMultipleObjects(
              Count: n2,
              Object: &Object_1,
              WaitType: WaitAny,
              WaitReason: WrUserRequest,
              WaitMode: 0,
              Alertable: 0,
              Timeout: nullptr,
              WaitBlockArray: nullptr);
    while ( v14 == STATUS_WAIT_1 && (gdwRITWakeReason & 2) == 0 );
    ObfDereferenceObject(Object: Object_1);
    if ( v14 == STATUS_WAIT_1 && (gdwRITWakeReason & 2) != 0 )
    {
      KeSetEvent(Event: Object__2, Increment: 1, Wait: 0);
      InitiateWin32kCleanup();
      ObfDereferenceObject(Object: Object__2);
      if ( Handle != nullptr )
        ZwClose(Handle);
      KeSetEvent(Event: gpevtRitReadyForCallOut, Increment: 1, Wait: 0);
      CRitTimerScanWakeSystem::CleanupRitTimerScanWakeEvent();
      return;
    }
    if ( (unsigned int)GetRITWakeReason(a1: nullptr) != 0 )
      KeSetEvent(Event: gpkeRITEvent, Increment: 1, Wait: 0);
    EnterCrit(a1: 0, a2: 1);
    if ( *(_QWORD *)(gptiRit + 448LL) == 0 )
      xxxSwitchDesktop(
        a1: *(_QWORD *)(gptiRit + 608LL),
        a2: *(_QWORD *)(*(_QWORD *)(gptiRit + 608LL) + 16LL),
        a3: 0,
        a4: 0);
    KeSetEvent(Event: gpevtRitReadyForCallOut, Increment: 1, Wait: 0);
    if ( gSessionId == gServiceSessionId )
    {
      CBaseInput::InitializeSensor(this: gpHidInput);
      CBaseInput::InitializeSensor(this: gpKeyboardSensor);
    }
    else
    {
      if ( gProtocolType != 0 )
      {
        DestinationString_ = 0;
        RtlInitUnicodeString(DestinationString: &DestinationString_, SourceString: nullptr);
        n2_1 = 1;
        v16 = false;
        while ( v16 )
        {
          if ( (int)CBaseInput::InitializeSensor(this: gpHidInput) >= 0 )
          {
            __imp_gpHidInput = (CBaseInput **)gpHidInput;
LABEL_37:
            CBaseInput::Read(this: *__imp_gpHidInput);
          }
LABEL_38:
          v16 = ++n2_1 == 2;
          if ( n2_1 > 2 )
            goto LABEL_39;
        }
        if ( n2_1 != 1 || (int)CBaseInput::InitializeSensor(this: gpKeyboardSensor) < 0 )
          goto LABEL_38;
        CBaseInput::HandleTSRequest(this: gpKeyboardSensor, a2: (enum InputTSRequest)0);
        __imp_gpHidInput = (CBaseInput **)gpKeyboardSensor;
        goto LABEL_37;
      }
      xxxRegisterForDeviceClassNotifications();
LABEL_39:
      DigitizerFlags = _GetDigitizerFlags();
      if ( (DigitizerFlags & 0xD) != 0 && DigitizerFlags < 0 )
        RegisterTabletButtonHandler();
      InitTimerPowerSaving();
      gnRITdemonTimerId = SetRITTimer(a1: gnRITdemonTimerId, a2: 1000, a3: xxxHungAppDemon, a4: 0);
    }
    gbIsRITReady = 1;
    if ( (unsigned int)UserIsUserCritSecIn() != 0 )
    {
      v19 = 0;
    }
    else
    {
      v19 = 1;
      UserEnterUserCritSec();
    }
    if ( gcSynchronizeTimer != -1 )
      gidSynchronizeTimer = UserSetTimer();
    if ( v19 != 0 )
      UserLeaveUserCritSec();
    UserSessionSwitchLeaveCrit();
    LegacyInputDispatcher::Create(a1: &v38);
    LegacyInputDispatcher::Initialize(
      this: v38,
      a2: 0,
      a3: false,
      a4: 0x40u,
      a5: 5u,
      a6: (struct LegacyDispatcherObject *)v60);
    CBaseInput::RegisterDispatcherObject(this: gpKeyboardSensor, a2: v38);
    CBaseInput::RegisterDispatcherObject(this: gpHidInput, a2: v38);
    while ( 1 )
    {
LABEL_49:
      n4_1 = LegacyInputDispatcher::WaitAndDispatch(this: v38);
      if ( n4_1 == 0 )
      {
        EnterCrit(a1: 0, a2: 1);
        xxxRemoveQueueCompletion();
        UserSessionSwitchLeaveCrit();
      }
      if ( n4_1 == 4 )
        break;
      if ( n4_1 == 2 )
      {
        EnterCrit(a1: 0, a2: 1);
        if ( gProtocolType != 0 )
        {
          DrvEscapeRemoteDrivers(
            a1: *(_QWORD *)(gpDispInfo + 16LL),
            a2: gProtocolType,
            a3: *(_QWORD *)(RemoteContext + 40),
            a4: 1,
            a5: 0,
            a6: 0);
        }
        else if ( gfRemotingConsole != 0 && gConsoleShadowhDev != 0 )
        {
          HDXDrvEscape(a1: gConsoleShadowhDev, a2: 1, a3: 0, a4: 0);
        }
LABEL_144:
        UserSessionSwitchLeaveCrit();
      }
      else
      {
        if ( ((n4_1 - 1) & 0xFFFFFFFD) == 0 )
        {
          EnterCrit(a1: 0, a2: 1);
          TimersProc();
          UserSessionSwitchLeaveCrit();
          __imp_gnRetryReadInput = gnRetryReadInput_0;
          if ( gnRetryReadInput != gnRetryReadInput_0 )
            __imp_gnRetryReadInput = gnRetryReadInput;
          gnRetryReadInput_0 = __imp_gnRetryReadInput;
        }
        if ( gspwndAltTab != nullptr )
        {
          EnterCrit(a1: 0, a2: 1);
          while ( (*(_BYTE *)(*(_QWORD *)(gptiRit + 440LL) + 6LL) & 0x40) != 0 )
            xxxReceiveMessage(a1: gptiRit);
          goto LABEL_144;
        }
      }
    }
    v39[0] = 0;
    KeClearEvent(Event: gpkeRITEvent);
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            if ( (unsigned int)GetRITWakeReason(a1: v39) == 0 )
              goto LABEL_49;
            n2_2 = v39[0];
            if ( ::n4 > 4u && (qword_1C0331B40 & 2) != 0 && (qword_1C0331B48 & 2) == qword_1C0331B48 )
            {
              switch ( v39[0] )
              {
                case 1u:
                  Mouse = "Mouse";
                  break;
                case 2u:
                  Mouse = "Shutdown";
                  break;
                case 4u:
                  Mouse = "EnableMMCSS";
                  break;
                case 8u:
                  Mouse = "RitTakeover";
                  break;
                case 0x10u:
                  Mouse = "DitTakeover";
                  break;
                case 0x20u:
                  Mouse = "ConfigUpdate";
                  break;
                case 0x40u:
                  Mouse = "GetUserProfile";
                  break;
                case 0x80u:
                  Mouse = "DitInControl";
                  break;
                default:
                  Mouse = "UNKNOWN";
                  break;
              }
              Mouse_1 = Mouse;
              _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EtwWriteTransfer(_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),_GUID const *,_GUID const *>::Write<_tlgWrapSz<char>>(
                a1: (const struct _tlgProvider_t *)&::n4,
                a2: byte_1C02F0B13,
                a3: nullptr,
                a4: nullptr,
                a5: (const struct _tlgWrapSz<char> *)&Mouse_1);
            }
            if ( n2_2 != 1 )
              break;
            ProcessMouseEvent();
          }
          if ( n2_2 == 2 )
          {
            InitiateWin32kCleanup();
            if ( gSessionId != gServiceSessionId )
            {
              EnterCrit(a1: 0, a2: 1);
              gpkeRITEvent = nullptr;
              ObfDereferenceObject(Object: v60[8]);
              UserSessionSwitchLeaveCrit();
            }
            if ( Handle != nullptr )
              ZwClose(Handle);
            EnterCrit(a1: 0, a2: 1);
            CleanupSensorExplicitly(a1: 1);
            if ( gbDIT == 0 )
              CleanupSensorExplicitly(a1: 2);
            UserSessionSwitchLeaveCrit();
            CRitTimerScanWakeSystem::CleanupRitTimerScanWakeEvent();
            if ( v38 != nullptr )
              LegacyInputDispatcher::`scalar deleting destructor'(this: v38, a2: v33);
            return;
          }
          if ( n2_2 != 4 )
            break;
          xxxClientEnableMMCSS(a1: (*gpsi & 0x1000) != 0);
        }
        if ( n2_2 == 8 )
        {
          EnterCrit(a1: 0, a2: 1);
          RitTakeOver();
          CBaseInput::RegisterDispatcherObject(this: gpHidInput, a2: v38);
          goto LABEL_70;
        }
        if ( n2_2 != 16 )
          break;
        PrepareForMasterInputThreadTakingOver(a1: v38);
      }
      if ( n2_2 == 128 )
      {
        EnterCrit(a1: 0, a2: 1);
        ZwSetEvent(EventHandle: ghDITRITEvent, PreviousState: nullptr);
        goto LABEL_70;
      }
      if ( n2_2 == 32 )
        break;
      if ( n2_2 == 64 )
      {
        EnterCrit(a1: 0, a2: 1);
        CheckPointerDeviceConfiguration();
        v23 = InteractiveControlManager::Instance();
        if ( CallbackContext > 4u )
        {
          `InteractiveControlManager::GetExternalParameters entry` = "InteractiveControlManager::GetExternalParameters entry";
          v49 = *(const struct _tlgProvider_t **)(gptiCurrent + 488LL);
          _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EtwWriteTransfer(_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),_GUID const *,_GUID const *>::Write<_tlgWrapSz<char>,_tlgWrapBuffer<_UNICODE_STRING>>(
            a1: v49,
            a2: byte_1C02F3699,
            a3: v24,
            a4: v25,
            a5: (const struct _tlgWrapSz<char> *)&`InteractiveControlManager::GetExternalParameters entry`,
            a6: (const struct _tlgWrapBuffer<_UNICODE_STRING> *)&v49);
        }
        Settings = InteractiveControlSettings::ReadSettings(this: (InteractiveControlManager *)((char *)v23 + 84));
        Settings_1 = Settings;
        if ( Settings < 0 && CallbackContext > 2u )
        {
          Settings_2 = Settings;
          `Function failed.` = "Function failed.";
          _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EtwWriteTransfer(_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),_GUID const *,_GUID const *>::Write<_tlgWrapSz<char>,_tlgWrapperByVal<4>>(
            a1: (const struct _tlgProvider_t *)&CallbackContext,
            a2: &unk_1C02F35F0,
            a3: v27,
            a4: v28,
            a5: (const struct _tlgWrapSz<char> *)&`Function failed.`,
            a6: (const struct _tlgWrapperByVal<4> *)&Settings_2);
        }
        if ( CallbackContext > 4u )
        {
          Settings_3 = Settings_1;
          `InteractiveControlManager::GetExternalParameters exit` = "InteractiveControlManager::GetExternalParameters exit";
          _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EtwWriteTransfer(_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),_GUID const *,_GUID const *>::Write<_tlgWrapSz<char>,_tlgWrapperByVal<4>>(
            a1: (const struct _tlgProvider_t *)&CallbackContext,
            a2: byte_1C02F357D,
            a3: v27,
            a4: v28,
            a5: (const struct _tlgWrapSz<char> *)&`InteractiveControlManager::GetExternalParameters exit`,
            a6: (const struct _tlgWrapperByVal<4> *)&Settings_3);
        }
        v30 = *(_DWORD *)UPDWORDPointer(a1: 8220);
        if ( n5 > 5u
          && (qword_1C032C408 & 0x200000000000LL) != 0
          && (qword_1C032C410 & 0x200000000000LL) == qword_1C032C410 )
        {
          v44 = v30;
          n0x1000000 = 0x1000000;
          _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EtwWriteTransfer(_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),_GUID const *,_GUID const *>::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>>(
            a1: (const struct _tlgProvider_t *)&n5,
            a2: byte_1C02F29C9,
            a3: v31,
            a4: v32,
            a5: (const struct _tlgWrapperByVal<8> *)&n0x1000000,
            a6: (const struct _tlgWrapperByVal<4> *)&v44);
        }
LABEL_70:
        UserSessionSwitchLeaveCrit();
      }
    }
    EnterCrit(a1: 0, a2: 1);
    goto LABEL_70;
  }
LABEL_145:
  CRitTimerScanWakeSystem::CleanupRitTimerScanWakeEvent();
  if ( v38 != nullptr )
    LegacyInputDispatcher::`scalar deleting destructor'(this: v38, a2: v36);
  KeSetEvent(Event: (PRKEVENT)a1[1], Increment: 1, Wait: 0);
  KeSetEvent(Event: gpevtRitReadyForCallOut, Increment: 1, Wait: 0);
}
