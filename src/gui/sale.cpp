#include "tab.hpp"

Sale::Sale(QFrame *tab_parent) : QFrame(tab_parent) { build_tab(); }

Sale::~Sale() = default;

auto Sale::build_tab() -> void { this->setStyleSheet("background-color: yellow"); }
auto Sale::set_layout() -> void {}
auto Sale::set_binding() -> void {}
auto Sale::set_button() -> void {}
