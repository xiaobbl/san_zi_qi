#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>
#include "san_zi_qi.h"
#include "quan_ju.h"
#include "szq_drawFunc.h"

void initial() {
	initgraph(WIDTH, HEIGHT);//初始化函数
	BeginBatchDraw();
	setlinestyle(PS_SOLID, LINE, nullptr, 0);
	hnd = GetHWnd();
	settextstyle(40, 0, _T("宋体"));
	SetWindowText(hnd, _T("三字棋"));
}
int main() {
	initial();
	bool flag = true;
	qi_Ju* qi = new qi_Ju();
	while (flag) {//重新游戏的循环
		reset(*qi); 
		while(1)//游戏进行的循环
		{
			printCurrentPlayer();
			while (handle(*qi)) {
				if (!IsWindow(hnd))
					return 0;
			}//获取并处理鼠标信息
			if (qi->is_Win()) {
				TCHAR info1[20] = TEXT("玩家"), info2[30] = { 0 };
				_tcscat(info1, (current_Player == CURRENT_C) ? _T("〇") : _T("X"));
				_tcscat(info1, _T("获胜了！"));
				_tcscpy(info2, info1);
				_tcscat(info2, _T("\n是否重开？"));
				int flag2 = MessageBox(hnd, info2, info1, MB_RETRYCANCEL | MB_ICONINFORMATION);
				if(flag2!=IDRETRY)
					flag = false;
				break;
			}
			else if (qi->isScoreDraw()) {
				TCHAR info1[] = TEXT("平局了！");
				TCHAR info2[] = TEXT("平局了！\n是否重开？");
				int flag2 = MessageBox(hnd, info2, info1, MB_RETRYCANCEL | MB_ICONINFORMATION);
				if (flag2 != IDRETRY)
					flag = false;
				break;
			}
			current_Player = !current_Player;
		}
	}
	EndBatchDraw();
	return 0;
}