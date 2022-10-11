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
        
        two word 2

.data
        ; Значение x, которое подставляется в уравнение
        mainValue REAL4 0.9
        
        resInReal4 real4 0.0
        resInStr byte 10 dup(0)
        
        ; Идентификаторы для отображения FpuState
        State byte 400 dup (0)
        Caption db "Состояние регистров FPU",0
        

.code
; Макроопределение для упрощённого показа FpuState
cMacro MACRO
        push cx
        invoke FpuState, ADDR State, 1
        invoke MessageBox, 0, addr State, addr Caption, 1
        invoke FpuFLtoA, addr sum, 14, addr resInStr, SRC1_REAL
        pop cx
endm

; Процедура для возведения в степень вещественного числа
; Записывает результат в верхний стек Fpu
pow proc x      :REAL4,
         degree :word

        mov cx, degree
        dec cx
        fld x
        ; Если степень равна 0, то возвращаем 1
        .if degree == 0
                finit
                fld one
                ret
        ; Если степень равна 1, то возвращем x
        .elseif degree == 1
                ret
        .endif
        mainLoop:
                fmul x
                dec cx
                jne mainLoop
        ret
pow endp

; Процедура для подсчёта факториала, который зааписывает результат в виде Real4 в стэк Fpu.
; Записывает результат в верхний стек Fpu
factorial proc x :word

        local v :real4
        fld one
        fstp v
        
        push ebx
        
        mov cx, x
        dec cx
        mov eax, 1
        mov ebx, 1
        
        fld v
        fld one
        ; Если x равен 0, то возвращаем 1, так как 0! = 1
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

; Процедура для суммирования членов аналитического ряда
sumMembersOfAnalyticalSeries proc
        local counter :word
        local doubleDX :word
        local resOfPow :real10
        local resOfFac :real4
        local valueForFutureDeleting :real4
        
        fld zero
        fld zero
        fld zero
        fstp resOfPow
        fstp resOfFac
        fstp valueForFutureDeleting
        
        mov counter, 0
        mov doubleDX, 0
        
        push cx
        mov cx, 5
        ; Цикл суммирования членов аналитического ряда
        expression:
                mov ax, counter
                mul two
                mov doubleDX, ax
                        
                push cx
                invoke pow, mainValue, doubleDX
                pop cx
                fstp resOfPow
                
                push cx
                invoke factorial, doubleDX
                pop cx
                fstp valueForFutureDeleting
                fstp resOfFac
                
                mov ax, counter
                mov bl, 2
                div bl
                ; Замена для (-1)^i
                .if ah == 0
                        fld resOfPow
                        fdiv resOfFac
                        
                        fadd resInReal4
                        fstp resInReal4
                .elseif
                        fld resOfPow
                        fdiv resOfFac
                        fdiv minusOne
                        
                        fadd resInReal4
                        fstp resInReal4
                .endif
                
                inc counter
                dec cx
                jne expression
        pop cx
        ret

sumMembersOfAnalyticalSeries endp

start:  
        finit
        call sumMembersOfAnalyticalSeries
        fld resInReal4
        ;invoke FpuState, ADDR State, 1
        ;invoke MessageBox, 0, addr State, addr Caption, 1
        invoke FpuFLtoA, 0, 14, addr resInStr, SRC1_FPU 
        PrintString resInStr
        ;invoke ExitProcess, 0
end start
