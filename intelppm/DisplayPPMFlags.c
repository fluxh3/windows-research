void __fastcall DisplayPPMFlags(__int64 a1, unsigned __int8 a2)
{
  const char *v4; // rdi
  const char *v5; // rax
  const char *v6; // rax
  const char *v7; // rax
  const char *v8; // rax
  const char *v9; // rax
  const char *v10; // rax
  const char *v11; // rax
  const char *v12; // rax
  const char *v13; // rax
  const char *v14; // rax
  const char *v15; // rax
  const char *v16; // rax
  const char *v17; // rax
  const char *v18; // rax
  const char *v19; // rax
  const char *v20; // rax
  const char *v21; // rax
  const char *v22; // rax
  const char *v23; // rax
  const char *v24; // rax
  const char *v25; // rax
  const char *v26; // rax
  const char *v27; // rax
  const char *v28; // rax
  const char *v29; // rax
  const char *v30; // rax
  const char *v31; // rax
  const char *v32; // rax

  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
      WPP_RECORDER_SF_(
        a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
        a2,
        a3: 2u,
        a4: 58,
        a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids);
    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
    {
      v4 = "En";
      if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
      {
        v5 = "En";
        if ( (a1 & 1) == 0 )
          v5 = "Dis";
        WPP_RECORDER_SF_s(
          a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
          a2,
          a3: 2u,
          a4: 59,
          a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
          a6: v5);
      }
      if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      {
        if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
        {
          v6 = "En";
          if ( (a1 & 2) == 0 )
            v6 = "Dis";
          WPP_RECORDER_SF_s(
            a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
            a2,
            a3: 2u,
            a4: 60,
            a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
            a6: v6);
        }
        if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        {
          if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
          {
            v7 = "En";
            if ( (a1 & 4) == 0 )
              v7 = "Dis";
            WPP_RECORDER_SF_s(
              a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
              a2,
              a3: 2u,
              a4: 61,
              a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
              a6: v7);
          }
          if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
          {
            if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
            {
              v8 = "En";
              if ( (a1 & 0x100000) == 0 )
                v8 = "Dis";
              WPP_RECORDER_SF_s(
                a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                a2,
                a3: 2u,
                a4: 62,
                a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                a6: v8);
            }
            if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
            {
              if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
              {
                v9 = "En";
                if ( (a1 & 0x200000) == 0 )
                  v9 = "Dis";
                WPP_RECORDER_SF_s(
                  a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                  a2,
                  a3: 2u,
                  a4: 63,
                  a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                  a6: v9);
              }
              if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
              {
                if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                  WPP_RECORDER_SF_(
                    a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                    a2,
                    a3: 2u,
                    a4: 64,
                    a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids);
                if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                {
                  if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                    WPP_RECORDER_SF_(
                      a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                      a2,
                      a3: 2u,
                      a4: 65,
                      a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids);
                  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                  {
                    if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                    {
                      v10 = "En";
                      if ( (a1 & 0x10) == 0 )
                        v10 = "Dis";
                      WPP_RECORDER_SF_s(
                        a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                        a2,
                        a3: 2u,
                        a4: 66,
                        a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                        a6: v10);
                    }
                    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                    {
                      if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                      {
                        v11 = "En";
                        if ( (a1 & 0x20) == 0 )
                          v11 = "Dis";
                        WPP_RECORDER_SF_s(
                          a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                          a2,
                          a3: 2u,
                          a4: 67,
                          a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                          a6: v11);
                      }
                      if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                      {
                        if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                        {
                          v12 = "En";
                          if ( (a1 & 0x40) == 0 )
                            v12 = "Dis";
                          WPP_RECORDER_SF_s(
                            a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                            a2,
                            a3: 2u,
                            a4: 68,
                            a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                            a6: v12);
                        }
                        if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                        {
                          if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                          {
                            v13 = "En";
                            if ( (a1 & 0x7F000) == 0 )
                              v13 = "Dis";
                            WPP_RECORDER_SF_s(
                              a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                              a2,
                              a3: 2u,
                              a4: 69,
                              a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                              a6: v13);
                          }
                          if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                          {
                            if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                            {
                              v14 = "En";
                              if ( (a1 & 0x80000000000LL) == 0 )
                                v14 = "Dis";
                              WPP_RECORDER_SF_s(
                                a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                a2,
                                a3: 2u,
                                a4: 70,
                                a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                a6: v14);
                            }
                            if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                            {
                              if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                              {
                                v15 = "En";
                                if ( (a1 & 0x20000000000LL) == 0 )
                                  v15 = "Dis";
                                WPP_RECORDER_SF_s(
                                  a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                  a2,
                                  a3: 2u,
                                  a4: 71,
                                  a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                  a6: v15);
                              }
                              if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                              {
                                if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                {
                                  v16 = "En";
                                  if ( (a1 & 0x40000000000LL) == 0 )
                                    v16 = "Dis";
                                  WPP_RECORDER_SF_s(
                                    a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                    a2,
                                    a3: 2u,
                                    a4: 72,
                                    a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                    a6: v16);
                                }
                                if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                {
                                  if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                  {
                                    v17 = "En";
                                    if ( (a1 & 0xE0000000000LL) == 0 )
                                      v17 = "Dis";
                                    WPP_RECORDER_SF_s(
                                      a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                      a2,
                                      a3: 2u,
                                      a4: 73,
                                      a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                      a6: v17);
                                  }
                                  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                  {
                                    if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                    {
                                      v18 = "En";
                                      if ( (a1 & 0x1000000) == 0 )
                                        v18 = "Dis";
                                      WPP_RECORDER_SF_s(
                                        a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                        a2,
                                        a3: 2u,
                                        a4: 74,
                                        a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                        a6: v18);
                                    }
                                    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                    {
                                      if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                      {
                                        v19 = "En";
                                        if ( (a1 & 0x2000000) == 0 )
                                          v19 = "Dis";
                                        WPP_RECORDER_SF_s(
                                          a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                          a2,
                                          a3: 2u,
                                          a4: 75,
                                          a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                          a6: v19);
                                      }
                                      if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                      {
                                        if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                        {
                                          v20 = "En";
                                          if ( (a1 & 0x10000000) == 0 )
                                            v20 = "Dis";
                                          WPP_RECORDER_SF_s(
                                            a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                            a2,
                                            a3: 2u,
                                            a4: 76,
                                            a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                            a6: v20);
                                        }
                                        if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                        {
                                          if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                          {
                                            v21 = "En";
                                            if ( (a1 & 0x20000000) == 0 )
                                              v21 = "Dis";
                                            WPP_RECORDER_SF_s(
                                              a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                              a2,
                                              a3: 2u,
                                              a4: 77,
                                              a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                              a6: v21);
                                          }
                                          if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                          {
                                            if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                            {
                                              v22 = "En";
                                              if ( (a1 & 0x40000000) == 0 )
                                                v22 = "Dis";
                                              WPP_RECORDER_SF_s(
                                                a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                a2,
                                                a3: 2u,
                                                a4: 78,
                                                a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                a6: v22);
                                            }
                                            if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                            {
                                              if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                              {
                                                v23 = "En";
                                                if ( (a1 & 0x80000000) == 0 )
                                                  v23 = "Dis";
                                                WPP_RECORDER_SF_s(
                                                  a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                  a2,
                                                  a3: 2u,
                                                  a4: 79,
                                                  a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                  a6: v23);
                                              }
                                              if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                              {
                                                if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                {
                                                  v24 = "En";
                                                  if ( (a1 & 0x8000000) == 0 )
                                                    v24 = "Dis";
                                                  WPP_RECORDER_SF_s(
                                                    a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                    a2,
                                                    a3: 2u,
                                                    a4: 80,
                                                    a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                    a6: v24);
                                                }
                                                if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                {
                                                  if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                  {
                                                    v25 = "En";
                                                    if ( (a1 & 0x4000000000LL) == 0 )
                                                      v25 = "Dis";
                                                    WPP_RECORDER_SF_s(
                                                      a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                      a2,
                                                      a3: 2u,
                                                      a4: 81,
                                                      a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                      a6: v25);
                                                  }
                                                  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                  {
                                                    if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                    {
                                                      v26 = "En";
                                                      if ( (a1 & 0x4000000) == 0 )
                                                        v26 = "Dis";
                                                      WPP_RECORDER_SF_s(
                                                        a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                        a2,
                                                        a3: 2u,
                                                        a4: 82,
                                                        a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                        a6: v26);
                                                    }
                                                    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                    {
                                                      if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                        WPP_RECORDER_SF_(
                                                          a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                          a2,
                                                          a3: 2u,
                                                          a4: 83,
                                                          a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids);
                                                      if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                      {
                                                        if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                          WPP_RECORDER_SF_(
                                                            a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                            a2,
                                                            a3: 2u,
                                                            a4: 84,
                                                            a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids);
                                                        if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                        {
                                                          if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                          {
                                                            v27 = "En";
                                                            if ( (a1 & 0x100000000LL) == 0 )
                                                              v27 = "Dis";
                                                            WPP_RECORDER_SF_s(
                                                              a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                              a2,
                                                              a3: 2u,
                                                              a4: 85,
                                                              a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                              a6: v27);
                                                          }
                                                          if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                          {
                                                            if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                            {
                                                              v28 = "En";
                                                              if ( (a1 & 0x200000000LL) == 0 )
                                                                v28 = "Dis";
                                                              WPP_RECORDER_SF_s(
                                                                a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                                a2,
                                                                a3: 2u,
                                                                a4: 86,
                                                                a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                                a6: v28);
                                                            }
                                                            if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                            {
                                                              if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                              {
                                                                v29 = "En";
                                                                if ( (a1 & 0x300) == 0 )
                                                                  v29 = "Dis";
                                                                WPP_RECORDER_SF_s(
                                                                  a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                                  a2,
                                                                  a3: 2u,
                                                                  a4: 87,
                                                                  a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                                  a6: v29);
                                                              }
                                                              if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                              {
                                                                if ( a2 < 5u || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                                {
                                                                  v30 = "En";
                                                                  if ( (a1 & 0x100000000000LL) == 0 )
                                                                    v30 = "Dis";
                                                                  WPP_RECORDER_SF_s(
                                                                    a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                                    a2,
                                                                    a3: 2u,
                                                                    a4: 88,
                                                                    a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                                    a6: v30);
                                                                }
                                                                if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                                {
                                                                  if ( a2 < 5u
                                                                    || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                                  {
                                                                    v31 = "En";
                                                                    if ( (a1 & 0x400) == 0 )
                                                                      v31 = "Dis";
                                                                    WPP_RECORDER_SF_s(
                                                                      a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                                      a2,
                                                                      a3: 2u,
                                                                      a4: 89,
                                                                      a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                                      a6: v31);
                                                                  }
                                                                  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                                  {
                                                                    if ( a2 < 5u
                                                                      || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                                    {
                                                                      v32 = "En";
                                                                      if ( (a1 & 0x1000000000LL) == 0 )
                                                                        v32 = "Dis";
                                                                      WPP_RECORDER_SF_s(
                                                                        a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                                        a2,
                                                                        a3: 2u,
                                                                        a4: 90,
                                                                        a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                                        a6: v32);
                                                                    }
                                                                    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
                                                                    {
                                                                      if ( a2 < 5u
                                                                        || *((_WORD *)WPP_GLOBAL_Control + 36) != 0 )
                                                                      {
                                                                        if ( (a1 & 0x10000000000LL) == 0 )
                                                                          v4 = "Dis";
                                                                        WPP_RECORDER_SF_s(
                                                                          a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                                          a2,
                                                                          a3: 2u,
                                                                          a4: 91,
                                                                          a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids,
                                                                          a6: v4);
                                                                      }
                                                                      if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED
                                                                        && (a2 < 5u
                                                                         || *((_WORD *)WPP_GLOBAL_Control + 36) != 0) )
                                                                      {
                                                                        WPP_RECORDER_SF_(
                                                                          a1: *((_QWORD *)WPP_GLOBAL_Control + 8),
                                                                          a2,
                                                                          a3: 2u,
                                                                          a4: 92,
                                                                          a5: (__int64)WPP_4aa995de970d3daca8f220cb4e8727bd_Traceguids);
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
