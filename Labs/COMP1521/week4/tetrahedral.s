# Read a number n and print the first n tetrahedral numbers
# https://en.wikipedia.org/wiki/Tetrahedral_number

main:                  # int main(void) {

    la   $a0, prompt   # printf("Enter how many: ");
    li   $v0, 4
    syscall

    li   $v0, 5         # scanf("%d", number);
    syscall
    move $t0, $v0       #moving scanned value into t0
    li $t1, 1           #defining n, t1

loop1:
    bgt $t1, $t0, end
    li $t2, 0       #defining total, t2
    li $t3, 1       #defining j, t3

loop2:
    bgt $t3, $t1, printing
    li $t4, 1          #defining i, t4

loop3:
    bgt $t4, $t3, jplus
    addu $t2, $t2, $t4
    addi $t4, $t4, 1
    j loop3

jplus:
    addi $t3, $t3, 1
    j loop2
    
printing:
    move $a0, $t2
    li $v0, 1
    syscall

    li   $a0, '\n'      # printf("%c", '\n');
    li   $v0, 11
    syscall

    addi $t1, $t1, 1
    j loop1

end:
    li $v0, 0
    jr $ra
    .data
prompt:
    .asciiz "Enter how many: "
