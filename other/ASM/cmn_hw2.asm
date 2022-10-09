.386
.model flat, stdcall
option casemap: none

include windows.inc
include user32.inc
include kernel32.inc
include Fpu.inc
include debug.inc

includelib user32.lib
includelib kernel32.lib
includelib Fpu.lib
includelib debug.lib 

.const
        one real4 1.0
        zero real4 0.0
        minusOne REAL4 -1.0
        startReal4 real4 1.0
        
        two word 2

.data
        doubleDX word 0
        temp real4 0.0
        resOfPow real10 0.0
        resOfFac real4 0.0
        sum real10 0.0
        sum4 real4 0.0
        a word -1
        b word 1
        delta real4 0.1
        eps real4 0.001
        resInStr byte 10 dup(0)
        x1 REAL4 1.57
        
        counter word 0
        
        State byte 400 dup (0)
        Caption db "Состояние регистров FPU",0
        

.code
cMacro MACRO
        push cx
        invoke FpuState, ADDR State, 1
        invoke MessageBox, 0, addr State, addr Caption, 1
        invoke FpuFLtoA, addr sum, 14, addr resInStr, SRC1_REAL
        pop cx
endm

pow proc x: REAL4, degree: word
        PrintDec degree
        mov cx, degree
        dec cx
        fld x
        .if degree == 0
                finit
                fld one
                ret
        .elseif degree == 1
                ret
        .endif
        fcom zero
        je retOne
        jmp other
retOne:
        finit
        fld one
        pop dx
        ret
other:
        mainLoop:
                fmul x
                dec cx
                jne mainLoop
        ret
pow endp

factorial proc x: word
        local v :real4
        fld startReal4
        fstp v
        
        push ebx
        
        mov cx, x
        dec cx
        mov eax, 1
        mov ebx, 1
        
        fld v
        fld startReal4
        .if x == 0
                ret
        .endif
        mainLoop:
                fadd one
                fmul st(1), st(0)
                dec cx
                jne mainLoop
        pop ebx
        ret
factorial endp

start:   
        mov cx, 5
        mov counter, 0
        mov doubleDX, 0
        
        expression:
                mov ax, counter
                mul two
                mov doubleDX, ax
                        
                PrintDec doubleDX
                push cx
                invoke pow, x1, doubleDX
                pop cx
                fstp resOfPow
                
                push cx
                invoke factorial, doubleDX
                pop cx
                fstp temp
                fstp resOfFac
                
                mov ax, counter
                mov bl, 2
                div bl
                .if ah == 0
                        fld resOfPow
                        fdiv resOfFac
                        fadd sum4
                        fstp sum4
                .elseif
                        fld resOfPow
                        fdiv resOfFac
                        fdiv minusOne
                        fadd sum4
                        fstp sum4
                .endif
                
                inc counter
                dec cx
                jne expression
        fld sum4
        ;invoke FpuState, ADDR State, 1
        ;invoke MessageBox, 0, addr State, addr Caption, 1
        invoke FpuFLtoA, 0, 14, addr resInStr, SRC1_FPU 
        PrintString resInStr
        invoke ExitProcess, 0
end start
