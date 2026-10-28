#include "mainwindow.hpp"

#include <QSize>
#include <QTabBar>

auto MainWindow::tab_info() -> std::array<TABS, 6>
{
    return {TABS{
                .name = QString("Venta"),
                .icon = QIcon(":res/sale.svg"),
            },
            TABS{
                .name = QString("Cliente"),
                .icon = QIcon(":res/client.svg"),
            },
            TABS{
                .name = QString("Inventario"),
                .icon = QIcon(":res/inventory.svg"),
            },
            TABS{
                .name = QString("Producto"),
                .icon = QIcon(":res/product.svg"),
            },
            TABS{
                .name = QString("Reportes"),
                .icon = QIcon(":res/report.svg"),
            },
            TABS{
                .name = QString("Configuraciones"),
                .icon = QIcon(":res/settings.svg"),
            }};
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { build_window(); }

MainWindow::~MainWindow() = default;

auto MainWindow::build_window() -> void
{
    this->setWindowTitle("Punto de Venta");
    this->setFixedSize(QSize(1280, 720));
    build_tab_bar();
}

auto MainWindow::build_tab_bar() -> void
{
    tab_bar = new QTabWidget(this);

    const auto &info_list = tab_info();
    const size_t TOTAL_TABS = tab_info().size();

    for (size_t i = 0; i < TOTAL_TABS; ++i)
    {

        QPointer<QFrame> current_frame = new QFrame(tab_bar);
        tab_bar->addTab(current_frame, info_list[i].icon, info_list[i].name);
    }

    tab_bar->setDocumentMode(true);
    tab_bar->tabBar()->setExpanding(true);
    tab_bar->setIconSize(QSize(32, 32));
    tab_bar->setElideMode(Qt::ElideRight); // in case of small screen...
    this->setCentralWidget(tab_bar);
}

auto MainWindow::set_tab(QFrame *frame) -> void {}
