__int64 __fastcall IsOverlaySchemeValid(const _GUID *a1)
{
  ULONG v1; // edi
  ULONG i; // [rsp+20h] [rbp-48h]
  DWORD v5; // [rsp+40h] [rbp-28h] BYREF
  _QWORD v6[2]; // [rsp+48h] [rbp-20h] BYREF

  v1 = 0;
  for ( i = 0; ; i = v1 )
  {
    v5 = 16;
    if ( PowerEnumerate(
           RootPowerKey: nullptr,
           SchemeGuid: nullptr,
           SubGroupOfPowerSettingsGuid: nullptr,
           AccessFlags: ACCESS_OVERLAY_SCHEME,
           Index: i,
           Buffer: (UCHAR *)v6,
           BufferSize: &v5) != 0 )
      break;
    if ( v6[0] == *(_QWORD *)&a1->Data1 && v6[1] == *(_QWORD *)a1->Data4 )
      return 1;
    ++v1;
  }
  return 0;
}
