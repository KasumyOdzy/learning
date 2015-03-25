#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QListWidgetItem>
#include <QDialogButtonBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"));
    ui->lineEdit->setText(fileName);
}

void MainWindow::on_pushButton_2_clicked()
{
    auto fname = ui->lineEdit->text();
    auto item = new QListWidgetItem(fname);
    ui->listWidget->addItem(item);
}

void MainWindow::on_pushButton_clicked()
{
    ; //
}

void MainWindow::on_buttonBox_accepted()
{
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel | QDialogButtonBox::Save | QDialogButtonBox::Open | QDialogButtonBox::Close);

         connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
         {
             QListWidgetItem* fname = ui->listWidget->selectedItems().at(0);
             QString quotedFname = "cmd /c \"" + fname->text() + "\"";
             system( quotedFname.toStdString().c_str() );
         }
         connect(buttonBox, SIGNAL(close()), this, SLOT(close()));
         {

         }

    /*  QListWidgetItem* fname = ui->listWidget->selectedItems().at(0);
    QString quotedFname = "cmd /c \"" + fname->text() + "\"";
    system( quotedFname.toStdString().c_str() );        */
}


