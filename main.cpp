#include <cstdlib>
#include <iostream>

#include "Grid.h"

void displayRemainingChoices(const Cell& c) {
  for (int possible: c.getRemainingChoices())
    std::cerr << possible << " ";
  std::cerr << std::endl;
}

int main(int argc, char** argv) {
  Grid grid;

  grid.fillCell(0, 0, 1);
  grid.fillCell(0, 2, 6);
  grid.fillCell(0, 3, 3);

  grid.fillCell(1, 3, 4);
  grid.fillCell(1, 4, 1);
  grid.fillCell(1, 7, 6);
  grid.fillCell(1, 8, 7);

  grid.fillCell(2, 4, 6);
  grid.fillCell(2, 5, 9);
  grid.fillCell(2, 8, 2);

  grid.fillCell(3, 0, 9);
  grid.fillCell(3, 2, 8);
  grid.fillCell(3, 3, 7);
  grid.fillCell(3, 6, 2);
  grid.fillCell(3, 8, 6);

  grid.fillCell(4, 1, 5);
  grid.fillCell(4, 4, 9);
  grid.fillCell(4, 7, 4);

  grid.fillCell(5, 0, 7);
  grid.fillCell(5, 2, 3);
  grid.fillCell(5, 5, 4);
  grid.fillCell(5, 6, 9);
  grid.fillCell(5, 8, 8);

  grid.fillCell(6, 0, 8);
  grid.fillCell(6, 3, 6);
  grid.fillCell(6, 4, 7);

  grid.fillCell(7, 0, 3);
  grid.fillCell(7, 1, 1);
  grid.fillCell(7, 4, 4);
  grid.fillCell(7, 5, 8);

  grid.fillCell(8, 5, 1);
  grid.fillCell(8, 6, 8);
  grid.fillCell(8, 8, 5);

  std::cerr << grid << std::endl;

  bool worked;
  do {
    worked = grid.fillCells();
  } while(worked);

  std::cerr << grid << std::endl;

  return EXIT_SUCCESS;
}
