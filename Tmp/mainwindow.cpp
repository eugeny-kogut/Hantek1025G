#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Qstring"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lib.setFileName("../HTDDSDll.dll");
    lib.load();

    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef int (*Func) ();

        Func f = (Func) lib.resolve("DDSSearch");
        if (f) {
            ui->lineEdit_4->setText(QString::number(f()));
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("FAIL TO LOAD");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef bool (*freq) (int, double, int*, int*);

        freq fr = (freq) lib.resolve("DDSSetFrequency");
        if (fr) {
            int wpn = 0;
            int tn = 0;
            double frequency;
            QString str = ui->lineEdit_2->text();
            frequency = str.toInt();
            if (fr(0, frequency, &wpn, &tn)) {
                ui->lineEdit_4->setText("MAY BE OK");
            } else {
                ui->lineEdit_4->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit->setText("OK");

        typedef bool (*meas) (int, bool, double*);

        meas me = (meas) lib.resolve("DDSGetMeasure");
        if (me) {
            double* ans = new double;
            if (me(0, 0, ans)) {
                ui->lineEdit->setText(QString::number(*ans, 'g', 6));
            } else {
                ui->lineEdit->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef bool (*sets) (int, bool);

        sets se = (sets) lib.resolve("DDSSetSingleWave");
        if (se) {
            if (se(0, 0)) {
                ui->lineEdit_4->setText("MAY BE OK");
            } else {
                ui->lineEdit_4->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef bool (*reset) (int);

        reset re = (reset) lib.resolve("DDSResetCounter");
        if (re) {
            if (re(0)) {
                ui->lineEdit_4->setText("MAY BE OK");
            } else {
                ui->lineEdit_4->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef bool (*sett) (int, bool, bool);

        sett set = (sett) lib.resolve("DDSSetTrigger");
        if (set) {
            if (set(0, 0, 0)) {
                ui->lineEdit_4->setText("MAY BE OK");
            } else {
                ui->lineEdit_4->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef bool (*sets) (int, unsigned short*);

        sets se = (sets) lib.resolve("DDSGetDigitalln");
        unsigned short ln=0;
        if (se) {
            if (se(0, &ln)) {
                ui->lineEdit_4->setText("MAY BE OK");
            } else {
                ui->lineEdit_4->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef bool (*setd) (int, bool);

        setd sed = (setd) lib.resolve("DDSSetDIOMode");
        if (sed) {
            if (sed(0, 0)) {
                ui->lineEdit_4->setText("MAY BE OK");
            } else {
                ui->lineEdit_4->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef bool (*setdout) (int, bool);

        setdout seout = (setdout) lib.resolve("DDSSetDigitalOut");
        if (seout) {
            if (seout(0, 0)) {
                ui->lineEdit_4->setText("MAY BE OK");
            } else {
                ui->lineEdit_4->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef bool (*down) (int, unsigned short*, int);

        down dow = (down) lib.resolve("DDSDownload");
        if (dow) {
            if (dow(0, 0, 0)) {
                ui->lineEdit_4->setText("MAY BE OK");
            } else {
                ui->lineEdit_4->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef bool (*check) (int);
        check ch = (check) lib.resolve("DDSCheck");
        if (ch) {
            if (ch(0)) {
                ui->lineEdit_4->setText("I AM OK");
            } else {
                ui->lineEdit_4->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_4->setText("OK");

        typedef bool (*setp) (int, bool);

        setp sep = (setp) lib.resolve("DDSSetPowerOnOutput");
        if (sep) {
            if (sep(0, 1)) {
                ui->lineEdit_4->setText("MAY BE OK");
            } else {
                ui->lineEdit_4->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_4->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_4->setText("NOT LOADED");
    }
}

void MainWindow::on_pushButton_12_clicked()
{
    bool bLoaded = lib.isLoaded();

    if (bLoaded) {
        ui->lineEdit_3->setText("OK");

        typedef bool (*meas) (int, bool, double*);

        meas me = (meas) lib.resolve("DDSGetMeasure");
        if (me) {
            double* ans = new double;
            if (me(0, 1, ans)) {
                ui->lineEdit_3->setText(QString::number(*ans, 'g', 6));
            } else {
                ui->lineEdit_3->setText("FAIL TO SEND COMMAND");
            }
        } else {
            ui->lineEdit_3->setText("FAIL TO RESOLVE");
        }

    } else {
        ui->lineEdit_3->setText("NOT LOADED");
    }
}


