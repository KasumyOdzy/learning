#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QListWidgetItem>
#include <QDialogButtonBox>
#include <QAction>
#include <QKeySequence>
#include <QTextStream>
#include <QTextStream>

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
    QFile mfile("//mfile.txt");
    QTextStream stream(&mfile);
    stream << ui->lineEdit->toPlainText();
    mfile close();

}

void MainWindow::on_pushButton_clicked()
{
   /* auto item = ui->listWidget->fname();
    auto fname = new QListWidgetItem(item);
    ui->listWidget->deleteLater();*/
}

void MainWindow::on_pushButton_3_clicked()
{
    QListWidgetItem* fname = ui->listWidget->selectedItems().at(0);
    QString quotedFname = "cmd /c \"" + fname->text() + "\"";
    system( quotedFname.toStdString().c_str() );
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}
