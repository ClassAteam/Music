#pragma once

class s2_3230
{
public:
    s2_3230();
    static s2_3230& instance();

    bool* Release;
    enum position{release, intake};
    position pos;
    double* bus1;
};

