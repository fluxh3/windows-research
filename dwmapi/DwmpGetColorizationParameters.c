__int64 __fastcall DwmpGetColorizationParameters(__int64 a1, __int64 a2, int a3)
{
  int ColorizationParameters; // eax
  unsigned int v5; // ebx
  void *v7; // [rsp+28h] [rbp-30h]
  _BYTE v8[16]; // [rsp+30h] [rbp-28h] BYREF

  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApiGetColorizationColor_Start,
      a3,
      a4: 1,
      a5: (__int64)v8);
  if ( a1 != 0 )
  {
    ColorizationParameters = DwmpReadColorizationParameters(a1);
    v5 = ColorizationParameters;
    if ( ColorizationParameters < 0 )
      MilInstrumentationCheckHR_MaybeFailFast(
        a1: 4u,
        a2: &qword_18001B190,
        a3: 3u,
        a4: ColorizationParameters,
        a5: 0x103u,
        a6: v7);
  }
  else
  {
    v5 = 0x80070057;
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001B190, a3: 3u, a4: -2147024809, a5: 0x101u, a6: v7);
  }
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApiGetColorizationColor_Stop,
      a3: v5);
  return v5;
}
