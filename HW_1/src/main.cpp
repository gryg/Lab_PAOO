#include "lib/caesarcipher.h"
#include <iostream>
#include <utility>


int main() {
    // Original object
    CaesarCipher originalText("Decoy text message longer than expected zzzzzzz!", 7);
    originalText.encrypt();
    std::cout << "Original: ";
    originalText.display();

    // Use the copy constructor
    CaesarCipher copiedText = originalText;
    std::cout << "Copied: ";
    copiedText.display();

    // Make some changes to demonstrate independence of copied object
    copiedText.decrypt();
    std::cout << "Copied (after decryption): ";
    copiedText.display();

    // Original remains unchanged
    std::cout << "Original (after copying): ";
    originalText.display();

    // Use the move constructor
    CaesarCipher movedText = std::move(copiedText);
    std::cout << "Moved: ";
    movedText.display();

    // Attempting to use the moved-from object will give undefined behavior. 
    // Ideally, you shouldn't use the moved-from object further.
    std::cout << "-----------------\n   Copied (after moving): ";
    copiedText.display();  // This might give undefined results or even crash. Avoid using moved-from objects.

    return 0;
}
