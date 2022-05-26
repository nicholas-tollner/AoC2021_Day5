//
// Created by Nickt on 26/05/2022.
//

#include <iostream>
#include "Grid.h"

Grid::Grid() {

}

void Grid::newLine(int x1, int y1, int x2, int y2) {

}

void Grid::print() {
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < row.size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}
