#include "landinggear_int.h"
#include "algorithms.h"

extern const double ts;

void landinggear_int::updateLogic()
{
    landinggear_123();
//    landinggear_1();
//    landinggear_2();
//    landinggear_3();
//    landinggear_4();
//    landinggear_5();
//    landinggear_6();
//    landinggear_7_8();
//    landinggear_9_10();
//    landinggear_11_12();

}

void landinggear_int::release()
{
    leftRack.release();
    rightRack.release();
    frontRack.release();
    qDebug() << "release";
    qDebug() << "leftRack current pos = " << leftRack.curPos;
    qDebug() << "rightRack current pos = " << rightRack.curPos;
    qDebug() << "frontRack current pos = " << frontRack.curPos;
}
void landinggear_int::intake()
{
    leftRack.intake();
    rightRack.intake();
    frontRack.intake();
    qDebug() << "intake";
    qDebug() << "leftRack current pos = " << leftRack.curPos;
    qDebug() << "rightRack current pos = " << rightRack.curPos;
    qDebug() << "frontRack current pos = " << frontRack.curPos;
}
double landinggear_int::presureCheck()
{
    double result{};

    if (exchange::pgs2 >= 130.0 && exchange::pgs2 < 280.0)
        result = two_points_to_Y(exchange::pgs2, 130.0, 280.0, 0.0, 45.0);

    if (exchange::pgs2 >= 280.0)
        result = 45.0;
    return result;
}
void landinggear_int::setVelocity()
{
    leftRack.moveVelocity = (presureCheck() / 1000);
    rightRack.moveVelocity = presureCheck() / 1000;
    frontRack.moveVelocity = presureCheck() / 1000;
    leftRack.sashes.moveVelocity = presureCheck() / 1000;
    rightRack.sashes.moveVelocity = presureCheck() / 1000;
    frontRack.sashes.moveVelocity = presureCheck() / 1000;
    leftRack.wheelcart.moveVelocity = presureCheck() / 1000;
    rightRack.wheelcart.moveVelocity = presureCheck() / 1000;
}
void landinggear_int::alarmUpd()
{
    bss_inst.levOpShVipshno = (leftRack.isReleased()) ? true : false;
    bss_inst.pravOpShVipshno = (rightRack.isReleased()) ? true : false;
    bss_inst.perOpShasVipno = (frontRack.isReleased()) ? true : false;
    bss_inst.BSS825X5BB = (!leftRack.isReleased() && !leftRack.isIntaken())
                                  ? true : false;
    bss_inst.BSS825X5DD = (!rightRack.isReleased() && !rightRack.isIntaken())
                                  ? true : false;
    bss_inst.BSS824X1n = (leftRack.isIntaken()) ? true : false;
    bss_inst.BSS824X1r = (rightRack.isIntaken()) ? true : false;
    bss_inst.BSS824X1p = (frontRack.isIntaken()) ? true : false;
    bss_inst.BSS824X1j = (presureCheck() <= 1.0) ? true : false;


}
void landinggear_int::outputUpd()
{

}
void landinggear_int::balloon_presure( double* P_bal)
{
    double delta_V_bal;
    double V_bal;
    V_bal = 0;
    if((*P_bal) == P_bal_l)
    {
        V_bal = V_bal_l;
        delta_V_bal = (Ksho * (*P_bal));
        V_bal = V_bal + delta_V_bal;
        V_bal_l = V_bal;
        *P_bal = 6615000 / V_bal;
    }
    if((*P_bal) == P_bal_p)
    {
        V_bal = V_bal_p;
        delta_V_bal = (Ksho * (*P_bal));
        V_bal = V_bal + delta_V_bal;
        V_bal_p = V_bal;
        *P_bal = 6615000 / V_bal;
    }
    if((*P_bal) == P_bal_per)
    {
        V_bal = V_bal_n;
        delta_V_bal = (Ksho * (*P_bal));
        V_bal = V_bal + delta_V_bal;
        V_bal_n = V_bal;
        *P_bal = 5550000 / V_bal;
    }
}

