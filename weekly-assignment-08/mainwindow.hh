#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void clear_button_clicked();
    void value_changed();

private slots:
    void on_exit_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HH
