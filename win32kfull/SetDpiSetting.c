__int64 __fastcall SetDpiSetting(int a1, unsigned int ValueData_1)
{
  NTSTATUS v2; // ebx
  int *p_ValueData; // rax
  ULONG n5; // ecx
  const WCHAR *LogPixels; // r8
  const WCHAR *`Control Panel\\\\Desktop`; // rdx
  int v8; // [rsp+40h] [rbp+8h] BYREF
  unsigned int ValueData; // [rsp+48h] [rbp+10h] BYREF

  ValueData = ValueData_1;
  v8 = 1;
  if ( a1 == 0 )
  {
    p_ValueData = (int *)&ValueData;
    LogPixels = L"LogPixels";
    `Control Panel\\\\Desktop` = L"Control Panel\\Desktop";
    n5 = 5;
    return (unsigned int)RtlWriteRegistryValue(
                           RelativeTo: n5,
                           Path: `Control Panel\\\\Desktop`,
                           ValueName: LogPixels,
                           ValueType: 4u,
                           ValueData: p_ValueData,
                           ValueLength: 4u);
  }
  if ( a1 != 1 )
    return (unsigned int)-1073741811;
  v2 = RtlWriteRegistryValue(
         RelativeTo: 0,
         Path: L"\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles\\Current\\Software\\Fonts",
         ValueName: L"LogPixels",
         ValueType: 4u,
         &ValueData,
         ValueLength: 4u);
  if ( v2 >= STATUS_SUCCESS )
    v2 = RtlWriteRegistryValue(
           RelativeTo: 0,
           Path: L"\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\FontDPI",
           ValueName: L"LogPixels",
           ValueType: 4u,
           &ValueData,
           ValueLength: 4u);
  SetDpiAllHWProfileSetting(a1: ValueData);
  if ( v2 >= STATUS_SUCCESS )
  {
    p_ValueData = &v8;
    n5 = 0;
    LogPixels = L"Overrode";
    `Control Panel\\\\Desktop` = L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\DPI";
    return (unsigned int)RtlWriteRegistryValue(
                           RelativeTo: n5,
                           Path: `Control Panel\\\\Desktop`,
                           ValueName: LogPixels,
                           ValueType: 4u,
                           ValueData: p_ValueData,
                           ValueLength: 4u);
  }
  return (unsigned int)v2;
}
