.data  # Data segment 
msg: .ascii "The result is "

.text  # Code segment
# Load integers into registers
li $t0, 5
li $t1, 7

# Add integers
add $t2, $t1, $t0

# Print result
li $v0, 4
la $a0, msg
syscall

li $v0, 1
move $a0, $t2
syscall

# Exit
li $v0, 10
syscall
