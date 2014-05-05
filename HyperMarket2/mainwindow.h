#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculator.h"
#include "database.h"
#include "stuffsuplyment.h"
#include "stuffcardtext.h"
#include "buyingagencydefineform.h"
#include "labelprintform.h"
#include "definestuffform.h"
#include "definestuffgroup.h"
#include "storeintroform.h"
#include "staffintroform.h"
#include "pricinggoodsform.h"
#include "introducingacount.h"
#include "minimumstuffsuplymant.h"
#include "sendstufftostore.h"
#include "sendstufftoshop.h"
#include "buyingagencydefineform.h"
#include "factor.h"
#include "manufacturers.h"
#include "factorprint.h"
#include "searchfactor.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_DB(DataBase db);
    StuffSuplyment *stuff_suplyment;
    StuffCardText *stuff_card_text;
    BuyingAgencyDefineForm *buyin_agency_define;
    LabelPrintForm *label_print;
    DefineStuffForm *define_stuff;
    DefineStuffGroup *define_stuff_group;
    StoreIntroForm *store_intro_form;
    StaffIntroForm *staff_intro_form;
    PricingGoodsForm *pricing_goods_form;
    IntroducingAcount *introducing_acount;
    MinimumStuffSuplymant *minimum_stuff_suplyment;
    SendStuffToShop *send_stuff_to_shop;
    BuyingAgencyDefineForm *buying_agency_define_form;
    Factor *factor;
    Manufacturers *manufacturers;
    Calculator *calc;
    SearchFactor *search_factor;
    
private slots:

    void on_StuffSuplyment_triggered();

    void on_StuffCardText_triggered();

    void on_buyinAgencyDefine_triggered();

    void on_LabelPrint_triggered();

    void on_DefineStuff_triggered();

    void on_DefineStuffGroup_triggered();

    void on_StoreIntro_triggered();

    void on_StaffIntro_triggered();

    void on_PricingGoodsForm_triggered();

    void on_accountIntro_triggered();

    void on_MinimumLevel_triggered();

    void on_SendStuffToShop_triggered();

    void on_Factor_triggered();

    void on_aboutUs_triggered();

    void on_ZeroSuplyment_triggered();

    void on_DailySale_2_triggered();

    void on_BestStuff_triggered();

    void on_BestStuffGroup_triggered();

    void on_DailyInterest_triggered();

    void on_MonthlyInterest_triggered();

    void on_YearlyIntrest_triggered();

    void on_SeeinfBuyFactor_triggered();

    void on_BuyList_triggered();

    void on_BuyOrder_triggered();

    void on_EnterBuyFactor_triggered();

    void on_UserDefine_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_SearchFactor_triggered();

private:
    Ui::MainWindow *ui;
    DataBase MainDataBase;
};

#endif // MAINWINDOW_H
