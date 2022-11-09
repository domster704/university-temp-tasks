.686
.model flat, stdcall
option casemap: none

include \masm32\include\windows.inc
include \masm32\include\user32.inc
include \masm32\include\kernel32.inc
include \masm32\include\Fpu.inc
include \masm32\include\debug.inc

includelib \masm32\lib\user32.lib
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\Fpu.lib
includelib \masm32\lib\debug.lib

.const
    zero real8 0.0
    one real8 1.0
    two real8 2.0
    
    n dword 169
    
.data
    res real8 0.0
    resInStr byte 100 dup(0)
    temp real8 0.0

.code
factorial proc nFac :dword   
    fld one
    fld one
    mov ecx, nFac
    .while (ecx > 0)       
        fadd one
        fmul st(1), st(0)
        dec ecx
    .endw
    fstp temp
    ret 
factorial endp

sumOfFactorials proc count: dword
    local counter: dword
    local result: real8
    
    fld zero
    fstp result
    
    mov ebx, count
    mov counter, ebx
    .while(counter > 0)
        invoke factorial, counter
        fstp temp
        fld result
        fadd temp
        fstp result
        dec counter
    .endw
    fld result
    ret
sumOfFactorials endp

start: 
    invoke sumOfFactorials, n
    invoke FpuFLtoA, 0, 16, addr resInStr, SRC1_FPU or STR_REG 
    PrintString resInStr
end start
