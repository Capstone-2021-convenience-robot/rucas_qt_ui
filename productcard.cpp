#include "productcard.h"
#include "ui_productcard.h"


ProductCard::ProductCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductCard)
{
    ui->setupUi(this);
}

ProductCard::~ProductCard()
{
    delete ui;
}



void ProductCard::setName(QString name)
{
    m_name = name;
    ui->productName->setText(name);
}
void ProductCard::setPrice(QString price)
{
    m_price = price;
    ui->price->setText(price);
}
void ProductCard::setImage(QPixmap pixmap)
{
    ui->image->setPixmap(pixmap.scaled(200,160, Qt::KeepAspectRatio));
}
void ProductCard::displayAmount()
{
    ui->amount->setText(QString::number(m_amount));
}

QString ProductCard::getName() { return m_name; }
QString ProductCard::getPrice() { return m_price; }


void ProductCard::setCard(Product product)
{
    setName(product.getProductName());
    setPrice(product.getProductPrice());
    setImage(product.getProductImage());
    displayAmount();
}

void ProductCard::plus1Amount() { m_amount += 1; }
void ProductCard::minus1Amount() { if(m_amount > 0) m_amount-=1; }

//----------------Buttons---------------------//
void ProductCard::on_plusButton_clicked()
{
    plus1Amount();
    displayAmount();
}

void ProductCard::on_minusButton_clicked()
{
    minus1Amount();
    displayAmount();
}

void ProductCard::on_addToCartButton_clicked()
{

    if(m_amount > 0){
        emit sendItemToCart(getName(), getPrice().toInt(), m_amount);


        m_amount = 0;
    }
    displayAmount();
}
