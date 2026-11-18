_DWORD *ActivateFixedFunctionCounters()
{
  _DWORD *result; // rax

  __writemsr(0x38Du, 0);
  __writemsr(0x309u, 0);
  __writemsr(0x30Au, 0);
  __writemsr(0x30Bu, 0);
  __writemsr(0x38Du, 0x333u);
  __writemsr(0x38Fu, __readmsr(0x38Fu) | 0x700000000LL);
  result = *(_DWORD **)(*(_QWORD *)(DevExts + 8LL * KeGetPcr()->Prcb.Number) + 360LL);
  *result = 3;
  return result;
}
