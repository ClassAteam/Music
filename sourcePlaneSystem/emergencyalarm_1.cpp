#include "emergencyalarm_1.h"
#include "externStruct/Struct_DeviceConnect.h"

extern  SH_DEVICE_CONNECT *pDev;


void emergencyalarm_int::emergencyalarm_1()
{

    for(auto & element : lights)
    {
        *element->outClue = *element->inClue;
//        qDebug() << "out_clue:" << element->outClue <<"out_address:" << &element->outClue;
//        qDebug() << "in_clue:" << element->inClue <<"in_address:" << &element->inClue;
//        pDev->OUT_D[2][18] = (element->inClue);
//        pDev->OUT_D[2][20] = (element->inClue);
    }

//    for(int i = 0; i < lights.count(); ++i)
//    {
//        *(lights[i]->outClue) = (lights[i]->inClue);
//        qDebug() << "out_clue:" << lights[i]->outClue <<"out_address:" << &lights[i]->outClue;
//        qDebug() << "in_clue:" <<  lights[i]->inClue <<"in_address:" << &lights[i]->inClue;

//    }

    if(exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
        PRBSS_939 = true;
    else
        PRBSS_939 = false;

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0 && exchange::s8_3364)
        PKLSHN = true;
    else
        PKLSHN = false;

    if (exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
        PRBSS_811 = true;
    else
        PRBSS_811 = false;

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
        PRBSS_812 = true;
    else
        PRBSS_812 = false;

    if ((exchange::ush2dpl >= 18.0) && (exchange::ush2dpp >= 18.0) && (exchange::s5_3364))
        PKLLL = true;
    else
        PKLLL = false;


    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
        PRBSS_913 = true;
    else
    {
        PRBSS_913 = false;
    }
    if (exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
    {
        PRBSS824 = true;
    }
    else
    {
        PRBSS824 = false;
    }

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
    {
        PRBSS825 = true;
    }
    else
    {
        PRBSS825 = false;
    }

    if ((exchange::ush2dpl >= 18.0) && (exchange::ush2dpp >= 18.0) && (exchange::s6_3364))
    {
        PKLPL = true;
    }
    else
    {
        PKLPL = false;
    }

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
        PRBSS926 = true;
    else
        PRBSS926 = false;

    if(exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
        PRBSS837 = true;
    else
        PRBSS837 = false;

    if(exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
        PRBSS838 = true;
    else
        PRBSS838 = false;

    if ((exchange::ush2dpl >= 18.0) && (exchange::ush2dpp >= 18.0) && exchange::s7_3364)
        PKLSHO = true;
    else
    {
        PKLSHO = false;
    }

        //Red lights_1
        static int bss811X2C{};
        lamp_blink(bss_inst.BSS811X1E, bss_inst.BSS811X2C, bss811X2C);

        //Red lights_1
        static int bss824X2D{};
        lamp_blink(bss_inst.BSS824X1G, bss_inst.BSS824X2D, bss824X2D);


        //Red lights_1_4
        static int bss824X2P{};
        lamp_blink(bss_inst.BSS824X1d, bss_inst.BSS824X2P, bss824X2P);


        //White lights_1
        bss_inst.BSS824X2f = (bss_inst.BSS824X1KK) ? true : false;
        static int BSS824X2f{};
        lamp_blink(bss_inst.BSS824X1MM, bss_inst.BSS824X2f, BSS824X2f);

        //White lights_1
        bss_inst.BSS824X2h = (bss_inst.BSS824X3A) ? true : false;
        static int BSS824X2h{};
        lamp_blink(bss_inst.BSS824X3C, bss_inst.BSS824X2h, BSS824X2h);

        //White lights_1 2
        static int BSS825X6E{};
        lamp_blink(bss_inst.BSS825X7A, bss_inst.BSS825X6E, BSS825X6E);

        //White lights_1 17

        static int BSS825X6Y{};
        lamp_blink(bss_inst.BSS825X5BB, bss_inst.BSS825X6Y, BSS825X6Y);

        //White lights_1 18

        static int BSS825X6a{};
        lamp_blink(bss_inst.BSS825X5DD, bss_inst.BSS825X6a, BSS825X6a);

        static int bss838X6g{};
        lamp_blink(bss_inst.BSS838X5MM, bss_inst.BSS838X6g, bss838X6g);
        //4
        static int bss838X6h{};
        lamp_blink(bss_inst.BSS838X7A, bss_inst.BSS838X6h, bss838X6h);

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
