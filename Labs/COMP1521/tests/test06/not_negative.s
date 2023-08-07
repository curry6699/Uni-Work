#  read numbers until a non-negative number entered
# x in $t0
main:
loop:
    la   $a0, str0       # printf("Enter a number: ");
    li   $v0, 4
    syscall

    li   $v0, 5          # scanf("%d", &x);
    syscall              #
    move $t0, $v0

    blt $t0, 0, pos

    la   $a0, str1       # printf("You entered: ");
    li   $v0, 4
    syscall
    move $a0, $t0        # printf("%d", x);
    li   $v0, 1
    syscall
    li   $a0, '\n'       # printf("%c", '\n');
    li   $v0, 11
    syscall
    li   $v0, 0          # return 0
    jr   $ra


pos:
    la   $a0, positive       # printf("You entered: ");
    li   $v0, 4
    syscall

    li   $a0, '\n'       # printf("%c", '\n');
    li   $v0, 11
    syscall

    j loop

.data
str0:
    .asciiz "Enter a number: "
str1:
    .asciiz "You entered: "
positive:
    .asciiz "Enter a positive number "
