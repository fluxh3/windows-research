HRESULT __stdcall DwmGetColorizationColor(DWORD *pcrColorization, BOOL *pfOpaqueBlend)
{
  int v4; // r9d
  HRESULT v5; // ebx
  int ColorizationParameters; // eax
  unsigned int v8; // [rsp+20h] [rbp-38h]
  void *v9; // [rsp+28h] [rbp-30h]
  _BYTE v10[40]; // [rsp+30h] [rbp-28h] BYREF
  DWORD v11; // [rsp+60h] [rbp+8h] BYREF

  if ( pcrColorization == nullptr )
  {
    v8 = 62;
LABEL_3:
    v4 = -2147024809;
    v5 = -2147024809;
    goto LABEL_4;
  }
  if ( pfOpaqueBlend == nullptr )
  {
    v8 = 63;
    goto LABEL_3;
  }
  v11 = 0;
  ColorizationParameters = DwmpGetColorizationParameters(a1: v10);
  v5 = ColorizationParameters;
  if ( ColorizationParameters >= 0 )
  {
    ColorizationParameters = DwmpCalculateColorizationColor(a1: v10, a2: &v11);
    v5 = ColorizationParameters;
    if ( ColorizationParameters >= 0 )
    {
      *pcrColorization = v11;
      *pfOpaqueBlend = true;
      return v5;
    }
    v8 = 74;
  }
  else
  {
    v8 = 69;
  }
  v4 = ColorizationParameters;
LABEL_4:
  MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA48, a3: 3u, a4: v4, a5: v8, a6: v9);
  return v5;
}
