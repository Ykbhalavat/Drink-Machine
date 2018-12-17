/*
 ============================================================================
 Name        : DrinkMachine.c
 Author      : Yash Bhalavat
 Version     :1.0
 Copyright   : Your copyright notice
 Description : This Program works as a simulates for a Drink-Machine and allows
 	 	 	 	 the user to purchase Drink item. it uses a dynamic memory allocation and structures
 	 	 	 	 to create the program.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include"DrinkMacnine.h"  // Header File

const int INVALID_INDEX = -1;   // Sets index to -1 if value is invalid

DrinkMachine*Create( )    // This function reads file and dynamically allocate memory to struct Drink item
{
	DrinkMachine*dtrptr =(DrinkMachine*) malloc(sizeof(DrinkMachine)); // create a DrinkMachine pointer and allocate memory

	dtrptr->version=1.0;  // creates a version
	dtrptr->indexofdrink=INVALID_INDEX;
	int value=0;
		char file_name[50];
		FILE*input;      //creating a file pointer
		printf("Enter Name of a file you wish to open = ");// please enter Drink_Machine.txt to open file.
		   scanf("%s",file_name);
		input=fopen(file_name,"r");     // opening a file and reading the file
		if (input==NULL)
		{
			printf("file could not be open \n");
		}
		fscanf(input,"%d",&value);
		dtrptr->array = (struct Drinkitem*)malloc(value*sizeof(struct Drinkitem));  //setting drink-item struct dynamically

		 for(int i=0;i<value;i++)     // loops until the value reches end of file.
			 	{
			 fscanf(input,"%s",dtrptr->array[i].nameofdrink);
				 fscanf(input,"%lf",&dtrptr->array[i].price);
					fscanf(input,"%d",&dtrptr->array[i].quantity);}

		printf("Total no of Elements : %d \n",value);
		dtrptr->Numdrinkitem=value;   // sets the no of drink-item struct to value
return dtrptr;
}

void Destroy(DrinkMachine*destroyptr )    // this function frees the allocated memory
{
	free(&destroyptr);
	free(&destroyptr->array);
	free(destroyptr->array);
}
struct Drinkitem*firstDrink(DrinkMachine*Dmachineptr )  // this function executes if the no of drink-item is greater than 0. returns the item

{

if( Dmachineptr->Numdrinkitem>0)
{
	Dmachineptr->indexofdrink=0;
	return Dmachineptr->array;

}
else
{
	Dmachineptr->indexofdrink=INVALID_INDEX;  // returns null if invalid-index and stops
	return NULL;
}

}

struct Drinkitem*nextdrink(DrinkMachine*Dptr )  // this function moves forward from first item.
{
	{
	   if(Dptr->indexofdrink == INVALID_INDEX){  // if invaild index it would return null.
	       return NULL;
	   }
	   else{      // if the index of drink this will execute
		   Dptr->indexofdrink++;
	       if(Dptr->indexofdrink < Dptr->Numdrinkitem)   //if index is less than no of drink item struct will execute
	           return (Dptr->array+Dptr->indexofdrink);
	       else{
	    	   Dptr->indexofdrink = INVALID_INDEX;// if invaild index it would return null.
	           return NULL;
	       }
	   }
	}
}

int iteams(DrinkMachine*Dnumptr)   // this struct returns the no of drink item.
{
	return Dnumptr->Numdrinkitem;
}



bool available(DrinkMachine *pDrinkMachine, int drinkid)  //function check the avability of drink
{
   for(int i=0; i<pDrinkMachine->Numdrinkitem; i++){   // loop until the no of drink item
       if(pDrinkMachine->array[i].drinkid == drinkid && pDrinkMachine->array[i].quantity>=1)
           return true;  // will return true
   }
   return false;  // return falsse
}

double cost(DrinkMachine *pDrinkMachine, int drinkid)  // function checks the cost of the drinks
{
   for(int i=0; i<pDrinkMachine->Numdrinkitem; i++)
   {
       if(pDrinkMachine->array[i].drinkid == drinkid)
           return pDrinkMachine->array[i].price;  // will return price if the entered amount is less than no drink item
   }
   return -1; // else return -1
}

enum Purchase purchase(DrinkMachine *pDrinkMachine, int drinkid, double Amount, double*Change) // checks the price of the function
{
	double change;
	 Change=&change;
	if(available(pDrinkMachine,drinkid))  // if drink availabe then only will go inside the statement
	{

	       if(pDrinkMachine->array[drinkid-1].quantity>=1)   // will go if quantity is greater or equal to 1
	       {
	           if(Amount<cost(pDrinkMachine,drinkid)) // if amount is less than cost then will go inside
	           {
	               return INSUFFICIENT_FUNDS;
	           }
	           else{  // else will perform calculation

	               pDrinkMachine->array[drinkid-1].quantity--;  // -1 the quantity
	               pDrinkMachine->array[drinkid-1].drinkpurchased++; // +1 the sold items
	               change = Amount - cost(pDrinkMachine,drinkid);
	               return PURCHASED;
	           }
	       }
	       else
	           return NOT_AVAILABLE;
	   }
	   else
	       return INVALID;
}


void dumpDrinkMachine(DrinkMachine *pDrinkMachine)  // prints out all information on to the screen.
{
	pDrinkMachine->array->drinkpurchased=0;
	printf( "Id\t\t""Name\t\t""Price\t\t" "Quantity\t" "Sold\t\n");
	 for(int i=0;i< pDrinkMachine->Numdrinkitem;i++)
	 	{
		 printf("%d",i+1);
	 	printf(" %20s",pDrinkMachine->array[i].nameofdrink);
		 	printf("\t%12.2lf\t",pDrinkMachine->array[i].price);
		 	printf("\t%d",pDrinkMachine->array[i].quantity);
		 	printf("%15d\n",pDrinkMachine->array[i].drinkpurchased);

	 	}
	 	printf(" \n\n\t*********The version is = %.1lf******** \n",pDrinkMachine->version);

}




