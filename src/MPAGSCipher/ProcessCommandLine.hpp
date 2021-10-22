#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#include <string>
#include <vector>

// process the command line arguments
bool processCommandLine(
const std::vector<std::string>& cmdLineArgs,
bool& helpRequested,
bool& versionRequested,
std::string& inputFile,
std::string& outputFile);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP