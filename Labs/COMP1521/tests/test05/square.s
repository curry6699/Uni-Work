main:
    li   $v0, 5         #   scanf("%d", &x);
    syscall             #
    move $t0, $v0

    li   $t1, 0         # t1 = i
loop1:

    bge  $t1, $t0, end
    li   $t2, 0         # t2 = j

loop2:

    bge  $t2, $t0, inci

    li   $a0, '*'      #   printf("%c", '\n');
    li   $v0, 11
    syscall

    addi $t2, $t2, 1
    j loop2

inci:
    addi $t1, $t1, 1
    li   $a0, '\n'      #   printf("%c", '\n');
    li   $v0, 11
    syscall
    j loop1

end:

    li   $v0, 0         # return 0
    jr   $ra