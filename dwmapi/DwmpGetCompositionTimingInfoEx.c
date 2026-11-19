__int64 __fastcall DwmpGetCompositionTimingInfoEx(__int64 a1, unsigned int *a2)
{
  int v4; // esi
  int v5; // r8d
  unsigned int v6; // ebx
  int FrameStatistics; // eax
  __int64 v8; // rcx
  signed int LastError; // eax
  _BYTE Src[4]; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v12; // [rsp+34h] [rbp-CCh]
  unsigned __int64 v13; // [rsp+3Ch] [rbp-C4h]
  __int64 v14; // [rsp+44h] [rbp-BCh]
  __int64 v15; // [rsp+4Ch] [rbp-B4h]
  __int64 v16; // [rsp+54h] [rbp-ACh]
  int v17; // [rsp+5Ch] [rbp-A4h]
  __int64 v18; // [rsp+60h] [rbp-A0h]
  __int64 v19; // [rsp+68h] [rbp-98h]
  int v20; // [rsp+70h] [rbp-90h]
  __int64 v21; // [rsp+74h] [rbp-8Ch]
  __int64 v22; // [rsp+7Ch] [rbp-84h]
  int v23; // [rsp+84h] [rbp-7Ch]
  __int64 v24; // [rsp+88h] [rbp-78h]
  int v25; // [rsp+90h] [rbp-70h]
  __int64 v26; // [rsp+94h] [rbp-6Ch]
  __int64 v27; // [rsp+A0h] [rbp-60h]
  int v28; // [rsp+A8h] [rbp-58h]
  __int64 v29; // [rsp+170h] [rbp+70h] BYREF
  __int64 v30; // [rsp+178h] [rbp+78h]
  _BYTE v31[16]; // [rsp+198h] [rbp+98h] BYREF

  v4 = 0;
  memset_0(a1: Src, Val: 0, Size: 0x13Cu);
  v6 = 0;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApiGetCompositionTimingInfo_Start,
      a3: v5,
      a4: 1,
      a5: (__int64)v31);
  if ( a2 != nullptr )
  {
    v6 = *a2;
    if ( *a2 == 292 || v6 == 316 )
    {
      if ( a1 != 0 )
      {
        v4 = -2147024809;
        DoStackCaptureDirect(a1: -2147024809, a2: 0x53u);
      }
      else if ( Frequency.QuadPart != 0
             || (SetLastError(dwErrCode: 0), QueryPerformanceFrequency(lpFrequency: &Frequency)) )
      {
        FrameStatistics = DCompositionGetFrameStatistics(a1: &v29, a2: 0, a3: 0);
        if ( FrameStatistics < 0 )
        {
          v4 = FrameStatistics | 0x10000000;
          DoStackCaptureDirect(a1: FrameStatistics | 0x10000000, a2: 0x64u);
        }
        else
        {
          v12 = v30;
          v8 = qword_180022368++;
          v13 = Frequency.QuadPart * (unsigned __int64)HIDWORD(v30) / (unsigned int)v30;
          v14 = v30;
          v15 = v29;
          v18 = v29;
          v19 = qword_180022368 - 1;
          v20 = dword_180022360;
          v23 = dword_180022360;
          v24 = qword_180022368 - 2;
          v25 = dword_180022360 - 1;
          v26 = qword_180022368 - 2;
          ++dword_180022360;
          v16 = qword_180022368;
          v17 = dword_180022360;
          v21 = v8;
          v22 = v8;
          v27 = 0;
          v28 = 1;
        }
      }
      else
      {
        LastError = GetLastError();
        if ( LastError > 0 )
          LastError = (unsigned __int16)LastError | 0x80070000;
        if ( LastError >= 0 )
          LastError = -2003304445;
        v4 = LastError;
        DoStackCaptureDirect(a1: LastError, a2: 0x5Cu);
      }
    }
    else
    {
      v4 = -2003304304;
      DoStackCaptureDirect(a1: -2003304304, a2: 0x4Bu);
    }
  }
  else
  {
    v4 = -2147024809;
    DoStackCaptureDirect(a1: -2147024809, a2: 0x44u);
  }
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 0 - 1
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApiGetCompositionTimingInfo_Stop,
      a3: (unsigned int)v4);
  if ( v4 >= 0 )
  {
    memcpy_0(a1: a2, Src, Size: v6);
    *a2 = v6;
  }
  DwmGetCompositionTimingInfoReport();
  return MilToDwmError(a1: v4);
}
