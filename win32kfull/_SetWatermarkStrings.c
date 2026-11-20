__int64 __fastcall SetWatermarkStrings(__int64 a1)
{
  int v3; // eax
  unsigned int v4; // edi
  __int64 v5; // rbx
  __int64 v6; // rsi
  ULONG64 MmUserProbeAddress; // rdx
  int v8; // ecx
  WCHAR *Buffer; // r8
  ULONG64 Buffer_1; // rdx
  _BYTE **MmUserProbeAddress_1; // rax
  struct _UNICODE_STRING *DestinationString; // rbx
  unsigned __int64 Length; // rcx
  unsigned __int64 DeviceObject_low; // rax
  int v15; // [rsp+20h] [rbp-38h]
  UNICODE_STRING SourceString; // [rsp+30h] [rbp-28h] BYREF
  int v17; // [rsp+68h] [rbp+10h]

  SourceString = 0;
  if ( PsGetCurrentProcessId() != (HANDLE)gpidLogon )
    return 0;
  v3 = 0;
  v4 = 1;
  while ( 1 )
  {
    v15 = v3;
    v5 = v3;
    if ( (unsigned __int64)v3 >= 1 )
      break;
    v6 = 2LL * v3;
    MmUserProbeAddress = a1 + 16LL * v3;
    if ( MmUserProbeAddress >= ::MmUserProbeAddress )
      MmUserProbeAddress = ::MmUserProbeAddress;
    v8 = *(_DWORD *)MmUserProbeAddress;
    v17 = *(_DWORD *)MmUserProbeAddress;
    *(_DWORD *)&SourceString.Length = *(_DWORD *)MmUserProbeAddress;
    Buffer = *(WCHAR **)(MmUserProbeAddress + 8);
    SourceString.Buffer = Buffer;
    if ( ((unsigned __int8)Buffer & 1) != 0 )
      ExRaiseDatatypeMisalignment();
    Buffer_1 = (ULONG64)Buffer + (unsigned __int16)v8 + 2;
    MmUserProbeAddress_1 = (_BYTE **)::MmUserProbeAddress;
    if ( Buffer_1 < ::MmUserProbeAddress && (unsigned __int16)v8 <= HIWORD(v17) )
    {
      if ( (v8 & 1) != 0 )
        goto LABEL_14;
      if ( Buffer_1 > (unsigned __int64)Buffer )
        goto LABEL_16;
    }
    if ( (v8 & 1) != 0 )
    {
LABEL_14:
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
      MmUserProbeAddress_1 = (_BYTE **)::MmUserProbeAddress;
    }
    **MmUserProbeAddress_1 = 0;
LABEL_16:
    *((_QWORD *)&WPP_MAIN_CB.Queue.Wcb.CurrentIrp + v6) = &gWatermarkStrings[32 * v5];
    DestinationString = (struct _UNICODE_STRING *)(&WPP_MAIN_CB.Queue.Wcb.DeviceObject + v6);
    DestinationString->Length = 0;
    DestinationString->MaximumLength = 256;
    RtlCopyUnicodeString(DestinationString, &SourceString);
    Length = DestinationString->Length;
    if ( Length >= (unsigned __int64)DestinationString->MaximumLength - 2 )
      Length = *((unsigned __int16 *)&WPP_MAIN_CB.Queue.Wcb.DeviceObject + 4 * v6 + 1) - 2LL;
    *(_WORD *)(*((_QWORD *)&WPP_MAIN_CB.Queue.Wcb.CurrentIrp + v6) + 2 * (Length >> 1)) = 0;
    v3 = v15 + 1;
  }
  if ( *(_DWORD *)(gpsi + 2164LL) != 0 )
  {
    DeviceObject_low = 126;
    if ( LOWORD(WPP_MAIN_CB.Queue.Wcb.DeviceObject) <= 0x7Eu )
      DeviceObject_low = LOWORD(WPP_MAIN_CB.Queue.Wcb.DeviceObject);
    gSafeModeStrLen = DeviceObject_low >> 1;
    if ( (int)RtlStringCchCopyNW(
                a1: &gwszSafeModeStr,
                a2: 0x40u,
                a3: (const unsigned __int16 *)WPP_MAIN_CB.Queue.Wcb.CurrentIrp,
                a4: gSafeModeStrLen) < 0 )
      return 0;
  }
  return v4;
}
