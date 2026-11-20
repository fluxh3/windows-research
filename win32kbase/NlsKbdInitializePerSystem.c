void NlsKbdInitializePerSystem()
{
  UNICODE_STRING String1; // [rsp+30h] [rbp-D0h] BYREF
  UNICODE_STRING DestinationString__4; // [rsp+40h] [rbp-C0h] BYREF
  UNICODE_STRING DestinationString__5; // [rsp+50h] [rbp-B0h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+60h] [rbp-A0h] BYREF
  struct _UNICODE_STRING DestinationString_; // [rsp+70h] [rbp-90h] BYREF
  struct _UNICODE_STRING DestinationString__2; // [rsp+80h] [rbp-80h] BYREF
  UNICODE_STRING String2; // [rsp+90h] [rbp-70h] BYREF
  UNICODE_STRING DestinationString__1; // [rsp+A0h] [rbp-60h] BYREF
  UNICODE_STRING DestinationString__3; // [rsp+B0h] [rbp-50h] BYREF
  struct _RTL_QUERY_REGISTRY_TABLE QueryTable; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v10; // [rsp+F8h] [rbp-8h]
  int n32; // [rsp+100h] [rbp+0h]
  const wchar_t *KanaHelpKey; // [rsp+108h] [rbp+8h]
  UNICODE_STRING *DestinationString_1; // [rsp+110h] [rbp+10h]
  int n16777217; // [rsp+118h] [rbp+18h]
  struct _UNICODE_STRING *DestinationString_2; // [rsp+120h] [rbp+20h]
  int v16; // [rsp+128h] [rbp+28h]
  __int64 v17; // [rsp+130h] [rbp+30h]
  int n32_1; // [rsp+138h] [rbp+38h]
  const wchar_t *clrkey; // [rsp+140h] [rbp+40h]
  UNICODE_STRING *DestinationString_3; // [rsp+148h] [rbp+48h]
  int n16777217_1; // [rsp+150h] [rbp+50h]
  struct _UNICODE_STRING *DestinationString_4; // [rsp+158h] [rbp+58h]
  int v23; // [rsp+160h] [rbp+60h]
  __int64 v24; // [rsp+168h] [rbp+68h]
  int v25; // [rsp+170h] [rbp+70h]
  __int64 v26; // [rsp+178h] [rbp+78h]

  DestinationString = 0;
  String2 = 0;
  DestinationString_ = 0;
  DestinationString__1 = 0;
  DestinationString__2 = 0;
  DestinationString__3 = 0;
  String1 = 0;
  DestinationString__4 = 0;
  DestinationString__5 = 0;
  if ( (_BYTE)gKeyboardInfo == 3 )
    gapulCvt_VK = (__int64 *)gapulCvt_VK_84;    // "j,"
  if ( (_WORD)gKeyboardInfo == 775 )
    gapulCvt_VK = (__int64 *)gapulCvt_VK_IBM02;
  NlsSetKeyStateToggle(a1: 0xF0u);
  NlsSetKeyStateToggle(a1: 0xF3u);
  NlsSetKeyStateToggle(a1: 0xF6u);
  NlsSetKeyStateToggle(a1: 0xFBu);
  RtlInitUnicodeString(&DestinationString, SourceString: L"end");
  RtlInitUnicodeString(DestinationString: &String2, SourceString: L"help");
  RtlInitUnicodeString(DestinationString: &DestinationString_, SourceString: L"yes");
  RtlInitUnicodeString(DestinationString: &DestinationString__1, SourceString: L"no");
  RtlInitUnicodeString(DestinationString: &DestinationString__2, SourceString: L"home");
  RtlInitUnicodeString(DestinationString: &DestinationString__3, SourceString: L"clear");
  RtlInitUnicodeString(DestinationString: &String1, SourceString: nullptr);
  RtlInitUnicodeString(DestinationString: &DestinationString__4, SourceString: nullptr);
  RtlInitUnicodeString(DestinationString: &DestinationString__5, SourceString: nullptr);
  QueryTable.QueryRoutine = nullptr;
  QueryTable.DefaultLength = 0;
  v10 = 0;
  v16 = 0;
  v17 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  QueryTable.Name = L"helpkey";
  QueryTable.EntryContext = &String1;
  QueryTable.DefaultData = &DestinationString;
  KanaHelpKey = L"KanaHelpKey";
  DestinationString_1 = &DestinationString__4;
  DestinationString_2 = &DestinationString_;
  clrkey = L"clrkey";
  DestinationString_3 = &DestinationString__5;
  QueryTable.Flags = 32;
  QueryTable.DefaultType = 16777217;
  n32 = 32;
  n16777217 = 16777217;
  n32_1 = 32;
  n16777217_1 = 16777217;
  DestinationString_4 = &DestinationString__2;
  if ( RtlQueryRegistryValues(
         RelativeTo: 3u,
         Path: L"WOW\\keyboard",
         &QueryTable,
         Context: nullptr,
         Environment: nullptr) >= STATUS_SUCCESS )
  {
    if ( RtlEqualUnicodeString(&String1, &String2, CaseInSensitive: 1u) != 0 )
      fNlsKbdConfiguration &= ~2u;
    if ( RtlEqualUnicodeString(String1: &DestinationString__4, String2: &DestinationString__1, CaseInSensitive: 1u) != 0 )
      fNlsKbdConfiguration &= ~1u;
    if ( RtlEqualUnicodeString(String1: &DestinationString__5, String2: &DestinationString__3, CaseInSensitive: 1u) != 0 )
      fNlsKbdConfiguration &= ~4u;
    ExFreePoolWithTag(P: String1.Buffer, Tag: 0);
    ExFreePoolWithTag(P: DestinationString__4.Buffer, Tag: 0);
    ExFreePoolWithTag(P: DestinationString__5.Buffer, Tag: 0);
  }
}
