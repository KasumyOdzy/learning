/**
The Giant Penis License (GPL)
Copyright (c) 2015 Kasumy Odzy
            ▄▄██▄██▄▄
          ▄█    █    █▄
         ▄█           █▄
         █             █
        █               █
        █               █
        █               █
        █               █
         █▄     █     ▄█
          █    ▄▄▄    █
          █           █
          █           █
          █           █
          █           █
          █           █
          █           █
          █           █
          █           █
          █           █
          █           █
          █           █
          █           █
    ▄████▄█           █▄████▄
  ▄█                         █▄
 █                             █
█                               █
█                               █
█                               █
█             ▄▄█▄▄             █
 █           █     █           █
  █▄       ▄█       █▄       ▄█
    █▄▄▄▄▄█           █▄▄▄▄▄█
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
**/

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
  mfile.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream stream(&mfile);
  stream << ui->lineEdit->text();
  mfile.close();
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

void MainWindow::on_actionRead_triggered()
{

}
