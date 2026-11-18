__int64 __fastcall DisplayKernelPerfStates(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // rax
  int v5; // [rsp+20h] [rbp-18h]
  __int64 v6; // [rsp+28h] [rbp-10h]

  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    if ( *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
    {
      HIDWORD(v6) = HIDWORD(a1);
      result = WPP_RECORDER_SF_q(a1: *((_QWORD *)WPP_GLOBAL_Control + 8), a2, a3, a4: 93, a5: v5);
    }
    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
    {
      if ( *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
      {
        LODWORD(v6) = *(unsigned __int16 *)(a1 + 4);
        result = WPP_RECORDER_SF_D(
                   a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                   a2: 5u,
                   a3: 2u,
                   a4: 94,
                   a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                   v6);
      }
      if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      {
        if ( *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
        {
          LODWORD(v6) = *(_DWORD *)(a1 + 16);
          result = WPP_RECORDER_SF_D(
                     a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                     a2: 5u,
                     a3: 2u,
                     a4: 95,
                     a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                     v6);
        }
        if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        {
          if ( *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
          {
            LODWORD(v6) = *(_DWORD *)(a1 + 20);
            result = WPP_RECORDER_SF_D(
                       a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                       a2: 5u,
                       a3: 2u,
                       a4: 96,
                       a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                       v6);
          }
          if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED
            && *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
          {
            return WPP_RECORDER_SF_(
                     a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                     a2: 5u,
                     a3: 2u,
                     a4: 97,
                     a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids);
          }
        }
      }
    }
  }
  return result;
}
