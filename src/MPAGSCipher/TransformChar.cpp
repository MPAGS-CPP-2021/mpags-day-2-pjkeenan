#include <string>
#include <cctype>

// Our project headers
#include "TransformChar.hpp"

std::string transformChar( const char inputChar ){
    
    /* transliteration of user input into required standard form
    
    argumemnts: const char inputChar - charcter to be transliterated

    return: string containiong the transliteration of the input charcter */

    std::string inputText;
    
    // Uppercase alphabetic characters
    if (std::isalpha(inputChar)) {
        inputText += std::toupper(inputChar);
        return inputText;
    }

    // Transliterate digits to English words
    switch (inputChar) {
        case '0':
            inputText += "ZERO";
            break;
        case '1':
            inputText += "ONE";
            break;
        case '2':
            inputText += "TWO";
            break;
        case '3':
            inputText += "THREE";
            break;
        case '4':
            inputText += "FOUR";
            break;
        case '5':
            inputText += "FIVE";
            break;
        case '6':
            inputText += "SIX";
            break;
        case '7':
            inputText += "SEVEN";
            break;
        case '8':
            inputText += "EIGHT";
            break;
        case '9':
            inputText += "NINE";
            break;
    }

    // If the character isn't alphabetic or numeric, DONT add it
    return inputText;
}