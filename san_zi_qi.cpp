#include <cstdio>
#include <ctype.h>

class qi_Ju {
private:
    char qi_Pan[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
public:
    int is_Win() const;
    void set(bool b, int x, int y);
    void reset();
    char get(int x, int y);
    int overflow(int x, int y);
    qi_Ju();
    bool isScoreDraw();
};
qi_Ju::qi_Ju()
{
}
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
char qi_Ju::get(int x, int y)
{
    return qi_Pan[x][y];
}
int qi_Ju::overflow(int x, int y)
{
    if (x > 2 || x < 0 || y > 2 || y < 0)
        return 1;
    return 0;
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
bool qi_Ju::isScoreDraw() {
    for (int i = 0; i < 9; i++) {
        if (((char*)qi_Pan)[i] == ' ')
            return false;
    }
    return true;
}