HRESULT __stdcall DwmIsCompositionEnabled(BOOL *pfEnabled)
{
  void (__fastcall *v2)(int *); // rax
  int pvParam; // [rsp+20h] [rbp-18h] BYREF
  char v5; // [rsp+24h] [rbp-14h]
  int v6; // [rsp+40h] [rbp+8h] BYREF

  if ( pfEnabled != nullptr )
  {
    v2 = (void (__fastcall *)(int *))qword_180022AF8;
    v6 = 0;
    if ( qword_180022AF8 != 0
      || (v2 = (void (__fastcall *)(int *))SbSelectProcedure(a1: 2880154539LL, a2: 0, a3: "kLsE", a4: 0),
          qword_180022AF8 = (__int64)v2,
          v2 != nullptr) )
    {
      v2(a1: &v6);
    }
    pvParam = 16;
    if ( SystemParametersInfoW(uiAction: 0x42u, uiParam: 0x10u, &pvParam, fWinIni: 0) && (v5 & 1) != 0 && v6 == 0 ) // 0..1..10
      *pfEnabled = false;
    else
      *pfEnabled = IsThreadDesktopComposited();
    return 0;
  }
  else
  {
    DoStackCaptureDirect(a1: -2147024809, a2: 0x26u);
    return -2147024809;
  }
}
