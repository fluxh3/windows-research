__int64 RIMReadPowerRegistrySettings()
{
  int gWakeOnDeviceTypes_4; // edx
  int gWakeOnDeviceTypes_3; // ecx
  int gWakeOnDeviceTypes_2; // edx
  unsigned int gWakeOnDeviceTypes_1; // ecx
  __int64 gWakeOnDeviceTypes; // rax
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF
  int v6; // [rsp+40h] [rbp+8h] BYREF

  v6 = 0;
  DestinationString = 0;
  RtlInitUnicodeString(&DestinationString, SourceString: L"\\Registry\\Machine\\SYSTEM\\INPUT");
  RIMRegQueryDWord(a1: &DestinationString, a2: L"WakeOnInputDeviceTypes", a3: 38, a4: &v6);
  gWakeOnDeviceTypes_4 = ((v6 & 2) != 0) | 2;
  if ( (v6 & 4) == 0 )
    gWakeOnDeviceTypes_4 = (v6 & 2) != 0;
  gWakeOnDeviceTypes_3 = gWakeOnDeviceTypes_4 | 0x10;
  if ( (v6 & 8) == 0 )
    gWakeOnDeviceTypes_3 = gWakeOnDeviceTypes_4;
  gWakeOnDeviceTypes_2 = gWakeOnDeviceTypes_3 | 4;
  if ( (v6 & 0x10) == 0 )
    gWakeOnDeviceTypes_2 = gWakeOnDeviceTypes_3;
  gWakeOnDeviceTypes_1 = gWakeOnDeviceTypes_2 | 8;
  if ( (v6 & 0x20) == 0 )
    gWakeOnDeviceTypes_1 = gWakeOnDeviceTypes_2;
  gWakeOnDeviceTypes = gWakeOnDeviceTypes_1 | 0x20;
  if ( (v6 & 0x80) == 0 )
    gWakeOnDeviceTypes = gWakeOnDeviceTypes_1;
  ::gWakeOnDeviceTypes = gWakeOnDeviceTypes;
  return gWakeOnDeviceTypes;
}
