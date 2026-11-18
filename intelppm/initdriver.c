__int64 __fastcall InitDriver(__int64 a1, _QWORD *a2)
{
  __int64 v4; // rsi
  char v5; // r14
  __int128 v6; // rt0
  __int64 v7; // rdi
  __int64 v8; // r9
  _BYTE v10[4]; // [rsp+20h] [rbp-30h] BYREF
  int v11; // [rsp+24h] [rbp-2Ch] BYREF
  __int128 v12; // [rsp+28h] [rbp-28h] BYREF
  __int128 v13; // [rsp+38h] [rbp-18h] BYREF

  if ( (unsigned __int8)IsHwpNativeInterruptSupported() == 0 )
    IsHgsInterruptSupported();
  PdcBuffer = -1073499381;
  dword_1C001C244 = -1073499364;
  dword_1C001C248 = -1073499354;
  *(_QWORD *)(a1 + 16) = 0x1C001C240LL;
  v4 = 572522496;
  *(_WORD *)(a1 + 32) = 12;
  v5 = 0;
  dword_1C001C238 = 0;
  *((_QWORD *)&v6 + 1) = *((_QWORD *)&ACPI_OSC_INTEL_GUID + 1);
  *(_QWORD *)&v6 = 0x1C003B356LL;
  OscBuffer = v6;
  dword_1C001C230 = -1073499296;
  dword_1C001C234 = -1073499286;
  dword_1C001C23C = -1073499277;
  *(_QWORD *)(a1 + 24) = 0x1C001C220LL;
  *(_WORD *)(a1 + 34) = 32;
  *(_QWORD *)(a1 + 64) = 0x1C0004160LL;
  *(_QWORD *)(a1 + 72) = 0x1C00019F0LL;
  *(_QWORD *)(a1 + 80) = 0x1C0001560LL;
  *(_QWORD *)(a1 + 88) = 0x1C0007730LL;
  *(_QWORD *)(a1 + 96) = 0x1C0007560LL;
  v13 = 0;
  v12 = 0;
  GetCpuIdInfo(a1: 0, a2: &v13);
  if ( (unsigned int)v13 >= 6 )
  {
    GetCpuIdInfo(a1: 6u, a2: &v12);
    if ( (BYTE8(v12) & 1) != 0 )
    {
      v4 = 639631360;
      *(_QWORD *)(a1 + 120) = 0x1C00013C0LL;
      if ( (unsigned __int8)IsNonwrappingACountMCountSupported() != 0 )
      {
        v5 = 1;
        v4 = 0x8026200000LL;
      }
    }
  }
  v12 = 0;
  GetCpuIdInfo(a1: 1u, a2: &v12);
  if ( (HIDWORD(v12) & 0x400000) != 0 )
    *(_QWORD *)(a1 + 128) = 0x1C0001540LL;
  if ( (unsigned __int8)IsPerformanceEnergyBiasSupported() != 0 )
    *(_QWORD *)(a1 + 136) = 0x1C0001850LL;
  if ( (unsigned __int8)IsTurboModeSupported() != 0 )
  {
    if ( (unsigned __int8)IsPerformanceEnergyBiasSupported() != 0 )
    {
      *(_QWORD *)(a1 + 72) = 0x1C0007590LL;
      *(_QWORD *)(a1 + 112) = 0x1C0001010LL;
      *(_QWORD *)(a1 + 88) = 0x1C0007680LL;
    }
    else
    {
      v5 = 0;
      *(_QWORD *)(a1 + 144) = 0x1C00077A0LL;
    }
  }
  v7 = v4 | 0x400000;
  if ( v5 == 0 )
    v7 = v4;
  v10[0] = IsMonitorMWaitSupported();
  if ( v10[0] != 0 || (GetHvPpmCapabilities(a1: 0, a2: 0, a3: v10), v10[0] != 0) )
  {
    *(_QWORD *)(a1 + 48) = 0x1C0020610LL;
    *(_QWORD *)(a1 + 56) = 0x1C0026160LL;
    v7 |= 0x12000007F000uLL;
  }
  if ( (unsigned __int8)IsHwpSupported() != 0 )
  {
    *(_QWORD *)(a1 + 152) = 0x1C0006D10LL;
    *(_QWORD *)(a1 + 168) = 0x1C00069F0LL;
  }
  if ( (unsigned __int8)IsHwpNativeInterruptSupported() != 0 || (unsigned __int8)IsHgsInterruptSupported() != 0 )
  {
    v7 |= 0x4000000000uLL;
    *(_QWORD *)(a1 + 160) = 0x1C0006760LL;
    *(_QWORD *)(a1 + 176) = 0x1C0006960LL;
  }
  *(_QWORD *)(a1 + 240) = 0;
  *(_DWORD *)(a1 + 216) = 409;
  *(_QWORD *)(a1 + 224) = -65536;
  *(_DWORD *)(a1 + 232) = 410;
  if ( qword_1C001C700 != 0 && qword_1C001C708 != 0 && qword_1C001C710 != 0 && qword_1C001C718 != 0 )
    v7 |= 0x200000000000uLL;
  if ( dword_1C001CC18 == 2 )
  {
    v11 = 0;
    if ( (int)GetRegistryDwordValueNoDefault(
                a1: L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\IntelHswPcc\\Enum",
                a2: L"Count",
                a3: &v11,
                a4: v8) >= 0
      && v11 != 0 )
    {
      *(_QWORD *)(a1 + 104) = 0x1C00073A0LL;
    }
  }
  *(_QWORD *)(a1 + 184) = 0x1C0025D30LL;
  *(_QWORD *)(a1 + 192) = 0x1C002AAC0LL;
  *a2 |= v7;
  return 0;
}
