#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H


#include <QWidget>
#include "customer.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    void setCustomerId(QString id);
    QString getCustomerId();


private slots:
    void on_closeButton_clicked();
    void on_okButton_clicked();


private:
    Ui::LoginWindow *ui;

    QString m_id;

signals:
    void sendCustomerInfo(Customer customer);
};

#endif // LOGINWINDOW_H
