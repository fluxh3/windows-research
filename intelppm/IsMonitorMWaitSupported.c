bool IsMonitorMWaitSupported()
{
  __int128 v1; // [rsp+20h] [rbp-38h] BYREF
  __int128 v2; // [rsp+30h] [rbp-28h] BYREF

  v2 = 0;
  v1 = 0;
  GetCpuIdInfo(a1: 1u, a2: &v1);
  if ( (BYTE8(v1) & 8) == 0 )
    return false;
  GetCpuIdInfo(a1: 0, a2: &v2);
  return (unsigned int)v2 >= 5;
}
