NTSTATUS __fastcall SetDpiScalingSetting(int a1, int ValueData_1)
{
  const WCHAR *`\\\\Registry\\\\Machine\\\\Software\\\\Microsoft\\\\Windows\\\\DWM`; // rdx
  ULONG n5; // ecx
  int ValueData; // [rsp+48h] [rbp+10h] BYREF

  ValueData = ValueData_1;
  if ( a1 != 0 )
  {
    if ( a1 != 1 )
      return STATUS_INVALID_PARAMETER;
    `\\\\Registry\\\\Machine\\\\Software\\\\Microsoft\\\\Windows\\\\DWM` = L"\\Registry\\Machine\\Software\\Microsoft\\Windows\\DWM";
    n5 = 0;
  }
  else
  {
    `\\\\Registry\\\\Machine\\\\Software\\\\Microsoft\\\\Windows\\\\DWM` = L"Software\\Microsoft\\Windows\\DWM";
    n5 = 5;
  }
  return RtlWriteRegistryValue(
           RelativeTo: n5,
           Path: `\\\\Registry\\\\Machine\\\\Software\\\\Microsoft\\\\Windows\\\\DWM`,
           ValueName: L"UseDpiScaling",
           ValueType: 4u,
           &ValueData,
           ValueLength: 4u);
}
