#include "caesarcipher.h"
#include <iostream>
#include <cstring>

CaesarCipher::CaesarCipher(const char *s, int sft) {
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
    shift = sft;
}

CaesarCipher::~CaesarCipher() {
    delete[] str;
}

CaesarCipher::CaesarCipher(const CaesarCipher& other) {
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);
    shift = other.shift;
}

CaesarCipher::CaesarCipher(CaesarCipher&& other) noexcept {
    str = other.str;
    length = other.length;
    shift = other.shift;
    other.str = nullptr;
    other.length = 0;
}

//todo decrypt & encrypt