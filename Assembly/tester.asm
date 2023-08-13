        mov     eax, DWORD PTR [rbp-4]
        cmp     eax, DWORD PTR [rbp-8]
        jg      .L2
        mov     eax, DWORD PTR [rbp-4]
        cmp     eax, DWORD PTR [rbp-12]
        jg      .L2
        mov     eax, DWORD PTR [rbp-8]
        cdq
        idiv    DWORD PTR [rbp-4]
        mov     eax, edx
        test    eax, eax
        jne     .L3
        mov     eax, DWORD PTR [rbp-12]
        cdq
        idiv    DWORD PTR [rbp-4]
        mov     eax, edx
        test    eax, eax
        jne     .L3
        mov     eax, DWORD PTR [rbp-4]
        mov     DWORD PTR [rbp-16], eax