BOOL __stdcall SetThreadPriority(HANDLE hThread, int nPriority)
{
  CInputThread *`?gpInputThread@@3PEAVCInputThread@@EA`; // rbx
  __int64 v3; // rcx
  BOOL result; // eax

  `?gpInputThread@@3PEAVCInputThread@@EA` = gpInputThread;
  RIMLockExclusive(a1: gpInputThread);
  if ( *((_DWORD *)`?gpInputThread@@3PEAVCInputThread@@EA` + 4) == 1 )
  {
    if ( CInputThread::_CalledOnInputThread(this: `?gpInputThread@@3PEAVCInputThread@@EA`) )
      MicrosoftTelemetryAssertTriggeredNoArgsKM(a1: v3);
    SetThreadBasePriority(Thread: **((PETHREAD **)`?gpInputThread@@3PEAVCInputThread@@EA` + 3));
  }
  *((_QWORD *)`?gpInputThread@@3PEAVCInputThread@@EA` + 1) = 0;
  ExReleasePushLockExclusiveEx(a1: `?gpInputThread@@3PEAVCInputThread@@EA`, a2: 0);
  KeLeaveCriticalRegion();
  return result;
}
