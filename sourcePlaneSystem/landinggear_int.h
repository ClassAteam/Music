#pragma once
#include "exchange.h"
#include "bss.h"

extern bss bss_inst;

extern double TICK;
const double opened{1.0};
const double balloonFullChargedSpeed{0.045};

class landinggear_int
{
    enum mode{usualRel, emergRel, usualIntake, idle};
    mode curMode;
    double presureCheck();
    double pneumoCheck();
    bool h2_3230();
    void checkForMode();
    void release();
    void intake();
    void setVelocity();
    void alarmUpd();
    void outputUpd();
    bool frontRackMove(landinggear_int& gear_inst);

    class mainRack
    {
    public:
        double curPos{opened};
        double curShift{opened};
        double moveVelocity{opened};
        double shiftVelocity{opened};
        bool isSashesOnTheMove();
        bool doShiftHappens();
        bool isReleased();
        bool isShifted();
        bool isShiftedBack();
        bool isIntaken();
        double release();
        double intake();
    private:
        double chngCurPos(bool open_close);
        double chngShift(bool open_close);

    public:
        class sashes
        {
        public:
            double curPos{opened};
            double moveVelocity{};
            double release();
            double intake();
            bool isReleased();
            bool isIntaken();
        private:
            double chngCurPos(bool open_close);
        };

        class wheelCart
        {
        public:
            double curPos{opened};
            double moveVelocity{};
            bool isReleased();
            bool isIntaken();
            double release();
            double intake();
        private:
            double chngCurPos(bool open_close);
        };
        sashes sashes;
        wheelCart wheelcart;
    };
    class frontRack
    {
    public:
        double curPos{opened};
        double moveVelocity;
        bool isReleased();
        bool isIntaken();
        double release();
        double intake();
    private:
        double chngCurPos(bool open_close);
    public:
        class sashes
        {
        public:
            double curPos{opened};
            double moveVelocity;
            double release();
            double intake();
            bool isReleased();
            bool isIntaken();
        private:
            double chngCurPos(bool open_close);
        };

        sashes sashes;
    };
    class pneumoballoon
    {
        double presure{balloonFullChargedSpeed};
    public:
        double consume();
        void toChargeOn();
        double getPresure();
    };

public:
    mainRack leftRack;
    mainRack rightRack;
    frontRack frontRack;
    pneumoballoon leftBalloon;
    pneumoballoon rightBalloon;
    pneumoballoon frontBalloon;


public:
    virtual void updateLogic();
    void timerEventUpd();
//    void balloon_presure(double* P_bal);
};
