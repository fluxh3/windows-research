__int64 SetKeyboardRate()
{
  unsigned int v0; // r9d

  v0 = ((unsigned int)gnKeyboardSpeed >> 5) & 3;
  gktp[1] = gKeyboardInfo[9] + (gnKeyboardSpeed & 0x1F) * (gKeyboardInfo[12] - (unsigned int)gKeyboardInfo[9]) / 0x1F;
  gktp[2] = gKeyboardInfo[10] + v0 * (gKeyboardInfo[13] - gKeyboardInfo[10]) / 3;
  gdwUpdateKeyboard |= 1u;
  return gdwUpdateKeyboard;
}
