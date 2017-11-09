#ifndef _struct_h
#define _struct_h
/* 1.1 create student structure
    student requires
    - gpa
    - numCouses
    - tuttions fees
*/

struct student {
    unsigned int gpa:4;
	unsigned int numCourses:6;
	float tuitionFees;
};

/* 1.2 create employee structure
    employee requires
    - salary
    - yearsService
    - level
*/

struct employee {
    unsigned int level:4;
	unsigned int yearsService:6;
	float salary;
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
#define TELEPHONE_SIZE 11

struct person {
    char *firstName[NAME_SIZE];
	char *familyName[NAME_SIZE];
	char *telephone[TELEPHONE_SIZE];
	unsigned int emplyeeOrStudent:1;
    union {
        struct student student;
        struct employee employee;
    };
};

#endif