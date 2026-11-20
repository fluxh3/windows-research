void __fastcall ReadTabletButtonSettings()
{
  unsigned int i; // edi
  unsigned __int64 v1; // rbx
  unsigned int v2; // [rsp+30h] [rbp+8h] BYREF

  for ( i = 0; i < 0xA; ++i )
  {
    v2 = 0;
    if ( (int)ReadTabletButtonIndex(a1: i, a2: &v2) >= 0 )
    {
      v1 = (unsigned __int64)v2 << 7;
      ReadTabletButtonConfig(
        a1: i,
        a2: L"PrimaryLandscape",
        a3: (struct tagTABLET_BUTTON_DESK_CONFIG *)((char *)&TabButtonConfig + v1));
      ReadTabletButtonConfig(
        a1: i,
        a2: L"PrimaryPortrait",
        a3: (struct tagTABLET_BUTTON_DESK_CONFIG *)((char *)qword_1C033DA20 + v1));
      ReadTabletButtonConfig(
        a1: i,
        a2: L"SecondaryLandscape",
        a3: (struct tagTABLET_BUTTON_DESK_CONFIG *)((char *)qword_1C033DA40 + v1));
      ReadTabletButtonConfig(
        a1: i,
        a2: L"SecondaryPortrait",
        a3: (struct tagTABLET_BUTTON_DESK_CONFIG *)((char *)qword_1C033DA60 + v1));
    }
  }
}