//main Rack
double landinggear_int::mainRack::release()
{
    sashes.release();
    if(sashes.curPos >= 0.4)
        chngCurPos(true);
    if(isReleased())
        chngShift(true);
    if(isShifted())
        wheelcart.release();
    return curPos;
}
double landinggear_int::mainRack::intake()
{
    chngShift(false);
    wheelcart.intake();
    if(isShiftedBack())
    {
        chngCurPos(false);
        sashes.intake();
    }
    return curPos;
}
bool landinggear_int::mainRack::isReleased()
{
    if(curPos >= 1.0)
        return true;
    else
        return false;
}bool landinggear_int::mainRack::isIntaken()
{
    if(curPos <= 0.0)
        return true;
    else
        return false;
}
bool landinggear_int::mainRack::isShifted()
{
    if(curShift >= 1.0)
        return true;
    else
        return false;
}
bool landinggear_int::mainRack::isShiftedBack()
{
    if(curShift <= 0.0)
        return true;
    else
        return false;
}
double landinggear_int::mainRack::chngCurPos(bool open_close)
{
    if(open_close)
    {
        if(!isReleased())
            curPos = curPos + moveVelocity * ts;
    }
    else
    {
        if(!isIntaken())
            curPos = curPos - moveVelocity * ts;
    }
    return curPos;
}
double landinggear_int::mainRack::chngShift(bool open_close)
{
    if(open_close)
    {
        if(!isShifted())
            curShift = curShift + moveVelocity * ts;
    }
    else
    {
        if(!isShiftedBack())
            curShift = curShift - moveVelocity * ts;
    }
    return curPos;
}

//sashes
double landinggear_int::mainRack::sashes::release()
{
    if(!isReleased())
    {
        chngCurPos(true);
    }
    return curPos;
}
double landinggear_int::mainRack::sashes::intake()
{
    if(!isIntaken())
    {
        chngCurPos(false);
    }
    return curPos;
}
bool landinggear_int::mainRack::sashes::isReleased()
{
    if(curPos >= 1.0)
        return true;
    else
        return false;
}
bool landinggear_int::mainRack::sashes::isIntaken()
{
    if(curPos <= 0.0)
        return true;
    else
        return false;
}
double landinggear_int::mainRack::sashes::chngCurPos(bool open_close)
{
    if(open_close)
    {
        if(!isReleased())
            curPos = curPos + moveVelocity * ts;
    }
    else
    {
        if(!isIntaken())
            curPos = curPos - moveVelocity * ts;
    }
    return curPos;
}

//wheelcart
double landinggear_int::mainRack::wheelCart::release()
{
    if(!isReleased())
    {
        chngCurPos(true);
    }
    return curPos;
}
double landinggear_int::mainRack::wheelCart::intake()
{
    if(!isIntaken())
    {
        chngCurPos(false);
    }
    return curPos;
}
bool landinggear_int::mainRack::wheelCart::isReleased()
{
    if(curPos >= 1.0)
        return true;
    else
        return false;
}
bool landinggear_int::mainRack::wheelCart::isIntaken()
{
    if(curPos <= 0.0)
        return true;
    else
        return false;
}
double landinggear_int::mainRack::wheelCart::chngCurPos(bool open_close)
{
    if(open_close)
    {
        if(!isReleased())
            curPos = curPos + moveVelocity * ts;
    }
    else
    {
        if(!isIntaken())
            curPos = curPos - moveVelocity * ts;
    }
    return curPos;
}

//frontRack
double landinggear_int::frontRack::release()
{
    sashes.release();
    if(sashes.curPos >= 0.4)
        chngCurPos(true);
    return curPos;
}
double landinggear_int::frontRack::intake()
{
    sashes.intake();
    chngCurPos(false);
    return curPos;
}
bool landinggear_int::frontRack::isReleased()
{
    if(curPos >= 1.0)
        return true;
    else
        return false;
}
bool landinggear_int::frontRack::isIntaken()
{
    if(curPos <= 0.0)
        return true;
    else
        return false;
}
double landinggear_int::frontRack::chngCurPos(bool open_close)
{
    if(open_close)
    {
        if(!isReleased())
            curPos = curPos + moveVelocity * ts;
    }
    else
    {
        if(!isIntaken())
            curPos = curPos - moveVelocity * ts;
    }
    return curPos;
}
double landinggear_int::frontRack::sashes::release()
{
    chngCurPos(true);
    return curPos;
}
double landinggear_int::frontRack::sashes::intake()
{
    chngCurPos(false);
    return curPos;
}
bool landinggear_int::frontRack::sashes::isReleased()
{
    if(curPos >= 1.0)
        return true;
    else
        return false;
}
bool landinggear_int::frontRack::sashes::isIntaken()
{
    if(curPos <= 0.0)
        return true;
    else
        return false;
}
double landinggear_int::frontRack::sashes::chngCurPos(bool open_close)
{
    if(open_close)
    {
        if(!isReleased())
            curPos = curPos + moveVelocity * ts;
    }
    else
    {
        if(!isIntaken())
            curPos = curPos - moveVelocity * ts;
    }
    return curPos;
}


bool landinggear_int::K5_3250{};
bool landinggear_int::K6_3250{};
bool landinggear_int::K9_3230{};
bool landinggear_int::S18_2930{};


