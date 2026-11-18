__int64 __fastcall QueryPepCapabilites(__int64 a1)
{
  __int64 v2; // rdx
  int VetoList; // edi
  int v4; // edx
  __int64 v6; // rcx
  int v7; // edx
  __int64 v8; // rax
  int v9; // ecx
  int v10; // [rsp+30h] [rbp-18h] BYREF
  int v11; // [rsp+34h] [rbp-14h] BYREF
  char v12; // [rsp+80h] [rbp+38h] BYREF
  char v13; // [rsp+88h] [rbp+40h] BYREF
  char v14; // [rsp+90h] [rbp+48h] BYREF
  int v15; // [rsp+98h] [rbp+50h] BYREF

  v2 = *(_QWORD *)(a1 + 208);
  VetoList = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  guard_dispatch_icall_nop(a1: WdfDriverGlobals, a2: v2);
  guard_dispatch_icall_nop(a1: WdfDriverGlobals, a2: qword_1C001C418);
  if ( PepPlatformStatesQueried == 0 )
  {
    if ( (*(_QWORD *)(a1 + 272) & 0x300000300LL) != 0 )
    {
      v6 = *(_QWORD *)(a1 + 1104);
      v15 = 0;
      if ( (int)PoFxProcessorNotification(a1: v6, a2: 16, a3: &v15) >= 0 )
        dword_1C001C9AC = -1073580465;
      ProcLibTraceGetPlatformIdleStates(a1: 0);
    }
    PepPlatformStatesQueried = 106;
    VetoList = PepQueryVetoList(a1);
  }
  guard_dispatch_icall_nop(a1: WdfDriverGlobals, a2: qword_1C001C418);
  if ( VetoList < 0 )
  {
    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
    {
      LOBYTE(v4) = 3;
      WPP_RECORDER_SF_D(a1: *((_QWORD *)WPP_GLOBAL_Control + 8), a2: v4, a3: 3, a4: 11, a5: 0x1C0012D80LL, a6: VetoList);
    }
  }
  else
  {
    if ( (*(_QWORD *)(a1 + 272) & 0x100000000000LL) != 0 )
      PepNotifyProcessorLpiStates(a1);
    VetoList = PepNotifyQueryCapabilities(
                 a1,
                 a2: (unsigned int)&v11,
                 a3: (unsigned int)&v14,
                 a4: (unsigned int)&v10,
                 a5: (__int64)&v13,
                 a6: (__int64)&v12);
    if ( VetoList >= 0 )
    {
      *(_BYTE *)(a1 + 1122) = v12;
      *(_BYTE *)(a1 + 1121) = v13;
      *(_DWORD *)(a1 + 1112) = v10;
      *(_DWORD *)(a1 + 1116) = v11;
      *(_BYTE *)(a1 + 1120) = v14;
      ProcLibTraceQueryCapabilities(a1, a2: 0);
      v8 = *(_QWORD *)(a1 + 272);
      v9 = *(_DWORD *)(a1 + 1116);
      if ( (v8 & 0x100000000000LL) != 0 )
      {
        if ( v9 != 0 )
        {
          if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
          {
            LOBYTE(v7) = 2;
            WPP_RECORDER_SF_(a1: *((_QWORD *)WPP_GLOBAL_Control + 8), a2: v7, a3: 1, a4: 12, a5: 0x1C0012D80LL);
          }
          *(_DWORD *)(a1 + 1116) = 0;
        }
      }
      else if ( v9 == 0 )
      {
        if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        {
          LOBYTE(v7) = 4;
          WPP_RECORDER_SF_(a1: *((_QWORD *)WPP_GLOBAL_Control + 8), a2: v7, a3: 2, a4: 13, a5: 0x1C0012D80LL);
          v8 = *(_QWORD *)(a1 + 272);
        }
        *(_QWORD *)(a1 + 272) = v8 & 0xFFFFFFFCFFFFFCFFuLL;
      }
      if ( *(_BYTE *)(a1 + 1121) == 0 && *(_DWORD *)(a1 + 1112) == 0 )
      {
        if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        {
          LOBYTE(v7) = 4;
          WPP_RECORDER_SF_(a1: *((_QWORD *)WPP_GLOBAL_Control + 8), a2: v7, a3: 2, a4: 14, a5: 0x1C0012D80LL);
        }
        *(_QWORD *)(a1 + 272) &= ~0x1000000000uLL;
      }
    }
  }
  guard_dispatch_icall_nop(a1: WdfDriverGlobals, a2: *(_QWORD *)(a1 + 208));
  return (unsigned int)VetoList;
}
