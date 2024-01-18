#pragma once
#include "san_zi_qi.h"
#ifndef DRAWFUNC
#define DRAWFUNC
void draw_an_X(int x, int y, int radius);
void reset(qi_Ju& qi);
bool handle(qi_Ju& qi);
void printCurrentPlayer();
#endif // !DRAWFUNC
