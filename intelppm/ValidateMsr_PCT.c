__int64 __fastcall ValidateMsr_PCT(__int64 a1)
{
  unsigned int v2; // ebx
  __int16 v3; // r9
  unsigned int Number; // [rsp+28h] [rbp-20h]
  int v6; // [rsp+30h] [rbp-18h]

  v2 = ((__int64 (*)(void))ValidateMsrGenAddr)();
  if ( (v2 & 0x80000000) == 0 )
  {
    if ( *(_QWORD *)(a1 + 4) != 0 )
    {
      if ( *(_QWORD *)(a1 + 16) == 0 )
        return 0;
      v2 = ValidateMsrGenAddr(a1: a1 + 12);
      if ( (v2 & 0x80000000) == 0 )
        return 0;
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        return v2;
      v3 = 36;
      v6 = v2;
    }
    else
    {
      v2 = 0xC000000D;
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        return v2;
      v3 = 35;
      v6 = -1073741811;
    }
    Number = KeGetPcr()->Prcb.Number;
    goto LABEL_4;
  }
  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    v3 = 34;
    v6 = v2;
    Number = KeGetPcr()->Prcb.Number;
LABEL_4:
    WPP_RECORDER_SF_dd(a1: *((_QWORD *)WPP_GLOBAL_Control + 8), a2: 2u, a3: 1u, a4: v3, a5: 0x1C0013E58LL, Number, v6);
  }
  return v2;
}
