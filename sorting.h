#pragma once
#include "types.h"

typedef void(*sortFunction)(Array*,void(*)(Context*),Context*);



void bubbleSort(Array* array,void(*callBack)(Context*),Context* context);
//Cele de jos sunt implementate deja;
void selectionSort(Array* array,void(*callBack)(Context*),Context* context);
void insertionSort(Array* array, void(*callBack)(Context*),Context* context);
void quickSort(Array* array, void(*callBack)(Context*),Context* context);
void mergeSort(Array* array, void(*callBack)(Context*),Context* context);
