/*
 * drinkMachineDriver.c
 *
 *  Created on: Oct 9, 2018
 *      Author: yashbhalavat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include"DrinkMacnine.h" // include the header file

int main()
{

DrinkMachine*mydrinkmachine=Create();  //sets the return of create equal to the new pointer
	dumpDrinkMachine(mydrinkmachine); // call the above set function

int id=0;
double paymenttaken=0;
cost(mydrinkmachine,id); // calls cost function
double amount = 0;
double Change = 0;
purchase(mydrinkmachine,id, amount, &Change); // calls purchase function
	int value=0;

for(int a=0;a<128;a++)  // goes inside loop if the  value a is less than 128
{
printf("Enter a drink id for the drink you want to purchase or 0 to quit : \n");
printf( "DRINKId\t\t""Name\t\t""Price\n");

for(int i=0;i< mydrinkmachine->Numdrinkitem;i++)  //goes inside loop and prints the  output
		 	{
			 printf("%d",i+1);
		 	printf(" %20s",mydrinkmachine->array[i].nameofdrink);
			 	printf("\t%12.2lf\t\n",mydrinkmachine->array[i].price);
		 	}
printf("ENTER = ");
scanf("%d",&(value));  // enter the value
if(value==0)  // if value 0 will go inside
{
	dumpDrinkMachine(mydrinkmachine);
	printf("Thank you for using the drink machine.\n");
	return EXIT_SUCCESS;  // will return after entering
}
else if(value>0 && value<=8)  //if between the value will go inside
{
	printf("Enter the amount for the purchase (up to $2.00)=");
	scanf("%lf",&paymenttaken);

	if(paymenttaken>2.00)  //if the payment taken is higher than 2 will go inside
	{
		printf("The amount is invalid\n");
	}
	else if (paymenttaken==mydrinkmachine->array[value].price) // if equal will use this
	{
		printf("your drink has been purchase\n");
		mydrinkmachine->array[value-1].quantity--;  // -1 the quantity
		mydrinkmachine->array[value-1].drinkpurchased++; // +1 the sold items

	}
	else if(paymenttaken>mydrinkmachine->array[value-1].price) // if more but less than 2.00 will use this.
	{
		mydrinkmachine->array[value-1].quantity--;  // -1 the quantity
		mydrinkmachine->array[value-1].drinkpurchased++; // +1 the sold items

			Change = paymenttaken - mydrinkmachine->array[value-1].price;
			printf("Name of your Purchase Drink is :%s \n",mydrinkmachine->array[value-1].nameofdrink);
		printf("your drink has been purchase. your change is = %.2lf\n", Change);
	}
	else if (paymenttaken < (mydrinkmachine)->array[value-1].price)// if payment taken is less than will uuse this
	{
		printf("INSUFFICIENT FUNDS. The price is = %.2lf \n",mydrinkmachine->array[value-1].price);
	}


}
else
{
	printf("The Drink-id is invalid"); // else will print this
}
printf("\\the Quantity is : %d \n",mydrinkmachine->array[value-1].quantity);
printf("\\the Sold item : %d \n",mydrinkmachine->array[value-1].drinkpurchased);

printf("Thank you for using the drink machine.\n");
}
fflush(stdin);
fflush(stdout);
Destroy(mydrinkmachine);// call destroy function.

}





