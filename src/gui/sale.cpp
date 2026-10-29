#include "tab.hpp"
#include <QIcon>

Sale::Sale(QFrame *tab_parent) : QFrame(tab_parent) { build_tab(); }

Sale::~Sale() = default;

auto Sale::build_tab() -> void
{
    QPointer<QVBoxLayout> main_layout = new QVBoxLayout(this);

    header = new QVBoxLayout();
    center = new QVBoxLayout();
    footer = new QVBoxLayout();

    main_layout->addLayout(header);
    main_layout->addLayout(center);
    main_layout->addLayout(footer);

    set_layout();
}

auto Sale::set_layout() -> void
{
    if (!(header || center || footer))
        return;

    QPointer<QFrame> header_container = new QFrame();
    QPointer<QFrame> footer_container = new QFrame();

    header_container->setStyleSheet("QFrame { border: 1px solid gray }");
    footer_container->setStyleSheet("QFrame { border: 1px solid gray }");

    build_too_bar(header_container);
    build_search_bar();

    header->addWidget(header_container);
    footer->addWidget(footer_container);
}

auto Sale::build_too_bar(QFrame *container) -> void
{
    tool_bar = new QToolBar(container);
    tool_bar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); // text and icon
}

auto Sale::build_search_bar() -> void
{
    if (!tool_bar)
        return;

    search = new QLineEdit();
    search->addAction(QIcon(":res/search.svg"), QLineEdit::LeadingPosition);
    search->setPlaceholderText("Buscar...");
    search->setStyleSheet("QLineEdit { background-color: white; color: black;}");

    search->setMinimumWidth(250);
    search->setMaximumWidth(400);
    search->setFixedHeight(30);

    tool_bar->addWidget(search);
}

auto Sale::set_binding() -> void {}
auto Sale::set_button() -> void {}
