int __fastcall sub_140024D10(HWND hWnd, __int64 a2, int a3)
{
  HWND DlgItem; // rbx
  HWND v7; // rbx
  HWND v8; // rcx
  HWND v9; // rbx
  HWND v10; // rcx
  HWND v11; // rbx
  HWND v12; // rcx
  HWND v13; // rax
  HWND v14; // rbx
  HWND v15; // rbx
  HWND v16; // rcx
  HWND v17; // rax

  SetDlgItemTextW(hDlg: hWnd, nIDDlgItem: 1152, lpString: *(LPCWSTR *)(a2 + 32));
  SendDlgItemMessageW(hDlg: hWnd, nIDDlgItem: 1152, Msg: 0xC5u, wParam: *(unsigned __int16 *)(a2 + 48) - 1LL, lParam: 0);
  SendMessageW(hWnd, Msg: 0x111u, wParam: 0x3000480u, lParam: 0);
  if ( *(char *)(a2 + 24) >= 0 )
  {
    DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1038);
    ShowWindow(hWnd: DlgItem, nCmdShow: 0);
    EnableWindow(hWnd: DlgItem, bEnable: false);
  }
  if ( (*(_DWORD *)(a2 + 24) & 0x10000) != 0 )
  {
    v7 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1040);
    ShowWindow(hWnd: v7, nCmdShow: 0);
    v8 = v7;
  }
  else
  {
    if ( (*(_DWORD *)(a2 + 24) & 0x1000) == 0 )
      goto LABEL_8;
    v8 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1040);
  }
  EnableWindow(hWnd: v8, bEnable: false);
LABEL_8:
  CheckDlgButton(hDlg: hWnd, nIDButton: 1040, uCheck: (*(_DWORD *)(a2 + 24) & 2) != 0);
  if ( (*(_DWORD *)(a2 + 24) & 0x8000) != 0 )
  {
    v9 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1041);
    ShowWindow(hWnd: v9, nCmdShow: 0);
    v10 = v9;
  }
  else
  {
    if ( (*(_DWORD *)(a2 + 24) & 0x800) == 0 )
      goto LABEL_13;
    v10 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1041);
  }
  EnableWindow(hWnd: v10, bEnable: false);
LABEL_13:
  CheckDlgButton(hDlg: hWnd, nIDButton: 1041, uCheck: (*(_DWORD *)(a2 + 24) & 4) != 0);
  if ( (*(_DWORD *)(a2 + 24) & 0x40000) != 0 )
  {
    if ( (*(_DWORD *)(a2 + 24) & 0x80000) == 0 )
      goto LABEL_18;
    v12 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1042);
  }
  else
  {
    v11 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1042);
    ShowWindow(hWnd: v11, nCmdShow: 0);
    v12 = v11;
  }
  EnableWindow(hWnd: v12, bEnable: false);
LABEL_18:
  CheckDlgButton(hDlg: hWnd, nIDButton: 1042, uCheck: (*(_DWORD *)(a2 + 24) & 0x100000) != 0);
  if ( (*(_DWORD *)(a2 + 24) & 0x4000) != 0 )
  {
    v13 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1072);
    ShowWindow(hWnd: v13, nCmdShow: 0);
    v14 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1056);
    ShowWindow(hWnd: v14, nCmdShow: 0);
    EnableWindow(hWnd: v14, bEnable: false);
    v15 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1057);
    ShowWindow(hWnd: v15, nCmdShow: 0);
    v16 = v15;
  }
  else
  {
    if ( (*(_DWORD *)(a2 + 24) & 0x400) == 0 )
      goto LABEL_23;
    v17 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1056);
    EnableWindow(hWnd: v17, bEnable: false);
    v16 = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1057);
  }
  EnableWindow(hWnd: v16, bEnable: false);
LABEL_23:
  if ( a3 == 0 )
    return CheckRadioButton(
             hDlg: hWnd,
             nIDFirstButton: 1056,
             nIDLastButton: 1057,
             nIDCheckButton: (*(_DWORD *)(a2 + 24) & 1) + 1056);
  SetDlgItemTextW(hDlg: hWnd, nIDDlgItem: 1153, lpString: *(LPCWSTR *)(a2 + 40));
  SendDlgItemMessageW(hDlg: hWnd, nIDDlgItem: 1153, Msg: 0xC5u, wParam: *(unsigned __int16 *)(a2 + 50) - 1LL, lParam: 0);
  return SendMessageW(hWnd, Msg: 0x111u, wParam: 0x3000481u, lParam: 0);
}
