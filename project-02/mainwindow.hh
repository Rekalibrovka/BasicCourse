// Kuanysh Kairbek
// 256285
// kuanysh.kairbek@student.tut.fi

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
    void reset_clicked();
    void gender_changed();
    void BMI_calc_triggered();
    void interpretation_ready();

private:
    Ui::MainWindow *ui;
    double BMI_ = 0;
};

#endif // MAINWINDOW_HH
