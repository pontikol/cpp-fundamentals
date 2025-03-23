	#include "validation.hpp"
	#include <cstdlib>
	#include <algorithm>
	#include  <cctype>

	std::string getErrorMessage(ErrorCode test)
	{
		switch (test) {
		case ErrorCode::Ok:
			return "Ok";
		case ErrorCode::PasswordNeedsAtLeastNineCharacters:
			return "Password needs to have at least nine characters";
		case ErrorCode::PasswordNeedsAtLeastOneNumber:
			return "Password needs to have at least one number";
		case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
			return "Password needs to have at least one special character";
		case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
			return "Password needs to have at least one uppercase letter";
		case ErrorCode::PasswordsDoNotMatch:
			return "Passwords do not match";
		default:
			return "Nieznany blad";
		}
	};

	bool doPasswordsMatch(std::string a, std::string b) {

		return a == b;
	}

	ErrorCode checkPasswordRules(std::string a) {
		if (a.size() >= 9) {
			if(std::any_of(a.begin(), a.end(), [](char x) { return isdigit(x); } )){
				if (std::any_of(a.begin(), a.end(), [](char x) { return ispunct(x); })) {
					if (std::any_of(a.begin(), a.end(), [](char x) { return isupper(x); })) {
						return ErrorCode::Ok;
					}
					else { return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter; }
				}
				else {
					return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
				}
			}
			else { return ErrorCode::PasswordNeedsAtLeastOneNumber;}
		}
		else {
			return ErrorCode::PasswordNeedsAtLeastNineCharacters;}
	}

	ErrorCode checkPassword(std::string a, std::string b) {
		if (doPasswordsMatch(a, b)) {
			return checkPasswordRules(a);
		}
		else return ErrorCode::PasswordsDoNotMatch;
	}

