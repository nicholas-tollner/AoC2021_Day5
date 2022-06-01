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
    std::vector<std::string> lines;                 // All lines from input file
    std::vector<int> x1, y1, x2, y2 = {};

    std::string delim = "> ";
    std::string line;

    size_t offset = delim.size();
    Grid grid;

    std::ifstream inFile("src/resources/input.txt");

    if (!inFile)
    {
        std::cout << "File could not be opened!" << std::endl;
    }

    // Read in lines from file and store in vector<string>
    while(std::getline(inFile, line))
    {
        lines.push_back(line);
        std::cout << "Added: " << line << std::endl;
    }

    // Process lines from vector<string> to vector<int>
    for (auto s : lines)
    {
        std::vector<std::string> temp1 = {};
        std::vector<std::string> temp2 = {};

        std::string secondHalf = s.substr(s.find(delim) + offset);

        std::stringstream firstCoords(s);
        getline(firstCoords, s, ' ');
        stringSplit(s, ',', temp1);

        x1.push_back(stoi(temp1[0]));
        y1.push_back(stoi(temp1[1]));

        std::stringstream secondCoords(secondHalf);
        getline(secondCoords, s, '\n');
        stringSplit(s, ',', temp2);

        x2.push_back(stoi(temp2[0]));
        y2.push_back(stoi(temp2[1]));
    }

    // Map all coordinate on grid
    for (int i = 0; i < lines.size(); i++)
    {
        grid.newLine(x1[i], y1[i], x2[i], y2[i]);
    }

    std::cout << "Total Overlapping Points: " << grid.countOverlap() << std::endl;
    return 0;
}