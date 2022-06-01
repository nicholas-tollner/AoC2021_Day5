//
// Created by Nickt on 26/05/2022.
//

#include <iostream>
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

    // Ignore diagonal lines
    if (x1 == x2 || y1 == y2) {
        // Work out if line is horizontal or vertical
        // e.g., if x2-x1 == 0 -> Line is vertical

        if (xDist == 0) {
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
        } else {
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
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}