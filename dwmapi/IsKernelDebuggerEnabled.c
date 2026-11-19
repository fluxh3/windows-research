__int64 __fastcall IsKernelDebuggerEnabled()
{
  NTSTATUS SystemInformation; // eax
  char v1; // cl

  if ( byte_1800259B6 == 0 )
  {
    SystemInformation = NtQuerySystemInformation(
                          SystemInformationClass: SystemKernelDebuggerInformation,
                          SystemInformation: &byte_1800259B4,
                          SystemInformationLength: 2u,
                          ReturnLength: nullptr);
    v1 = byte_1800259B6;
    if ( SystemInformation >= 0 )
      v1 = 1;
    byte_1800259B6 = v1;
  }
  return (unsigned __int8)byte_1800259B4;
}
