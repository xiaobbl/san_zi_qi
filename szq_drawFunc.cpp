#include <graphics.h>
#include <math.h>
#include "san_zi_qi.h"
#include "quan_ju.h"

void draw_an_X(int x,int y,int radius) {//»­Ò»¸öXÐÍ
	double half_length = sqrt(2.0) * (double)radius;
	line(x - half_length, y - half_length, x + half_length, y + half_length);
	line(x + half_length, y - half_length, x - half_length, y + half_length);
	return;
}
void reset(qi_Ju& qi) {
	cleardevice();
	qi.reset();
	current_Player = CURRENT_X;
	line(0, 300, WIDTH, 300);
	line(300, 0, 300, HEIGHT);
	line(0, 600 + LINE, WIDTH, 600 + LINE);
	line(600 + LINE, 0, 600 + LINE, HEIGHT);
	FlushBatchDraw();
}
bool handle(qi_Ju& qi) {
	ExMessage message;
	getmessage(&message);
	msg = &message;
	if (msg->message != WM_LBUTTONUP)
		return true;
	int x = msg->x / (300 + LINE);
	int y = msg->y / (300 + LINE);
	if (!isspace(qi.get(x, y)))
		return true;
	if (current_Player == CURRENT_X) {
		draw_an_X(x * (300 + LINE) + 150, y * (300 + LINE) + 150, NORMAL_RADIUS);
	}
	else {
		circle(x * (300 + LINE) + 150, y * (300 + LINE) + 150, NORMAL_RADIUS);
	}
	qi.set(current_Player, x, y);
	FlushBatchDraw();
	return false;
}