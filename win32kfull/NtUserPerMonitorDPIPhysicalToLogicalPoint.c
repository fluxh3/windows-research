__int64 __fastcall NtUserPerMonitorDPIPhysicalToLogicalPoint(__int64 a1, _QWORD *MmUserProbeAddress_1)
{
  __int64 v4; // rcx
  _QWORD *MmUserProbeAddress; // rdx
  unsigned int CurrentThreadDpiAwarenessContext; // eax
  unsigned int CurrentThreadDpiAwarenessContext_1; // esi
  __int64 v8; // r8
  __int64 v10; // [rsp+70h] [rbp+8h] BYREF
  __int64 v11; // [rsp+80h] [rbp+18h] BYREF
  __int64 v12; // [rsp+88h] [rbp+20h] BYREF

  EnterSharedCrit(a1: 0, a2: 1);
  if ( a1 == 0 || (a1 = ValidateHwnd(a1)) != 0 )
  {
    v10 = 0;
    MmUserProbeAddress = MmUserProbeAddress_1;
    if ( (unsigned __int64)MmUserProbeAddress_1 >= ::MmUserProbeAddress )
      MmUserProbeAddress = (_QWORD *)::MmUserProbeAddress;
    *MmUserProbeAddress = *MmUserProbeAddress;
    v10 = *MmUserProbeAddress_1;
    CurrentThreadDpiAwarenessContext = W32GetCurrentThreadDpiAwarenessContext();
    CurrentThreadDpiAwarenessContext_1 = CurrentThreadDpiAwarenessContext;
    if ( a1 != 0 )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(W32GetThreadWin32Thread(a1: (__int64)KeGetCurrentThread()) + 472) + 224LL) & 1) == 0 )
        W32GetThreadWin32Thread(a1: (__int64)KeGetCurrentThread());
      v11 = GuessMonitorOverrideForCoordinateConversions(
              a1: v10,
              a2: *(unsigned int *)(*(_QWORD *)(a1 + 40) + 288LL),
              a3: 1);
      PhysicalToLogicalDPIPoint(a1: &v10, a2: &v10, a3: *(unsigned int *)(*(_QWORD *)(a1 + 40) + 288LL), a4: &v11);
      LODWORD(a1) = DCEPtInRect(a1: *(_QWORD *)(a1 + 40) + 88LL, a2: v10) != 0;
    }
    else
    {
      v12 = GuessMonitorOverrideForCoordinateConversions(a1: v10, a2: CurrentThreadDpiAwarenessContext, a3: 1);
      PhysicalToLogicalDPIPoint(a1: &v10, a2: &v10, a3: CurrentThreadDpiAwarenessContext_1, a4: &v12);
      LODWORD(a1) = 1;
      v8 = v10;
    }
    if ( (_DWORD)a1 != 0 )
    {
      *MmUserProbeAddress_1 = v8;
      LODWORD(a1) = 1;
    }
  }
  UserSessionSwitchLeaveCrit(a1: v4);
  return (int)a1;
}
