#-------------------------------------------------------------------------------
# lcrand.s
#
# This program prompts the user for a min and max integer value and then for an
# integer number of results to produce. Finally, it asks for a number to use as
# a random number seed. With those four values properly entered, it loops
# generating a series of random numbers that fit between the min and max values
# previously entered, using the Linear Congruence algorithm.
#
# This is intended to be the first project in Assembly Language written by
# students in CS200 at NAU as an introduction to the language. It does not
# require the use of subroutines or other advanced techniques.
#
# Author: Manish pratap choudhary (mc4323)
# Date:4 04/12/2024
#
# Revision Log
#-------------------------------------------------------------------------------
# 10/02/2023 - Created Skeleton for student use
#-------------------------------------------------------------------------------
.data
# constants
Multiplier: .word 1073807359 # a sufficiently large prime
# You probably have enough registers that you won't need variables.
# However, if you do wish to have named variables, do it here.
# Word Variables First
# HalfWord Variables Next
# Byte Variables Last (Strings and characters are Byte data)
# common strings
minPrompt: .asciiz "Enter the smallest number acceptable (0<=n<=998): "
maxPrompt: .asciiz "Enter the biggest number acceptable ( n <= 1000): "
qtyPrompt: .asciiz "How many randoms do you want (5 - 100)? "
rsdPrompt: .asciiz "Enter a seed number (1073741824 - 2147483646): "
smErr1: .asciiz "That number is too small, try again: "
smErr2: .asciiz "The max cannot be less than the min, try again: "
bgErr: .asciiz "That number is too large, try again: "
outStr: .asciiz "Here is the series of randoms:\n"
newLine: .asciiz "\n"
.text
.globl main
#-------------------------------------------------------------------------------
# The start: entry point from the MIPS file is encompassed in the kernel code
# of the QTSPIM simulator. This version starts with main: which does everything
# in this simple program.
#-------------------------------------------------------------------------------
main: # start of the main procedure

# Prompt for the minimum result and get the value
min_input:
    li      $v0, 4                  # syscall to print string
    la      $a0, minPrompt          # load address of minPrompt
    syscall

    li      $v0, 5                  # syscall to read integer
    syscall                         # read integer
    move    $t0, $v0                # save the input in $t0
    
    # Check if the input is within the valid range
    blt     $t0, 0, min_input_error # if input < 0, go to error
    bgt     $t0, 998, min_input_error # if input > 998, go to error

# Prompt for the maximum result and get the value
max_input:
    li      $v0, 4                  # syscall to print string
    la      $a0, maxPrompt          # load address of maxPrompt
    syscall

    li      $v0, 5                  # syscall to read integer
    syscall                         # read integer
    move    $t1, $v0                # save the input in $t1

    # Check if the input is within the valid range and greater than minimum
    blt     $t1, $t0, max_input_error # if input < min, go to error
    bgt     $t1, 1000, max_input_error # if input > 1000, go to error

# Prompt for the number of randoms to generate
qty_input:
    li      $v0, 4                  # syscall to print string
    la      $a0, qtyPrompt          # load address of qtyPrompt
    syscall

    li      $v0, 5                  # syscall to read integer
    syscall                         # read integer
    move    $t2, $v0                # save the input in $t2

    # Check if the input is within the valid range
    blt     $t2, 5, qty_input_error # if input < 5, go to error
    bgt     $t2, 100, qty_input_error # if input > 100, go to error

# Prompt for the seed number
seed_input:
    li      $v0, 4                  # syscall to print string
    la      $a0, rsdPrompt          # load address of rsdPrompt
    syscall

    li      $v0, 5                  # syscall to read integer
    syscall                         # read integer
    move    $t3, $v0                # save the input in $t3

    # Check if the input is within the valid range
    blt     $t3, 1073741823, seed_input_error # if input < 1073741823, go to error
    bgt     $t3, 2147483646, seed_input_error # if input > 2147483646, go to error

    # Output the series of random numbers
    li      $v0, 4                  # syscall to print string
    la      $a0, outStr             # load address of outStr
    syscall

    # Calculate the range
    sub     $t4, $t1, $t0           # $t4 = max - min
    addi    $t4, $t4, 1             # $t4 = max - min + 1

    # Initialize loop counter
    move    $t5, $t2                # $t5 = number of randoms

random_loop:
    # Generate a random
    lw      $t7, Multiplier       # Load Multiplier value into $t4
    mulu    $t3, $t3, $t7         # Multiply seed by Multiplier
    mflo    $t3
    mfhi    $t6                      # $t6 = high part of result (random)
    move    $t3, $t6                 # $t3 = high part of result (new seed)

    # Range fit the random for output
    div     $t6, $t4                # $t6 = random / range
    mfhi    $t6                      # $t6 = random % range
    add     $t6, $t6, $t0            # $t6 = random % range + min

    # Print out the result
    li      $v0, 1                  # syscall to print integer
    la    $a0, 0($t6)                # load random number to print
    syscall

    # Print a newline
    li      $v0, 4                  # syscall to print string
    la      $a0, newLine            # load address of newLine
    syscall

    # Decrement loop counter
    subi    $t5, $t5, 1             # decrement loop counter

    # Repeat loop if loop counter > 0
    bgtz    $t5, random_loop        # if $t5 > 0, repeat loop

exit_program:
    # Exit program
    li      $v0, 10                 # syscall to exit program
    syscall

min_input_error:
    # Print error message for min input
    li      $v0, 4                  # syscall to print string
    la      $a0, smErr1             # load address of smErr1
    syscall
    j       min_input                # jump back to prompt for min input

max_input_error:
    # Print error message for max input
    li      $v0, 4                  # syscall to print string
    la      $a0, smErr2             # load address of smErr2
    syscall
    j       max_input                # jump back to prompt for max input

qty_input_error:
    # Print error message for quantity input
    li      $v0, 4                  # syscall to print string
    la      $a0, qtyPrompt          # load address of qtyPrompt
    syscall
    j       qty_input                # jump back to prompt for quantity input

seed_input_error:
    # Print error message for seed input
    li      $v0, 4                  # syscall to print string
    la      $a0, bgErr              # load address of bgErr
    syscall
    j       seed_input               # jump back to prompt for seed input
