#include <iostream>
#include "test2.h"
static int  a = 0;
void print()
{
    while(!val)
    {
       print_val();
       a++;

       if(a == 10)
       {
           break;
       }
    }
}

int main()
{
    print();
    change_val();
    return 0;

}