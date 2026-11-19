__int64 __fastcall DwmpAllocateSecurityDescriptor(struct _ACL **a1, ACCESS_MASK a2)
{
  unsigned int v2; // edi
  NTSTATUS v5; // eax
  ULONG v6; // r14d
  HANDLE ProcessHeap; // rax
  struct _ACL *Heap; // rax
  struct _ACL *v9; // rbx
  NTSTATUS SecurityDescriptor; // eax
  unsigned int v12; // edx
  unsigned int v13; // edx
  HANDLE v14; // rax
  PSID Sid; // [rsp+60h] [rbp-20h] BYREF
  struct _SID_IDENTIFIER_AUTHORITY IdentifierAuthority; // [rsp+68h] [rbp-18h] BYREF

  v2 = 0;
  *(_WORD *)&IdentifierAuthority.Value[4] = 1280;
  Sid = nullptr;
  *(_DWORD *)IdentifierAuthority.Value = 0;
  v5 = RtlAllocateAndInitializeSid(
         &IdentifierAuthority,
         SubAuthorityCount: 3u,
         SubAuthority0: 0x5Au,
         SubAuthority1: 0,
         SubAuthority2: NtCurrentPeb()->SessionId,
         SubAuthority3: 0,
         SubAuthority4: 0,
         SubAuthority5: 0,
         SubAuthority6: 0,
         SubAuthority7: 0,
         &Sid);
  if ( v5 < 0 )
  {
    v12 = 48;
    v2 = v5 | 0x10000000;
LABEL_15:
    DoStackCaptureDirect(a1: v2, a2: v12);
    goto LABEL_10;
  }
  v6 = RtlLengthSid(Sid);
  ProcessHeap = GetProcessHeap();
  Heap = (struct _ACL *)RtlAllocateHeap(HeapHandle: ProcessHeap, Flags: 8u, Size: v6 + 60);
  v9 = Heap;
  if ( Heap == nullptr )
  {
    v2 = 0x8007000E;
    v12 = 58;
    goto LABEL_15;
  }
  SecurityDescriptor = RtlCreateSecurityDescriptor(SecurityDescriptor: Heap, Revision: 1u);
  if ( SecurityDescriptor < 0 )
  {
    v13 = 60;
  }
  else
  {
    SecurityDescriptor = RtlCreateAcl(Acl: v9 + 5, AclSize: v6 + 20, AclRevision: 2u);
    if ( SecurityDescriptor < 0 )
    {
      v13 = 64;
    }
    else
    {
      SecurityDescriptor = RtlAddAccessAllowedAce(Acl: v9 + 5, Revision: 2u, AccessMask: a2, Sid);
      if ( SecurityDescriptor < 0 )
      {
        v13 = 69;
      }
      else
      {
        SecurityDescriptor = RtlSetDaclSecurityDescriptor(
                               SecurityDescriptor: v9,
                               DaclPresent: 1u,
                               Dacl: v9 + 5,
                               DaclDefaulted: 0);
        if ( SecurityDescriptor >= 0 )
        {
          *a1 = v9;
          v9 = nullptr;
          goto LABEL_8;
        }
        v13 = 71;
      }
    }
  }
  v2 = SecurityDescriptor | 0x10000000;
  DoStackCaptureDirect(a1: SecurityDescriptor | 0x10000000, a2: v13);
LABEL_8:
  if ( v9 != nullptr )
  {
    v14 = GetProcessHeap();
    RtlFreeHeap(HeapHandle: v14, Flags: 0, P: v9);
  }
LABEL_10:
  if ( Sid != nullptr )
    RtlFreeSid(Sid);
  return v2;
}
