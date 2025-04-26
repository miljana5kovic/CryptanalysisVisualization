#ifndef STATE_H
#define STATE_H
#include <bits/stdc++.h>
using namespace std;

class State
{
private:
    bool isEncode;//weather it is encode or decode

public:
    unordered_set<char> distinctChars;
    State();
    State(string text, bool isEncode);
};

#endif // STATE_H
