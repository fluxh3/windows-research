struct ReEnterLeaveCrit *ResetAccessibilityCountersOnMouseInput()
{
  struct ReEnterLeaveCrit *result; // rax
  __int64 v1; // rcx
  int v2; // [rsp+30h] [rbp+8h] BYREF

  gStickyKeysLeftShiftCount = 0;
  gStickyKeysRightShiftCount = 0;
  __faststorefence();
  if ( gtmridFKActivation != 0 )
  {
    result = ReEnterLeaveCrit::ReEnterLeaveCrit(this: (ReEnterLeaveCrit *)&v2);
    if ( gtmridFKActivation != 0 )
    {
      result = (struct ReEnterLeaveCrit *)ApiSetEditionKillAccessibilityTimer();
      gtmridFKActivation = 0;
      gFilterKeysState = 8;
    }
    if ( v2 == 0 )
      return (struct ReEnterLeaveCrit *)UserSessionSwitchLeaveCrit(a1: v1);
  }
  return result;
}
