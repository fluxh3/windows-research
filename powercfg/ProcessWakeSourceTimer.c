HLOCAL __fastcall ProcessWakeSourceTimer(__int64 a1)
{
  __int64 v2; // rax
  HLOCAL result; // rax
  __int64 ResString; // rax
  __int64 v5; // rax
  void *v6; // rdi
  __int64 v7; // rax
  __int64 RequesterReason; // rax
  void *v9; // rbx
  int v10; // [rsp+30h] [rbp+8h] BYREF

  if ( *(_QWORD *)(a1 + 8) != 0 )
  {
    ResString = GetResString(uID: 0x528u);
    PowercfgPrint(a1: 0, a2: ResString);
    v5 = GetResString(uID: 0x5A7u);
    result = (HLOCAL)PowerHelperGetRequesterId(a1: a1 + 8, a2: v5, a3: &v10);
    v6 = result;
    if ( result != nullptr )
    {
      swprintf_s(Buffer: (wchar_t *const)g_lpszBuf, BufferCount: 0x204u, Format: L"%s", result);
      PowercfgPrint(a1: 0, a2: g_lpszBuf);
      if ( v10 != 0 )
        LocalFree(hMem: v6);
      result = (HLOCAL)PowercfgPrint(a1: 0, a2: L"\n");
    }
    if ( *(_QWORD *)(a1 + 40) != 0 )
    {
      v7 = GetResString(uID: 0x529u);
      PowercfgPrint(a1: 0, a2: v7);
      RequesterReason = PowerHelperGetRequesterReason(a1: a1 + 8 + *(_QWORD *)(a1 + 40), a2: &v10);
      v9 = (void *)RequesterReason;
      if ( RequesterReason != 0 )
        PowercfgPrint(a1: 0, a2: RequesterReason);
      result = (HLOCAL)PowercfgPrint(a1: 0, a2: L"\n");
      if ( v10 != 0 )
        return LocalFree(hMem: v9);
    }
  }
  else
  {
    v2 = GetResString(uID: 0x52Bu);
    return (HLOCAL)PowercfgPrint(a1: 0, a2: v2);
  }
  return result;
}
