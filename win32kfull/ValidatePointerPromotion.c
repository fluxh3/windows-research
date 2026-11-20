__int64 __fastcall ValidatePointerPromotion(
        unsigned __int16 a1,
        unsigned int a2,
        unsigned int *a3,
        struct tagMOUSE_PROMOTION_ENTRY **a4,
        struct tagMOUSE_PROMOTION_ENTRY **a5)
{
  unsigned int n0x10000000; // ebx
  __int16 *CacheById; // rax
  __int16 *CacheById_1; // rdi
  const struct tagMOUSE_PROMOTION_QUEUE *v11; // rcx
  struct tagMOUSE_PROMOTION_ENTRY *MousePromotionEntry_1; // r8
  struct tagMOUSE_PROMOTION_ENTRY *MousePromotionEntry_2; // r9
  struct tagMOUSE_PROMOTION_ENTRY *MousePromotionEntry; // rax
  unsigned int v15; // r10d
  struct tagMOUSE_PROMOTION_ENTRY **v16; // rax
  int v18; // eax
  struct tagMOUSE_PROMOTION_ENTRY *MousePromotionEntry_3; // [rsp+20h] [rbp-38h] BYREF
  struct tagMOUSE_PROMOTION_ENTRY *MousePromotionEntry_4; // [rsp+28h] [rbp-30h] BYREF
  unsigned int v21; // [rsp+70h] [rbp+18h] BYREF

  n0x10000000 = *a3;
  MousePromotionEntry_3 = nullptr;
  MousePromotionEntry_4 = nullptr;
  CacheById = (__int16 *)FindCacheById(a1, a2: &v21);
  CacheById_1 = CacheById;
  if ( CacheById == nullptr || CacheById == &word_1C033BAC8 && (dword_1C033BBC8 & 2) != 0 )
    return 0;
  v11 = (const struct tagMOUSE_PROMOTION_QUEUE *)(CacheById + 4);
  if ( n0x10000000 != 0 )
  {
    if ( (unsigned int)FindMousePromotionInContactRange(
                         a1: v11,
                         a2,
                         p_MousePromotionEntry: &MousePromotionEntry_3,
                         p_MousePromotionEntry: &MousePromotionEntry_4) != 0 )
    {
      MousePromotionEntry_1 = MousePromotionEntry_3;
      MousePromotionEntry_2 = MousePromotionEntry_4;
    }
    else
    {
      MousePromotionEntry_1 = nullptr;
      MousePromotionEntry_2 = nullptr;
    }
  }
  else
  {
    MousePromotionEntry = FindMousePromotionEntry(a1: v11, a2);
    MousePromotionEntry_1 = MousePromotionEntry;
    if ( MousePromotionEntry != nullptr && (*((_DWORD *)MousePromotionEntry + 5) & 0x40004) != 0 )
      MousePromotionEntry_1 = nullptr;
    MousePromotionEntry_2 = MousePromotionEntry_1;
  }
  if ( MousePromotionEntry_1 == nullptr )
    return 0;
  if ( n0x10000000 != 0x10000000
    || (n0x10000000 = DetectPromotionType(
                        MousePromotionEntry: MousePromotionEntry_1,
                        MousePromotionEntry: MousePromotionEntry_2)) != v15 )
  {
    v18 = n0x10000000 & 0x20000;
    if ( MousePromotionEntry_2 != nullptr )
    {
      if ( v18 != 0 && *((_DWORD *)MousePromotionEntry_2 + 9) != a2
        || (n0x10000000 & 0x1000000) == 0 && (*((_DWORD *)MousePromotionEntry_2 + 5) & 0x8000) != 0 )
      {
        return 0;
      }
    }
    else if ( v18 != 0 || CacheById_1 != &word_1C033BAC8 )
    {
      return 0;
    }
    *a3 = n0x10000000;
    goto LABEL_17;
  }
  if ( CacheById_1 == &word_1C033BAC8 )
  {
    *a3 = v15;
LABEL_17:
    v16 = a5;
    *a4 = MousePromotionEntry_1;
    *v16 = MousePromotionEntry_2;
    return 1;
  }
  return 0;
}
