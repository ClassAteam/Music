#pragma once
#include "bss.h"
#include "allElCons.h"
#include "input_feed.h"
#include "exchange.h"
#include "algorithms.h"

extern bss bss_inst;

class cabinlighting_int
{
public:
    bool
        PK11PBLLZO,//priznak podklyucheniya kanala 1 svetil'nikov zalivayushego osvesheniya pulta bortovogo levogo letchika
        PK12PBLLZO,//priznak podklyucheniya kanala 2 svetil'nikov zalivayushego osvesheniya pulta bortovogo levogo letchika
        PK12PBPLZO,//priznak podklyucheniya kanala 1 svetil'nikov zalivayushego osvesheniya pulta bortovogo pravogo letchika
        PK1LBSHOZO,//priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya levogo borta shturmana-operatora
        PK1LSPDZO,//priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya levoy i srendey pribornih dosok letchikov(SSD24)
        PK1PBSHNZO,//priznak podlkyucheniya kanala 1 svetilnikov zalivayushego osvesheniya pravogo borta shturmana0navigatora
        PK1PDSHNZO,//priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya pribornoy doski shturmana-navigatora
        PK1PDSHOZO,//priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya pribornoy doski sjturmana - operatora
        PK1PPDZO,//priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya levoy i srendey pribornih dosok letchikov(SSD24)
        PK1SPLSZO,//priznak podlkyucheniya levogo svetilnika zalivayushego osvesheniya srednego pulta
        PK1SPPSZO,//priznak podlkyucheniya pravogo svetilnika zalivayushego osvesheniya srednego pulta
        PK22PBPLZO,//priznak podklyucheniya kanala 2 svetil'nikov zalivayushego osvesheniya pulta bortovogo pravogo letchika
        PK2LBSHOZO,//priznak podklyucheniya kanala 2 svetilnikov zalivayushego osvesheniya levogo borta shturmana-operatora
        PK2LSPDZO,//priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya pravoy i srendey pribornih dosok letchikov(SSD24)
        PK2PBSHNZO,//priznak podlkyucheniya kanala 2 svetilnikov zalivayushego osvesheniya pravogo borta shturmana0navigatora
        PK2PDSHNZO,//priznak podklyucheniya kanala 2 svetilnikov zalivayushego osvesheniya pribornoy doski shturmana-navigatora
        PK2PDSHOZO,//priznak podklyucheniya kanala 2 svetilnikov zalivayushego osvesheniya pribornoy doski sjturmana - operatora
        PK2PPDZO,//priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya levoy i srendey pribornih dosok letchikov(SSD24)
        PSSD37RKL,//priznak podklyucheniya svetilnika svetodiodnogo kabini letchikov
        PSSD37RKSH,//priznak podklyucheniya svetilnika svetodiodnogo kabini shturmanov
        PSSD42L,//priznak podklyucheniya svetilnikov svetodiodnih individualnogo osvesheniya levogo
        PSSD42P,//priznak podklyucheniya svetilnikov svetodiodnih individualnogo osvesheniya pravogo
        S1_3340,//viklyuchatel' upravleniya posadochno-rulezhnimi farami "UBORKA-VIPUSK"
        S2_3340,//viklyuchatel SVET LEV
        S5_3340,//viklyuchatel' SVET PRAV
        S1_3860,//viklyuchatel' PITANIE upravleniya shtangoy zapravki
        otkaz_zaliv_osvesh_ll_1,//otkaz kanala 1 zalivayushego osvesheniya levogo letchika
        otkaz_zaliv_osvesh_ll_2,//otkaz kanala 2 zalivayushego osvesheniya levogo letchika
        otkaz_zaliv_osvesh_pl_1,//otkaz kanala 1 zalivayushego osvesheniya pravogo letchika
        otkaz_zaliv_osvesh_pl_2,//otkaz kanala 2 zalivayushego osvesheniya pravogo letchika
        otkaz_zaliv_osvesh_shn_1,//otkaz kanala 2 zalivayushego osvesheniya shturmana navigatora
        otkaz_zaliv_osvesh_shn_2,//otkaz kanala 2 zalivayushego osvesheniya shturmana navigatora
        otkaz_zaliv_osvesh_sho_1,//otkaz kanala 1 zalivayushego osvesheniya shturmana operatora
        otkaz_zaliv_osvesh_sho_2;//otkaz kanala 2 zalivayushego osvesheniya shturmana operatora
    int
        S1_3341,//pereklyuchatel' yarkosti aeronavigatsionnih ogney |ANO 10% - 30% - 1000% -Miganie"
        S3_3340,//pereklyuchatel' FARI ZAPRAVKI VIPUSK-UBORKA LEV
        S4_3340,//pereklyuchatel FARI ZAPRAVKI VIPUSK-UBORKA PRAV
        S6_3340;//pereklyuchatel sveta posadochno-rulezhnih far |VZLET POSADKA RULENIE-OTKL"

    double
        alpha_fsv_ol,//polozhenie fari svetodiodnoy vidvizhnoy FSV-01 levoy
        alpha_fsv_op,//polozhenie fari svetodiodnoy vidvizhnoy FSV-01 pravoy
        Vpr,//skorost' pribornaya m/s
        alpha_fazl,//polozheni fari FSV-02 osvesheniya agregatov zapravki levoy
        alpha_fazp;//polozheni fari FSV-02 osvesheniya agregatov zapravki pravoy

    bool
        PBUSTO4_1_1k,
        PBUSTO4_1_2k,
        PBUSTO4_2_1k,
        PBUSTO4_2_2k,
        PBUSTO4_3_1k,
        PBUSTO4_3_2k,
        PBUSTO4_4_1k,
        PBUSTO4_4_2k,
        F1_3310,
        F2_3310,
        F3_3310,
        F4_3310,
        F5_3310,
        F6_3310,
        F7_3310,
        F8_3310,
        F1_3312,
        F2_3312,
        F3_3312,
        PSSD37RKSH_D,
        PSSD37RKL_D,
        PBUSTO3_1_1k,
        PBUSTO3_1_2k,
        PBUSTO3_2_1k,
        PBUSTO3_2_2k,
        PBUSTO3_3_1k,
        PBUSTO3_3_2k,
        PBUSTO3_4_1k,
        PBUSTO3_4_2k,
        PFSV_02L,
        PFSV_02P,
        PFPRLR,
        PFPRPR,
        PFSV_01LR,
        PFSV_01PR,
        PV_OSN_HV_10,
        PV_OSN_HV_30,
        PV_OSN_HV_100,
        PV_OSN_HV_MIG,
        PV_DOP,
        K32_3230,
        PVMV10,
        PVMN10,
        PVMV100,
        PVMN100;

    double
        UZOPBLL1,
        UZOPBLL2,
        UZOPBPL1,
        UZOPBPL2,
        UZOPDSHO1,
        UZOPDSHO2,
        UZOLBSHO1,
        UZOLBSHO2,
        UZOPDSHN1,
        UZOPDSHN2,
        UZOPBSHN1,
        UZOPBSHN2,
        USOOKL,
        USOOKSH,
        UZOLSPD1,
        UZOLSPD2,
        UZOPPD1,
        UZOPPD2,
        UZOSPLS1,
        UZOSPPS1;

public:
    virtual void updateLogic();

    void cabinlighting_1();
    void cabinlighting_2();
    void cabinlighting_3();
    void cabinlighting_4();
    void cabinlighting_5();
};
