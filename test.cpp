#include <iostream>
#include "algsort.hpp"

using namespace std;

#define TAB 3
//przeprowadzamy test na małej ilości tablic, zmienną można zmieniać

int main()
{
    cout<<"test dzialania algorytmow na malej tablicy dwuwymiarowej z wizualizacja\n\n";
    int size;
    cout << "Podaj rozmiar: ";
    cin >> size;
    cout << endl;
    
    int **arr2d = new int *[TAB]; //tworzenie tablicy dwuwymiarowej
    for (int i = 0; i < TAB; i++)
    {
       arr2d[i] = new int[size];
    }

    // wypełnienie tablicy losowymi liczbami
    srand(time(NULL));
    for (int i = 0; i < TAB; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr2d[i][j] = rand() % 100000 + 1;
        }
    }  

    cout << "Procent: ";
    double p = 0.0;
    cin >> p;

    for (int i = 0; i < TAB; i++)
    {
        percentsort(arr2d[i], 0, size - 1, p);

        if (p==100)   reverse(arr2d[i], size); 
        //gdy sortujemy 100% tablicy, zostanie ona potem odwrócona 
        //w ten sposób mamy tablicę z elementami posortowanymi odwrotnie
    }

    cout << "\n\n~~QUICKSORT~~" << endl;

    cout<<"\nPrzed sortowaniem: "<<endl;
    for(int i=0; i<TAB; i++){
        for(int j=0; j<size; j++)
        {
            cout<<arr2d[i][j]<<" ";
        } cout<<endl;
    }
	
    for (int i = 0; i < TAB; i++)
    {
        quicksort(arr2d[i], 0, size - 1);
    }

    cout<<"\nPo sortowaniu: "<<endl;
    for(int i=0; i<TAB; i++){
        for(int j=0; j<size; j++)
        {
            cout<<arr2d[i][j]<<" ";
        } cout<<endl;
    }

    delete[] arr2d;
    
/////////////////////////////////////////////////////////////////////////////////

    cout << "\n\n~~MERGESORT~~" << endl;

    int **arr2dm = new int *[TAB]; //tworzenie tablicy dwuwymiarowej
    for (int i = 0; i < TAB; i++)
    {
       arr2dm[i] = new int[size];
    }

    // wypełnienie tablicy losowymi liczbami
    srand(time(NULL));
    for (int i = 0; i < TAB; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr2dm[i][j] = rand() % 1000000 + 1;
        }
    }  

    for (int i = 0; i < TAB; i++)
    {
        percentsort(arr2dm[i], 0, size - 1, p);

        if (p==100)   reverse(arr2dm[i], size);
        //gdy sortujemy 100% tablicy, zostanie ona potem odwrócona 
        //w ten sposób mamy tablicę z elementami posortowanymi odwrotnie
    }

    cout<<"\nPrzed sortowaniem: "<<endl;
    for(int i=0; i<TAB; i++){
        for(int j=0; j<size; j++)
        {
            cout<<arr2dm[i][j]<<" ";
        } cout<<endl;
    }

    for (int i = 0; i < TAB; i++)
    {
        mergesort(arr2dm[i], 0, size - 1);
    }

    cout<<"\nPo sortowaniu: "<<endl;
    for(int i=0; i<TAB; i++){
        for(int j=0; j<size; j++)
        {
            cout<<arr2dm[i][j]<<" ";
        } cout<<endl;
    }

    delete[] arr2dm;

//////////////////////////////////////////////////////////////////////////////

    cout << "\n\n~~INTROSORT~~" << endl;

    int **arrin = new int *[TAB]; //tworzenie tablicy dwuwymiarowej
    for (int i = 0; i < TAB; i++)
    {
       arrin[i] = new int[size];
    }

    // wypełnienie tablicy losowymi liczbami
    srand(time(NULL));
    for (int i = 0; i < TAB; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arrin[i][j] = rand() % 10000 + 1;
        }
    }  

    for (int i = 0; i < TAB; i++)
    {
        percentsort(arrin[i], 0, size - 1, p);

        if (p==100)   reverse(arrin[i], size); 
        //gdy sortujemy 100% tablicy, zostanie ona potem odwrócona 
        //w ten sposób mamy tablicę z elementami posortowanymi odwrotnie
    }

    cout<<"\nPrzed sortowaniem: "<<endl;
    for(int i=0; i<TAB; i++){
        for(int j=0; j<size; j++)
        {
            cout<<arrin[i][j]<<" ";
        } cout<<endl;
    }

    for (int i = 0; i < TAB; i++)
    {
        introsort(arrin[i], size);
    }
  
    cout<<"\nPo sortowaniu: "<<endl;
    for(int i=0; i<TAB; i++){
        for(int j=0; j<size; j++)
        {
            cout<<arrin[i][j]<<" ";
        } cout<<endl;
    }

    delete[] arrin;

}