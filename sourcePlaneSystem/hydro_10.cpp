#include "hydro_10.h"

//static void X(bool &KSURGS1, bool &qp1k, bool &qpintp, bool &qp1intp, bool &qpfll, bool &qp1fll,
//              bool &qpflp, bool &qp1flp, bool &qp1fist);
static void X(bool &ksurgs1,
              double &qpk,//kolichestvo potreblyaemoy zhidkosti pri rabote kilya
              double &qpintl,//kolichestvo potreblyaemoy zhidkosti pri rabote
              //interseptora levogo
              double &qpintp,//kolichestvo potreblyaemoy zhidkosti pri rabote
              //interseptora pravogo
              double &qpfll,//kolichestvo potreblyaemoy zhidkosti pri rabote
              //flaperona levogo
              double &qpflp,//kolichestvo potreblyaemoy zhidkosti pri rabote
              //flaperona pravogo
              double &qpfist,//kolichestvo potreblyaemoy zhidkosti pri rabote
              //stabilizatora
              double &ddelta_k,//skorost' peremesheniya kilya
              double &ddeltaintl,//skorost' peremesheniya interceptora levogo
              double &ddeltaintp,//skorost' peremesheniya interceptora pravogo
              double &ddeltafll,//skorost' peremesheniya flaperonov levih
              double &ddeltaflp,//skorost' peremesheniya flaperonov pravih
              double &dfist,//skorost' peremesheniya stabilizatora
              double &sk,
              double &sint,
              double &sfl,
              double &sfp,
              double &sst,
              double &spchk,
              double &skl,
              double &sstv,
              double &qppchk,//kolichestvo potreblyaemoy gidrozhidkosti pri
              //povorote krila
              double &qpvkldv,//kolichestvo potreblyaemoy zhidkosti pri rabote
              //klina vozduha zabornika
              double &qpfistv//kolichestvo potreblyaemoy gidrozhidkosti pri
              //rabote stvorki perepuska dvigatelya
              )
{
    if(ksurgs1)
    {
        qpk = abs(ddelta_k * ts) * sk;
        qpintl = abs(ddeltaintl * ts) * sint;
        qpintp = abs(ddeltaintp * ts) * sint;
        qpfll = abs(ddeltafll * ts) * sfl;
        qpflp = abs(ddeltaflp * ts) * sfp;
        qpfist = abs(dfist * ts) * sst;
    }
    else
    {
        qpk = 0.0;
        qpintl = 0.0;
        qpintp = 0.0;
        qpfll = 0.0;
        qpflp = 0.0;
        qpfist = 0.0;
    }
    qppchk = abs(wingsmech.D_X_l * ts) * spchk;
    qpvkldv = abs(qpvkldv * ts) * skl;
    qpvkldv = abs(qpfistv * ts) * sstv;
}

void hydro_int::hydro_10()
{
    X(KSURGS[0],
      qpk[0],
      qpintl[0],
      qpintp[0],
      qpfll[0],
      qpflp[0],
      qpfist[0],
      ddelta_k,
      ddelta_int_l,
      ddelta_int_p,
      ddelta_fl_l,
      ddelta_fl_p,
      ddelta_fi_st,
      sk,
      sint,
      sfl,
      sfp,
      sst,
      spchk,
      skl,
      sstv,
      qppchk[0],
      qpvkldv[0],
      qpfistv[0]
      );

    X(KSURGS[1],
      qpk[1],
      qpintl[1],
      qpintp[1],
      qpfll[1],
      qpflp[1],
      qpfist[1],
      ddelta_k,
      ddelta_int_l,
      ddelta_int_p,
      ddelta_fl_l,
      ddelta_fl_p,
      ddelta_fi_st,
      sk,
      sint,
      sfl,
      sfp,
      sst,
      spchk,
      skl,
      sstv,
      qppchk[1],
      qpvkldv[1],
      qpfistv[1]
      );

    X(KSURGS[2],
      qpk[2],
      qpintl[2],
      qpintp[2],
      qpfll[2],
      qpflp[2],
      qpfist[2],
      ddelta_k,
      ddelta_int_l,
      ddelta_int_p,
      ddelta_fl_l,
      ddelta_fl_p,
      ddelta_fi_st,
      sk,
      sint,
      sfl,
      sfp,
      sst,
      spchk,
      skl,
      sstv,
      qppchk[2],
      qpvkldv[2],
      qpfistv[2]
      );

    X(KSURGS[3],
      qpk[3],
      qpintl[3],
      qpintp[3],
      qpfll[3],
      qpflp[3],
      qpfist[3],
      ddelta_k,
      ddelta_int_l,
      ddelta_int_p,
      ddelta_fl_l,
      ddelta_fl_p,
      ddelta_fi_st,
      sk,
      sint,
      sfl,
      sfp,
      sst,
      spchk,
      skl,
      sstv,
      qppchk[3],
      qpvkldv[3],
      qpfistv[3]
      );

    qpnk1 = (landinggea.GK_nk1) ? exchange::speed * ts * snk : 0.0;
    qpnk3 = (landinggea.GK_nk2) ? exchange::speed * ts * snk : 0.0;

    if(landinggea.gk_oovsh)
    {
        static double deltashlp{landinggea.delta_sh_l};
        static double deltashpp{landinggea.delta_sh_p};
        static double deltashnp{landinggea.delta_sh_n};
        static double deltashiftlp{landinggea.delta_shift_l};
        static double deltashiftpp{landinggea.delta_shift_p};
        static double deltastvl{landinggea.delta_stv_l};
        static double deltastvp{landinggea.delta_stv_p};
        static double deltastvn{landinggea.delta_stv_n};

        qp2shl = abs(landinggea.delta_sh_l - deltashlp) * ts * ssh;
        qp2shp = abs(landinggea.delta_sh_p - deltashpp) * ts * ssh;
        qp2shn = abs(landinggea.delta_sh_n - deltashnp) * ts * ssh;
        qp2shiftl = abs(landinggea.delta_shift_l - deltashiftlp) * ts * ssh;
        qp2shiftp = abs(landinggea.delta_shift_p - deltashiftpp) * ts * ssh;
        qp2stvl = abs(landinggea.delta_stv_l - deltastvl) * ts * ssh;
        qp2stvp = abs(landinggea.delta_stv_p - deltastvp) * ts * ssh;
        qp2stvn = abs(landinggea.delta_stv_n - deltastvn) * ts * ssh;

        deltashlp = qp2shl;
        deltashpp = qp2shp;
        deltashnp = qp2shn;
        deltashiftlp = qp2shiftl;
        deltashiftpp = qp2shiftp;
        deltastvl = qp2stvl;
        deltastvp = qp2stvp;
        deltastvn = qp2stvn;
    }
    else
    {
        qp2shl = 0.0;
        qp2shp = 0.0;
        qp2shn = 0.0;
        qp2shiftl = 0.0;
        qp2shiftp = 0.0;
        qp2stvl = 0.0;
        qp2stvp = 0.0;
        qp2stvn = 0.0;
    }

}

