#pragma once

#include "tab.hpp"

#include <QFrame>
#include <QIcon>
#include <QMainWindow>
#include <QPointer>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include <array>
#include <memory>

// some widget properties
namespace Props
{
    struct TABS
    {
        QString name;
        QIcon icon;
    };

} // namespace Props

using namespace Props;

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

  private:
    auto build_window() -> void;
    auto build_tab_bar() -> void;
    auto set_tab(QFrame *frame) -> void;

    /*
     * @brief GET TAB PROPERTIES.
     * @return ARRAY OF TABS PROPERTIES.
     */
    [[nodiscard]] auto tab_info() -> std::array<TABS, 6>;

    QPointer<QTabWidget> tab_bar;
    std::unique_ptr<Sale> sale = nullptr;
};
