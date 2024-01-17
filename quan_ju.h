#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>

#ifndef QUANJU
#define QUANJU

#define HEIGHT 1100
#define WIDTH 910
#define LINE 5
#define TEXT_HEIGHT 50
#define NORMAL_RADIUS 100
#define IS_X 1
#define IS_C 0
#define CURRENT_X false
#define CURRENT_C true
#define REFRESH_RATE 144
extern ExMessage* msg;
extern bool current_Player;
extern HWND hnd;

#endif // QUANJU