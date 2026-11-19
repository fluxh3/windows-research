__int64 __fastcall Microsoft::WRL::Details::MakeAndInitialize<Windows::System::Threading::CThreadPoolTimer,Windows::System::Threading::IThreadPoolTimer,Windows::System::Threading::ITimerElapsedHandler * &,Windows::Foundation::TimeSpan &,Windows::Foundation::TimeSpan &,Windows::System::Threading::ITimerDestroyedHandler * &>(
        Microsoft::WRL::Details *this,
        struct Windows::System::Threading::IThreadPoolTimer **a2,
        struct Windows::System::Threading::ITimerElapsedHandler **a3,
        struct Windows::Foundation::TimeSpan *a4,
        struct Windows::Foundation::TimeSpan *a5)
{
  Windows::System::Threading::CThreadPoolTimer *v9; // rax
  Windows::System::Threading::CThreadPoolTimer *v10; // rbx
  __int64 v11; // rdx
  int v12; // edi
  __int64 v13; // r8
  __int64 v14; // r9
  __int64 v16; // [rsp+20h] [rbp-38h]

  *(_QWORD *)this = 0;
  v9 = (Windows::System::Threading::CThreadPoolTimer *)operator new(
                                                         a1: 0x80u,
                                                         a2: (const std::nothrow_t *)&std::nothrow);
  if ( v9 == nullptr )
    return 2147942414LL;
  v10 = Windows::System::Threading::CThreadPoolTimer::CThreadPoolTimer(this: v9);
  v12 = guard_dispatch_icall_nop(a1: v10, a2: *a2, a3: *a3, a4: *(_QWORD *)a4, a5: *(_QWORD *)a5);
  if ( v12 >= 0 )
    v12 = guard_dispatch_icall_nop(a1: v10, a2: &GUID_594ebe78_55ea_4a88_a50d_3402ae1f9cf2, a3: this, a4: v14, a5: v16);
  guard_dispatch_icall_nop(a1: v10, a2: v11, a3: v13, a4: v14, a5: v16);
  return (unsigned int)v12;
}
