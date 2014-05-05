#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stuff_suplyment = new StuffSuplyment();
    stuff_card_text = new StuffCardText();
    buyin_agency_define = new BuyingAgencyDefineForm();
    label_print = new LabelPrintForm();
    define_stuff = new DefineStuffForm();
    define_stuff_group = new DefineStuffGroup();
    store_intro_form = new StoreIntroForm();
    staff_intro_form = new StaffIntroForm();
    pricing_goods_form = new PricingGoodsForm();
    introducing_acount = new IntroducingAcount();
    minimum_stuff_suplyment = new MinimumStuffSuplymant();
    send_stuff_to_shop = new SendStuffToShop();
    buying_agency_define_form = new BuyingAgencyDefineForm();
    factor = new Factor();
    manufacturers = new Manufacturers();
    search_factor = new SearchFactor();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_DB(DataBase db)
{
    MainDataBase = db;
}


void MainWindow::on_StuffSuplyment_triggered()
{
    stuff_suplyment->exec();
}

void MainWindow::on_StuffCardText_triggered()
{
    stuff_card_text->exec();
}

void MainWindow::on_buyinAgencyDefine_triggered()
{
    buyin_agency_define->set_DB(this->MainDataBase);
    buyin_agency_define->exec();
}

void MainWindow::on_LabelPrint_triggered()
{
    label_print->exec();
}

void MainWindow::on_DefineStuff_triggered()
{
    define_stuff->set_DB(this->MainDataBase);
    define_stuff->exec();
}

void MainWindow::on_DefineStuffGroup_triggered()
{
    define_stuff_group->set_DB(this->MainDataBase);
    define_stuff_group->exec();
}

void MainWindow::on_StoreIntro_triggered()
{
    store_intro_form->set_DB(this->MainDataBase);
    store_intro_form->exec();
}

void MainWindow::on_StaffIntro_triggered()
{
    staff_intro_form->set_DB(this->MainDataBase);
    staff_intro_form->exec();
}

void MainWindow::on_PricingGoodsForm_triggered()
{
    pricing_goods_form->set_DB(this->MainDataBase);
    pricing_goods_form->exec();
}

void MainWindow::on_accountIntro_triggered()
{
    introducing_acount->set_DB(this->MainDataBase);
    introducing_acount->exec();
}

void MainWindow::on_MinimumLevel_triggered()
{
    minimum_stuff_suplyment->set_DB(this->MainDataBase);
    minimum_stuff_suplyment->exec();
}

void MainWindow::on_SendStuffToShop_triggered()
{
    send_stuff_to_shop->set_DB(this->MainDataBase);
    send_stuff_to_shop->exec();
}

void MainWindow::on_Factor_triggered()
{
    factor->set_DB(this->MainDataBase);
    factor->exec();
}

void MainWindow::on_aboutUs_triggered()
{
    manufacturers->exec();
}

void MainWindow::on_ZeroSuplyment_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_DailySale_2_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_BestStuff_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_BestStuffGroup_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_DailyInterest_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_MonthlyInterest_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_YearlyIntrest_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_SeeinfBuyFactor_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_BuyList_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_BuyOrder_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_EnterBuyFactor_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_UserDefine_triggered()
{
    QMessageBox::information(this, "فعال سازی", "برای استفاده از این بخش ابتدا نرم افزار خود را فعال کنید. با سازندگان نرم افزار تماس بگیرید");
}

void MainWindow::on_pushButton_clicked()
{
    factor = new Factor(this);
    factor->set_DB(this->MainDataBase);
    factor->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    pricing_goods_form->set_DB(this->MainDataBase);
    pricing_goods_form->exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    send_stuff_to_shop->set_DB(this->MainDataBase);
    send_stuff_to_shop->exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    calc = new Calculator(this);
    calc->show();
}

void MainWindow::on_SearchFactor_triggered()
{
    search_factor->exec();
}
