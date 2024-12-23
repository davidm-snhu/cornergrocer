#include <fstream>
#include <iostream>

#ifndef CORNERGROCER_STRINGCOUNTER_H
#define CORNERGROCER_STRINGCOUNTER_H
#include "StringCounter.h"
#endif

#ifndef CORNERGROCER_CORNERGROCERMENU_H
#define CORNERGROCER_CORNERGROCERMENU_H
#include "CornerGrocerMenu.h"
#endif

#define INPUT_FILENAME "CS210_Project_Three_Input_File.txt"
#define BACKUP_FILENAME "frequency.dat"


int main(int argc, char** argv) {
    auto inputWordFile = std::ifstream(INPUT_FILENAME);
    if (!inputWordFile.is_open()) {
        std::cout << "Error: Could not locate the input file \"" << INPUT_FILENAME << "\" in the current directory:\n\"" << argv[0] << "\"" << std::endl;
        std::cout << "Press enter to exit." << std::endl;
        std::cin.ignore();
        return -1;
    }

    auto stringCounter = StringCounter::fromFileLines(inputWordFile);
    inputWordFile.close();

    auto backupFile = std::ofstream(BACKUP_FILENAME);
    if (!backupFile.is_open()) {
        stringCounter.saveToFile(backupFile);
    } {
        std::cout << "Warning: Could not save a backup to \"" << BACKUP_FILENAME << "\" in the current directory:\n\"" << argv[0] << "\"\nThe program will continue." << std::endl;
    }
    backupFile.close();

    CornerGrocerMenu::run(stringCounter.viewCounts());
}