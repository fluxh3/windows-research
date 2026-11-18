__int64 __fastcall AcpiEval_PCCP(__int64 a1, _QWORD *a2)
{
  void *v4; // rbx
  int v5; // edi
  _QWORD *PoolWithTag; // rax
  _DWORD *v7; // r14
  unsigned __int8 v9[2]; // [rsp+40h] [rbp-30h] BYREF
  int v10; // [rsp+42h] [rbp-2Eh]
  char *v11; // [rsp+48h] [rbp-28h]
  __int64 v12; // [rsp+50h] [rbp-20h]
  char v13; // [rsp+58h] [rbp-18h]
  int v14; // [rsp+5Ah] [rbp-16h]
  char *v15; // [rsp+60h] [rbp-10h]
  __int64 v16; // [rsp+68h] [rbp-8h]
  int v17; // [rsp+A0h] [rbp+30h] BYREF
  PVOID P; // [rsp+B0h] [rbp+40h] BYREF

  v13 = 1;
  v17 = 0;
  v11 = "InputBufferOffset";
  v9[0] = 0;
  v10 = 0;
  v15 = "OutputBufferOffset";
  v12 = 0x1C0025870LL;
  v4 = nullptr;
  v14 = 0x40000;
  v16 = 0x1C0025870LL;
  P = nullptr;
  _InterlockedOr((volatile signed __int32 *)(a1 + 1092), 0x8000u);
  v5 = AcpiEvaluateMethod(a1, a2: 1346585424, a3: nullptr, a4: &P, a5: &v17);
  if ( v5 < 0 )
    goto LABEL_13;
  *(_QWORD *)(a1 + 264) |= *(_DWORD *)(a1 + 272) & 0x80000000;
  if ( v17 == 0 )
  {
    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      WPP_RECORDER_SF_(a1: *((_QWORD *)WPP_GLOBAL_Control + 8), a2: 2u, a3: 1u, a4: 45, a5: 0x1C00140F0LL);
    v5 = -1073741275;
    goto LABEL_13;
  }
  PoolWithTag = ExAllocatePoolWithTag(PoolType: NonPagedPoolNx, NumberOfBytes: 8u, Tag: 0x72637250u);
  v4 = PoolWithTag;
  if ( PoolWithTag == nullptr )
  {
    v5 = -1073741670;
LABEL_13:
    _InterlockedOr((volatile signed __int32 *)(a1 + 1096), 0x8000u);
    v7 = P;
    goto LABEL_14;
  }
  v7 = P;
  *PoolWithTag = 0;
  v5 = AcpiParseCore(
         a1: v9,
         a2: 2,
         a3: (unsigned __int64)(v7 + 3),
         a4: v7[1] - 12,
         a5: (__int64)PoolWithTag,
         a6: 8,
         a7: "PCCP",
         a8: 0);
  if ( v5 >= 0 )
  {
    *a2 = v4;
    v4 = nullptr;
  }
  else if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    WPP_RECORDER_SF_(a1: *((_QWORD *)WPP_GLOBAL_Control + 8), a2: 2u, a3: 1u, a4: 46, a5: 0x1C00140F0LL);
  }
  if ( v5 < 0 )
    goto LABEL_13;
LABEL_14:
  if ( v4 != nullptr )
    ExFreePoolWithTag(P: v4, Tag: 0);
  if ( v7 != nullptr )
    ExFreePoolWithTag(P: v7, Tag: 0);
  return (unsigned int)v5;
}
