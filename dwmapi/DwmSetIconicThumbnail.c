HRESULT __stdcall DwmSetIconicThumbnail(HWND hwnd, HBITMAP hbmp, DWORD dwSITFlags)
{
  int *v5; // rdi
  void *v6; // r15
  bool v7; // bl
  HWND ShellWindow; // rax
  int ObjectW; // r12d
  signed int cx; // ebx
  signed int cy; // esi
  __int64 v12; // rcx
  unsigned int v13; // ebx
  int v14; // r9d
  int v15; // r12d
  CApiPortClient *v16; // rax
  char v17; // si
  int v18; // eax
  __int64 v19; // rcx
  int v20; // eax
  int v21; // eax
  unsigned int v23; // [rsp+20h] [rbp-A9h]
  void *v24; // [rsp+28h] [rbp-A1h]
  void *v25; // [rsp+28h] [rbp-A1h]
  char v26; // [rsp+30h] [rbp-99h]
  tagSIZE dwProcessId; // [rsp+38h] [rbp-91h] BYREF
  int v28; // [rsp+40h] [rbp-89h] BYREF
  tagSIZE v29; // [rsp+48h] [rbp-81h] BYREF
  void *v30; // [rsp+50h] [rbp-79h] BYREF
  int v31; // [rsp+58h] [rbp-71h] BYREF
  HWND v32; // [rsp+5Ch] [rbp-6Dh]
  signed int v33; // [rsp+64h] [rbp-65h]
  signed int v34; // [rsp+68h] [rbp-61h]
  int v35; // [rsp+6Ch] [rbp-5Dh]
  _BYTE pv[4]; // [rsp+70h] [rbp-59h] BYREF
  int v37; // [rsp+74h] [rbp-55h]
  int v38; // [rsp+78h] [rbp-51h]
  unsigned __int16 v39; // [rsp+82h] [rbp-47h]
  int v40; // [rsp+B0h] [rbp-19h]

  v28 = dwSITFlags;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0p_EtwEventWriteTransfer(a1: hwnd, a2: "\x1B", a3: hwnd);
  v5 = &g_PortClient;
  v26 = 0;
  v6 = nullptr;
  v30 = nullptr;
  v7 = false;
  ShellWindow = GetShellWindow();
  if ( ShellWindow != nullptr )
  {
    dwProcessId.cx = 0;
    GetWindowThreadProcessId(hWnd: ShellWindow, lpdwProcessId: (LPDWORD)&dwProcessId);
    v7 = GetCurrentProcessId() == dwProcessId.cx;
  }
  if ( hwnd == nullptr || hbmp == nullptr || !v7 && !IsHwndInProcess(hWnd: hwnd) )
  {
    v23 = 651;
    goto LABEL_45;
  }
  ObjectW = GetObjectW(h: hbmp, c: 104, pv);
  cx = abs32(v37);
  v29.cx = cx;
  cy = abs32(v38);
  v29.cy = cy;
  if ( (unsigned int)DwmGetIdealIconicThumbnailSize(a1: v12, a2: &dwProcessId) == 0 )
  {
    v13 = 0x80004005;
    v23 = 662;
LABEL_11:
    v14 = v13;
LABEL_46:
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001B848, a3: 2u, a4: v14, a5: v23, a6: v24);
    goto LABEL_47;
  }
  if ( ObjectW != 104 || v39 != 32 || v40 != 0 )
  {
    v23 = 669;
    goto LABEL_45;
  }
  if ( wil::details::FeatureImpl<__WilFeatureTraits_Feature_WindowTabHost>::__private_IsEnabled(this: (wil::details::FeatureImpl<struct __WilFeatureTraits_Feature_WindowTabHost> *)`wil::Feature<__WilFeatureTraits_Feature_WindowTabHost>::GetImpl'::`2'::impl) )
  {
    if ( (cx > dwProcessId.cx || cy > dwProcessId.cy) && GetWindowTabOwner(a1: hwnd) == nullptr )
    {
      v23 = 678;
LABEL_45:
      v14 = -2147024809;
      v13 = 0x80070057;
      goto LABEL_46;
    }
  }
  else if ( cx > dwProcessId.cx || cy > dwProcessId.cy )
  {
    v23 = 684;
    goto LABEL_45;
  }
  v15 = cy * cx * v39 / 8;
  if ( v15 <= 0 )
    goto LABEL_33;
  v16 = (CApiPortClient *)(*(__int64 (__fastcall **)(LPVOID, __int64))(*(_QWORD *)WPF::g_pProcessHeap + 8LL))(
                            a1: WPF::g_pProcessHeap,
                            a2: 80);
  if ( v16 != nullptr )
    v5 = (int *)CApiPortClient::CApiPortClient(this: v16, a2: v15);
  else
    v5 = nullptr;
  if ( v5 == nullptr )
  {
    v13 = 0x8007000E;
    v23 = 690;
    goto LABEL_11;
  }
  v17 = 1;
  v26 = 1;
  v18 = CApiPortClient::LockExtraDataPointer(this: (CApiPortClient *)v5, a2: v15, a3: &v30);
  v13 = v18;
  if ( v18 >= 0 )
  {
    v6 = v30;
    v20 = CopyBitmapHelper(hbm: hbmp, a2: &v29, a3: v15, a4: (char *)v30);
    v13 = v20;
    if ( v20 < 0 )
    {
      MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001B848, a3: 2u, a4: v20, a5: 0x2B6u, a6: v24);
      goto LABEL_37;
    }
    cy = v29.cy;
    cx = v29.cx;
LABEL_33:
    v32 = hwnd;
    v33 = cx;
    v34 = cy;
    v31 = 1073741881;
    v35 = v28;
    v21 = CApiPortClient::SendRequest(this: (CApiPortClient *)v5, a2: &v31, a3: 24, a4: &v28, a5: nullptr, a6: 0);
    v13 = v21;
    if ( v21 >= 0 )
      v13 = v28;
    else
      MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001B848, a3: 2u, a4: v21, a5: 0x2C2u, a6: v25);
    v17 = v26;
    goto LABEL_37;
  }
  MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001B848, a3: 2u, a4: v18, a5: 0x2B4u, a6: v24);
  v6 = v30;
LABEL_37:
  if ( v6 != nullptr )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v5 + 8));
  if ( v17 != 0 && v5 != nullptr )
    CApiPortClient::`scalar deleting destructor'(this: (CApiPortClient *)v5);
LABEL_47:
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0qp_EtwEventWriteTransfer(a1: v19, a2: ApiSetIconicThumbnail_Stop, a3: v13, a4: hwnd);
  return v13;
}
