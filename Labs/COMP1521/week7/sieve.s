# Sieve of Eratosthenes
# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

main:

 li $t8, 0           # i = t8
loop:
    # PUT YOUR CODE

    bge $t8, 1000, init_i   # if i >= 1000 jump to second_while
   
    li $t0, 1
    sb $t0, prime($t8)
    addi $t8, $t8, 1

    j loop


init_i:
    li $t8, 2           # i = 2

second_while:
    bge $t8, 1000, end

    lb $t0, prime($t8)  # t0 = prime[i]

    bne $t0, 1, increment

	move $a0, $t8		# a0 = i
	li	$v0, 1        	# printf("%d")
    syscall

    li 	$a0, '\n'    	# printf("%c", '\n');
    li  $v0, 11
    syscall

    li $t6, 2
    mul $t7, $t8, $t6   # t7: j = i * 2

third_while:
    bge $t7, 1000, increment

    li $t1, 0
    sb $t1, prime($t7)

    add $t7, $t7, $t8

    j third_while

increment:
    addi $t8, $t8, 1


    j second_while

end:

    li $v0, 0           # return 0
    jr $ra

.data
prime:
    .space 1000