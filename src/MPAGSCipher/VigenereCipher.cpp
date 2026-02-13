#include "VigenereCipher.hpp"

#include <iostream>
#include <cctype>
#include <algorithm>

VigenereCipher::VigenereCipher(const std::string& key)
{
    this->setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{
    // Keep only alphabetic characters and uppercase them
    for (char c : key) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            key_ += std::toupper(static_cast<unsigned char>(c));
        }
    }

    // Default key if empty
    if (key_.empty()) {
        key_ = "A";  // shift 0 (safe default)
    }

    // Build lookup table
    for (char c : key_) {
        int shift = c - 'A';  // letter position
        charLookup_.insert({c, CaesarCipher(shift)});
    }
}


std::string VigenereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    std::string outputText{""};
    std::size_t keyIndex = 0;

    for (char c : inputText) {
            // Determine key character (repeat key)
            char keyChar = key_[keyIndex % key_.size()];

            // Retrieve CaesarCipher from lookup
            const CaesarCipher& cc = charLookup_.at(keyChar);

            // Encrypt/decrypt single character
            std::string letter(1, c);
            std::string result = cc.applyCipher(letter, cipherMode);

            outputText += result;

            ++keyIndex;
        }

    return outputText;
}
