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
