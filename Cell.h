#ifndef CELL_H
#define CELL_H

#include <vector>

class Cell
{
public:
  Cell(void);
  virtual ~Cell(void);

  inline std::vector<int> getRemainingChoices(void) const { return _remainingChoices; }

  void removeChoice(int choice);
  void insertChoice(int choice);

  bool isFilled(void) const;

private:
  std::vector<int> _remainingChoices;
};

#endif // CELL_H
