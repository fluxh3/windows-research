__int64 __fastcall DwmTetherContact(int a1, int a2, __int64 a3)
{
  __int64 ThreadDpiAwarenessContext; // rax
  CApiPortClient *v6; // rcx
  int v7; // eax
  unsigned int v8; // ebx
  void *v10; // [rsp+28h] [rbp-40h]
  __int64 v11; // [rsp+30h] [rbp-38h] BYREF
  _DWORD v12[3]; // [rsp+38h] [rbp-30h] BYREF
  __int64 v13; // [rsp+44h] [rbp-24h]

  v11 = a3;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApiTetherContact_Start,
      a3,
      a4: 1,
      a5: (__int64)v12);
  v12[0] = 1073741891;
  v13 = 0;
  v12[1] = a1;
  v12[2] = a2;
  ThreadDpiAwarenessContext = GetThreadDpiAwarenessContext();
  TransformPoint(a1: &v11, a2: -3, a3: ThreadDpiAwarenessContext);
  v13 = v11;
  v7 = CApiPortClient::SendNotification(this: v6, a2: v12, a3: 20);
  v8 = v7;
  if ( v7 < 0 )
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA38, a3: 1u, a4: v7, a5: 0xB1u, a6: v10);
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApiTetherContact_Stop,
      a3: v8);
  return v8;
}
