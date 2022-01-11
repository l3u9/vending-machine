#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{

    money += coin;
    ui->lcdNumber->display(money);
    setControl();

}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);

}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);

}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);

}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);

}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);

}

void Widget::on_pbReset_clicked()
{
    int cnt;
    int coins[4] = {500,100,50,10};
    std::map<int,int> changes;
    auto info = QString("");


    for (int coin : coins ) {
        cnt = money / coin;
        money -= (coin * cnt);
        changes.insert(std::pair<int,int>(coin, cnt));
    }

    for (auto iter = changes.rbegin(); iter != changes.rend(); ++iter){
        info.append(QString::number(iter->first) + "￦ : " + QString::number(iter->second) + "\n");
    }


    messageBox.setText("Reset");
    messageBox.setInformativeText(info);
    messageBox.exec();

    setControl();

}

