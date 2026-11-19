void __fastcall MilInstrumentationBreak(const unsigned __int16 *a1, const unsigned __int16 *a2)
{
  char v2; // bl
  int v3; // eax
  int v4; // ebx
  BOOL v5; // eax
  char v6; // cl
  HANDLE CurrentThread; // rax
  HANDLE CurrentProcess; // rax
  unsigned int Response; // [rsp+78h] [rbp+10h] BYREF

  LOBYTE(Response) = (_BYTE)a2;
  v2 = (char)a1;
  if ( !g_fDisableInstrumentationBreaks )
  {
    Response = 0;
    if ( RegGetHKLMDword(a1, a2, a3: &Response)
      && Response == 0
      && ((v2 & 8) == 0
       || (unsigned int)IsKernelDebuggerPresent() != 0
       || !IsDebuggerPresent() && (unsigned int)IsKernelDebuggerEnabled() != 0) )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v3 = IsKernelDebuggerPresent();
          LOWORD(Response) = 63;
          v4 = v3;
          if ( v3 == 0 )
          {
            v5 = IsDebuggerPresent();
            v6 = Response;
            if ( v5 )
              v6 = 103;
            LOBYTE(Response) = v6;
          }
          DbgPrintEx(
            ComponentId: 0x65u,
            Level: 0,
            Format: "\n*** Assertion failed: %ls%ls%ls\n***   %s%ls%sSource: `%ls:%ld`\n\n",
            L"Unexpected HRESULT in MilInstrumentation* caller",
            &dword_18001C9E4,
            &dword_18001C9E4,
            "Function: ",
            L"MilInstrumentationBreak",
            ", ",
            L"clientcore\\windows\\dwm\\shared\\util\\utillib\\debugbreak.cpp",
            221);
          if ( v4 == 0 )
          {
            DbgPrintEx(
              ComponentId: 0x65u,
              Level: 0,
              Format: "(No kernel debugger is present.) Respond with:\n"
              "  g                    -- Go (continue)\n"
              "  eb 0x%p 'p';g  -- terminate Process\n"
              "  eb 0x%p 't';g  -- terminate Thread\n"
              " or regular debugging.\n",
              &Response,
              &Response);
            __debugbreak();
          }
          DbgPrompt(
            Prompt: "Break, Go (continue), terminate Process, or terminate Thread (bgpt)? ",
            (PCH)&Response,
            MaximumResponseLength: 2u);
          if ( (char)Response <= 98 )
            break;
          switch ( (char)Response )
          {
            case 'g':
              return;
            case 'i':
LABEL_30:
              DbgPrintEx(ComponentId: 0x65u, Level: 0, Format: "'i' is only supported with debug builds.\n");
              break;
            case 'p':
LABEL_28:
              CurrentProcess = GetCurrentProcess();
              TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000001);
              goto LABEL_29;
            case 't':
LABEL_27:
              CurrentThread = GetCurrentThread();
              TerminateThread(hThread: CurrentThread, dwExitCode: 0xC0000001);
              goto LABEL_29;
            default:
              goto LABEL_29;
          }
        }
        switch ( (char)Response )
        {
          case 'b':
          case 'B':
            __debugbreak();
          case 'G':
            return;
          case 'I':
            goto LABEL_30;
          case 'P':
            goto LABEL_28;
          case 'T':
            goto LABEL_27;
          default:
            break;
        }
LABEL_29:
        DbgPrintEx(ComponentId: 0x65u, Level: 0, Format: "Unrecognized response.\n");
      }
    }
  }
}
