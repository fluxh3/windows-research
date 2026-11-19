HRESULT __stdcall DwmRegisterThumbnail(HWND hwndDestination, HWND hwndSource, PHTHUMBNAIL phThumbnailId)
{
  int v5; // eax
  unsigned int v6; // ebx
  void *v8; // [rsp+28h] [rbp-40h]
  _BYTE v9[16]; // [rsp+30h] [rbp-38h] BYREF

  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApiRegisterThumbnail_Start,
      a3: (_DWORD)phThumbnailId,
      a4: 1,
      a5: (__int64)v9);
  v5 = DwmpRegisterThumbnail(hWnd: hwndDestination, a2: (__int64)phThumbnailId);
  v6 = v5;
  if ( v5 < 0 )
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: v5, a5: 0x46u, a6: v8);
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApiRegisterThumbnail_Stop,
      a3: v6);
  return v6;
}
