#pragma once

#include "tab.hpp"

#include <QIcon>
#include <QMainWindow>
#include <QPointer>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include <array>

namespace Conf
{
    struct TABS
    {
        QString name;
        QIcon icon;
        QPointer<QFrame> frame;
    };

    [[nodiscard]] inline auto get_tab_info() -> std::array<TABS, 6>
    {
        std::array<TABS, 6> tab_info = {
            TABS{.name = QString("Venta"), .icon = QIcon(":res/sale.svg"), .frame = new QFrame()},
            TABS{.name = QString("Cliente"),
                 .icon = QIcon(":res/client.svg"),
                 .frame = new QFrame()},
            TABS{.name = QString("Inventario"),
                 .icon = QIcon(":res/inventory.svg"),
                 .frame = new QFrame()},
            TABS{.name = QString("Producto"),
                 .icon = QIcon(":res/product.svg"),
                 .frame = new QFrame()},
            TABS{.name = QString("Reportes"),
                 .icon = QIcon(":res/report.svg"),
                 .frame = new QFrame()},
            TABS{.name = QString("Configuraciones"),
                 .icon = QIcon(":res/settings.svg"),
                 .frame = new QFrame()},

        };
        return tab_info;
    }
} // namespace Conf

using namespace Conf;

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

  private:
    auto build_window() -> void;
    auto build_tab_bar() -> void;
    QPointer<QTabWidget> tab_bar;
    Sale *sale = nullptr;
};
