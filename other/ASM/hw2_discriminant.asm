.686
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
	zero real4 0.0
	two real4 2.0
	four real4 4.0

.data
	aInit real4 1.0
	bInit real4 8.0
	cInit real4 16.0
	
	resInReal4 real4 0.0
	resInStr byte 20 dup(0)
	State byte 400 dup (0)
    Caption db "State FPU",0

.code

cMacro MACRO
        push cx
        invoke FpuState, ADDR State, 1
        invoke MessageBox, 0, addr State, addr Caption, 1
        pop cx
endm

getRes macro
	invoke FpuFLtoA, 0, 16, addr resInStr, SRC1_FPU
	PrintString resInStr
endm

dicsriminant proc ak :real4,
				  bk :real4,
				  ck :real4
				  
	LOCAL D :real4
	LOCAL ac4 :real4
	LOCAL b2 :real4
	
	fld four
	fmul ak
	fmul ck
	fstp ac4
	
	fld bk
	fmul bk
	fstp b2
	
	fld b2
	fsub ac4
	;TODO if D < 0 then error
	fld zero
	fxch st(1)
	
	fcomi st(0), st(1)
	fstp D
	finit
	fld D
	
	ja sqrt
	je sqrt
	jb exit
	
	sqrt:
		fsqrt
		ret
	exit:
		ret
	
	ret

dicsriminant endp

countTheRoots proc D :real4,
			  	   ak :real4,
			  	   bk :real4	
			  	   
	LOCAL numeratorPlus :real4
	LOCAL numeratorMinus :real4
	
	fld zero
	fld D
	fcomi st(0), st(1)
	finit
	
	ja over2
	je eq0
	jb less0
	
	; There are 2 float numbers in stack
	; st(0) - is when b2 + sqrt(D)
	; st(1) - is when b2 - sqrt(D)
	over2:
		PrintDec 1
		fld bk
		fchs
		fadd D
		fstp numeratorPlus
	
		fld bk
		fchs
		fsub D
		fstp numeratorMinus
		
		fld numeratorMinus
		fdiv two
		fdiv ak
		
		fld numeratorPlus
		fdiv two
		fdiv ak
		
		ret
	
	eq0:
		fld bk
		fchs
		fdiv two
		fdiv ak
		
		ret
	
	less0:
		finit
		ret
	
	ret

countTheRoots endp

start:
	invoke dicsriminant, aInit, bInit, cInit
	fstp resInReal4
	finit
	invoke countTheRoots, resInReal4, aInit, bInit
	;fstp resInReal4
	cMacro
	;getRes
end start
