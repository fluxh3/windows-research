__int64 __fastcall ConnectHwpInterrupt(__int64 a1)
{
  __int64 v1; // rax
  unsigned __int64 v2; // rdx
  __int64 v3; // rcx
  bool v4; // r8
  char v5; // r9
  unsigned __int64 v6; // rax
  char v7; // r10
  unsigned __int64 v8; // rax
  int v9; // ebx
  unsigned __int64 v10; // rax
  unsigned __int64 v12; // [rsp+40h] [rbp+8h]
  unsigned __int64 v13; // [rsp+40h] [rbp+8h]
  unsigned __int64 v14; // [rsp+40h] [rbp+8h]

  v1 = *(_QWORD *)(a1 + 88);
  if ( v1 != 0 && (*(_DWORD *)(v1 + 4) & 0x1000) != 0 )
  {
    IsHwpNativeInterruptSupported();
    HwpNotificationInterruptSupported = -117;
    IsHwpHighestInterruptSupported();
    HwpHighestInterruptSupported = -106;
    v4 = (unsigned __int8)IsHgsInterruptSupported() != 0
      && qword_1C001C6F0 != 0
      && (unsigned __int8)guard_dispatch_icall_nop(a1: v3, a2: v2) != 0;
    v5 = HwpNotificationInterruptSupported;
    HgsInterruptSupported = -53;
    if ( HwpNotificationInterruptSupported != 0 || HwpHighestInterruptSupported != 0 )
    {
      v6 = __readmsr(0x773u);
      v12 = v6;
      if ( v5 != 0 )
      {
        LODWORD(v6) = v6 & 0xFFFFFFFC;
        LODWORD(v12) = v6;
      }
      v7 = HwpHighestInterruptSupported;
      if ( HwpHighestInterruptSupported != 0 )
        LODWORD(v12) = v6 & 0xFFFFFFFB;
      __writemsr(0x773u, v12);
      v8 = __readmsr(0x777u);
      v13 = v8;
      if ( v5 != 0 )
      {
        LODWORD(v8) = v8 & 0xFFFFFFFA;
        LODWORD(v13) = v8;
      }
      if ( v7 != 0 )
        LODWORD(v13) = v8 & 0xFFFFFFF7;
      v2 = HIDWORD(v13);
      __writemsr(0x777u, v13);
    }
    if ( v4 )
    {
      v14 = __readmsr(0x1B2u) & 0xFFFFFFFFFDFFFFFFuLL;
      v2 = HIDWORD(v14);
      __writemsr(0x1B2u, v14);
    }
    v9 = guard_dispatch_icall_nop(a1: HwpInterruptService, a2: v2);
    if ( v9 >= 0 )
    {
      if ( HgsInterruptSupported != 0 )
      {
        v10 = __readmsr(0x1B1u);
        if ( (v10 & 0x4000000) != 0 )
          guard_dispatch_icall_nop(a1: 433, a2: (unsigned __int64)HIDWORD(v10) << 32);
      }
      return 0;
    }
    else if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
    {
      WPP_RECORDER_SF_D(
        a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
        a2: 2u,
        a3: 3u,
        a4: 14,
        a5: (__int64)WPP_839ec2002e32316adf7bb8cd76f5d3dc_Traceguids,
        v9);
    }
  }
  else
  {
    v9 = -1073741637;
    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      WPP_RECORDER_SF_(
        a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
        a2: 4u,
        a3: 3u,
        a4: 13,
        a5: (__int64)WPP_839ec2002e32316adf7bb8cd76f5d3dc_Traceguids);
  }
  return (unsigned int)v9;
}
