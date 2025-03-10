.section .data
    buffer: 
        .fill 256, 1, 0
    buffer2:
        .fill 512, 1, 0
    filename:
        .asciz "test1.txt"
    filename2:
        .asciz "test2.txt"
    message:
        .asciz "Hello world"
    newline:
        .asciz "\n"

.section .text
    .global _start

    _start: 
        ldr x0, =buffer
        mov x1, #256
        mov x8, #17
        svc#0

        mov x0, #1
        ldr x1, =buffer
        mov x2, #256
        mov x8, #64
        svc#0

        mov x0, #1
        ldr x1, =newline
        mov x2, #1
        mov x8, #64
        svc#0

        mov x0, #-100
        ldr x1, =filename
        mov x2, #1
        mov x3, #0200
        mov x8, #56
        svc#0

        mov x10, x0

        mov x0, x10
        ldr x1, =message
        mov x2, #11
        mov x8, #64
        svc#0

        mov x0, x10
        mov x8, #57
        svc#0

        mov x0, #-100
        ldr x1, =filename2
        mov x2, #0
        mov x3, #0400
        mov x8, #56
        svc#0

        mov x11, x0

        mov x0, x11
        ldr x1, =buffer2
        mov x2, #512
        mov x8, #63
        svc#0

        mov x0, #1
        ldr x1, =buffer2
        mov x2, #512
        mov x8, #64
        svc#0

        mov x0, x11
        mov x8, #57
        svc#0

        mov x0, #1
        ldr x1, =newline
        mov x2, #1
        mov x8, #64
        svc#0

        mov x0, #1
        mov x8, #93   
        svc#0        

