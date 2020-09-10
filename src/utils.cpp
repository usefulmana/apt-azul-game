#include "utils.h"
#include <sstream>
#include <iostream>
#include <time.h>

#define FIRST_FACTORY 0
#define LAST_FACTORY 5

#define FIRST_STORAGE_ROW 1
#define LAST_STORAGE_ROW 5

/**
 * Split a string into elements of a vector
 * @param str : a string to be split
 * @param delimiter : a char to split
 * @return : a vector containing the split string
 */
std::vector<std::string> splitString(std::string str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string temp;
    while (std::getline(ss, temp, delimiter)){
        result.push_back(temp);
    }
    return result;
}

/**
 * Checking player's input
 * @param input : input string to be checked
 * @return : a vector containing errors of the player's input
 */
std::vector<std::string> checkInput(std::string input) {
    std::vector<std::string> result;
    std::vector<std::string> inputArr = splitString(input, ' ');
    std::string colors = "RYBLUF.";

    // Check if entered num of args for save
    if (inputArr.size() == 2){
        // Check for save command
        if (inputArr[0] != "save") {
            result.push_back("Invalid input. Correct input = save. Your input = " + inputArr[0]);
        }
    }
    // Check if entered num of args for turn
    else if (inputArr.size() == 4){
        // Check for turn command
        if (inputArr[0] != "turn") {
            result.push_back("Invalid input. Correct input = turn. Your input = " + inputArr[0]);
        }

        // Check Inputted Factory Number
        try {
            // Convert input from string to int
            int factory = std::stoi(inputArr[1]);
            if (factory < FIRST_FACTORY || factory > LAST_FACTORY) {
                result.push_back("Invalid Factory #. Please enter an integer number for factories (0->5). Your input = "
                                 + inputArr[1]);
            }
        }
        catch (std::exception const &e) {
            result.push_back(
                    "Invalid factory #. Please enter an integer number for factories (0->5). Your input = " + inputArr[1]);
        }

        // Check Inputted Colour
        size_t correctColor = colors.find(inputArr[2]);
        if (correctColor == std::string::npos){
            result.push_back("Invalid color. Color should be R,Y,B,L,U. Your input: " + inputArr[2]);
        }

        // Check Inputted Storage Row
        try {
            // Convert input from string to int
            int storageRow = std::stoi(inputArr[3]);
            if (storageRow < FIRST_STORAGE_ROW || storageRow > LAST_STORAGE_ROW) {
                result.push_back(
                    "Invalid Storage #. Please enter an integer number for storage number (1->5). Your input = " + inputArr[3]);
            }
        }
        catch (std::exception const &e) {
            result.push_back(
                    "Invalid Storage #. Please enter an integer number for storage number (1->5). Your input = " + inputArr[3]);
        }

        // TODO Check move validity
    }
    else {
        result.push_back("Wrong number of arguments or arguments are not separated by space. Your input = " + input);
    }

    return result;
}

/**
 * Get current date time
 * @return a datetime string. Format is YYYYMMDDHHMMSS
 */
const std::string getDateTime(){
    // Current time of system
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", &tstruct);
    return buf;
}

/**
 * Write a string to a file
 * @param fileName : target file's name
 * @param str : string to be written
 */
void writeToFile(const std::string & fileName, const std::string & str){
    std::ofstream file;
    file.open(fileName, std::ios_base::app);
    file << str + '\n';
    file.close();
}

/**
 * Write a vector of strings to a file
 * @param fileName : target file's name
 * @param str : string vector to be written
 */
void writeMultipleStrToFile(const std::string & fileName, std::vector<std::string> vector){
    std::ofstream file;
    file.open(fileName);
    for (auto & str: vector){
        file << str + '\n';
    }
    file.close();
}

/**
 * Delete a file
 * @param fileName: target file's name
 */
void deleteAFile(const std::string & fileName){
    const int success = std::remove(fileName.c_str());
    if( success == 0 ){
        std::cout << "Successfully deleted " << fileName << std::endl;
    } else {
        std::cout << "Failed to delete " << fileName << std::endl;
    }
}

/**
 * Rename a file
 * @param oldName: old name of the file
 * @param newName: new name of the file
 */
void renameAFile(const std::string & oldName, const std::string & newName){
    std::rename(oldName.c_str(), newName.c_str());
}

/**
 * Check if a file exists
 * @param file : file to check
 * @return : true if the file exists, false if not
 */
bool checkIfFileExists(const char* file){
    std::ifstream f(file);
    return f.good();
}

/**
 * Quit the game
 */
void quitGame() {
    std::cout << std::endl;
    std::cout << "Quitting the game. See you again!" << std::endl;

    // Quit
    exit(0);
}