#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFontComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menu();
    icons();
    connect(box,SIGNAL(currentFontChanged(QFont)),doc,SLOT(setCurrentFont(QFont)));
    connect(ui->m1act1,SIGNAL(triggered()),this,SLOT(newfile()));
    connect(ui->m1act2,SIGNAL(triggered()),this,SLOT(open()));
    connect(ui->m1act3,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->m1act4,SIGNAL(triggered()),this,SLOT(savefileas()));
    connect(ui->m1act6,SIGNAL(triggered()),this,SLOT(quit()));
    connect(ui->m2act1,SIGNAL(triggered()),this,SLOT(undo()));
    connect(ui->m2act2,SIGNAL(triggered()),this,SLOT(redo()));
    connect(ui->m2act3,SIGNAL(triggered()),this,SLOT(cut()));
    connect(ui->m2act4,SIGNAL(triggered()),this,SLOT(copy()));
    connect(ui->m2act5,SIGNAL(triggered()),this,SLOT(paste()));
    connect(ui->m2act6,SIGNAL(triggered()),this,SLOT(selectall()));
    connect(ui->m2act7,SIGNAL(triggered()),this,SLOT(search()));
    connect(line,SIGNAL(textChanged(QString)),this,SLOT(setfindcount()));
    connect(ui->m2act8,SIGNAL(triggered()),this,SLOT(replac()));
    connect(ui->m3act1,SIGNAL(triggered()),this,SLOT(zoomin()));
    connect(ui->m3act2,SIGNAL(triggered()),this,SLOT(zoomout()));
    connect(ui->m3act3,SIGNAL(triggered()),this,SLOT(fullscreen()));
    connect(box,SIGNAL(currentFontChanged(QFont)),this,SLOT(fontstyle()));
    connect(ui->m4act1,SIGNAL(triggered()),this,SLOT(table()));
    connect(ui->m4act2,SIGNAL(triggered()),this,SLOT(image()));
    connect(ui->m5act1_2,SIGNAL(triggered()),this,SLOT(about()));
    connect(combo_size,SIGNAL(currentIndexChanged(int)),this, SLOT(fontsize()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

//sets menu
void MainWindow::menu()
{
    setWindowTitle("Text Editor");
    windowTitle().resize(40);
    f.setPointSize(10);
    ui->bar->setFont(f);
    ui->menu_1->setFont(f);
    ui->menu_2->setFont(f);
    ui->menu_3->setFont(f);
    ui->menu_4->setFont(f);
    ui->menu_5->setFont(f);

    //File menu
    doc=new QTextEdit;
    setCentralWidget(doc);
    QPixmap pix("editor.jpg");
    QIcon icon(pix);
    setWindowIcon(icon);

    ui->m1act1->setShortcut(QKeySequence::New);
    ui->m1act1->setStatusTip(tr("Create a new spreadsheet file"));
    ui->m1act1->setIcon(QIcon("filenew.png"));

    ui->m1act2->setShortcut(QKeySequence::Open);
    ui->m1act2->setStatusTip(tr("Open a file"));
    ui->m1act2->setIcon(QIcon("fileopen.png"));

    ui->m1act3->setShortcut(QKeySequence::Save);
    ui->m1act3->setStatusTip(tr("Saves a file"));
    ui->m1act3->setIcon(QIcon("filesave.png"));

    ui->m1act4->setShortcut(QKeySequence::SaveAs);
    ui->m1act4->setStatusTip("Saves a file");

    ui->m1act5->setShortcut(QKeySequence::Print);
    ui->m1act5->setStatusTip(tr("Print Files"));
    ui->m1act5->setIcon(QIcon("fileprint.png"));

    ui->m1act6->setShortcut(QKeySequence::Quit);
    ui->m1act6->setStatusTip(tr("Quit Editor"));

    //Edit menu

    ui->m2act1->setShortcut(QKeySequence::Undo);
    ui->m2act1->setStatusTip("Directs back to previous changes");
    ui->m2act1->setIcon(QIcon("undo.png"));

    ui->m2act2->setShortcut(QKeySequence::Redo);
    ui->m2act2->setStatusTip("Directs back to previous changes done using undo");

    ui->m2act3->setShortcut(QKeySequence::Cut);
    ui->m2act3->setStatusTip("Cuts text");
    ui->m2act3->setIcon(QIcon("cut.png"));

    ui->m2act4->setShortcut(QKeySequence::Copy);
    ui->m2act4->setStatusTip("Copies text");
    ui->m2act4->setIcon(QIcon("copy.png"));

    ui->m2act5->setShortcut(QKeySequence::Paste);
    ui->m2act5->setStatusTip("Pastes text");
    ui->m2act5 ->setIcon(QIcon("paste.png"));

    ui->m2act6->setShortcut(QKeySequence::SelectAll);
    ui->m2act6->setStatusTip("Selects entire area");

    ui->m2act7->setShortcut(QKeySequence::Find);
    ui->m2act7->setStatusTip("Finds text");
    ui->m2act7->setIcon(QIcon("find.png"));

    ui->m2act8->setShortcut(QKeySequence::Replace);
    ui->m2act8->setStatusTip("Finds text and Replaces");

            //View menu

    ui->m3act1->setShortcut(QKeySequence::ZoomIn);
    ui->m3act1->setStatusTip("Zooms In");
    ui->m3act1 ->setIcon(QIcon("zoomin.png"));

    ui->m3act2->setShortcut(QKeySequence::ZoomOut);
    ui->m3act2->setStatusTip("Zooms out");    
    ui->m3act2 ->setIcon(QIcon("zoomout.png"));

    ui->m3act3->setShortcut(QKeySequence::FullScreen);
    ui->m3act3->setStatusTip("Fullscreen view");

    //Insert menu

    ui->m4act1->setStatusTip("Inserts table in file");
    ui->m4act2->setStatusTip("Inserts image");

    ui->m4act3->setShortcut(QKeySequence::Open);
    ui->m4act3->setStatusTip("Inserts File");
}
//sets icons

void MainWindow::icons()
{
    f.setPointSize(12);
    lab1->setFont(f);
    lab2->setFont(f);
    combo_size->setFixedWidth(45);
    QPixmap pix("filenew.png");
    QIcon ButtonIcon(pix);
    button.setFlat(1);
    button.setIcon(ButtonIcon);
    button.setIconSize(pix.rect().size());
    button.connect(&button,SIGNAL(clicked()),this,SLOT(newfile()));
    QPixmap pix2("editcopy.png");
    QIcon ButtonIcon2(pix2);
    button2.setFlat(1);
    button2.setIcon(ButtonIcon2);
    button2.setIconSize(pix2.rect().size());
    button.connect(&button2,SIGNAL(clicked()),this,SLOT(copy()));
    QPixmap pix3("cut.png");
    QIcon ButtonIcon3(pix3);
    button3.setFlat(1);
    button3.setIcon(ButtonIcon3);
    button3.setIconSize(pix3.rect().size());
    button3.connect(&button3,SIGNAL(clicked()),this,SLOT(cut()));
    QPixmap pix4("paste.png");
    QIcon ButtonIcon4(pix4);
    button4.setFlat(1);
    button4.setIcon(ButtonIcon4);
    button4.setIconSize(pix4.rect().size());
    button4.connect(&button4,SIGNAL(clicked()),this,SLOT(paste()));
    QPixmap pix5("fileprint.png");
    QIcon ButtonIcon5(pix5);
    button5.setFlat(1);
    button5.setIcon(ButtonIcon5);
    button5.setIconSize(pix5.rect().size());
    button5.connect(&button5,SIGNAL(clicked()),this,SLOT(print()));
    QPixmap pix6("fileopen.png");
    QIcon ButtonIcon6(pix6);
    button6.setFlat(1);
    button6.setIcon(ButtonIcon6);
    button6.setIconSize(pix6.rect().size());
    button6.connect(&button6,SIGNAL(clicked()),this,SLOT(open()));
    QPixmap pix7("filesave.png");
    QIcon ButtonIcon7(pix7);
    button7.setFlat(1);
    button7.setIcon(ButtonIcon7);
    button7.setIconSize(pix7.rect().size());
    button7.connect(&button7,SIGNAL(clicked()),this,SLOT(save()));
    QPixmap pix8("undo.png");
    QIcon ButtonIcon8(pix8);
    button8.setFlat(1);
    button8.setIcon(ButtonIcon8);
    button8.setIconSize(pix8.rect().size());
    button8.connect(&button8,SIGNAL(clicked()),this,SLOT(undo()));
    QPixmap pix9("bold.png");
    QIcon ButtonIcon9(pix9);
    button9.setFlat(1);
    button9.setIcon(ButtonIcon9);
    button9.setIconSize(pix9.rect().size());
    button9.connect(&button9,SIGNAL(clicked()),this,SLOT(bold()));
    QPixmap pix10("italic.png");
    QIcon ButtonIcon10(pix10);
    button10.setFlat(1);
    button10.setIcon(ButtonIcon10);
    button10.setIconSize(pix10.rect().size());
    button10.connect(&button10,SIGNAL(clicked()),this,SLOT(italics()));
    QPixmap pix11("underline.png");
    QIcon ButtonIcon11(pix11);
    button11.setFlat(1);
    button11.setIcon(ButtonIcon11);
    button11.setIconSize(pix11.rect().size());
    button11.connect(&button11,SIGNAL(clicked()),this,SLOT(underline()));
    QPixmap pix12("zoomin.png");
    QIcon ButtonIcon12(pix12);
    button12.setFlat(1);
    button12.setIcon(ButtonIcon12);
    button12.setIconSize(pix12.rect().size());
    button12.connect(&button12,SIGNAL(clicked()),this,SLOT(zoomin()));
    QPixmap pix13("zoomout.png");
    QIcon ButtonIcon13(pix13);
    button13.setFlat(1);
    button13.setIcon(ButtonIcon13);
    button13.setIconSize(pix13.rect().size());
    button13.connect(&button13,SIGNAL(clicked()),this,SLOT(zoomout()));
    combo_size->addItem("8");
    combo_size->addItem("9");
    combo_size->addItem("10");
    combo_size->addItem("12");
    combo_size->addItem("14");
    combo_size->addItem("18");
    combo_size->addItem("24");
    combo_size->addItem("28");
    combo_size->addItem("32");
    combo_size->addItem("36");
    combo_size->addItem("48");
    combo_size->addItem("56");
    combo_size->addItem("62");
    combo_size->addItem("72");
    ui->toolBar->setFixedHeight(40);
    ui->toolBar->addWidget(&button);          //new
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(&button7);          //save
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(&button6);           //open
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(&button3);           //cut
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(&button2);           //copy
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(&button4);           //paste
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(&button8);           //undo
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(&button5);           //print
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(&button12);           //print
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(&button13);           //print
    ui->toolBar->addSeparator();
                 //toolbar2
    ui->toolBar_2->setFixedHeight(40);
    ui->toolBar_2->addWidget(lab1);
    ui->toolBar_2->addSeparator();
    ui->toolBar_2->addWidget(box);                 //font
    ui->toolBar_2->addSeparator();
    ui->toolBar_2->addWidget(lab2);
    ui->toolBar_2->addSeparator();
    ui->toolBar_2->addWidget(combo_size);          //fontsize
    ui->toolBar_2->addSeparator();
    ui->toolBar_2->addWidget(&button9);             //bold
    ui->toolBar_2->addSeparator();
    ui->toolBar_2->addWidget(&button10);             //italics
    ui->toolBar_2->addSeparator();
    ui->toolBar_2->addWidget(&button11);              //underline
    ui->toolBar_2->addSeparator();
    button.setStatusTip("Creates new file");
    button2.setStatusTip("Copies text");
    button3.setStatusTip("Cuts text");
    button4.setStatusTip("Pastes text");
    button5.setStatusTip("Prints file");
}

void MainWindow::newfile()
{

    qDebug()<<"HE;LKE";
    (new MainWindow)->show();
}
void MainWindow::quit()
{

        int a=QMessageBox::warning(this," ","Save changes to document before closing?" ,QMessageBox::Save|QMessageBox::Cancel|QMessageBox::Discard);
       switch(a)
        {
            case QMessageBox::Save:
            save();
            break;
            case QMessageBox::Cancel:
            return;
            case QMessageBox::Discard:
            this->close();
        }
            this->close();
}
void MainWindow::fullscreen()
{
    if(!this->isFullScreen())
    this->showFullScreen();
    else
        this->showNormal();
}
void MainWindow::save()
{
    if(currentfile.isEmpty())
        savefileas();
    else
        savefile(currentfile);
}
void MainWindow::savefileas()
{
   QString filename = QFileDialog::getSaveFileName( this, tr("Save As"), currentfile );
    if( filename.isEmpty() )
    return;
        savefile(filename);
}
void MainWindow::savefile(QString filename)
{
    QFile file( filename );
    if( !file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
      QMessageBox::warning( this," ", tr("Failed to save file.") );
      return ;
    }
    QTextStream stream( &file );
    stream << doc->toPlainText();
    file.close();
    currentfile = filename;
    setWindowTitle( tr("%1[*]").arg(filename));
}
void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this);
    if(filename.isEmpty())
        return;
    loadfile(filename);
}
void MainWindow::loadfile(QString filename)
{
    QFile file(filename);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
      {
        QMessageBox::warning( this, tr("SDI"), tr("Failed to open file.") );
        return;
      }
    QTextStream stream(&file);
    doc->setPlainText(stream.readAll());
    file.close();
    currentfile=filename;
    setWindowTitle( tr("%1[*]" ).arg(filename));
}
void MainWindow::cut()
{
    doc->cut();
}
void MainWindow::copy()
{
    doc->copy();
}
void MainWindow::paste()
{
    doc->paste();
}
void MainWindow::undo()
{
    doc->undo();
}
void MainWindow::redo()
{
    doc->redo();
}
void MainWindow::selectall()
{
    doc->selectAll();
}
void MainWindow::fontstyle()
{
    int size=doc->fontPointSize();
    qDebug()<<doc->fontPointSize();
    QString str=box->currentText();
    doc->setFontFamily(str);
    doc->setFontPointSize(size);
}
void MainWindow::fontsize()
{
    int s=combo_size->currentText().toInt();
    doc->setFontPointSize(s);
}
void MainWindow::bold()
{
    if(doc->fontWeight()==0)
      doc->setFontWeight(1);
    else
      doc->setFontWeight(0);
}
void MainWindow::italics()
{
    if(doc->fontItalic()==0)
      doc->setFontItalic(1);
    else
      doc->setFontItalic(0);
}
void MainWindow::underline()
{
    if(doc->fontUnderline()==0)
      doc->setFontUnderline(1);
    else
      doc->setFontUnderline(0);
}
void MainWindow::zoomin()
{   
    doc->zoomIn();
}
void MainWindow::zoomout()
{
    doc->zoomOut();
}
void MainWindow::search()
{
    QLabel *label=new QLabel("Find What");
    QPushButton *b=new QPushButton("Find Next");
    QPushButton *b2=new QPushButton("Cancel");
    QVBoxLayout *vbox=new QVBoxLayout;
    QHBoxLayout *hbox=new QHBoxLayout;
    vbox->addWidget(b);
    vbox->addWidget(b2);
    hbox->addWidget(label);
    hbox->addWidget(line);
    hbox->addLayout(vbox);
    diag->setLayout(hbox);
    diag->setWindowTitle("Find");
    QPixmap pix("find.png");
    QIcon icon(pix);
    diag->setWindowIcon(icon);
    diag->show();
    connect(b,SIGNAL(clicked()),this,SLOT(find2()));
    connect(b2,SIGNAL(clicked()),this,SLOT(clos()));
}
void MainWindow::find2()
{
 QString str;
 str=line->text();
 qDebug()<<str;
 if(c==0)
 doc->moveCursor(QTextCursor::Start);            //cursor moves to start so as to search from beginning
if(line->text().isEmpty())
    QMessageBox::information(this,"Oops","Enter word",QMessageBox::Ok);
if(c!=0&&doc->find(str)==0)
    doc->moveCursor(QTextCursor::Start);
if(doc->find(str)==0&&c==0)
{
   QPixmap pix4("face-sad.png");
   QIcon icon4("face-sad.png");
   QIcon icon3("sad.png");
   QMessageBox oops;
   oops.setWindowIcon(icon3);
   oops.setIconPixmap(pix4);
   oops.setText("Sorry!\nWord not found");
   oops.setWindowTitle("Oops");
   oops.setDefaultButton(QMessageBox::Ok);
   oops.exec();
}
else
    c++;
}
void MainWindow::setfindcount()
{
c=0;
return;
}

