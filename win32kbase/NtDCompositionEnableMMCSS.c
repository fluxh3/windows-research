__int64 __fastcall NtDCompositionEnableMMCSS(int a1)
{
  unsigned int v2; // edi
  DirectComposition::CConnection *DefaultConnection; // rsi
  struct DirectComposition::CProcessData *v4; // rbp
  struct _ERESOURCE *Resource; // rbx
  int v6; // eax
  bool v7; // cl
  int v8; // eax

  v2 = 0;
  DefaultConnection = DirectComposition::CConnection::GetDefaultConnection();
  if ( DefaultConnection != nullptr )
  {
    v4 = DirectComposition::CProcessData::Current();
    Resource = *((struct _ERESOURCE **)v4 + 1);
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(Resource, Wait: 1u);
    v6 = *((_DWORD *)v4 + 10);
    if ( a1 != 0 )
    {
      if ( v6 != -1 )
      {
        v7 = v6 == 0;
        v8 = v6 + 1;
        goto LABEL_8;
      }
    }
    else if ( v6 != 0 )
    {
      v8 = v6 - 1;
      v7 = v8 == 0;
LABEL_8:
      *((_DWORD *)v4 + 10) = v8;
      if ( v7 )
        v2 = DirectComposition::CConnection::EnableMMCSS(this: DefaultConnection, a2: a1);
      goto LABEL_11;
    }
    v2 = 0xC0000001;
LABEL_11:
    ExReleaseResourceLite(Resource: *((PERESOURCE *)v4 + 1));
    KeLeaveCriticalRegion();
    DirectComposition::CConnection::Release(this: DefaultConnection);
    return v2;
  }
  return (unsigned int)-1073741790;
}
