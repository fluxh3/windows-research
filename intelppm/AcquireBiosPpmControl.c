char __fastcall AcquireBiosPpmControl(__int64 a1)
{
  __int64 v1; // rax

  v1 = *(_QWORD *)(a1 + 272);
  if ( (v1 & 0x7F070) != 0 && dword_1C001CE80 != 0 && byte_1C001CE85 != 0 )
  {
    __outbyte(dword_1C001CE80, byte_1C001CE85);
    v1 = *(_QWORD *)(a1 + 272);
  }
  if ( (v1 & 0x70000000) != 0 && dword_1C001CE80 != 0 )
  {
    LOBYTE(v1) = byte_1C001CE84;
    if ( byte_1C001CE84 != 0 )
      __outbyte(dword_1C001CE80, byte_1C001CE84);
  }
  return v1;
}
