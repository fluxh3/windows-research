__int64 __fastcall ConvertAllLegacyPolicies(int a1)
{
  unsigned int v1; // ebx
  BOOLEAN ActivePwrScheme; // al
  unsigned int v3; // ecx
  UINT v4; // edi
  const wchar_t *ResString; // rax
  GUID v6; // xmm0
  __int64 i; // rsi
  __int64 v8; // rax
  __int64 v9; // rax
  GUID *SchemeGuid; // [rsp+28h] [rbp-69h] BYREF
  unsigned int puiID; // [rsp+30h] [rbp-61h] BYREF
  __m128i v13; // [rsp+38h] [rbp-59h] BYREF
  struct _POWER_POLICY pPowerPolicy; // [rsp+48h] [rbp-49h] BYREF

  v1 = 0;
  puiID = 0;
  SchemeGuid = nullptr;
  if ( a1 == 2 )
  {
    ActivePwrScheme = GetActivePwrScheme(&puiID);
    v3 = puiID;
    v4 = 0;
    if ( ActivePwrScheme == 0 )
      v3 = 1;
    puiID = v3;
    while ( 1 )
    {
      memset_0(a1: &pPowerPolicy, Val: 0, Size: sizeof(pPowerPolicy));
      if ( ReadPwrScheme(uiID: v4, &pPowerPolicy) != 0 )
        break;
LABEL_24:
      if ( ++v4 >= 0x3E7 )
        return v1;
    }
    ResString = (const wchar_t *)GetResString(uID: 0x33Du);
    swprintf_s(Buffer: (wchar_t *const)g_lpszBuf, BufferCount: 0x204u, Format: ResString, v4);
    PowercfgPrint(a1: 0, a2: g_lpszBuf);
    SchemeGuid = nullptr;
    switch ( v4 )
    {
      case 1u:
        v6 = GUID_TYPICAL_POWER_SAVINGS;
        break;
      case 3u:
        v6 = GUID_MIN_POWER_SAVINGS;
        break;
      case 5u:
        v6 = GUID_MAX_POWER_SAVINGS;
        break;
      default:
        goto LABEL_14;
    }
    SchemeGuid = (GUID *)&v13;
    v13 = (__m128i)v6;
LABEL_14:
    if ( (unsigned int)PowerPolicyToGUIDFormat(a1: &SchemeGuid, a2: &pPowerPolicy) != 0 || SchemeGuid == nullptr )
    {
      v9 = GetResString(uID: 0xCu);
      PowercfgPrint(a1: 0, a2: v9);
    }
    else
    {
      for ( i = 4; i != 0; --i )
        PowercfgPrint(a1: 0, a2: L" ");
      v8 = GetResString(uID: 0x342u);
      PowercfgPrint(a1: 0, a2: v8);
      PrintGUID(a1: SchemeGuid); 
      PowercfgPrint(a1: 0, a2: L"\n");
      if ( v4 == puiID )
        PowerSetActiveScheme(UserRootPowerKey: nullptr, SchemeGuid);
    }
    if ( SchemeGuid != nullptr && SchemeGuid != (GUID *)&v13 )
    {
      LocalFree(hMem: SchemeGuid);
      SchemeGuid = nullptr;
    }
    goto LABEL_24;
  }
  return 87;
}
