__int64 __fastcall SetCaretBlinkTime(int a1)
{
  __int64 v3; // rbx

  if ( (unsigned int)CheckWinstaAttributeAccess(DesiredAccess: 0x10u) == 0
    || (unsigned int)CheckDesktopPolicy(a1: 0, a2: 4) != 0 )
  {
    return 0;
  }
  *(_DWORD *)(gpsi + 4984LL) = a1;
  v3 = *(_QWORD *)(gptiCurrent + 424LL);
  if ( *(_QWORD *)(v3 + 344) != 0 )
  {
    RemoveCaretTimer(a1: *(tagWND **)(v3 + 296), a2: *(struct tagQ **)(gptiCurrent + 424LL));
    CreateCaretTimer(a1: *(tagWND **)(v3 + 296), a2: (struct tagQ *)v3);
  }
  return 1;
}
