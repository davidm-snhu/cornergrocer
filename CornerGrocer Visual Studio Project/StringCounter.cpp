#ifndef CORNERGROCER_STRINGCOUNTER_H
#define CORNERGROCER_STRINGCOUNTER_H
#include "StringCounter.h"
#endif

StringCounter StringCounter::fromFileLines(std::ifstream& source) {
    std::unordered_map<std::string, uint32_t> counts;
    std::string lineBuffer;

    while (!source.eof() && source.good()) {
        std::getline(source, lineBuffer);
        counts[lineBuffer] += 1;
    }

    StringCounter sc;
    sc.counts = counts;
    return sc;
}
void StringCounter::saveToFile(std::ofstream& outputFile) const {
    for (auto it = counts.cbegin(); it != counts.cend(); it++) {
        outputFile << it->first << ' ' << it->second << std::endl;
    }
}

const std::unordered_map<std::string, uint32_t>& StringCounter::viewCounts() const {
    return counts;
}