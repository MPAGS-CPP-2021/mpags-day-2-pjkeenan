#include <string>

// Our project headers
#include "RunCeasarCipher.hpp"

std::string runCeasarCipher(const std::string& inputText, const size_t key, const bool encrypt){

    /*  (en/de)crypt input text via the Ceasar cipher
    
    argumemts:
        const std::string& inputText            - String of text to be (en/de)crypted
        const size_t key                        - The cipher key
        const bool encrypt                      - bool signalling if input text is to be en/de crypted
                                                  (true to encrypt, false to decrypt)

    return:
        string of (en/de)crypted text with the Ceasar cipher
    */

    // Create the alphabet container
    const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    // Create output string
    std::string cryptedText{""};
    // Flag sign as +1 for encrypt, -1 for decrypt
    int sign {1};
    if (!encrypt){
        sign = -1;
    }
    // Loop over transliterated input text
    for (const char& inputChar : inputText){

        // Find index of letter in alphabet
        int i{0}; // Declared outside of 'for loop' scope so can be used later
        for ( ; i < 26; i++){
            if (inputChar == alphabet[i]){
            //std::cout << "letter index: " << i << std::endl;
            break;
            }
        }

        // Apply encrypt/decrypt shift to position in alphabet index
        // making sure to wrap around ends
        // Force i -> [0, 25] to match alphabet index
        int shift = sign * key;
        i = (i+ shift) % 26;
        if (i<0){
            i+=26;
        }
        // Find new letter and add to output string
        cryptedText += alphabet[i];
        
    } // end loop over transliterated characters
    return cryptedText;
}