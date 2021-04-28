#pragma once

typedef struct {

} Context;

typedef void(*sortFunction)(unsigned*,unsigned,void(*)(Context*),Context*);

void sortF(unsigned* arr,unsigned size,void(*callBack)(Context*),Context* context);

void sortBubble(unsigned* arr,unsigned size,void(*callBack)(Context*),Context* context);
void sortSelection(unsigned* arr,unsigned size,void(*callBack)(Context*),Context* context);
