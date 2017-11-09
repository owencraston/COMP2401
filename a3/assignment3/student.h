#ifndef _student_h
#define _student_h

#include "struct.h"

void printStudent(struct person s);
void printAllStudents(struct person s[], int arraySize);
void searchByFamilyName(struct person *s, int arraySize);

#endif