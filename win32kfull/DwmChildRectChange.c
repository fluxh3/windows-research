LONG_PTR __fastcall DwmChildRectChange(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // r10
  INT v4; // r15d
  __m128i v6; // xmm2
  int v7; // ebx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int n96; // eax
  int v11; // edi
  __int32 v12; // ebx
  int v13; // r11d
  int v14; // r14d
  int v15; // ecx
  __int32 v16; // r9d
  int v17; // ecx
  __int32 v18; // r8d
  int v19; // edx
  int v20; // eax
  int v21; // ebx
  struct _KTHREAD *CurrentThread; // rdi
  __m128i v23; // xmm1
  _QWORD *ThreadWin32Thread; // rax
  struct _KTHREAD *v25; // r14
  __int64 v26; // rdi
  __int64 *v27; // rax
  struct _KTHREAD *v28; // r14
  __int64 v29; // rdi
  __int64 *v30; // rax
  __int64 v31; // rcx
  int v32; // eax
  __int64 v33; // rdi
  LONG_PTR Object_1; // rax
  void *Object; // rbx
  __int64 v36; // rax
  __int64 v37; // rax
  int v38; // ebx
  __int64 v39; // rax
  __int64 CurrentProcess; // rax
  int ProcessSessionId; // ebx
  __int64 CurrentThreadProcess; // rax
  __int64 v43; // rax
  int v44; // ebx
  __int64 v45; // rax
  unsigned __int16 ScaledLogPixels; // ax
  INT ScaledLogPixels_1; // edi
  __m128i v48; // [rsp+30h] [rbp-D0h]
  __m128i v49; // [rsp+30h] [rbp-D0h]
  __int128 v50; // [rsp+48h] [rbp-B8h] BYREF
  __m128i v51; // [rsp+58h] [rbp-A8h] BYREF
  __m128i v52; // [rsp+68h] [rbp-98h] BYREF
  __m128i v53; // [rsp+80h] [rbp-80h] BYREF
  _DWORD v54[28]; // [rsp+90h] [rbp-70h] BYREF

  v3 = a1[5];
  v4 = 0;
  v6 = *(__m128i *)(v3 + 88);
  v7 = _mm_cvtsi128_si32(v6);
  v48 = v6;
  v8 = *(_QWORD *)(v3 + 96);
  if ( v7 < v8 && v6.m128i_i32[1] < _mm_srli_si128(v6, 8).m128i_i32[1] )
  {
    v9 = *(_DWORD *)(v3 + 288);
    v50 = 0;
    if ( (v9 & 0xF) == 3 )
    {
      n96 = (v9 >> 8) & 0x1FF;
    }
    else if ( (*(_DWORD *)(v3 + 232) & 0x8000000) != 0 )
    {
      n96 = GetWindowDpiLastNotify(a1);
    }
    else if ( (v9 & 0xF) == 0
           && (v36 = *(_QWORD *)(a1[2] + 448)) != 0
           && (*(_DWORD *)(**(_QWORD **)(v36 + 8) + 64LL) & 1) != 0 )
    {
      n96 = 96;
    }
    else
    {
      n96 = *(unsigned __int16 *)(*(_QWORD *)(a1[2] + 416) + 284LL);
    }
    AdjustWindowRectExForDpi(a1: &v50, a2: *(_DWORD *)(v3 + 28), a3, a4: *(_DWORD *)(v3 + 24), n96);
    v3 = a1[5];
    v4 = DWORD2(v50);
    v11 = v8 - DWORD2(v50);
    v12 = v7 - v50;
    v13 = v48.m128i_i32[1] - DWORD1(v50);
    v14 = v48.m128i_i32[3] - HIDWORD(v50);
    v15 = *(_DWORD *)(v3 + 104);
    if ( v15 < *(_DWORD *)(v3 + 112) && *(_DWORD *)(v3 + 108) < *(_DWORD *)(v3 + 116) )
    {
      if ( v12 >= v15 )
        v12 = *(_DWORD *)(v3 + 104);
      if ( v13 >= *(_DWORD *)(v3 + 108) )
        v13 = *(_DWORD *)(v3 + 108);
      if ( v11 <= *(_DWORD *)(v3 + 112) )
        v11 = *(_DWORD *)(v3 + 112);
      if ( v14 <= *(_DWORD *)(v3 + 116) )
        v14 = *(_DWORD *)(v3 + 116);
    }
    v16 = *(_DWORD *)(v3 + 88);
    v17 = *(_DWORD *)(v3 + 96);
    v18 = v17;
    v19 = *(_DWORD *)(v3 + 92);
    if ( v12 <= v16 )
      v12 = *(_DWORD *)(v3 + 88);
    v20 = *(_DWORD *)(v3 + 100);
    if ( v12 < v17 )
      v18 = v12;
    v21 = *(_DWORD *)(v3 + 100);
    v49.m128i_i32[0] = v18;
    if ( v13 <= v19 )
      v13 = *(_DWORD *)(v3 + 92);
    if ( v13 < v20 )
      v21 = v13;
    v49.m128i_i32[1] = v21;
    if ( v11 >= v17 )
      v11 = *(_DWORD *)(v3 + 96);
    if ( v11 > v16 )
      v16 = v11;
    if ( v14 >= v20 )
      v14 = *(_DWORD *)(v3 + 100);
    if ( v14 > v19 )
      v19 = v14;
    v49.m128i_i32[3] = v19;
    if ( v18 > v16 )
      v16 = v18;
    v49.m128i_i32[2] = v16;
    if ( v21 > v19 )
      v49.m128i_i32[3] = v21;
    v6 = v49;
  }
  CurrentThread = KeGetCurrentThread();
  v23 = *(__m128i *)(v3 + 104);
  v51 = *(__m128i *)(v3 + 88);
  v52 = v23;
  v53 = v6;
  if ( (unsigned __int8)KeIsAttachedProcess() == 0
    || (v37 = PsGetCurrentProcess(),
        v38 = PsGetProcessSessionIdEx(a1: v37),
        v39 = PsGetCurrentThreadProcess(),
        v38 == (unsigned int)PsGetProcessSessionIdEx(a1: v39)) )
  {
    ThreadWin32Thread = (_QWORD *)PsGetThreadWin32Thread(a1: CurrentThread);
    if ( ThreadWin32Thread != nullptr && *ThreadWin32Thread != 0 )
    {
      v25 = KeGetCurrentThread();
      v26 = 0;
      if ( (unsigned __int8)KeIsAttachedProcess() == 0
        || (CurrentProcess = PsGetCurrentProcess(),
            ProcessSessionId = PsGetProcessSessionIdEx(a1: CurrentProcess),
            CurrentThreadProcess = PsGetCurrentThreadProcess(),
            ProcessSessionId == (unsigned int)PsGetProcessSessionIdEx(a1: CurrentThreadProcess)) )
      {
        v27 = (__int64 *)PsGetThreadWin32Thread(a1: v25);
        if ( v27 != nullptr )
          v26 = *v27;
      }
      if ( *(_QWORD *)(v26 + 448) != 0 )
      {
        v28 = KeGetCurrentThread();
        v29 = 0;
        if ( (unsigned __int8)KeIsAttachedProcess() == 0
          || (v43 = PsGetCurrentProcess(),
              v44 = PsGetProcessSessionIdEx(a1: v43),
              v45 = PsGetCurrentThreadProcess(),
              v44 == (unsigned int)PsGetProcessSessionIdEx(a1: v45)) )
        {
          v30 = (__int64 *)PsGetThreadWin32Thread(a1: v28);
          if ( v30 != nullptr )
            v29 = *v30;
        }
        if ( (*(_DWORD *)(**(_QWORD **)(*(_QWORD *)(v29 + 448) + 8LL) + 64LL) & 1) != 0 )
        {
          v31 = a1[5];
          v32 = *(_DWORD *)(v31 + 288);
          if ( (v32 & 0xF) == 0 && (v32 & 0x40000000) != 0 && *(_WORD *)(v31 + 284) != 96 )
          {
            ScaledLogPixels = GreGetScaledLogPixels();
            ScaledLogPixels_1 = ScaledLogPixels;
            ScaleDPIRect(a1: &v51, a2: &v51, b: ScaledLogPixels, c: 0x60u, a5: 0, a6: 0);
            ScaleDPIRect(a1: &v52, a2: &v52, b: ScaledLogPixels_1, c: 0x60u, a5: 0, a6: 0);
            ScaleDPIRect(a1: &v53, a2: &v53, b: ScaledLogPixels_1, c: 0x60u, a5: 0, a6: 0);
            v4 = EngMulDiv(a: v4, b: ScaledLogPixels_1, c: 96);
          }
        }
      }
    }
  }
  DirtyVisRgnTrackers(a1);
  v33 = *a1;
  Object_1 = ReferenceDwmApiPort();
  Object = (void *)Object_1;
  _InterlockedIncrement64(&g_cDWMWindowUniqueness);
  if ( Object_1 != 0 )
  {
    memset(a1: v54, Val: 0, Size: 0x68u);
    v54[0] = 6815808;
    *(__m128i *)&v54[13] = v51;
    LOWORD(v54[1]) = 0x8000;
    *(__m128i *)&v54[21] = v53;
    v54[10] = 1073741845;
    *(_QWORD *)&v54[11] = v33;
    *(__m128i *)&v54[17] = v52;
    v54[25] = v4;
    EtwUpdateEvent(a1: v33);
    LpcRequestPort(a1: Object, a2: v54);
    return ObfDereferenceObject(Object);
  }
  return Object_1;
}
