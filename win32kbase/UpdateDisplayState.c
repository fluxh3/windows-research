void __fastcall UpdateDisplayState(
        _MONITOR_DISPLAY_STATE PowerMonitorOff,
        POWER_MONITOR_REQUEST_REASON MonitorRequestReasonNearProximity,
        char a3)
{
  char v6; // bp
  __int64 gdwInAtomicOperation; // rcx
  char v8; // si
  LeaveEnterCrit *v9; // rcx
  _WIN32K_INPUT_MODE n2; // ecx
  __int128 v11; // [rsp+30h] [rbp-68h] BYREF
  _DWORD InputBuffer[3]; // [rsp+40h] [rbp-58h] BYREF
  char v13; // [rsp+4Ch] [rbp-4Ch]
  char v14; // [rsp+4Dh] [rbp-4Bh]
  char v15; // [rsp+4Eh] [rbp-4Ah]
  char v16; // [rsp+4Fh] [rbp-49h]

  gPowerDisplayState = gSessionId;
  dword_1C024D13C = (int)dword_1C024D140;
  LODWORD(dword_1C024D140) = PowerMonitorOff;
  qword_1C024D108 = ((((unsigned __int64)MEMORY[0xFFFFF78000000004] << 32)
                    * (unsigned __int128)(unsigned __int64)(MEMORY[0xFFFFF78000000320] << 8)) >> 64)
                  - qword_1C024D110;
  qword_1C024D110 = (((unsigned __int64)MEMORY[0xFFFFF78000000004] << 32)
                   * (unsigned __int128)(unsigned __int64)(MEMORY[0xFFFFF78000000320] << 8)) >> 64;
  if ( gProtocolType != 0 )
  {
    v6 = 0;
    word_1C024D144 = 0;
  }
  else
  {
    v6 = 1;
    word_1C024D144 = 1;
  }
  if ( PowerMonitorOff != PowerMonitorOff )
  {
    *(_DWORD *)gPowerTransitionsState = 1;
    qword_1C024D19C = 0;
  }
  else
  {
    *(_DWORD *)gPowerTransitionsState = 0;
    if ( MonitorRequestReasonNearProximity == MonitorRequestReasonGracePeriod )
    {
      LODWORD(qword_1C024D19C) = 1;
    }
    else
    {
      LODWORD(qword_1C024D19C) = 0;
      if ( MonitorRequestReasonNearProximity == MonitorRequestReasonNearProximity )
        SetProximityBlocking();
    }
  }
  gdwInAtomicOperation = (unsigned int)::gdwInAtomicOperation;
  if ( (_DWORD)::gdwInAtomicOperation != 0 && (gdwExtraInstrumentations & 1) != 0 )
    KeBugCheckEx(
      BugCheckCode: 0x160u,
      BugCheckParameter1: (unsigned int)::gdwInAtomicOperation,
      BugCheckParameter2: 0,
      BugCheckParameter3: 0,
      BugCheckParameter4: 0);
  if ( PowerMonitorOff == PowerMonitorOff && gPowerAdaptiveState == 0 )
  {
    gPowerAdaptiveState = 1;
    PowerInputEvent(a1: 0);
  }
  UserSessionSwitchLeaveCrit(a1: gdwInAtomicOperation);
  if ( gbTtmEnabled == 0
    && (unsigned int)(PowerMonitorOff - 1) > 1
    && (PowerMonitorOff != PowerMonitorOff
     || MonitorRequestReasonNearProximity == MonitorRequestReasonGracePeriod
     || MonitorRequestReasonNearProximity == MonitorRequestReasonNearProximity) )
  {
    v8 = 0;
  }
  else
  {
    v8 = 1;
    if ( PowerMonitorOff != PowerMonitorDim )
    {
      v11 = 0;
      xxxSendWinlogonPowerMessage(a1: 0, a2: 261 - (unsigned int)(PowerMonitorOff != PowerMonitorOff), a3: &v11);
    }
  }
  InputBuffer[0] = gSessionId;
  InputBuffer[1] = PowerMonitorOff;
  InputBuffer[2] = MonitorRequestReasonNearProximity;
  v13 = v6;
  v14 = v8;
  v15 = a3;
  if ( *(_DWORD *)gPowerTransitionsState != 0
    || (_DWORD)qword_1C024D19C != 0
    || (v16 = 0, HIDWORD(qword_1C024D19C) != 0) )
  {
    v16 = 1;
  }
  ZwPowerInformation(
    InformationLevel: SessionDisplayState,
    InputBuffer,
    InputBufferLength: 0x10u,
    OutputBuffer: nullptr,
    OutputBufferLength: 0);
  if ( gSystemIsAoAc != 0 )
  {
    if ( (*(_DWORD *)gPowerTransitionsState != 0 || qword_1C024D19C != 0) && HIDWORD(qword_1C024D19C) == 0 )
      n2 = 0;
    else
      n2 = 2;
    SetInputMode(n2);
  }
  LeaveEnterCrit::~LeaveEnterCrit(this: v9);
  EtwTraceDisplayChange();
  CitDisplayPowerChange(p_gPowerDisplayState: &gPowerDisplayState);
}
