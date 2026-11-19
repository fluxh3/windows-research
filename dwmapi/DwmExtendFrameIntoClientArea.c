HRESULT __stdcall DwmExtendFrameIntoClientArea(HWND hWnd, const MARGINS *pMarInset)
{
  int v2; // r8d
  int v5; // edi
  HDC DC; // rbx
  signed int LastError; // eax
  int v8; // esi
  CPortClient *v9; // rbx
  int v10; // r12d
  __int64 v11; // rcx
  int v12; // eax
  HANDLE ProcessHeap; // rax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  ULONG v18; // r15d
  SIZE_T v19; // r14
  _PORT_MESSAGE *v20; // rax
  __int16 v21; // r8
  _PORT_MESSAGE *v22; // rsi
  __int64 v23; // rcx
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // ecx
  __int64 v28; // r8
  int v29; // edx
  DWORD CurrentProcessId; // eax
  HWINEVENTHOOK v31; // rbx
  signed int v32; // eax
  char *inserted; // rax
  unsigned int idProcess; // [rsp+28h] [rbp-E0h]
  SIZE_T *idThread; // [rsp+30h] [rbp-D8h]
  int ZeroInit; // [rsp+4Ch] [rbp-BCh]
  SIZE_T v38; // [rsp+58h] [rbp-B0h] BYREF
  _DWORD v39[10]; // [rsp+60h] [rbp-A8h] BYREF
  HWND Buffer; // [rsp+88h] [rbp-80h] BYREF
  __int128 v41; // [rsp+90h] [rbp-78h]
  __int64 v42; // [rsp+A0h] [rbp-68h]
  __int64 v43; // [rsp+A8h] [rbp-60h]
  __int64 v44; // [rsp+B0h] [rbp-58h]
  __int64 v45; // [rsp+B8h] [rbp-50h]
  char v46[24]; // [rsp+C0h] [rbp-48h] BYREF
  unsigned __int16 v47[8]; // [rsp+D8h] [rbp-30h] BYREF
  __int128 v48; // [rsp+E8h] [rbp-20h]
  __int128 v49; // [rsp+F8h] [rbp-10h]
  __int128 v50; // [rsp+108h] [rbp+0h]
  __int128 v51; // [rsp+118h] [rbp+10h]
  __int16 v52; // [rsp+128h] [rbp+20h]
  unsigned __int16 v53[8]; // [rsp+138h] [rbp+30h] BYREF
  __int128 v54; // [rsp+148h] [rbp+40h]
  __int128 v55; // [rsp+158h] [rbp+50h]
  __int128 v56; // [rsp+168h] [rbp+60h]
  __int128 v57; // [rsp+178h] [rbp+70h]
  __int16 v58; // [rsp+188h] [rbp+80h]

  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 )
    McGenEventWrite_EtwEventWriteTransfer(
      a1: (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: (unsigned int)ApiExtendFrameIntoClientArea_Start,
      a3: v2,
      a4: 1,
      a5: (__int64)v46);
  if ( (unsigned int)IsTopLevelWindow(a1: hWnd) == 0 )
  {
    v5 = -2147024809;
    idProcess = 35;
LABEL_5:
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: v5, a5: idProcess, a6: idThread);
    goto LABEL_87;
  }
  v39[2] = 1073741850;
  *(_OWORD *)&v39[3] = (unsigned __int64)hWnd;
  *(MARGINS *)&v39[5] = *pMarInset;
  if ( (unsigned int)IsWindowGdiScaled(a1: hWnd) != 0 )
  {
    DC = GetDC(hWnd);
    if ( DC != nullptr )
    {
      SetLastError(dwErrCode: 0);
      if ( (unsigned int)ScaleValues(a1: DC, a2: &v39[5], a3: 4) == 0 )
      {
        LastError = GetLastError();
        v5 = LastError;
        if ( LastError > 0 )
          v5 = (unsigned __int16)LastError | 0x80070000;
        idProcess = 50;
        if ( v5 >= 0 )
          v5 = -2003304445;
        goto LABEL_5;
      }
      ReleaseDC(hWnd, hDC: DC);
    }
  }
  v5 = -2144980991;
  v8 = 0;
  EnterCriticalSection(lpCriticalSection: &CriticalSection);
  v9 = qword_180022EF8;
  if ( qword_180022EF8 == nullptr || (v10 = 1, *((_QWORD *)qword_180022EF8 + 2) == 0) )
    v10 = 0;
  if ( byte_180022F28 == 0 )
  {
    while ( 1 )
    {
      if ( v9 != nullptr && *((_QWORD *)v9 + 2) != 0 )
        goto LABEL_36;
      ReleaseInterface<CPortClientRefCounted>(a1: &qword_180022EF8);
      v9 = (CPortClient *)(*(__int64 (__fastcall **)(LPVOID, __int64))(*(_QWORD *)WPF::g_pProcessHeap + 8LL))(
                            a1: WPF::g_pProcessHeap,
                            a2: 64);
      if ( v9 != nullptr )
      {
        v11 = qword_180022EF0;
        v12 = g_PortClient;
        *(_QWORD *)v9 = &CPortClient::`vftable';
        *((_DWORD *)v9 + 2) = 0;
        *((_QWORD *)v9 + 4) = v11;
        *((_QWORD *)v9 + 2) = 0;
        *((_BYTE *)v9 + 24) = 0;
        *((_DWORD *)v9 + 7) = v12;
        *((_QWORD *)v9 + 5) = 0;
        ProcessHeap = GetProcessHeap();
        *(_QWORD *)v9 = &CPortClientRefCounted::`vftable';
        *((_QWORD *)v9 + 6) = ProcessHeap;
        *((_DWORD *)v9 + 14) = 1;
        v52 = 0;
        v58 = 0;
        *(_OWORD *)v47 = 0;
        v48 = 0;
        v49 = 0;
        v50 = 0;
        v51 = 0;
        *(_OWORD *)v53 = 0;
        v54 = 0;
        v55 = 0;
        v56 = 0;
        v57 = 0;
        LeaveCriticalSection(lpCriticalSection: &CriticalSection);
        if ( NtCurrentPeb()->SessionId != 0
          && (v14 = StringCchPrintfW(a1: v47, a2: 0x29u, a3: L"\\Sessions\\%d", NtCurrentPeb()->SessionId),
              v5 = v14,
              v14 < 0) )
        {
          MilInstrumentationCheckHR_MaybeFailFast(
            a1: 4u,
            a2: &CApiPortClient::MILINSTRUMENTATIONHRESULTLIST,
            a3: 2u,
            a4: v14,
            a5: 0x10Cu,
            a6: idThread);
        }
        else
        {
          v15 = StringCchPrintfW(a1: v53, a2: 0x29u, a3: L"%s\\Windows\\DwmApiPort", v47);
          v5 = v15;
          if ( v15 < 0 )
          {
            MilInstrumentationCheckHR_MaybeFailFast(
              a1: 4u,
              a2: &CApiPortClient::MILINSTRUMENTATIONHRESULTLIST,
              a3: 2u,
              a4: v15,
              a5: 0x113u,
              a6: idThread);
          }
          else
          {
            v16 = CPortClient::ConnectWithName(this: v9, a2: v53);
            v17 = CApiPortClient::Translate(a1: v16);
            v5 = v17;
            if ( v17 < 0 )
              MilInstrumentationCheckHR_MaybeFailFast(
                a1: 4u,
                a2: &CApiPortClient::MILINSTRUMENTATIONHRESULTLIST,
                a3: 2u,
                a4: v17,
                a5: 0x116u,
                a6: idThread);
          }
        }
        EnterCriticalSection(lpCriticalSection: &CriticalSection);
        if ( v5 >= 0 && qword_180022EF8 == nullptr )
        {
          qword_180022EF8 = v9;
          goto LABEL_35;
        }
        CPortClientRefCounted::Release(this: v9);
      }
      else
      {
        v5 = -2147024882;
        MilInstrumentationCheckHR_MaybeFailFast(
          a1: 4u,
          a2: &CApiPortClient::MILINSTRUMENTATIONHRESULTLIST,
          a3: 2u,
          a4: -2147024882,
          a5: 0xF7u,
          a6: idThread);
      }
      v9 = qword_180022EF8;
LABEL_35:
      if ( v5 < 0 )
      {
        MilInstrumentationCheckHR_MaybeFailFast(
          a1: 4u,
          a2: &CApiPortClient::MILINSTRUMENTATIONHRESULTLIST,
          a3: 2u,
          a4: v5,
          a5: 0xA6u,
          a6: idThread);
        goto LABEL_69;
      }
LABEL_36:
      if ( v9 != nullptr )
        _InterlockedIncrement((volatile signed __int32 *)v9 + 14);
      LeaveCriticalSection(lpCriticalSection: &CriticalSection);
      v18 = v39[2];
      v5 = 0;
      v19 = (unsigned __int16)(max<short>(a1: 0x1Cu, a2: 0) + 48);
      v20 = (_PORT_MESSAGE *)HeapAlloc(hHeap: *((HANDLE *)v9 + 6), dwFlags: 8u, dwBytes: v19);
      v22 = v20;
      if ( v20 != nullptr )
      {
        v20[1].u1.Length = v18;
        LpcSetPayloadSizeBytes(a1: v20, a2: 36, a3: v21);
        v22[1].8 = *(union _PORT_MESSAGE::$C6BC508B531A81D74C33985719C23F49 *)&v39[2];
        *(_QWORD *)&v22[1].MessageId = *(_QWORD *)&v39[6];
        v22[1].CallbackId = v39[8];
        v23 = *((_QWORD *)v9 + 2);
        v38 = v19;
        idThread = &v38;
        v24 = NtAlpcSendWaitReceivePort(a1: v23, a2: 0x20000, a3: v22, a4: 0, a5: v22);
        v25 = CPortClient::CheckStatus(this: v9, a2: v24);
        if ( v25 >= 0 )
        {
          ZeroInit = v22[1].u2.ZeroInit;
        }
        else
        {
          v5 = v25 | 0x10000000;
          MilInstrumentationCheckHR_MaybeFailFast(
            a1: 4u,
            a2: &CPortClient::MILINSTRUMENTATIONHRESULTLIST,
            a3: 9u,
            a4: v25 | 0x10000000,
            a5: 0x216u,
            a6: &v38);
        }
        HeapFree(hHeap: *((HANDLE *)v9 + 6), dwFlags: 0, lpMem: v22);
      }
      else
      {
        v5 = -2147024882;
        MilInstrumentationCheckHR_MaybeFailFast(
          a1: 4u,
          a2: &CPortClient::MILINSTRUMENTATIONHRESULTLIST,
          a3: 9u,
          a4: -2147024882,
          a5: 0x204u,
          a6: idThread);
      }
      if ( _InterlockedExchangeAdd((volatile signed __int32 *)v9 + 14, 0xFFFFFFFF) == 1 )
        (**(void (__fastcall ***)(CPortClient *, __int64))v9)(a1: v9, a2: 1);
      EnterCriticalSection(lpCriticalSection: &CriticalSection);
      v9 = qword_180022EF8;
      if ( qword_180022EF8 != nullptr )
      {
        if ( _InterlockedCompareExchange((volatile signed __int32 *)qword_180022EF8 + 14, 1, 1) == 1
          && *((_DWORD *)v9 + 2) != 0 )
        {
          CPortClient::Disconnect(this: v9);
        }
        v9 = qword_180022EF8;
      }
      if ( v5 != -805306313 )
      {
        if ( (unsigned int)(v5 + 805306334) <= 0x1F && (v27 = -2147221503, _bittest(&v27, (unsigned __int8)(v5 - 34)))
          || (v28 = 0x10000000000041LL, (unsigned int)(v5 + 805305825) <= 0x34)
          && _bittest64(&v28, (unsigned __int8)(v5 - 31)) )
        {
          v5 = -2144980991;
          goto LABEL_59;
        }
        if ( v5 >= 0 )
        {
          if ( (unsigned int)(ZeroInit + 805306334) <= 0x1F
            && (v29 = -2145124351, _bittest(&v29, (unsigned __int8)(ZeroInit - 34)))
            || ZeroInit == -2003303402
            || (unsigned int)(ZeroInit + 805305825) <= 0x34 && _bittest64(&v28, (unsigned __int8)(ZeroInit - 31)) )
          {
            v8 = -2144980991;
          }
          else
          {
            v8 = ZeroInit;
          }
          break;
        }
LABEL_59:
        MilInstrumentationCheckHR_MaybeFailFast(
          a1: 4u,
          a2: &CApiPortClient::MILINSTRUMENTATIONHRESULTLIST,
          a3: 2u,
          a4: v5,
          a5: 0xC5u,
          a6: idThread);
LABEL_69:
        v8 = 0;
        break;
      }
      v26 = v10--;
      if ( v26 <= 0 )
      {
        v5 = -2144980991;
        MilInstrumentationCheckHR_MaybeFailFast(
          a1: 4u,
          a2: &CApiPortClient::MILINSTRUMENTATIONHRESULTLIST,
          a3: 2u,
          a4: -2144980991,
          a5: 0xC5u,
          a6: idThread);
        goto LABEL_69;
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection: &CriticalSection);
  if ( v5 < 0 )
  {
    MilInstrumentationCheckHR_MaybeFailFast(a1: 4u, a2: &qword_18001CA40, a3: 2u, a4: v5, a5: 0x39u, a6: idThread);
    goto LABEL_87;
  }
  v5 = v8;
  if ( v8 >= 0 )
  {
    *(_QWORD *)v39 = &CDwmHwndData::s_cs;
    EnterCriticalSection(lpCriticalSection: &CDwmHwndData::s_cs);
    v41 = 0;
    Buffer = hWnd;
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v45 = 0;
    if ( CDwmHwndData::s_hCleanupHook != nullptr )
      goto LABEL_84;
    LeaveCriticalSection(lpCriticalSection: &CDwmHwndData::s_cs);
    SetLastError(dwErrCode: 0);
    CurrentProcessId = GetCurrentProcessId();
    v31 = SetWinEventHook(
            eventMin: 0x8001u,
            eventMax: 0x8001u,
            hmodWinEventProc: g_hDwmApiInstance,
            pfnWinEventProc: CDwmHwndData::WinEventCallback,
            idProcess: CurrentProcessId,
            idThread: 0,
            dwFlags: 4u);
    if ( v31 != nullptr )
    {
      EnterCriticalSection(lpCriticalSection: &CDwmHwndData::s_cs);
      if ( CDwmHwndData::s_hCleanupHook == nullptr )
      {
        CDwmHwndData::s_hCleanupHook = v31;
        goto LABEL_84;
      }
      LeaveCriticalSection(lpCriticalSection: &CDwmHwndData::s_cs);
      UnhookWinEvent(hWinEventHook: v31);
    }
    else
    {
      v32 = GetLastError();
      if ( v32 > 0 )
        v32 = (unsigned __int16)v32 | 0x80070000;
      if ( v32 >= 0 )
        v32 = -2003304445;
      DoStackCaptureDirect(a1: v32, a2: 0x3Du);
    }
    EnterCriticalSection(lpCriticalSection: &CDwmHwndData::s_cs);
LABEL_84:
    inserted = (char *)RtlInsertElementGenericTable(
                         Table: &CDwmHwndData::s_dwmHwndDataMap,
                         &Buffer,
                         BufferSize: 0x38u,
                         NewElement: nullptr);
    if ( inserted != nullptr )
    {
      v5 = 0;
      *(_OWORD *)(inserted + 8) = *(_OWORD *)&v39[5];
      LeaveCriticalSection(lpCriticalSection: &CDwmHwndData::s_cs);
    }
    else
    {
      DoStackCaptureDirect(a1: -2147024882, a2: 0xDDu);
      v5 = -2147024882;
      MilInstrumentationCheckHR_MaybeFailFast(
        a1: 4u,
        a2: &qword_18001CA40,
        a3: 2u,
        a4: -2147024882,
        a5: 0x42u,
        a6: idThread);
      CGuard<CDwmCS>::~CGuard<CDwmCS>(this: (CGuard<class CDwmCS> *)v39);
    }
  }
LABEL_87:
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 )
    McTemplateU0q_EtwEventWriteTransfer(
      a1: Microsoft_Windows_Dwm_Api_Provider_Context,
      a2: ApiExtendFrameIntoClientArea_Stop,
      a3: (unsigned int)v5);
  return v5;
}
