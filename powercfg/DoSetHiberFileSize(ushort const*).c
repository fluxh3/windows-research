__int64 __fastcall DoSetHiberFileSize(const unsigned __int16 *a1)
{
  NTSTATUS v1; // eax
  unsigned int v2; // ebx
  ULONG v3; // eax
  __int64 v4; // rbx
  const wchar_t *ResString; // rax
  unsigned int v7; // [rsp+58h] [rbp+10h] BYREF
  __int64 v8; // [rsp+60h] [rbp+18h] BYREF

  v7 = wcstoul(String: a1, EndPtr: nullptr, Radix: 10);
  v1 = PowerInformationWithPrivileges(a1: 51, a2: &v7, a3: 4, a4: &v8, a5: 8);
  if ( v1 >= 0 )
  {
    v2 = DoHibernate(lpString1: L"off");
    if ( v2 == 0 )
    {
      v2 = DoHibernate(lpString1: L"on");
      if ( v2 == 0 )
      {
        v4 = v8;
        ResString = (const wchar_t *)GetResString(uID: 0x509u);
        swprintf_s(Buffer: (wchar_t *const)g_lpszBuf, BufferCount: 0x204u, Format: ResString, v4);
        PowercfgPrint(a1: 0, a2: g_lpszBuf);
        return 0;
      }
    }
  }
  else
  {
    v2 = 1627;
    if ( g_lpszErr2 == nullptr )
    {
      v3 = RtlNtStatusToDosError(Status: v1);
      FormatMessageW(
        dwFlags: 0x1300u,
        lpSource: nullptr,
        dwMessageId: v3,
        dwLanguageId: 0x400u,
        lpBuffer: (LPWSTR)&g_lpszErr2,
        nSize: 0,
        Arguments: nullptr);
    }
  }
  return v2;
}
