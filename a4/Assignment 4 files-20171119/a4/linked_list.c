
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Created By
 Doron Nussbaum 2016
 
 Modifications:
 November 2017 - minor modifications
 
 
 Copyright 2017
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// Define 



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
id - id of person
firstName - first name of person
familyName - family name of person

input/output
head - head of linked list

return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, char *firstName, char *familyName){
	// alocate memory
	PersonalInfo *newNode = NULL;
	newNode = (PersonalInfo *)malloc(sizeof(PersonalInfo));
	// set the data
	newNode->id = id; //set id
	strcpy(newNode->firstName, firstName);
	strcpy(newNode->familyName, familyName);

	//point to the next node
	newNode->next = *head;
	//update head
	*head = newNode;

	//return newNode
	return newNode;
}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
node - the node after which the new node must be added to the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName) {
	//check if the passed node is valid
	if (node == NULL) {
		//return null since its invalid
		return NULL;
	} else {
		//allocate  memory
		PersonalInfo *newNode = NULL;
		newNode = (PersonalInfo *)malloc(sizeof(PersonalInfo));

		// set the data
		newNode->id = id; //set id
		strcpy(newNode->firstName, firstName); //set fist name
		strcpy(newNode->familyName, familyName); //set family name 

		// make mew node point after node
		newNode->next = node->next;
		//set node to point to the newStruct
		node->next = newNode;

		//return newNNode
		return newNode;
	}
}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName) {
    //create variables
    PersonalInfo* newNode = (PersonalInfo*) malloc(sizeof(PersonalInfo));//allocte mem
    PersonalInfo* last = *head;

    newNode->id = id;//set id
    strcpy(newNode->firstName, firstName);//set first name
    strcpy(newNode->familyName, familyName);//set last name
    //check if the head is null
    if (*head == NULL) {
        *head = newNode;
        return *head;
    }
    //iterate through the list and find the last node
    while (last->next != NULL) {
        //set last
        last = last->next;
    }
    //iterate
    last->next = newNode;

    return newNode;
}


/************************************************************************/
/*
Purpose: search for the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


PersonalInfo *searchByName(PersonalInfo *head, char *firstName) { 
	//check if the head is valid
	if (head == NULL) {
		//return null since it is invalid
		return NULL;
	} else {
		//iterate throught the list to find the node with the corret name
		PersonalInfo *temp = head;
		while(temp != NULL) {
			//find the node based on name
			if (strcmp(temp->firstName, firstName)==0) {
				return temp;
			} else {
				//set temp node to next node
				temp = temp->next;
			}
		}
	}
}

/************************************************************************/
/*
Purpose: search for the first node with the matching id
Input
head - the head of the list
id - id of person person

return
a pointer to the node that was allocated.  

NULL - if no node was found or list empty 

*/


