//
// Created by Nickt on 26/05/2022.
//

#ifndef AOC2021_DAY5_GRID_H
#define AOC2021_DAY5_GRID_H

#include <array>
#include <vector>

class Grid {
public:
    Grid();
    void newLine(int x1, int y1, int x2, int y2);
    void print();
    void writeToFile(std::ofstream &file);
    int countOverlap();

private:
    std::vector<std::array<int, 1000>> grid = {};
    int count = 0;
};

#endif //AOC2021_DAY5_GRID_H
