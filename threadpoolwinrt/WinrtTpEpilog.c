__int64 __fastcall WinrtTpEpilog()
{
  PVOID Value; // rbx
  __int64 v1; // r8
  __int64 v2; // r9
  __int64 v3; // rdx
  __int64 v4; // r8
  __int64 v5; // r9
  __int64 v7; // rdx
  __int64 v8; // r8
  __int64 v9; // r9
  int v10; // [rsp+30h] [rbp+8h] BYREF

  Value = FlsGetValue(dwFlsIndex: g_flsSlot);
  if ( Value != nullptr )
  {
    guard_dispatch_icall_nop(a1: Value, a2: &v10, a3: v1, a4: v2);
    if ( v10 == 0 )
    {
      guard_dispatch_icall_nop(a1: Value, a2: v3, a3: v4, a4: v5);
      FlsSetValue(dwFlsIndex: g_flsSlot, lpFlsData: nullptr);
      guard_dispatch_icall_nop(a1: Value, a2: v7, a3: v8, a4: v9);
    }
  }
  return 0;
}
