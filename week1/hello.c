#include<stdio.h>
#include<cs50.h>

int main(void)
{
    //get name
    string name = get_string("What's your name?\n"); 
    
    //print hello with name
    printf("Hello,%s\n", name);
    
}
