__int64 __fastcall DwmpCalculateColorizationColor(unsigned __int8 *a1, int *a2)
{
  float v4; // xmm6_4
  float v5; // xmm13_4
  float v6; // xmm9_4
  float v7; // xmm0_4
  float v8; // xmm11_4
  float v9; // xmm10_4
  int v10; // ebx
  int v11; // ebx
  int v12; // ebx

  v4 = (float)*((unsigned int *)a1 + 3) / 100.0;
  v5 = (float)*((unsigned int *)a1 + 2) / 100.0;
  v6 = (float)a1[1] / 255.0;
  v7 = (float)a1[2] / 255.0;
  v8 = (float)*a1 / 255.0;
  v9 = (float)((float)((float)((float)(v6 * 0.7152f) + (float)(v7 * 0.2126f)) + (float)(v8 * 0.0722f)) * v4) * v5;
  v10 = (unsigned __int8)(int)floorf_0(
                                X: (float)((float)((float)((float)((float)a1[6] / 255.0) * v9) + (float)(v7 * v5)) * 255.0)
                              + 0.5);
  v11 = (((unsigned __int8)(int)floorf_0(
                                  X: (float)(fmaxf(
                                            (float)(1.0 - v4) - (float)((float)*((unsigned int *)a1 + 4) / 100.0),
                                            0.0)
                                        * 255.0)
                                + 0.5) << 8)
       | v10) << 8;
  v12 = ((unsigned __int8)(int)floorf_0(
                                 X: (float)((float)((float)((float)((float)a1[5] / 255.0) * v9) + (float)(v6 * v5)) * 255.0)
                               + 0.5)
       | v11) << 8;
  *a2 = (unsigned __int8)(int)floorf_0(
                                X: (float)((float)((float)((float)((float)a1[4] / 255.0) * v9) + (float)(v8 * v5)) * 255.0)
                              + 0.5)
      | v12;
  return 0;
}
