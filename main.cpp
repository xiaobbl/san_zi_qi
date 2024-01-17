#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>
#include "san_zi_qi.h"
#include "quan_ju.h"
#include "szq_drawFunc.h"

void initial() {
	initgraph(WIDTH, HEIGHT);//��ʼ������
	BeginBatchDraw();
	setlinestyle(PS_SOLID, LINE, nullptr, 0);
	hnd = GetHWnd();
	settextstyle(40, 0, _T("����"));
	SetWindowText(hnd, _T("������"));
}
int main() {
	initial();
	bool flag = true;
	qi_Ju* qi = new qi_Ju();
	while (flag) {//������Ϸ��ѭ��
		reset(*qi); 
		while(1)//��Ϸ���е�ѭ��
		{
			printCurrentPlayer();
			while (handle(*qi)) {
				if (!IsWindow(hnd))
					return 0;
			}//��ȡ�����������Ϣ
			if (qi->is_Win()) {
				TCHAR info1[20] = TEXT("���"), info2[30] = { 0 };
				wcscat(info1, (current_Player == CURRENT_C) ? L"��" : L"X");
				wcscat(info1, L"��ʤ�ˣ�");
				wcscpy(info2, info1);
				wcscat(info2, L"\n�Ƿ��ؿ���");
				int flag2 = MessageBox(hnd, info2, info1, MB_RETRYCANCEL | MB_ICONINFORMATION);
				if(flag2!=IDRETRY)
					flag = false;
				break;
			}
			else if (qi->isScoreDraw()) {
				TCHAR info1[] = TEXT("ƽ���ˣ�");
				TCHAR info2[] = TEXT("ƽ���ˣ�\n�Ƿ��ؿ���");
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