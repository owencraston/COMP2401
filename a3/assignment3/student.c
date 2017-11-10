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
    // char *tele = s.telephone;

    //get the info from the student
    int gpa = s.student.gpa;
    int numCourses = s.student.numCourses;
    float tuitionFees = s.student.tuitionFees;

    //print the student info...

    // //set a var as the full name and print it
    char fullName[33];
    //format fullname
    sprintf(fullName, "%s %s", firstName, familyName);
    //print extra info
    printf("%-33s GPA: %2d, Courses: %2d, Tuition: %8.2f\n", fullName, gpa, numCourses, tuitionFees);
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
void searchByFamilyName(struct person *person, int arraySize) {
    //create var to store 
    char input[45];
    printf("Input the last name of the person you wish to find:"); //print message to users
    scanf("%s[^\n]\n", input); //get input
    //create pointer
    struct person *s;
    for(int i = 0; i < arraySize; i++) {
        //increment the pointer
        s = person + i;
        //check if the person is a student and if the names match
        if(s->emplyeeOrStudent == 1 && strcmp(s->familyName, input) == 0) {
            //print the students info
            printStudent(*s);
        }
    }
}