#include "allElCons.h"
#include "powerdc_int.h"


/////////////////////////////////////////////////////////////alternating current
allElConsAlt::allElConsAlt()
{
    //init all consumers by currency, bus to consume from and name
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen1, "PN1B6"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::shavar3, "PN1B4"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::shavar3, "PN1B3L"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::shavar3, "PN1B1L"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::shavar3, "PN1B2L"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::gen1, "PND3BL"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen1, "PN2B6"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen2, "PN2B4"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::gen1, "PN2B3L"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen1, "PN3B3L"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen1, "PN2B1L"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::gen1, "PN2B2L"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::shavar3, "PN1RB1"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::shavar3, "PNTO1DV"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::gen4, "PN2RB1"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen1, "PN3RB1"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::shavar3, "PN1RB2"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::shavar3, "PNTO2DV"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::gen4, "PN2RB2"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen2, "PN3RB2"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen4, "PN1B5"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::shavar4, "PN3B4"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::shavar4, "PN1B3P"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::shavar4, "PN1B1P"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::shavar4, "PN1B2P"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::gen4, "PNDB5"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::gen4, "PNDB3P"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen1, "PN2B5"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen4, "PN4B4"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::gen4, "PN2B3P"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen4, "PN3B3P"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen4, "PN2B1P"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::gen4, "PN2B2P"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::shavar4, "PN1B3P"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::shavar4, "PNTO3DV"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen1, "PN3RB3"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen3, "PN1RB4"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::shavar4, "PNTO4DV"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::shavar4, "PN2RB4"));
    consumers.append(new sngElConsAlt(15, sngElConsAlt::gen1, "PN3RB4"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen4, "PNP3B1L"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen2, "PNP1B1L"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::shavar3, "PNP1B6"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::gen1, "PNP2B1L"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen1, "PNP2B1P"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::gen3, "PNP1B5"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::gen4, "PNP1B1P"));
    consumers.append(new sngElConsAlt(5, sngElConsAlt::shavar4, "PNP3B1P"));
    consumers.append(new sngElConsAlt(8, sngElConsAlt::shavar4, "PDN1"));
//    consumers.append(sngElCons(antiicing_inst.POV3dv1, sngElCons::shp1, "POV3dv1"));
//    consumers.append(sngElCons(antiicing_inst.POV3dv2, sngElCons::shp1, "POV3dv2"));
//    consumers.append(sngElCons(antiicing_inst.POV3dv3, sngElCons::shp2, "POV3dv3"));
//    consumers.append(sngElCons(antiicing_inst.POV3dv4, sngElCons::shp2, "POV3dv4"));
}

QVector<double> allElConsAlt::getIvg_pool()
//take voltages on each bus corresponding to consumers
{
    QVector<double>ivg(consumers.count());
    for(int i = 0; i < consumers.count(); ++i)
    {
        if(consumers[i]->isActive == true)
        {
            switch(consumers[i]->bus)
            {
            case sngElConsAlt::gen1:
                ivg[gen1] += (consumers[i]->currency);
                break;
            case sngElConsAlt::gen2:
                ivg[gen2] += consumers[i]->currency;
                break;
            case sngElConsAlt::gen3:
                ivg[gen3] += consumers[i]->currency;
                break;
            case sngElConsAlt::gen4:
                ivg[gen4] += consumers[i]->currency;
                break;
            case sngElConsAlt::shavar1:
                ivg[shavar1] += consumers[i]->currency;
                break;
            case sngElConsAlt::shavar2:
                ivg[shavar2] += consumers[i]->currency;
                break;
            case sngElConsAlt::shavar3:
                ivg[shavar3] += consumers[i]->currency;
                break;
            case sngElConsAlt::shavar4:
                ivg[shavar4] += consumers[i]->currency;
                break;
            case sngElConsAlt::shp1:
                ivg[shp1] += consumers[i]->currency;
                break;
            case sngElConsAlt::shp2:
                ivg[shp2] += consumers[i]->currency;
                break;
            }
        }
    }
    return ivg;
}

