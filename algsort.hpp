#ifndef ALGSORT_HPP
#define ALGSORT_HPP

#include <iostream>
#include <math.h>
#include <cmath>
#include <algorithm>

template <typename T>
void swap(T &arr1, T &arr2)
{
    T temp = arr1;
    arr1 = arr2;
    arr2 = temp;
}

// funkcja odwracająca (w zamyśle posortowaną) tablicę
template <typename T>
void reverse(T *arr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size-i-1]); //size -1 bo indeksy idą od 0
    }
}

// funkcja scalająca posortowane podtablice (mergesort):
template <typename T>
void merge(T *arr, int l, int m, int r) //tablica, indeks lewy, środkowy, prawy
{
// podzielenie wyjściowej tablicy na 2 podtablice
    T lSize = m - l + 1;
    T rSize = r - m;

    T *lArr = new T[lSize];
    T *rArr = new T[rSize];
// wypełnienie podtablic danymi
    for (int i = 0; i < lSize; i++)
    {
        lArr[i] = arr[l + i];
    }

    for (int j = 0; j < rSize; j++)
    {
        rArr[j] = arr[m + 1 + j];
    }
// Scalenie
      int x = 0, y = 0, z; 
      
      for (z = l; x < lSize && y < rSize; z++)
	{
		if (lArr[x] <= rArr[y])
			arr[z] = lArr[x++];
		else
			arr[z] = rArr[y++];
    }

	while (x < lSize)
		arr[z++] = lArr[x++];

	while (y < rSize)
		arr[z++] = rArr[y++];

    delete[] lArr;
    delete[] rArr;
}

template <typename T>
void mergesort(T *arr, int l, int r)
{
    if (l < r) 
    {
        long int m = (l + r) / 2;   //podzielenie na pół
        mergesort(arr, l, m);        //sortowanie podtablicy o indeksach od l do m
        mergesort(arr, m + 1, r);   //sortowanie podtablicy o indeksach od m+1 do r
        merge(arr, l, m, r);        //scalenie 
    }
}

//implementacja algorytmu zaczerpnięta ze strony: https://binarnie.pl/sortowanie-przez-scalanie/

template <typename T>
void quicksort(T *arr, int l, int r) //tablica, lewy, prawy
{
  //odpowiednik partycjonowania
int piv=arr[(l+r)/2]; // piv - oś
int i=l;
int j=r;

do{
while (arr[i]<piv) i++;
while (arr[j]>piv) j--;
if (i<=j){
swap(arr[i], arr[j]);
i++;
j--;
}
}while (i<=j);
//rekurencyjne wywołanie
if (j>l) quicksort(arr, l, j);
if (i<r) quicksort(arr, i, r);
}  
//implementacja algorytmu zaczerpnięta ze strony: https://miroslawzelent.pl/kurs-c++/sortowanie-zlozonosc-algorytmow/


/////////////// sortowanie introspektywne - funkcje ////////////

template <typename T>
void MedianOfThree (T *arr, long &L, long &R)
{
  if (arr[++L-1]>arr[--R])
    swap(arr[L-1],arr[R]);
  if (arr[L-1]>arr[R/2])
    swap(arr[L-1],arr[R/2]);
  if (arr[R/2]>arr[R])
    swap(arr[R/2],arr[R]);
  swap(arr[R/2],arr[R-1]);
}
 
template <typename T>
long Partition (T *arr, long L, long R)
{
  long i, j;
  if (R>=3)
    MedianOfThree(arr,L,R);
  for (i=L, j=R-2; ; )
  {
    for ( ; arr[i]<arr[R-1]; ++i);
    for ( ; j>=L && arr[j]>arr[R-1]; --j);
    if (i<j)
      swap(arr[i++],arr[j--]);
    else break;
  }
  swap(arr[i],arr[R-1]);
  return i;
}

///////////////////////////////////////

template <typename T>
void Heapify (T *arr, long i, long N)
{
  long j;
  while (i<=N/2)
  {
    j=2*i;
    if (j+1<=N && arr[j+1]>arr[j])
      j=j+1;
    if (arr[i]<arr[j])
      swap(arr[i],arr[j]);
    else break;
    i=j;
  }
}

template <typename T>
void Heap_Sort (T *arr, long N)
{
  long i;
  for (i=N/2; i>0; --i)
    Heapify(arr-1,i,N);
  for (i=N-1; i>0; --i)
  {
    swap(arr[0],arr[i]);
    Heapify(arr-1,1,i);
  }
}

///////////////////////////////////////

template <typename T>
void Insertion_Sort (T *arr, long N)
{
  long i, j;
  T temp;
  for (i=1; i<N; ++i)
  {
    temp=arr[i];
    for (j=i; j>0 && temp<arr[j-1]; --j)
      arr[j]=arr[j-1];
    arr[j]=temp;
  }
}

///////////////////////////////////////

template <typename T>
void Intro_Sort (T *arr, long N, int M)
{
  long i;
  if (M<=0)
  {
    Heap_Sort(arr,N);
    return;
  }
  i=Partition(arr,0,N);
  if (i>16)
    Intro_Sort(arr,i,M-1);
  if (N-1-i>16)
    Intro_Sort(arr+i+1,N-1-i,M-1);
}

template <typename T>
void introsort (T *arr, long N)
{
  Intro_Sort(arr,N,(2*log(N))); //(int)floor(2*log(N)/M_LN2)
  Insertion_Sort(arr,N);
}

//implementacja algorytmu zaczerpnięta ze strony: https://pl.wikipedia.org/wiki/Sortowanie_introspektywne

////////////// sortowanie procenta elementów tablicy /////////////////

template <typename T>
void percentsort(T *arr, int f, int l, double percent) //tablica, pierwszy, ostatni, procent
{

    int split = (l + 1) * percent / 100; //dodajemy jedynkę, bo indeksy idą od 0

    T *arr1 = new T[split];  //tablica początkowych elemnetów, które zostaną posortowane
    T *arr2 = new T[l + 1 - split]; //reszta elementów, nieposortowana

//wypełnienie podtablic elementami z tablicy wyjściowej
    int i = 0, j = 0;
    while (i < split)
    {
        arr1[i] = arr[i];
        i++;
    }

    while (i <= l)
    {
        arr2[j] = arr[i];
        i++;
        j++;
    }

//posortowanie procenta tablic, czyli podtablicy arr1
    quicksort(arr1, 0, split - 1);
    
//scalenie podtablic (wzorowane na kodzie z funkcji merge)
    int x = 0, y = 0, z = 0;

    while (x < split)
    {
        arr[z++] = arr1[x++];
    }

    while (y < (l + 1 - split))
    {
        arr[z++] = arr2[y++];
    }
}

template<typename T>
void check(T *arr, int size) //sprawdzenie, czy się posortowało
{
    for (int i = 0; i < size - 1 ; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            std::cout << "Sortowanie nie powiodło się, koniec pracy programu\n";
            std::cin.get();
            exit(1);
        }
    }
}

#endif