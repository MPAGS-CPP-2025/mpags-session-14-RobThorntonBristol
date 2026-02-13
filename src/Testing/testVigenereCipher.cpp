//! Unit Tests for MPAGSCipher VigenereCipher Class
#include "gtest/gtest.h"

#include "VigenereCipher.hpp"

TEST(VigenereCipher, Encrypt)
{
    VigenereCipher vc{"LEMON"};
    EXPECT_EQ(vc.applyCipher("ATTACKATDAWN", CipherMode::Encrypt),
              "LXFOPVEFRNHR");
}

TEST(VigenereCipher, Decrypt)
{
    VigenereCipher vc{"LEMON"};
    EXPECT_EQ(vc.applyCipher("LXFOPVEFRNHR", CipherMode::Decrypt),
              "ATTACKATDAWN");
}