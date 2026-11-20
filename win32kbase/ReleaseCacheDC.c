__int64 __fastcall ReleaseCacheDC(__int64 a1, int a2, int a3)
{
  __int64 v3; // rdi
  int v4; // ebp
  struct _ERESOURCE *ghsemGreLock; // rbx
  struct _ERESOURCE *ghsemDCVisRgn; // rbx
  __int64 v7; // r13
  __int64 v8; // rsi
  __int64 v9; // rdx
  int v10; // r8d
  int v11; // eax
  HDC v12; // rbx
  BOOL v13; // ebx
  __int64 n0x10000_12; // rbp
  __int64 v15; // r12
  GdiHandleManager *`?gpHandleManager@@3PEAVGdiHandleManager@@EA`; // r14
  unsigned int n0x10000; // ebx
  __int64 v18; // r14
  unsigned int n0x10000_1; // edx
  __int64 v20; // rcx
  __int64 v21; // r14
  unsigned __int16 *v22; // rdi
  __int64 v23; // r13
  _QWORD *v24; // rax
  char v25; // al
  unsigned int n0x10000_2; // ebx
  __int64 v27; // rdx
  unsigned int n0x10000_3; // r8d
  __int64 v29; // rcx
  __int64 v30; // r9
  unsigned int n0x10000_4; // ebx
  GdiHandleManager *`?gpHandleManager@@3PEAVGdiHandleManager@@EA_2`; // rdi
  __int64 v33; // rdx
  unsigned int n0x10000_5; // r8d
  __int64 v35; // rcx
  __int64 v36; // r9
  _DWORD *v37; // rdx
  unsigned int n0x10000_6; // ebx
  __int64 v39; // rdx
  unsigned int n0x10000_7; // r8d
  __int64 v41; // rcx
  __int64 v42; // r10
  REGION *v43; // rdx
  HDC v44; // r15
  int v45; // eax
  unsigned int v46; // edi
  unsigned int v47; // edi
  GdiHandleManager *`?gpHandleManager@@3PEAVGdiHandleManager@@EA_3`; // rbx
  unsigned int v49; // eax
  __int64 v50; // r9
  unsigned int v51; // edx
  unsigned int v52; // r8d
  __int64 v53; // rcx
  GdiHandleEntryTable *v54; // r9
  struct _ENTRY *v55; // rax
  struct _ENTRY *v56; // rbx
  bool v57; // zf
  BOOL v58; // r14d
  char n16; // al
  unsigned int n0x10000_8; // ebx
  GdiHandleManager *`?gpHandleManager@@3PEAVGdiHandleManager@@EA_4`; // rdi
  __int64 v62; // rdx
  unsigned int n0x10000_9; // r8d
  __int64 v64; // rcx
  __int64 v65; // r9
  _DWORD *v66; // rdx
  unsigned int n0x10000_10; // ebx
  __int64 v68; // rdx
  unsigned int n0x10000_11; // r8d
  __int64 v70; // rcx
  __int64 v71; // r10
  int ghsemDCVisRgn_1; // ecx
  int ghsemGreLock_1; // ecx
  int v75; // eax
  __int64 v76; // rcx
  __int64 CurrentProcess; // rax
  __int64 CurrentThreadProcess; // rax
  GdiHandleManager *`?gpHandleManager@@3PEAVGdiHandleManager@@EA_1`; // rbx
  unsigned int v80; // eax
  __int64 v81; // r9
  unsigned __int64 v82; // rdx
  unsigned int v83; // r8d
  __int64 v84; // rcx
  __int64 v85; // r10
  __int64 v86; // rdx
  void *v87; // rdx
  ReferenceTrackerCountedType n2; // ecx
  __int64 v89; // [rsp+30h] [rbp-88h] BYREF
  _QWORD v90[2]; // [rsp+38h] [rbp-80h] BYREF
  unsigned __int16 *v91; // [rsp+48h] [rbp-70h] BYREF
  int v92; // [rsp+50h] [rbp-68h]
  int v93; // [rsp+54h] [rbp-64h]
  struct _ENTRY *v94; // [rsp+60h] [rbp-58h] BYREF
  int v95; // [rsp+68h] [rbp-50h]
  int v96; // [rsp+6Ch] [rbp-4Ch]
  __int64 v98; // [rsp+D0h] [rbp+18h] BYREF
  __int64 v99; // [rsp+D8h] [rbp+20h]

  v3 = a1;
  v4 = a2;
  LODWORD(a1) = (_DWORD)ghsemDynamicModeChange;
  if ( ghsemDynamicModeChange != nullptr )
    ExEnterPriorityRegionAndAcquireResourceShared();
  if ( gbLockEtw != 0 && (Microsoft_Windows_Win32kEnableBits & 0x10) != 0 )
    McTemplateK0pz_EtwWriteTransfer(
      a1,
      a2: (unsigned int)LockAcquireShared,
      a3,
      a4: (_DWORD)ghsemDynamicModeChange,
      a5: (__int64)L"ghsemDynamicModeChange");
  ghsemGreLock = (struct _ERESOURCE *)::ghsemGreLock;
  if ( ::ghsemGreLock != 0 )
  {
    PsEnterPriorityRegion();
    ExEnterCriticalRegionAndAcquireResourceExclusive(Resource: ghsemGreLock);
  }
  if ( gbLockEtw != 0 && (Microsoft_Windows_Win32kEnableBits & 0x10) != 0 )
    McTemplateK0pqz_EtwWriteTransfer(a1, a2, a3, a4: ::ghsemGreLock, a5: 2, a6: (__int64)L"ghsemGreLock");
  ghsemDCVisRgn = ::ghsemDCVisRgn;
  if ( ::ghsemDCVisRgn != nullptr )
  {
    PsEnterPriorityRegion();
    ExEnterCriticalRegionAndAcquireResourceExclusive(Resource: ghsemDCVisRgn);
  }
  if ( gbLockEtw != 0 && (Microsoft_Windows_Win32kEnableBits & 0x10) != 0 )
    McTemplateK0pqz_EtwWriteTransfer(a1, a2, a3, a4: (_DWORD)::ghsemDCVisRgn, a5: 3, a6: (__int64)L"ghsemDCVisRgn");
  v7 = gpDispInfo + 24;
  v99 = gpDispInfo + 24;
  v8 = *(_QWORD *)(gpDispInfo + 24);
  if ( v8 == 0 )
  {
LABEL_126:
    GreUnlockVisRgn(a1: *(_QWORD *)(gpDispInfo + 40));
    UserSetLastError(a1: 1425);
    return 2;
  }
  while ( 1 )
  {
    v9 = *(_QWORD *)(v8 + 8);
    if ( v9 == v3 )
      break;
    v7 = v8;
    v99 = v8;
    v8 = *(_QWORD *)v8;
    if ( v8 == 0 )
      goto LABEL_126;
  }
  v10 = *(_DWORD *)(v8 + 64);
  if ( v10 < 0 )
  {
    v75 = DestroyCacheDC(a1: v7, a2: v9);
    v76 = *(_QWORD *)(gpDispInfo + 40);
    if ( v75 != 0 )
    {
      GreUnlockVisRgn(a1: v76);
      return 1;
    }
    goto LABEL_136;
  }
  if ( (v10 & 0x401800) == 0x1000 )
  {
    if ( (v10 & 0x4000) != 0 )
    {
      a1 = *(_QWORD *)(*(_QWORD *)(v8 + 32) + 40LL);
      if ( (*(_BYTE *)(a1 + 27) & 2) != 0
        && (int)IsFlushWEFCOMPOSITEDDCEBoundsSupported() >= 0
        && qword_1C02525D0 != nullptr )
      {
        qword_1C02525D0(a1: v8);
      }
    }
    v11 = *(_DWORD *)(v8 + 64);
    if ( (v11 & 2) == 0 )
      goto LABEL_114;
    if ( qword_1C02519C0 != nullptr && (int)qword_1C02519C0() >= 0 && qword_1C02519C8 != nullptr )
      qword_1C02519C8(a1: v3, a2: 0, a3: 0, a4: 0, a5: 0);
    v12 = *(HDC *)(v8 + 8);
    v90[0] = 0;
    v90[1] = 0;
    XDCOBJ::vLock(this: (XDCOBJ *)v90, a2: v12);
    v13 = v90[0] != 0
       && (unsigned int)XDCOBJ::bCleanDC(this: (XDCOBJ *)v90, a2: 0) != 0
       && (unsigned int)GreSetDCOwnerEx(a1: v12, a2: 2147483666LL, a3: 0, a4: 0) != 0;
    XDCOBJ::vUnlockNoNullSet(this: (XDCOBJ *)v90);
    if ( v13 != 0 )
    {
      *(_DWORD *)(v8 + 64) &= ~0x1000u;
      n0x10000_12 = *(_QWORD *)(v8 + 8);
      v15 = 0;
      *(_QWORD *)(v8 + 72) = 0;
      *(_QWORD *)(v8 + 80) = 0;
      v89 = 0;
      PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion(a1: &v89);
      if ( (unsigned __int8)KeIsAttachedProcess() != 0 )
      {
        CurrentProcess = PsGetCurrentProcess();
        PsGetProcessSessionIdEx(a1: CurrentProcess);
        CurrentThreadProcess = PsGetCurrentThreadProcess();
        PsGetProcessSessionIdEx(a1: CurrentThreadProcess);
      }
      `?gpHandleManager@@3PEAVGdiHandleManager@@EA` = gpHandleManager;
      n0x10000 = (unsigned __int16)n0x10000_12 | ((unsigned int)n0x10000_12 >> 8) & 0xFF0000;
      v92 = 1;
      if ( n0x10000 >= 0x10000 )
      {
        if ( *(_DWORD *)gpHandleManager > 0x10000u )
        {
          if ( *((unsigned __int8 *)GdiHandleEntryDirectory::GetEntry(
                                      this: *((GdiHandleEntryDirectory **)gpHandleManager + 2),
                                      a2: (unsigned __int16)n0x10000_12,
                                      a3: true)
               + 13) == (((unsigned int)n0x10000_12 >> 8) & 0xFF0000) >> 16 )
            n0x10000 = (unsigned __int16)n0x10000_12;
        }
        else
        {
          n0x10000 = (unsigned __int16)n0x10000_12;
        }
      }
      v18 = *((_QWORD *)`?gpHandleManager@@3PEAVGdiHandleManager@@EA` + 2);
      n0x10000_1 = *(_DWORD *)(v18 + 2056);
      if ( n0x10000 >= n0x10000_1 + ((*(unsigned __int16 *)(v18 + 2) + 0xFFFF) << 16) )
        goto LABEL_181;
      v20 = ((n0x10000 - n0x10000_1) >> 16) + 1;
      if ( n0x10000 < n0x10000_1 )
        v20 = 0;
      v21 = *(_QWORD *)(v18 + 8 * v20 + 8);
      if ( (_DWORD)v20 != 0 )
        n0x10000 += ((1 - (_DWORD)v20) << 16) - n0x10000_1;
      v22 = nullptr;
      if ( n0x10000 < *(_DWORD *)(v21 + 20) )
      {
        v23 = 16LL * (unsigned __int8)n0x10000;
        v24 = *(_QWORD **)(v21 + 24);
        v90[0] = 8 * ((unsigned __int64)n0x10000 >> 8);
        v98 = v23 + *(_QWORD *)(*v24 + v90[0]);
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(a1: v98, a2: 0);
        if ( n0x10000 < *(_DWORD *)(v21 + 20)
          && *(_QWORD *)(*(_QWORD *)(**(_QWORD **)(v21 + 24) + v90[0]) + v23 + 8) != 0 )
        {
          *(_DWORD *)(*(_QWORD *)v21 + 24LL * n0x10000 + 8) |= 1u;
          v22 = (unsigned __int16 *)(24LL * n0x10000 + *(_QWORD *)v21);
        }
        else
        {
          ExReleasePushLockExclusiveEx(a1: v98, a2: 0);
          KeLeaveCriticalRegion();
        }
        v7 = v99;
      }
      v91 = v22;
      if ( v22 == nullptr )
      {
LABEL_181:
        KeLeaveCriticalRegion();
        goto LABEL_107;
      }
      _m_prefetchw(v22 + 4);
      v93 = *((_DWORD *)v22 + 2);
      v25 = *((_BYTE *)v22 + 15);
      if ( (v25 & 0x20) != 0 )
        goto LABEL_161;
      if ( (v25 & 0x40) != 0 )
      {
        `?gpHandleManager@@3PEAVGdiHandleManager@@EA_1` = gpHandleManager;
        v80 = GdiHandleManager::DecodeIndex(this: gpHandleManager, a2: *(_DWORD *)v22 & 0xFFFFFF);
        v81 = *((_QWORD *)`?gpHandleManager@@3PEAVGdiHandleManager@@EA_1` + 2);
        v82 = v80;
        v83 = *(_DWORD *)(v81 + 2056);
        if ( v80 >= v83 + ((*(unsigned __int16 *)(v81 + 2) + 0xFFFF) << 16) )
          goto LABEL_158;
        v84 = ((v80 - v83) >> 16) + 1;
        if ( v80 < v83 )
          v84 = 0;
        v85 = *(_QWORD *)(v81 + 8 * v84 + 8);
        if ( (_DWORD)v84 != 0 )
          v82 = ((1 - (_DWORD)v84) << 16) - *(_DWORD *)(v81 + 2056) + v80;
        if ( (unsigned int)v82 >= *(_DWORD *)(v85 + 20) )
LABEL_158:
          v86 = 0;
        else
          v86 = *(_QWORD *)(*(_QWORD *)(**(_QWORD **)(v85 + 24) + 8 * (v82 >> 8)) + 16LL * (unsigned __int8)v82 + 8);
        if ( *(_WORD *)(v86 + 12) != 0 && *(struct _KTHREAD **)(v86 + 16) == KeGetCurrentThread() )
        {
LABEL_162:
          v22 = v91;
          goto LABEL_44;
        }
LABEL_161:
        HANDLELOCK::vUnlock(this: (HANDLELOCK *)&v91);
        if ( v92 == 0 )
          goto LABEL_107;
        goto LABEL_162;
      }
LABEL_44:
      if ( *((_BYTE *)v22 + 14) == 1 && v22[6] == WORD1(n0x10000_12) )
      {
        n0x10000_2 = *(_DWORD *)v22 & 0xFFFFFF;
        if ( n0x10000_2 >= 0x10000 )
        {
          if ( *(_DWORD *)gpHandleManager > 0x10000u )
          {
            if ( *((unsigned __int8 *)GdiHandleEntryDirectory::GetEntry(
                                        this: *((GdiHandleEntryDirectory **)gpHandleManager + 2),
                                        a2: *v22,
                                        a3: true)
                 + 13) == HIWORD(n0x10000_2) )
              n0x10000_2 = (unsigned __int16)n0x10000_2;
          }
          else
          {
            n0x10000_2 = *v22;
          }
        }
        v27 = *((_QWORD *)gpHandleManager + 2);
        n0x10000_3 = *(_DWORD *)(v27 + 2056);
        if ( n0x10000_2 >= n0x10000_3 + ((*(unsigned __int16 *)(v27 + 2) + 0xFFFF) << 16) )
          goto LABEL_165;
        v29 = ((n0x10000_2 - n0x10000_3) >> 16) + 1;
        if ( n0x10000_2 < n0x10000_3 )
          v29 = 0;
        v30 = *(_QWORD *)(v27 + 8 * v29 + 8);
        if ( (_DWORD)v29 != 0 )
          n0x10000_2 += ((1 - (_DWORD)v29) << 16) - *(_DWORD *)(v27 + 2056);
        if ( n0x10000_2 >= *(_DWORD *)(v30 + 20) )
LABEL_165:
          v15 = 0;
        else
          v15 = *(_QWORD *)(*(_QWORD *)(**(_QWORD **)(v30 + 24) + 8 * ((unsigned __int64)n0x10000_2 >> 8))
                          + 16LL * (unsigned __int8)n0x10000_2
                          + 8);
        ++*(_DWORD *)(v15 + 8);
      }
      n0x10000_4 = *(_DWORD *)v22 & 0xFFFFFF;
      if ( n0x10000_4 >= 0x10000 )
      {
        if ( *(_DWORD *)gpHandleManager > 0x10000u )
        {
          if ( *((unsigned __int8 *)GdiHandleEntryDirectory::GetEntry(
                                      this: *((GdiHandleEntryDirectory **)gpHandleManager + 2),
                                      a2: *v22,
                                      a3: true)
               + 13) == HIWORD(n0x10000_4) )
            n0x10000_4 = (unsigned __int16)n0x10000_4;
        }
        else
        {
          n0x10000_4 = *v22;
        }
      }
      `?gpHandleManager@@3PEAVGdiHandleManager@@EA_2` = gpHandleManager;
      v33 = *((_QWORD *)gpHandleManager + 2);
      n0x10000_5 = *(_DWORD *)(v33 + 2056);
      if ( n0x10000_4 >= n0x10000_5 + ((*(unsigned __int16 *)(v33 + 2) + 0xFFFF) << 16) )
        goto LABEL_168;
      v35 = ((n0x10000_4 - n0x10000_5) >> 16) + 1;
      if ( n0x10000_4 < n0x10000_5 )
        v35 = 0;
      v36 = *(_QWORD *)(v33 + 8 * v35 + 8);
      if ( (_DWORD)v35 != 0 )
        n0x10000_4 += ((1 - (_DWORD)v35) << 16) - *(_DWORD *)(v33 + 2056);
      if ( n0x10000_4 >= *(_DWORD *)(v36 + 20) )
LABEL_168:
        v37 = nullptr;
      else
        v37 = *(_DWORD **)(*(_QWORD *)(**(_QWORD **)(v36 + 24) + 8 * ((unsigned __int64)n0x10000_4 >> 8))
                         + 16LL * (unsigned __int8)n0x10000_4
                         + 8);
      n0x10000_6 = (unsigned __int16)*v37 | (*v37 >> 8) & 0xFF0000;
      if ( n0x10000_6 >= 0x10000 )
      {
        if ( *(_DWORD *)gpHandleManager > 0x10000u )
        {
          if ( *((unsigned __int8 *)GdiHandleEntryDirectory::GetEntry(
                                      this: *((GdiHandleEntryDirectory **)gpHandleManager + 2),
                                      a2: (unsigned __int16)*v37,
                                      a3: true)
               + 13) == HIWORD(n0x10000_6) )
            n0x10000_6 = (unsigned __int16)n0x10000_6;
        }
        else
        {
          n0x10000_6 = (unsigned __int16)*v37;
        }
      }
      v39 = *((_QWORD *)`?gpHandleManager@@3PEAVGdiHandleManager@@EA_2` + 2);
      n0x10000_7 = *(_DWORD *)(v39 + 2056);
      if ( n0x10000_6 < n0x10000_7 + ((*(unsigned __int16 *)(v39 + 2) + 0xFFFF) << 16) )
      {
        v41 = ((n0x10000_6 - n0x10000_7) >> 16) + 1;
        if ( n0x10000_6 < n0x10000_7 )
          v41 = 0;
        v42 = *(_QWORD *)(v39 + 8 * v41 + 8);
        if ( (_DWORD)v41 != 0 )
          n0x10000_6 += ((1 - (_DWORD)v41) << 16) - *(_DWORD *)(v39 + 2056);
        *(_DWORD *)(*(_QWORD *)v42 + 24LL * n0x10000_6 + 8) &= ~1u;
        ExReleasePushLockExclusiveEx(
          a1: *(_QWORD *)(**(_QWORD **)(v42 + 24) + 8 * ((unsigned __int64)n0x10000_6 >> 8))
        + 16LL * (unsigned __int8)n0x10000_6,
          a2: 0);
        KeLeaveCriticalRegion();
      }
      KeLeaveCriticalRegion();
      if ( v15 == 0 )
        goto LABEL_107;
      v43 = *(REGION **)(v15 + 1120);
      *(_DWORD *)(v15 + 36) &= ~0x100000u;
      GrepValidateVisRgn(a1: (DC *)v15, a2: v43);
      v44 = *(HDC *)v15;
      v45 = (unsigned __int16)*(_QWORD *)v15;
      v46 = ((unsigned int)*(_QWORD *)v15 >> 8) & 0xFF0000;
      v98 = 0;
      v47 = v45 | v46;
      PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion(a1: &v98);
      IsThreadCrossSessionAttached();
      `?gpHandleManager@@3PEAVGdiHandleManager@@EA_3` = gpHandleManager;
      v95 = 1;
      v49 = GdiHandleManager::DecodeIndex(this: gpHandleManager, a2: v47);
      v50 = *((_QWORD *)`?gpHandleManager@@3PEAVGdiHandleManager@@EA_3` + 2);
      v51 = v49;
      v52 = *(_DWORD *)(v50 + 2056);
      if ( v49 >= v52 + ((*(unsigned __int16 *)(v50 + 2) + 0xFFFF) << 16) )
        goto LABEL_181;
      v53 = ((v49 - v52) >> 16) + 1;
      if ( v49 < v52 )
        v53 = 0;
      v54 = *(GdiHandleEntryTable **)(v50 + 8 * v53 + 8);
      if ( (_DWORD)v53 != 0 )
        v51 = ((1 - (_DWORD)v53) << 16) - v52 + v49;
      v55 = GdiHandleEntryTable::AcquireEntryLock(this: v54, a2: v51, a3: false);
      v94 = v55;
      v56 = v55;
      if ( v55 == nullptr )
        goto LABEL_181;
      _m_prefetchw((char *)v55 + 8);
      v57 = (*((_BYTE *)v55 + 15) & 0x20) == 0;
      v96 = *((_DWORD *)v55 + 2);
      if ( v57 )
        goto LABEL_84;
      HANDLELOCK::vUnlock(this: (HANDLELOCK *)&v94);
      if ( v95 != 0 )
      {
        v56 = v94;
LABEL_84:
        v58 = (*((_BYTE *)v56 + 15) & 8) != 0;
        n16 = *((_BYTE *)v56 + 14);
        if ( n16 == 5 )
        {
          v87 = *(void **)(v15 + 680);
          n2 = 0;
        }
        else
        {
          if ( n16 != 16 )
          {
LABEL_86:
            --*(_DWORD *)(v15 + 8);
            n0x10000_8 = *(_DWORD *)v56 & 0xFFFFFF;
            if ( n0x10000_8 >= 0x10000 )
            {
              if ( *(_DWORD *)gpHandleManager > 0x10000u )
              {
                if ( *((unsigned __int8 *)GdiHandleEntryDirectory::GetEntry(
                                            this: *((GdiHandleEntryDirectory **)gpHandleManager + 2),
                                            a2: (unsigned __int16)n0x10000_8,
                                            a3: true)
                     + 13) == HIWORD(n0x10000_8) )
                  n0x10000_8 = (unsigned __int16)n0x10000_8;
              }
              else
              {
                n0x10000_8 = (unsigned __int16)n0x10000_8;
              }
            }
            `?gpHandleManager@@3PEAVGdiHandleManager@@EA_4` = gpHandleManager;
            v62 = *((_QWORD *)gpHandleManager + 2);
            n0x10000_9 = *(_DWORD *)(v62 + 2056);
            if ( n0x10000_8 >= n0x10000_9 + ((*(unsigned __int16 *)(v62 + 2) + 0xFFFF) << 16) )
              goto LABEL_178;
            v64 = ((n0x10000_8 - n0x10000_9) >> 16) + 1;
            if ( n0x10000_8 < n0x10000_9 )
              v64 = 0;
            v65 = *(_QWORD *)(v62 + 8 * v64 + 8);
            if ( (_DWORD)v64 != 0 )
              n0x10000_8 += ((1 - (_DWORD)v64) << 16) - *(_DWORD *)(v62 + 2056);
            if ( n0x10000_8 >= *(_DWORD *)(v65 + 20) )
LABEL_178:
              v66 = nullptr;
            else
              v66 = *(_DWORD **)(*(_QWORD *)(**(_QWORD **)(v65 + 24) + 8 * ((unsigned __int64)n0x10000_8 >> 8))
                               + 16LL * (unsigned __int8)n0x10000_8
                               + 8);
            n0x10000_10 = (unsigned __int16)*v66 | (*v66 >> 8) & 0xFF0000;
            if ( n0x10000_10 >= 0x10000 )
            {
              if ( *(_DWORD *)gpHandleManager > 0x10000u )
              {
                if ( *((unsigned __int8 *)GdiHandleEntryDirectory::GetEntry(
                                            this: *((GdiHandleEntryDirectory **)gpHandleManager + 2),
                                            a2: (unsigned __int16)*v66,
                                            a3: true)
                     + 13) == HIWORD(n0x10000_10) )
                  n0x10000_10 = (unsigned __int16)n0x10000_10;
              }
              else
              {
                n0x10000_10 = (unsigned __int16)*v66;
              }
            }
            v68 = *((_QWORD *)`?gpHandleManager@@3PEAVGdiHandleManager@@EA_4` + 2);
            n0x10000_11 = *(_DWORD *)(v68 + 2056);
            if ( n0x10000_10 < n0x10000_11 + ((*(unsigned __int16 *)(v68 + 2) + 0xFFFF) << 16) )
            {
              v70 = ((n0x10000_10 - n0x10000_11) >> 16) + 1;
              if ( n0x10000_10 < n0x10000_11 )
                v70 = 0;
              v71 = *(_QWORD *)(v68 + 8 * v70 + 8);
              if ( (_DWORD)v70 != 0 )
                n0x10000_10 += ((1 - (_DWORD)v70) << 16) - *(_DWORD *)(v68 + 2056);
              *(_DWORD *)(*(_QWORD *)v71 + 24LL * n0x10000_10 + 8) &= ~1u;
              ExReleasePushLockExclusiveEx(
                a1: *(_QWORD *)(**(_QWORD **)(v71 + 24) + 8 * ((unsigned __int64)n0x10000_10 >> 8))
              + 16LL * (unsigned __int8)n0x10000_10,
                a2: 0);
              KeLeaveCriticalRegion();
            }
            KeLeaveCriticalRegion();
            if ( v58 != 0 )
              bDeleteDCInternalEx(a1: v44);
            goto LABEL_107;
          }
          v87 = *(void **)(v15 + 136);
          n2 = 2;
        }
        TrackObjectReferenceDecrement(a1: n2, a2: v87);
        goto LABEL_86;
      }
LABEL_107:
      if ( (*(_DWORD *)(v8 + 64) & 0x4000) != 0
        && qword_1C02519A0 != nullptr
        && (int)qword_1C02519A0() >= 0
        && qword_1C02519A8 != nullptr )
      {
        qword_1C02519A8(a1: *(_QWORD *)(v8 + 8), a2: 0);
      }
      if ( ++gnDCECount > 32 && (unsigned int)DestroyCacheDC(a1: v7, a2: *(_QWORD *)(v8 + 8)) != 0 )
      {
        GreUnlockVisRgn(a1: *(_QWORD *)(gpDispInfo + 40));
        return 1;
      }
      v11 = *(_DWORD *)(v8 + 64);
      v4 = a2;
LABEL_114:
      if ( (v11 & 0xC0) != 0
        && ((v11 & 2) != 0 || v4 != 0)
        && (int)IsDeleteHrgnClipSupported() >= 0
        && qword_1C02525C0 != nullptr )
      {
        qword_1C02525C0(a1: v8);
      }
      if ( gbLockEtw != 0 && (Microsoft_Windows_Win32kEnableBits & 0x10) != 0 )
        McTemplateK0pz_EtwWriteTransfer(
          a1,
          a2: (unsigned int)LockRelease,
          a3: v10,
          a4: (_DWORD)::ghsemDCVisRgn,
          a5: (__int64)L"ghsemDCVisRgn");
      ghsemDCVisRgn_1 = (int)::ghsemDCVisRgn;
      if ( ::ghsemDCVisRgn != nullptr )
      {
        ExReleaseResourceAndLeaveCriticalRegion(Resource: ::ghsemDCVisRgn);
        PsLeavePriorityRegion();
      }
      if ( gbLockEtw != 0 && (Microsoft_Windows_Win32kEnableBits & 0x10) != 0 )
        McTemplateK0pz_EtwWriteTransfer(
          a1: ghsemDCVisRgn_1,
          a2: (unsigned int)LockRelease,
          a3: v10,
          a4: ::ghsemGreLock,
          a5: (__int64)L"ghsemGreLock");
      ghsemGreLock_1 = ::ghsemGreLock;
      if ( ::ghsemGreLock != 0 )
      {
        ExReleaseResourceAndLeaveCriticalRegion(Resource: (PERESOURCE)::ghsemGreLock);
        PsLeavePriorityRegion();
      }
      if ( gbLockEtw != 0 && (Microsoft_Windows_Win32kEnableBits & 0x10) != 0 )
        McTemplateK0pz_EtwWriteTransfer(
          a1: ghsemGreLock_1,
          a2: (unsigned int)LockRelease,
          a3: v10,
          a4: (_DWORD)ghsemDynamicModeChange,
          a5: (__int64)L"ghsemDynamicModeChange");
      if ( ghsemDynamicModeChange != nullptr )
      {
        ExReleaseResourceAndLeaveCriticalRegion(Resource: ghsemDynamicModeChange);
        PsLeavePriorityRegion();
      }
      return 0;
    }
  }
  v76 = *(_QWORD *)(gpDispInfo + 40);
LABEL_136:
  GreUnlockVisRgn(a1: v76);
  return 2;
}
