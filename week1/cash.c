#include<stdio.h>

#include<cs50.h>

#include<math.h>


int main(void)
{
  //ask for dollars/Change owed
  float dollars;
   do
   {
    dollars = get_float("Change owed:");
   }
   while (dollars < 0);

 //Round dollar to cents
   int cents = round(dollars * 100);

   //Set initial number of coins to 0
   int coins = 0;


   //Start calculation for 25c, 10c,5c,1c
  while (cents>= 25)
  {
     cents = cents - 25;
      coins++;
  }


    while (cents>= 10 && cents<25)
  {
     cents = cents - 10;
      coins++;
  }

   while (cents>= 5 && cents<10)
  {
     cents = cents - 5;
      coins++;
  }

   while (cents>= 1 && cents<5)
  {
     cents = cents - 1;
      coins++;
  }

  //print out the number of coins based on above calculation
  printf("Coins needed: %i\n", coins);


}