void allElConsAlt::makeCorresCurr()
//change buses in powerdc
{
    QVector<double>buses;
    buses = getIvg_pool();

    buses[shp1] = 5;
    buses[shp2] = 5;
    if(!powerdc_int::purglk4)
        buses[shp1] = buses[shp1] + buses[shavar3];
    if(!powerdc_int::purgpk4)
        buses[shp2]= buses[shp2] + buses[shavar4];

    powerdc_int::ing1 = 0;
    powerdc_int::ing2 = 0;
    if(powerdc_int::purgk1)
    {
        powerdc_int::ing1 = buses[gen1];
        if(powerdc_int::purgk21)
        {
            powerdc_int::ing2 = buses[gen2] + buses[shp1];
        }
        else
        {
            powerdc_int::ing1 +=(buses[gen2] + buses[shp1]);
        }
        if(!powerdc_int::pp400[1] && powerdc_int::pss400)
            powerdc_int::ing1 = powerdc_int::ing1 + buses[gen3] + buses[gen4] + buses[shp2];
    }
    else
    {
        if(powerdc_int::purgk21)
        {
            powerdc_int::ing2 = buses[gen1] + buses[gen2] + buses[shp1];

            if(!powerdc_int::pp400[1] && powerdc_int::pss400)
                powerdc_int::ing2 = powerdc_int::ing2 + buses[gen3] + buses[gen4] + buses[shp2] + buses[shavar4];
        }
        else
        {
            if(powerdc_int::purglk4)
            {
                if(powerdc_int::purglk5)
                    powerdc_int::ing1 = buses[shavar3];
                else
                    if(powerdc_int::prgen[1])
                    powerdc_int::ing2 = buses[shavar3];
            }
        }
    }
    powerdc_int::ing3 = 0;
    powerdc_int::ing4 = 0;

    if(powerdc_int::purgk41)
    {
        powerdc_int::ing4 = buses[gen4];

        if(powerdc_int::purgk31)
            powerdc_int::ing3 = buses[gen3] + buses[shp2];
        else
        {
            powerdc_int::ing4 = buses[gen4] + buses[gen3] + buses[shp2];
            if(!powerdc_int::pp400[0] && powerdc_int::pss400)
                powerdc_int::ing4 = powerdc_int::ing4 + buses[gen1] + buses[gen2] + buses[shp1];
        }

    }
    else
    {
        if(powerdc_int::purgk31)
        {
            powerdc_int::ing3 = buses[gen4] + buses[gen3] + buses[shp2];
            if(!powerdc_int::pp400[0] && powerdc_int::pss400)
            {
                powerdc_int::ing3 = powerdc_int::ing3 + buses[gen1] + buses[gen2] + buses[shp1];
            }
        }
        else
        {
            if(powerdc_int::purgpk4)
            {
                if(powerdc_int::purgpk5)
                    powerdc_int::ing4 = buses[shavar4];
                else
                {
                    if(powerdc_int::prgen[2])
                        powerdc_int::ing3 = buses[shavar4];
                }
            }
        }
    }
    /////////////////////////////////////////////////////ingrap & ingvsu

    double sumA{buses[gen1] + buses[gen2] + buses[gen3] + buses[gen4] + buses[shp1] + buses[shp2]};
    double sumB{buses[gen1] + buses[gen2] + buses[shp1]};
    double sumC{buses[gen3] + buses[gen4]+ buses[shp2]};

    if(powerdc_int::purglk2)
    {
        if(powerdc_int::purglk7)
        {
            if(powerdc_int::purglk8 && powerdc_int::purgpk7)
            {
                powerdc_int::ingvsu = sumA;
            }
            else
            {
                powerdc_int::ingvsu = sumB;
            }
            bss_inst.BSS837X1FF = true;
            uks_inst.UKS2X35 = true;
        }
        else
        {
            if(powerdc_int::purglk8 && powerdc_int::purgpk7)
            {
                powerdc_int::ingvsu = sumC;
                bss_inst.BSS837X1FF = true;
                uks_inst.UKS2X35 = true;
            }
            else
            {
                powerdc_int::ingvsu = 0;
                bss_inst.BSS837X1FF = false;
                uks_inst.UKS2X35 = false;
            }
        }
    }
    else
    {
        powerdc_int::ingvsu = 0;
        bss_inst.BSS837X1FF = false;
    }

    if(powerdc_int::purgpk3)
    {
        if(powerdc_int::purgpk7)
        {
            if(powerdc_int::purglk8 && powerdc_int::purglk7)
            {
                powerdc_int::ingrap = sumA;
                bss_inst.BSS926X3R = true;
                uks_inst.UKS3X324 = true;
            }
            else
            {
                powerdc_int::ingrap = sumC;
                bss_inst.BSS926X3R = true;
                uks_inst.UKS3X324 = true;
            }
        }
        else
        {
            if(powerdc_int::purglk8 && powerdc_int::purglk7)
            {
                powerdc_int::ingrap = sumB;
                bss_inst.BSS926X3R = true;
                uks_inst.UKS3X324 = true;
            }
            else
            {
                powerdc_int::ingrap = 0;
                bss_inst.BSS926X3R = false;
                uks_inst.UKS3X324 = false;
            }
        }
    }
    else
    {
        powerdc_int::ingrap = 0;
        bss_inst.BSS926X3R = false;
    }

    if(powerdc_int::pss400)
        bss_inst.BSS926X3T = true;
    else
        bss_inst.BSS926X3T = false;
}

