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

    std::vector<int> x1 = {};
    std::vector<int> y1 = {};
    std::vector<int> x2 = {};
    std::vector<int> y2 = {};

    Grid grid;

    std::string delim = "> ";
    size_t offset = delim.size();

    std::string line;

    // Read in lines from file and store in vector<string>
    while(std::getline(inFile, line))
    {
        lines.push_back(line);
    }

    // Process lines from vector<string> to vector<int>
    for (int i = 0; i < lines.size(); i++)
    {
        std::vector<std::string> temp1 = {};
        std::vector<std::string> temp2 = {};

        line = lines[i];
        std::string secondHalf = line.substr(line.find(delim) + offset);

        std::stringstream firstCoords(line);
        getline(firstCoords, line, ' ');
        stringSplit(line, ',', temp1);

        x1.push_back(stoi(temp1[0]));
        y1.push_back(stoi(temp1[1]));

        std::stringstream secondCoords(secondHalf);
        getline(secondCoords, line, '\n');
        stringSplit(line, ',', temp2);

        x2.push_back(stoi(temp2[0]));
        y2.push_back(stoi(temp2[1]));
    }

    for (int i = 0; i < lines.size(); i++)
    {
        std::cout << "Initial: " << x1[i] << ", " << y1[i] << "  Final: " << x2[i] << ", " << y2[i] << std::endl;
    }

    return 0;
}