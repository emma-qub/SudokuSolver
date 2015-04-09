#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GridWidget.h"

class MainWindow: public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = NULL);
  virtual ~MainWindow(void);

signals:

public slots:

private:
  GridWidget* _gridWidget;
};

#endif // MAINWINDOW_H
