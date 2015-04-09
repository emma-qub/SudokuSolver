#include "Grid.h"

Grid::Grid(void) {
  for (int i = 0; i < 9; ++i) {
    std::vector<Cell*> line;
    for (int j = 0; j < 9; ++j) {
      line.push_back(new Cell);
    }
    _cells.push_back(line);
  }
}

Grid::~Grid(void) {
  for (auto line: _cells)
    for (Cell* cell: line)
      delete cell;
}

std::vector<Cell*> Grid::getLineFromCell(Cell* cell) const {
  int i = 0;
  int j = 0;
  getCellCoordinates(cell, i, j);

  return getLineFromCellCoordinate(i);
}

std::vector<Cell*> Grid::getLineFromCellCoordinate(int i) const {
  return _cells.at(i);
}

std::vector<Cell*> Grid::getColumnFromCell(Cell* cell) const {
  int i = 0;
  int j = 0;
  getCellCoordinates(cell, i, j);

  return getColumnFromCellCoordinate(j);
}

std::vector<Cell*> Grid::getColumnFromCellCoordinate(int j) const {
  std::vector<Cell*> column;

  for (int k = 0; k < 9; ++k) {
    column.push_back(_cells.at(k).at(j));
  }

  return column;
}

std::vector<Cell*> Grid::getCaseFromCell(Cell* cell) const {
  int i = 0;
  int j = 0;
  getCellCoordinates(cell, i, j);

  return getCaseFromCellCoordinate(i, j);
}

std::vector<Cell*> Grid::getCaseFromCellCoordinate(int i, int j) const {
  std::vector<Cell*> res;

  int fstLine = i/3;
  int fstColumn = j/3;
  for (int k = 0; k < 3; ++k) {
    for (int l = 0; l < 3; ++l) {
      res.push_back(_cells.at(3*fstLine+k).at(3*fstColumn+l));
    }
  }

  return res;
}

void Grid::fillCell(int i, int j, int value) {
  Cell* cell = _cells.at(i).at(j);
  fillCell(cell, value);
}

void Grid::fillCell(Cell* cell, int value) {
  cell->fill(value);

  for (Cell* currentCell: getLineFromCell(cell)) {
    currentCell->removeChoice(value);
  }

  for (Cell* currentCell: getColumnFromCell(cell)) {
    currentCell->removeChoice(value);
  }

  for (Cell* currentCell: getCaseFromCell(cell)) {
    currentCell->removeChoice(value);
  }
}

bool Grid::fillCells(void) {
  bool worked = false;

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      Cell* cell = _cells.at(i).at(j);
      if (!cell->isFilled() && cell->hasOnlyOneChoice()) {
        worked = true;
        std::cerr << "(" << i << "," << j << ") " << cell->getChoices().at(0) << std::endl;
        fillCell(cell, cell->getChoices().at(0));
      }
    }
  }

  return worked;
}

void Grid::fileOnlyChoice(int i, int j, int value, CellsSetType cellsSetType) {
  std::vector<Cell*> cells;
  switch (cellsSetType) {
  case CellsSetType::Line: {
    cells = getLineFromCellCoordinate(i);
    break;
  }
  case CellsSetType::Column: {
    cells = getColumnFromCellCoordinate(j);
    break;
  }
  case CellsSetType::Block: {
    cells = getCaseFromCellCoordinate(i, j);
    break;
  }
  default: {
    break;
  }
  }

  int countValues = 0;
  for (Cell* cell: cells) {
    if (!cell->isFilled() && cell->getChoices().at(value-1))
      ++countValues;
  }

  if (countValues == 1) {
    for (Cell* cell: cells) {
      if (!cell->isFilled() && cell->getChoices().at(value-1))
        fillCell(cell, value);
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Grid& grid) {
  os << "+---------------+---------------+---------------+\n";
  for (int i = 0; i < 27; ++i) {
    for (int j = 0; j < 9; ++j) {
      Cell* cell = grid._cells.at(i/3).at(j);
      if (j == 0 || (j%3 == 0 && j%9 != 0))
        os << "|";
      else
        os << "   ";
      if (cell->isFilled()) {
        if (i%3 == 0)
          os << "   ";
        else if (i%3 == 1)
          os << " " << cell->getValue() << " ";
        else if (i%3 == 2)
          os << "   ";
      } else {
        for (int k = 3*(i%3); k < 3*(i%3)+3; ++k) {
          cell->getRemainingChoices().at(k) ? os << k+1 : os << " ";
        }
      }
      if (j == 8)
        os << "|";
    }
    if ((i+1)%9 == 0)
      os << "\n+---------------+---------------+---------------+\n";
    else if ((i+1)%3 == 0)
      os << "\n|               |               |               |\n";
    else
      os << "\n";
  }

  return os;
}

void Grid::getCellCoordinates(Cell* cell, int& i, int& j) const {
  for (i = 0; i < 9; ++i) {
    for (j = 0; j < 9; ++j) {
      if (_cells.at(i).at(j) == cell) {
        return;
      }
    }
  }
}
