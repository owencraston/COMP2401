

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "populateRecords.h"
#include "student.h"
#include "employee.h"

#define NUM_RECORDS 20

void summary(struct person p[], int arraySize);

int main() {
    struct person person[NUM_RECORDS];

    populateRecords(person, NUM_RECORDS);

    //switch statement for users options
    int choice;
    unsigned int running = 1;

    while (running == 1) {
        //get the value from the menu function
        choice = menu();
        switch(choice){
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
            case 0:
                running = quit();
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

void summary(struct person person[], int size) {
    //create variables to store the summary values
    int numRecords = 0;
    //student info
    int numStudents = 0;
    int totalGpa = 0;
    int totalNumCourses = 0;
    int totalTuition = 0;
    //employee info
    int numEmployees = 0;
    int minLevel = 15; //set at max
    int maxLevel = 0; //set at min
    int totalYOS = 0;
    int totalSalary = 0;

  for (int i=0; i<size; i++) {
      // increment the number of records
    numRecords++;
    // check if the person is a student
    if (person[i].emplyeeOrStudent == 1) {
        // add to the studet counter
      numStudents++;

      //add to the student values based on the current student
      totalGpa += person[i].student.gpa;
      totalNumCourses += person[i].student.numCourses;
      totalTuition += person[i].student.tuitionFees;
    }
    else {
      numEmployees++;
      totalYOS += person[i].employee.yearsService;
      totalSalary += person[i].employee.salary;

      // check for min/max level
      if (person[i].employee.level > maxLevel) maxLevel = person[i].employee.level; // set max if value is greater than current max
      if (person[i].employee.level < minLevel) minLevel = person[i].employee.level; //set min if value us smaller than current min
    }
  }

    // claculate avergaes
    float avgGpa = totalGpa/numStudents;
    float avgNumCourses = totalNumCourses/numStudents;
    float avgTuition = totalTuition/numStudents;

    float avgSalary = totalSalary/numEmployees;
    float avgYOS = totalYOS/numEmployees;


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
    char yn[2]; //make var to store user input
    printf("are you sure you want to quit the program? Type y/n to proceed\n");
    scanf("%s", &yn); //get input

    if(strcmp(yn, "y")== 0) {
        return 0;
    } else {
        return 1;
    }
}

