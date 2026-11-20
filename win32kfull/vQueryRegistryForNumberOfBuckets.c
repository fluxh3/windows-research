__int64 __fastcall vQueryRegistryForNumberOfBuckets(unsigned int *a1, _DWORD *a2)
{
  NTSTATUS v4; // eax
  unsigned int n5_1; // ecx
  bool v6; // sf
  unsigned int n10000; // eax
  __int64 n5; // rax
  unsigned int n10000_1; // [rsp+30h] [rbp-D0h] BYREF
  unsigned int n5_2; // [rsp+34h] [rbp-CCh] BYREF
  unsigned int n10000_2; // [rsp+38h] [rbp-C8h] BYREF
  unsigned int n5_3; // [rsp+3Ch] [rbp-C4h] BYREF
  struct _RTL_QUERY_REGISTRY_TABLE QueryTable; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v14; // [rsp+78h] [rbp-88h]
  int n288; // [rsp+80h] [rbp-80h]
  const wchar_t *NumberOfPublicFontFilesSetByUser; // [rsp+88h] [rbp-78h]
  unsigned int *p_n10000; // [rsp+90h] [rbp-70h]
  int n0x4000000; // [rsp+98h] [rbp-68h]
  __int64 v19; // [rsp+A0h] [rbp-60h]
  int v20; // [rsp+A8h] [rbp-58h]
  __int64 v21; // [rsp+B0h] [rbp-50h]
  int n288_1; // [rsp+B8h] [rbp-48h]
  const wchar_t *NumberOfDeviceFontFilesAtLastLogOff; // [rsp+C0h] [rbp-40h]
  unsigned int *p_n5; // [rsp+C8h] [rbp-38h]
  int n0x4000000_1; // [rsp+D0h] [rbp-30h]
  __int64 v26; // [rsp+D8h] [rbp-28h]
  int v27; // [rsp+E0h] [rbp-20h]
  __int64 v28; // [rsp+E8h] [rbp-18h]
  int n288_2; // [rsp+F0h] [rbp-10h]
  const wchar_t *NumberOfDeviceFontFilesSetByUser; // [rsp+F8h] [rbp-8h]
  unsigned int *p_n5_1; // [rsp+100h] [rbp+0h]
  int n0x4000000_2; // [rsp+108h] [rbp+8h]
  __int64 v33; // [rsp+110h] [rbp+10h]
  int v34; // [rsp+118h] [rbp+18h]
  __int64 v35; // [rsp+120h] [rbp+20h]
  int v36; // [rsp+128h] [rbp+28h]
  __int64 v37; // [rsp+130h] [rbp+30h]

  QueryTable.Name = L"NumberOfPublicFontFilesAtLastLogOff";
  n10000_2 = 0;
  n10000_1 = 0;
  QueryTable.Flags = 288;
  n288 = 288;
  QueryTable.DefaultType = 0x4000000;
  QueryTable.EntryContext = &n10000_2;
  n0x4000000 = 0x4000000;
  NumberOfPublicFontFilesSetByUser = L"NumberOfPublicFontFilesSetByUser";
  p_n10000 = &n10000_1;
  NumberOfDeviceFontFilesAtLastLogOff = L"NumberOfDeviceFontFilesAtLastLogOff";
  p_n5 = &n5_3;
  NumberOfDeviceFontFilesSetByUser = L"NumberOfDeviceFontFilesSetByUser";
  n288_1 = 288;
  n0x4000000_1 = 0x4000000;
  n288_2 = 288;
  n0x4000000_2 = 0x4000000;
  p_n5_1 = &n5_2;
  n5_3 = 0;
  n5_2 = 0;
  QueryTable.QueryRoutine = nullptr;
  QueryTable.DefaultData = nullptr;
  QueryTable.DefaultLength = 0;
  v14 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v4 = RtlQueryRegistryValues(RelativeTo: 3u, Path: L"FontCache", &QueryTable, Context: nullptr, Environment: nullptr);
  n5_1 = n5_2;
  v6 = v4 < STATUS_SUCCESS;
  n10000 = n10000_1;
  if ( !v6 )
  {
    if ( n10000_1 == 0 )
      n10000 = n10000_2;
    if ( n5_2 == 0 )
      n5_1 = n5_3;
  }
  if ( n10000 >= 0x64 )
  {
    if ( n10000 > 0x2710 )
      n10000 = 10000;
  }
  else
  {
    n10000 = 100;
  }
  *a1 = n10000;
  n5 = 5;
  if ( n5_1 >= 5 )
  {
    n5 = n5_1;
    if ( n5_1 > 0x64 )
      n5 = 100;
  }
  *a2 = n5;
  return n5;
}
