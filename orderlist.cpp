#include "orderlist.h"
#include "ui_orderlist.h"

OrderList::OrderList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderList)
{
    ui->setupUi(this);

    // initialize table
    clearTable();

}

void OrderList::getOrderInfo(Customer customer){

    m_customer = customer;
    updateTable( m_customer);
}

void OrderList::updateTable(Customer customer){
    clearTable();
    vector<CartItem>::iterator itr;

    for (itr = customer.shoppingCart.begin(); itr != customer.shoppingCart.end(); ++itr){
        ui->orderTable->insertRow(index);
        ui->orderTable->setItem(index, NAME, new QTableWidgetItem(itr->getItemName()));
        ui->orderTable->setItem(index, PRICE, new QTableWidgetItem(QString::number(itr->getItemPrice())));
        ui->orderTable->setItem(index, QUANTITY, new QTableWidgetItem(QString::number(itr->getItemQuantity())));
        ui->orderTable->setItem(index, AMOUNT, new QTableWidgetItem(QString::number(itr->getItemAmount())));

        // get total amount
        totalPrice += itr->getItemAmount();
        ui->priceBox->setText(QString::number(totalPrice) + "₩");

        index ++;
        //ui->debugbox->setNum(index);
    }

}

void OrderList::clearTable(){
    index = 0;
    totalPrice = 0;
    ui->priceBox->setText("0₩");
    ui->orderTable->clearContents();
    ui->orderTable->setRowCount(index);
}



OrderList::~OrderList()
{
    delete ui;
}