PersonalInfo *searchById(PersonalInfo *head, unsigned int id) {
    //check if the head is valid
	if (head == NULL) {
		//return null since it is invalid
		return NULL;
	} else {
		//iterate throught the list to find the node with the correct id
		PersonalInfo *temp = head;
		while(temp != NULL) {
			//find the node based on id
			if (temp->id == id) {
				return temp;
			} else {
				//set temp node as next node
				temp = temp->next;
			}
		}
	}
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted
1 if node was not deleted or list is empty

*/


int deleteFromList(PersonalInfo **head, unsigned int *id,char *firstName, char *familyName) {
	//check if head is valid 
	if (*head == NULL) {
		//return 1 since the head did not exists
		return 1;
	} else {
		//print the head node
		printNode(*head);
        *id = (*head)->id;
        strcpy(firstName, (*head)->firstName);
        strcpy(familyName, (*head)->familyName);
		//set temp = head
		PersonalInfo *temp = *head;
		//update head to the next node
		*head = temp->next;
		//free memory
		free(temp);
		//return 0 since it worked
		return 0;
	}
}


/***************************************************************/

/*
Purpose: delete the last node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted  
1 if node was not deleted or list is empty 

*/


int deleteLast(PersonalInfo **head, unsigned int *id,char *firstName, char *familyName) {
    if (head == NULL) {
        //return since its invlaid 
        return 1;
    } else {
        //print the head
        printNode(*head);
        PersonalInfo *temp = *head;
        while (temp->next->next != NULL) {
        temp = temp->next;
    }
        // create a deleted var
        PersonalInfo *deleted = temp->next;
        //print the deleted record
        printNode(deleted);
        //set temp to the deleted next node
        temp->next = deleted->next;
        //free memory
        free(deleted);
        //return 0 since it was valid
        return 0;
    }
}

/************************************************************************/

/*
Purpose: delete the record after the given node 
Input
node - a node in the list

output
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0 if node was deleted 
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/



int deleteAfter(PersonalInfo *node, unsigned int *id, char *firstName, char *familyName) {
	// return 1 if node was not deleted (either input node is NULL or input node was the lastnode in the list
	if (node == NULL || node->next == NULL) {
		return 1;
	} else {
		//print the node that is beiong deleted
		printNode(node->next);	
        //set a temp deleted variable
		PersonalInfo *deleted = node->next;
		//set next node to next next
		node->next = deleted->next; 
        //set new attributes
        *id = node->id;
        strcpy(firstName, node->firstName);
        strcpy(familyName, node->familyName);
        //free the mem
		free(deleted);
		//return 0 since it was valid
		return 0;
	}
}

/************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonalInfo **head, char *firstName, char *familyName, unsigned int *id) {
	//check if head is valid
	if (head == NULL) {
		//return 1 since it is invalid
		return 1;
	} else {
		PersonalInfo *temp = *head;
		while (temp->next != NULL) {
			if (strcmp(temp->next->firstName, firstName)==0) {
				//print the node that is beiong deleted
				printNode(temp->next);
				//set a temp deleted variable
				PersonalInfo *deleted = temp->next;
				//set next node to next next
				temp->next = deleted->next;
				//free the memory
				free(deleted);
				return 0;
			} else {
				temp = temp->next;
			}
		}
	}
return 1;
}
/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(PersonalInfo **head) {
	//create current and next pointers
	PersonalInfo *current = NULL;
	PersonalInfo *next = NULL;
	//iterate through the list
	while(current != NULL) {
		//set next to the current nodes next node
		next = current->next;
		//free the current node memory
		free(current);
		//set current next
		current = next;
	}
	//set head to null
	*head = NULL;
}



/************************************************************************/
/*
Purpose: prints the fields of a node
input:
node - a pointer to a given node

*/


void printNode(PersonalInfo *node)
{
	printf("%-20s %-20s %7d \n",node->firstName, node->familyName, node->id);

}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head) {
	//create temp node
	PersonalInfo *current= head;
	//iterate through list
	while (current != NULL) {
		//print the current node
		printNode(current);
		//set current to the next node
		current = current->next;
	}
}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


int listSize(PersonalInfo *head) {
int count = 0;//create counter
//iterate through the list
while (head != NULL) {
    count++;//increment counter
    head = head->next;//move to next node
}
//return value
return count;
}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list with a matching firstName
input
head - the head of the list

return 
the number of nodes in the list that match the firstName


*/


int countRecords(PersonalInfo *head, char *firstName) {

int count = 0;//create counter
//iterate through the list
while (head != NULL) {
    //compare strings
    if (strcmp(head->firstName, firstName) == 0) {
            count++;//iterate ount
    }
    //move to next node
    head = head->next;
}
//return value
return count;
}




/************************************************************************/
/*

Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name. 
You can assume that the listed is sorted by first name.

input
head - the head of the  list


 
*/




void removeDuplicates(PersonalInfo *head) {
	//check if the head is valid
	if (head != NULL) {
		//create current node
		PersonalInfo *current = head;
		// create next node
		PersonalInfo *next = NULL;
		
		//iterate the list
		while (current->next != NULL) {
			//compare the first names of current and current next 
			if (strcmp(current->firstName, current->next->firstName)== 0) {
				// set next to the next next variable
				next = current->next->next;
				//free the allocated mem
				free(current->next);
			} else {
				//move curernt to the next position
				current = current->next;
			}
		}
	}
}

