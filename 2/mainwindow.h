#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDialogButtonBox>
#include <QAction>
#include <QKeySequence>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
  void on_toolButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_actionRead_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
