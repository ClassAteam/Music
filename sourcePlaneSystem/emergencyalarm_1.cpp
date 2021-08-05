#include "emergencyalarm_1.h"
#include "externStruct/Struct_DeviceConnect.h"

extern  SH_DEVICE_CONNECT *pDev;

void emergencyalarm_int::emergencyalarm_1()
{
    cso_ll_k = false;
    cso_ll_zh = false;
    cso_pl_k = false;
    cso_pl_zh = false;
    cso_sho_k = false;
    cso_sho_zh = false;
    cso_shn_k = false;
    cso_shn_zh = false;
    //Red lights_1
//    static int bss811X2C{};
//    lamp_blink(bss_inst.BSS811X1E, bss811X2C);
    //Red lights_1
    static int bss824X2D{};
    lamp_blink(bss_inst.BSS824X1G, bss824X2D);
    //Red lights_1_4
    static int bss824X2P{};
    lamp_blink(bss_inst.BSS824X1d, bss824X2P);
    //White lights_1
    static int BSS824X2f{};
    lamp_blink(bss_inst.BSS824X1MM, BSS824X2f);
    //White lights_1
    static int BSS824X2h{};
    lamp_blink(bss_inst.BSS824X3C, BSS824X2h);
    //White lights_1 2
    static int BSS825X6E{};
    lamp_blink(bss_inst.BSS825X7A, BSS825X6E);
    //White lights_1 17
    static int BSS825X6Y{};
    lamp_blink(bss_inst.levOpShVipshno, BSS825X6Y);
    //White lights_1 18
    static int BSS825X6a{};
    lamp_blink(bss_inst.pravOpShVipshno, BSS825X6a);
    static int bss838X6g{};
    lamp_blink(bss_inst.BSS838X5MM, bss838X6g);
    static int bss838X6h{};
    lamp_blink(bss_inst.BSS838X7A, bss838X6h);

    for(auto & light : lights)
    {
        if(light->powerCheck())
        {
            light->lightFromBtn();
            light->lightUp();
            light->updCentrlLight(*this);
        }
        else
        {
            *light->outClue = false;
        }
    }


    if (bss_inst.BSS812X5Z == true && bss_inst.BSS812X5b == true)
    {
        bss_inst.BSS812X6M = true;
    }
    else
    {
        bss_inst.BSS812X6M = false;
    }

    if (bss_inst.BSS812X5d == true && bss_inst.BSS812X5f == true)
    {
        bss_inst.BSS812X6N = true;
    }
    else
    {
        bss_inst.BSS812X6N = false;
    }
}
