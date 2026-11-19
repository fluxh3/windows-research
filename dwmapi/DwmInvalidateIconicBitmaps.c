HRESULT __stdcall DwmInvalidateIconicBitmaps(HWND hwnd)
{
  int v2; // eax
  __int64 v3; // rcx
  unsigned int v4; // ebx
  void *v6; // [rsp+28h] [rbp-20h]
  void *v7; // [rsp+28h] [rbp-20h]
  int v8; // [rsp+30h] [rbp-18h] BYREF
  HWND v9; // [rsp+34h] [rbp-14h]
  int v10; // [rsp+50h] [rbp+8h] BYREF

  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0p_EtwEventWriteTransfer(a1: hwnd, a2: ApiInvalidateIconicBitmaps_Start, a3: hwnd);
  if ( hwnd != nullptr && IsHwndInProcess(hWnd: hwnd) )
  {
    v8 = 1073741885;
    v9 = hwnd;
    v2 = CApiPortClient::SendRequest(
           this: (CApiPortClient *)&g_PortClient,
           a2: &v8,
           a3: 12,
           a4: &v10,
           a5: nullptr,
           a6: 0);
    v4 = v2;
    if ( v2 < 0 )
      MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: v2, a5: 0x429u, a6: v7);
    else
      v4 = v10;
  }
  else
  {
    v4 = 0x80070057;
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: -2147024809, a5: 0x420u, a6: v6);
  }
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0qp_EtwEventWriteTransfer(a1: v3, a2: ApiInvalidateIconicBitmaps_Stop, a3: v4, a4: hwnd);
  return v4;
}
