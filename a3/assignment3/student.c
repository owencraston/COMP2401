//all the function related to the student will go in here
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "struct.h"

#include "student.h"
#include "struct.h"

//create singular print function for a student
void printStudent(struct person s) {
    //get the info from the person struct
    char *firstName = s.firstName;
    char *familyName = s.familyName;
    char *tele = s.telephone;

    //get the info from the student
    int gpa = s.student.gpa;
    int numCourses = s.student.numCourses;
    float tuitionFees = s.student.tuitionFees;

    //print the student info...

    //set a var as the full name and print it
    char fullName[33];
    sprintf(fullName, "%s %s", firstName, familyName);

    //print extra info
    printf("Tele: %-10s,  GPA: %-10d, numCourses: %-10d, tuition: %-10f, \n", fullName, tele, gpa, numCourses, tuitionFees);
}
//print all students function
void printAllStudents(struct person s[], int arraySize) {
    //iterate through students array
    for (int i=0; i < arraySize; i++) {
        //check if the person is a student
        if (s[i].emplyeeOrStudent == 1) {
            //call print function on that student
            printStudent(s[i]);
        }
    }
    // signify the end of function call
    printf("Done!\n");
}

//search/print by family name
void searchByFamilyName(struct person *s, int arraySize) {
    //get the family name from input
    char lastName[20]; //create var to hold the users input
    printf("Input the last name of the person you wish to find:");//print message to users
    scanf("%s[^\n]\n", lastName);//get input
    //create pointer
    struct person *stu;
    for (int i=0; i<arraySize; i++) {
        //increment the pointer
        stu = s + i;
        //check if the person is a student
        if (s->emplyeeOrStudent == 1) {
            //check if the student is the specified student
            if(s->familyName == lastName) {
                //print students info
                printStudent(*s);
            } else {
                printf("no student matched the specified name\n");
            }
        }
    }

}