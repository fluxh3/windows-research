void __fastcall DisplayDiagnosticContext(const struct _ADAPTIVE_STANDBY_DIAGNOSTIC_CONTEXT *a1)
{
  const struct _ADAPTIVE_STANDBY_BUDGET_DECISION_SUMMARY *v2; // rdx
  const struct _ADAPTIVE_STANDBY_BUDGET_DECISION_DATA *v3; // rcx

  PowercfgPrint(a1: 0, a2: L"General Information\n");
  swprintf_s(
    Buffer: (wchar_t *const)g_lpszBuf,
    BufferCount: 0x204u,
    Format: L"\t- Battery: %d%%.\n",
    *((unsigned int *)a1 + 1));
  PowercfgPrint(a1: 0, a2: g_lpszBuf);
  swprintf_s(
    Buffer: (wchar_t *const)g_lpszBuf,
    BufferCount: 0x204u,
    Format: L"\t- Battery Full Charge Capacity: %d mWh.\n",
    *((unsigned int *)a1 + 2));
  PowercfgPrint(a1: 0, a2: g_lpszBuf);
  PowercfgPrint(a1: 0, a2: L"Power Settings Context\n");
  swprintf_s(
    Buffer: (wchar_t *const)g_lpszBuf,
    BufferCount: 0x204u,
    Format: L"\t- Hibernate Timeout: %d seconds.\n",
    *((unsigned int *)a1 + 3));
  PowercfgPrint(a1: 0, a2: g_lpszBuf);
  swprintf_s(
    Buffer: (wchar_t *const)g_lpszBuf,
    BufferCount: 0x204u,
    Format: L"\t- Low Battery Level: %d%%.\n",
    *((unsigned int *)a1 + 4));
  PowercfgPrint(a1: 0, a2: g_lpszBuf);
  if ( *(_DWORD *)a1 != 0 )
  {
    if ( *(_DWORD *)a1 == 1 )
    {
      DisplayStandbyBudgetDiagnosticContext(
        a1: v3,
        a2: v2,
        a3: (const struct _ADAPTIVE_STANDBY_DIAGNOSTIC_CONTEXT *)((char *)a1 + 84));
    }
    else
    {
      swprintf_s(Buffer: (wchar_t *const)g_lpszBuf, BufferCount: 0x204u, Format: L"INVALID ADAPTIVE STANDBY ACTION.\n");
      PowercfgPrint(a1: 0, a2: g_lpszBuf);
    }
  }
  else
  {
    DisplayBatteryReserveDiagnosticContext(
      a1: (const struct _ADAPTIVE_STANDBY_DIAGNOSTIC_CONTEXT *)((char *)a1 + 32),
      a2: (const struct _ADAPTIVE_STANDBY_DIAGNOSTIC_CONTEXT *)((char *)a1 + 160),
      a3: (const struct _ADAPTIVE_STANDBY_DIAGNOSTIC_CONTEXT *)((char *)a1 + 184));
  }
}
