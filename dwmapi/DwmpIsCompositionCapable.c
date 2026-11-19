__int64 __fastcall DwmpIsCompositionCapable(__int64 a1, _DWORD *a2, int a3)
{
  unsigned int v3; // ebx
  _BYTE v6[16]; // [rsp+30h] [rbp-28h] BYREF

  v3 = 0;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApipIsCompositionCapable_Start,
      a3,
      a4: 1,
      a5: (__int64)v6);
  if ( a2 != nullptr )
  {
    *a2 = 1;
  }
  else
  {
    v3 = 0x80070057;
    DoStackCaptureDirect(a1: -2147024809, a2: 0x7Cu);
  }
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApipIsCompositionCapable_Stop,
      a3: v3);
  return v3;
}
