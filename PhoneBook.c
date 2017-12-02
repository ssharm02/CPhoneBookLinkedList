//Major project for C, coded by Sarthak Sharma and Luis Ortiz
//Phonebook app add, load, save, retrieve and delete records 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<regex.h>

//Prototype Functions
void insertPhoneBookData();
void printTheInfo();
void loadPhoneBook(); 
void retrievePhoneBook();
void deletePhoneData();
void clrscr();
//void savetofile();

//Structure of the phone book: first name, last name, and phone number stored within the structure
typedef struct contactNode { 
	char fName[30];
	char lName[30];
	char number[11];
	struct contactNode *cNextNode; //Pointer to next node
}contactNode;

typedef struct contactNode cNode; //Synonym for struct contactNode
cNode *nodeStart, *nodeTemp;

int main(void) 
{	
	//NodePtr first;
	int choice;
	while(choice != 5) 
	{

	printf("Main menu:\n");
	printf("1: Add Records to PhoneBook\n");
	printf("2: Print PhoneBook\n");
	printf("3: Delete Records from PhoneBook\n");
	printf("5: Save Records to Text file\n");
	printf("6: Press 6 to Clear Screen\n");
	printf("Enter a Choice from 1 to 5: ");
	scanf("%d", &choice);
		
		//Switch statement asks for user choice and calls the appropriate method for the particular choice
		switch(choice) 
		{
		case 1: insertPhoneBookData(); //method to insert data into the linked list
				clrscr(); //method to clear the screen
				//savetofile();
		break;
		case 2: printTheInfo();
				getchar(); //get char before clearing the screen
				clrscr();
				
		break;
		case 3: //SaveFile(&first);
				getchar();
				clrscr();
		break;
		case 4: deletePhoneData();
				getchar();
				clrscr();
		break;
		default:
			printf("\n\nThanks for using the program.\n\n");
			return 0;
		}//end of switch statement
	}//end of while loop

	return 0;

}//End of main method


//Method to insert phonebook data into a Linked List
void insertPhoneBookData(void) 
{
	cNode *nodePtr,*prevNode;
	nodeTemp=(cNode *)malloc(sizeof(cNode));
	printf("First name: ");
	//if(scanf("%s", &nodeTemp)==0) {
	scanf("%s", nodeTemp->fName);
//	}
	//else {
		//printf("Invalid Value");
	//}
	printf("Last name: ");
	scanf("%s", nodeTemp->lName);
	printf("Mobile Num: ");
	scanf("%s", nodeTemp->number);
	nodeTemp->cNextNode=NULL;


	if(nodeStart==NULL) 
		nodeStart=nodeTemp;
	else {
 	prevNode=nodePtr=nodeStart;
 	while(strcmp(nodeTemp->fName,nodePtr->fName)>0){
 		prevNode=nodePtr;
 		nodePtr= nodePtr->cNextNode;
	if (nodePtr == NULL) 
	break;
 	}
		if(nodePtr==prevNode) {
			nodeTemp->cNextNode=nodeStart;
			nodeStart=nodeTemp;
		}
		else if(nodePtr==NULL)
			prevNode->cNextNode=nodeTemp;
		else {
			nodeTemp->cNextNode=nodePtr;
			prevNode->cNextNode=nodeTemp;
		}
	}
}

//Method to delete a record from the phonebook
void deletePhoneData(void)
{
	cNode *nodePtr,*prevNode,*nodeTemp;
	char userNameDelete[30]; //User name to delete
	char deletionChar; //Character variable that confirms deletion
	if(nodeStart==NULL) 
	{
		printf("\n\t\tPhonebook is empty....\n");
		getchar();
		clrscr();
		return;
	}
	printf("First Name to Delete : ");
	scanf("%s",userNameDelete); //Get name to delete from the User

 prevNode=nodePtr=nodeStart;
 	while(strcmp(nodePtr->fName,userNameDelete)!=0){
 		prevNode=nodePtr;
 		nodePtr= nodePtr->cNextNode;
		if (nodePtr == NULL) 
		break;
 	}
	if(nodePtr!=NULL){
		printf("\nAre you sure you want to delete this record? [y/n]: ");
		scanf("%s",&deletionChar);

printf("\n\nThe following record has been deleted");
		printf("\nFirst Name : %s\n",nodePtr->fName);
		printf("Last Name : %s\n",nodePtr->lName);
		printf("Phone Number : %s\n",nodePtr->number);
		if(deletionChar=='y') {
			if (nodePtr==nodeStart) {
				nodeTemp=nodeStart->cNextNode;
				free(nodeStart);
				nodeStart=nodeTemp;
			}
			else {
				nodeTemp=nodePtr->cNextNode;
				free(nodePtr);
				prevNode->cNextNode=nodeTemp;
			}
			printf("\n\nRecord Deleted....");
			
		}
		else
			printf("\n\nRecord not Deleted....");
	
	}
	else {
		printf("\nNo Matching Records Found .......");
		
	}
 getchar();
}//end of Delete function


void retrievePhoneBook(void)
{
	cNode *nodePtr;
	char userNameSearch[20];
	if(nodeStart==NULL) {
		printf("\n\t\t\tPhoneBook is Empty....\n");
getchar();
		return;
	}
	printf("First Name to Find : ");
	scanf("%s",userNameSearch);
 nodePtr=nodeStart;
 while(strcmp(nodePtr->fName,userNameSearch)!=0){
 	nodePtr= nodePtr->cNextNode;
if (nodePtr == NULL) break;
 }
	if(nodePtr!=NULL) {
		printf("\t\t------------------------------\n");
		printf("\nFirst Name : %s\n",nodePtr->fName);
		printf("Last Name : %s\n",nodePtr->lName);
		printf("Phone Number : %s\n",nodePtr->number);
		printf("\n\t\t------------------------------\n");
	}
	else {
		printf("Invalid Entery\n");
	}
 getchar();
}



void printTheInfo(void)
{
	cNode *nodePtr;
	if(nodeStart==NULL) {
		printf("\n\t\t\tTelephone Directory is Empty....\n");
getchar();
		return;
	}
	//clrscr();
	printf("\t\t------------------------------\n");
	for(nodePtr=nodeStart; nodePtr!=NULL; nodePtr=nodePtr->cNextNode) {
		printf("\tFirst name: %s", nodePtr->fName);
		printf("\n\tLast name: %s", nodePtr->lName);
		printf("\n\tMobile Num: %s", nodePtr->number);
		printf("\n\t\t------------------------------\n");
 }
 getchar();
}
//Simple method that clears the console screen  
void clrscr(void)
{
    system("@cls||clear");
}
