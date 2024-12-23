#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

class StringCounter {
public:

    /// Goes over each line in a file and records how many times each unique line is repeated.
    static StringCounter fromFileLines(std::ifstream& source);

    /// Writes each key-value pair to a separate line in an output file.
    /// Each line has the key, a space, and then the count value.
    void saveToFile(std::ofstream& outputFile) const;

    /// Allows read-only access to the counter's internal hashmap
    const std::unordered_map<std::string, uint32_t>& viewCounts() const;
private:
    std::unordered_map<std::string, uint32_t> counts;
};