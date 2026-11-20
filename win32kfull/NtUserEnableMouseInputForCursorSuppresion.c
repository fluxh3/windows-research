__int64 __fastcall NtUserEnableMouseInputForCursorSuppression(int a1)
{
  __int64 v2; // rbx
  __int64 v3; // rcx
  __int64 v5; // rax
  enum CURSOR_SUPPRESSION_STATE n2; // ecx
  __int64 CurrentProcessWin32Process; // rax

  EnterCrit(a1: 0, a2: 1);
  v2 = 0;
  if ( (a1 != 0) != a1 )
  {
    UserSetLastError(a1: 87);
    goto LABEL_6;
  }
  v3 = (unsigned int)(gCursorSuppressionState - 1);
  if ( gCursorSuppressionState != 1 )
  {
    v3 = (unsigned int)(gCursorSuppressionState - 2);
    if ( gCursorSuppressionState == 2 )
      goto LABEL_4;
    v3 = (unsigned int)(gCursorSuppressionState - 4);
    if ( gCursorSuppressionState == 4 )
      goto LABEL_4;
    v3 = (unsigned int)(gCursorSuppressionState - 5);
    if ( gCursorSuppressionState != 5 )
    {
      v3 = (unsigned int)(gCursorSuppressionState - 6);
      if ( gCursorSuppressionState == 6 || gCursorSuppressionState == 8 )
      {
LABEL_4:
        if ( a1 == 0 )
        {
          CurrentProcessWin32Process = PsGetCurrentProcessWin32Process(a1: v3);
          n2 = 1;
          *(_DWORD *)(CurrentProcessWin32Process + 820) |= 0x80000u;
          goto LABEL_14;
        }
      }
LABEL_5:
      v2 = 1;
LABEL_6:
      UserSessionSwitchLeaveCrit(a1: v3);
      return v2;
    }
  }
  if ( a1 == 0 )
    goto LABEL_5;
  v5 = PsGetCurrentProcessWin32Process(a1: v3);
  n2 = 2;
  *(_DWORD *)(v5 + 820) &= ~0x80000u;
LABEL_14:
  TransitionCursorSuppressionState(a1: n2);
  goto LABEL_5;
}
