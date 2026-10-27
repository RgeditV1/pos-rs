#include "mainwindow.hpp"

#include <QSize>
#include <QTabBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { build_window(); }
MainWindow::~MainWindow()
{
    if (sale)
        delete sale;
}

auto MainWindow::build_window() -> void
{
    this->setWindowTitle("Punto de Venta");
    this->setFixedSize(QSize(1280, 720));
    build_tab_bar();
}

auto MainWindow::build_tab_bar() -> void
{
    tab_bar = new QTabWidget(this);
    for (short i = 0; i < get_tab_info().size(); i++)
    {
        tab_bar->addTab(get_tab_info()[i].frame, get_tab_info()[i].icon, get_tab_info()[i].name);
    }
    tab_bar->setDocumentMode(true);
    tab_bar->tabBar()->setExpanding(true);
    tab_bar->setIconSize(QSize(32, 32));
    tab_bar->setElideMode(Qt::ElideRight); // in case of small screen
    this->setCentralWidget(tab_bar);
}
