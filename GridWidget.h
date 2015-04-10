#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H

#include <QtWidgets>

#include "Grid.h"

class GridWidget: public QWidget {
  Q_OBJECT

public:
  explicit GridWidget(QWidget *parent = NULL);
  virtual ~GridWidget(void);

private:
  void setCellStyleSheet(void);

signals:

public slots:
  void fillGrid(const QString& = "");
  void fillFromGrid(void);
  void solveGrid(void);

private:
  Grid _grid;
  QVector<QVector<QLineEdit*>> _gridLineEdit;
};

#endif // GRIDWIDGET_H
