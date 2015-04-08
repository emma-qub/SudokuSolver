#include "Cell.h"

Cell::Cell(void):
  _remainingChoices(9, true),
  _value(-1) {
}

Cell::~Cell(void) {
}

void Cell::removeChoice(int choice) {
  _remainingChoices[choice-1] = false;
}

void Cell::insertChoice(int choice) {
  _remainingChoices[choice-1] = true;
}

bool Cell::isFilled(void) const {
  return _value != -1;
}
