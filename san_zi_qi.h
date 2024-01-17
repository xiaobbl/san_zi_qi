#pragma once
class qi_Ju {
private:
    char qi_Pan[3][3];
public:
    int is_Win() const;
    void set(bool b, int x, int y);
    void reset();
    char get(int x, int y);
    int overflow(int x, int y);
    qi_Ju();
    bool isScoreDraw();
};