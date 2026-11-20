__int64 __fastcall UpdatePerUserKeyboardIndicators(__int64 a1)
{
  __int64 __imp_gProtocolType; // rax
  __int64 v2; // rbx
  unsigned int v3; // eax
  char v4; // cl
  __int64 __imp_gafAsyncKeyState; // rcx
  unsigned int v6; // [rsp+48h] [rbp+10h] BYREF

  v6 = 0x80000000;
  __imp_gProtocolType = gProtocolType;
  v2 = *(_QWORD *)(gptiCurrent + 424LL);
  if ( gProtocolType == 0 )
  {
    FastGetProfileIntW(a1, a2: 13, a3: L"InitialKeyboardIndicators", a4: 0x80000000LL, a5: &v6, a6: 0);
    v3 = v6 & 0x80000002;
    v6 = v3;
    if ( v3 == 0x80000000 )
    {
      LOWORD(v3) = gklpBootTime[1];
      v6 = (unsigned __int16)v3;
    }
    v4 = *(_BYTE *)(v2 + 264);
    if ( (v3 & 2) != 0 )
    {
      *(_BYTE *)(v2 + 264) = v4 | 2;
      __imp_gafAsyncKeyState = gafAsyncKeyState;
      *((_BYTE *)&gafAsyncKeyState + 36) |= 2u;
      gafRawKeyState[36] |= 2u;
    }
    else
    {
      *(_BYTE *)(v2 + 264) = v4 & 0xFD;
      __imp_gafAsyncKeyState = gafAsyncKeyState;
      *((_BYTE *)&gafAsyncKeyState + 36) &= ~2u;
      gafRawKeyState[36] &= ~2u;
    }
    gfKanaToggle = 0;
    *(_BYTE *)(v2 + 233) &= ~8u;
    *(_BYTE *)(__imp_gafAsyncKeyState + 5) &= ~8u;
    gafRawKeyState[5] &= ~8u;
    return UpdateKeyLights(a1: 0);
  }
  return __imp_gProtocolType;
}