/////////////////////////////////////////////////////////////direct current
allElConsDir::allElConsDir()
{
    //init all consumers by currency, bus to consume from and name
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shal, "por1kz", &por1kz));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shal, "prr1kz", &prr1kz));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shal, "psr1kz", &psr1kz));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shal, "por1kpr", &por1kpr));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shal, "prr1kpr", &prr1kpr));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shal, "psr1kpr", &psr1kpr));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shal, "por1kpchk", &por1kpchk));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shal, "prr1kpchk", &prr1kpchk));
    consumers.append(new sngElConsDir(30.0, sngElConsDir::shal, "k4_4940", &k4_4940));
    consumers.append(new sngElConsDir(30.0, sngElConsDir::shal, "s1_4940", &s1_4940));
    consumers.append(new sngElConsDir(3.0, sngElConsDir::shal, "prn1gs1", &prn1gs1));
    consumers.append(new sngElConsDir(3.0, sngElConsDir::shal, "prn2gs1", &prn2gs1));
    consumers.append(new sngElConsDir(3.0, sngElConsDir::shal, "prn1gs2", &prn1gs2));
    consumers.append(new sngElConsDir(3.0, sngElConsDir::shal, "prn2gs2", &prn2gs2));
    consumers.append(new sngElConsDir(8.0, sngElConsDir::shal, "pbutzo", &pbutzo));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::sh1dpl, "poppd1", &poppd1));
    consumers.append(new sngElConsDir(8.0, sngElConsDir::sh1dpl, "gk_avn", &gk_avn));
    consumers.append(new sngElConsDir(20.0, sngElConsDir::sh1dpl, "k1_17723", &k1_17723));
    consumers.append(new sngElConsDir(5.0, sngElConsDir::sh1dpl, "s1_11028", &s1_11028));
    consumers.append(new sngElConsDir(5.0, sngElConsDir::sh1dpl, "s1_11313", &s1_11313));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::sh2dpl, "k1_2250", &k1_2250));
    consumers.append(new sngElConsDir(5.0, sngElConsDir::sh2dpl, "s1_11052", &s1_11052));
    consumers.append(new sngElConsDir(35.0, sngElConsDir::sh2dpl, "k14_2420", &k14_2420));
    consumers.append(new sngElConsDir(35.0, sngElConsDir::sh2dpl, "k15_2420", &k15_2420));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::sh1l, "k2_7322", &k2_7322));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::sh1l, "k9_7322", &k9_7322));
    consumers.append(new sngElConsDir(5.0, sngElConsDir::sh1l, "k1_11038", &k1_11038));
    consumers.append(new sngElConsDir(7.0, sngElConsDir::sh1l, "s1_11081", &s1_11081));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::sh2l, "k3_2250", &k3_2250));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::sh2l, "poppd3", &poppd3));
    consumers.append(new sngElConsDir(7.0, sngElConsDir::sh2l, "k3_3650", &k3_3650));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::sh2l, "k4_7322", &k4_7322));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::sh2l, "k11_7322", &k11_7322));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::sh2l, "r865gd", &r865gd));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::sho1l, "k5_2250", &k5_2250));
    consumers.append(new sngElConsDir(7.0, sngElConsDir::sho1l, "y1_3650", &y1_3650));
    consumers.append(new sngElConsDir(7.0, sngElConsDir::sho1l, "y2_3650", &y2_3650));
    consumers.append(new sngElConsDir(7.0, sngElConsDir::sho2l, "k1_17723", &k1_17723));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::shap, "k7_2420", &k7_2420));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::shap, "k8_2420", &k8_2420));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shap, "por2kz", &por2kz));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shap, "prr2kz", &prr2kz));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shap, "psr2kz", &psr2kz));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shap, "por2kpr", &por2kpr));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shap, "prr2kpr", &prr2kpr));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shap, "psr2kpr", &psr2kpr));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shap, "por2kpchk", &por2kpchk));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shap, "prr2kpchk", &prr2kpchk));
    consumers.append(new sngElConsDir(3.0, sngElConsDir::shap, "prn1gs3", &prn1gs3));
    consumers.append(new sngElConsDir(3.0, sngElConsDir::shap, "prn2gs3", &prn2gs3));
    consumers.append(new sngElConsDir(3.0, sngElConsDir::shap, "prn1gs4", &prn1gs4));
    consumers.append(new sngElConsDir(3.0, sngElConsDir::shap, "prn2gs4", &prn2gs4));
    consumers.append(new sngElConsDir(12.0, sngElConsDir::shap, "gk_avl", &gk_avl));
    consumers.append(new sngElConsDir(12.0, sngElConsDir::shap, "gk_avp", &gk_avp));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::shap, "k18_7322", &k18_7322));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::sh1dpp, "k11_2250", &k11_2250));
    consumers.append(new sngElConsDir(9.0, sngElConsDir::sh1dpp, "poppd2", &poppd2));
    consumers.append(new sngElConsDir(8.0, sngElConsDir::sh1dpp, "pbutzr", &pbutzr));
    consumers.append(new sngElConsDir(5.0, sngElConsDir::sh2dpp, "s1_11028", &s1_11028));
    consumers.append(new sngElConsDir(7.0, sngElConsDir::sh2dpp, "s1_11081", &s1_11081));
    consumers.append(new sngElConsDir(5.0, sngElConsDir::sh2dpp, "s2_11052", &s2_11052));
    consumers.append(new sngElConsDir(35.0, sngElConsDir::sh2dpp, "k30_2420", &k30_2420));
    consumers.append(new sngElConsDir(35.0, sngElConsDir::sh2dpp, "k31_2420", &k31_2420));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::sh1p, "k3_7322", &k3_7322));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::sh1p, "k8_7322", &k8_7322));
    consumers.append(new sngElConsDir(5.0, sngElConsDir::sh1p, "k2_11038", &k2_11038));
    consumers.append(new sngElConsDir(10.0, sngElConsDir::sh2p, "k8_2250", &k8_2250));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::sh2p, "prsop", &prsop));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::sh2p, "k5_7322", &k5_7322));
    consumers.append(new sngElConsDir(15.0, sngElConsDir::sh2p, "k10_7322", &k10_7322));
    consumers.append(new sngElConsDir(20.0, sngElConsDir::sh2p, "k2_17723", &k2_17723));
    consumers.append(new sngElConsDir(2.0, sngElConsDir::sho1p, "f32_3020", &f32_3020));
    consumers.append(new sngElConsDir(2.0, sngElConsDir::sho1p, "f319_3020", &f319_3020));
    consumers.append(new sngElConsDir(2.0, sngElConsDir::sho1p, "f356_3020", &f356_3020));
    consumers.append(new sngElConsDir(2.0, sngElConsDir::sho1p, "f353_3020", &f353_3020));
    consumers.append(new sngElConsDir(7.0, sngElConsDir::sho2p, "k1_17723", &k1_17723));
}

