#include "state.h"

State::State() {}
State::State(string text, bool isEncode){
    for (int i = 0; i < text.size(); i++) {
        char c = tolower(text[i]);
        if(c!=' ')
            distinctChars.insert(c);
    }
    this->isEncode = isEncode;
}
