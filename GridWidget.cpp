#include "GridWidget.h"

GridWidget::GridWidget(QWidget *parent):
  QWidget(parent),
  _grid() {

  QVBoxLayout* mainLayout =  new QVBoxLayout;
  for (int i = 0; i < 9; ++i) {
    QVector<QLineEdit*> line;
    QHBoxLayout* lineLayout = new QHBoxLayout;
    for (int j = 0; j < 9; ++j) {
      QLineEdit* cellLineEdit = new QLineEdit;
      cellLineEdit->setFixedSize(75, 75);
      cellLineEdit->setAlignment(Qt::AlignHCenter);
      cellLineEdit->setValidator(new QIntValidator(1, 9, this));
      line.push_back(cellLineEdit);
      lineLayout->addWidget(cellLineEdit);
      QString style = "QLineEdit { border: solid 5px #000;";
      if (i%3 == 0) {
        style += "border-top: solid 10px #000; }";
      } else {
        style += "}";
      }
      cellLineEdit->setStyleSheet(style);
      connect(cellLineEdit, SIGNAL(textChanged(const QString)), this, SLOT(fillGrid(const QString)));
    }
    _gridLineEdit.push_back(line);
    mainLayout->addLayout(lineLayout);
  }

  mainLayout->setAlignment(Qt::AlignCenter);
  setLayout(mainLayout);
}

GridWidget::~GridWidget(void) {

}

void GridWidget::fillGrid(const QString&) {
  for (int i = 0; i < _gridLineEdit.size(); ++i) {
    for (int j = 0; j < _gridLineEdit.at(i).size(); ++j) {
      QLineEdit* cellLineEdit = _gridLineEdit.at(i).at(j);
      if (!cellLineEdit->text().isEmpty())
        _grid.fillCell(i, j, cellLineEdit->text().toInt());
    }
  }
}

void GridWidget::fillFromGrid(void) {
  for (int i = 0; i < _gridLineEdit.size(); ++i) {
    for (int j = 0; j < _gridLineEdit.at(i).size(); ++j) {
      QLineEdit* cellLineEdit = _gridLineEdit.at(i).at(j);
      Cell* cell = _grid.getCell(i, j);
      if (cell->isFilled()) {
        int value = cell->getValue();
        disconnect(cellLineEdit, SIGNAL(textChanged(const QString)), this, SLOT(fillGrid(const QString)));
        cellLineEdit->setText(QString::number(value));
        connect(cellLineEdit, SIGNAL(textChanged(const QString)), this, SLOT(fillGrid(const QString)));
      }
    }
  }
}

void GridWidget::solveGrid(void) {
  bool worked1;
  bool worked2;
  do {
    worked1 = _grid.fillCells();
    worked2 = _grid.fillOnlyChoices();
    fillFromGrid();
  } while(worked1 || worked2);
}
