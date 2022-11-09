; Набор команд для версии процессора .386 (может быть .486, .586 и тд)
.386

;.model flat показывает, в какой среде будет работать программа. 
; Все программы работают под управлением операционной системы, которая их запускает и обеспечивает 
; взаимодействие с внешней средой. Директива .model задаёт модель памяти flat (плоская или сплошная)
; для нашей программы.
; Stdcall - это "уговор" о том, кто будет чистить параметры (функция, которую вызвали, или сам вызывающий).
; Stdcall говорит, что функция сама будет чистить параметры
.model flat, stdcall
; Говорим ассемблеру, что нам важен регистр
option casemap: none 

; Библиотеки и конфигурационные файлы для работы с WinApi
include windows.inc
include user32.inc
include kernel32.inc
include debug.inc

includelib user32.lib
includelib kernel32.lib
; Библиотека для "дебага", с помощью которой, можно легко выводить на экран значения
includelib debug.lib 

.const 
        ; Основная переменная, которая посылается в процедуру factorial для вычисления факториала
        mainVariable dword 19

.code
; Процедура, которая считает факториал числа n. Результат сохраняет в регистре eax
; Что такое процедуры - https://prog-cpp.ru/asm-proc/
; Для процедур важно знать, что такое стек - https://assembler-code.com/stek-v-assemblere-push-i-pop/
; А также, что такое прототипы - 
; https://learn.microsoft.com/ru-ru/cpp/assembler/masm/proto?view=msvc-160&viewFallbackFrom=vs-2019
factorial proc n :dword
        ; Локальная переменная (можно создать только в процедурах)
        local var: dword
        mov var, 1

        mov eax, 1
        ; Если n = 0, то факториал нуля - это единица
        .if n == 0
                ret
        .endif
        
        ; Регистр ECX (Extended Counter Register) - счётчик, который часто используют для циклов
        mov ecx, n
        ; Секция mainLoop - по моей реализации является циклом
        mainLoop:
                ; Про mul (multiply - умножение) можно прочитать здесь - 
                ; http://www.av-assembler.ru/instructions/mul.php
                mul var
                inc var
                dec ecx
                ; jne - условный переход, если флаг zf != 0. Флаги меняются каждый раз, когда происходят
                ; математические опреации (в данном случае dec (декримент - в C++ это --)) 
                jne mainLoop
        ; По сути это всё равно следующему
        ; for (int cx = n; cx > 0; cx--) {
        ;       ax *= var++;
        ; } 
        ; Или такой же аналог с while (он кстати есть встроенный в masm32 (для этого надо установить
        ; процессор .686, но это читы, так что сделал по старинке)
        ret                
factorial endp

; Секция start, в которой выполняется основной наш код
start:
        ; Что такое директива inovke - https://studfile.net/preview/1869264/page:57/
        invoke factorial, mainVariable
        ; Макрос для вывода decimal значений в окно
        ; Что такое макроопределения и макросы - https://prog-cpp.ru/asm-macro/
        PrintDec eax
end start