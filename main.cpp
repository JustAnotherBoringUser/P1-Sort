#include <iostream>
#include <time.h>
#include "exp.hpp"

using namespace std;

int main()
{
    int choice;

    while(choice!=4){

    cout<<"Wybierz rodzaj sortowania: \n1 - quicksort\n2 - mergesort\n3 - introsort\n4 - koniec\n";
    cin>>choice;

    switch(choice) {
    case 1: quickm(); break;
    case 2: mergem(); break;
    case 3: introm();  break;  
    case 4: break;      
        }
    }

}
