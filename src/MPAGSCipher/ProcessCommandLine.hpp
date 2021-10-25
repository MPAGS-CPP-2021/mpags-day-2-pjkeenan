#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#include <string>
#include <vector>

// process the command line arguments processStatus = processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, encrypt, key);
bool processCommandLine(
const std::vector<std::string>& cmdLineArgs,
bool& helpRequested,
bool& versionRequested,
std::string& inputFile,
std::string& outputFile,
bool& encrypt,
size_t& key);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP