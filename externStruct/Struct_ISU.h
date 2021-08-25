//expected signals from ISU
#pragma once
#include <QVector>


struct SH_ISU
{
    //ISU
    //1st engine rotate frequency
    double nvd1{};
    //2st engine rotate frequency
    double nvd2{};
    //3st engine rotate frequency
    double nvd3{};
    //4st engine rotate frequency
    double nvd4{};
    //VSU's rotate frequency
    double nvdVsu{};
    //air presure from additional power plug
    double Pvvsu{};
    //eng1 work clue
    bool ezr1_34{};
    //eng2 work clue
    bool ezr2_34{};
    //eng3 work clue
    bool ezr3_34{};
    //eng4 work clue
    bool ezr4_34{};
    //eng1 work clue
    bool prd1dv{};
    //eng2 work clue
    bool prd2dv{};
    //eng3 work clue
    bool prd3dv{};
    //eng4 work clue
    bool prd4dv{};
    // sign of landing wheels wrapping (should be changed for Sl i Sp)
    bool wrapsign{};
    //skorost' peremesheniya klina vozduhozabornika dvigatelya #1
    double dqkldv1{};
    //skorost' peremesheniya klina vozduhozabornika dvigatelya #2
    double dqkldv2{};
    //skorost' peremesheniya klina vozduhozabornika dvigatelya #3
    double dqkldv3{};
    //skorost' peremesheniya klina vozduhozabornika dvigatelya #4
    double dqkldv4{};
    //skorost' peremesheniya stvorok perepuska vozduha dvigatelya #1
    double dfistv1{};
    //skorost' peremesheniya stvorok perepuska vozduha dvigatelya #2
    double dfistv2{};
    //skorost' peremesheniya stvorok perepuska vozduha dvigatelya #3
    double dfistv3{};
    //skorost' peremesheniya stvorok perepuska vozduha dvigatelya #4
    double dfistv4{};
    //
    bool ezr_23sku1_vikl_dv1;//признак сигнала из СКУ "ВЫКЛЮЧИ ДВ"
    bool ezr_23sku2_vikl_dv2;//признак сигнала из СКУ "ВЫКЛЮЧИ ДВ"
    bool ezr_23sku3_vikl_dv3;//признак сигнала из СКУ "ВЫКЛЮЧИ ДВ"
    bool ezr_23sku4_vikl_dv4;//признак сигнала из СКУ "ВЫКЛЮЧИ ДВ"

    //SUR
    //keel speed
    double ddelta_k{};
    //skorost' peremesheniya interzeptora levih
    double ddelta_int_l{};
    //skorost' peremesheniya interzeptora pravogo
    double ddelta_int_p{};
    //skorost' peremesheniya flaperonov levih
    double ddelta_fl_l{};
    //skorost' peremesheniya flaperonov pravih
    double ddelta_fl_p{};
    //skorost' peremesheniya stabilizatora
    double ddelta_fi_st{};
    //priznak signala polnogo zakritiya stvorok gruzovih otsekov
    bool PBI4M_1{};

    //IDP
    double vkx{};//skorost' dvizheniya po VPP(putevaya skorost'), m/s
    double M{};//chislo Maha
    double H_{};//visota poleta, m
    double Ph_{};//atmosfernoe davlenie na dannoy visote

    //SVS
    double Vpr{};

    //from where ???
    bool pk70_vkl{};
    bool pk70_pgo{};
    bool pk70_zgo{};
    bool pk70_kontrt{};
    bool puvzl{};
    bool puvzp{};
    double tnv{};//температура нуружного воздуха

    //VIM95
    enum modeType{VOR, ILS, SP50};//режим установленный в вычислителе
    int course;//курс установленный в вычислителе
    double freq;//частота установленная в вычислителе
    int NorthAngle;//фактический азимут
    //позиция в пространстве ЛА
    double planePosX;
    double planePosY;


};
