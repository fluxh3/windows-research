void __fastcall LoadScalingOverrides()
{
  int v0; // eax
  DWORD pcbData; // [rsp+50h] [rbp+8h] BYREF

  if ( g_legacyCompatScalingOverride == DEVICE_SCALE_FACTOR_INVALID )
  {
    pcbData = 4;
    RegGetValueW(
      hkey: HKEY_LOCAL_MACHINE,
      lpSubKey: L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Scaling",
      lpValue: L"LegacyAppScaleFactor",
      dwFlags: 0x20000018u,
      pdwType: nullptr,
      pvData: &g_legacyCompatScalingOverride,
      &pcbData);
  }
  if ( g_windowOverride == 0 )
  {
    pcbData = 4;
    RegGetValueW(
      hkey: HKEY_LOCAL_MACHINE,
      lpSubKey: L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Scaling",
      lpValue: L"WindowOverride",
      dwFlags: 0x20000018u,
      pdwType: nullptr,
      pvData: &g_windowOverride,
      &pcbData);
    v0 = g_windowOverride;
    if ( g_windowOverride == 0 )
      v0 = 100;
    g_windowOverride = v0;
  }
}
