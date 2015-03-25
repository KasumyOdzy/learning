#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDialogButtonBox>

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

  void on_buttonBox_accepted();

    private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
