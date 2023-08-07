# COMP1521 21T2 ... final exam, question 2

	.data
even_parity_str:	.asciiz "the parity is even\n"
odd_parity_str:		.asciiz "the parity is odd\n"

	.text
main:
	li	$v0, 5
	syscall
	move	$t0, $v0
	# input is in $t0	# t0 = n

	# TODO
	li	$t7, 0		# t7 = bit_idx 
	li	$t6, 0		# t6 = n_bits_set


loop:
	beq $t7, 32, after_loop
	srl $t1, $t0, $t7	# t1 = bit

	li $t5, 1		# t5 = 1
	and $t1, $t1, $t5	# t1: bit = n >> bit_idx & 1

	add $t6, $t6, $t1
	addi $t7, $t7, 1

	j loop

after_loop:
	li $t5, 2		# t5 = 2

	rem $t3, $t6, $t5	# t3 = t6 % 2




	bnez $t3, print_odd

print_even:
	li	$v0, 4
	la	$a0, even_parity_str
	syscall

	j end

print_odd:
	li	$v0, 4
	la	$a0, odd_parity_str
	syscall

end: 
	li	$v0, 0
	jr	$ra
