#pragma once

class s1_3230//Выключатель "ОТКЛЮЧЕНИЕ ОСНОВНОГО УПРАВЛЕНИЯ ШАССИ"
{
public:
    s1_3230();
    static s1_3230& instance();

    bool* On;
    enum position{off, on};
    position pos;
    double* bus1;
};
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
class s3_3230//Выключатель "ОСНОВН УПРАВЛ СИГНАЛ ДАВЛ"
{
public:
    s3_3230();
    static s3_3230& instance();

    bool* On;
    enum position{off, on};
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
class s4_3250//Выключатель "ПОВОРОТ КОЛЕС РУЛЕНИЕ"
{
public:
    s4_3250();
    static s4_3250& instance();

    bool* On;
    enum position{off, on};
    position pos;
    double* bus1;
};

