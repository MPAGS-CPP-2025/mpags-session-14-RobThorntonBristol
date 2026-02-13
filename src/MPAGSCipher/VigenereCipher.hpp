#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"

#include <map>
#include <string>
#include <cctype>

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the VigenereCipher class
 */

/**
 * \class VigenereCipher
 * \brief Encrypt or decrypt text using the Vigenere cipher with the given key
 */
class VigenereCipher {
  public:
    /**
     * \brief Create a new VigenereCipher, with the given key
     *
     * \param key The key to be used in the cipher
     */
    explicit VigenereCipher(const std::string& key);

    /**
     * \brief Apply the cipher to the provided text
     *
     * \param inputText The text to encrypt or decrypt
     * \param cipherMode Whether to encrypt or decrypt the input text
     * \return The result of applying the cipher to the input text
     */
    std::string applyCipher(const std::string& inputText,
                            const CipherMode cipherMode) const;

  private:
    /**
     * \brief Set and sanitise the cipher key
     */
    void setKey(const std::string& key);

    /// The cipher key
    std::string key_;

    /// Lookup table mapping key characters to CaesarCipher objects
    std::map<char, CaesarCipher> charLookup_;
};

#endif
