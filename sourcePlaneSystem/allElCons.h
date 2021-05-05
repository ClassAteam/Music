#pragma once
#include <QVector>
//extern bss bss_inst;
//extern exchange exchange_inst;

////////////////////////////////////////////////////////////alternating current
class sngElConsAlt
{
public:
    enum bus_indx{gen1, gen2, gen3, gen4, shavar1, shavar2, shavar3, shavar4, shp1, shp2};

    sngElConsAlt(const double& in_currency, bus_indx in_bus, QString in_name)
        : isActive{false}, currency{in_currency}, bus{in_bus}, name{in_name}
    {
    }

public:
    bool isActive;//need to be pointer i guess
    double currency;
    bus_indx bus;
    QString name;
};

class allElConsAlt
{
public:
    enum bus_indx{gen1, gen2, gen3, gen4, shavar1, shavar2, shavar3, shavar4, shp1, shp2};
    enum major_bus{gvsu, rap};

    allElConsAlt();

    //get current at all buses
    QVector<double> getIvg_pool();

    //adjust all corresponding values
    void makeCorresCurr();

public:
    QVector<sngElConsAlt*> consumers;
    QVector<double> busesLoad;
};
////////////////////////////////////////////////////////////direct current

class sngElConsDir
{
public:
    enum bus_indx{shal, sh1dpl, sh2dpl, sh1l, sh2l, sho1l, sho2l, shap, sh1dpp,
                    sh2dpp, sh1p, sh2p, sho1p, sho2p};

    sngElConsDir(const double& in_currency, bus_indx in_bus, QString in_name, bool* isActive)
        : isActive{isActive}, currency{in_currency}, bus{in_bus}, name{in_name}
    {
    }

public:
    bool* isActive;//need to be pointer i guess
    double currency;
    bus_indx bus;
    QString name;
};

class allElConsDir
{
public:
    enum bus_indx{shal, sh1dpl, sh2dpl, sh1l, sh2l, sho1l, sho2l, shap, sh1dpp,
                    sh2dpp, sh1p, sh2p, sho1p, sho2p};

    allElConsDir();

    //get current at all buses
    QVector<double> getIvg_pool();

    //adjust all corresponding values
    void makeCorresCurr();

public:
    QVector<sngElConsDir*> consumers;
    QVector<double> busesLoad;

    static bool
    por1kz,
    prr1kz,
    psr1kz,
    por1kpr,
    prr1kpr,
    psr1kpr,
    por1kpchk,
    prr1kpchk,
    k4_4940,
    s1_4940,
    prn1gs1,
    prn2gs1,
    prn1gs2,
    prn2gs2,
    pbutzo,
    poppd1,
    gk_avn,
    k1_17723,
    s1_11028,
    s1_11313,
    k1_2250,
    s1_11052,
    k14_2420,
    k15_2420,
    k2_7322,
    k9_7322,
    k1_11038,
    s1_11081,
    k3_2250,
    poppd3,
    k3_3650,
    k4_7322,
    k11_7322,
    r865gd,
    k5_2250,
    y1_3650,
    y2_3650,
    k7_2420,
    k8_2420,
    por2kz,
    prr2kz,
    psr2kz,
    por2kpr,
    prr2kpr,
    psr2kpr,
    por2kpchk,
    prr2kpchk,
    prn1gs3,
    prn2gs3,
    prn1gs4,
    prn2gs4,
    gk_avl,
    gk_avp,
    k18_7322,
    k11_2250,
    poppd2,
    pbutzr,
    s2_11052,
    k30_2420,
    k31_2420,
    k3_7322,
    k8_7322,
    k2_11038,
    k8_2250,
    prsop,
    k5_7322,
    k10_7322,
    k2_17723,
    f32_3020,
    f319_3020,
    f356_3020,
    f353_3020;
};
