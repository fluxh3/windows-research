_BOOL8 __fastcall vGetFontDriverLWT(_BOOL8 *a1, _BOOL8 *a2)
{
  _BOOL8 result; // rax
  _BOOL8 v5; // [rsp+40h] [rbp+18h] BYREF

  v5 = false;
  if ( Win32FileInfo(SourceString: L"\\SystemRoot\\system32\\win32kfull.sys", a2: &v5, a3: nullptr) )
    *a1 = v5;
  result = Win32FileInfo(SourceString: L"\\SystemRoot\\system32\\atmfd.dll", a2: &v5, a3: nullptr);
  if ( result )
  {
    result = v5;
    *a2 = v5;
  }
  return result;
}
