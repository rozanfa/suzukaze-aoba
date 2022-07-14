section .data
    congratsMsg db 'Selamat! Jawabanmu benar', 0xa
    lenCongratsMsg equ $-congratsMsg
    falseMsg db 'Sayang sekali, jawabanmu salah', 0xa
    lenFalseMsg equ $-falseMsg
    problem_file_name db 'problem.txt', 0x0
    solution_file_name db 'solution.txt', 0x0
    log_file_name db 'log.txt', 0x0
    yourAnswerMsg db 'Jawaban anda : '
    lenYourAnswerMsg equ $-yourAnswerMsg
    correctAnswerMsg db 'Jawaban yang benar : '
    lenCorrectAnswerMsg equ $-correctAnswerMsg
    newLine db 0x0a
    

section .bss
    solution resb 2
    answer resb 2
    fd_out resb 1
    fd_in  resb 1
    problem resb 10000
    log resb 10000


section .text
    global _start

readInput:
    ; Prosedur untuk membaca input dari user
    ; Panjang input 2 byte
    ; Hasil dari pembacaan disimpan di eax
    mov eax, 3  ; syscall number
    mov ebx, 2  ; file descriptor (stdin)
    mov edx, 2  ; buffer size 
    int 80h
    mov eax, [ecx]  ; copy value of input to eax
    ret

writeProblem:
    ; Prosedur untuk menuliskan soal dari
    ; problem.txt
    mov eax, 5  ; syscall number
    mov ebx, problem_file_name  ;file name
    mov ecx, 0          ;for read only access
    mov edx, 0777       ;read, write and execute by all
    int  0x80           ;call kernel
        
    mov  [fd_in], eax   
        
    ; Baca file problem
    mov eax, 3      ;syscall number
    mov ebx, [fd_in]    ;file descriptor
    mov ecx, problem    ;buffer
    mov edx, 10000  ;buffer size
    int 0x80     ;call kernel

    ; Tutup file
    mov eax, 6
    mov ebx, [fd_in]
    int  0x80    
        
    ; Print isi file problem
    mov eax, 4  ; syscall number
    mov ebx, 1  ; file descriptor (stdout)
    mov ecx, problem    ; buffer
    mov edx, 10000  ; buffer size
    int 0x80    ; call kernel

    ret


getSolution:
    ; Prosedur untuk mengambil jawaban dari
    ; solution.txt
    mov eax, 5  ; syscall number
    mov ebx, solution_file_name ;file name
    mov ecx, 0             ;for read only access
    mov edx, 0777          ;read, write and execute by all
    int  0x80           ;call kernel
        
    mov  [fd_in], eax
        
    ; Baca file solution
    mov eax, 3    ;syscall number
    mov ebx, [fd_in]    ;file descriptor
    mov ecx, solution   ;buffer
    mov edx, 10000  ;buffer size
    int 0x80    ;call kernel

    ; Tutup file
    mov eax, 6  
    mov ebx, [fd_in]
    int  0x80    
    ret


_start:
    call writeProblem   ; panggil prosedur writeProblem

    call readInput   ; panggil prosedur readInput
    mov ebx, answer  ; 
    mov [ebx], ax   ; copy input ke variabel answer

    call getSolution    ; panggil prosedur getSolution

    mov ax, [solution]  ; copy solution ke ax
    mov bx, [answer]    ; copy answer ke bx
    cmp bx, ax        ; compare bx dan ax
    jne false

true:
    ; Print ucapan selamat bila jawaban benar
    mov eax, 4
    mov ebx, 1
    mov ecx, congratsMsg
    mov edx, lenCongratsMsg
    int 80h
	jmp writeLog

false:
    ; Print pesan kesalahan bila jawaban salah
    mov eax, 4
    mov ebx, 1
    mov ecx, falseMsg
    mov edx, lenFalseMsg
    int 80h


writeLog:
    ; Buat file log
    mov eax, 8
    mov ebx, log_file_name  ;nama file  
    mov ecx, 0777        ;read, write and execute by all
    int 0x80             ;call kernel
        
    mov [fd_out], eax

    ; Tulis yourAnswerMsg
    mov	edx, lenYourAnswerMsg   ;number of bytes
    mov	ecx, yourAnswerMsg      ;message to write
    mov	ebx, [fd_out]       ;file descriptor 
    mov	eax,4               ;system call number (sys_write)
    int	0x80                ;call kernel

    ; Tulis jawaban user
    mov	edx, 2          ;number of bytes
    mov	ecx, answer     ;message to write
    mov	ebx, [fd_out]   ;file descriptor 
    mov	eax,4           ;system call number (sys_write)
    int	0x80            ;call kernel

    ; Tulis newline
    mov	edx, 1          ;number of bytes
    mov	ecx, newLine    ;message to write
    mov	ebx, [fd_out]   ;file descriptor 
    mov	eax,4           ;system call number (sys_write)
    int	0x80            ;call kernel

    ; Tulis pesan correctAnswerMsg
    mov	edx, lenCorrectAnswerMsg    ;number of bytes
    mov	ecx, correctAnswerMsg       ;message to write
    mov	ebx, [fd_out]    ;file descriptor 
    mov	eax,4            ;system call number (sys_write)
    int	0x80             ;call kernel

    ; Tulis solusi
    mov	edx, 2           ;number of bytes
    mov	ecx, solution    ;message to write
    mov	ebx, [fd_out]    ;file descriptor 
    mov	eax,4            ;system call number (sys_write)
    int	0x80             ;call kernel

    ; Tutup file
    mov eax, 6
    mov ebx, [fd_out]

exit:
    ; Exit
    mov eax, 1
    mov ebx, 0
    int 80h

