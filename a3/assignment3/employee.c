//all the function related to the employee will go in here
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "struct.h"

#include "employee.h"
#include "struct.h"

//create singular print function for an employee
void printEmployee(struct person e) {
    //get the info from the person struct
    char *firstName = e.firstName;
    char *familyName = e.familyName;
    char *tele = e.telephone;

    //get the info from the employee
    int level = e.employee.level;
    int yearsService = e.employee.yearsService;
    float salary = e.employee.salary;

    //print the employee info...

    //set a var as the full name and print it
    char fullName[100];
    sprintf(fullName, "%s %s", firstName, familyName);

    //print extra info
    printf("Tele: %-10s,  Level: %-10d, yearsService: %-10d, salary: %-10f, \n", fullName, tele, level, yearsService, salary);
}
//print all employees function
void printAllEmployees(struct person e[], int arraySize) {
    //iterate through employees array
    for (int i=0; i < arraySize; i++) {
        //check if the person is an employee
        if (e[i].emplyeeOrStudent == 0) {
            //call print function on that employee
            printEmployee(e[i]);
        }
    }
    // signify the end of function call
    printf("Done!\n");
}