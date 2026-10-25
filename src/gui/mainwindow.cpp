#include "mainwindow.hpp"

#include <QSize>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { build_window(); }
MainWindow::~MainWindow() = default;
auto MainWindow::build_window() -> void
{
    this->setWindowTitle("Punto de Venta");
    this->setFixedSize(QSize(1280, 720));
}
