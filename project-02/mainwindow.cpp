// Kuanysh Kairbek
// 256285
// kuanysh.kairbek@student.tut.fi

#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //basic functions
    connect(ui->actionReset, SIGNAL(triggered(bool)),this, SLOT(reset_clicked()));
    connect(ui->actionMale, SIGNAL(triggered(bool)),this, SLOT(gender_changed()));
    connect(ui->actionFemale, SIGNAL(triggered(bool)),this, SLOT(gender_changed()));
    //BMI
    connect(ui->Weight_spinBox, SIGNAL(valueChanged(int)),this, SLOT(BMI_calc_triggered()));
    connect(ui->Height_spinBox, SIGNAL(valueChanged(int)),this, SLOT(BMI_calc_triggered()));
    //Interpretation
    connect(ui->Weight_spinBox, SIGNAL(valueChanged(int)),this, SLOT(interpretation_ready()));
    connect(ui->Height_spinBox, SIGNAL(valueChanged(int)),this, SLOT(interpretation_ready()));
    connect(ui->actionMale, SIGNAL(triggered(bool)),this, SLOT(interpretation_ready()));
    connect(ui->actionFemale, SIGNAL(triggered(bool)),this, SLOT(interpretation_ready()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset_clicked()
{
    ui->actionMale->setChecked(true);
    ui->actionFemale->setChecked(false);
    ui->Gender_value->setText("Male");
    ui->Weight_spinBox->setValue(0);
    ui->Height_spinBox->setValue(0);
    ui->Weight_horSlider->setValue(0);
    ui->Height_horSlider->setValue(0);
    ui->BMI_value->setText("-");
    ui->Interpretation_value->setText("-");
}

void MainWindow::gender_changed()
{
    if (ui->actionMale->isChecked()) {
        ui->Gender_value->setText("Male");
    } else {
        ui->Gender_value->setText("Female");
    }
}

void MainWindow::BMI_calc_triggered()
{
    int weight = ui->Weight_spinBox->value();
    int height = ui->Height_spinBox->value();
    if (weight > 0 && height > 0) {
        BMI_ = weight/(pow(height/100.0,2.0));
        ui->BMI_value->setText(QString::number(BMI_));
    }
}

void MainWindow::interpretation_ready()
{
    if (BMI_ != 0) {
        if (ui->actionMale->isChecked()) {
            //Male case
            if (BMI_ <= 20.7) {
                ui->Interpretation_value->setText("underweight");
            } else if (BMI_ > 20.7 && BMI_ <= 26.4) {
                ui->Interpretation_value->setText("normal");
            } else if (BMI_ > 26.4 && BMI_ <= 27.8) {
                ui->Interpretation_value->setText("slight overweight");
            } else if (BMI_ > 27.8 && BMI_ <= 31.1) {
                ui->Interpretation_value->setText("overweight");
            } else if (BMI_ > 31.1) {
                ui->Interpretation_value->setText("much overweight");
            }
        } else {
            //Female case
            if (BMI_ <= 19.1) {
                ui->Interpretation_value->setText("underweight");
            } else if (BMI_ > 19.1 && BMI_ <= 25.8) {
                ui->Interpretation_value->setText("normal");
            } else if (BMI_ > 25.8 && BMI_ <= 27.3) {
                ui->Interpretation_value->setText("slight overweight");
            } else if (BMI_ > 27.3 && BMI_ <= 32.2) {
                ui->Interpretation_value->setText("overweight");
            } else if (BMI_ > 32.2) {
                ui->Interpretation_value->setText("much overweight");
            }
        }
    }
}
