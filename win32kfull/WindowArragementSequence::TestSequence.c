void __fastcall WindowArrangementSequence::TestSequence(
        WindowArrangementSequence *this,
        const struct tagHOTKEY *const a2,
        int n8,
        unsigned __int16 a4,
        unsigned int a5)
{
  int `?fWindowArrangementSequenceInProgress@WindowArrangementSequence`; // eax
  bool v6; // zf
  __int64 n2; // r8

  if ( this != nullptr )
  {
    if ( (((unsigned __int16)a2 << 16) | a4) == qword_1C033BAB0 )
      return;
    `?fWindowArrangementSequenceInProgress@WindowArrangementSequence` = *(_QWORD *)this == gptiRit
                                                                     && (unsigned int)(*((_DWORD *)this + 8) - 16) <= 0xD;
    if ( WindowArrangementSequence::fWindowArrangementSequenceInProgress == `?fWindowArrangementSequenceInProgress@WindowArrangementSequence` )
      return;
    WindowArrangementSequence::fWindowArrangementSequenceInProgress = `?fWindowArrangementSequenceInProgress@WindowArrangementSequence`;
    v6 = `?fWindowArrangementSequenceInProgress@WindowArrangementSequence` == 0;
    goto LABEL_19;
  }
  if ( a5 != 0 )
  {
    if ( n8 == 0 )
    {
      if ( WindowArrangementSequence::fWindowArrangementSequenceInProgress == 0 )
        return;
LABEL_20:
      n2 = 1;
      goto LABEL_21;
    }
    if ( WindowArrangementSequence::fWindowArrangementSequenceInProgress == 0 )
      return;
    v6 = (n8 & 0xE) == 0;
LABEL_19:
    if ( !v6 )
      return;
    goto LABEL_20;
  }
  if ( n8 == 8 && WindowArrangementSequence::fWindowArrangementSequenceInProgress != 0 )
  {
    n2 = 2;
LABEL_21:
    `anonymous namespace'::NotifyShellSimplePayload(a1: 0, a2: 3, a3: n2, a4: 8);
    WindowArrangementSequence::fWindowArrangementSequenceInProgress = 0;
  }
}
