#include "GridWidget.h"

GridWidget::GridWidget(QWidget *parent):
  QWidget(parent),
  _grid() {

  setStyleSheet(
  "QLineEdit {"
    "border: 2px solid black;"
    "padding: 0px;"
    "margin: 0px;"
    "background: white;"
    "font-size: 20px;"
  "}"
  );

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
      lineLayout->setSpacing(0);
      // connect(cellLineEdit, SIGNAL(textChanged(const QString)), this, SLOT(fillGrid(const QString)));
    }
    _gridLineEdit.push_back(line);
    mainLayout->addLayout(lineLayout);
  }

  mainLayout->setSpacing(0);

  setCellStyleSheet();

  mainLayout->setAlignment(Qt::AlignCenter);
  setLayout(mainLayout);
}

GridWidget::~GridWidget(void) {

}

void GridWidget::setCellStyleSheet(void) {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      QString style = "";
      if (i == 0) {
        style += "border-top: 10px solid black;";
      } else if (i == 8) {
        style += "border-bottom: 10px solid black;";
      } else if (i%3 == 0) {
        style += "border-top: 4px solid black;";
      } else if (i%3 == 2) {
        style += "border-bottom: 4px solid black;";
      }

      if (j == 0) {
        style += "border-left: 10px solid black;";
      } else if (j == 8) {
        style += "border-right: 10px solid black;";
      } else if (j%3 == 0) {
        style += "border-left: 4px solid black;";
      } else if (j%3 == 2) {
        style += "border-right: 4px solid black;";
      }

      QLineEdit* cellLineEdit = _gridLineEdit.at(i).at(j);
      cellLineEdit->setStyleSheet(cellLineEdit->styleSheet()+style);
    }
  }
}

void GridWidget::fillGrid(const QString&) {
  for (int i = 0; i < _gridLineEdit.size(); ++i) {
    for (int j = 0; j < _gridLineEdit.at(i).size(); ++j) {
      QLineEdit* cellLineEdit = _gridLineEdit.at(i).at(j);
      if (!cellLineEdit->text().isEmpty()) {
        _grid.fillCell(i, j, cellLineEdit->text().toInt());
        cellLineEdit->setStyleSheet(cellLineEdit->styleSheet()+"font-weight: bold; font-size: 24px;");
      }
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
//        disconnect(cellLineEdit, SIGNAL(textChanged(const QString)), this, SLOT(fillGrid(const QString)));
        cellLineEdit->setText(QString::number(value));
//        connect(cellLineEdit, SIGNAL(textChanged(const QString)), this, SLOT(fillGrid(const QString)));
      }
    }
  }
}

void GridWidget::solveGrid(void) {
  fillGrid();

  bool worked1;
  bool worked2;
  do {
    worked1 = _grid.fillCells();
    worked2 = _grid.fillOnlyChoices();
    fillFromGrid();
  } while(worked1 || worked2);
}
