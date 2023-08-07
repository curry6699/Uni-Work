# read a number n and print the integers 1..n one per line

main:                 # int main(void)
    la   $a0, prompt  # printf("Enter a number: ");
    li   $v0, 4
    syscall

    li   $v0, 5       # scanf("%d", number);
    syscall
    li $t1, 1          #defining i
    move $t0, $v0

loop:

    bgt $t1, $t0, end     #while condition

    move $a0, $t1    
    li $v0, 1
    syscall

    li   $a0, '\n'    # printf("%c", '\n');
    li   $v0, 11
    syscall

    addi $t1, $t1, 1
    j loop

end:
    li $v0, 0
    jr $ra
    .data

prompt:
    .asciiz "Enter a number: "
