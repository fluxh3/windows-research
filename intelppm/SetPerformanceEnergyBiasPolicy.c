__int64 __fastcall SetPerformanceEnergyBiasPolicy(__int64 a1, int a2)
{
  unsigned __int64 v2; // rax
  __int64 result; // rax

  if ( *(_DWORD *)(*(_QWORD *)a1 + 80LL) != 0 )
    return guard_dispatch_icall_nop(a1: *(unsigned int *)(*(_QWORD *)a1 + 84LL), a2: 432);
  v2 = __readmsr(0x1B0u);
  result = ((unsigned __int8)((1500 - 15 * a2) / 0x64u) ^ (unsigned __int8)v2) & 0xF ^ v2;
  __writemsr(0x1B0u, result);
  return result;
}
