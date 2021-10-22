#include <string>
#include <iostream>
#include <vector>

// Our project headers
#include "ProcessCommandLine.hpp"

// process the command line arguments
bool processCommandLine(
const std::vector<std::string>& cmdLineArgs,
bool& helpRequested,
bool& versionRequested,
std::string& inputFile,
std::string& outputFile){

    /*  parse and process the arguments given to mpags-cipher executable.
        modify helpRequested, versionRequired and in/out file variabkes as required by given args
    
    argumemts:
        const std::vector<std::string>& args   - Array of all arguments
        bool& helpRequested                    - bool signalling program help required
        bool& versionRequested                 - bool signalling program version number required
        std::string& inputFile                 - file to read input text from
        std::string& outputFile                - file to write output text to
    
    return:
        bool indicating if processComandLine was successful (0) or not (1)
    */

    // Status flag to indicate success of parsing, true for success, false for failure
    bool processStatus{true};

    //typedef std::vector<std::string>::size_type size_type;
    const size_t nArgs {cmdLineArgs.size()};
    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    for (size_t i{1}; i < nArgs; ++i) {
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            helpRequested = true;
        } else if (cmdLineArgs[i] == "--version") {
            versionRequested = true;
        } else if (cmdLineArgs[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                processStatus = false;
            } else {
                // Got filename, so assign value and advance past it
                inputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                processStatus = false;
            } else {
                // Got filename, so assign value and advance past it
                outputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << cmdLineArgs[i]
                      << "'\n";
            processStatus = false;
        }
    }
    return processStatus;
} // end cmdline parsing
