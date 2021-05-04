#pragma once
#include "types.h"


typedef void(*sortFunction)(Array*,void(*)(Context*),Context*);



void sortBubble(Array* array,void(*callBack)(Context*),Context* context);
void sortSelection(Array* array,void(*callBack)(Context*),Context* context);
