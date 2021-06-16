#pragma once
#include "exchange.h"
#include "bss.h"
#include "uks.h"

extern bss bss_inst;
extern uks uks_inst;

class antiicing_int
{
public:

    bool
        OTKAZ_vtsepiob_pos1dv{},//otkaz v tsepi obograva POS 1 dvigatelya
        OTKAZ_vtsepiob_pos2dv{},//otkaz v tsepi obograva POS 2 dvigatelya
        OTKAZ_vtsepiob_pos3dv{},//otkaz v tsepi obograva POS 3 dvigatelya
        OTKAZ_vtsepiob_pos4dv{},//otkaz v tsepi obograva POS 4 dvigatelya
        POLOBST{},//priznak obogreva lobovogo stekla
        POLST{},//priznak obogreva levogo stekla
        POPST{},//priznak obogreva pravogo stekla
        POV3dv1{},//priznak obograeva vozduhozabornika 1 dvigatelya
        POV3dv2{},//priznak obograeva vozduhozabornika 2 dvigatelya
        POV3dv3{},//priznak obograeva vozduhozabornika 3 dvigatelya
        POV3dv4{},//priznak obograeva vozduhozabornika 4 dvigatelya
        otkaz_l_so121{},//otkaz levogo kanala CO-121
        otkaz_lozhn_srab_lev_so121{},//oozhnoe stabativanie levogo kanala CO_121
        otkaz_lozhn_srab_prav_so121{},//oozhnoe stabativanie pravogo kanala CO_121
        otkaz_p_so121{},//otkaz pravogo kanala CO-121
        otkaz_vozduhozabor{},//otkaz POS vozduhozabornikov
        poppd1{},//priznak obogreva PPD #1
        poppd2{},//priznak obogreva PPD #2
        poppd3{};//priznak obogreva PPD #3

    double
        usho1p{},
        M{},//chislo Maha
        M_buf{},
        alpha_rud_1dv{},//polozhenie richaga upravleniya dvigatelem 1, grad
        alpha_rud_2dv{},//polozhenie richaga upravleniya dvigatelem 2, grad
        alpha_rud_3dv{},//polozhenie richaga upravleniya dvigatelem 3, grad
        alpha_rud_4dv{};//polozhenie richaga upravleniya dvigatelem 4, grad

    bool
        PZ1{},
        PZ2{},
        PZ3{},
        F110_3020{},
        F11_3040{},
        F125_3020{},
        F12_3020{},
        F12_3040{},
        F134_3020{},
        F13_3040{},
        F19_3020{},
        F42_3250{},
        K14_3020{},
        K16_3020{},
        K16_3030{},
        K18_3030{},
        K19_3020{},
        K1_3030{},
        K1_3040{},
        K20_3020{},
        K21_3020{},
        K22_3020{},
        K23_3020{},
        K24_3230{},
        K25_3020{},
        K25_3230{},
        K26_3230{},
        K27_3230{},
        K28_3020{},
        K29_3020{},
        K2_3020{},
        K2_3030{},
        K2_3040{},
        K2_3080{},
        K30_3020{},
        K32_3020{},
        K35_3020{},
        K36_3020{},
        K37_3020{},
        K39_3020{},
        K3_3040{},
        K40_3020{},
        K41_3020{},
        K44_3020{},
        K46_3020{},
        K4_3030{},
        K51_3020{},
        K52_3020{},
        K53_3020{},
        K54_3020{},
        K55_3020{},
        K56_3020{},
        K57_3020{},
        K58_3020{},
        K59_3020{},
        K5_3030{},
        K7_3030{},
        K8_3030{},
        PBSO1{},
        PBSO2{},
        PKPPD{},
        POB1dv1{},
        POB1dv2{},
        POB1dv3{},
        POB1dv4{},
        POB2dv1{},
        POB2dv2{},
        POB2dv3{},
        POB2dv4{},
        POB3dv1{},
        POB3dv2{},
        POB3dv3{},
        POB3dv4{},
        PONdv1{},
        PONdv2{},
        PONdv3{},
        PONdv4{},
        PRSOL{},//priznak raboti signala obledeneniya leviy
        PSOBLL{},
        PSOBLP{},//priznak raboti signala obledeneniya praviy
        PSOLD{},//priznak signala obledeneniya ot levogo datchika
        PSOPD{},//priznak signala obledeneniya ot pravogo datchika
        PVOVNA1{},
        PVOVNA2{},
        PVOVNA3{},
        PVOVNA4{},
        S4_3080{},
        S5_3080{},
        S6_3080{},
        f319_3020{},
        f320_3020{},
        f32_3020{},
        f330_3020{},
        f340_3020{},
        f34_3020{},
        f353_3020{},
        f356_3020{},
        obled_svs{},// priznak signala "obledenenie" v sistemu vozd signalov
        H1_3030{},
        H2_3030{},
        H3_3030{},
        H1_3040{},
        prsop{},
        signal_obled{};

public:
    virtual void updateLogic();

    void antiicing_1();
    void antiicing_2();
    void antiicing_3();
    void antiicing_4();
    void antiicing_5();
    void antiicing_6();
};
