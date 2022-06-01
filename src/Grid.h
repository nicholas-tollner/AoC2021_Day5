//
// Created by Nickt on 26/05/2022.
//

#ifndef AOC2021_DAY5_GRID_H
#define AOC2021_DAY5_GRID_H

#include <array>

class Grid {
public:
    Grid();
    void newLine(int x1, int y1, int x2, int y2);
    void print();
    int countOverlap();

private:
    std::array<std::array<int, 10>, 10> grid = {};
    std::array<int, 10> row = {};
    int count = 0;
};


#endif //AOC2021_DAY5_GRID_H
