__int64 __fastcall UserBeep(unsigned int a1, int a2)
{
  unsigned int v2; // ebx
  __int64 v3; // rdi
  NTSTATUS v5; // eax
  NTSTATUS v7; // r14d
  unsigned __int64 InputBuffer; // [rsp+60h] [rbp-19h] BYREF
  union _LARGE_INTEGER Interval; // [rsp+68h] [rbp-11h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+70h] [rbp-9h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+80h] [rbp+7h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+90h] [rbp+17h] BYREF
  int v13; // [rsp+F0h] [rbp+77h] BYREF
  void *FileHandle; // [rsp+F8h] [rbp+7Fh] BYREF

  v2 = 0;
  v3 = a2;
  InputBuffer = 0;
  memset(&ObjectAttributes, 0, sizeof(ObjectAttributes));
  FileHandle = nullptr;
  Interval.QuadPart = 0;
  DestinationString = 0;
  IoStatusBlock = 0;
  if ( gProtocolType != 0 )
  {
    if ( gpRemoteBeepDevice == 0 )
      return 0;
    v5 = ObOpenObjectByPointer(
           Object: gpRemoteBeepDevice,
           HandleAttributes: 0,
           PassedAccessState: nullptr,
           DesiredAccess: 0x1F0003u,
           ObjectType: nullptr,
           AccessMode: 0,
           Handle: &FileHandle);
  }
  else
  {
    RtlInitUnicodeString(&DestinationString, SourceString: L"\\Device\\Beep");
    ObjectAttributes.Length = 48;
    ObjectAttributes.RootDirectory = nullptr;
    ObjectAttributes.Attributes = 512;
    ObjectAttributes.ObjectName = &DestinationString;
    *(__m128i *)&ObjectAttributes.SecurityDescriptor = 0;
    v5 = ZwCreateFile(
           &FileHandle,
           DesiredAccess: 3u,
           &ObjectAttributes,
           &IoStatusBlock,
           AllocationSize: nullptr,
           FileAttributes: 0,
           ShareAccess: 3u,
           CreateDisposition: 3u,
           CreateOptions: 0,
           EaBuffer: nullptr,
           EaLength: 0);
  }
  if ( v5 < STATUS_SUCCESS )
    return 0;
  if ( (a1 != 0 || (_DWORD)v3 != 0) && a1 - 37 > 0x7FDA )
  {
    v7 = STATUS_INVALID_PARAMETER;
  }
  else
  {
    InputBuffer = __PAIR64__(v3, a1);
    v7 = ZwDeviceIoControlFile(
           FileHandle,
           Event: nullptr,
           ApcRoutine: nullptr,
           ApcContext: nullptr,
           &IoStatusBlock,
           IoControlCode: 0x10000u,
           &InputBuffer,
           InputBufferLength: 8u,
           OutputBuffer: nullptr,
           OutputBufferLength: 0);
  }
  ReEnterLeaveCrit::ReEnterLeaveCrit(this: (ReEnterLeaveCrit *)&v13);
  xxxSoundSentry();
  if ( v13 == 0 )
    UserSessionSwitchLeaveCrit();
  if ( v7 >= STATUS_SUCCESS )
  {
    if ( (_DWORD)v3 != -1 && (a1 != 0 || (_DWORD)v3 != 0) )
    {
      Interval.QuadPart = -10000 * v3;
      KeDelayExecutionThread(WaitMode: 1, Alertable: 0, &Interval);
    }
    v2 = 1;
  }
  ZwClose(Handle: FileHandle);
  return v2;
}
