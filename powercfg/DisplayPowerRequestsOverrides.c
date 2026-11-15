__int64 DisplayPowerRequestOverrides()
{
  unsigned int v0; // ebx
  HKEY phkResult; // [rsp+40h] [rbp+10h] BYREF
  HKEY hKey; // [rsp+48h] [rbp+18h] BYREF

  phkResult = HKEY_CURRENT_USER_LOCAL_SETTINGS|0x7FFFFFF8LL;
  hKey = HKEY_CURRENT_USER_LOCAL_SETTINGS|0x7FFFFFF8LL;
  v0 = RegOpenKeyExW(
         hKey: HKEY_LOCAL_MACHINE,
         lpSubKey: L"System\\CurrentControlSet\\Control\\Power\\PowerRequestOverride",
         ulOptions: 0,
         samDesired: 0x20019u,
         phkResult: &hKey);
  if ( v0 == 0 )
  {
    PowercfgPrint(a1: 0, a2: L"[SERVICE]\n");
    if ( RegOpenKeyExW(hKey, lpSubKey: L"Service", ulOptions: 0, samDesired: 0x20019u, &phkResult) != 0 )
      goto LABEL_6;
    v0 = EnumeratePowerRequestOverrides(hKey: phkResult);
    if ( (unsigned __int64)phkResult - 1 <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      RegCloseKey(hKey: phkResult);
      phkResult = HKEY_CURRENT_USER_LOCAL_SETTINGS|0x7FFFFFF8LL;
    }
    if ( v0 == 0 )
    {
LABEL_6:
      PowercfgPrint(a1: 0, a2: L"\n");
      PowercfgPrint(a1: 0, a2: L"[PROCESS]\n");
      if ( RegOpenKeyExW(hKey, lpSubKey: L"Process", ulOptions: 0, samDesired: 0x20019u, &phkResult) != 0 )
        goto LABEL_10;
      v0 = EnumeratePowerRequestOverrides(hKey: phkResult);
      if ( (unsigned __int64)phkResult - 1 <= 0xFFFFFFFFFFFFFFFDuLL )
      {
        RegCloseKey(hKey: phkResult);
        phkResult = HKEY_CURRENT_USER_LOCAL_SETTINGS|0x7FFFFFF8LL;
      }
      if ( v0 == 0 )
      {
LABEL_10:
        PowercfgPrint(a1: 0, a2: L"\n");
        PowercfgPrint(a1: 0, a2: L"[DRIVER]\n");
        if ( RegOpenKeyExW(hKey, lpSubKey: L"Driver", ulOptions: 0, samDesired: 0x20019u, &phkResult) != 0 )
          goto LABEL_14;
        v0 = EnumeratePowerRequestOverrides(hKey: phkResult);
        if ( (unsigned __int64)phkResult - 1 <= 0xFFFFFFFFFFFFFFFDuLL )
        {
          RegCloseKey(hKey: phkResult);
          phkResult = HKEY_CURRENT_USER_LOCAL_SETTINGS|0x7FFFFFF8LL;
        }
        if ( v0 == 0 )
        {
LABEL_14:
          PowercfgPrint(a1: 0, a2: L"\n");
          v0 = 0;
        }
      }
    }
  }
  if ( (unsigned __int64)hKey - 1 <= 0xFFFFFFFFFFFFFFFDuLL )
    RegCloseKey(hKey);
  return v0;
}
