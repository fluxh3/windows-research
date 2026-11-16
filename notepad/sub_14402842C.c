__int64 __fastcall sub_14002842C(const WCHAR *string)
{
  unsigned __int64 v2; // rbx
  UINT32 v3; // edx
  const WCHAR *v4; // rcx
  HRESULT v5; // ebx
  HRESULT v6; // eax
  int ActivationFactory; // eax
  __int64 v8; // rdx
  __int64 v9; // rdx
  __int64 v10; // rcx
  __int64 v12; // rbx
  unsigned int v13; // edi
  __int64 v14; // rcx
  __int64 v15; // [rsp+20h] [rbp-50h] BYREF
  HSTRING stringa; // [rsp+28h] [rbp-48h] BYREF
  __int16 v17; // [rsp+30h] [rbp-40h]
  __int64 v18; // [rsp+38h] [rbp-38h] BYREF
  HSTRING_HEADER hstringHeader; // [rsp+40h] [rbp-30h] BYREF
  HSTRING v20; // [rsp+58h] [rbp-18h] BYREF
  void *retaddr; // [rsp+78h] [rbp+8h]

  stringa = nullptr;
  v17 = 0;
  if ( string != nullptr )
  {
    v2 = -1;
    do
      ++v2;
    while ( string[v2] != 0 );
    if ( v2 > 0xFFFFFFFF )
    {
      v5 = -2147024362;
LABEL_9:
      sub_140007D70(
        a1: retaddr,
        a2: 174,
        a3: "shell\\osshell\\accesory\\common\\edpapphelper\\edpapphelper.cpp",
        a4: (unsigned int)v5);
LABEL_16:
      WindowsDeleteString(string: stringa);
      return (unsigned int)v5;
    }
    WindowsDeleteString(string: nullptr);
    v3 = v2;
    stringa = nullptr;
    v4 = string;
  }
  else
  {
    WindowsDeleteString(string: nullptr);
    v3 = 0;
    v4 = (const WCHAR *)&qword_14002C370;
  }
  v5 = WindowsCreateString(sourceString: v4, length: v3, string: &stringa);
  if ( v5 < 0 )
    goto LABEL_9;
  hstringHeader.Reserved.Reserved2[16] = 0;
  hstringHeader.Reserved.Reserved1 = sub_14000D3B0;
  *(_QWORD *)&hstringHeader.Reserved.Reserved2[8] = stringa;
  stringa = nullptr;
  hstringHeader.Reserved.Reserved2[17] = HIBYTE(v17) + 1;
  LOBYTE(v17) = 1;
  sub_140025F34(a1: &v18, a2: &hstringHeader);
  WindowsDeleteString(string: *(HSTRING *)&hstringHeader.Reserved.Reserved2[8]);
  v15 = 0;
  v20 = nullptr;
  v6 = WindowsCreateStringReference(
         sourceString: L"Windows.Security.EnterpriseData.ProtectionPolicyManager",
         length: 0x37u,
         &hstringHeader,
         string: &v20);
  if ( v6 < 0 )
  {
    sub_14000B5E0(a1: (unsigned int)v6);
    JUMPOUT(0x1400286C6LL);
  }
  ActivationFactory = RoGetActivationFactory(a1: v20, a2: qword_14002F270, a3: &v15);
  v5 = ActivationFactory;
  if ( ActivationFactory < 0 )
  {
    sub_140007D70(
      a1: retaddr,
      a2: 195,
      a3: "shell\\osshell\\accesory\\common\\edpapphelper\\edpapphelper.cpp",
      a4: (unsigned int)ActivationFactory);
    v10 = v15;
    if ( v15 != 0 )
    {
      v15 = 0;
      guard_xfg_dispatch_icall_nop(a1: v10, a2: v9);
    }
    if ( v18 != 0 )
      guard_xfg_dispatch_icall_nop(a1: v18, a2: v9);
    goto LABEL_16;
  }
  v12 = v18;
  if ( v18 != 0 )
    v13 = guard_xfg_dispatch_icall_nop(a1: v15, a2: v18);
  else
    v13 = 0x8007000E;
  v14 = v15;
  if ( v15 != 0 )
  {
    v15 = 0;
    guard_xfg_dispatch_icall_nop(a1: v14, a2: v8);
  }
  if ( v12 != 0 )
    guard_xfg_dispatch_icall_nop(a1: v12, a2: v8);
  WindowsDeleteString(string: stringa);
  return v13;
}
