#pragma once
#include <QString>
#include <QVector>
#include "land_comstations.h"



class VIM95
{
    enum modeType{VOR, ILS, SP50};
    modeType mode;

    class vorSystem
    {
    public:
        double northCourseToBeacon;
        double relativeCourseToBeacon;
        bool to_from;
        bool beaconNotCaptured;
        void updateParams();
        void setFreq(double freq);

    private:
        vorBeacon* curBeacon;
        double freq;
    };

    class ilsSystem
    {
    public:
        double HorizonArrowValue;
        double GlissadeArrowValue;
        void updateParams();

    private:
        ilsBeacon* currBeacon;
    };

public:
    VIM95();
    ilsSystem ils;
    vorSystem vor;
    static VIM95& instance();
};

