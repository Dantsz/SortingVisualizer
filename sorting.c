#include "sorting.h"
#include <stdlib.h>

//Merge Sort Algorithm
static void merge(Array* array, unsigned middle, unsigned left, unsigned right,void(*callBack)(Context*),Context* context)
{
    unsigned n1 = middle - left + 1;
    unsigned n2 = right - middle ;
    unsigned *v1 = malloc(n1 * sizeof (unsigned ));
    unsigned *v2 = malloc(n2 * sizeof (unsigned ));

    for(unsigned i = 0; i < n1; i++)
        v1[i] = array->data[left+i];
    for(unsigned i =0; i< n2; i++)
        v2[i] = array->data[middle+1+i];
    unsigned i = 0, j = 0, k = left;
    while(i < n1 && j < n2)
    {
        if(v1[i]< v2[j])
        {
            array->data[k] = v1[i];
            callBack(context); //aici se modifica ceva si trebuie printat pe ecran;
            i++;
        }
        else
        {
            array->data[k] = v2[j];
            callBack(context);//aici se modifica ceva si trebuie printat pe ecran;
            j++;
        }
        k++;
    }
    //daca cumva au mai ramas elemente ori in subvectorul stang ori in subvectorul drept le adaugam la final.
    while(i < n1)
    {
        array->data[k] = v1[i];
        callBack(context);
        i++;
        k++;
    }
    while(j < n2)
    {
        array->data[k] = v2[j];
        callBack(context);
        j++;
        k++;
    }

}
static void mergeSorting(Array* array, unsigned left, unsigned right,void(*callBack)(Context*),Context* context )
{
    if(left<right) {
        unsigned middle = (left + right) / 2; //cautam mijlocul vectorului pe care vrem sa il aranjam
        mergeSorting(array, left, middle,callBack,context);
        mergeSorting(array, middle + 1,right,callBack,context); //apelam metoda divide et impera pt a sorta pe rand toti subvectorii array-ului
        merge(array, middle, left, right,callBack,context);//apelam functia pentru a lipi cei doi subvectori ordonati
    }
}
void mergeSort(Array* array, void(*callBack)(Context*),Context* context)
{
    mergeSorting(array,0,array->size-1,callBack,context);
}

//Quick Sort Algorithm

static unsigned pivot(Array* array,unsigned left, unsigned right,void(*callBack)(Context*),Context* context)
{
    unsigned piv = array->data[right];
    unsigned index = left-1;
    unsigned aux;
    for(unsigned i = left; i < right; i++)
    {
        if(array->data[i] < piv)
        {
            index++;
            aux = array->data[index];
            array->data[index] = array->data[i];
            // aici nu apelam callback deoarece ne dorim sa ne arate pe ecran direct liniile inversate
            array->data[i] = aux;
            callBack(context); // se face o modificare deci reapelam modificarea ecranului

        }
    }
    aux = array->data[index + 1];
    array->data[index + 1] = array->data[right];
    array->data[right] = aux;
    callBack(context); // se face o modificare deci reapelam modificarea ecranului
    return index + 1;
}

static void quickSorting(Array* array,unsigned left,unsigned right,void(*callBack)(Context*),Context* context)
{
    if(left < right)
    {
        unsigned piv = pivot(array, left, right,callBack,context);
        quickSorting(array, left, piv - 1,callBack,context);
        quickSorting(array, piv + 1, right,callBack,context);
    }
}

void quickSort(Array* array, void(*callBack)(Context*),Context* context)
{
    quickSorting(array,0,array->size-1,callBack,context);
}

//Selection Sort Algorithm

static void swap(unsigned *a, unsigned *b)
{
    unsigned aux = *a;
    *a = *b;
    *b = aux;
}
static unsigned minim(Array* array, unsigned begin)
{
   unsigned min = array->data[begin], indexMin = begin;
   for(unsigned i = begin + 1; i < array->size; i++)
   {
       if(array->data[i] < min) {
           min = array->data[i];
           indexMin = i;
       }

   }
   return indexMin;
}
void selectionSort(Array* array,void(*callBack)(Context*),Context* context){
       for(unsigned i = 0; i < array->size; i++)
       {
           unsigned min = minim(array,i);
           swap(&array->data[min],&array->data[i]);
           callBack(context);// dupa ce am modificat ceva trimitem la ecran pentru a modifica grafica
       }

}

// Insertion Sort Algorithm

void insertionSort(Array* array, void(*callBack)(Context*),Context* context)
{
    unsigned elem;
    for(unsigned i = 1; i < array->size; i++)
    {
        elem = array->data[i];
        unsigned j = i - 1;
        while(j >= 0 && elem < array->data[j])
        {
            array->data[j+1] = array->data[j];
            callBack(context); //aici se modifica un element care trebuie transmis la ecran
            j--;
        }
        array->data[j + 1] = elem;
        callBack(context);

    }
}