#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>
#include <math.h>
#include "san_zi_qi.h"
#include "quan_ju.h"
#include "szq_drawFunc.h"

void draw_an_X(int x,int y,int radius) {//画一个X型
	line(x - radius, y - radius, x + radius, y + radius);
	line(x + radius, y - radius, x - radius, y + radius);
	return;
}
void reset(qi_Ju& qi) {
	cleardevice();
	qi.reset();
	current_Player = CURRENT_X;
	line(0, 300 + TEXT_HEIGHT, WIDTH, 300 + TEXT_HEIGHT);
	line(300, 0 + TEXT_HEIGHT, 300, HEIGHT + TEXT_HEIGHT);
	line(0, 600 + LINE + TEXT_HEIGHT, WIDTH, 600 + LINE + TEXT_HEIGHT);
	line(600 + LINE, 0 + TEXT_HEIGHT, 600 + LINE, HEIGHT + TEXT_HEIGHT);
	FlushBatchDraw();
}
bool handle(qi_Ju& qi) {
	ExMessage message;
	if (!peekmessage(&message))
		return true;
	if (message.message != WM_LBUTTONUP)
	{
		if (message.message == WM_MOVE)
			FlushBatchDraw();
		return true;
	}
	int x = message.x / (300 + LINE);
	int y = (message.y - TEXT_HEIGHT) / (300 + LINE);
	if (message.y < TEXT_HEIGHT || !isspace(qi.get(x, y)))
		return true;
	if (current_Player == CURRENT_X) {
		draw_an_X(x * (300 + LINE) + 150, y * (300 + LINE) + 150 + TEXT_HEIGHT, NORMAL_RADIUS);
	}
	else {
		circle(x * (300 + LINE) + 150, y * (300 + LINE) + 150 + TEXT_HEIGHT, NORMAL_RADIUS);
	}
	qi.set(current_Player, x, y);
	FlushBatchDraw();
	return false;
}
void printCurrentPlayer() {
	RECT r = { 0, 0, WIDTH, TEXT_HEIGHT };
	clearrectangle(0, 0, WIDTH, TEXT_HEIGHT);
	TCHAR char1[10] = L"玩家";
	wcscat(char1, current_Player == CURRENT_C ? L"〇" : L"X");
	wcscat(char1, L"：");
	drawtext(char1, &r, DT_LEFT);
	FlushBatchDraw();
}