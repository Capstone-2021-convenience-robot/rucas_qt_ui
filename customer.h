#ifndef CUSTOMER_H
#define CUSTOMER_H


#include <vector>
#include <QWidget>
#include "cartitem.h"

using namespace std;

class Customer{


private:

    QString m_customerId;




public:

    Customer(QString customerId): m_customerId(customerId){}

    ~Customer(){}

    vector<CartItem> shoppingCart;







    void setCustomerId(QString customerId) { m_customerId = customerId; }
    QString getCustomerId() { return m_customerId; }

    void addToCart(CartItem item)
    {
        shoppingCart.push_back(item);
    }

    CartItem getBackOfShoppingCart(){
        return shoppingCart.back();
    }


};





#endif // CUSTOMER_H
