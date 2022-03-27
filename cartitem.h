#ifndef CARTITEM_H
#define CARTITEM_H

#include <QString>

class CartItem{

private:

    QString m_name;
    int m_price;
    int m_quantity;
    int m_amount;


public:

    void setItemName(QString name) { m_name = name; }
    void setItemPrice(int price) { m_price = price; }
    void setItemQuantity(int quantity) { m_quantity = quantity; }
    void setItemAmount(int amount) { m_amount = amount; }

    QString getItemName() { return m_name; }
    int getItemPrice() { return m_price; }
    int getItemQuantity() { return m_quantity; }
    int getItemAmount() { return m_amount; }


};





#endif // CARTITEM_H
