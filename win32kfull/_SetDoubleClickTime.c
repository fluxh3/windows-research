__int64 __fastcall SetDoubleClickTime(unsigned int n5000)
{
  __int64 v2; // rdi
  __int64 i; // r9
  __int64 v4; // rax
  __int64 v5; // r9

  v2 = *(_QWORD *)(PsGetCurrentProcessWin32Process() + 664);
  if ( (unsigned int)CheckWinstaAttributeAccess(DesiredAccess: 0x10u) == 0 )
    return 0;
  if ( n5000 != 0 )
  {
    if ( n5000 > 0x1388 )
      n5000 = 5000;
  }
  else
  {
    n5000 = 500;
  }
  gdtDblClk = n5000;
  *(_DWORD *)(gpsi + 4980LL) = 4 * n5000;
  *(_DWORD *)(gpsi + 4976LL) = *(_DWORD *)(gpsi + 4980LL) / 5u;
  if ( v2 != 0 )
  {
    for ( i = *(_QWORD *)(v2 + 16); i != 0; i = *(_QWORD *)(v5 + 32) )
    {
      v4 = safe_cast_fnid_to_PTOOLTIPWND(a1: *(_QWORD *)(i + 112));
      InitTooltipDelay(a1: v4);
    }
  }
  return 1;
}
