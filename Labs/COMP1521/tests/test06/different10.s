# x in register $t0
# i in register $t1
# n_seen in register $t2
# registers $t3 and $t4 used to hold temporary results
main:

    li   $t2, 0          # n_seen = 0;

first:

    bge  $t2, 10, end    # while (n_seen < 10)

    la   $a0, string0    # printf("Enter a number: ");
    li   $v0, 4
    syscall

    li   $v0, 5          # scanf("%d", &x);
    syscall

    move $t0, $v0
    li   $t5, 0

first_loop:    
  

    bge  $t5, $t2, other_if
    mul  $t6, $t5, 4        
    lw   $t6, numbers($t6)  # numbers[i]
    beq  $t0, $t6, other_if
    addi $t5, $t5, 1
    
    j first_loop
    
other_if:
    bne  $t2, $t5, end_first

    mul  $t3, $t2, 4        # calculate &numbers[n_seen]
    sw   $t0, numbers($t3)     # numbers[n_seen] = x

    addi $t2, $t2, 1    # n_seen++;
    j first

end_first:
    j first

end:
    la   $a0, string1   # printf("10th different number was: ");
    li   $v0, 4
    syscall

    move $a0, $t0       # printf("%d", x)
    li   $v0, 1
    syscall

    li   $a0, '\n'      # printf("%c", '\n');
    li   $v0, 11
    syscall

    li   $v0, 0         # return 0
    jr   $ra

    .data

numbers:
    .space 40           # int numbers[10];

string0:
    .asciiz "Enter a number: "
string1:
    .asciiz "10th different number was: "

