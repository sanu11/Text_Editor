#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QTextEdit>
#include <QMainWindow>
#include<QMenu>
#include<QAction>
#include<QHBoxLayout>
#include<QLabel>
#include<QDebug>
#include<QFileDialog>
#include<QFile>
#include<QTextEdit>
#include<QMessageBox>
#include<QTextEdit>
#include<QTextStream>
#include<QFontComboBox>
#include<QFont>
#include<QAbstractButton>
#include<QPushButton>
#include<QPixmap>
#include<QLineEdit>
#include<QIcon>
#include<QTextDocumentFragment>
#include<QTextTable>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QFont f;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void menu();
    void icons();
    void savefile(QString);
    //find diaglogue
    QDialog *diag=new QDialog;
    QDialog *diag2=new QDialog;
    QLineEdit *line=new QLineEdit;
    QLineEdit *line2=new QLineEdit;
    //font
    QComboBox *combo=new QComboBox;
    QFontComboBox *box=new QFontComboBox;
    QComboBox *combo_size=new QComboBox;
    QLabel *lab1=new QLabel(" Font   ");
    QLabel *lab2=new QLabel("  Font size  ");
    QLabel *lab3=new QLabel("      ");

    //icons
    QPushButton button,button2,button3,button4,button5,button6,button7,button8,button9,button10,button11,button12,button13;
    //table
    QDialog *diag3=new QDialog;
    QLineEdit *line3=new QLineEdit;
    QLineEdit *line4=new QLineEdit;
private:
    int c=0;
    QString currentfile;
    QTextEdit *doc;
    Ui::MainWindow *ui;
    void loadfile(QString);

    private slots:
    void newfile();
    void save();
    void savefileas();
    void open();
    void quit();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void selectall();
    void zoomin();
    void zoomout();
    void fontsize();
    void fontstyle();
    void bold();
    void italics();
    void underline();
    void fullscreen();
    void search();
    void find2();
    void setfindcount();
    void clos();
    void replac();
    void clos2();
    void replac2();
    void image();
    void table();
    void addtable();
    void about();
};

#endif // MAINWINDOW_H
