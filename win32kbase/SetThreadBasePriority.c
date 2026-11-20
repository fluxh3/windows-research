NTSTATUS __fastcall SetThreadBasePriority(PETHREAD Thread, int a2)
{
  __m128i SystemInformation_1; // [rsp+20h] [rbp-38h]
  __m128i SystemInformation; // [rsp+30h] [rbp-28h] BYREF
  int v7; // [rsp+40h] [rbp-18h]
  int v8; // [rsp+44h] [rbp-14h]

  v8 = 0;
  SystemInformation_1.m128i_i64[0] = (__int64)PsGetThreadProcessId(Thread);
  v7 = a2;
  SystemInformation_1.m128i_i64[1] = (__int64)PsGetThreadId(Thread);
  SystemInformation = SystemInformation_1;
  return ZwSetSystemInformation(
           SystemInformationClass: SystemThreadPriorityClientIdInformation,
           &SystemInformation,
           SystemInformationLength: 0x18u);
}
