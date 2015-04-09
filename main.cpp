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

  grid.fillCell(0, 0, 8);

  grid.fillCell(1, 3, 3);
  grid.fillCell(1, 2, 6);
  grid.fillCell(1, 3, 7);

  grid.fillCell(2, 1, 7);
  grid.fillCell(2, 4, 9);
  grid.fillCell(2, 6, 2);

  grid.fillCell(3, 1, 5);
  grid.fillCell(3, 5, 7);

  grid.fillCell(4, 4, 4);
  grid.fillCell(4, 5, 5);
  grid.fillCell(4, 6, 7);

  grid.fillCell(5, 3, 1);
  grid.fillCell(5, 7, 3);

  grid.fillCell(6, 0, 2);
  grid.fillCell(6, 3, 7);
  grid.fillCell(6, 4, 8);

  grid.fillCell(7, 2, 8);
  grid.fillCell(7, 3, 5);
  grid.fillCell(7, 7, 1);

  grid.fillCell(8, 1, 9);
  grid.fillCell(8, 6, 4);

  std::cerr << grid << std::endl;

  bool worked1;
  bool worked2;
  do {
    worked1 = grid.fillCells();
    worked2 = grid.fillOnlyChoices();
    std::cerr << "loop" << std::endl;
  } while(worked1 || worked2);

  std::cerr << grid << std::endl;

  return EXIT_SUCCESS;
}
