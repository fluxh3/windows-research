__int64 __fastcall RaisePower(unsigned int n10000000, signed int n1000000, char a3)
{
  char v3; // si
  unsigned int n1000000_1; // ebx
  unsigned int n10000000_1; // r10d
  unsigned int n1000000_2; // r9d
  int n1000000_3; // edx
  int v8; // edi
  __int16 v9; // cx
  unsigned int v10; // eax
  int v11; // esi
  unsigned int v12; // r9d
  __int64 result; // rax

  v3 = a3;
  n1000000_1 = n1000000;
  n10000000_1 = n10000000;
  n1000000_2 = 1000000;
  if ( (a3 & 2) != 0 )
  {
    if ( n1000000 != 1 )
      goto LABEL_5;
    return n10000000;
  }
  if ( n1000000 == 1000000 )
    return n10000000;
  n1000000_3 = n1000000 / 1000000;
  if ( n1000000_1 == 1000000 * ((int)n1000000_1 / 1000000) )
  {
    n1000000_1 = n1000000_3;
    v3 = a3 | 2;
  }
LABEL_5:
  if ( (int)n10000000 <= 0 )
  {
    n10000000_1 = -n10000000;
    v8 = 1;
    if ( n10000000 == 0 )
      return 0;
  }
  else
  {
    v8 = 0;
  }
  if ( n1000000_1 == 0 )
    return v8 != 0 ? -1000000 : 1000000;
  if ( n10000000_1 != 10000000 )
    n1000000_2 = Log(a1: n10000000_1);
  v9 = v3 & 1;
  if ( (v3 & 2) == 0 )
  {
    if ( (v3 & 1) != 0 )
      v10 = DivFD6(a1: n1000000_2, a2: n1000000_1);
    else
      v10 = MulFD6(a1: n1000000_2, a2: n1000000_1);
    v11 = v8;
    goto LABEL_14;
  }
  v11 = (n1000000_1 & 1) != 0 ? v8 : 0;
  if ( v9 != 0 )
  {
    v10 = FD6DivL(n1000000: n1000000_2, n1000000: n1000000_1);
LABEL_14:
    v12 = v10;
    goto LABEL_15;
  }
  v12 = n1000000_1 * n1000000_2;
LABEL_15:
  result = AntiLog(a1: v12);
  if ( v11 != 0 )
    return (unsigned int)-(int)result;
  return result;
}
