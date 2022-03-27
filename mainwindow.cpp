#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "product.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    // connect customer info
    connect(ui->loginWindow, SIGNAL(sendCustomerInfo(Customer)), this, SLOT(getCustomerInfo(Customer)));
    connect(this, SIGNAL(sendCustomerInfo(Customer)), ui->recommendationWindow, SLOT(getCustomerInfo(Customer)));
    connect(this, SIGNAL(sendOrderInfo(Customer)), ui->orderList, SLOT(getOrderInfo(Customer)));



    //get relative image path
    m_projectPath = QCoreApplication::applicationDirPath();
    m_imagePath = m_projectPath + "/image";
    ui->recommendationWindow->imagePath = m_imagePath;

    //textbox for debug

    //ui->debugbox->setText("");


    //Product(const string name, uint8_t id, uint8_t size, uint8_t location, uint8_t quantity)
    // *product name must be identical with image file name*
    Product cocacola("cocacola", "000", "030", "108", "011", "1500");
    Product chocosongi("chocosongi", "001", "030", "211", "5", "1400");
    Product cupramen("cupramen", "002", "110", "131", "6", "1400");
    Product samgak("samgak", "003", "040", "511", "13", "1500");
    Product powerade("powerade", "004", "70", "431", "3", "2200");
    Product sunchip("sunchip", "005", "60", "622", "5", "1800");


    //setup UI
    cocacola.loadProductImage(makeImagePath(m_imagePath, cocacola.getProductName()));
    ui->card1->setCard(cocacola);
    connect(ui->card1, SIGNAL(sendItemToCart(QString, int, int)), this, SLOT(putItemToCart(QString, int, int)));

    chocosongi.loadProductImage(makeImagePath(m_imagePath, chocosongi.getProductName()));
    ui->card2->setCard(chocosongi);
    connect(ui->card2, SIGNAL(sendItemToCart(QString, int, int)), this, SLOT(putItemToCart(QString, int, int)));

    cupramen.loadProductImage(makeImagePath(m_imagePath, cupramen.getProductName()));
    ui->card3->setCard(cupramen);
    connect(ui->card3, SIGNAL(sendItemToCart(QString, int, int)), this, SLOT(putItemToCart(QString, int, int)));

    samgak.loadProductImage(makeImagePath(m_imagePath, samgak.getProductName()));
    ui->card4->setCard(samgak);
    connect(ui->card4, SIGNAL(sendItemToCart(QString, int, int)), this, SLOT(putItemToCart(QString, int, int)));

    powerade.loadProductImage(makeImagePath(m_imagePath, powerade.getProductName()));
    ui->card5->setCard(powerade);
    connect(ui->card5, SIGNAL(sendItemToCart(QString, int, int)), this, SLOT(putItemToCart(QString, int, int)));

    sunchip.loadProductImage(makeImagePath(m_imagePath, sunchip.getProductName()));
    ui->card6->setCard(sunchip);
    connect(ui->card6, SIGNAL(sendItemToCart(QString, int, int)), this, SLOT(putItemToCart(QString, int, int)));







}


// generate Image Path for products to load image
QString MainWindow::makeImagePath(QString imagePath, QString productName)
{
    QString fullPath = imagePath + "/" + productName + ".jpeg";
    return fullPath;
}

void MainWindow::getCustomerInfo(Customer customer){
    updateCustomerInfo(customer);
    ui->customerIdBox->setText(m_customer.getCustomerId());
    emit sendCustomerInfo(customer);
}

void MainWindow::updateCustomerInfo(Customer customer){
    m_customer = customer;
}

void MainWindow::putItemToCart(QString name, int price, int quantity){

    int t_amount = price * quantity;
    CartItem tempItem;
    tempItem.setItemName(name);
    tempItem.setItemQuantity(quantity);
    tempItem.setItemPrice(price);
    tempItem.setItemAmount(t_amount);
    m_customer.addToCart(tempItem);
    emit sendOrderInfo(m_customer);
    //ui->debugbox->setText(m_customer.shoppingCart.back().getItemName());    //debug
}

void MainWindow::clearShoppingCart(){
    m_customer.shoppingCart.clear();
    m_customer.shoppingCart.shrink_to_fit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//----------------Buttons---------------------//
void MainWindow::on_clearCartButton_clicked()
{
    clearShoppingCart();
    emit sendOrderInfo(m_customer);
}
