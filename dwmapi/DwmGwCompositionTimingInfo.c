HRESULT __stdcall DwmGetCompositionTimingInfo(HWND hwnd, DWM_TIMING_INFO *pTimingInfo)
{
  int CompositionTimingInfo; // eax
  HRESULT v3; // ebx
  unsigned int v5; // edx
  int v6; // ecx

  if ( pTimingInfo == nullptr )
  {
    v3 = -2147024809;
    v5 = 172;
LABEL_7:
    v6 = v3;
LABEL_9:
    DoStackCaptureDirect(a1: v6, a2: v5);
    return v3;
  }
  if ( pTimingInfo->cbSize != 292 )
  {
    v3 = -2003304304;
    v5 = 175;
    goto LABEL_7;
  }
  CompositionTimingInfo = DwmpGetCompositionTimingInfoEx(a1: (__int64)hwnd, a2: &pTimingInfo->cbSize);
  v3 = CompositionTimingInfo;
  if ( CompositionTimingInfo < 0 )
  {
    v5 = 179;
    v6 = CompositionTimingInfo;
    goto LABEL_9;
  }
  return v3;
}
