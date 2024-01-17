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
	while (flag) {//������Ϸ��ѭ��
		reset(*qi); 
		while(1)//��Ϸ���е�ѭ��
		{
			SetWindowText(hnd, (const WCHAR*)(current_Player == CURRENT_C ? "��ҩ���" : "���X"));
			while (handle(*qi));//��ȡ�����������Ϣ
			if (qi->is_Win()) {
				char info1[20] = "���", info2[30] = { 0 };
				strcat(info1, (current_Player == CURRENT_C) ? "��" : "X");
				strcat(info1, "��ʤ�ˣ�");
				strcpy(info2, info1);
				strcat(info2, "\n�Ƿ��ؿ���");
				int flag2 = MessageBox(hnd, (const WCHAR*)info2, (const WCHAR*)info1, MB_RETRYCANCEL | MB_ICONINFORMATION);
				if(flag2!=IDRETRY)
					flag = false;
				break;
			}
			else if (qi->isScoreDraw()) {
				char info1[] = "ƽ���ˣ�";
				char info2[] = "ƽ���ˣ�\n�Ƿ��ؿ���";
				int flag2 = MessageBox(hnd, (const WCHAR*)info2, (const WCHAR*)info1, MB_RETRYCANCEL | MB_ICONINFORMATION);
				if (flag2 != IDRETRY)
					flag = false;
				break;
			}
			current_Player = !current_Player;
		}
		
	}
}