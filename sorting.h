#pragma once

typedef struct {

} Context;

typedef struct{
  unsigned* data;
  unsigned size;

}Array;

typedef void(*sortFunction)(Array*,void(*)(Context*),Context*);



void sortBubble(Array* array,void(*callBack)(Context*),Context* context);
void sortSelection(Array* array,void(*callBack)(Context*),Context* context);
