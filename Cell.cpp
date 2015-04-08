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

std::vector<int> Cell::getChoices(void) const {
  std::vector<int> res;

  for (unsigned int k = 0; k < _remainingChoices.size(); ++k)
    if (_remainingChoices.at(k))
      res.push_back(k+1);

  return res;

}

bool Cell::isFilled(void) const {
  return _value != -1;
}

bool Cell::hasOnlyOneChoice(void) const {
  int choicesCount = 0;

  for (bool b: _remainingChoices)
    if (b)
      ++choicesCount;

  return choicesCount == 1;
}
