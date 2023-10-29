#pragma once
#include <cstddef>  //size_t

class CaesarCipher {
private:
    char* str;
    size_t length;
    int shift;

    char encryptChar(char c, int shift) const;
    char decryptChar(char c, int shift) const;

public:
    CaesarCipher(const char* s = "", int shift = 3); //used default params

    ~CaesarCipher();

    CaesarCipher(const CaesarCipher& other);

    CaesarCipher(CaesarCipher&& other) noexcept;

    void encrypt();
    void decrypt();

    void display() const;
};
