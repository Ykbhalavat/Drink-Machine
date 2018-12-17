/*
 * DrinkMacnine.h
 *
 *  Created on: Oct 9, 2018
 *      Author: yashbhalavat
 */

#ifndef DRINKMACNINE_H_
#define DRINKMACNINE_H_
#include <string.h>
#include<stdbool.h>


struct Drinkitem  // struct 1
{
	int drinkid;
	char nameofdrink[50];
		int quantity;
		double price;
		int drinkpurchased;
};

typedef struct Drink_Machine // struct 2
{
double version;
int Numdrinkitem;
struct Drinkitem* array;  // array pointer to struct 1
int indexofdrink;

}DrinkMachine;
											// FUNCTION PROTOTYPES
void Destroy(DrinkMachine*destroyptr );
DrinkMachine* 	Create();
void destroy(DrinkMachine *drinkMachine);
struct Drinkitem* firstDrink(DrinkMachine* Dmachineptr);
struct Drinkitem* nextDrink(DrinkMachine *Dptr);
int iteams(DrinkMachine*abc);
bool available(DrinkMachine *pDrinkMachine, int drinkid);
double cost(DrinkMachine *pDrinkMachine, int drinkid);
enum Purchase{ PURCHASED, INVALID, NOT_AVAILABLE, INSUFFICIENT_FUNDS };
enum Purchase purchase(DrinkMachine *pDrinkMachine, int drinkid, double Amount, double*Change);
void dumpDrinkMachine(DrinkMachine *pDrinkMachine);




#endif /* DRINKMACNINE_H_ */
