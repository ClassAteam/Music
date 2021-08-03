#include "antiicing_3.h"

void antiicing_int::antiicing_3()
{
static int
    Counter_warmup_k22,
    Counter_warmup_k29,
    Counter_warmup_k40,
    Counter_warmup_k46;

    //1 K56 toggle
    if(f34_3020)
    {
        if(!K14_3020 && !K16_3020 && !K19_3020 && !K20_3020)
            K56_3020 = false;
        else
            K56_3020 = true;
    }
    else
        K56_3020 = false;

    K22_3020 = false;

    //2 K57 toggle
    if(f320_3020)
    {
        if(!K21_3020 && !K23_3020 && !K25_3020 && !K28_3020)
            K57_3020 = false;
        else
            K57_3020 = true;
    }
    else
        K57_3020 = false;

    K29_3020 = false;

    //3 K58 toggle
    if(f330_3020)
    {
        if(!K30_3020 && !K32_3020 && !K35_3020 && !K36_3020)
            K58_3020 = false;
        else
            K58_3020 = true;
    }
    else
        K58_3020 = false;

    K40_3020 = false;

    //4 K59 toggle
    if(f340_3020)
    {
        if(!K37_3020 && !K39_3020 && !K41_3020 && !K44_3020)
            K59_3020 = false;
        else
            K59_3020 = true;
    }
    else
        K59_3020 = false;

    K46_3020 = false;

    //K22 delaying
    if(f32_3020 && !K56_3020)
    {
        Counter_warmup_k22++;

        if(TICK * Counter_warmup_k22 > 1000)
            K22_3020 = true;
    }
    else
    {
        Counter_warmup_k22 = 0;
        K22_3020 = false;
    }

    //K29 delaying
    if(f319_3020 && !K57_3020)
    {
        Counter_warmup_k29++;

        if(TICK * Counter_warmup_k29 > 1000)
            K29_3020 = true;
    }
    else
    {
        Counter_warmup_k29 = 0;
        K29_3020 = false;
    }

    //K40 delaying
    if(f356_3020 && !K58_3020)
    {
        Counter_warmup_k40++;

        if(TICK * Counter_warmup_k40 > 1000)
            K40_3020 = true;
    }
    else
    {
        Counter_warmup_k40 = 0;
        K40_3020 = false;
    }

    //K46 delaying
    if(f353_3020 && !K59_3020)
    {
        Counter_warmup_k46++;

        if(TICK * Counter_warmup_k46 > 1000)
            K46_3020 = true;
    }
    else
    {
        Counter_warmup_k46 = 0;
        K46_3020 = false;
    }

    //BSS824X1z toggle
    if(usho1p >= 18.0 && K22_3020)
        bss_inst.BSS824X1z = true;
    else
        bss_inst.BSS824X1z = false;

    //BSS824X1BB toggle
    if (usho1p >= 18.0 && K29_3020)
        bss_inst.BSS824X1BB = true;
    else
        bss_inst.BSS824X1BB = false;

    //BSS824X1DD toggle
    if(usho1p >= 18.0 && K40_3020)
        bss_inst.BSS824X1DD = true;
    else
        bss_inst.BSS824X1DD = false;

    //BSS824X1FF toggle
    if(usho1p >= 18.0 && K46_3020)
        bss_inst.BSS824X1FF = true;
    else
        bss_inst.BSS824X1FF = false;

    //PONdv1, POB1dv1, POB2dv1, POB3dv1 toggle
    if(exchange::ushpP[0][0] >= 106.0)
    {
        PONdv1 = (K14_3020) ? true : false;
        POB1dv1 = (K16_3020) ? true : false;
        POB2dv1 = (K19_3020) ? true : false;
        POB3dv1 = (K20_3020) ? true : false;
    }
    else
    {
        PONdv1 = false;
        POB1dv1 = false;
        POB2dv1 = false;
        POB3dv1 = false;
    }

    //2 PONdv2, POB1dv2, POB2dv2, POB3dv2 toggle
    if (exchange::ushpP[0][0] >= 106.0)
    {
        PONdv2 = (K21_3020) ? true : false;
        POB1dv2 = (K23_3020) ? true : false;
        POB2dv2 = (K25_3020) ? true : false;
        POB3dv2 = (K28_3020) ? true : false;
    }
    else
    {
        PONdv2 = false;
        POB1dv2 = false;
        POB2dv2 = false;
        POB3dv2 = false;
    }

    //3 PONdv3, POB1dv3, POB2dv3, POB3dv3 toggle
    if(exchange::ushpP[1][0] >= 106.0)
    {
        PONdv3 = (K30_3020) ? true : false;
        POB1dv3 = (K32_3020) ? true : false;
        POB2dv3 = (K35_3020) ? true : false;
        POB3dv3 = (K36_3020) ? true : false;
    }
    else
    {
        PONdv3 = false;
        POB1dv3 = false;
        POB2dv3 = false;
        POB3dv3 = false;
    }

    //4 PONdv4, POB1dv4, POB2dv4, POB3dv4 toggle
    if(exchange::ushpP[1][0] >= 106.0)
    {
        PONdv4 = (K37_3020) ? true : false;
        POB1dv4 = (K39_3020) ? true : false;
        POB2dv4 = (K41_3020) ? true : false;
        POB3dv4 = (K44_3020) ? true : false;
    }
    else
    {
        PONdv4 = false;
        POB1dv4 = false;
        POB2dv4 = false;
        POB3dv4 = false;
    }

    PVOVNA3 = (exchange::ush1p >= 18.0 && S5_3080) ? true : false;
    PVOVNA2 = (exchange::ush2l >= 18.0 && S4_3080) ? true : false;
    PVOVNA1 = (exchange::ush1l >= 18.0 && exchange::s3_3080) ? true : false;
    PVOVNA4 = (exchange::ush2p >= 18.0 && S6_3080) ? true : false;

    bss_inst.BSS825X5p = (exchange::usho1p >= 18.0 && F110_3020) ? true : false;

//    POV3dv1 = (PONdv1 * 35) + (POB1dv1 * 40) + (POB2dv1 * 40) + (POB3dv1 * 30);

//    POV3dv2 = (PONdv2 * 35) + (POB1dv2 * 40) + (POB2dv2 * 40) + (POB3dv2 * 30);

//    POV3dv3 = (PONdv3 * 35) + (POB1dv3 * 40) + (POB2dv3 * 40) + (POB3dv3 * 30);

//    POV3dv4 = (PONdv4 * 35) + (POB1dv4 * 40) + (POB2dv4 * 40) + (POB3dv4 * 30);

}
