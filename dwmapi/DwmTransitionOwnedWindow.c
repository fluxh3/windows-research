HRESULT __stdcall DwmTransitionOwnedWindow(HWND hwnd, enum DWMTRANSITION_OWNEDWINDOW_TARGET target)
{
  __int16 v2; // di
  unsigned int v4; // ebx
  DWORD dwProcessId; // [rsp+40h] [rbp+18h] BYREF

  v2 = target;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0pd_EtwEventWriteTransfer(
      a1: hwnd,
      a2: ApiTransitionOwnedWindow_Start,
      a3: hwnd,
      a4: (unsigned int)target);
  GetWindowThreadProcessId(hWnd: hwnd, lpdwProcessId: &dwProcessId);
  if ( dwProcessId == GetCurrentProcessId()
    && GetWindow(hWnd: hwnd, uCmd: 4u) != nullptr
    && GetAncestor(hwnd, gaFlags: 2u) == hwnd )
  {
    v4 = DwmpTransitionWindow(a1: hwnd, a2: v2 & 0xFFF | 0x80000000);
  }
  else
  {
    v4 = 0x80070057;
  }
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApiTransitionOwnedWindow_Stop,
      a3: v4);
  return v4;
}
