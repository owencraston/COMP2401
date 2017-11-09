

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "populateRecords.h"
#include "menu.h"
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

        switch(choice){
            
            case 0:
                //stop the loop by setting the value of quit to true
                checkQuit = quit();
                if (checkQuit == 1) {
                    running = 1;
                }
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
		printf("0, Quit\n");

		//get users input
		printf("Input your pick:");
		scanf("%d", &choice);

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
    float numRecords = 0;
    float numStudents = 0;
    float avgGpa = 0;
    float avgNumCourses = 0;
    float avgTuition = 0;
    float numEmployees = 0;
    float minLevel = 15; //set at max
    float maxLevel = 0; //set at min
    float avgYOS = 0;
    float avgSalary = 0;


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
            avgGpa += p[i].student.gpa;
            //average number of courses
            avgNumCourses += p[i].student.numCourses;
            //average tuition
            avgTuition += p[i].student.tuitionFees;
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
            avgYOS += p[i].employee.yearsService;
            //increment the salary
            avgSalary += p[i].employee.salary;
        }
    }

    //calculate averages
    //students
    avgGpa = avgGpa/numStudents;
    avgNumCourses = avgNumCourses/numStudents;
    avgTuition = avgTuition/numStudents;
    //employee
    avgYOS = avgYOS/numEmployees;
    avgSalary = avgSalary/numEmployees;

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
    int quit = 0;
    while (quit = 0) {
        //inform the user
        printf("are you sure you want to quit the program? Type y/n to proceed\n");
        scanf("%s[^\n]\n", yn);//get input
        
        //check input
        if (yn == "y") {
            printf("thank you.\n");
            quit = 0;
            return 1;
        } else if (yn == "n") {
            quit = 0;
            return 0;
        } else {
            // try again
            printf("invalid input. Try again\n");
        }
    }
}

