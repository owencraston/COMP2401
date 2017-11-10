#ifndef _struct_h
#define _struct_h
/* 1.1 create student structure
    student requires
    - gpa
    - numCouses
    - tuttions fees
*/

struct student {
    float tuitionFees;
    unsigned short numCourses:6;
    unsigned short gpa:4;
    
};

/* 1.2 create employee structure
    employee requires
    - salary
    - yearsService
    - level
*/

struct employee {
   float salary;
    unsigned short yearsService:6;
    unsigned short level:4;
   
};

/*
1.3 create person structure
    person requires
    - first name
    - last name 
    - telephone
    - discriminator to determine if the person is a student or employee
    - union between student and employee record 
*/

#define NAME_SIZE 16
#define TELE_SIZE 11

struct person {
    char *firstName[NAME_SIZE];
    char *familyName[NAME_SIZE];
    char *telephone[TELE_SIZE]; // this doesnt seem to be needed anywhere but i left it in
	unsigned int emplyeeOrStudent:1;
    union {
        struct student student;
        struct employee employee;
    };
};

#endif