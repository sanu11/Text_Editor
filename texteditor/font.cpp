#include "font.h"
#include "ui_font.h"

format::format(QWidget *parent) :
    QMainWindow(parent),
    ui2(new Ui::format)
{
    ui2->setupUi(this);
}

format::~format()
{
    delete ui2;
}
