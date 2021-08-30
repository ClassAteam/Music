#pragma once
#include <QString>
#include <QVector>
#include "land_comstations.h"

struct vorPack//�������� ������ � ������ VOR
{

    int beaconCourse;//������ ����������
    int shifting;//���������� �� ����� ���� ��� ������ �� ��������� �������
    bool to_from;//������ ����������� ������ ��
    int courseAngle;//�������� ���� ����������
    bool signalCaptured;//������ ���������� �����
    QString beaconName;//��� ����������� �����
};


class VIM95
{
    enum modeType{VOR, ILS, SP50};
    modeType mode;

    class vor
    {
        const double VISUAL_DISTANCE{10000};
        const int* course;
        const double* freq;
        bool tryBeaconCapture();
        bool producePack();
        int beaconAzimuth();
        int shifting();
        bool to_from();
        int courseAngle();
        vor(int* course, double* freq);

    public:
        vorBeacon currBeacon;//����������� ���� � ���������� ������,
        //���� currBeacon.alias = "none", �� ���� �� ��� ��������
        vorPack pack;//�������� ����� ������ ��� ���������� ������
    };

    class ilsSystem
    {
    public:
        double proceedValue();//�������� ���������� �� ���������
        double proceedGlissadeValue();//�������� ���������� �� ��������
        ilsLocalizer* currLocalizer;

    private:
        bool tryBeaconCapture();
    };

public:
    VIM95();
    ilsSystem ils;
    static VIM95& instance();
};

