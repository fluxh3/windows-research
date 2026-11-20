__int64 __fastcall NtUserSetInformationThread(__int64 a1, unsigned int a2, volatile void *Address, unsigned int Length)
{
  SIZE_T Length_1; // rsi
  __int64 v8; // rcx
  __int64 v9; // rcx
  unsigned int v10; // edi
  _BYTE Src[40]; // [rsp+30h] [rbp-28h] BYREF

  Length_1 = Length;
  memset(Src, 0, 32);
  EnterCrit(a1: 0, a2: 1);
  if ( PsGetCurrentProcess(a1: v8) == gpepCSRSS || a2 == 1 )
  {
    if ( (unsigned int)Length_1 > 0x20 )
    {
      v10 = 0xC000000D;
    }
    else
    {
      if ( (_DWORD)Length_1 != 0 )
      {
        ProbeForRead(Address, Length: Length_1, Alignment: 4u);
        memmove(a1: Src, Src: (const void *)Address, Size: Length_1);
      }
      v10 = xxxSetInformationThread(a1, a2, Src, Length: (unsigned int)Length_1);
      if ( (_DWORD)Length_1 != 0 )
      {
        ProbeForWrite(Address, Length: Length_1, Alignment: 4u);
        memmove(a1: (void *)Address, Src, Size: Length_1);
      }
    }
  }
  else
  {
    v10 = 0xC0000022;
  }
  UserSessionSwitchLeaveCrit(a1: v9);
  return v10;
}
