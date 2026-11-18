__int64 __fastcall AcpiEval_OSC(__int64 a1, _DWORD *a2, __int16 a3, _QWORD *a4)
{
  int v5; // ecx
  _DWORD *v8; // rbx
  unsigned __int16 v9; // r13
  unsigned int v10; // ebp
  _DWORD *PoolWithTag; // rax
  __int64 v12; // rcx
  int v13; // edi
  __int64 v15; // [rsp+78h] [rbp+10h] BYREF
  int v16; // [rsp+80h] [rbp+18h] BYREF

  LOWORD(v16) = a3;
  v5 = a2[5];
  v16 = 0;
  v8 = nullptr;
  if ( (unsigned int)(v5 - 1) > 4 )
  {
    v13 = -1073741823;
  }
  else
  {
    v9 = 4 * v5;
    v10 = 4 * v5 + 64;
    PoolWithTag = ExAllocatePoolWithTag(PoolType: PagedPool, NumberOfBytes: v10, Tag: 0x72637250u);
    v8 = PoolWithTag;
    if ( PoolWithTag == nullptr )
    {
      v13 = -1073741670;
LABEL_14:
      _InterlockedOr((volatile signed __int32 *)(a1 + 1096), 0x10000u);
      return (unsigned int)v13;
    }
    memset(a1: PoolWithTag, Val: 0, Size: v10);
    v8[2] = v10;
    *v8 = 1130980673;
    v8[1] = 1129533279;
    v8[3] = 4;
    v8[4] = 1048578;
    memcpy_s(a1: v8 + 5, DstSize: 0x10u, Src: a2, MaxCount: 0x10u);
    v12 = 4;
    if ( *((_WORD *)v8 + 9) >= 4u )
      v12 = *((unsigned __int16 *)v8 + 9);
    *(_DWORD *)((char *)v8 + v12 + 20) = 0x40000;
    *(_DWORD *)((char *)v8 + v12 + 24) = a2[4];
    *(_DWORD *)((char *)v8 + v12 + 28) = 0x40000;
    *(_DWORD *)((char *)v8 + v12 + 32) = a2[5];
    *(_WORD *)((char *)v8 + v12 + 36) = 2;
    *(_WORD *)((char *)v8 + v12 + 38) = v9;
    memcpy_s(a1: (char *)v8 + v12 + 40, DstSize: v9, Src: a2 + 6, MaxCount: v9);
    _InterlockedOr((volatile signed __int32 *)(a1 + 1092), 0x10000u);
    v15 = 0;
    v13 = AcpiEvaluateMethod(a1, a2: 0, a3: v8, a4: &v15, a5: &v16);
    if ( v13 >= 0 && v15 != 0 && a4 != nullptr )
      *a4 = v15 + 16;
  }
  if ( v8 != nullptr )
    ExFreePoolWithTag(P: v8, Tag: 0);
  if ( v13 < 0 )
    goto LABEL_14;
  return (unsigned int)v13;
}
