void __fastcall ProcessHidRawInput(struct DEVICEINFO *a1)
{
  char v2; // [rsp+38h] [rbp+10h] BYREF
  char v3; // [rsp+40h] [rbp+18h] BYREF

  UserAtomicCheck::UserAtomicCheck(this: (UserAtomicCheck *)&v3);
  InputTraceLogging::ThreadLockedPerfRegion::ThreadLockedPerfRegion(
    this: (InputTraceLogging::ThreadLockedPerfRegion *)&v2,
    a2: "RawHidInput",
    a3: nullptr);
  xxxProcessHidInput(a1);
  InputTraceLogging::ThreadLockedPerfRegion::~ThreadLockedPerfRegion(this: (InputTraceLogging::ThreadLockedPerfRegion *)&v2);
  UserAtomicCheck::~UserAtomicCheck(this: (UserAtomicCheck *)&v3);
}