void MainWindow::clos()
{
diag->close();
}
void MainWindow::replac()
{

    QLabel *label=new QLabel("Find What");
    QPushButton *b=new QPushButton("Find Next");
    QPushButton *b2=new QPushButton("Cancel");
    QVBoxLayout *vbox=new QVBoxLayout;
    QHBoxLayout *hbox=new QHBoxLayout;
    QLabel *label2=new QLabel("Replace With");
    QVBoxLayout *vbox2=new QVBoxLayout;
    QVBoxLayout *vbox3=new QVBoxLayout;
    QPushButton *b3=new QPushButton("Replace");
    vbox->addWidget(b);
    vbox->addWidget(b3);
    vbox->addWidget(b2);
    vbox2->addWidget(line);
    vbox2->addWidget(line2);
    vbox3->addWidget(label);
    vbox3->addWidget(label2);
    hbox->addLayout(vbox3);
    hbox->addLayout(vbox2);
    hbox->addLayout(vbox);
    diag2->setLayout(hbox);
    diag2->setWindowTitle("Find and Replace");
    QPixmap pix("find.png");
    QIcon icon(pix);
    diag2->setWindowIcon(icon);
    diag2->show();
    connect(b,SIGNAL(clicked()),this,SLOT(find2()));
    connect(b2,SIGNAL(clicked()),this,SLOT(clos2()));
    connect(b3,SIGNAL(clicked()),this,SLOT(replac2()));
}
void MainWindow::clos2()
{
    diag2->close();
}
void MainWindow::replac2()
{
    QString str=line2->text();
    doc->textCursor().insertText(str);
}
void MainWindow::image()
{
    QString image = QFileDialog::getOpenFileName(this);
    QString s1="<img src=\"";
    QString s2=image;
    s2 = QDir::fromNativeSeparators(s2);
    QString s3="\"";
    QString s5="\"/>";
    QString str2=s1+image+s5;
    qDebug()<<str2;
    doc->append(str2);
    QTextCursor cursor;
}
void MainWindow::table()
{
   QLabel *label=new QLabel("Rows    ");
   label->setFont(f);

   line3->setFont(f);
   QLabel *label2=new QLabel("Columns");
   label2->setFont(f);
   line4->setFont(f);
   QHBoxLayout *box2=new QHBoxLayout;
   QHBoxLayout *box3=new QHBoxLayout;
   QPushButton *add=new QPushButton("Add");
   box2->addWidget(label);
   box2->addWidget(line3);
   box3->addWidget(label2);
   box3->addWidget(line4);
   QVBoxLayout *box4=new QVBoxLayout;
   box4->addLayout(box2);
   box4->addLayout(box3);
   QHBoxLayout *box5=new QHBoxLayout;
   box5->addLayout(box4);
   box5->addWidget(add);
   diag3->setLayout(box5);
   diag3->setWindowTitle("Table");
   QIcon icon("tableview.png");
   diag3->setWindowIcon(icon);
   diag3->show();
   connect(add,SIGNAL(clicked()),this,SLOT(addtable()));
}
void MainWindow::addtable()
{
qDebug()<<"ajdc";
int row=line3->text().toInt();
int column=line4->text().toInt();
QTextCursor *cursor=new QTextCursor;
QTextTableFormat tableFormat;
tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Groove);
tableFormat.setCellPadding(1);
tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 40));
tableFormat.setAlignment(Qt::AlignLeft);
doc->textCursor().insertTable(row,column,tableFormat);
}
void MainWindow::about()
{
      QMessageBox::about( this, tr("About Editor"), tr("A single document interface application"));
}