QVector<double> allElConsDir::getIvg_pool()
//take voltages on each bus corresponding to consumers
{
    QVector<double>ivg(consumers.count());
    for(int i = 0; i < consumers.count(); ++i)
    {
        if(*(consumers[i]->isActive) == true)
        {
            switch(consumers[i]->bus)
            {
            case sngElConsDir::shal:
                ivg[shal] += (consumers[i]->currency);
                break;
            case sngElConsDir::sh1dpl:
                ivg[sh1dpl] += consumers[i]->currency;
                break;
            case sngElConsDir::sh2dpl:
                ivg[sh2dpl] += consumers[i]->currency;
                break;
            case sngElConsDir::sh1l:
                ivg[sh1l] += consumers[i]->currency;
                break;
            case sngElConsDir::sh2l:
                ivg[sh2l] += consumers[i]->currency;
                break;
            case sngElConsDir::sho1l:
                ivg[sho1l] += consumers[i]->currency;
                break;
            case sngElConsDir::sho2l:
                ivg[sho2l] += consumers[i]->currency;
                break;
            case sngElConsDir::shap:
                ivg[shap] += consumers[i]->currency;
                break;
            case sngElConsDir::sh1dpp:
                ivg[sh1dpp] += consumers[i]->currency;
                break;
            case sngElConsDir::sh2dpp:
                ivg[sh2dpp] += consumers[i]->currency;
                break;
            case sngElConsDir::sh1p:
                ivg[sh1p] += consumers[i]->currency;
                break;
            case sngElConsDir::sh2p:
                ivg[sh2p] += consumers[i]->currency;
                break;
            case sngElConsDir::sho1p:
                ivg[sho1p] += consumers[i]->currency;
                break;
            case sngElConsDir::sho2p:
                ivg[sho2p] += consumers[i]->currency;
                break;
            }
        }
    }
    return ivg;
}

