__int64 __fastcall DwmpActivateLivePreview(int a1, __int64 a2, __int64 a3, int a4, __m128i *a5)
{
  char v9; // bl
  unsigned int v10; // eax
  __int64 *v11; // rdx
  int v12; // eax
  unsigned int v13; // ebx
  void *v15; // [rsp+28h] [rbp-38h]
  _DWORD v16[2]; // [rsp+30h] [rbp-30h] BYREF
  __int64 v17; // [rsp+38h] [rbp-28h]
  __int64 v18; // [rsp+40h] [rbp-20h]
  int v19; // [rsp+48h] [rbp-18h]
  _DWORD v20[5]; // [rsp+4Ch] [rbp-14h]
  int v21; // [rsp+A8h] [rbp+48h] BYREF

  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 )
    McTemplateU0tpq_EtwEventWriteTransfer(a1, a2: (unsigned int)ApipActivateLivePreview_Start, a3: a1, a4: a2, a5: a4);
  v9 = 1;
  if ( a4 <= 0 )
    goto LABEL_24;
  if ( a4 <= 2 )
  {
LABEL_7:
    v9 = 0;
    goto LABEL_8;
  }
  if ( a4 > 5 )
  {
    if ( a4 == 6 )
      goto LABEL_7;
LABEL_24:
    v13 = 0x80070057;
    goto LABEL_25;
  }
LABEL_8:
  if ( a1 == 0 || GetSystemMetrics(nIndex: 8193) != 0 )
    goto LABEL_16;
  v10 = ++dword_180023198;
  if ( v9 != 0 )
  {
    if ( (byte_180023041 & 0x10) != 0 )
    {
      v11 = PerfTrack_InspectorWindow_Begin_Info;
LABEL_15:
      McTemplateU0q_EtwEventWriteTransfer(a1: Microsoft_Windows_Shell_Core_Provider_Context, a2: v11, a3: v10);
LABEL_16:
      v10 = dword_180023198;
    }
  }
  else if ( (byte_180023041 & 0x10) != 0 )
  {
    v11 = PerfTrack_InspectorGadget_Begin_Info;
    goto LABEL_15;
  }
  v16[0] = 1073741880;
  *(_QWORD *)&v20[2] = 0;
  *(_QWORD *)v20 = v10;
  v20[4] = 0;
  v19 = a4;
  v16[1] = a1;
  v17 = a2;
  v18 = a3;
  if ( a5 != nullptr )
    *(__m128i *)&v20[1] = *a5;
  v12 = CApiPortClient::SendRequest(
          this: (CApiPortClient *)&g_PortClient,
          a2: v16,
          a3: 48,
          a4: &v21,
          a5: nullptr,
          a6: 0);
  v13 = v12;
  if ( v12 >= 0 )
  {
    v13 = v21;
    if ( v21 < 0 )
      MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA38, a3: 1u, a4: v21, a5: 0x53u, a6: v15);
  }
  else
  {
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA38, a3: 1u, a4: v12, a5: 0x52u, a6: v15);
  }
LABEL_25:
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 )
    McTemplateU0tpq_EtwEventWriteTransfer(a1, a2: (unsigned int)ApipActivateLivePreview_Stop, a3: a1, a4: a2, a5: a4);
  return v13;
}
