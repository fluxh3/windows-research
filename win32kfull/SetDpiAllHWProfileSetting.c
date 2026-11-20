__int64 __fastcall SetDpiAllHWProfileSetting(unsigned int ValueData)
{
  ULONG i_1; // ebx
  ULONG i; // edx
  ULONG ResultLength; // [rsp+30h] [rbp-D0h] BYREF
  void *KeyHandle; // [rsp+38h] [rbp-C8h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-C0h] BYREF
  unsigned int ValueDataa; // [rsp+50h] [rbp-B0h] BYREF
  UNICODE_STRING Source; // [rsp+58h] [rbp-A8h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+68h] [rbp-98h] BYREF
  _BYTE KeyInformation[12]; // [rsp+A0h] [rbp-60h] BYREF
  int Length; // [rsp+ACh] [rbp-54h]
  char v12; // [rsp+B0h] [rbp-50h] BYREF
  char v13; // [rsp+1A0h] [rbp+A0h] BYREF

  *(&ObjectAttributes.Length + 1) = 0;
  *(&ObjectAttributes.Attributes + 1) = 0;
  KeyHandle = nullptr;
  ValueDataa = ValueData;
  i_1 = 0;
  ResultLength = 0;
  DestinationString = 0;
  Source = 0;
  RtlInitUnicodeString(
    &DestinationString,
    SourceString: L"\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles");
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  *(__m128i *)&ObjectAttributes.SecurityDescriptor = 0;
  if ( ZwOpenKey(&KeyHandle, DesiredAccess: 0x20019u, &ObjectAttributes) < STATUS_SUCCESS )
    return 3221225474LL;
  for ( i = 0;
        ZwEnumerateKey(
          KeyHandle,
          Index: i,
          KeyInformationClass: KeyBasicInformation,
          KeyInformation,
          Length: 0x100u,
          &ResultLength) >= STATUS_SUCCESS;
        i = i_1 )
  {
    Source.Buffer = (PWSTR)&v12;
    Source.Length = Length;
    ++i_1;
    Source.MaximumLength = Length;
    *(_QWORD *)&DestinationString.Length = 0x2000000;
    DestinationString.Buffer = (PWSTR)&v13;
    if ( RtlAppendUnicodeToString(
           Destination: &DestinationString,
           Source: L"\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles\\") >= STATUS_SUCCESS
      && RtlAppendUnicodeStringToString(Destination: &DestinationString, &Source) >= STATUS_SUCCESS
      && RtlAppendUnicodeToString(Destination: &DestinationString, Source: L"\\Software\\Fonts") >= STATUS_SUCCESS )
    {
      RtlWriteRegistryValue(
        RelativeTo: 0,
        Path: DestinationString.Buffer,
        ValueName: L"LogPixels",
        ValueType: 4u,
        ValueData: &ValueDataa,
        ValueLength: 4u);
    }
  }
  if ( KeyHandle != nullptr )
    ZwClose(Handle: KeyHandle);
  return 0;
}
