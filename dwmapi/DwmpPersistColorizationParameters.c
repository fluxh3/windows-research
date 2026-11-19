__int64 __fastcall DwmpPersistColorizationParameters(unsigned int *a1)
{
  LSTATUS v2; // eax
  signed int v3; // ebx
  int v4; // eax
  unsigned int v6; // edx
  int v7; // ecx
  HKEY hKey; // [rsp+60h] [rbp+8h] BYREF

  hKey = nullptr;
  if ( a1 == nullptr )
  {
    v3 = -2147024809;
    v6 = 138;
LABEL_17:
    v7 = v3;
    goto LABEL_26;
  }
  v2 = RegCreateKeyExW(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: L"Software\\Microsoft\\Windows\\DWM",
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 2u,
         lpSecurityAttributes: nullptr,
         phkResult: &hKey,
         lpdwDisposition: nullptr);
  v3 = v2;
  if ( v2 > 0 )
    v3 = (unsigned __int16)v2 | 0x80070000;
  if ( v3 < 0 )
  {
    v6 = 150;
    goto LABEL_17;
  }
  v4 = DwmpSaveColorizationParameter(a1: hKey, a2: L"ColorizationColor", a3: *a1);
  v3 = v4;
  if ( v4 < 0 )
  {
    v6 = 152;
  }
  else
  {
    v4 = DwmpSaveColorizationParameter(a1: hKey, a2: L"ColorizationColorBalance", a3: a1[2]);
    v3 = v4;
    if ( v4 < 0 )
    {
      v6 = 153;
    }
    else
    {
      v4 = DwmpSaveColorizationParameter(a1: hKey, a2: L"ColorizationAfterglow", a3: a1[1]);
      v3 = v4;
      if ( v4 < 0 )
      {
        v6 = 154;
      }
      else
      {
        v4 = DwmpSaveColorizationParameter(a1: hKey, a2: L"ColorizationAfterglowBalance", a3: a1[3]);
        v3 = v4;
        if ( v4 < 0 )
        {
          v6 = 155;
        }
        else
        {
          v4 = DwmpSaveColorizationParameter(a1: hKey, a2: L"ColorizationBlurBalance", a3: a1[4]);
          v3 = v4;
          if ( v4 < 0 )
          {
            v6 = 156;
          }
          else
          {
            v4 = DwmpSaveColorizationParameter(a1: hKey, a2: L"EnableWindowColorization", a3: a1[5]);
            v3 = v4;
            if ( v4 < 0 )
            {
              v6 = 157;
            }
            else
            {
              v4 = DwmpSaveColorizationParameter(a1: hKey, a2: L"ColorizationGlassAttribute", a3: a1[6]);
              v3 = v4;
              if ( v4 >= 0 )
                goto LABEL_12;
              v6 = 158;
            }
          }
        }
      }
    }
  }
  v7 = v4;
LABEL_26:
  DoStackCaptureDirect(a1: v7, a2: v6);
LABEL_12:
  if ( hKey != nullptr )
    RegCloseKey(hKey);
  return (unsigned int)v3;
}
