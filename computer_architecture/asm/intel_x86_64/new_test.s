section .data
    num1 dd 10         ; First number
    num2 dd 20         ; Second number
    result dd 0        ; Variable to store the result

    msg db 'Result: ', 0

section .text
    global _start

_start:
    ; Load the first number into the eax register
    mov eax, [num1]

    ; Add the second number to the eax register
    add eax, [num2]

    ; Store the result in the result variable
    mov [result], eax

    ; Print the message
    mov rax, 1          ; System call number for write
    mov rdi, 1          ; File descriptor (stdout)
    mov rsi, msg        ; Pointer to the message
    mov rdx, 8          ; Length of the message
    syscall

    ; Print the result
    mov rax, 1          ; System call number for write
    mov rdi, 1          ; File descriptor (stdout)
    mov rsi, [result]   ; Pointer to the result variable
    mov rdx, 4          ; Length of the result (assuming a 32-bit integer)
    syscall

    ; Exit the program
    mov rax, 60         ; System call number for exit
    xor rdi, rdi        ; Exit code 0
    syscall

