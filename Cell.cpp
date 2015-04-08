#include "Cell.h"
#include <algorithm>

Cell::Cell(void) {
  for (int k = 1; k < 10; ++k) {
    _remainingChoices.push_back(k);
  }
}

Cell::~Cell(void) {
}

void Cell::removeChoice(int choice) {
  auto it = _remainingChoices.begin();
  for (; it != _remainingChoices.end(); ++it) {
    if (*it == choice) {
      _remainingChoices.erase(it);
      return;
    }
  }
}

void Cell::insertChoice(int choice) {
  auto it = _remainingChoices.begin();
  for (; it != _remainingChoices.end(); ++it) {
    if (choice == *it) {
      return;
    }
  }

  _remainingChoices.insert(it, choice);
  std::sort(_remainingChoices.begin(), _remainingChoices.end());
}

bool Cell::isFilled(void) const {
  return _remainingChoices.size() == 1;
}
