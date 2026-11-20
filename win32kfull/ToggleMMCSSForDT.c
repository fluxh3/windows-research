void __fastcall ToggleMMCSSForDT()
{
  __int64 CurrentProcess; // rax

  CurrentProcess = PsGetCurrentProcess();
  if ( (unsigned int)IsProcessDwm(a1: CurrentProcess) == 0 )
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  KeSetEvent(Event: Event_0, Increment: 1, Wait: 0);
}
