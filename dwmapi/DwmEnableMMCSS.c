HRESULT __stdcall DwmEnableMMCSS(BOOL fEnableMMCSS)
{
  int v1; // r8d
  int v3; // eax
  unsigned int v4; // ebx
  int v6; // [rsp+30h] [rbp-28h] BYREF
  _DWORD v7[4]; // [rsp+38h] [rbp-20h] BYREF

  v6 = 0;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1 (on/off)
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApiEnableMMCSS_Start,
      a3: v1,
      a4: 1,
      a5: (__int64)v7);
  v7[0] = 1073741869;
  v7[1] = fEnableMMCSS;
  v3 = CApiPortClient::SendRequest(this: (CApiPortClient *)&g_PortClient, a2: v7, a3: 8, a4: &v6, a5: nullptr, a6: 0);
  v4 = v3;
  if ( v3 < 0 )
    DoStackCaptureDirect(a1: v3, a2: 0x25u);
  else
    v4 = v6;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1 (on/off)
    McTemplateU0q_EtwEventWriteTransfer(a1: Microsoft_Windows_Dwm_Api_Provider_Context, a2: ApiEnableMMCSS_Stop, a3: v4);
  return MilToDwmError(a1: v4);
}
