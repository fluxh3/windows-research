__int64 __fastcall AcpiEval_PDC(__int64 a1, const void *a2, unsigned __int16 a3)
{
  rsize_t v5; // rbp
  unsigned int v6; // ebx
  int *PoolWithTag; // rax
  int *v8; // rsi
  int v9; // ebx
  int v11; // [rsp+60h] [rbp+18h] BYREF
  PVOID P; // [rsp+68h] [rbp+20h] BYREF

  v11 = 0;
  P = nullptr;
  v5 = a3;
  v6 = a3 + 24;
  PoolWithTag = (int *)ExAllocatePoolWithTag(PoolType: PagedPool, NumberOfBytes: v6, Tag: 0x72637250u);
  v8 = PoolWithTag;
  if ( PoolWithTag == nullptr )
  {
    v9 = -1073741670;
LABEL_6:
    _InterlockedOr((volatile signed __int32 *)(a1 + 1096), 0x20000u);
    return (unsigned int)v9;
  }
  *PoolWithTag = 1130980673;
  PoolWithTag[1] = 1128550495;
  PoolWithTag[2] = v6;
  PoolWithTag[3] = 1;
  *((_WORD *)PoolWithTag + 9) = v5;
  *((_WORD *)PoolWithTag + 8) = 2;
  memcpy_s(a1: PoolWithTag + 5, DstSize: v5, Src: a2, MaxCount: v5);
  _InterlockedOr((volatile signed __int32 *)(a1 + 1092), 0x20000u);
  v9 = AcpiEvaluateMethod(a1, a2: 0, a3: v8, a4: &P, a5: &v11);
  ExFreePoolWithTag(P: v8, Tag: 0);
  if ( P != nullptr )
    ExFreePoolWithTag(P, Tag: 0);
  if ( v9 < 0 )
    goto LABEL_6;
  return (unsigned int)v9;
}
