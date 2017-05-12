#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->clear_button, SIGNAL(clicked()),this, SLOT(clear_button_clicked()));
    connect(ui->kmh_spinbox, SIGNAL(valueChanged(int)),this, SLOT(value_changed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clear_button_clicked()
{
    ui->kmh_spinbox->setValue(0);

    ui->miles_lcd->display(0.0);  // Not really neccessary after the program is finished.
}

void MainWindow::on_exit_button_clicked()
{
    close();
}

double km_to_miles(int km)
{
    return km/1.609;
}

void MainWindow::value_changed()
{
    ui->miles_lcd->display(km_to_miles(ui->kmh_spinbox->value()));
}
