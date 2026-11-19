__int64 __fastcall DwmpCreateSessionShutdownEvent(unsigned int a1, void **a2)
{
  int v3; // eax
  int v4; // ebx
  NTSTATUS v5; // eax
  signed int LastError; // eax
  unsigned int v8; // edx
  int v9; // ecx
  PSECURITY_DESCRIPTOR SecurityDescriptor; // [rsp+30h] [rbp-79h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+38h] [rbp-71h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+68h] [rbp-41h] BYREF
  WCHAR SourceString[56]; // [rsp+80h] [rbp-29h] BYREF

  SecurityDescriptor = nullptr;
  v3 = StringCchPrintfW(a1: SourceString, a2: 0x35u, a3: L"\\Sessions\\%d\\Windows\\DwmCatastrophicShutdown", a1);
  v4 = v3;
  if ( v3 < 0 )
  {
    v8 = 42;
    v9 = v3;
  }
  else
  {
    RtlInitUnicodeString(&DestinationString, SourceString);
    SetLastError(dwErrCode: 0);
    if ( ConvertStringSecurityDescriptorToSecurityDescriptorW(
           StringSecurityDescriptor: L"D:(A;;0x00100002;;;SY)",
           StringSDRevision: 1u,
           &SecurityDescriptor,
           SecurityDescriptorSize: nullptr) )
    {
      if ( SecurityDescriptor != nullptr )
      {
        ObjectAttributes.RootDirectory = nullptr;
        ObjectAttributes.Attributes = 0;
        ObjectAttributes.SecurityQualityOfService = nullptr;
        ObjectAttributes.ObjectName = &DestinationString;
        ObjectAttributes.Length = 48;
        ObjectAttributes.SecurityDescriptor = SecurityDescriptor;
        v5 = NtCreateEvent(
               EventHandle: a2,
               DesiredAccess: 0x100002u,
               &ObjectAttributes,
               EventType: NotificationEvent,
               InitialState: 0);
        if ( v5 >= 0 )
          goto LABEL_5;
        v8 = 69;
        v4 = v5 | 0x10000000;
      }
      else
      {
        v4 = -2147024882;
        v8 = 57;
      }
    }
    else
    {
      LastError = GetLastError();
      v4 = LastError;
      if ( LastError > 0 )
        v4 = (unsigned __int16)LastError | 0x80070000;
      v8 = 55;
      if ( v4 >= 0 )
        v4 = -2003304445;
    }
    v9 = v4;
  }
  DoStackCaptureDirect(a1: v9, a2: v8);
LABEL_5:
  if ( SecurityDescriptor != nullptr )
    LocalFree(hMem: SecurityDescriptor);
  return (unsigned int)v4;
}
