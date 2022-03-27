#include "recommendationwindow.h"
#include "ui_recommendationwindow.h"

RecommendationWindow::RecommendationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecommendationWindow)
{
    ui->setupUi(this);



}


void RecommendationWindow::getCustomerInfo(Customer customer){
    ui->cutomerIdBox->setText(customer.getCustomerId());
    ui->cutomerIdBox_2->setText(customer.getCustomerId());
    ui->debugbox->setText(customer.getCustomerId());
}




RecommendationWindow::~RecommendationWindow()
{
    delete ui;
}

void RecommendationWindow::on_okButton_clicked()
{
    this->close();
}
