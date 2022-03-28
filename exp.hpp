#ifndef EXP_HPP
#define EXP_HPP

#include <iostream>
#include <time.h>
#include "algsort.hpp"

#define TAB 100
// 100 tablic

void quickm()
{
    int arrSize[5] = {10000, 50000, 100000, 500000, 1000000}; //rozmiary tablic
	std::cout << "Podaj procent posortowanych elementow poczatkowych:\n(0 - wszystkie elementy losowe, 100 - wszystkie posortowane odwrotnie)\n";
    double p = 0.0;
    std::cin >> p;

    clock_t start,stop; //zmienne do timera
    double czas;

    
        for (int size : arrSize){

        int **arr2d = new int *[TAB]; //tworzenie tablicy dwuwymiarowej [100][size]
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

        for (int i = 0; i < TAB; i++)
        {
            percentsort(arr2d[i], 0, size - 1, p);

            if (p==100)   reverse(arr2d[i], size); 
            //w ten sposób mamy tablicę z elementami posortowanymi odwrotnie
        }

        start = clock(); //timer start
        for (int i = 0; i < TAB; i++)
        {
            quicksort(arr2d[i], 0, size - 1);
        }
        stop = clock();
        czas = (double)(stop-start) / CLOCKS_PER_SEC;
         for (int i = 0; i < TAB; i++)
        {
            check(arr2d[i], size);
        }
        std::cout<<"\n100 tablic rozmiaru "<<size<<", "<<p<<"%"<<std::endl;
        std::cout<<"\nCzas sortowania: "<<czas<<" s"<<std::endl; 

        for (int i = 0; i < TAB; i++)
        {
            delete[] arr2d[i];
        }

        delete[] arr2d;

        }

}

void mergem()
{
    int arrSize[5] = {10000, 50000, 100000, 500000, 1000000}; //rozmiary tablic
	std::cout << "Podaj procent posortowanych elementow poczatkowych:\n(0 - wszystkie elementy losowe, 100 - wszystkie posortowane odwrotnie)\n";
    double p = 0.0;
    std::cin >> p;

    clock_t start,stop; //zmienne do timera
    double czas;

        for (int size : arrSize){

        int **arr2d = new int *[TAB]; //tworzenie tablicy dwuwymiarowej [100][size]
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

        for (int i = 0; i < TAB; i++)
        {
            percentsort(arr2d[i], 0, size - 1, p);

            if (p==100)   reverse(arr2d[i], size); 
            //w ten sposób mamy tablicę z elementami posortowanymi odwrotnie
        }

        start = clock(); //timer start
         for (int i = 0; i < TAB; i++)
        {
            mergesort(arr2d[i], 0, size - 1);
        }
        stop = clock();
        czas = (double)(stop-start) / CLOCKS_PER_SEC;
         for (int i = 0; i < TAB; i++)
        {
            check(arr2d[i], size);
        }
        std::cout<<"\n100 tablic rozmiaru "<<size<<", "<<p<<"%"<<std::endl;
        std::cout<<"\nCzas sortowania: "<<czas<<" s"<<std::endl; 

        for (int i = 0; i < TAB; i++)
        {
            delete[] arr2d[i];
        }

        delete[] arr2d;

        }

}

void introm()
{
    int arrSize[5] = {10000, 50000, 100000, 500000, 1000000}; //rozmiary tablic
	std::cout << "Podaj procent posortowanych elementow poczatkowych:\n(0 - wszystkie elementy losowe, 100 - wszystkie posortowane odwrotnie)\n";
    double p = 0.0;
    std::cin >> p;

    clock_t start,stop; //zmienne do timera
    double czas;

        for (int size : arrSize){

        int **arr2d = new int *[TAB]; //tworzenie tablicy dwuwymiarowej [100][size]
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

        for (int i = 0; i < TAB; i++)
        {
            percentsort(arr2d[i], 0, size - 1, p);

            if (p==100)   reverse(arr2d[i], size); 
            //w ten sposób mamy tablicę z elementami posortowanymi odwrotnie
        }

        start = clock(); //timer start
         for (int i = 0; i < TAB; i++)
        {
            introsort(arr2d[i], size);
        }
        stop = clock();
        czas = (double)(stop-start) / CLOCKS_PER_SEC;
         for (int i = 0; i < TAB; i++)
        {
            check(arr2d[i], size);
        }
        std::cout<<"\n100 tablic rozmiaru "<<size<<", "<<p<<"%"<<std::endl;
        std::cout<<"\nCzas sortowania: "<<czas<<" s"<<std::endl; 

        for (int i = 0; i < TAB; i++)
        {
            delete[] arr2d[i];
        }

        delete[] arr2d;

        }

}

#endif 