#ifndef PRODUCT_H
#define PRODUCT_H


#include <string>
#include <QWidget>

using namespace std;

class Product {

private:

    const QString m_name;
    QString m_id;
    QString m_size;
    QString m_location;
    QString m_quantity;
    QString m_price;
    QPixmap m_img;


public:
    Product() : m_name("null"), m_id("000"), m_size("000"), m_location("000"), m_quantity("000"), m_price("1000")
    {
        //default
    }

    Product(const QString name, QString id, QString size, QString location, QString quantity, QString price) : m_name(name), m_id(id), m_size(size), m_location(location), m_quantity(quantity), m_price(price)
    {

    }

    ~Product(){

    }


    //setter
    void setProductId(QString id){ m_id = id; }
    void setProductSize(QString size){ m_size = size; }
    void setProductLocation(QString location){ m_location = location; }
    void setProductQuantity(QString quantity){ m_quantity = quantity; }
    void setProductPrice(QString price){ m_price = price; }
    void loadProductImage(QString path){ m_img.load(path); }


    //getter
    QString getProductName() { return m_name; }
    QString getProductId() { return m_id; }
    QString getProductSize() { return m_size; }
    QString getProductLocation() { return m_location; }
    QString getProductQuantity() { return m_quantity; }
    QString getProductPrice() { return m_price; }
    QPixmap getProductImage() { return m_img; }


};























#endif // PRODUCT_H
