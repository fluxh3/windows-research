HRESULT __stdcall DwmFlush()
{
  int v0; // r8d
  int v1; // eax
  unsigned int v2; // ebx
  unsigned int v4; // edx
  int v5; // ecx
  int v6; // [rsp+30h] [rbp-28h] BYREF
  _DWORD v7[4]; // [rsp+38h] [rbp-20h] BYREF

  v6 = 0;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApiFlush_Start,
      a3: v0,
      a4: 1,
      a5: (__int64)v7);
  v7[0] = -2147483639;
  v7[1] = 0;
  v1 = CApiPortClient::SendRequest(this: (CApiPortClient *)&g_PortClient, a2: v7, a3: 8, a4: &v6, a5: nullptr, a6: 0);
  v2 = v1;
  if ( v1 < 0 )
  {
    v4 = 174;
    v5 = v1;
  }
  else
  {
    v2 = v6;
    if ( v6 >= 0 )
      goto LABEL_5;
    v4 = 176;
    v5 = v6;
  }
  DoStackCaptureDirect(a1: v5, a2: v4);
LABEL_5:
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(a1: Microsoft_Windows_Dwm_Api_Provider_Context, a2: ApiFlush_Stop, a3: v2);
  return v2;
}
