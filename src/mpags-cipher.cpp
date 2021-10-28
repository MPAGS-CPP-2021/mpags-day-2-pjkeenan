#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Our project headers - use "" not <> as internal to project
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCeasarCipher.hpp"

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool processStatus{false};
    bool helpRequested{false};
    bool versionRequested{false};
    bool encrypt{true};
    std::string inputFile{""};
    std::string outputFile{""};
    size_t key{0};

    // Parse command line args
    processStatus = processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, encrypt, key);
    if (!processStatus){
        return 1;
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << "  -e               Encrypt text with Ceasar cipher\n\n"
            << "  -d               Decrypt text with Ceasar cipher\n\n"
            << "  -k VALUE         Key for Ceasar cipher (en/de)cryption\n"
            << "                   Should be value >= 0\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string outputText;

    // Read in user input from stdin/file
    if (!inputFile.empty()) {
        // Open file and check can read
        std::ifstream inFileStream {inputFile};
        if (!inFileStream.good()){
            std::cerr << "[error] failed to produce ifstream on input file <" << inputFile << ">" << std::endl;
            return 1; 
        }

        // loop over each character from input file
        while (inFileStream >> inputChar) {
            outputText += transformChar (inputChar);
        }
    } // end if {have file with contents}

    else { // No input file with contents -> input from cin
        // loop over each character from user input
        while (std::cin >> inputChar) {
            outputText += transformChar (inputChar);
        }
    }

    outputText = runCeasarCipher(outputText, key, encrypt);

    // Output the transliterated text to stdout/file
    if (!outputFile.empty()) {
        // Open file and check can write
        std::ofstream outFileStream {outputFile};
        if (!outFileStream.good()){
            std::cerr << "[error] failed to produce ofstream on output file <" << outputFile << ">" << std::endl;
            return 1; 
        }
        // Put transliterated text into output file
        outFileStream << outputText << std::endl;
    } // end if {have file with contents}

    else { // No output file -> output to cout
        std::cout << outputText << std::endl;
    }

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}
