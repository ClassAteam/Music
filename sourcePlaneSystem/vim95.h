#pragma once
#include <QString>
#include <QVector>
#include "land_comstations.h"



class VIM95
{
public:
    double xJetPosition();
    double yJetPosition();
    double zJetPosition();
    double PolarAngle();

private:
    enum modeType{VOR, ILS, SP50, AVT, VIKL};
    modeType mode;
    double* xJetPos;
    double* yJetPos;
    double* zJetPos;
    double* JetPolarAngle;

    class vorSystem
    {
    public:
        QString capturedBeaconName;
        double northCourseToBeacon;
        double relativeCourseToBeacon;
        bool to_from;
        bool beaconNotCaptured;
        void updateParams();
        void setFreq(double freq);

    private:
        vorBeacon* currBeacon;
        double freq;
    };

    class ilsSystem
    {
    public:
        QString capturedBeaconName;
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

