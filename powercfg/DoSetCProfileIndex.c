__int64 __fastcall DoSetxCProfileIndex(RPC_WSTR StringUuid, RPC_WSTR a2, RPC_WSTR a3, wchar_t *String, char a5)
{
  unsigned int v8; // esi
  unsigned int v9; // ebx
  __int64 ResString; // rax
  ULONG Index; // edi
  DWORD v12; // eax
  __int64 v13; // rax
  DWORD BufferSize; // [rsp+40h] [rbp-21h] BYREF
  _GUID Uuid; // [rsp+48h] [rbp-19h] BYREF
  UUID v18; // [rsp+58h] [rbp-9h] BYREF
  UCHAR Buffer[8]; // [rsp+68h] [rbp+7h] BYREF
  __int64 v20; // [rsp+70h] [rbp+Fh]
  UUID v21; // [rsp+78h] [rbp+17h] BYREF

  v8 = wcstoul(String, EndPtr: nullptr, Radix: 10);
  v9 = ConvertStringToGuid(StringUuid, &Uuid);
  if ( v9 == 0 )
  {
    if ( (unsigned int)IsOverlaySchemeValid(a1: &Uuid) != 0
      && Uuid.Data1 == 0x3AF9B8D9u
      && Uuid.Data2 == 0x7C97u
      && Uuid.Data3 == 0x431Du
      && *(_QWORD *)Uuid.Data4 == 0x9F43EABFA83478ADuLL )
    {
      ResString = GetResString(uID: 0x21FEu);
      PowercfgPrint(a1: 0, a2: ResString);
    }
    v9 = ConvertStringToGuid(StringUuid: a2, Uuid: &v18);
    if ( v9 == 0 )
    {
      for ( Index = 0; ; ++Index )
      {
        BufferSize = 16;
        v12 = PowerEnumerate(
                RootPowerKey: nullptr,
                SchemeGuid: nullptr,
                SubGroupOfPowerSettingsGuid: nullptr,
                AccessFlags: ACCESS_PROFILE,
                Index,
                Buffer,
                &BufferSize);
        if ( *(_QWORD *)&v18.Data1 == *(_QWORD *)Buffer && *(_QWORD *)v18.Data4 == v20 )
          break;
        if ( v12 != 0 )
        {
          v13 = GetResString(uID: 0x2261u);
          PowercfgPrint(a1: 0, a2: v13);
          return v9;
        }
      }
      v9 = ConvertStringToGuid(StringUuid: a3, Uuid: &v21);
      if ( v9 == 0 )
      {
        if ( a5 != 0 )
          return (unsigned int)PowerWriteACProfileIndex(a1: &Uuid, a2: &v18, a3: &v21, a4: v8);
        else
          return (unsigned int)PowerWriteDCProfileIndex(a1: &Uuid, a2: &v18, a3: &v21, a4: v8);
      }
    }
  }
  return v9;
}
