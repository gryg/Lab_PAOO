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


char CaesarCipher::encryptChar(char c, int shift) const {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return (c - base + shift) % 26 + base;
    }
    return c;
}

char CaesarCipher::decryptChar(char c, int shift) const {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return (c - base - shift + 26) % 26 + base; // +26 in order to handle negative shifts
    }
    return c;
}