#include "switches.h"
#include "externStruct/Struct_DeviceConnect.h"

extern  SH_DEVICE_CONNECT DEVICE_CONNECT;

s2_3230::s2_3230() : Release{&DEVICE_CONNECT.IN_MAT[156]}
{

}
s2_3230& s2_3230::instance()
{
    static s2_3230 singleton;
    if(*(singleton.Release))
        singleton.pos = intake;
    else
        singleton.pos = release;
    return singleton;
}
s30_3230::s30_3230() : Release{&DEVICE_CONNECT.IN_MAT[469]}
{

}
s30_3230& s30_3230::instance()
{
    static s30_3230 singleton;
    if(*(singleton.Release))
        singleton.pos = release;
    else
        singleton.pos = intake;
    return singleton;
}
