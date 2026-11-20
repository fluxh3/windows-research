static NSInstrumentation::CPointerHashTable *__fastcall NSInstrumentation::CPointerHashTable::Create(
        char storeHashInKey)
{
  _QWORD *PoolWithTag; // rax
  _QWORD *PoolWithTag_1; // rbx
  PVOID v4; // rax
  char v5; // al

  PoolWithTag = ExAllocatePoolWithTag(PoolType: PagedPoolSession, NumberOfBytes: 0x38u, Tag: 0x38497355u);
  PoolWithTag_1 = PoolWithTag;
  if ( PoolWithTag != nullptr )
  {
    PoolWithTag[4] = 0;
    *((_DWORD *)PoolWithTag + 10) = 0;
    *((_DWORD *)PoolWithTag + 11) = 0;
    *((_DWORD *)PoolWithTag + 12) = 0;
    *((_BYTE *)PoolWithTag + 52) &= ~1u;
    *((_DWORD *)PoolWithTag + 6) = 0;
    *((_DWORD *)PoolWithTag + 7) = 0;
    *PoolWithTag = 0;
    *((_DWORD *)PoolWithTag + 4) = 0;
    v4 = ExAllocatePoolWithTag(PoolType: PagedPoolSession, NumberOfBytes: 0x1000u, Tag: 0x38497355u);
    PoolWithTag_1[4] = v4;
    if ( v4 != nullptr )
    {
      memset(a1: v4, Val: 0, Size: 0x1000u);
      v5 = *((_BYTE *)PoolWithTag_1 + 52);
      *((_DWORD *)PoolWithTag_1 + 12) = 0;
      *((_DWORD *)PoolWithTag_1 + 10) = 256;
      *((_BYTE *)PoolWithTag_1 + 52) = storeHashInKey | v5 & 0xFE;
      *((_DWORD *)PoolWithTag_1 + 11) = 8;
      return (NSInstrumentation::CPointerHashTable *)PoolWithTag_1;
    }
    NSInstrumentation::CPointerHashTable::Destroy(P: PoolWithTag_1);
  }
  return nullptr;
}
