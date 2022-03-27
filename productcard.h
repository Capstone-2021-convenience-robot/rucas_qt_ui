#ifndef PRODUCTCARD_H
#define PRODUCTCARD_H


#include <QWidget>
#include "product.h"

namespace Ui {
class ProductCard;
}

class ProductCard : public QWidget
{
    Q_OBJECT

public:
    explicit ProductCard(QWidget *parent = nullptr);
    ~ProductCard();

    void setCard(Product product);

    int getAmount();
    void plus1Amount();
    void minus1Amount();

    QString getName();
    QString getPrice();


private:
    Ui::ProductCard *ui;

    int m_amount = 0;
    QString m_name;
    QString m_price;

    void setName(QString name);
    void setPrice(QString price);
    void setImage(QPixmap pixmap);
    void displayAmount();



private slots:
    void on_plusButton_clicked();
    void on_minusButton_clicked();
    void on_addToCartButton_clicked();

signals:
    void sendItemToCart(QString name, int price, int quantity);


};

#endif // PRODUCTCARD_H
