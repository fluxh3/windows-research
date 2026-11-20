int __fastcall SetThreadName(HANDLE ThreadHandle, const WCHAR *SourceString)
{
  int result; // eax
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  DestinationString = 0;
  result = RtlInitUnicodeStringEx(&DestinationString, SourceString);
  if ( result >= 0 )
    return ZwSetInformationThread(
             ThreadHandle,
             ThreadInformationClass: ThreadDescriptorTableEntry|0x20,
             ThreadInformation: &DestinationString,
             ThreadInformationLength: 0x10u);
  return result;
}
