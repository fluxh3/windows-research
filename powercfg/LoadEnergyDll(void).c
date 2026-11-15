__int64 __fastcall LoadEnergyDll()
{
  unsigned int v0; // ebx
  HMODULE Library; // rax
  FARPROC ProcAddress; // rax
  FARPROC v3; // rax
  FARPROC v4; // rax
  FARPROC v5; // rax
  FARPROC v6; // rax
  FARPROC v7; // rax
  FARPROC v8; // rax
  FARPROC v9; // rax
  FARPROC v10; // rax
  FARPROC v11; // rax
  FARPROC v12; // rax
  FARPROC v13; // rax
  FARPROC v14; // rax
  FARPROC v15; // rax
  FARPROC v16; // rax

  v0 = 0xC0040105;
  Library = LoadLibraryExW(lpLibFileName: L"energy", hFile: nullptr, dwFlags: 0);
  EnergyDll = (HINSTANCE)&loc_14000B74A;
  if ( Library == nullptr )
    goto LABEL_18;
  ProcAddress = GetProcAddress(hModule: Library, lpProcName: "EnergyWizard_CreateEnergyWizard");
  PCreateEnergyWizard = (void *(*)())&loc_14000B770;
  if ( ProcAddress == nullptr )
    goto LABEL_18;
  v3 = GetProcAddress(hModule: EnergyDll, lpProcName: "EnergyWizard_DestroyEnergyWizard");
  PDestroyEnergyWizard = (void (*)(void *))&loc_14000B79A;
  if ( v3 == nullptr )
    goto LABEL_18;
  v4 = GetProcAddress(hModule: EnergyDll, lpProcName: "EnergyWizard_DefaultTraceDuration");
  PDefaultTraceDuration = (int (*)(void *, unsigned int *))&loc_14000B7C4;
  if ( v4 == nullptr )
    goto LABEL_18;
  v5 = GetProcAddress(hModule: EnergyDll, lpProcName: "EnergyWizard_CollectTrace");
  PCollectTrace = (int (*)(void *, const unsigned __int16 *, unsigned int))&loc_14000B7EE;
  if ( v5 == nullptr )
    goto LABEL_18;
  v6 = GetProcAddress(hModule: EnergyDll, lpProcName: "EnergyWizard_CancelTrace");
  PCancelTrace = (int (*)(void *))&loc_14000B818;
  if ( v6 == nullptr )
    goto LABEL_18;
  v7 = GetProcAddress(hModule: EnergyDll, lpProcName: "EnergyWizard_Analyze");
  PAnalyze = (int (*)(void *, const unsigned __int16 *, const unsigned __int16 *))&loc_14000B842;
  if ( v7 == nullptr )
    goto LABEL_18;
  v8 = GetProcAddress(hModule: EnergyDll, lpProcName: "EnergyWizard_SaveReport");
  PSaveReport = (int (*)(void *, const unsigned __int16 *))&loc_14000B86C;
  if ( v8 == nullptr )
    goto LABEL_18;
  v9 = GetProcAddress(hModule: EnergyDll, lpProcName: "EnergyWizard_GetLogEntryCounts");
  PGetLogEntryCounts = (int (*)(void *, unsigned int *, unsigned int *, unsigned int *))&loc_14000B896;
  if ( v9 == nullptr )
    goto LABEL_18;
  v10 = GetProcAddress(hModule: EnergyDll, lpProcName: "EnergyWizard_SqmAnalysis");
  PTelemetryAnalysis = (int (*)(void *, int))&loc_14000B8C0;
  if ( v10 == nullptr )
    goto LABEL_18;
  v11 = GetProcAddress(hModule: EnergyDll, lpProcName: "EnergyWizard_TransformReport");
  PTransformReport = (int (*)(void *, const unsigned __int16 *, const unsigned __int16 *))&loc_14000B8EA;
  if ( v11 == nullptr )
    goto LABEL_18;
  v12 = GetProcAddress(hModule: EnergyDll, lpProcName: "SaveBatteryReport");
  PSaveBatteryReport = (int (*)(const unsigned __int16 *, unsigned int))&loc_14000B914;
  if ( v12 == nullptr )
    goto LABEL_18;
  v13 = GetProcAddress(hModule: EnergyDll, lpProcName: "TransformBatteryReport");
  PTransformBatteryReport = (int (*)(const unsigned __int16 *, const unsigned __int16 *))&loc_14000B93E;
  if ( v13 == nullptr )
    goto LABEL_18;
  v14 = GetProcAddress(hModule: EnergyDll, lpProcName: "SaveSleepStudyReport");
  PSaveSleepStudyReport = (int (*)(const unsigned __int16 *, const unsigned __int16 *, unsigned int, unsigned __int8, enum _SLEEPSTUDY_TELEMETRY_TYPE, unsigned __int8 *))&loc_14000B964;
  if ( v14 != nullptr
    && (v15 = GetProcAddress(hModule: EnergyDll, lpProcName: "TransformSleepStudyReport"),
        PTransformSleepStudyReport = (int (*)(const unsigned __int16 *, const unsigned __int16 *))&loc_14000B98A,
        v15 != nullptr)
    && (v16 = GetProcAddress(hModule: EnergyDll, lpProcName: "CreateProvisioningXml"),
        PCreateProvisioningXml = (unsigned int (*)(const unsigned __int16 *, const unsigned __int16 *, const unsigned __int16 *, const unsigned __int16 *, const unsigned __int16 *))&loc_14000B9B0,
        v16 != nullptr) )
  {
    return 0;
  }
  else
  {
LABEL_18:
    UnloadEnergyDll();
  }
  return v0;
}
