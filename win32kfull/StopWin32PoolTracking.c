void __fastcall StopWin32PoolTracking()
{
  _DWORD *DeviceContext; // rax
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-50h] BYREF
  struct _UNICODE_STRING ValueName; // [rsp+30h] [rbp-40h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+40h] [rbp-30h] BYREF
  void *KeyHandle; // [rsp+80h] [rbp+10h] BYREF

  DeviceContext = WPP_MAIN_CB.Queue.Wcb.DeviceContext;
  if ( WPP_MAIN_CB.Queue.Wcb.DeviceContext != nullptr )
  {
    *((_DWORD *)WPP_MAIN_CB.Queue.Wcb.DeviceContext + 11) = 0;
    DeviceContext[10] = 0;
  }
  if ( gpxsGlobals != nullptr && *((_DWORD *)gpxsGlobals + 8) != 0 )
  {
    *(&ObjectAttributes.Length + 1) = 0;
    *(&ObjectAttributes.Attributes + 1) = 0;
    KeyHandle = nullptr;
    DestinationString = 0;
    ValueName = 0;
    RtlInitUnicodeString(
      &DestinationString,
      SourceString: L"\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\SESSION MANAGER\\MEMORY MANAGEMENT");
    ObjectAttributes.RootDirectory = nullptr;
    ObjectAttributes.ObjectName = &DestinationString;
    ObjectAttributes.Length = 48;
    ObjectAttributes.Attributes = 576;
    *(__m128i *)&ObjectAttributes.SecurityDescriptor = 0;
    if ( ZwOpenKey(&KeyHandle, DesiredAccess: 0x2001Fu, &ObjectAttributes) >= STATUS_SUCCESS )
    {
      RtlInitUnicodeString(DestinationString: &ValueName, SourceString: L"SESSION_HAS_VALID_POOL_ON_EXIT");
      if ( ZwDeleteValueKey(KeyHandle, &ValueName) >= STATUS_SUCCESS )
        ZwFlushKey(KeyHandle);
      ZwClose(Handle: KeyHandle);
    }
  }
}
