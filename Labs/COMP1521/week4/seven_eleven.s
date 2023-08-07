# Read a number and print positive multiples of 7 or 11 < n

main:                  # int main(void) {

    la   $a0, prompt   # printf("Enter a number: ");
    li   $v0, 4
    syscall

    li   $v0, 5         # scanf("%d", number);
    syscall
    li $t1, 1          #defining i
    move $t0, $v0

loop:
    
    bgeu $t1, $t0 end

    rem $t2, $t1, 7
    bne $t2, 0, eleven
    
    move $a0, $t1    
    li $v0, 1
    syscall

    li   $a0, '\n'    # printf("%c", '\n');
    li   $v0, 11
    syscall

    addi $t1, $t1, 1
    j loop

eleven:
    rem $t2, $t1, 11
    bne $t2, 0, add_one

    move $a0, $t1    
    li $v0, 1
    syscall

    li   $a0, '\n'    # printf("%c", '\n');
    li   $v0, 11
    syscall

    addi $t1, $t1, 1
    j loop

add_one:
   addi $t1, $t1, 1
   j loop 

end:
    li $v0, 0
    jr   $ra           # return

    .data
prompt:
    .asciiz "Enter a number: "
