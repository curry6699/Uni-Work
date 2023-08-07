# Read 10 numbers into an array
# print 0 if they are in non-decreasing order
# print 1 otherwise

# i in register $t0

main:

    li   $t0, 0         # i = 0
loop_1:
    bge  $t0, 10, definingiswap  # while (i < 10) {

    li   $v0, 5         #   scanf("%d", &numbers[i]);
    syscall             #

    mul  $t1, $t0, 4    #   calculate &numbers[i]
    la   $t2, numbers   #
    add  $t3, $t1, $t2  #
    sw   $v0, ($t3)     #   store entered number in array

    addi $t0, $t0, 1    #   i++;
    j    loop_1          # }

definingiswap:
    li $t0, 1       #define i = 1
    li $t5, 0       #making swap = 0  


loop:
    bge $t0, 10, end #

    mul $t2, $t0, 4
    lw $t1, numbers($t2) 

    li $t4, 1
    sub $t4, $t0, $t4
    mul $t4, $t4, 4
    lw $t3, numbers($t4)

    bge $t1, $t3, end1

    li $t5, 1

    

end1:
    addi $t0, $t0, 1
    j loop

end:
    move $a0, $t5
    li $v0, 1
    syscall
    li $a0, '\n'
    li $v0, 11
    syscall
    jr $ra
.data



numbers:
    .word 0 0 0 0 0 0 0 0 0 0  # int numbers[10] = {0};

