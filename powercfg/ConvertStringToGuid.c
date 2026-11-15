__int64 __fastcall ConvertStringToGuid(RPC_WSTR StringUuid, UUID *Uuid)
{
  unsigned int v4; // ebx
  UUID *v5; // rax
  unsigned int v6; // eax

  v4 = 0;
  v5 = (UUID *)AliasToGUID();
  if ( v5 != nullptr )
  {
    *Uuid = *v5;
  }
  else
  {
    v6 = UuidFromStringW(StringUuid, Uuid);
    if ( v6 != 0 )
      return 87;
    return v6;
  }
  return v4;
}
