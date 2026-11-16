__int64 __fastcall sub_140026760(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // ebx
  __int64 v5; // rdx
  __int64 v6; // rdx
  __int64 v7; // rcx
  __int64 v9; // rdx
  unsigned int v10; // esi
  __int64 v11; // rbx
  int v12; // eax
  const WCHAR *StringRawBuffer; // rbx
  const WCHAR *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rcx
  __int64 v17; // rcx
  void *retaddr; // [rsp+58h] [rbp+28h]
  __int64 v19; // [rsp+68h] [rbp+38h] BYREF
  __int64 v20; // [rsp+70h] [rbp+40h] BYREF
  HSTRING string; // [rsp+78h] [rbp+48h]

  v19 = a2;
  v20 = 0;
  v4 = guard_xfg_dispatch_icall_nop(a1: a3, a2: &v20);
  if ( v4 < 0 )
  {
    v5 = 178;
    goto LABEL_3;
  }
  LODWORD(v19) = 0;
  v4 = guard_xfg_dispatch_icall_nop(a1: v20, a2: &v19);
  if ( v4 >= 0 )
  {
    v10 = 0;
    if ( (_DWORD)v19 != 0 )
    {
      while ( 1 )
      {
        v11 = v20;
        WindowsDeleteString(string: nullptr);
        string = nullptr;
        v12 = guard_xfg_dispatch_icall_nop(a1: v11, a2: v10);
        v4 = v12;
        if ( v12 < 0 )
        {
          sub_140007D70(
            a1: retaddr,
            a2: 184,
            a3: "shell\\osshell\\accesory\\common\\edpapphelper\\edpapphelper.cpp",
            a4: (unsigned int)v12);
          WindowsDeleteString(string);
          string = nullptr;
          goto LABEL_4;
        }
        StringRawBuffer = WindowsGetStringRawBuffer(string: *(HSTRING *)(a1 + 8), length: nullptr);
        v14 = WindowsGetStringRawBuffer(string, length: nullptr);
        if ( CompareStringOrdinal(
               lpString1: v14,
               cchCount1: -1,
               lpString2: StringRawBuffer,
               cchCount2: -1,
               bIgnoreCase: true) == 2 )
          break;
        WindowsDeleteString(string);
        v10 += 2;
        if ( v10 >= (unsigned int)v19 )
          goto LABEL_13;
      }
      guard_xfg_dispatch_icall_nop(a1: v16, a2: v15);
      WindowsDeleteString(string);
      v17 = v20;
      string = nullptr;
      if ( v20 == 0 )
        return 0;
    }
    else
    {
LABEL_13:
      v17 = v20;
      if ( v20 == 0 )
        return 0;
    }
    v20 = 0;
    guard_xfg_dispatch_icall_nop(a1: v17, a2: v9);
    return 0;
  }
  v5 = 180;
LABEL_3:
  sub_140007D70(
    a1: retaddr,
    a2: v5,
    a3: "shell\\osshell\\accesory\\common\\edpapphelper\\edpapphelper.cpp",
    a4: (unsigned int)v4);
LABEL_4:
  v7 = v20;
  if ( v20 != 0 )
  {
    v20 = 0;
    guard_xfg_dispatch_icall_nop(a1: v7, a2: v6);
  }
  return (unsigned int)v4;
}
