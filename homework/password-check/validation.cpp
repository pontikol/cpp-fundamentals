	#include "validation.hpp"
	#include <cstdlib>
	#include <algorithm>
	#include  <cctype>

	std::string getErrorMessage(ErrorCode test)
	{
		switch (test) {
		case ErrorCode::Ok:
			return "Haslo jest poprawne";
		case ErrorCode::PasswordNeedsAtLeastNineCharacters:
			return "Haslo powinno zawierac conajmniej dziewiec znakow";
		case ErrorCode::PasswordNeedsAtLeastOneNumber:
			return "Haslo powinno zawierac conajmniej jedna cyfre";
		case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
			return "Haslo powinno zawierac conajmniej jeden znak specjalny";
		case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
			return "Haslo powinno zwierac conajmniej jedna duza litere";
		case ErrorCode::PasswordsDoNotMatch:
			return "Hasla nie sa takie same";
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

