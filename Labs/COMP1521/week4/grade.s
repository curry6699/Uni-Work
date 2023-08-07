# read a mark and print the corresponding UNSW grade

main:
    la   $a0, prompt    # printf("Enter a mark: ");
    li   $v0, 4
    syscall

    li   $v0, 5         # scanf("%d", mark);
    syscall

    bge $v0, 85, High
    bge $v0, 75, Distinction
    bge $v0, 65, Credit
    bge $v0, 50, Pass


    la   $a0, fl        # printf("FL\n");
    li   $v0, 4
    syscall


    jr   $ra            # return



High:
    la $a0, hd
    li $v0, 4 #print High Disctintion
    syscall
    j end
Distinction:
    la $a0, dn
    li $v0, 4 #print Distinction
    syscall
    j end

Credit:
    la $a0, cr
    li $v0, 4 #print Credit
    syscall
    j end

Pass:
    la $a0, ps
    li $v0, 4 #print Pass
    syscall
    j end

end: 
    li, $v0, 0
    jr $ra
    
    .data

prompt:
    .asciiz "Enter a mark: "
fl:
    .asciiz "FL\n"
ps:
    .asciiz "PS\n"
cr:
    .asciiz "CR\n"
dn:
    .asciiz "DN\n"
hd:
    .asciiz "HD\n"
