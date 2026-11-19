__int64 __fastcall DwmpActivateHardwareExpression(int a1, __int64 a2, int a3)
{
  int v4; // eax
  unsigned int v5; // ebx
  void *v7; // [rsp+28h] [rbp-30h]
  int v8; // [rsp+30h] [rbp-28h] BYREF
  _DWORD v9[4]; // [rsp+38h] [rbp-20h] BYREF

  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApipActivateHardwareExpression_Start,
      a3,
      a4: 1,
      a5: (__int64)v9);
  v9[0] = 1073741902;
  v9[1] = a1;
  v4 = CApiPortClient::SendRequest(this: (CApiPortClient *)&g_PortClient, a2: v9, a3: 8, a4: &v8, a5: nullptr, a6: 0);
  v5 = v4;
  if ( v4 >= 0 )
    v5 = v8;
  else
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA38, a3: 1u, a4: v4, a5: 0x23u, a6: v7);
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApipActivateHardwareExpression_Stop,
      a3: v5);
  return v5;
}
