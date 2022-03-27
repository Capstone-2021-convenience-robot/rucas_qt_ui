#ifndef RECOMMENDATIONWINDOW_H
#define RECOMMENDATIONWINDOW_H

#include <QWidget>
#include "customer.h"

namespace Ui {
class RecommendationWindow;
}

class RecommendationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RecommendationWindow(QWidget *parent = nullptr);
    QString imagePath;
    ~RecommendationWindow();

private:
    Ui::RecommendationWindow *ui;


private slots:
    void getCustomerInfo(Customer customer);

    void on_okButton_clicked();
};

#endif // RECOMMENDATIONWINDOW_H
