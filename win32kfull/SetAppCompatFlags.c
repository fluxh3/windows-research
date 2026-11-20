__int64 __fastcall SetAppCompatFlags(_QWORD *p_Thread)
{
  PEPROCESS ThreadProcess; // rax
  __int64 ProcessPeb; // r13
  __int64 v4; // rax
  int v5; // ecx
  unsigned __int16 *v7; // rdx
  int v8; // r14d
  ULONG64 MmUserProbeAddress; // rdx
  int v10; // ecx
  ULONG64 MmUserProbeAddress_3; // r8
  ULONG64 MmUserProbeAddress_2; // rdx
  _BYTE **MmUserProbeAddress_1; // rax
  _WORD *v14; // rbx
  _WORD *v15; // rax
  _WORD *v16; // rcx
  _WORD *v17; // rsi
  unsigned int n162; // ebx
  __int64 n162_2; // r15
  _WORD *v20; // rcx
  size_t n30; // r8
  __int64 ThreadTeb; // rax
  __int64 v23; // rbx
  __int64 v24; // rbx
  __int64 v25; // rax
  __int64 CurrentProcessWin32Process; // rax
  __int64 v27; // rax
  int v28; // eax
  __int64 v29; // rax
  int v30; // edx
  int v31; // r8d
  int v32; // r9d
  int v33; // [rsp+20h] [rbp-218h]
  ULONG Value; // [rsp+40h] [rbp-1F8h] BYREF
  int v35; // [rsp+44h] [rbp-1F4h] BYREF
  int v36; // [rsp+48h] [rbp-1F0h]
  unsigned int n162_1; // [rsp+4Ch] [rbp-1ECh]
  _WORD *v38; // [rsp+50h] [rbp-1E8h]
  _WORD *v39; // [rsp+58h] [rbp-1E0h]
  __int128 v40; // [rsp+60h] [rbp-1D8h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+70h] [rbp-1C8h] BYREF
  UNICODE_STRING DestinationString_; // [rsp+80h] [rbp-1B8h] BYREF
  WCHAR Buffer[96]; // [rsp+A0h] [rbp-198h] BYREF
  WCHAR SourceString[80]; // [rsp+160h] [rbp-D8h] BYREF

  Value = 0;
  DestinationString_ = 0;
  v40 = 0;
  ThreadProcess = PsGetThreadProcess(Thread: (PETHREAD)*p_Thread);
  ProcessPeb = PsGetProcessPeb(a1: ThreadProcess);
  v4 = p_Thread[82];
  if ( v4 != 0 )
  {
    v5 = *(_DWORD *)(v4 + 632);
    *((_DWORD *)p_Thread + 158) = v5;
    p_Thread[80] = *(_QWORD *)(v4 + 640);
    *(_DWORD *)(p_Thread[59] + 20LL) = v5;
    *(_DWORD *)(p_Thread[59] + 24LL) = *((_DWORD *)p_Thread + 160);
    return 0;
  }
  v7 = (unsigned __int16 *)p_Thread[61];
  v8 = 1;
  if ( v7 == nullptr )
  {
    MmUserProbeAddress = *(_QWORD *)(ProcessPeb + 32) + 96LL;
    if ( MmUserProbeAddress >= ::MmUserProbeAddress )
      MmUserProbeAddress = ::MmUserProbeAddress;
    v10 = *(_DWORD *)MmUserProbeAddress;
    v36 = v10;
    LODWORD(v40) = v10;
    MmUserProbeAddress_3 = *(_QWORD *)(MmUserProbeAddress + 8);
    *((_QWORD *)&v40 + 1) = MmUserProbeAddress_3;
    if ( (MmUserProbeAddress_3 & 1) != 0 )
      ExRaiseDatatypeMisalignment();
    MmUserProbeAddress_2 = MmUserProbeAddress_3 + (unsigned __int16)v10 + 2LL;
    MmUserProbeAddress_1 = (_BYTE **)::MmUserProbeAddress;
    if ( MmUserProbeAddress_2 < ::MmUserProbeAddress && (unsigned __int16)v10 <= HIWORD(v36) )
    {
      if ( (v10 & 1) != 0 )
        goto LABEL_13;
      if ( MmUserProbeAddress_2 > MmUserProbeAddress_3 )
      {
LABEL_15:
        v7 = (unsigned __int16 *)&v40;
        goto LABEL_16;
      }
    }
    if ( (v10 & 1) == 0 )
    {
LABEL_14:
      **MmUserProbeAddress_1 = 0;
      goto LABEL_15;
    }
LABEL_13:
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    MmUserProbeAddress_1 = (_BYTE **)::MmUserProbeAddress;
    goto LABEL_14;
  }
LABEL_16:
  v14 = (_WORD *)(*((_QWORD *)v7 + 1) + 2 * ((unsigned __int64)*v7 >> 1));
  v39 = v14;
  v15 = v14;
  v38 = v14;
  while ( 1 )
  {
    v16 = *((_WORD **)v7 + 1);
    if ( v14 == v16 )
      break;
    if ( *v14 == 46 )
      goto LABEL_20;
    v39 = --v14;
  }
  v14 = v15;
  v39 = v15;
LABEL_20:
  v17 = v14;
  v38 = v14;
  while ( v17 != v16 )
  {
    if ( *v17 == 92 || *v17 == 58 )
    {
      v38 = ++v17;
      break;
    }
    v38 = --v17;
  }
  n162 = 2 * (v14 - v17);
  n162_1 = n162;
  if ( n162 >= 0xA4 )
    n162 = 162;
  n162_1 = n162;
  n162_2 = n162;
  memmove(a1: Buffer, Src: v17, Size: n162);
  v20 = (_WORD *)(p_Thread[52] + 992LL);
  if ( *v20 == 0 )
  {
    n30 = 30;
    if ( n162 < 0x1E )
      n30 = n162;
    memmove(a1: v20, Src: v17, Size: n30);
    *(_WORD *)(p_Thread[52] + 1022LL) = 0;
  }
  if ( (*(_DWORD *)(PsGetCurrentProcessWin32Process() + 12) & 0x80u) == 0 )
  {
    v25 = *(_QWORD *)(ProcessPeb + 720);
  }
  else
  {
    ThreadTeb = PsGetThreadTeb(Thread: *p_Thread);
    v23 = ThreadTeb + 0x2000;
    ProbeForRead(Address: (volatile void *)(ThreadTeb + 8240), Length: 4u, Alignment: 4u);
    v24 = *(unsigned int *)(v23 + 48);
    ProbeForRead(Address: (volatile void *)(unsigned int)v24, Length: 0x480u, Alignment: 4u);
    v25 = *(_QWORD *)(v24 + 480);
  }
  p_Thread[80] = v25;
  if ( (v25 & 0x800000000000000LL) != 0 )
  {
    v35 = 0;
    FastGetProfileDwordEx(
      a1: 0,
      n4: 4,
      ForceDisableGDIScaling: (wchar_t *)L"ForceDisableGDIScaling",
      a4: 0,
      n4: 4,
      a6: &v35,
      a7: 0);
    if ( v35 != 0 )
    {
      p_Thread[80] &= ~0x800000000000000uLL;
      CurrentProcessWin32Process = PsGetCurrentProcessWin32Process();
      *(_DWORD *)(CurrentProcessWin32Process + 12) &= ~0x20000000u;
    }
    else
    {
      v27 = PsGetCurrentProcessWin32Process();
      *(_DWORD *)(v27 + 12) |= 0x20000000u;
      TraceLoggingGDIScaledAppEvent();
    }
  }
  *(_DWORD *)(p_Thread[59] + 24LL) = *((_DWORD *)p_Thread + 160);
  if ( (p_Thread[80] & 0x2000000) == 0 && (unsigned int)IsCurrentDesktopComposed() != 0 )
    v8 = 0;
  if ( (*(_DWORD *)(p_Thread[52] + 820LL) & 0x30) == 0x10 )
    *(_QWORD *)p_Thread[59] |= 0x10000000uLL;
  if ( v8 != 0 )
  {
LABEL_48:
    *(_QWORD *)p_Thread[59] |= 0x20000000uLL;
    goto LABEL_51;
  }
  if ( (p_Thread[80] & 0x880000000000000LL) == 0 )
  {
    if ( (*(_DWORD *)(p_Thread[52] + 820LL) & 0x30) != 0x10 )
    {
      if ( (unsigned int)IsImmersiveBroker() != 0 )
        *(_QWORD *)(p_Thread[59] + 224LL) |= 0x80uLL;
      goto LABEL_51;
    }
    goto LABEL_48;
  }
  *(_QWORD *)(p_Thread[59] + 224LL) |= 0x10uLL;
LABEL_51:
  if ( (p_Thread[80] & 0x100000000000000LL) != 0 )
    *(_QWORD *)(p_Thread[59] + 224LL) |= 0x20uLL;
  v28 = *((_DWORD *)p_Thread + 160);
  if ( (v28 & 0x10000000) == 0 && *((_WORD *)p_Thread + 312) < 0x600u )
  {
    *((_DWORD *)p_Thread + 160) = v28 | 0x20000000;
    *(_DWORD *)(p_Thread[59] + 24LL) |= 0x20000000u;
  }
  if ( (n162_2 & 0xFFFFFFFFFFFFFFFEuLL) >= 0xB4 )
    _report_rangecheckfailure();
  *(WCHAR *)((char *)Buffer + (n162_2 & 0xFFFFFFFFFFFFFFFEuLL)) = 0;
  v29 = PsGetCurrentProcessWin32Process();
  if ( (unsigned int)FastGetProfileStringW(
                       a1: 0,
                       a2: (*(_DWORD *)(v29 + 12) & 0x80u) != 0 ? 43 : 33,
                       Buffer,
                       a4: 0,
                       SourceString,
                       n80: 80,
                       a7: 0) != 0 )
  {
    DestinationString = 0;
    RtlInitUnicodeString(&DestinationString, SourceString);
    RtlUnicodeStringToInteger(String: &DestinationString, Base: 0, &Value);
  }
  if ( *(unsigned int **)&WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED )
    WPP_RECORDER_SF_DS(
      p_WPP_RECORDER_INITIALIZED: (unsigned int)&WPP_RECORDER_INITIALIZED,
      a2: v30,
      a3: v31,
      a4: v32,
      a5: v33,
      Value,
      Buffer);
  *(_DWORD *)(p_Thread[59] + 20LL) = Value;
  *((_DWORD *)p_Thread + 158) = Value;
  *(WCHAR *)((char *)Buffer + (n162_2 & 0xFFFFFFFFFFFFFFFEuLL)) = 0;
  RtlInitUnicodeString(DestinationString: &DestinationString_, SourceString: Buffer);
  return SetAppImeCompatFlags(p_Thread, DestinationString: &DestinationString_);
}
