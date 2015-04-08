#ifndef CELL_H
#define CELL_H

#include <vector>

class Cell
{
public:
  Cell(void);
  virtual ~Cell(void);

  inline std::vector<bool> getRemainingChoices(void) const { return _remainingChoices; }

  void removeChoice(int choice);
  void insertChoice(int choice);

  inline int getValue(void) const { return _value; }
  inline void fill(int value) { _value = value; }
  inline void empty(void) { _value = -1; }

  bool isFilled(void) const;

private:
  std::vector<bool> _remainingChoices;
  int _value;
};

#endif // CELL_H
