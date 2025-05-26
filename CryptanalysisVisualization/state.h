#ifndef STATE_H
#define STATE_H
#include <bits/stdc++.h>
using namespace std;

class State
{
private:
    bool isEncode;//weather it is encode or decode

public:
    map<char, int> distinctChars;
    map<int, char> pointerToChar;

    map<char, char> letterMappings;
    State();
    State(string text, bool isEncode);
};

#endif // STATE_H
