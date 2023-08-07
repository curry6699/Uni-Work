# Recursive factorial function
# n < 1 yields n! = 1
# $s0 is used for n
# we use an s register because the convention is their value
# is preserved across function calls
# f is in $t0

# DO NOT CHANGE THE CODE IN MAIN

main:
    addi $sp, $sp, -8  # create stack frame
    sw   $ra, 4($sp)   # save return address
    sw   $s0, 0($sp)   # save $s0

    li   $s0, 0
    la   $a0, msg1
    li   $v0, 4
    syscall            # printf(Enter n: ")

    li    $v0, 5
    syscall            # scanf("%d", &n)
    move  $s0, $v0

    move  $a0, $s0     # factorial(n)
    jal   factorial    #
    move  $t0, $v0     #

    move  $a0, $s0
    li    $v0, 1
    syscall            # printf ("%d", n)

    la    $a0, msg2
    li    $v0, 4
    syscall            # printf("! = ")

    move  $a0, $t0
    li    $v0, 1
    syscall            # printf ("%d", f)

    li   $a0, '\n'     # printf("%c", '\n');
    li   $v0, 11
    syscall

                       # clean up stack frame
    lw   $s0, 0($sp)   # restore $s0
    lw   $ra, 4($sp)   # restore $ra
    addi $sp, $sp, 8   # restore sp

    li  $v0, 0         # return 0
    jr  $ra

    .data
msg1:   .asciiz "Enter n: "
msg2:   .asciiz "! = "


# DO NOT CHANGE CODE ABOVE HERE


    .text
factorial:
    #  ADD CODE TO CREATE STACK FRAME
    addi $sp, $sp, -12  # create stack frame
    sw   $ra, 8($sp)   # save return address
    sw   $s1, 4($sp)   # save $s0
    sw   $s0,  ($sp)

    # ADD CODE FORFUNCTION HERE

    move $s0, $a0       # s0 = n

    li $t1, 1

    bgt $s0, $t1, recurse # if t0 > t1 jump to recurse c: n > 1
    ble $s0, $t1, return_one    # else
    j end

recurse:    
    addi $a0, $a0, -1
    jal factorial
    move $s1, $v0       # s1 = output
    mul $t6, $s0, $s1

    j end

return_one:
    li $t6, 1           # result = 6

end:
    # ADD CODE TO REMOVE STACK FRAME
    lw   $s0,   ($sp)
    lw   $s1, 4($sp)   # restore $s0
    lw   $ra, 8($sp)   # restore $ra
    addi $sp, $sp, 12   # restore sp

    move $v0, $t6
    jr  $ra
