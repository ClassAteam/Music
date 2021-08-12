#pragma once

class s2_3230//Переключатель "ШАССИ: ВЫПУСК - УБОРКА"
{
public:
    s2_3230();
    static s2_3230& instance();

    bool* Release;
    enum position{release, intake};
    position pos;
    double* bus1;
};
class s30_3230//"АВАРИЙНЫЙ ВЫПУСК ШАССИ"
{
public:
    s30_3230();
    static s30_3230& instance();

    bool* Release;
    enum position{off, release};
    position pos;
    double* bus1;
};
class s31_3230//"ПЕРЕКЛЮЧАТЕЛЬ ШАССИ ОТКЛ-ОПОРА ПЕРЕДН-ОПОРА ЛЕВ- ОПОРА ПРАВАЯ"
{
public:
    s31_3230();
    static s31_3230& instance();

    bool* Otkl;
    bool* Peredn;
    bool* Lev;
    bool* Prav;
    enum position{otkl, peredn, lev, prav};
    position pos;
    double* bus1;
};

