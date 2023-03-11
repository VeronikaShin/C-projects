# C-projects
my short projects on C

used only stdio.h

pong.c
To display the graphics, only use ASCII characters (with output
to the terminal). I need to implement the step-by-step
version and using the standard library.


Keys:

A/Z and K/M - to move the rackets;
Space Bar - to skip an action at a certain step of the game in step-by-step mode.

Graphics

The field is a 80 x 25-symbol rectangle.
Racket size is 3 symbols;
Ball size is 1 symbol.

UI/UX

When one of the players scores 21 points, congratulations to the winner are displayed on the screen and the game ends

maxmin.c 
finds max and min out of 3 integer numbers and displays them on the screen

squaring.c
receives an array of integers via stdin, squares them and outputs the result to stdout. In case of incorrect input, you must output n/a. 

stat.c 
receives an array of integers via stdin, displays it, calculates and displays on the new line a set
of statistical metrics – maxima and minima, the expected value, and variance, assuming that we are dealing with a discrete uniform distribution

search.c
The program has to receive an array of integers via stdin and find the first occurrence of number that meets the following requirements in that array: even number, equal to or above the expected value, follows the three-sigma rule, does not equal 0. The number it finds must be output to stdout. If such number does not exist, the program must output 0. The maximum number of numbers entered is 30

sort.c
the program expects an stdin array with the length of 10 integers for input and outputs the same array sorted in ascending order. 
was used bubble sort and dynamic array. 

matrix.c
Matrix memory allocation must be implemented in
4 types: one static and 3 dynamic ones. For static memory allocation, the
maximum size of the matrix does not exceed 100 x 100. To select the method
of memory allocation in the program, you need to implement the menu with
subparagraphs 1–4. The size of the matrix (first the number of rows, then the columns) is taken from two numbers in stdin
right before its input. 
