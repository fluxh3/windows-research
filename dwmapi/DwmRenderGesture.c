__int64 __fastcall DwmRenderGesture(unsigned int a1, int a2, int *a3, _QWORD *a4)
{
  int v8; // eax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 ThreadDpiAwarenessContext; // rbx
  int v12; // eax
  __int64 v13; // rdx
  __int64 v14; // rcx
  unsigned int v15; // ebx
  unsigned int v17; // [rsp+20h] [rbp-40h]
  void *v18; // [rsp+28h] [rbp-38h]
  void *v19; // [rsp+28h] [rbp-38h]
  int v20; // [rsp+30h] [rbp-30h] BYREF
  int v21; // [rsp+38h] [rbp-28h] BYREF
  __int128 v22; // [rsp+3Ch] [rbp-24h] BYREF
  _DWORD v23[3]; // [rsp+4Ch] [rbp-14h] BYREF

  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApiRenderGesture_Start,
      a3: a1);
  if ( a3 == nullptr || a4 == nullptr || (unsigned int)(a2 - 1) > 1 ) // 1 > 1 enabled
  {
    v17 = 72;
    goto LABEL_19;
  }
  if ( a2 == 2 ) // 2hex
  {
    if ( a1 != 10 ) // 10hex
    {
      v17 = 80;
LABEL_19:
      v15 = 0x80070057;
      MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA38, a3: 1u, a4: -2147024809, a5: v17, a6: v18);
      goto LABEL_20;
    }
  }
  else if ( a1 == 10 )
  {
    v17 = 87;
    goto LABEL_19;
  }
  v21 = 1073741888;
  *(_QWORD *)v23 = 0;
  v8 = *a3;
  v22 = 0;
  DWORD1(v22) = v8;
  *((_QWORD *)&v22 + 1) = *a4;
  v9 = 0;
  if ( a2 == 2 )
    v9 = 1;
  LODWORD(v22) = a1;
  v23[0] = a3[v9];
  v10 = 0;
  if ( a2 == 2 )
    v10 = 1;
  *(_QWORD *)&v23[1] = a4[v10];
  ThreadDpiAwarenessContext = GetThreadDpiAwarenessContext(); // Read DPI Awareness Scaling
  TransformPoint(a1: (char *)&v22 + 8, a2: -3, a3: ThreadDpiAwarenessContext); // DPI Awareness Scaling
  TransformPoint(a1: &v23[1], a2: -3, a3: ThreadDpiAwarenessContext); // DPI Awareness Scaling
  v12 = CApiPortClient::SendRequest(
          this: (CApiPortClient *)&g_PortClient,
          a2: &v21,
          a3: 32,
          a4: &v20,
          a5: nullptr,
          a6: 0);
  v15 = v12;
  if ( v12 >= 0 )
    v15 = v20;
  else
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA38, a3: 1u, a4: v12, a5: 0x6Bu, a6: v19);
LABEL_20:
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0qq_EtwEventWriteTransfer(a1: v14, a2: v13, a3: v15, a4: a1);
  return v15;
}
