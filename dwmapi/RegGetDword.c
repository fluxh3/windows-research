bool __fastcall RegGetDword(HKEY a1, const unsigned __int16 *const a2, unsigned int *a3)
{
  bool v3; // bl
  DWORD v6; // [rsp+40h] [rbp+8h] BYREF
  __int64 v7; // [rsp+48h] [rbp+10h] BYREF
  unsigned int v8; // [rsp+58h] [rbp+20h] BYREF

  HIDWORD(v7) = HIDWORD(a2);
  v3 = false;
  LODWORD(v7) = 4;
  if ( a1 != nullptr
    && RegQueryValueExW(
         hKey: a1,
         lpValueName: L"DisableInstrumentationBreaking",
         lpReserved: nullptr,
         lpType: &v6,
         lpData: (LPBYTE)&v8,
         lpcbData: (LPDWORD)&v7) == 0 )
  {
    v3 = v6 == 4;
    *a3 = v8;
  }
  return v3;
}