void allElConsDir::makeCorresCurr()
//change buses in powerdc
{
    QVector<double>buses;
    buses = getIvg_pool();

    powerdc_int::insh2dpl = buses[sh2dpl];
    powerdc_int::inshal = buses[shal];
    powerdc_int::insh1dpl = buses[sh1dpl];
    powerdc_int::insh1l = buses[sh1l];
    powerdc_int::insh2l = buses[sh2l];
    powerdc_int::insho1l = buses[sho1l];
    powerdc_int::insho2l = buses[sho2l];
    powerdc_int::inshap = buses[shap];
    powerdc_int::insh1dpp = buses[sh1dpp];
    powerdc_int::insh2dpp = buses[sh2dpp];
    powerdc_int::insh1p = buses[sh1p];
    powerdc_int::insh2p = buses[sh2p];
    powerdc_int::insho1p = buses[sho1p];
    powerdc_int::insho2p = buses[sho2p];

    if(exchange::ushzvsu >= 18.0)
    {
        if(powerdc_int::apdvsu_35)
        {
            powerdc_int::inshzvsu = 600 - 0.14 * powerdc_int::nvsu;
        }
        else
        {
            if(powerdc_int::apdvsu_49)
            {
                powerdc_int::inshzvsu = 250.0;
            }
            else
            {
                powerdc_int::inshzvsu = 0;
            }
        }
    }
    else
    {
        powerdc_int::inshzvsu = 0;
    }

    if(!powerdc_int::purg27lk9)
    {
        powerdc_int::inshal = (powerdc_int::inshal + powerdc_int::insh1dpl + powerdc_int::insh2dpl);
    }
    if(!powerdc_int::purg27pk9)
    {
        powerdc_int::inshap = (powerdc_int::inshap + powerdc_int::insh1dpp + powerdc_int::insh2dpp);
    }

    if(powerdc_int::purg27lk6)
    {
        powerdc_int::iak1 = powerdc_int::inshzvsu;
    }
    else
    {
        if(!powerdc_int::s14_2430)
            powerdc_int::iak1 = 0;
        else
        {
            if(powerdc_int::pvkgvsu27)
            {
                powerdc_int::iak1 = 0.013 * (powerdc_int::ea1 - exchange::ushal) /
                                    powerdc_int::ra1;
            }
            else
            {
                if(powerdc_int::purg27lk4)
                    powerdc_int::iak1 = 0;
                else
                {
                    if(powerdc_int::plp27)
                    {
                        powerdc_int::iak1 = 0.013 * (powerdc_int::ea1 - exchange::ushal) /
                                            powerdc_int::ra1; //what is the order
                    }
                    else
                    {
                        if(powerdc_int::ppp27)
                        {
                            if(powerdc_int::pss27)
                                powerdc_int::iak1 = 0.013 * (powerdc_int::ea1 - exchange::ushal) /
                                                    powerdc_int::ra1;
                            else
                            {
                                powerdc_int::iak1 = powerdc_int::inshal;
                            }
                        }
                        else
                        {
                            if(!powerdc_int::purg27pk3)
                                powerdc_int::iak1 = powerdc_int::inshal;
                            else
                            {
                                if(powerdc_int::purg27pk5)
                                    powerdc_int::iak1 = (powerdc_int::inshal + powerdc_int::inshap) / 2;
                                else
                                    powerdc_int::iak1 = (powerdc_int::inshal + powerdc_int::inshap);
                            }
                        }
                    }
                }
            }
        }
    }

    if(!powerdc_int::s15_2430)
        powerdc_int::iak2 = 0;
    else
    {
        if(powerdc_int::pvkgvsu27 && powerdc_int::purg27pk3)
        {
            powerdc_int::iak2 = 0.013 * (powerdc_int::ea2 - exchange::ushap) /
                                powerdc_int::ra2;
        }
        else
        {
            if(powerdc_int::purg27pk4)
                powerdc_int::iak2 = 0;
            else
            {
                if(powerdc_int::ppp27)
                    powerdc_int::iak2 = 0.013 * (powerdc_int::ea2 - exchange::ushap) /
                                        powerdc_int::ra2;
                else
                {
                    if(powerdc_int::plp27)
                    {
                        if(powerdc_int::pss27)
                            powerdc_int::iak2 = 0.013 * (powerdc_int::ea2 - exchange::ushap) /
                                                powerdc_int::ra2;
                        else
                        {
                            powerdc_int::iak2 = powerdc_int::inshap;
                        }
                    }
                    else
                    {
                        if(!powerdc_int::purg27pk3)
                            powerdc_int::iak2 = powerdc_int::inshap;
                        else
                        {
                            if(!powerdc_int::purg27lk5)
                                powerdc_int::iak2 = powerdc_int::inshal + powerdc_int::inshap;
                            else
                                powerdc_int::iak2 = (powerdc_int::inshal + powerdc_int::inshap) / 2;
                        }
                    }
                }
            }
        }
    }

//    else
//    {
//        inshal = inshal + insh1dpl + insh2dpl;
//    }

    if(powerdc_int::purg27pk9)
    {
        powerdc_int::insh1p = powerdc_int::insh1p + powerdc_int::insh1dpp + powerdc_int::insh2dpp;
    }
    if(powerdc_int::purg27lk9)
    {
        powerdc_int::insh1l = powerdc_int::insh1l + powerdc_int::insh1dpl + powerdc_int::insh2dpl;
    }

//    else
//    {
//        inshap = inshap + insh1dpp + insh2dpp;
//    }

    powerdc_int::insl27 = powerdc_int::insh1l + powerdc_int::insh2l;

    powerdc_int::insp27 = powerdc_int::insh1p + powerdc_int::insh2p;

    if(powerdc_int::plp27)
    {
        powerdc_int::insl27 = powerdc_int::insl27 + powerdc_int::inshal;
    }

    if(powerdc_int::ppp27)
    {
        powerdc_int::insp27 = powerdc_int::insp27 + powerdc_int::inshap;
    }

    if(powerdc_int::purg27lk1)
    {
        powerdc_int::insl27 = powerdc_int::insl27 + powerdc_int::inshal;
    }

    if(powerdc_int::purg27pk1)
    {
        powerdc_int::insp27 = powerdc_int::insp27 + powerdc_int::inshap;
    }

    if(powerdc_int::purg27lk7)
    {
        powerdc_int::insl27 = powerdc_int::insl27  + powerdc_int::insho1l + powerdc_int::insho2l;
    }
    if(powerdc_int::purg27pk7)
    {
        powerdc_int::insp27 = powerdc_int::insp27 + powerdc_int::insho1p + powerdc_int::insho2p;
    }

    powerdc_int::irap1 = 0;
    powerdc_int::irap2 = 0;

    if(powerdc_int::purg27lk4)
    {
        powerdc_int::irap1 = (powerdc_int::insl27 + powerdc_int::inshzvsu);

        if(!powerdc_int::purg27pk4 && powerdc_int::pss27)
        {
            powerdc_int::irap1 = powerdc_int::irap1 + powerdc_int::insp27;
        }
    }

    if(powerdc_int::purg27pk4)
    {
        powerdc_int::irap2 = powerdc_int::irap2 + powerdc_int::insp27;

        if(!powerdc_int::purg27lk4 && powerdc_int::pss27)
        {
            powerdc_int::irap2 = powerdc_int::irap2 + powerdc_int::insl27 +
                                 powerdc_int::inshzvsu;
        }
    }

    powerdc_int::urap1 = 28.5 - 0.003 * powerdc_int::irap1;

    powerdc_int::urap2 = 28.5 - 0.003 * powerdc_int::irap2;

    powerdc_int::ingvsu_27 = 0;

    if(powerdc_int::ppgvsu27)
    {
        powerdc_int::ingvsu_27 = powerdc_int::insl27;

        if(powerdc_int::pss27)
        {
            powerdc_int::ingvsu_27 = powerdc_int::ingvsu_27 + powerdc_int::insp27;
        }
    }

    powerdc_int::ing1_27 = 0;
    powerdc_int::ing2_27 = 0;
    powerdc_int::ing3_27 = 0;
    powerdc_int::ing4_27 = 0;

    if(powerdc_int::prg1)
    {
        if(powerdc_int::pss27)
        {
            powerdc_int::ing1_27 = ((powerdc_int::insl27 + powerdc_int::insp27
                                     +powerdc_int::inshzvsu)/ (powerdc_int::prg1 +
                                       powerdc_int::prg2 + powerdc_int::prg3 +
                                       powerdc_int::prg4));
        }
        else
        {
            powerdc_int::ing1_27 = ((powerdc_int::insl27 + powerdc_int::inshzvsu) /
                                                              (powerdc_int::prg1 + powerdc_int::prg2));
        }
    }

    if(powerdc_int::prg2)
    {
        if(powerdc_int::pss27)
        {
            powerdc_int::ing2_27 = ((powerdc_int::insl27 + powerdc_int::insp27
                                     +powerdc_int::inshzvsu)/ (powerdc_int::prg1 +
                                       powerdc_int::prg2 + powerdc_int::prg3 +
                                       powerdc_int::prg4));
        }
        else
        {
            powerdc_int::ing1_27 = ((powerdc_int::insl27 + powerdc_int::inshzvsu) /
                                                              (powerdc_int::prg1 + powerdc_int::prg2));
        }
    }

    if(powerdc_int::prg3)
    {
        if(powerdc_int::pss27)
        {
            powerdc_int::ing3_27 = ((powerdc_int::insl27 + powerdc_int::insp27
                                     +powerdc_int::inshzvsu)/ (powerdc_int::prg1 +
                                       powerdc_int::prg2 + powerdc_int::prg3 +
                                       powerdc_int::prg4));
        }
        else
        {
            powerdc_int::ing3_27 = powerdc_int::insp27 /
                                   (powerdc_int::prg3 + powerdc_int::prg4);
        }
    }
    if(powerdc_int::prg4)
    {
        if(powerdc_int::pss27)
        {
            powerdc_int::ing4_27 = ((powerdc_int::insl27 + powerdc_int::insp27
                                     +powerdc_int::inshzvsu)/ (powerdc_int::prg1 +
                                       powerdc_int::prg2 + powerdc_int::prg3 +
                                       powerdc_int::prg4));
        }
        else
        {
            powerdc_int::ing4_27 = powerdc_int::insp27 /
                                   (powerdc_int::prg3 + powerdc_int::prg4);
        }
    }
}
bool allElConsDir::por1kz{};
bool allElConsDir::prr1kz{};
bool allElConsDir::psr1kz{};
bool allElConsDir::por1kpr{};
bool allElConsDir::prr1kpr{};
bool allElConsDir::psr1kpr{};
bool allElConsDir::por1kpchk{};
bool allElConsDir::prr1kpchk{};
bool allElConsDir::k4_4940{};
bool allElConsDir::s1_4940{};
bool allElConsDir::prn1gs1{};
bool allElConsDir::prn2gs1{};
bool allElConsDir::prn1gs2{};
bool allElConsDir::prn2gs2{};
bool allElConsDir::pbutzo{};
bool allElConsDir::poppd1{};
bool allElConsDir::gk_avn{};
bool allElConsDir::k1_17723{};
bool allElConsDir::s1_11028{};
bool allElConsDir::s1_11313{};
bool allElConsDir::k1_2250{};
bool allElConsDir::s1_11052{};
bool allElConsDir::k14_2420{};
bool allElConsDir::k15_2420{};
bool allElConsDir::k2_7322{};
bool allElConsDir::k9_7322{};
bool allElConsDir::k1_11038{};
bool allElConsDir::s1_11081{};
bool allElConsDir::k3_2250{};
bool allElConsDir::poppd3{};
bool allElConsDir::k3_3650{};
bool allElConsDir::k4_7322{};
bool allElConsDir::k11_7322{};
bool allElConsDir::r865gd{};
bool allElConsDir::k5_2250{};
bool allElConsDir::y1_3650{};
bool allElConsDir::y2_3650{};
bool allElConsDir::k7_2420{};
bool allElConsDir::k8_2420{};
bool allElConsDir::por2kz{};
bool allElConsDir::prr2kz{};
bool allElConsDir::psr2kz{};
bool allElConsDir::por2kpr{};
bool allElConsDir::prr2kpr{};
bool allElConsDir::psr2kpr{};
bool allElConsDir::por2kpchk{};
bool allElConsDir::prr2kpchk{};
bool allElConsDir::prn1gs3{};
bool allElConsDir::prn2gs3{};
bool allElConsDir::prn1gs4{};
bool allElConsDir::prn2gs4{};
bool allElConsDir::gk_avl{};
bool allElConsDir::gk_avp{};
bool allElConsDir::k18_7322{};
bool allElConsDir::k11_2250{};
bool allElConsDir::poppd2{};
bool allElConsDir::pbutzr{};
bool allElConsDir::s2_11052{};
bool allElConsDir::k30_2420{};
bool allElConsDir::k31_2420{};
bool allElConsDir::k3_7322{};
bool allElConsDir::k8_7322{};
bool allElConsDir::k2_11038{};
bool allElConsDir::k8_2250{};
bool allElConsDir::prsop{};
bool allElConsDir::k5_7322{};
bool allElConsDir::k10_7322{};
bool allElConsDir::k2_17723{};
bool allElConsDir::f32_3020{};
bool allElConsDir::f319_3020{};
bool allElConsDir::f353_3020{};
bool allElConsDir::f356_3020{};
