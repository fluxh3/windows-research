__int64 ThreadUnlockWorker1()
{
  struct _KTHREAD *CurrentThread; // rsi
  __int64 v1; // rdi
  __int64 *ThreadWin32Thread; // rax
  _QWORD *v3; // rcx
  __int64 v4; // rbx
  struct _HANDLEENTRY *v5; // rdi
  char v6; // al
  __int64 CurrentProcess; // rax
  int ProcessSessionId; // ebx
  __int64 CurrentThreadProcess; // rax
  char *v11; // rcx

  CurrentThread = KeGetCurrentThread();
  v1 = 0;
  if ( (unsigned __int8)KeIsAttachedProcess() == 0
    || (CurrentProcess = PsGetCurrentProcess(),
        ProcessSessionId = PsGetProcessSessionIdEx(a1: CurrentProcess),
        CurrentThreadProcess = PsGetCurrentThreadProcess(),
        ProcessSessionId == (unsigned int)PsGetProcessSessionIdEx(a1: CurrentThreadProcess)) )
  {
    ThreadWin32Thread = (__int64 *)PsGetThreadWin32Thread(a1: CurrentThread);
    if ( ThreadWin32Thread != nullptr )
      v1 = *ThreadWin32Thread;
  }
  v3 = *(_QWORD **)(v1 + 408);
  *(_QWORD *)(v1 + 408) = *v3;
  v4 = v3[1];
  if ( v4 != 0 && _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 8), 0xFFFFFFFF) == 1 )
  {
    v5 = (struct _HANDLEENTRY *)((char *)qword_1C024AD48
                               + dword_1C024AD50 * (unsigned int)(unsigned __int16)*(_DWORD *)v4);
    v6 = *((_BYTE *)v5 + 25);
    if ( (v6 & 1) != 0 && (v6 & 2) == 0 )
    {
      if ( (unsigned int)IS_USERCRIT_OWNED_SHAREDONLY() != 0 || (unsigned int)IS_USERCRIT_NOTOWNED_ATALL() != 0 )
      {
        GetDomainLockRef(a1: (DomainLockType)12);
        v11 = (char *)gpKernelHandleTable + 24 * (unsigned __int16)*(_DWORD *)v4;
        if ( *((_QWORD *)v11 + 2) == 0 )
        {
          _InterlockedIncrement((volatile signed __int32 *)(v4 + 8));
          AddToDeferredUserCritThreadUnlockList(a1: v11);
        }
      }
      else
      {
        HMDestroyUnlockedObjectWorker(a1: v5);
      }
      return 0;
    }
  }
  return v4;
}
