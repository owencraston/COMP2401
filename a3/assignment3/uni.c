

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "populateRecords.h"
#include "student.h"
#include "employee.h"

#define NUM_RECORDS 20

void summary(struct person p[], int arraySize);

int main()
{
    struct person person[NUM_RECORDS];


    populateRecords(person, NUM_RECORDS);

    //switch statement for users options
    int choice;
    int checkQuit;
    unsigned int running = 0;

    while (running == 0) {
        //get the value from the menu function
        choice = menu();
        unsigned int check;

        switch(choice){
            
            case 0:
                running = quit();
                break;
            case 1:
                // call the printAllEmployees function
                printAllEmployees(person, NUM_RECORDS);
                break;
            case 2:
                //call the printAllStudents function
                printAllStudents(person, NUM_RECORDS);
                break;
            case 3:
                //call the searchByFamilyName function
                searchByFamilyName(person, NUM_RECORDS);
                break;
            case 4:
                // call the summary function
                summary(person, NUM_RECORDS);
                break;
        }
    }
        
    return 0;
}

int menu() {
	int choice;
	unsigned int quit = 0;
	while(quit == 0) {
		printf("\n");
		printf("1, print all employees. \n");		
		printf("2, print all student. \n");
		printf("3, search students using family name. \n");
		printf("4, summary of data. \n");
        printf("0, Quit");
        printf("\n");

		//get users input
		printf("Input your pick:");
		scanf("%d[^\n]\n", &choice);

		//verify the response from the user
		if (choice <= 4 && choice >= 0) {
			//end loop
			quit = 1;
		} else {
			//the input was invalid so try again
			printf("Your input was invalid. Please input an integer between 0-4.\n");
        }
    }
	//returnt the chosen option
    return choice;
}


void summary(struct person p[], int arraySize) {
    //create variables to store the summary values
    int numRecords = 0;
    int numStudents = 0;
    int totalGpa = 0;
    int totalNumCourses = 0;
    int totalTuition = 0;
    int numEmployees = 0;
    int minLevel = 15; //set at max
    int maxLevel = 0; //set at min
    int totalYOS = 0;
    int totalSalary = 0;


    //iterate throught the array and get the values
    for (int i=0; i<arraySize; i++) {
        //increment the numRecord var
        numRecords ++;
        // check if the person is a student
        if (p[i].emplyeeOrStudent == 1) {
            //calculate all the student related attributes
            //increment the number of students
            numStudents ++;
            //gpa
            totalGpa += p[i].student.gpa;
            //average number of courses
            totalNumCourses += p[i].student.numCourses;
            //average tuition
            totalTuition += p[i].student.tuitionFees;
        } else if (p[i].emplyeeOrStudent == 0) {
            //calculate all the values related to the employee
            //increment the number of employees
            numEmployees ++;
            // check if this is employee is the max level
            if (p[i].employee.level > maxLevel) {
                //set this value as the new max
                maxLevel = p[i].employee.level;
            }
            //check if this employee is the min level
            if (p[i].employee.level < minLevel) {
                //set this value as the new min level
                minLevel = p[i].employee.level;
            }
            //increment the years of service
            totalYOS += p[i].employee.yearsService;
            //increment the salary
            totalSalary += p[i].employee.salary;
        }
    }

    //calculate averages
    //students
    float avgGpa = avgGpa/numStudents;
    float avgNumCourses = avgNumCourses/numStudents;
    float avgTuition = avgTuition/numStudents;
    //employee
    float avgYOS = avgYOS/numEmployees;
    float avgSalary = avgSalary/numEmployees;

    //print the results
    printf("Output:\n");
    printf("Total number of records: %d\n", numRecords);
	printf("Student Stats:\n");
	printf("Number of Students: %d\n", numStudents);
	printf("Average GPA:  %.2f", avgGpa);
	printf(", Average Number of courses:  %.2f", avgNumCourses);
    printf(", Average Tutition Fees: %.2f\n", avgTuition);
    // employee
    printf("Employees' Stats:\n");
	printf("Number of Employees: %d\n", numEmployees);
	printf("Max Level: %d", maxLevel);
	printf(", Min Level: %d\n", minLevel);
	printf("Average Years of Service:  %.2f", avgYOS);
	printf(", Average Salary:  %.2f\n\n", avgSalary);
}

int quit() {
    char yn[3]; //make var to store user input
    printf("are you sure you want to quit the program? Type y/n to proceed\n");
    scanf("%s", &yn); //get input

    if(strcmp(yn, "y")== 0) {
        return 0;
    } else {
        return 1;
    }
}

