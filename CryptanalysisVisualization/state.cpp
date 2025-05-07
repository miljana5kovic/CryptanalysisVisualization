#include "state.h"

State::State() {}
State::State(string text, bool isEncode) {
    int counter = 0;
    for (int i = 0; i < text.size(); i++) {
        char c = tolower(text[i]);
        if(c!=' ') {
            if(distinctChars.find(c) == distinctChars.end()) { pointerToChar[counter] = c; counter++; distinctChars[c] = counter; }
        }
    }
    this->isEncode = isEncode;
}
