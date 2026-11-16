__int64 __fastcall sub_140026E9C(__int64 a1, __int64 a2)
{
  HRESULT v3; // eax
  int ActivationFactory; // eax
  int v5; // ebx
  __int64 v6; // rdx
  __int64 v7; // rcx
  __int64 v8; // rbx
  __int64 v9; // rax
  int v10; // eax
  __int64 v11; // rcx
  __int64 v12; // rdi
  __int64 v13; // rcx
  __int64 v15; // [rsp+20h] [rbp-40h] BYREF
  __int64 v16; // [rsp+28h] [rbp-38h]
  __int64 v17; // [rsp+30h] [rbp-30h]
  HSTRING_HEADER hstringHeader; // [rsp+38h] [rbp-28h] BYREF
  HSTRING string; // [rsp+50h] [rbp-10h] BYREF
  void *retaddr; // [rsp+78h] [rbp+18h]

  v15 = 0;
  string = nullptr;
  v17 = a1;
  v3 = WindowsCreateStringReference(
         sourceString: L"Windows.Storage.StorageFile",
         length: 0x1Bu,
         &hstringHeader,
         &string);
  if ( v3 < 0 )
  {
    sub_14000B5E0(a1: (unsigned int)v3);
    JUMPOUT(0x140027081LL);
  }
  ActivationFactory = RoGetActivationFactory(a1: string, a2: qword_14002C108, a3: &v15);
  v5 = ActivationFactory;
  if ( ActivationFactory >= 0 )
  {
    v8 = v15;
    v16 = 0;
    v9 = sub_140009CAC(&hstringHeader);
    v10 = guard_xfg_dispatch_icall_nop(a1: v8, a2: *(_QWORD *)(v9 + 24));
    v5 = v10;
    if ( v10 >= 0 )
    {
      v12 = v16;
      v5 = sub_14002630C(a1: v16);
      if ( v5 >= 0 )
        v5 = guard_xfg_dispatch_icall_nop(a1: v12, a2);
      v13 = v16;
      if ( v16 != 0 )
      {
        v16 = 0;
        guard_xfg_dispatch_icall_nop(a1: v13, a2: v6);
      }
      v7 = v15;
      if ( v15 != 0 )
        goto LABEL_14;
      return (unsigned int)v5;
    }
    sub_140007D70(
      a1: retaddr,
      a2: 30,
      a3: "shell\\osshell\\accesory\\common\\edpapphelper\\edpapphelper.cpp",
      a4: (unsigned int)v10);
    v11 = v16;
    if ( v16 != 0 )
    {
      v16 = 0;
      guard_xfg_dispatch_icall_nop(a1: v11, a2: v6);
    }
  }
  else
  {
    sub_140007D70(
      a1: retaddr,
      a2: 28,
      a3: "shell\\osshell\\accesory\\common\\edpapphelper\\edpapphelper.cpp",
      a4: (unsigned int)ActivationFactory);
  }
  v7 = v15;
  if ( v15 != 0 )
  {
LABEL_14:
    v15 = 0;
    guard_xfg_dispatch_icall_nop(a1: v7, a2: v6);
  }
  return (unsigned int)v5;
}
