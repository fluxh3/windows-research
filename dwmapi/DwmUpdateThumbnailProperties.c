HRESULT __stdcall DwmUpdateThumbnailProperties(HTHUMBNAIL hThumbnailId, const DWM_THUMBNAIL_PROPERTIES *ptnProperties)
{
  int v2; // r8d
  DWORD CurrentProcessId; // eax
  __int128 v6; // xmm0
  __int128 v7; // xmm1
  int v8; // eax
  unsigned int v9; // ebx
  void *v11; // [rsp+28h] [rbp-21h]
  void *v12; // [rsp+28h] [rbp-21h]
  int v13; // [rsp+30h] [rbp-19h] BYREF
  unsigned __int64 v14; // [rsp+34h] [rbp-15h]
  __int128 v15; // [rsp+3Ch] [rbp-Dh]
  __int128 v16; // [rsp+4Ch] [rbp+3h]
  __int64 v17; // [rsp+5Ch] [rbp+13h]
  int v18; // [rsp+64h] [rbp+1Bh]
  char v19; // [rsp+68h] [rbp+1Fh]
  int v20[4]; // [rsp+70h] [rbp+27h] BYREF

  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApiUpdateThumbnailProperties_Start,
      a3: v2,
      a4: 1,
      a5: (__int64)v20);
  if ( hThumbnailId != nullptr
    && ptnProperties != nullptr
    && ptnProperties->dwFlags != 0
    && ((ptnProperties->dwFlags & 1) == 0 || IsValidRect(a1: &ptnProperties->rcDestination))
    && ((ptnProperties->dwFlags & 2) == 0 || IsValidRect(a1: &ptnProperties->rcSource)) )
  {
    v13 = 1073741855;
    CurrentProcessId = GetCurrentProcessId();
    v6 = *(_OWORD *)&ptnProperties->dwFlags;
    v7 = *(_OWORD *)&ptnProperties->rcDestination.bottom;
    *(_QWORD *)v20 = __PAIR64__(CurrentProcessId, (unsigned int)hThumbnailId);
    v14 = __PAIR64__(CurrentProcessId, (unsigned int)hThumbnailId);
    v18 = *(BOOL *)((char *)&ptnProperties->fVisible + 3);
    LOBYTE(CurrentProcessId) = HIBYTE(ptnProperties->fSourceClientAreaOnly);
    v15 = v6;
    *(_QWORD *)&v6 = *(_QWORD *)&ptnProperties->rcSource.bottom;
    v19 = CurrentProcessId;
    v16 = v7;
    v17 = v6;
    v8 = CApiPortClient::SendRequest(
           this: (CApiPortClient *)&g_PortClient,
           a2: &v13,
           a3: 57,
           a4: v20,
           a5: nullptr,
           a6: 0);
    v9 = v8;
    if ( v8 >= 0 )
      v9 = v20[0];
    else
      MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: v8, a5: 0x1ACu, a6: v12);
  }
  else
  {
    v9 = 0x80070057;
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: -2147024809, a5: 0x1A1u, a6: v11);
  }
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApiUpdateThumbnailProperties_Stop,
      a3: v9);
  return v9;
}
