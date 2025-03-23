#ifndef VALIDATION_HPP
#define VALIDATION_HPP
#include <string>

enum class ErrorCode {
    Ok = 2,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoNotMatch
};

std::string getErrorMessage(ErrorCode test);
bool doPasswordsMatch(std::string a, std::string b);
ErrorCode checkPasswordRules(std::string a);
ErrorCode checkPassword(std::string a, std::string b);

#endif
