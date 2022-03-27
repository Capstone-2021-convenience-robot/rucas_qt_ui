#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "customer.h"


LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_closeButton_clicked()
{
    this->close();
}

void LoginWindow::on_okButton_clicked()
{

    setCustomerId(ui->idEdit->text());
    Customer customer(getCustomerId());


    emit sendCustomerInfo(customer);
    this->close();
}

void LoginWindow::setCustomerId(QString id) { m_id = id; }
QString LoginWindow::getCustomerId() {return m_id;}
