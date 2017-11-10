John-Owen Craston
student #: 101037159
Date: November 9th 2017

Purpose: the purpose of this software is to be abel to observer and manage aa student/employee "database"
Organisation: This program is organised into seperate files with each file containg seperate logic for functions related to that file
example: all the functions rlated to student are contained in the studen.c file and similarly for the employee. Functions that are common between
both stdents and employees are stored in the uni.c file. Structures, functions and values that need to be shared across fils are included in the header
file for each type of file. An example of this is the struct.h file which allows us to create the structures for ths program and share them across the entire
program. functions related to the employee and student are listed in their respective header files.

Instructions:
to compile: "gcc -o uni uni.c student.c employee.c populateRecords.c"
To run: (use the output file) "./uni"

This program has 4 options. when you run the program the options will be ...
1, print all employees.		
2, print all student.
3, search students using family name.
4, summary of data.
0, Quit

type the answer in the terminal and the program will execute, performing the actiosn they describe

If you type 0, it will prommt you to quit and quit by typeing y or n. y will quit the proram and n will stop it from quitting

issues/limitations: A limitation of this program is that names can not be more than 15 chars.

