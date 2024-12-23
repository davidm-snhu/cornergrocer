#ifndef CORNERGROCER_CORNERGROCERMENU_H
#define CORNERGROCER_CORNERGROCERMENU_H
#include "CornerGrocerMenu.h"
#endif


bool menuOptionIsValid(const std::string& input) {
    return input == "1" || input == "2" || input == "3" || input == "4";
}
void search_for_item(const std::unordered_map<std::string, uint32_t>& counts) {
    std::string itemBuffer;
    std::cout << "Enter the item you would like to search for: ";
    std::getline(std::cin, itemBuffer);

    auto it = counts.find(itemBuffer);
    uint32_t foundCount = 0;
    if (it != counts.end()) {
        foundCount = it->second;
    }

    std::cout << foundCount << std::endl;
}
void printAllCountsNumeric(const std::unordered_map<std::string, uint32_t>& counts, uint32_t longestItemLength) {
    // for each key-value pair
    for (auto it = counts.cbegin(); it != counts.cend(); it++) {
        // print the string key
        std::cout << it->first;

        // print enough padding afterward to align the numbers vertically
        for (uint32_t i = 0; i <= longestItemLength - it->first.length(); i++) {
            std::cout << ' ';
        }

        // priunt the int value and go to the next line
        std::cout << ' ' << it->second << std::endl;
    }
}
void printAllCountsHistogram(const std::unordered_map<std::string, uint32_t>& counts, uint32_t longestItemLength) {
    // for each key-value pair
    for (auto it = counts.cbegin(); it != counts.cend(); it++) {
        // print the key
        std::cout << it->first;
        // print enough spaces to make each line's first asterisk line up
        for (uint32_t i = 0; i <= longestItemLength - it->first.length(); i++) {
            std::cout << ' ';
        }
        // print one asterisk for each time the key was counted in the  input
        for (uint32_t i = 0; i < it->second; i++) {
            std::cout << '*';
        }
        
        std::cout << std::endl;
    }
}

void CornerGrocerMenu::run(const std::unordered_map<std::string, uint32_t>& counts) {

    // determine how long the longest string in the map is, and retain that count
    // this is used for text padding later
    uint32_t longestItemLength = 0;
    for (auto it = counts.cbegin(); it != counts.cend(); it++) {
        if (it->first.length() > longestItemLength) {
            longestItemLength = it->first.length();
        }
    }

    std::string menuChoice = "0";
    // continue looping until the user chooses to exit
    while (menuChoice != "4") {
        // print the menu options and ask for a response until a valid response is given
        do {
            std::cout << "\n\n\n" << std::endl;
            std::cout << "Please enter one of the following options:" << std::endl;
            std::cout << "1: Search for a specific item" << std::endl;
            std::cout << "2: Print all item counts (numeric)" << std::endl;
            std::cout << "3: Print all item counts (histogram)" << std::endl;
            std::cout << "4: Exit" << std::endl;
            std::getline(std::cin, menuChoice);
        } while (!menuOptionIsValid(menuChoice));
        std::cout << std::endl;

        // carry out the user's choice
        switch (std::stoi(menuChoice)) {
        case 1:
            search_for_item(counts);
            break;
        case 2:
            printAllCountsNumeric(counts, longestItemLength);
            break;
        case 3:
            printAllCountsHistogram(counts, longestItemLength);
            break;
        case 4:
            std::cout << "Exiting program." << std::endl;
            return;
        default:
            // should be unreachable thanks to checking with menuOptionIsValid
            return;
        }
        std::cout << "Press enter to return to the main menu." << std::endl;
        std::cin.ignore();
    }
}