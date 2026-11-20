__int64 ReadCursorSuppressionConfig()
{
  unsigned int v0; // ebx
  int v2; // [rsp+40h] [rbp+8h] BYREF

  v0 = 0;
  v2 = 0;
  if ( gSessionId != gServiceSessionId && gProtocolType == 0 )
  {
    FastGetProfileDword(a1: 0, a2: 49, a3: L"EnableCursorSuppression", a4: 0, a5: &v2);
    return v2 != 0;
  }
  return v0;
}
