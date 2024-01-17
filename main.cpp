#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>
#include "san_zi_qi.h"
#include "quan_ju.h"
#include "szq_drawFunc.h"

void initial() {
	initgraph(WIDTH, HEIGHT);
	BeginBatchDraw();
	setlinestyle(PS_SOLID, LINE, nullptr, 0);
	hnd = GetHWnd();
}
int main() {
	initial();
	bool flag = true;
	qi_Ju* qi = new qi_Ju();
	while (flag) {//重新游戏的循环
		reset(*qi); 
		while(1)//游戏进行的循环
		{
			SetWindowText(hnd, (const WCHAR*)(current_Player == CURRENT_C ? "玩家〇：" : "玩家X"));
			while (handle(*qi));//获取并处理鼠标信息
			if (qi->is_Win()) {
				char info1[20] = "玩家", info2[30] = { 0 };
				strcat(info1, (current_Player == CURRENT_C) ? "〇" : "X");
				strcat(info1, "获胜了！");
				strcpy(info2, info1);
				strcat(info2, "\n是否重开？");
				int flag2 = MessageBox(hnd, (const WCHAR*)info2, (const WCHAR*)info1, MB_RETRYCANCEL | MB_ICONINFORMATION);
				if(flag2!=IDRETRY)
					flag = false;
				break;
			}
			else if (qi->isScoreDraw()) {
				char info1[] = "平局了！";
				char info2[] = "平局了！\n是否重开？";
				int flag2 = MessageBox(hnd, (const WCHAR*)info2, (const WCHAR*)info1, MB_RETRYCANCEL | MB_ICONINFORMATION);
				if (flag2 != IDRETRY)
					flag = false;
				break;
			}
			current_Player = !current_Player;
		}
		
	}
}