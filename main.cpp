#include <cstdlib>
#include <iostream>

#include "Cell.h"

void displayRemainingChoices(const Cell& c) {
  for (int possible: c.getRemainingChoices())
    std::cerr << possible << " ";
  std::cerr << std::endl;
}

int main(int argc, char** argv) {

  Cell c;
  displayRemainingChoices(c);

  c.removeChoice(10);

  displayRemainingChoices(c);

  c.removeChoice(3);

  displayRemainingChoices(c);

  c.removeChoice(2);
  c.removeChoice(4);
  c.removeChoice(5);
  c.removeChoice(6);

  displayRemainingChoices(c);

  c.insertChoice(4);

  displayRemainingChoices(c);

  return EXIT_SUCCESS;
}
