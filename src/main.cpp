//
// Created by Nickt on 25/05/2022.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "Grid.h"
#include "strings.h"


int main(int argc, const char *argv[])
{
    std::ifstream inFile("src/resources/input_test.txt");
    std::vector<std::string> lines;                 // All lines from input file
    std::vector<std::string> initialPos;            // Store x1, y1
    std::vector<std::string> finalPos;              // Store x2, y2

    std::array<int, 10> x1 = {};
    std::array<int, 10> y1 = {};
    std::array<int, 10> x2 = {};
    std::array<int, 10> y2 = {};

    Grid grid;

    std::string delim = "> ";
    size_t offset = delim.size();

    std::string line;

    while(std::getline(inFile, line))
    {
        lines.push_back(line);
    }

    // Process lines from input file
    for (int i = 0; i < lines.size(); i++)
    {
        std::vector<std::string> temp1 = {};
        std::vector<std::string> temp2 = {};

        line = lines[i];
        std::string secondHalf = line.substr(line.find(delim) + offset);

        std::stringstream firstCoords(line);
        getline(firstCoords, line, ' ');
        stringSplit(line, ',', temp1);

        initialPos.push_back(temp1[0] + " " + temp1[1]);

        std::stringstream secondCoords(secondHalf);
        getline(secondCoords, line, '\n');
        stringSplit(line, ',', temp2);

        finalPos.push_back(temp2[0] + " " + temp2[1]);
    }

    for (int i = 0; i < lines.size(); i++)
    {
        std::cout << initialPos[i] << "   " << finalPos[i] << std::endl;
    }

    //initialPos[i] - finalPos[i]
    // abs?

    return 0;
}