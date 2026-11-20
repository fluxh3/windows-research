__int64 __fastcall xxxCheckFullScreen(tagWND *a1, struct tagSIZERECT *a2)
{
  unsigned int v2; // r14d
  __int64 v5; // rdx
  __int64 v6; // r12
  struct _KTHREAD *CurrentThread; // r13
  __int64 v8; // r15
  __int64 *ThreadWin32Thread; // rax
  unsigned int WindowCompositedDpiContext; // eax
  tagRECT v11; // xmm6
  __int64 top_2; // rdx
  unsigned int DpiDependentMetric_2; // r8d
  unsigned int v14; // eax
  __int64 top; // rdx
  __int64 left; // rcx
  __int64 DpiDependentMetric_1; // r8
  tagRECT *MonitorRectForWindow; // rax
  __int64 v20; // rdx
  __int64 v21; // rdx
  int n3; // ecx
  unsigned int WindowDpiLastNotify; // eax
  unsigned int DpiDependentMetric; // eax
  int WindowBordersWithDpiAwareness; // eax
  LONG bottom; // edx
  __int64 CurrentProcess; // rax
  int ProcessSessionId; // ebx
  __int64 CurrentThreadProcess; // rax
  __int64 v30; // rax
  int v31; // eax
  int v32; // eax
  int top_1; // eax
  tagRECT v34; // [rsp+28h] [rbp-99h] BYREF
  tagRECT v35; // [rsp+38h] [rbp-89h] BYREF
  tagRECT v36; // [rsp+48h] [rbp-79h] BYREF
  __int64 v37; // [rsp+58h] [rbp-69h]
  _QWORD v38[3]; // [rsp+60h] [rbp-61h] BYREF
  tagRECT v39; // [rsp+78h] [rbp-49h] BYREF
  char v40[16]; // [rsp+88h] [rbp-39h] BYREF
  char v41[16]; // [rsp+98h] [rbp-29h] BYREF
  char v42[16]; // [rsp+A8h] [rbp-19h] BYREF
  tagRECT v43; // [rsp+B8h] [rbp-9h] BYREF

  v2 = 0;
  v38[2] = 0;
  v43 = 0;
  v5 = *(_QWORD *)(GetDispInfo() + 96);
  v37 = v5;
  if ( *(_DWORD *)*gpDispInfo <= 1u )
  {
    v6 = v5;
    goto LABEL_3;
  }
  v39 = *(tagRECT *)GetScreenRectForWindow(a1: v40, a2: a1);
  if ( (unsigned int)IsMaxedRect(a1: &v39, a2) == 0 )
  {
    RECTFromSIZERECT(a1: &v43);
    v6 = MonitorFromRect(a1: &v43);
LABEL_3:
    CurrentThread = KeGetCurrentThread();
    v8 = 0;
    if ( (unsigned __int8)KeIsAttachedProcess() == 0
      || (CurrentProcess = PsGetCurrentProcess(),
          ProcessSessionId = PsGetProcessSessionIdEx(a1: CurrentProcess),
          CurrentThreadProcess = PsGetCurrentThreadProcess(),
          ProcessSessionId == (unsigned int)PsGetProcessSessionIdEx(a1: CurrentThreadProcess)) )
    {
      ThreadWin32Thread = (__int64 *)PsGetThreadWin32Thread(a1: CurrentThread);
      if ( ThreadWin32Thread != nullptr )
        v8 = *ThreadWin32Thread;
    }
    v38[0] = *(_QWORD *)(v8 + 408);
    *(_QWORD *)(v8 + 408) = v38;
    v38[1] = v6;
    HMLockObject(a1: v6);
    WindowCompositedDpiContext = GetWindowCompositedDpiContext(a1);
    v11 = *(tagRECT *)GetMonitorWorkRectForDpiContext(a1: v41, a2: v6, WindowCompositedDpiContext);
    v34 = v11;
    if ( (unsigned int)IsMaxedRect(a1: &v34, a2) != 0 )
    {
      MonitorRectForWindow = (tagRECT *)GetMonitorRectForWindow(a1: v42, a2: v6, a3: a1);
      v20 = *((_QWORD *)a1 + 5);
      v36 = *MonitorRectForWindow;
      if ( (*(_BYTE *)(v20 + 31) & 1) != 0
        && (SetOrClrWF(a1: 1, a2: a1, a3: 832, a4: 1), (*(_BYTE *)((v21 = *((_QWORD *)a1 + 5)) + 31) & 1) != 0)
        && (((*(_BYTE *)(v21 + 30) & 0xC0) == 0xC0) & *(_BYTE *)(v21 + 30)) != 0 )
      {
        n3 = *(_DWORD *)(v21 + 288) & 0xF;
        if ( n3 == 3 )
        {
          WindowDpiLastNotify = (*(_DWORD *)(v21 + 288) >> 8) & 0x1FF;
        }
        else if ( (*(_DWORD *)(v21 + 232) & 0x8000000) != 0 )
        {
          WindowDpiLastNotify = GetWindowDpiLastNotify(a1);
        }
        else if ( n3 == 0
               && (v30 = *(_QWORD *)(*((_QWORD *)a1 + 2) + 448LL)) != 0
               && (*(_DWORD *)(**(_QWORD **)(v30 + 8) + 64LL) & 1) != 0 )
        {
          WindowDpiLastNotify = 96;
        }
        else
        {
          WindowDpiLastNotify = *(unsigned __int16 *)(*(_QWORD *)(*((_QWORD *)a1 + 2) + 416LL) + 284LL);
        }
        DpiDependentMetric = GetDpiDependentMetric(a1: 2, a2: WindowDpiLastNotify);
        DpiDependentMetric_1 = DpiDependentMetric;
        if ( (int)(*(_DWORD *)a2 + DpiDependentMetric) > v36.right
          || (int)(left = (unsigned int)(*((_DWORD *)a2 + 2) + *(_DWORD *)a2)) < v36.right
          || (int)((top = *((unsigned int *)a2 + 1)) + DpiDependentMetric) > v36.top
          || (int)(top = (unsigned int)(*((_DWORD *)a2 + 3) + top)) < v36.bottom )
        {
          if ( (*(_BYTE *)(*((_QWORD *)a1 + 5) + 20LL) & 0x40) != 0 )
            v2 = xxxRemoveFullScreen(a1, top, DpiDependentMetric);
          if ( *((_DWORD *)a1 + 77) != 0 )
          {
            v35 = v11;
            ExtendRectByWindowMargin(a1, a2: &v35, a3: &v35);
            left = (unsigned int)v35.left;
            top = (unsigned int)v35.top;
            v31 = v35.right - v35.left;
            *(_DWORD *)a2 = v35.left;
            *((_DWORD *)a2 + 2) = v31;
            v32 = v35.bottom - top;
            *((_DWORD *)a2 + 1) = top;
            *((_DWORD *)a2 + 3) = v32;
          }
          else
          {
            WindowBordersWithDpiAwareness = GetWindowBordersWithDpiAwareness(
                                              a1,
                                              top,
                                              DpiDependentMetric: DpiDependentMetric_1);
            bottom = v34.bottom;
            *(_DWORD *)a2 = v34.left - WindowBordersWithDpiAwareness;
            *((_DWORD *)a2 + 1) = v34.top - WindowBordersWithDpiAwareness;
            WindowBordersWithDpiAwareness *= 2;
            left = (unsigned int)(WindowBordersWithDpiAwareness - v34.top);
            top = (unsigned int)(left + bottom);
            *((_DWORD *)a2 + 2) = v34.right + WindowBordersWithDpiAwareness - v34.left;
            if ( v6 == v37 && (*(_BYTE *)(*((_QWORD *)a1 + 5) + 21LL) & 2) == 0 )
            {
              top_1 = *((_DWORD *)a2 + 3);
              if ( (int)top >= top_1 )
                top = (unsigned int)top_1;
            }
            *((_DWORD *)a2 + 3) = top;
          }
          goto LABEL_11;
        }
        if ( (*(_BYTE *)(*((_QWORD *)a1 + 5) + 20LL) & 0x40) != 0 )
        {
LABEL_11:
          ThreadUnlock1(a1: left, a2: top, a3: DpiDependentMetric_1);
          return v2;
        }
      }
      else if ( (unsigned int)IsMaxedRect(a1: &v36, a2) == 0 )
      {
        goto LABEL_11;
      }
      v14 = xxxAddFullScreen(a1);
    }
    else
    {
      if ( (*(_BYTE *)(*((_QWORD *)a1 + 5) + 31LL) & 1) != 0 )
        SetOrClrWF(a1: 0, a2: a1, a3: 832, a4: 1);
      v14 = xxxRemoveFullScreen(a1, top: top_2, DpiDependentMetric: DpiDependentMetric_2);
    }
    v2 = v14;
    goto LABEL_11;
  }
  return 0;
}
