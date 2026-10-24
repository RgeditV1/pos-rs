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

  protected:
    virtual auto build_tab() -> void = 0;
    virtual auto set_layout() -> void = 0;  // Set the layout
    virtual auto set_binding() -> void = 0; // bind widget with their custom action
    virtual auto set_button() -> void = 0;  // no need explaination

    virtual auto set_entry() -> void;     // all fields that wait for an input
    virtual auto set_container() -> void; // could`ve a tabBar, Pane, Scroll View
    virtual auto set_popup() -> void;
};

class Sell : protected Tab
{
  private:
    QTabWidget *parent;

  public:
    explicit Sell(QTabWidget *tab_parent);
    ~Sell() override;

  protected:
    auto build_tab() -> void override;
    auto set_layout() -> void override;
};
