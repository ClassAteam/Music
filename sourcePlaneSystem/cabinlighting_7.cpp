#include "cabinlighting_7.h"
#include "landinggear_int.h"

extern landinggear_int landinggea;

void cabinlighting_int::cabinlighting_7()
{
    static bool K1_3341{};
    static bool K2_3341{};
    static bool K3_3341{};
    static bool K4_3341{};
    static bool K5_3341{};
    static bool K6_3341{};
    static bool K7_3341{};
    static bool K8_3341{};
    static bool K9_3341{};
    POVSH_L = false;
    POVSH_P = false;
    POVSH_PER = false;

    if (exchange::ush2dpp >= 18.0 && K7_3341)
    {
        POVSH_PER = true;
    }

    if (exchange::ushap >= 18.0 && K8_3341)
    {
        POVSH_L = true;
        if(K9_3341) POVSH_P = true;
    }
    K2_3341 = false;
    K5_3341 = false;
    K7_3341 = false;
    K8_3341 = false;
    K9_3341 = false;

    if(exchange::ush1dpp >= 18.0 && landinggea.frontRack.isReleased()) K2_3341 = true;
    if(exchange::ushap >= 18.0 && exchange::K27_3230) K5_3341 = true;
    if(K2_3341 && !K5_3341) K7_3341 = true;

    K3_3341 = false;
    K6_3341 = false;

    if(exchange::ush1dpl >= 18.0 && landinggea.leftRack.isReleased())
        K3_3341 = true;

    if(exchange::ushal >= 18.0 && exchange::K26_3230)
        K6_3341 = true;

    if(K3_3341 && !K6_3341) K8_3341 = true;

    K4_3341 = false;

    if(exchange::ush1dpp >= 18.0 && landinggea.rightRack.isReleased())
        K4_3341 = true;

    if(K4_3341 && !K5_3341) K9_3341 = true;

}
