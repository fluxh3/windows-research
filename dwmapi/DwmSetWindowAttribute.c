HRESULT __stdcall DwmSetWindowAttribute(HWND hwnd, DWORD dwAttribute, LPCVOID pvAttribute, DWORD cbAttribute)
{
  _DWORD *v5; // rbp
  int v8; // ebx
  wil::details::in1diag3 *v9; // rcx
  __int64 v10; // rdx
  signed int LastError; // eax
  unsigned int v13; // r8d
  HRESULT v14; // ebx
  int v15; // [rsp+20h] [rbp-28h] BYREF
  _DWORD *v16; // [rsp+28h] [rbp-20h]
  DWORD v17; // [rsp+30h] [rbp-18h]
  wil::details::in1diag3 *retaddr; // [rsp+48h] [rbp+0h]

  v5 = pvAttribute;
  if ( pvAttribute != nullptr && cbAttribute >= 4 )
  {
    if ( dwAttribute > 0x10000 )
    {
      if ( dwAttribute == 65537 )
      {
        v8 = 11;
      }
      else
      {
        if ( dwAttribute != 65538 )
        {
LABEL_29:
          switch ( dwAttribute )
          {
            case 0x11u:
              LOBYTE(pvAttribute) = 3;
              wil::details::FeatureImpl<__WilFeatureTraits_Feature_TabShell>::ReportUsage(
                this: (wil::details::FeatureImpl<struct __WilFeatureTraits_Feature_TabShell> *)`wil::Feature<__WilFeatureTraits_Feature_TabShell>::GetImpl'::`2'::impl,
                a2: false,
                a3: (enum wil::ReportingKind)pvAttribute,
                a4: *(unsigned __int64 *)&cbAttribute);
              v9 = retaddr;
              v10 = 162;
              break;
            case 0x12u:
              LOBYTE(pvAttribute) = 3;
              wil::details::FeatureImpl<__WilFeatureTraits_Feature_TabShell>::ReportUsage(
                this: (wil::details::FeatureImpl<struct __WilFeatureTraits_Feature_TabShell> *)`wil::Feature<__WilFeatureTraits_Feature_TabShell>::GetImpl'::`2'::impl,
                a2: false,
                a3: (enum wil::ReportingKind)pvAttribute,
                a4: *(unsigned __int64 *)&cbAttribute);
              v9 = retaddr;
              v10 = 169;
              break;
            case 0x13u:
              LOBYTE(pvAttribute) = 3;
              wil::details::FeatureImpl<__WilFeatureTraits_Feature_TabShell>::ReportUsage(
                this: (wil::details::FeatureImpl<struct __WilFeatureTraits_Feature_TabShell> *)`wil::Feature<__WilFeatureTraits_Feature_TabShell>::GetImpl'::`2'::impl,
                a2: false,
                a3: (enum wil::ReportingKind)pvAttribute,
                a4: *(unsigned __int64 *)&cbAttribute);
              v9 = retaddr;
              v10 = 178;
              break;
            default:
              v9 = retaddr;
              v10 = 185;
              break;
          }
          goto LABEL_25;
        }
        v8 = 12;
      }
    }
    else if ( dwAttribute == 0x10000 )
    {
      v8 = 10;
    }
    else
    {
      switch ( dwAttribute )
      {
        case 1u:
          v8 = 1;
          break;
        case 2u:
          v8 = 2;
          break;
        case 3u:
          v8 = 3;
          break;
        case 4u:
          v8 = 4;
          break;
        case 5u:
          v8 = 5;
          break;
        case 6u:
          v8 = 6;
          break;
        case 7u:
          v8 = 7;
          break;
        case 9u:
          v8 = 8;
          break;
        case 0xAu:
          v8 = 9;
          break;
        case 0xBu:
          v8 = 16;
          break;
        case 0xCu:
          v8 = 13;
          break;
        case 0xDu:
          v8 = 17;
          break;
        case 0xEu:
          v8 = 18;
          break;
        case 0xFu:
          v8 = 20;
          break;
        case 0x10u:
          v8 = 25;
          break;
        case 0x14u:
          v8 = 26;
          break;
        default:
          goto LABEL_29;
      }
      if ( dwAttribute == 15 && (unsigned int)IsShellManagedWindow(a1: hwnd) == 0 )
      {
        v9 = retaddr;
        v10 = 150;
LABEL_25:
        wil::details::in1diag3::Return_Hr(
          this: v9,
          a2: (void *)v10,
          a3: (unsigned int)"clientcore\\windows\\dwm\\dwmapi\\attribute.cpp",
          a4: (const char *)0x80070057LL,
          a5: v15);
        return -2147024809;
      }
    }
    v15 = v8;
    v16 = v5;
    v17 = cbAttribute;
    if ( (unsigned int)SetWindowCompositionAttribute(a1: hwnd, a2: &v15) != 0 )
      goto LABEL_47;
    LastError = GetLastError();
    v14 = LastError;
    if ( LastError > 0 )
      v14 = (unsigned __int16)LastError | 0x80070000;
    if ( v14 >= 0 )
    {
LABEL_47:
      if ( dwAttribute == 15 && cbAttribute == 4 && *v5 != 0 )
        DwmFlush();
      return 0;
    }
    else
    {
      if ( dwAttribute != 65537 )
        wil::details::in1diag3::_Log_Hr(
          this: retaddr,
          a2: (void *)0x9D,
          a3: v13,
          a4: (const char *)(unsigned int)v14,
          a5: v15);
      return v14;
    }
  }
  else
  {
    wil::details::in1diag3::Return_Hr(
      this: retaddr,
      a2: (void *)0x8E,
      a3: (unsigned int)"clientcore\\windows\\dwm\\dwmapi\\attribute.cpp",
      a4: (const char *)0x80070057LL,
      a5: v15);
    return -2147024809;
  }
}
