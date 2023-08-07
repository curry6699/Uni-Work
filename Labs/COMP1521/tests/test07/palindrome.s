# read a line and print whether it is a palindrom

main:
    la   $a0, str0       # printf("Enter a line of input: ");
    li   $v0, 4
    syscall

    la   $a0, line
    la   $a1, 256
    li   $v0, 8          # fgets(buffer, 256, stdin)
    syscall              #

    li $t6, 0 # t6 = i
loop:
    lb $t1, line($t6)
    beq $t1, 0, after_loop
    addi $t6, $t6, 1
    j loop

after_loop:

    li $t5, 0   # t5 = j
    addi $t4, $t6, -2 # t4 = k

loop2:
    bge $t5, $t4, print

    lb $t0, line($t5)
    lb $t1, line($t4)
    beq $t0, $t1, increment

    la   $a0, not_palindrome
    li   $v0, 4
    syscall

    li   $v0, 0          # return 0
    jr   $ra

increment:
    addi $t5, $t5, 1
    addi $t4, $t4, -1

    j loop2

print:

    la   $a0, palindrome
    li   $v0, 4
    syscall

    li   $v0, 0          # return 0
    jr   $ra


.data
str0:
    .asciiz "Enter a line of input: "
palindrome:
    .asciiz "palindrome\n"
not_palindrome:
    .asciiz "not palindrome\n"


# line of input stored here
line:
    .space 256

