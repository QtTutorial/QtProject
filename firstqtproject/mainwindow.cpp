#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QCompleter>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    db=new YTDBConnection;
    ui->setupUi(this);
    ui->comboBox->setEnabled(false);
    QStringList cityname;
    if(db->OpenDB())
    {
        if(db->getData(cityname))
        {
            ui->comboBox->addItems(cityname);
        }
    }
}
void MainWindow::on_comboBox_currentIndexChanged()
{
     db->getData(ui->tableView,ui->comboBox->currentText());
}
MainWindow::~MainWindow()
{
    db->CloseDB();
    delete db;
    delete ui;
}
void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked)  ui->comboBox->setEnabled(true);
    else ui->comboBox->setEnabled(false);
}

