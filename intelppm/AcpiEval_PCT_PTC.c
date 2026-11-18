__int64 __fastcall AcpiEval_PCT_PTC(__int64 a1, int a2, __int64 a3)
{
  unsigned int v4; // eax
  int v6; // eax
  PVOID v7; // rsi
  int v8; // ebx
  __int64 v9; // rdx
  __int64 v10; // rdx
  int v12; // [rsp+40h] [rbp-39h] BYREF
  int v13; // [rsp+48h] [rbp-31h] BYREF
  PVOID P; // [rsp+50h] [rbp-29h] BYREF
  unsigned __int8 v15[2]; // [rsp+58h] [rbp-21h] BYREF
  int v16; // [rsp+5Ah] [rbp-1Fh]
  char *v17; // [rsp+60h] [rbp-19h]
  __int64 (__fastcall *v18)(); // [rsp+68h] [rbp-11h]
  char v19; // [rsp+70h] [rbp-9h]
  int v20; // [rsp+72h] [rbp-7h]
  char *v21; // [rsp+78h] [rbp-1h]
  __int64 (__fastcall *v22)(); // [rsp+80h] [rbp+7h]
  int v23; // [rsp+88h] [rbp+Fh] BYREF
  char v24; // [rsp+8Ch] [rbp+13h]

  v12 = a2;
  v13 = 0;
  v17 = "Control";
  v15[0] = 0;
  v18 = AcpiParseRegister;
  v21 = "Status";
  v22 = AcpiParseRegister;
  v4 = 32;
  v16 = 2;
  v19 = 1;
  if ( a2 != 1413697631 )
    v4 = 1024;
  v20 = 786434;
  v23 = a2;
  v24 = 0;
  P = nullptr;
  _InterlockedOr((volatile signed __int32 *)(a1 + 1092), v4);
  v6 = AcpiEvaluateMethod(a1, a2: v12, a3: nullptr, a4: &P, a5: &v13);
  v7 = P;
  v8 = v6;
  if ( v6 >= 0 )
  {
    if ( v13 != 0 )
    {
      v8 = AcpiParseCore(
             a1: v15,
             a2: 2,
             a3: (unsigned __int64)P + 12,
             a4: *((_DWORD *)P + 1) - 12,
             a5: a3,
             a6: 24,
             a7: (const char *)&v23,
             a8: 0);
      if ( v8 < 0 )
      {
        if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
          WPP_RECORDER_SF_s(
            a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
            a2: 2u,
            a3: 1u,
            a4: 19,
            a5: 0x1C00140F0LL,
            a6: (const char *)&v23);
      }
      else
      {
        AcpiTranslateAccessSize(a1: a3, a2: v9);
        AcpiTranslateAccessSize(a1: a3 + 12, a2: v10);
      }
    }
    else
    {
      if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        WPP_RECORDER_SF_s(
          a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
          a2: 2u,
          a3: 1u,
          a4: 18,
          a5: 0x1C00140F0LL,
          a6: (const char *)&v12);
      v8 = -1073741275;
    }
  }
  if ( v7 != nullptr )
    ExFreePoolWithTag(P: v7, Tag: 0);
  if ( v8 < 0 )
  {
    if ( v12 == 1413697631 )
      _InterlockedOr((volatile signed __int32 *)(a1 + 1096), 0x20u);
    else
      _InterlockedOr((volatile signed __int32 *)(a1 + 1096), 0x400u);
  }
  return (unsigned int)v8;
}
