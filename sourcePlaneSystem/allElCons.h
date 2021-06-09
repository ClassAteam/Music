#pragma once
#include <QVector>
#include "wingsmech_int.h"
#include "hydro_int.h"
#include "landinggear_int.h"
//extern bss bss_inst;
//extern exchange exchange_inst;
extern wingsmech_int wingsmech;
extern hydro_int hydro;
extern landinggear_int landinggea;


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

};
