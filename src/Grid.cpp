//
// Created by Nickt on 26/05/2022.
//

#include <iostream>
#include "Grid.h"

Grid::Grid() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < row.size(); j++) {
            grid[i][j] = 0;
        }
    }
}

void Grid::newLine(int x1, int y1, int x2, int y2) {
    int xDist = x2 - x1;
    int yDist = y2 - y1;

    // Ignore diagonal lines
    if (x1 == x2 || y1 == y2) {
        // Work out if line is horizontal or vertical
        // e.g., if x2-x1 == 0 -> Line is vertical
        if (xDist == 0) {
            std::cout << "\nVert - Initial: " << x1 << "," << y1 << " Final: " << x2 << "," << y2
                      << " Distance Between Y: " << yDist;
            // Start counting from y2
            if (yDist < 0)
            {
                for (int i = y2; i <= abs(yDist) + y2; i++) {
                    ++grid[i][x1];

                    if (i == abs(yDist)) {
                        std::cout << " Drawn";
                    }
                }
            } else {
                // Count from y1
                for (int i = y1; i <= yDist + y1; i++) {
                    ++grid[i][x1];

                    if (i == yDist) {
                        std::cout << " Drawn";
                    }
                }
            }
        } else {
            std::cout << "\nHori - Initial: " << x1 << "," << y1 << " Final: " << x2 << "," << y2
                      << " Distance Between X: " << xDist;

            // Start counting from x2
            if (xDist < 0) {
                for (int i = x2; i <= abs(xDist) + x2; i++) {
                    ++grid[y1][i];

                    if (i == abs(xDist)) {
                        std::cout << " Drawn";
                    }
                }
            } else {
                // Count from x1
                for (int i = x1; i <= xDist + x1; i++) {
                    ++grid[y1][i];

                    if (i == xDist) {
                        std::cout << " Drawn";
                    }
                }
            }
        }
    }
}

/**
 * Iterates through grid vector and prints out all values
 */
void Grid::print() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < row.size(); j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/**
 * Iterates through grid vector and counts all instances greater than 1
 * @return Total number of overlaps
 */
int Grid::countOverlap() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < row.size(); j++) {
            if (grid[i][j] > 1)
            {
                count++;
            }
        }
    }
    return count;
}
