#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>

#include "Cell.h"

class Grid
{
public:
  Grid(void);
  virtual ~Grid(void);

  std::vector<Cell*> getLineFromCell(Cell* cell) const;
  std::vector<Cell*> getColumnFromCell(Cell* cell) const;
  std::vector<Cell*> getCaseFromCell(Cell* cell) const;

  void fillCell(int i, int j, int value);
  void fillCell(Cell* cell, int value);
  bool fillCells(void);

  friend std::ostream& operator<<(std::ostream& os, const Grid& grid);

private:
  void getCellCoordinates(Cell* cell, int& i, int& j) const;
  Cell* getCell(int i, int j) const;

private:
  std::vector<std::vector<Cell*>> _cells;
};

#endif // GRID_H
