__int64 __fastcall SetDPIinSetup(struct _DXGK_DISPLAY_SCENARIO_CONTEXT *a1)
{
  int CurrentDpiInfoFromHDev; // esi
  unsigned int v4; // kr00_4
  unsigned int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  struct _DEVCAPS *gpGdiDevCaps; // rdx
  UNICODE_STRING String2; // [rsp+80h] [rbp-80h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+90h] [rbp-70h] BYREF
  __int64 v14; // [rsp+A0h] [rbp-60h] BYREF
  struct _RTL_QUERY_REGISTRY_TABLE QueryTable; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v16; // [rsp+E8h] [rbp-18h]
  int v17; // [rsp+F0h] [rbp-10h]
  __int64 v18; // [rsp+F8h] [rbp-8h]
  __int64 v19; // [rsp+100h] [rbp+0h]
  int v20; // [rsp+108h] [rbp+8h]
  __int64 v21; // [rsp+110h] [rbp+10h]
  int v22; // [rsp+118h] [rbp+18h]
  _DWORD v23[36]; // [rsp+120h] [rbp+20h] BYREF
  __int64 v24; // [rsp+1C8h] [rbp+C8h] BYREF
  int v25; // [rsp+1D0h] [rbp+D0h] BYREF
  __int64 v26; // [rsp+1D8h] [rbp+D8h] BYREF

  QueryTable.Flags = 292;
  v25 = 0;
  QueryTable.Name = L"ImageState";
  v26 = 0;
  QueryTable.EntryContext = &DestinationString;
  QueryTable.QueryRoutine = nullptr;
  QueryTable.DefaultType = 16777217;
  QueryTable.DefaultData = nullptr;
  DestinationString = 0;
  QueryTable.DefaultLength = 0;
  String2 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  RtlInitUnicodeString(&DestinationString, SourceString: nullptr);
  if ( RtlQueryRegistryValues(
         RelativeTo: 0,
         Path: L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\State",
         &QueryTable,
         Context: nullptr,
         Environment: nullptr) < STATUS_SUCCESS )
    goto LABEL_4;
  RtlInitUnicodeString(DestinationString: &String2, SourceString: L"IMAGE_STATE_SPECIALIZE_RESEAL_TO_OOBE");
  if ( RtlCompareUnicodeString(String1: &DestinationString, &String2, CaseInSensitive: 1u) != 0 )
  {
    RtlInitUnicodeString(DestinationString: &String2, SourceString: L"IMAGE_STATE_COMPLETE");
    if ( RtlCompareUnicodeString(String1: &DestinationString, &String2, CaseInSensitive: 1u) != 0 )
      return 3221225474LL;
LABEL_4:
    RtlDeleteRegistryValue(
      RelativeTo: 0,
      Path: L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\DPI",
      ValueName: L"Overrode");
    return 3221225474LL;
  }
  QueryTable.Flags |= 0x80u;
  QueryTable.Name = L"Upgrade";
  QueryTable.EntryContext = &v25;
  if ( RtlQueryRegistryValues(
         RelativeTo: 0,
         Path: L"\\Registry\\Machine\\SYSTEM\\Setup",
         &QueryTable,
         Context: nullptr,
         Environment: nullptr) >= STATUS_SUCCESS )
    return 3221225474LL;
  QueryTable.Name = L"Overrode";
  if ( RtlQueryRegistryValues(
         RelativeTo: 0,
         Path: L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\DPI",
         &QueryTable,
         Context: nullptr,
         Environment: nullptr) >= STATUS_SUCCESS )
    return 3221225474LL;
  memset(a1: v23, Val: 0, Size: 0x60u);
  CurrentDpiInfoFromHDev = DrvGetCurrentDpiInfoFromHDev(a1: *(_QWORD *)(*(_QWORD *)(gpDispInfo + 96) + 232LL), a2: v23);
  v4 = 96 * v23[2] + 50;
  v5 = v4 / 0x64;
  if ( CurrentDpiInfoFromHDev >= 0 )
  {
    v6 = -1073741637;
    gbSetupDPIInitialized = 1;
    if ( qword_1C0252798 != nullptr )
      v7 = qword_1C0252798();
    else
      v7 = -1073741637;
    if ( v7 >= 0 && qword_1C02527A0 != nullptr )
      qword_1C02527A0(a1: 1, a2: &v25);
    if ( v25 != v5 )
    {
      v8 = qword_1C02527B8 != nullptr ? qword_1C02527B8() : -1073741637;
      if ( v8 >= 0 )
      {
        v9 = qword_1C02527C0 != nullptr ? qword_1C02527C0(a1: 1, a2: v5) : -1073741637;
        if ( v9 >= 0 )
        {
          v10 = qword_1C02527A8 != nullptr ? qword_1C02527A8() : -1073741637;
          if ( v10 >= 0 )
          {
            if ( qword_1C02527B0 != nullptr )
              v6 = qword_1C02527B0(a1: 1, a2: v4 / 0x64 > 0x78);
            if ( v6 >= 0 )
            {
              LOBYTE(v24) = 0;
              gDrvDpiWin8Style = 0;
              gDrvDpiAdjusted = 0;
              if ( (int)DrvSetDisplayConfig(
                          a1: 0,
                          a2: 0,
                          a3: 2191,
                          a4: 0,
                          a5: 0,
                          a6: 0,
                          a7: 0,
                          a8: 0,
                          a9: *(struct _MDEV **)(gpDispInfo + 16),
                          a10: (__int64)&v26,
                          a11: 0,
                          a12: 0,
                          a13: (__int64)&v24,
                          a14: 0,
                          a15: (__int64)a1) >= 0
                && (_BYTE)v24 == 0 )
              {
                GreReinitializeStockFonts(a1: v5, a2: 1);
                gpGdiDevCaps = ::gpGdiDevCaps;
                *(_QWORD *)(gpDispInfo + 40) = *(_QWORD *)v26;
                *(_QWORD *)(gpDispInfo + 16) = v26;
                v14 = *(_QWORD *)(gpDispInfo + 40);
                vGetDeviceCaps(this: (PDEVOBJ *)&v14, a2: gpGdiDevCaps);
                *((_WORD *)gpsi + 3499) = v5;
                ++*((_WORD *)gpsi + 3507);
                *(_WORD *)(PsGetCurrentProcessWin32Process() + 284) = *((_WORD *)gpsi + 3499);
              }
            }
          }
        }
      }
    }
  }
  return (unsigned int)CurrentDpiInfoFromHDev;
}
