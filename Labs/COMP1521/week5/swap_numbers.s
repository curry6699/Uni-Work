# read 10 numbers into an array
# swap any pairs of of number which are out of order
# then print the 10 numbers

# i in register $t0,
# registers $t1 - $t3 used to hold temporary results

main:

    li   $t0, 0         # i = 0
loop:
    bge  $t0, 10, izero  # while (i < 10) {

    li   $v0, 5         #   scanf("%d", &numbers[i]);
    syscall             #

    mul  $t1, $t0, 4    #   calculate &numbers[i]
    la   $t2, numbers   #
    add  $t3, $t1, $t2  #
    sw   $v0, ($t3)     #   store entered number in array

    addi $t0, $t0, 1    #   i++;
    j    loop          # }
izero:

    li   $t0, 0         # i = 0

loop1:
    bge  $t0, 10, izeroa  # while (i < 10) {

    mul  $t2, $t0, 4    #   calculate &numbers[i], t1 = x
    lw $t1, numbers($t2)    # x = numbers[i]
    li $t4, 1               #defining new variable, offset
    sub $t4, $t0, $t4       # t4 = i - offset
    mul $t4, $t4, 4         #t4 = t4*offset
    lw $t3, numbers($t4)    #t3 = y, y = numbers[$t4]

    bge $t1, $t3, increment     #if (t3 > t1) go to
    sw $t3, numbers($t2)    # numbers[i] = y
    sw $t1, numbers($t4)    # numbers[offset/i] = x

increment:
    addi $t0, $t0, 1
    j loop1

izeroa:
    li $t0, 0       # make i 0

loop2:
    bge $t0, 10, end       #while condition

    mul $t1, $t0, 4     # t1 = i * 4
    la   $t2, numbers   # setup array
    add  $t3, $t1, $t2  # t3 = offset + array start
    lw   $a0, ($t3)     #   load numbers[i] into $a0
    li   $v0, 1         #   printf("%d", numbers[i])
    syscall
    li   $a0, '\n'      #   printf("%c", '\n');
    li   $v0, 11
    syscall
    addi $t0, $t0, 1    #   i++
    j    loop2       # }

end:
    li   $v0, 0
    jr   $ra            # return 0

.data

numbers:
    .word 0 0 0 0 0 0 0 0 0 0  # int numbers[10] = {0};

