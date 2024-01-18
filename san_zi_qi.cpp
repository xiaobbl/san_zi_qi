#include <cstdio>
#include <ctype.h>
#include "san_zi_qi.h"

void qi_Ju::set(bool b, int x, int y)
{
    if (b)
        qi_Pan[x][y] = '*';
    else
        qi_Pan[x][y] = '#';
    return;
}
void qi_Ju::reset() {
    for (int i = 0; i < 9; i++)
        qi_Pan[0][i] = ' ';
}
char qi_Ju::get(int x, int y) const
{
    return qi_Pan[x][y];
}
int qi_Ju::is_Win() const
{
    if (
        (qi_Pan[0][0] == qi_Pan[0][1] && qi_Pan[0][0] == qi_Pan[0][2] && qi_Pan[0][0] != ' ') ||
        (qi_Pan[0][0] == qi_Pan[1][0] && qi_Pan[0][0] == qi_Pan[2][0] && qi_Pan[0][0] != ' ') ||
        (qi_Pan[2][0] == qi_Pan[2][1] && qi_Pan[2][0] == qi_Pan[2][2] && qi_Pan[2][0] != ' ') ||
        (qi_Pan[0][2] == qi_Pan[1][2] && qi_Pan[0][2] == qi_Pan[2][2] && qi_Pan[0][2] != ' ') ||
        (qi_Pan[0][0] == qi_Pan[1][1] && qi_Pan[0][0] == qi_Pan[2][2] && qi_Pan[0][0] != ' ') ||
        (qi_Pan[1][0] == qi_Pan[1][1] && qi_Pan[1][0] == qi_Pan[1][2] && qi_Pan[1][0] != ' ') ||
        (qi_Pan[0][1] == qi_Pan[1][1] && qi_Pan[0][1] == qi_Pan[2][1] && qi_Pan[0][1] != ' ') ||
        (qi_Pan[2][0] == qi_Pan[1][1] && qi_Pan[2][0] == qi_Pan[0][2] && qi_Pan[0][2] != ' '))
        return 1;
    else
        return 0;
}
bool qi_Ju::isScoreDraw() const {
    for (int i = 0; i < 9; i++) {
        if (qi_Pan[0][i] == ' ')
            return false;
    }
    return true;
}