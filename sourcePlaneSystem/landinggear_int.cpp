#include "landinggear_int.h"
#include "emergencyalarm_int.h"
#include "algorithms.h"
#include "switches.h"
#include "externStruct/Struct_DeviceConnect.h"

extern  SH_DEVICE_CONNECT DEVICE_CONNECT;

extern emergencyalarm_int emergencyalarm;

extern const double ts;

void landinggear_int::updateLogic()
{
    timerEventUpd();
}

void landinggear_int::release()
{
    setVelocity();
    leftRack.release();
    rightRack.release();
    frontRack.release();
}
void landinggear_int::intake()
{
    setVelocity();
    leftRack.intake();
    rightRack.intake();
    frontRack.intake();
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
double landinggear_int::pneumoCheck()
{
    double result{};
    result = 0.04;

    return result;
}

bool landinggear_int::h2_3230()
{
    switch(s31_3230::instance().pos)
    {
    case s31_3230::position::peredn:
    {
        if(frontBalloon.getPresure() <= 0.043)
            return true;
        break;
    }
    case s31_3230::position::lev:
    {
        if(leftBalloon.getPresure() <= 0.043)
            return true;
        break;
    }
    case s31_3230::position::prav:
    {
        if(rightBalloon.getPresure() <= 0.043)
            return true;
        break;
    }
    case s31_3230::position::otkl:
    {
        return false;
        break;
    }
    }
    return false;
}

void landinggear_int::checkForMode()
{
    if(s30_3230::instance().pos == s30_3230::position::release)
    {
        curMode = emergRel;
    }else if(s2_3230::instance().pos == s2_3230::position::release)
    {
        curMode = mode::usualRel;
    } else if(s2_3230::instance().pos == s2_3230::position::intake)
    {
        curMode = mode::usualIntake;
    }
}

bool landinggear_int::mainRack::isSashesOnTheMove()
{
     if(!sashes.isIntaken() && !sashes.isReleased())
         return true;
     else
         return false;
}

bool landinggear_int::mainRack::doShiftHappens()
{
     if(!isShifted() && !isShiftedBack())
         return true;
     else
         return false;

}
void landinggear_int::setVelocity()
{
    if(curMode == mode::usualIntake || curMode == mode::usualRel)
    {
        leftRack.moveVelocity = presureCheck() / 1000;
        rightRack.moveVelocity = presureCheck() / 1000;
        frontRack.moveVelocity = presureCheck() / 1000;
        leftRack.shiftVelocity = presureCheck() / 300;
        rightRack.shiftVelocity = presureCheck() / 300;
        leftRack.sashes.moveVelocity = presureCheck() / 300;
        rightRack.sashes.moveVelocity = presureCheck() / 300;
        frontRack.sashes.moveVelocity = presureCheck() / 300;
        leftRack.wheelcart.moveVelocity = presureCheck() / 500;
        rightRack.wheelcart.moveVelocity = presureCheck() / 500;
    }
    if(curMode == mode::emergRel)
    {
        if(!leftRack.isReleased())
        leftRack.moveVelocity = leftBalloon.consume();
        if(!rightRack.isReleased())
        rightRack.moveVelocity = rightBalloon.consume();
        if(!frontRack.isReleased())
        frontRack.moveVelocity = frontBalloon.consume();

        if(!leftRack.sashes.isReleased())
        leftRack.sashes.moveVelocity = leftBalloon.consume();
        if(!rightRack.sashes.isReleased())
        rightRack.sashes.moveVelocity = rightBalloon.consume();
        if(!frontRack.sashes.isReleased())
        frontRack.sashes.moveVelocity = frontBalloon.consume();
        if(!leftRack.wheelcart.isReleased())
        leftRack.wheelcart.moveVelocity = leftBalloon.consume();
        if(!rightRack.wheelcart.isReleased())
        rightRack.wheelcart.moveVelocity = rightBalloon.consume();
    }
}

void landinggear_int::alarmUpd()
{
    //[1][28]
    bss_inst.s_1_28 = (leftRack.isReleased()) ? true : false;
    //[1][32]
    bss_inst.s_1_32 = (rightRack.isReleased()) ? true : false;
    //[1][30]
    bss_inst.s_1_30 = (frontRack.isReleased()) ? true : false;

    if(curMode == mode::usualIntake)
    {
        //1
        if(!leftRack.isShifted())
        {
            bss_inst.s_1_28_b = true;
            bss_inst.s_1_29 = false;
        }
        //2
        if(leftRack.isShiftedBack())
        {
            bss_inst.s_1_28_b = false;
            bss_inst.s_1_28 = false;
        }
        if(!leftRack.isReleased())
        {
            bss_inst.s_1_29 = true;
        }
        //3
        if(leftRack.sashes.isIntaken())
        {
            bss_inst.s_1_29 = false;
        }

        //1
        if(!rightRack.isShifted())
        {
            bss_inst.s_1_32_b = true;
            bss_inst.s_1_33 = false;
        }
        //2
        if(rightRack.isShiftedBack())
        {
            bss_inst.s_1_32 = false;
            bss_inst.s_1_32_b = false;
        }
        if(!rightRack.isReleased())
        {
            bss_inst.s_1_33 = true;
        }
        //3
        if(rightRack.sashes.isIntaken())
        {
            bss_inst.s_1_33 = false;
        }
    }

    if(curMode == mode::usualRel || curMode == mode::emergRel)
    {
        //1
        if(!leftRack.sashes.isIntaken() && !leftRack.sashes.isReleased())
            bss_inst.s_1_29 = true;
        //2
        if(leftRack.doShiftHappens())
        {
            bss_inst.s_1_28 = false;
            bss_inst.s_1_28_b = true;
            bss_inst.s_1_29 = false;
        }
        //3
        if(leftRack.isShifted())
        {
            bss_inst.s_1_28_b = false;
            bss_inst.s_1_28 = true;
        }

        //1
        if(!rightRack.sashes.isIntaken() && !rightRack.sashes.isReleased())
            bss_inst.s_1_33 = true;
        //2
        if(rightRack.doShiftHappens())
        {
            bss_inst.s_1_32 = false;
            bss_inst.s_1_32_b = true;
            bss_inst.s_1_33 = false;
        }
        //3
        if(rightRack.isShifted())
        {
            bss_inst.s_1_32_b = false;
            bss_inst.s_1_32 = true;
        }
    }



//    //[1][29]
//    bss_inst.s_1_29 = leftRack.isSashesOnTheMove();
//    //[1][33]
//    bss_inst.s_1_33 = rightRack.isSashesOnTheMove();

    //[1][31]
    bss_inst.s_1_31 = frontRackMove(*this);

    bss_inst.Pmalo = (presureCheck() <= 11.0) ? true : false;
    //[1][116]
    DEVICE_CONNECT.OUT_D[1][116] = h2_3230();
}
void landinggear_int::outputUpd()
{

}
//void landinggear_int::balloon_presure( double* P_bal)
//{
//    double delta_V_bal;
//    double V_bal;
//    V_bal = 0;
//    if((*P_bal) == P_bal_l)
//    {
//        V_bal = V_bal_l;
//        delta_V_bal = (Ksho * (*P_bal));
//        V_bal = V_bal + delta_V_bal;
//        V_bal_l = V_bal;
//        *P_bal = 6615000 / V_bal;
//    }
//    if((*P_bal) == P_bal_p)
//    {
//        V_bal = V_bal_p;
//        delta_V_bal = (Ksho * (*P_bal));
//        V_bal = V_bal + delta_V_bal;
//        V_bal_p = V_bal;
//        *P_bal = 6615000 / V_bal;
//    }
//    if((*P_bal) == P_bal_per)
//    {
//        V_bal = V_bal_n;
//        delta_V_bal = (Ksho * (*P_bal));
//        V_bal = V_bal + delta_V_bal;
//        V_bal_n = V_bal;
//        *P_bal = 5550000 / V_bal;
//    }
//}

//main Rack
double landinggear_int::mainRack::release()
{
    sashes.release();
    if(sashes.isReleased())
        chngCurPos(true);
    if(isReleased())
        chngShift(true);
    if(curPos >= 0.25)
        wheelcart.release();
    return curPos;
}
double landinggear_int::mainRack::intake()
{
    chngShift(false);
    if(isShiftedBack())
    {
        chngCurPos(false);
    }
    if(curPos <= 0.75)
        wheelcart.intake();
    if(isIntaken())
        sashes.intake();
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
            curShift = curShift + shiftVelocity * ts;
    }
    else
    {
        if(!isShiftedBack())
            curShift = curShift - shiftVelocity * ts;
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
    if(sashes.isReleased())
        chngCurPos(true);
    return curPos;
}
double landinggear_int::frontRack::intake()
{
    chngCurPos(false);
    if(isIntaken())
        sashes.intake();
    return curPos;
}

bool landinggear_int::frontRackMove(landinggear_int& gear_inst)
{
    if(gear_inst.curMode == mode::usualRel)
    {
        if(!frontRack.isReleased())
            return true;
        else
            return false;
    }
    if(gear_inst.curMode == mode::usualIntake)
    {
        if(!(frontRack.sashes.isIntaken()))
            return true;
        else
            return false;
    }
    return false;
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

double landinggear_int::pneumoballoon::consume()
{
    if(presure > 0.0)presure = presure - 0.0000001;
    else presure = 0.0;

    return presure;
}

void landinggear_int::pneumoballoon::toChargeOn()
{
    presure = balloonFullChargedSpeed;
}

double landinggear_int::pneumoballoon::getPresure()
{
    return presure;
}
