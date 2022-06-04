//
// Created by Nickt on 26/05/2022.
//

#include <iostream>
#include <fstream>
#include "Grid.h"

/**
 * Constructor for the Grid class
 */
Grid::Grid()
{
    for (int i = 0; i < 1000; i++)
    {
        grid.push_back(std::array<int, 1000>());
    }
}
/**
 * Marks the given coordinate on the grid vector
 * @param x1 first x coordinate
 * @param y1 first y coordinate
 * @param x2 second x coordinate
 * @param y2 second y coordinate
 */
void Grid::newLine(int x1, int y1, int x2, int y2) {
    int xDist = x2 - x1;
    int yDist = y2 - y1;
    double slope = (double) yDist / (double) xDist;

    // Line is horizontal when slope is 0
    if (std::abs(slope) == 0) {
        // Start counting from x2
        if (xDist < 0) {
            for (int i = x2; i <= abs(xDist) + x2; i++) {
                ++grid[y1][i];
            }
        } else {
            // Count from x1
            for (int i = x1; i <= xDist + x1; i++) {
                ++grid[y1][i];
            }
        }
        // Line is vertical when slope is infinity or -infinity
    } else if (slope == (1.0 / 0.0) || slope == (-1.0 / 0.0)) {
        // Start counting from y2
        if (yDist < 0)
        {
            for (int i = y2; i <= abs(yDist) + y2; i++) {
                ++grid[i][x1];
            }
        } else {
            // Count from y1
            for (int i = y1; i <= yDist + y1; i++) {
                ++grid[i][x1];
            }
        }
        // Line is diagonal when slope is 1 or -1
    } else if (abs(slope) == 1) {
        if (slope < 0 && xDist < 0)
        {
            int pos = x2;
            for (int i = y2; i >= y1; i--) {
                ++grid[i][pos];
                pos++;
            }
        } else if (slope < 0 && xDist > 0) {
            int pos = x1;
            for (int i = y1; i >= y2; i--) {
                ++grid[i][pos];
                pos++;
            }
        } else if (slope > 0 && xDist < 0) {
            int pos = x2;
            for (int i = y2; i <= y1; i++) {
                ++grid[i][pos];
                pos++;
            }
        } else if (slope > 0 && xDist > 0) {
            int pos = x1;
            for (int i = y1; i <= y2; i++) {
                ++grid[i][pos];
                pos++;
            }
        }
    }
}

/**
 * Iterates through grid vector and counts all instances greater than 1
 * @return Total number of overlaps
 */
int Grid::countOverlap() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
            if (grid[i][j] > 1)
            {
                count++;
            }
        }
    }
    return count;
}

/**
 * Iterates through grid vector and prints out all values
 */
void Grid::print() {
    std::cout << "\n";
    for (int i = 0; i < 10; i++) {
        std::cout << "   ";
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 0)
            {
                std::cout << ".";
            } else {
                std::cout << grid[i][j];
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Grid::writeToFile(std::ofstream &file) {

    if (!file)
    {
        printf("File could not be opened!");
        return;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 0)
            {
                file << ".";
            } else {
                file << grid[i][j];
            }
        }
        file << "\n";
    }
}

