__int64 __fastcall AcquirePccInterface(__int64 a1)
{
  __int64 v2; // rax
  int PccInternalInterfaceInfo; // ebx
  __int64 v5; // rdx

  guard_dispatch_icall_nop(a1: WdfDriverGlobals, a2: qword_1C001C418);
  if ( qword_1C001C900 != 0 )
  {
    PccInternalInterfaceInfo = 0;
  }
  else
  {
    dword_1C001C8D8 = -1;
    v2 = guard_dispatch_icall_nop(a1: WdfDriverGlobals, a2: a1);
    PccInternalInterfaceInfo = guard_dispatch_icall_nop(a1: WdfDriverGlobals, a2: v2);
    if ( PccInternalInterfaceInfo >= 0 )
    {
      PccInternalInterfaceInfo = ValidatePccHeader(a1: qword_1C001C900);
      if ( PccInternalInterfaceInfo < 0 )
        goto LABEL_9;
      if ( dword_1C001C84C == 1 )
        PccInternalInterfaceInfo = GetPccInternalInterfaceInfo(a1);
      if ( PccInternalInterfaceInfo < 0 )
      {
LABEL_9:
        guard_dispatch_icall_nop(a1: qword_1C001C8C0, a2: v5);
        memset(a1: &qword_1C001C8B8, Val: 0, Size: 0x80u);
      }
    }
  }
  guard_dispatch_icall_nop(a1: WdfDriverGlobals, a2: qword_1C001C418);
  return (unsigned int)PccInternalInterfaceInfo;
}
