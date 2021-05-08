#pragma once

#include "types.h"

Window* createWindow(unsigned width,unsigned height,const char* name);
void draw(Array* array,Context* context);
int drawMenuButton(Context* context);
int drawMenu(Context* context);
int choices(Context* context, unsigned distance);
void destroyWindow();

