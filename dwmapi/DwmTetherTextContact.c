__int64 __fastcall DwmTetherTextContact(unsigned int a1, int a2, __int64 a3, unsigned int a4)
{
  signed int LastError; // eax
  unsigned int v8; // ebx
  int v9; // r9d
  HMONITOR v10; // rax
  int v11; // eax
  __int64 ThreadDpiAwarenessContext; // rax
  CApiPortClient *v13; // rcx
  unsigned int v15; // [rsp+20h] [rbp-A9h]
  void *v16; // [rsp+28h] [rbp-A1h]
  __int64 v17; // [rsp+30h] [rbp-99h] BYREF
  _DWORD v18[6]; // [rsp+40h] [rbp-89h] BYREF
  HWND hwnd; // [rsp+58h] [rbp-71h]
  _OWORD v20[2]; // [rsp+A0h] [rbp-29h] BYREF
  int v21; // [rsp+C0h] [rbp-9h]
  _DWORD v22[5]; // [rsp+C8h] [rbp-1h] BYREF
  unsigned __int64 v23; // [rsp+DCh] [rbp+13h]

  v17 = a3;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApiTetherTextContact_Start,
      a3,
      a4: 1,
      a5: (__int64)v22);
  if ( (unsigned int)GetPointerInfo(a1, a2: v18) == 0 )
  {
    LastError = GetLastError();
    v8 = LastError;
    if ( LastError > 0 )
      v8 = (unsigned __int16)LastError | 0x80070000;
    if ( (v8 & 0x80000000) != 0 )
    {
      v15 = 212;
LABEL_8:
      v9 = v8;
      goto LABEL_16;
    }
  }
  if ( v18[0] != 2 )
  {
    v8 = 0x80070057;
    v15 = 217;
    goto LABEL_8;
  }
  v10 = MonitorFromWindow(hwnd, dwFlags: 1u);
  v21 = 0;
  *(_QWORD *)v22 = 100;
  *(_QWORD *)&v22[2] = 0x6000000064LL;
  v20[1] = 0;
  v20[0] = *(_OWORD *)v22;
  v11 = CImmersiveOrPrimaryMonitor::Init(this: (CImmersiveOrPrimaryMonitor *)v20, a2: v10);
  v8 = v11;
  if ( v11 >= 0 )
  {
    v22[0] = 1073741937;
    *(_QWORD *)&v22[3] = 0;
    v22[1] = a1;
    v22[2] = a2;
    v23 = 0;
    ThreadDpiAwarenessContext = GetThreadDpiAwarenessContext();
    TransformPoint(a1: &v17, a2: -3, a3: ThreadDpiAwarenessContext);
    *(_QWORD *)&v22[3] = v17;
    v23 = __PAIR64__(v20[0], a4);
    v11 = CApiPortClient::SendNotification(this: v13, a2: v22, a3: 28);
    v8 = v11;
    if ( v11 >= 0 )
      goto LABEL_17;
    v15 = 234;
  }
  else
  {
    v15 = 221;
  }
  v9 = v11;
LABEL_16:
  MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: v9, a5: v15, a6: v16);
LABEL_17:
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApiTetherTextContact_Stop,
      a3: v8);
  return v8;
}
