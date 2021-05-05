#include "algorithms.h"

//to take  the value along the function within 2 linear intervals
double m_2_L_intervals(double input,
                                        double x1,
                                        double x2,
                                        double x3,
                                        double y1,
                                        double y2,
                                        double y3)
{
    double result;
    result = 0;
    if((input >= x1) && (input) < x2)
    {
        result = two_points_to_Y(input,x1, x2, y1, y2 );
        return result;
    }
    if((input >= x2) && (input) <= x3)
    {
        result = two_points_to_Y(input,x2, x3, y2, y3 );
        return result;
    }
    result = y3;
    return result;
}

//to take  the value along the function within 3 linear intervals
double m_3_L_intervals(double input,
                                        double x1,
                                        double x2,
                                        double x3,
                                        double x4,
                                        double y1,
                                        double y2,
                                        double y3,
                                        double y4)
{
    double result;
    result = 0;
    if((input >= x1) && (input) <= x2)
    {
        result = two_points_to_Y(input,x1, x2, y1, y2 );
        return result;
    }
    if((input > x2) && (input) < x3)
    {
        result = two_points_to_Y(input,x2, x3, y2, y3 );
        return result;
    }
    if((input >= x3) && (input) <= x4)
    {
        result = two_points_to_Y(input,x3, x4, y3, y4 );
        return result;
    }
    result = y4;
    return result;
}
double m_4_L_intervals(double input,
                                        double x1,
                                        double x2,
                                        double x3,
                                        double x4,
                                        double x5,
                                        double y1,
                                        double y2,
                                        double y3,
                                        double y4,
                                        double y5)
{
    double result;
    result = 0;
    if((input >= x1) && (input) <= x2)
    {
        result = two_points_to_Y(input,x1, x2, y1, y2 );
        return result;
    }
    if((input > x2) && (input) < x3)
    {
        result = two_points_to_Y(input,x2, x3, y2, y3 );
        return result;
    }
    if((input >= x3) && (input) <= x4)
    {
        result = two_points_to_Y(input,x3, x4, y3, y4 );
        return result;
    }
    if((input >= x4) && (input) <= x5)
    {
        result = two_points_to_Y(input,x4, x5, y4, y5 );
        return result;
    }
    result = y5;
    return result;
}
double m_5_L_intervals(double input,
                                        double x1,
                                        double x2,
                                        double x3,
                                        double x4,
                                        double x5,
                                        double x6,
                                        double y1,
                                        double y2,
                                        double y3,
                                        double y4,
                                        double y5,
                                        double y6)
{
    double result;
    result = 0;
    if((input >= x1) && (input) <= x2)
    {
        result = two_points_to_Y(input,x1, x2, y1, y2 );
        return result;
    }
    if((input > x2) && (input) < x3)
    {
        result = two_points_to_Y(input,x2, x3, y2, y3 );
        return result;
    }
    if((input >= x3) && (input) <= x4)
    {
        result = two_points_to_Y(input,x3, x4, y3, y4 );
        return result;
    }
    if((input >= x4) && (input) <= x5)
    {
        result = two_points_to_Y(input,x4, x5, y4, y5 );
        return result;
    }
    if((input >= x5) && (input) <= x6)
    {
        result = two_points_to_Y(input,x5, x6, y5, y6 );
        return result;
    }
    result = y6;
    return result;
}
// to get Y value from linear function between two points(x1,y1 ; x2,y2)
double two_points_to_Y(double insert, double x1, double x2, double y1, double y2)
{
    double Y;
    Y = (((insert - x1) / (x2 - x1)) * (y2 - y1)) + y1;
    return Y;
}
// to get presure from altitude
double presure_from_altitude(double altitude)
{
    double result;
    altitude = (altitude / 1000);
    result = 101.3 * (pow ((1 -((6.5 * altitude) / 288)), 5.255));
    result = (result / 100);

    return result;

}
double a1[12] = { -0.5, 0, 0.05, 0.1, 1, 2, 5, 8, 10, 12, 15, 20 };
double b1[12] = {806, 760, 755, 751, 674, 596.3, 405.4, 267.4, 198.8,
                 145.5, 90.8, 41.5 };

double a2[12] = { 20, 15, 12, 10, 8 , 5, 2, 1, 0.1, 0.05, 0, -0.5 };
double b2[12] = {41.5, 90.8, 145.5, 198.8, 267.4, 405.4, 596.3, 674.1, 751,
                 755, 760, 806 };
double yx_d(double *x1,double *y1,int n,double x)
{
double f1;
int i,i2;
    if(x<=x1[0])
       f1=y1[0];
    else
       if(x>=x1[n-1])
          f1=y1[n-1];
       else
       {
        i=1;
        while((x-x1[i])>0.)
        i++;
        i2=i-1;
        f1=y1[i2]+(x-x1[i2])/(x1[i2]-x1[i])*(y1[i2]-y1[i]);
       }
    return(f1);
}
