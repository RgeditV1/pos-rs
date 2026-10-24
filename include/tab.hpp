#pragma once

class QTabWidget;
// class QWidget;

/* Tabs class */
class Tab; // Base Class
class Sell;
class Inventory;
class Client;
class Product;
class Configuration;
class Report;

class Tab
{
  public:
    virtual ~Tab() = 0;
    virtual auto build_tab(QTabWidget *tab_parent) -> void = 0;
    virtual auto set_entry() -> void;     // all fields that wait for an input
    virtual auto set_container() -> void; // could`ve a tabBar, Pane, Scroll View
    virtual auto set_button() -> void;    // no need explaination
    virtual auto set_popup() -> void;
};

class Sell : protected Tab
{
  private:
    QTabWidget *parent;

  public:
    explicit Sell(QTabWidget *tab_parent);

  protected:
    auto build_tab(QTabWidget *tab_parent) -> void override;
};
