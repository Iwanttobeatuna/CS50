#include <stdio.h>
#include<cs50.h>


int main (void)
{
  int sum = 0;
  for(int i=0; i<10; i++)
  {
      sum += get_int("Number:");

  }
  printf("Sum:%i\n", sum);
  
}
