#ifndef FORMAT_H
#define FORMAT_H

#include <QMainWindow>

namespace Ui {
class format;
}

class format : public QMainWindow
{
    Q_OBJECT

public:
    explicit format(QWidget *parent = 0);
    ~format();

private:
    Ui::format *ui;
};

#endif // FORMAT_H
