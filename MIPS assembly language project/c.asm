.data
inputMessage: .asciiz "Enter a number (1 - 20): "
errorMessage1: .asciiz "Number must be > 0, try again.\n"
errorMessage2: .asciiz "Number must be < 21, try again.\n"
outputMessage: .asciiz "The fibonacci value is: "

.text
.globl main
main:
    addiu   $sp, $sp, -20       # allocate stack space for main
    sw      $fp, 0($sp)         # save original $fp
    sw      $ra, 4($sp)         # save $ra
    addiu   $fp, $sp, 16        # set new frame pointer

    li      $t0, -1              # initialize number to -1
    sw      $t0, 8($fp)         # store number on stack

while:
    lw      $t0, 8($fp)         # load number
    li      $t1, 1               # load 1
    blt     $t0, $t1, lessThan1 # if number < 1, jump to lessThan1
    li      $t1, 20              # load 20
    bgt     $t0, $t1, greaterThan20 # if number > 20, jump to greaterThan20
    j       endWhile            # else, jump to endWhile

lessThan1:
    la      $a0, errorMessage1  # load error message 1
    li      $v0, 4               # print string
    syscall
    j       while               # jump back to while

greaterThan20:
    la      $a0, errorMessage2  # load error message 2
    li      $v0, 4               # print string
    syscall
    j       while               # jump back to while

endWhile:
    la      $a0, inputMessage   # load input message
    li      $v0, 4               # print string
    syscall
    li      $v0, 5               # read integer
    syscall
    sw      $v0, 8($fp)         # store input number

    lw      $t0, 8($fp)         # load number
    move    $a0, $t0            # move number to $a0
    jal     fib                 # call fib function

    la      $a0, outputMessage  # load output message
    li      $v0, 4               # print string
    syscall
    move    $a0, $v0            # move result to $a0
    li      $v0, 1               # print integer
    syscall

    lw      $fp, 0($sp)         # restore $fp
    lw      $ra, 4($sp)         # restore $ra
    addiu   $sp, $sp, 20        # deallocate stack space
    jr      $ra                 # return

fib:
    addiu   $sp, $sp, -20       # allocate stack space for fib
    sw      $fp, 0($sp)         # save $fp
    sw      $ra, 4($sp)         # save $ra
    addiu   $fp, $sp, 16        # set new frame pointer

    sw      $a0, 8($fp)         # store n on stack

    lw      $t0, 8($fp)         # load n
    li      $t1, 2               # load 2
    blt     $t0, $t1, lessThan2  # if n < 2, jump to lessThan2

    lw      $t0, 8($fp)         # load n
    addiu   $t1, $t0, -2        # n - 2
    move    $a0, $t1            # move n - 2 to $a0
    jal     fib                 # recursive call to fib

    move    $t2, $v0            # save result of fib(n-2) in $t2

    lw      $t0, 8($fp)         # load n
    addiu   $t1, $t0, -1        # n - 1
    move    $a0, $t1            # move n - 1 to $a0
    jal     fib                 # recursive call to fib

    add     $v0, $t2, $v0       #calculate result = fib(n-2) + fib(n-1)

    lw      $fp, 0($sp)         # restore $fp
    lw      $ra, 4($sp)         # restore $ra
    addiu   $sp, $sp, 20        # deallocate stack space
    jr      $ra                 # return

lessThan2:
    lw      $t0, 8($fp)         # load n
    move    $t1, $t0           # move n to $t1
    li      $t2, 1              # load 1
    add     $t1, $t1, $t2      # n + 1
    move    $v0, $t1            # result = n + 1

    lw      $fp, 0($sp)         # restore $fp
    lw      $ra, 4($sp)         # restore $ra
    addiu   $sp, $sp, 20        # deallocate stack space
    jr      $ra