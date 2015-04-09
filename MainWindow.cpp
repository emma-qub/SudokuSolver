#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent):
  QMainWindow(parent) {

  _gridWidget = new GridWidget;

  setCentralWidget(_gridWidget);

  QAction* solveAction = menuBar()->addAction("Solve Grid");
  solveAction->setShortcut(QKeySequence("CTRL+R"));
  connect(solveAction, SIGNAL(triggered(void)), _gridWidget, SLOT(solveGrid(void)));

  setWindowTitle("Sudoku Solver");
  setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow(void) {

}

