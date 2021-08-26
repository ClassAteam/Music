#pragma once

class QPointF;
class QLineF;

double m_2_L_intervals(double input,
                                        double x1,
                                        double x2,
                                        double x3,
                                        double y1,
                                        double y2,
                                        double y3);
double m_3_L_intervals(double input,
                                        double x1,
                                        double x2,
                                        double x3,
                                        double x4,
                                        double y1,
                                        double y2,
                                        double y3,
                                        double y4);
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
                                        double y5);
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
                                        double y6);

double two_points_to_Y(double insert, double x1,
                       double x2, double y1, double y2);

double presure_from_altitude(double altitude);

double yx_d(double *x1,double *y1,int n,double x);

double dist_point_line(QPointF point, QLineF line);
