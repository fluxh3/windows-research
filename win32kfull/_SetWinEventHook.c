__int64 __fastcall SetWinEventHook(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7,
        char a8)
{
  __int64 v8; // r12
  int HmodTableIndex; // edi
  __int64 __imp_gpWinEventHooks_1; // rax
  __int64 __imp_gpWinEventHooks; // rbx
  int v13; // ecx
  int v14; // eax
  __int64 v15; // r8
  __int64 v17; // rax
  int n1427; // ecx

  v8 = a3;
  if ( (*(_DWORD *)(gptiCurrent + 480LL) & 1) != 0 )
    return 0;
  if ( a5 == 0 )
  {
    n1427 = 1427;
LABEL_20:
    UserSetLastError(a1: n1427);
    return 0;
  }
  if ( a1 > a2 )
  {
    n1427 = 1426;
    goto LABEL_20;
  }
  if ( (a8 & 4) != 0 )
  {
    if ( a3 == 0 )
    {
      n1427 = 1428;
      goto LABEL_20;
    }
    if ( a4 == 0 )
    {
      n1427 = 1157;
      goto LABEL_20;
    }
    HmodTableIndex = GetHmodTableIndex(a1: a4);
    if ( HmodTableIndex == -1 )
    {
      n1427 = 126;
      goto LABEL_20;
    }
  }
  else
  {
    HmodTableIndex = -1;
    v8 = 0;
  }
  if ( a7 != 0 )
  {
    v17 = PtiFromThreadId(a1: a7);
    if ( v17 == 0 || (*(_DWORD *)(v17 + 480) & 0x1000000) == 0 )
    {
      n1427 = 1444;
      goto LABEL_20;
    }
  }
  LOBYTE(a3) = 15;
  __imp_gpWinEventHooks_1 = HMAllocObject(a1: gptiCurrent, a2: 0, a3, a4: 96);
  __imp_gpWinEventHooks = __imp_gpWinEventHooks_1;
  if ( __imp_gpWinEventHooks_1 == 0 )
    return 0;
  v13 = *(_DWORD *)(__imp_gpWinEventHooks_1 + 40);
  *(_DWORD *)(__imp_gpWinEventHooks_1 + 32) = a1;
  *(_DWORD *)(__imp_gpWinEventHooks_1 + 36) = a2;
  *(_QWORD *)(__imp_gpWinEventHooks_1 + 48) = a6;
  *(_DWORD *)(__imp_gpWinEventHooks_1 + 56) = a7;
  *(_DWORD *)(__imp_gpWinEventHooks_1 + 72) = HmodTableIndex;
  *(_DWORD *)(__imp_gpWinEventHooks_1 + 40) = (2 * (a8 & 0xB)) | v13 & 0xFFFFFFE0 | ((a8 & 4) != 0 ? 8 : 0);
  if ( HmodTableIndex >= 0 )
    AddHmodDependency(HmodTableIndex);
  *(_QWORD *)(__imp_gpWinEventHooks + 64) = a5 - v8;
  *(_QWORD *)(__imp_gpWinEventHooks + 24) = gpWinEventHooks;
  gpWinEventHooks = __imp_gpWinEventHooks;
  v14 = CategoryMaskFromEventRange(a1, a2, __imp_gpsi: gpsi);
  *(_DWORD *)(v15 + 1892) |= v14;
  *(_DWORD *)(__imp_gpWinEventHooks + 88) = W32GetCurrentThreadDpiAwarenessContext();
  return __imp_gpWinEventHooks;
}
