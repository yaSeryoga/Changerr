#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "changer_functions.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    ui->new_text->setReadOnly(true);
    delete ui;
}


void MainWindow::on_change_btn_clicked()
{
    QString user_text = ui->user_text->toPlainText();
    QString key_word = ui->key_word->toPlainText();
    QString change_word = ui->change_word->toPlainText();



    QString Error = "";
    if (user_text == "") Error += "You do not input text!\n";
    if (key_word == "") Error += "You do not input key word!\n";
    if (finding(user_text, key_word) == false) Error += "Key word was not found in the text!\n";
    if (change_word == "") Error += "You do not input change word!\n";


    if (Error == ""){
        ui->new_text->clear();
        ui->new_text->insertPlainText(change(user_text, key_word, change_word));
    } else QMessageBox::critical(this, "Error", Error);



}
