__int64 __fastcall ShouldHaveShadow(__int64 a1)
{
  unsigned int __imp_gbDisableAlpha; // r9d
  _QWORD *v2; // r10
  __int64 v4; // rax
  unsigned int __imp_gbDisableAlpha_1; // eax

  if ( (unsigned int)IsTopLevelWindow(a1) != 0
    && gbDisableAlpha == __imp_gbDisableAlpha
    && gcOverlays == __imp_gbDisableAlpha
    && ((unsigned int)gpdwCPUserPreferencesMask & 0x80040000) == 0x80040000
    && (*(_BYTE *)(*(_QWORD *)(v2[17] + 8LL) + 10LL) & 2) != 0 )
  {
    v4 = v2[2];
    if ( *(_DWORD *)(v4 + 624) > 0x9900u )
      __imp_gbDisableAlpha_1 = __imp_gbDisableAlpha;
    else
      __imp_gbDisableAlpha_1 = *(_DWORD *)(v4 + 640);
    if ( (__imp_gbDisableAlpha_1 & 0x400000) == 0
      && ((*(_WORD *)(v2[5] + 42LL) & 0x3FFF) != 0x29C
       || ((unsigned int)gpdwCPUserPreferencesMask & 0x80000200) == 0x80000200
       || ((unsigned int)gpdwCPUserPreferencesMask & 0x80000002) != 0x80000002) )
    {
      return 1;
    }
  }
  return __imp_gbDisableAlpha;
}
