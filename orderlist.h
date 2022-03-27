#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <QWidget>
#include <QTableWidgetItem>
#include "customer.h"

namespace Ui {
class OrderList;
}

class OrderList : public QWidget
{
    Q_OBJECT

public:
    explicit OrderList(QWidget *parent = nullptr);
    ~OrderList();

    int index;
    int totalPrice;

private:
    Ui::OrderList *ui;

    Customer m_customer{"default"};
    QString name = "Pjy";
    enum column { NAME, PRICE, QUANTITY, AMOUNT };

    void clearTable();
    void updateTable(Customer customer);


private slots:
    void getOrderInfo(Customer customer);

};

#endif // ORDERLIST_H
