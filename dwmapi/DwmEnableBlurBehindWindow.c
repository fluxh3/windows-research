HRESULT __stdcall DwmEnableBlurBehindWindow(HWND hWnd, const DWM_BLURBEHIND *pBlurBehind)
{
  int v2; // r8d
  int *v3; // rdi
  HRGN hRgnBlur; // r14
  char v7; // r13
  LPRGNDATA v8; // r12
  DWORD dwFlags; // eax
  DWORD RegionData; // esi
  CApiPortClient *v11; // rax
  int v12; // eax
  HRESULT v13; // ebx
  int v14; // eax
  HDC DC; // rbx
  HDC v17; // rax
  signed int LastError; // eax
  int v19; // r9d
  unsigned int v20; // [rsp+20h] [rbp-50h]
  void *v21; // [rsp+28h] [rbp-48h]
  void *v22; // [rsp+28h] [rbp-48h]
  int v23; // [rsp+30h] [rbp-40h] BYREF
  __int128 v24; // [rsp+34h] [rbp-3Ch]
  _BOOL8 v25; // [rsp+44h] [rbp-2Ch]
  LPRGNDATA lpRgnData[2]; // [rsp+50h] [rbp-20h] BYREF

  v3 = &g_PortClient;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 )
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApiEnableBlurBehindWindow_Start,
      a3: v2,
      a4: 1,
      a5: (__int64)lpRgnData);
  hRgnBlur = nullptr;
  v7 = 0;
  lpRgnData[0] = nullptr;
  v8 = nullptr;
  if ( (unsigned int)IsTopLevelWindow(a1: hWnd) == 0
    || pBlurBehind == nullptr
    || (dwFlags = pBlurBehind->dwFlags, pBlurBehind->dwFlags == 0)
    || (dwFlags & 0xFFFFFFF8) != 0 )
  {
    v20 = 110;
    goto LABEL_43;
  }
  if ( (dwFlags & 2) != 0 )
    hRgnBlur = pBlurBehind->hRgnBlur;
  v23 = 1073741857;
  v25 = false;
  v24 = 0;
  DWORD2(v24) = dwFlags;
  HIDWORD(v24) = pBlurBehind->fEnable;
  *(_QWORD *)&v24 = hWnd;
  v25 = hRgnBlur != nullptr;
  HIDWORD(v25) = pBlurBehind->fTransitionOnMaximized;
  if ( hRgnBlur != nullptr )
  {
    if ( (unsigned int)IsWindowGdiScaled(a1: hWnd) != 0 )
    {
      DC = GetDC(hWnd);
      if ( DC != nullptr )
      {
        SetLastError(dwErrCode: 0);
        v17 = GetDC(hWnd);
        if ( (unsigned int)ScaleRgn(a1: v17, a2: hRgnBlur) == 0 )
        {
          LastError = GetLastError();
          v13 = LastError;
          if ( LastError > 0 )
            v13 = (unsigned __int16)LastError | 0x80070000;
          v20 = 139;
          if ( v13 >= 0 )
            v13 = -2003304445;
          goto LABEL_35;
        }
        ReleaseDC(hWnd, hDC: DC);
      }
    }
    RegionData = GetRegionData(hrgn: hRgnBlur, nCount: 0, lpRgnData: nullptr);
    if ( RegionData != 0 )
    {
      v11 = (CApiPortClient *)(*(__int64 (__fastcall **)(LPVOID, __int64))(*(_QWORD *)WPF::g_pProcessHeap + 8LL))(
                                a1: WPF::g_pProcessHeap,
                                a2: 80);
      if ( v11 != nullptr )
        v3 = (int *)CApiPortClient::CApiPortClient(this: v11, a2: RegionData);
      else
        v3 = nullptr;
      if ( v3 == nullptr )
      {
        v13 = -2147024882;
        v20 = 148;
LABEL_35:
        v19 = v13;
LABEL_44:
        MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: v19, a5: v20, a6: v21);
        goto LABEL_19;
      }
      v7 = 1;
      v12 = CApiPortClient::LockExtraDataPointer(this: (CApiPortClient *)v3, a2: RegionData, a3: (void **)lpRgnData);
      v13 = v12;
      if ( v12 < 0 )
      {
        MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: v12, a5: 0x97u, a6: v21);
        v8 = lpRgnData[0];
        goto LABEL_19;
      }
      v8 = lpRgnData[0];
      if ( GetRegionData(hrgn: hRgnBlur, nCount: RegionData, lpRgnData: lpRgnData[0]) == 0 )
      {
        v20 = 155;
LABEL_43:
        v19 = -2147024809;
        v13 = -2147024809;
        goto LABEL_44;
      }
    }
  }
  v14 = CApiPortClient::SendRequest(
          this: (CApiPortClient *)v3,
          a2: &v23,
          a3: 28,
          a4: (int *)lpRgnData,
          a5: nullptr,
          a6: 0);
  v13 = v14;
  if ( v14 < 0 )
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: v14, a5: 0xA4u, a6: v22);
  else
    v13 = (HRESULT)lpRgnData[0];
LABEL_19:
  (*(void (__fastcall **)(LPVOID, _QWORD))(*(_QWORD *)WPF::g_pProcessHeap + 32LL))(a1: WPF::g_pProcessHeap, a2: 0);
  if ( v8 != nullptr )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v3 + 8));
  if ( v7 != 0 && v3 != nullptr )
    CApiPortClient::`scalar deleting destructor'(this: (CApiPortClient *)v3);
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApiEnableBlurBehindWindow_Stop,
      a3: (unsigned int)v13);
  return v13;
}
