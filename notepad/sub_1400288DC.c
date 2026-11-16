__int64 __fastcall sub_1400288DC(__int64 a1)
{
  HRESULT v2; // eax
  int ActivationFactory; // eax
  unsigned int v4; // edi
  _QWORD *v5; // rcx
  unsigned int v7; // eax
  _QWORD *v8; // rcx
  unsigned int v9; // ebx
  _QWORD *v10; // [rsp+20h] [rbp-30h] BYREF
  HSTRING_HEADER hstringHeader; // [rsp+28h] [rbp-28h] BYREF
  HSTRING string; // [rsp+40h] [rbp-10h] BYREF
  void *retaddr; // [rsp+58h] [rbp+8h]

  v10 = nullptr;
  string = nullptr;
  v2 = WindowsCreateStringReference(
         sourceString: L"Windows.Security.EnterpriseData.ProtectionPolicyManager",
         length: 0x37u,
         &hstringHeader,
         &string);
  if ( v2 < 0 )
  {
    sub_14000B5E0(a1: (unsigned int)v2);
    JUMPOUT(0x140028A24LL);
  }
  ActivationFactory = RoGetActivationFactory(a1: string, a2: qword_14002F270, a3: &v10);
  v4 = ActivationFactory;
  if ( ActivationFactory >= 0 )
  {
    v7 = guard_xfg_dispatch_icall_nop(a1: v10, a2: a1);
    v8 = v10;
    v9 = v7;
    if ( v10 != nullptr )
    {
      v10 = nullptr;
      guard_xfg_dispatch_icall_nop(a1: v8, a2: *v8);
    }
    return v9;
  }
  else
  {
    sub_140007D70(
      a1: retaddr,
      a2: 202,
      a3: "shell\\osshell\\accesory\\common\\edpapphelper\\edpapphelper.cpp",
      a4: (unsigned int)ActivationFactory);
    v5 = v10;
    if ( v10 != nullptr )
    {
      v10 = nullptr;
      guard_xfg_dispatch_icall_nop(a1: v5, a2: *v5);
    }
    return v4;
  }
}
