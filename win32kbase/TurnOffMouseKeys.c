void __fastcall TurnOffMouseKeys()
{
  dword_1C024BBA4 &= ~1u;
  gdwPUDFlags &= ~0x2000u;
  MKHideMouseCursor();
  if ( (dword_1C024BBA4 & 0x10) != 0 )
    ApiSetEditionPostRitSound(a1: 1);
  ApiSetEditionPostAccessibility(a1: 3);
}
