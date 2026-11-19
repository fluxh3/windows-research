__int64 __fastcall DwmpSetColorizationParameters(__int128 *a1, int a2, int a3)
{
  int v5; // eax
  unsigned int v6; // ebx
  int v7; // r9d
  unsigned int v9; // [rsp+20h] [rbp-60h]
  void *v10; // [rsp+28h] [rbp-58h]
  int v11; // [rsp+30h] [rbp-50h] BYREF
  int v12; // [rsp+38h] [rbp-48h] BYREF
  __int128 v13; // [rsp+3Ch] [rbp-44h]
  __int128 v14; // [rsp+4Ch] [rbp-34h]
  _BYTE v15[16]; // [rsp+60h] [rbp-20h] BYREF

  v13 = 0;
  v14 = 0;
  v12 = 1073741864;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApipSetColorizationColor_Start,
      a3,
      a4: 1,
      a5: (__int64)v15);
  if ( a1 == nullptr )
  {
    v6 = 0x80070057;
    v9 = 199;
    goto LABEL_17;
  }
  if ( a2 == 0 )
  {
    v5 = DwmpPersistColorizationParameters(a1);
    v6 = v5;
    if ( v5 < 0 )
    {
      v9 = 203;
      goto LABEL_8;
    }
  }
  v13 = *a1;
  v14 = a1[1];
  v5 = CApiPortClient::SendRequest(
         this: (CApiPortClient *)&g_PortClient,
         a2: &v12,
         a3: 36,
         a4: &v11,
         a5: nullptr,
         a6: 0);
  v6 = v5;
  if ( v5 < 0 )
  {
    v9 = 219;
LABEL_8:
    v7 = v5;
LABEL_9:
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001B190, a3: 3u, a4: v7, a5: v9, a6: v10);
    goto LABEL_10;
  }
  v6 = v11;
  if ( v11 < 0 )
  {
    v9 = 221;
LABEL_17:
    v7 = v6;
    goto LABEL_9;
  }
LABEL_10:
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApipSetColorizationColor_Stop,
      a3: v6);
  return v6;
}
