// Title: LinkedListForInts.h
// Description & Purpose: This is a header file to be able to easily incorporate linked lists into projects
// Attribution: Inspirational credit and some base code goes to Sean Banerjee, sbanerje@clarkson.edu
// Author: Cameron Palmer, campalme@clarkson.edu
// Last Modified: September 23rd, 2020


// Imports
#include<iostream>
#include<cstdio>
#include<cstdlib>


// Struct for a single node. Includes an int for the data in the node and a pointer to the previous node
struct node
{
	int data;
	node* previousPtr;
};

// Functions
// Insert an item into the list
node* addItem(node*, char);	

// Delete an item from the list
node* deleteItem(node*, char);	

// Check if the list if empty
int isEmpty(node*);			

// Print the list		
void printList(node*);	



int main()
{
	node* headPtr = NULL;		//Points to top of the list
	int choice;					//Stores the choice from the user
	char item;					//Stores the data the user enters

	instructions();				//Prints the instructions
	std::cin >> choice;			//Gets the user choice

	while (choice != 3)			//Loop as long as choice is not 3
	{
		//The switch statement allows us to easily work with the user choices
		switch (choice)
		{
			//The user wants to enter an item into the list
			case 1:
				std::cout << "Enter a character: " << std::endl;
				std::cin >> item;				
				headPtr = insertItem(headPtr, item);
				printList(headPtr);
				break;

			//The user wants to delete an item from the list
			case 2:
				//Check if the list is not empty
				if (!isEmpty(headPtr))
				{
					std::cout << "Enter the item you want to delete:" << std::endl;
					std::cin >> item;

					headPtr = deleteItem(headPtr, item);
					printList(headPtr);
				}
				//The list is empty, tell the user the list is empty
				else
				{
					std::cout << "The list is empty." << std::endl;
				}
				break;
			//User choice is invalid, display error and show menu again
			default:
				std::cout << "Invalid choice." << std::endl;
				instructions();
				break;
		}

		//Get choice from the user again
		instructions();
		std::cin >> choice;
	}

	std::cout << "Program terminated." << std::endl;
	return 0;
}

//Function: insertItem
//Inputs: pointer to top of list and item to insert
//Outputs: insert item to the top of the list and return the new address of the top of the list
//Errors: none
node* insertItem(node* headPtr, char item)
{
	node* newPtr;				//newPtr - our new location
	newPtr = new node;			//allocate memory for the new location
	node* currentPtr;			//currentPtr - our current location
	node* previousPtr;			//previousPtr - the previous location

	//check to see if newPtr is NULL, it will be NULL if we could not allocate memory to it
	if (newPtr != NULL)
	{
		newPtr->data = item;		//Set data to the value provided by the data provided by the user
		newPtr->prevPtr = NULL;		//Set prevPtr of the newly created node to NULL while we search for the spot to insert to		
		
		previousPtr = NULL;				//Set the previous location to NULL
		currentPtr = headPtr;			//Start at the head and begin searching

		//Loop and search for the location to insert to
		while (currentPtr != NULL && item > currentPtr->data)
		{
			previousPtr = currentPtr;			//Go to next item
			currentPtr = currentPtr->prevPtr;	//Go to next item
		}

		//If we reached the end then we have to insert at the front
		if (previousPtr == NULL)
		{
			newPtr->prevPtr = headPtr;	//Set prevPtr of the newly created node to headPtr
			headPtr = newPtr;			//Set headPtr to the newly created node
		}
		else
		{
			previousPtr->prevPtr = newPtr;	//Set prevPtr of prior location to newPtr
			newPtr->prevPtr = currentPtr;	//Set prevPtr of newly created node to currentPtr
		}

	}
	else
	{
		//Print error message is we cannot allocate memory
		std::cout << "Could not insert " << item << ". No memory available." << std::endl;
	}

	return headPtr;		//return location of headPtr after insertion
}

node* deleteItem(node* headPtr, char item)
{
	node* previousPtr;
	node* currentPtr;
	node* tempPtr;
	
	//Check if the value is at the top of the list
	if (item == headPtr->data)
	{
		tempPtr = headPtr;				//Save the location of headPtr to a temporary location
		headPtr = headPtr->prevPtr;		//Set headPtr to the location of prevPtr
		free(tempPtr);					//Free the temporary location to clear up memory
		return headPtr;					//Return the new address of headPtr
	}

	else
	{
		//Traverse the list until we find the first instance of item
		previousPtr = headPtr;			//Set previousPtr to the top of the list
		currentPtr = headPtr->prevPtr;	//Set currentPtr to the previous item in the list

		//Loop and search for the item
		while (currentPtr && currentPtr->data != item)
		{
			previousPtr = currentPtr;			//Go to next item
			currentPtr = currentPtr->prevPtr;	//Go to next item
		}

		//If we have not reached the end of the list 
		if (currentPtr)
		{
			tempPtr = currentPtr;						//Set a temporary location for currentPtr
			previousPtr->prevPtr = currentPtr->prevPtr;	//Delink by re-setting location of prevPtr
			free(tempPtr);								//Free up the memory
			return headPtr;
		}
		//If we reached the end then we did not find the item
		else
		{
			//Tell the user we did not find the item and return the headPtr location unchanged
			std::cout << item << " was not found." << std::endl;
			return headPtr;
		}
	}
}

//Function: instructions
//Inputs: none
//Ouputs: shows the user menu on the screen
//Errors: none
void instructions()
{
	std::cout << "Enter your choice: " << std::endl;
	std::cout << "1 to insert an item into the list." << std::endl;
	std::cout << "2 to delete an item from the list." << std::endl;
	std::cout << "3 to end" << std::endl;
}

//Function: isEmpty
//Inputs: pointer to top of list
//Outputs: returns 1 if the list is empty, otherwise returns 0
//Errors: none
int isEmpty(node* sPtr)
{
	//Checks if sPtr is equal to NULL, if it is then it returns 1
	return sPtr == NULL;
}

//Function printList
//Inputs: pointer to top of list
//Outputs: prints the elements of the list to the screen
//Errors: none
void printList(node* currentPtr)
{
	//Check if currentPtr is NULL, if it is NULL then the list is empty
	if (!currentPtr)
	{
		std::cout << "List is empty." << std::endl;
	}

	//List is not empty, begin printing it
	else
	{
		std::cout << "The list is: " << std::endl;
		//Loop until we reach the end of the list
		while (currentPtr)
		{
			printf("%c --> ", currentPtr->data);	//Print the content
			currentPtr = currentPtr->prevPtr;		//Update currentPtr to move to previous item
		}

		std::cout << "NULL" << std::endl;
	}
}