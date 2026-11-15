__int64 __fastcall DisplayPowerSettingInformation(HKEY a1, _GUID *a2, _GUID *a3, _GUID *a4, unsigned int a5)
{
  unsigned int v5; // esi
  unsigned int v8; // edi
  unsigned int v10; // esi
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  UCHAR *v14; // r15
  __int64 v15; // rax
  ULONG v16; // r15d
  DWORD PossibleFriendlyName; // r12d
  __int64 ResString; // rax
  UCHAR *v19; // rax
  __int64 v20; // rax
  UCHAR *hMem; // [rsp+70h] [rbp+40h]
  _GUID *ValueMinimum; // [rsp+78h] [rbp+48h] BYREF

  ValueMinimum = a2;
  v5 = a5;
  v8 = DisplayGUIDAndFriendlyName(a1, a2: nullptr, a3, a4, a5);
  PowercfgPrint(a1: 0, a2: L"\n");
  DisplayAlias(a1: a4, a2: v5);
  if ( v8 != 0 )
    return v8;
  v10 = v5 + 2;
  if ( PowerReadValueMin(
         RootPowerKey: nullptr,
         SubGroupOfPowerSettingsGuid: a3,
         PowerSettingGuid: a4,
         (LPDWORD)&ValueMinimum) != 0 )
  {
    v16 = 0;
    do
    {
      LODWORD(ValueMinimum) = 0;
      PossibleFriendlyName = PowerReadPossibleFriendlyName(
                               RootPowerKey: nullptr,
                               SubGroupOfPowerSettingsGuid: a3,
                               PowerSettingGuid: a4,
                               PossibleSettingIndex: v16,
                               Buffer: nullptr,
                               BufferSize: (LPDWORD)&ValueMinimum);
      if ( PossibleFriendlyName == 0 && (_DWORD)ValueMinimum != 0 )
      {
        PrependPadding(a1: v10);
        ResString = GetResString(uID: 0x379u);
        PowercfgPrint(a1: 0, a2: ResString);
        swprintf_s(Buffer: (wchar_t *const)g_lpszBuf, BufferCount: 0x204u, Format: L"%03d\n", v16);
        PowercfgPrint(a1: 0, a2: g_lpszBuf);
        v19 = (UCHAR *)LocalAlloc(uFlags: PossibleFriendlyName + 64, uBytes: (unsigned int)ValueMinimum);
        hMem = v19;
        if ( v19 != nullptr )
        {
          PossibleFriendlyName = PowerReadPossibleFriendlyName(
                                   RootPowerKey: nullptr,
                                   SubGroupOfPowerSettingsGuid: a3,
                                   PowerSettingGuid: a4,
                                   PossibleSettingIndex: v16,
                                   Buffer: v19,
                                   BufferSize: (LPDWORD)&ValueMinimum);
          if ( PossibleFriendlyName == 0 )
          {
            PrependPadding(a1: v10);
            v20 = GetResString(uID: 0x374u);
            PowercfgPrint(a1: 0, a2: v20);
            swprintf_s(Buffer: (wchar_t *const)g_lpszBuf, BufferCount: 0x204u, Format: L"%s\n", hMem);
            PowercfgPrint(a1: 0, a2: g_lpszBuf);
          }
          LocalFree(hMem);
        }
      }
      ++v16;
    }
    while ( PossibleFriendlyName == 0 );
  }
  else
  {
    PrependPadding(a1: v10);
    v11 = GetResString(uID: 0x360u);
    PowercfgPrint(a1: 0, a2: v11);
    swprintf_s(Buffer: (wchar_t *const)g_lpszBuf, BufferCount: 0x204u, Format: L"0x%08lx\n", (unsigned int)ValueMinimum);
    PowercfgPrint(a1: 0, a2: g_lpszBuf);
    if ( PowerReadValueMax(
           RootPowerKey: nullptr,
           SubGroupOfPowerSettingsGuid: a3,
           PowerSettingGuid: a4,
           ValueMaximum: (LPDWORD)&ValueMinimum) == 0 )
    {
      PrependPadding(a1: v10);
      v12 = GetResString(uID: 0x365u);
      PowercfgPrint(a1: 0, a2: v12);
      swprintf_s(
        Buffer: (wchar_t *const)g_lpszBuf,
        BufferCount: 0x204u,
        Format: L"0x%08lx\n",
        (unsigned int)ValueMinimum);
      PowercfgPrint(a1: 0, a2: g_lpszBuf);
    }
    if ( PowerReadValueIncrement(
           RootPowerKey: nullptr,
           SubGroupOfPowerSettingsGuid: a3,
           PowerSettingGuid: a4,
           ValueIncrement: (LPDWORD)&ValueMinimum) == 0 )
    {
      PrependPadding(a1: v10);
      v13 = GetResString(uID: 0x36Au);
      PowercfgPrint(a1: 0, a2: v13);
      swprintf_s(
        Buffer: (wchar_t *const)g_lpszBuf,
        BufferCount: 0x204u,
        Format: L"0x%08lx\n",
        (unsigned int)ValueMinimum);
      PowercfgPrint(a1: 0, a2: g_lpszBuf);
    }
    LODWORD(ValueMinimum) = 0;
    if ( PowerReadValueUnitsSpecifier(
           RootPowerKey: nullptr,
           SubGroupOfPowerSettingsGuid: a3,
           PowerSettingGuid: a4,
           Buffer: nullptr,
           BufferSize: (LPDWORD)&ValueMinimum) == 0
      && (_DWORD)ValueMinimum != 0 )
    {
      v14 = (UCHAR *)LocalAlloc(uFlags: 0x40u, uBytes: (unsigned int)ValueMinimum);
      if ( v14 != nullptr )
      {
        if ( PowerReadValueUnitsSpecifier(
               RootPowerKey: nullptr,
               SubGroupOfPowerSettingsGuid: a3,
               PowerSettingGuid: a4,
               Buffer: v14,
               BufferSize: (LPDWORD)&ValueMinimum) == 0 )
        {
          PrependPadding(a1: v10);
          v15 = GetResString(uID: 0x36Fu);
          PowercfgPrint(a1: 0, a2: v15);
          swprintf_s(Buffer: (wchar_t *const)g_lpszBuf, BufferCount: 0x204u, Format: L"%s\n", v14);
          PowercfgPrint(a1: 0, a2: g_lpszBuf);
        }
        LocalFree(hMem: v14);
      }
    }
  }
  return 0;
}
