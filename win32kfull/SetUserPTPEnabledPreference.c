__int64 __fastcall SetUserPTPEnabledPreference(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // rax
  int p___imp_gPTPEnabled; // [rsp+40h] [rbp+18h] BYREF
  __int64 v8; // [rsp+48h] [rbp+20h] BYREF

  v8 = 0;
  p___imp_gPTPEnabled = 1;
  if ( grpWinStaList != 0 && (unsigned int)AccessPTPEnabledStatus(a1: 0, a2: 1, a3: &p___imp_gPTPEnabled) != 0 )
    gPTPEnabled = p___imp_gPTPEnabled;
  result = RIMFindConfigDeviceForInput(a1: a3, a2, a3: a1, a4: &v8);
  if ( (_DWORD)result != 0 )
  {
    if ( p___imp_gPTPEnabled != 0 )
      return RIMUnRevokeConfigurationChange(a1: v8, a2: 87);
    else
      return RIMRevokeConfigurationChange(a1: v8, a2: 87);
  }
  return result;
}
