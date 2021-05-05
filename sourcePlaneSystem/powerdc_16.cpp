#include "powerdc_16.h"

void powerdc_int::powerdc_16()
{
    static int
        tick[4]{};
    bool* k13_pool[] = {&k13_2420, &k16_2420};
    bool* k31_pool[] = {&k31_2420, &k34_2420};
    bool* purgk1_pool[] = {&purgk1, &purgk21};
    bool* purgk21_pool[] = {&purgk21, &purgk1};
    bool* purgk41_pool[] = {&purgk41, &purgk31};
    bool* purgk31_pool[] = {&purgk31, &purgk41};
    bool* purglk6_pool[] = {&purglk6, &purgpk6};
    bool* purglk4_pool[] = {&purglk4, &purgpk4};
    bool* purglk5_pool[] = {&purglk5, &purgpk6};

    for(int i = 0; i < 2; i++)
    {
        for(int y = 0; y < 3; y++)
        {
            if(*purgk1_pool[i])
            {
                exchange::ushgP[i][y] = ugP[i][y];

                exchange::fshg[i] = fg[i];
                tick[i] = 0;
            }
            else
            {
                if(*purgk21_pool[i])
                {
                    if(i < 1)
                        exchange::ushgP[i][y] = ugP[i + 1][y];
                    else
                        exchange::ushgP[i][y] = ugP[i - 1][y];
                }
                else
                {
                    if(pp400[1])
                    {
                        if(pss400)
                        {
                            exchange::ushgP[i][y] = exchange::ushgP[i + 2][y];
                            exchange::fshg[i] = exchange::fshg[i + 2];
                        }
                        else
                        {
                            if(tick[i] * TICK >= 500)
                            {
                                exchange::ushgP[i][y] = 0.0;
                                exchange::fshg[i] = 0.0;
                            }
                            else
                            {
                                tick[i]++;
                            }
                        }
                    }
                    else
                    {
                        if(purglk2)
                        {
                            exchange::ushgP[i][y] = ugP[4][y];
                            exchange::fshg[i] = fg[4];
                        }
                        else
                        {
                            if(purgpk3)
                            {
                                exchange::ushgP[i][y] = exchange::urapP[y];
                                exchange::fshg[i] = exchange::frap;
                            }
                            else
                            {
                                if(tick[i] * TICK >= 500)
                                {
                                    exchange::ushgP[i][y] = 0;
                                    exchange::fshg[i] = 0;
                                }
                                else
                                {
                                    tick[i]++;
                                }
                            }
                        }
                    }
                }
            }

            if(*purgk41_pool[i])
            {
                exchange::ushgP[i + 2][y] = ugP[i + 2][y];
                exchange::fshg[i + 2] = fg[i + 2];
                tick[i + 2] = 0;
            }
            else
            {
                if(*purgk31_pool[i])
                {
                    exchange::ushgP[i + 2][y] = ugP[i + 2][y];
                    exchange::fshg[i + 2] = fg[i + 2];
                }
                else
                {
                    if(pp400[0])
                    {
                        if(pss400)
                        {
                            exchange::ushgP[i + 2][y] = exchange::ushgP[1][y];
                            exchange::fshg[i + 2] = exchange::fshg[1];
                        }
                        else
                        {
                            if(tick[i + 2] * TICK >= 500)
                            {
                                exchange::ushgP[i + 2][y] = 0;
                                exchange::fshg[i + 2] = 0;
                            }
                            else
                            {
                                tick[i + 2]++;
                            }
                        }
                    }
                    else
                    {
                        if(purgpk3)
                        {
                            exchange::ushgP[i + 2][y] = exchange::urapP[y];
                            exchange::fshg[i + 2] = exchange::frap;
                            tick[i + 2] = 0;
                        }
                        else
                        {
                            if(purglk2)
                            {
                                exchange::ushgP[i + 2][y] = ugP[4][y];
                                exchange::fshg[i + 2] = fg[4];
                                tick[i + 2] = 0;
                            }
                            else
                            {
                                if(tick[i + 2] * TICK >= 500)
                                {
                                    exchange::ushgP[i + 2][y] = 0;
                                    exchange::fshg[i + 2] = 0;
                                }
                                else
                                {
                                    tick[i + 2]++;
                                }
                            }
                        }
                    }
                }
            }

            if(pp400[0])
            {
                if(pss400)
                {

                }
                else
                {
                    if(pp400[1])
                    {

                    }
                    else
                    {
                        if(purglk2)
                        {
                            exchange::ushgP[i + 2][y] = ugP[4][y];
                            exchange::fshg[i + 2] = fg[4];
                        }
                    }
                }
            }
            else
            {
                if(pp400[1])
                {
                    if(!pss400)
                    {
                        if(purgpk3)
                        {
                            exchange::ushgP[i][y] = exchange::urapP[y];
                            exchange::fshg[i] = exchange::frap;
                        }
                    }
                }
            }

            if(*purglk6_pool[i])
            {
                if(i == 0)
                {
                    exchange::ushpP[i][y] = exchange::ushgP[i][y];
                    exchange::fshp[0] = exchange::fshg[0];
                }
                else
                {
                    exchange::ushpP[i][y] = exchange::ushgP[3][y];
                    exchange::fshp[1] = exchange::fshg[2];
                }
            }
            else
            {
                if(i == 0)
                {
                    exchange::ushpP[i][y] = exchange::ushgP[1][y];
                    exchange::fshp[0] = exchange::fshg[1];
                }
                else
                {
                    exchange::ushpP[i][y] = exchange::ushgP[3][y];
                    exchange::fshp[1] = exchange::fshg[3];
                }

            }
            if(*purglk4_pool[i])
            {
                if(*purglk5_pool[i])
                {
                    if(i == 0)
                    {
                        exchange::ushavP[2][y] = ugP[0][y];
                        exchange::fshav[2] = fg[0];
                    }
                    else
                    {
                        exchange::ushavP[3][y] = ugP[3][y];
                        exchange::fshav[3] = fg[3];
                    }
                }
                else
                {
                    if(i == 0)
                    {
                        exchange::ushavP[2][y] = ugP[1][y];
                        exchange::fshav[2] = fg[1];
                    }
                    else
                    {
                        exchange::ushavP[3][y] = ugP[2][y];
                        exchange::fshav[3] = fg[2];
                    }
                }
            }
            else
            {
                if(i ==0)
                {
                    exchange::ushavP[2][y] = exchange::ushpP[0][y];
                    exchange::fshav[2] = exchange::fshp[0];
                }
                else
                {
                    exchange::ushavP[3][y] = exchange::ushpP[1][y];
                    exchange::fshav[3] = exchange::fshp[1];
                }

                if(*k13_pool[i])
                {
                    exchange::ushavP[i][y] = exchange::ushavP[3 - i][y];
                    exchange::fshav[i] = exchange::fshav[3 - i];
                }
                else
                {
                    exchange::ushavP[i][y] = exchange::ushgP[i + 1][y];
                    exchange::fshav[i] = exchange::fshg[i + 1];
                }
            }

            if(*k31_pool[i])
            {
                if(i == 0)
                {
                    exchange::ushpos[0] = exchange::upos;
                    exchange::fshpos[0] = exchange::fpos;
                }
                else
                {
                    exchange::ushpos[1] = exchange::upos;
                    exchange::fshpos[1] = exchange::fpos;
                }
            }
            else
            {
                if(i == 0)
                {
                    exchange::ushpos[0] = exchange::ushavP[0][0];
                    exchange::fshpos[0] = exchange::fshav[0];
                }
                else
                {
                    exchange::ushpos[1] = exchange::ushavP[1][0];
                    exchange::fshpos[1] = exchange::fshav[1];
                }
            }

            if(k14_2420)
            {
                exchange::ushpts[y] = exchange::uptsP[y];
                exchange::fshpts = exchange::fpts ;
            }
            else
            {
                exchange::ushpts[y] = exchange::ushavP[0][y];
                exchange::fshpts = exchange::fshav[0];
            }
        }
    }

}

