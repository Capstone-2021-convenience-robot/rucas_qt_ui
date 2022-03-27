#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include "customer.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString m_projectPath;
    QString m_imagePath;
    QString makeImagePath(QString imagePath, QString productName);




private:
    Ui::MainWindow *ui;

    Customer m_customer{"default"};

    void updateCustomerInfo(Customer customer);
    void clearShoppingCart();

private slots:
    void getCustomerInfo(Customer customer);
    void putItemToCart(QString name, int price, int quantity);

    void on_clearCartButton_clicked();

signals:
    void sendCustomerInfo(Customer customer);
    void sendOrderInfo(Customer customer);


};

#endif // MAINWINDOW_H
