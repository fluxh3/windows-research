__int64 __fastcall SetMouseTrails(int a1)
{
  __int64 __imp_gProtocolType; // rax

  SetPointer(a1: 0);
  LODWORD(WPP_MAIN_CB.Dpc.SystemArgument1) = a1 != 0 ? a1 - 1 : 0;
  SetPointer(a1: 1);
  __imp_gProtocolType = gProtocolType;
  if ( gProtocolType == 0 )
  {
    __imp_gProtocolType = LODWORD(WPP_MAIN_CB.Dpc.SystemArgument1) != 0;
    if ( (_DWORD)__imp_gProtocolType != (WPP_MAIN_CB.DeviceLock.Header.WaitListHead.Flink != nullptr) )
    {
      if ( LODWORD(WPP_MAIN_CB.Dpc.SystemArgument1) != 0 )
      {
        return PostMessage(a1: *(_QWORD *)(*(_QWORD *)(gTermIO[2] + 456LL) + 24LL), a2: 1025, a3: 0, a4: 0);
      }
      else
      {
        __imp_gProtocolType = FindTimer(
                                a1: 0,
                                a2: WPP_MAIN_CB.DeviceLock.Header.WaitListHead.Flink,
                                a3: 4,
                                a4: 1,
                                a5: 0);
        WPP_MAIN_CB.DeviceLock.Header.WaitListHead.Flink = nullptr;
      }
    }
  }
  return __imp_gProtocolType;
}
