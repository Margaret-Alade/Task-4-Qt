#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QStyleFactory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton->setChecked(true);
    ui->radioButton_4->setChecked(true);
    ui->radioButton->setText("Сова");
    ui->radioButton_2->setText("Крыса");
    ui->radioButton_3->setText("Змея");
    ui->radioButton_4->setText("Паук");

    ui->comboBox->addItem("Зеленый");
    ui->comboBox->addItem("Красный");
    ui->comboBox->addItem("Синий");
    ui->comboBox->addItem("Желтый");

    ui->pushButton->setCheckable(true);

    ui->progressBar->setValue(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);

    ui->progressBar_2->setValue(0);
    ui->progressBar_2->setMinimum(0);
    ui->progressBar_2->setMaximum(10);

    ui->progressBar_2->setStyle(QStyleFactory::create("Fusion"));

    ui->pushButton->setText("Увеличить");

    ui->dial->setValue(0);
    ui->dial->setMinimum(0);
    ui->dial->setMaximum(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dial_sliderMoved(int position)
{
    ui->lineEdit->setText(QString::number(position));
    ui->progressBar->setValue(position);

}


void MainWindow::on_pushButton_toggled(bool checked)
{
    if (checked) {
        int value = ui->progressBar_2->value();

        ui->progressBar_2->setValue(value+1);

        if(ui->progressBar_2->value() == 10) {
            ui->progressBar_2->setValue(0);
        }
    }

}

