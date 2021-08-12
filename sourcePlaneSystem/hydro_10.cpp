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
              double &sst,
              double &skl,
              double &sstv,
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
        qpflp = abs(ddeltaflp * ts) * sfl;
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
    qpvkldv = abs(qpvkldv * ts) * skl;
    qpfistv = abs(qpfistv * ts) * sstv;
}

double hydro_int::qpsumF(int hydroID)
{
    double sum;
    sum = qppchkl[hydroID] +
          qppchkp[hydroID] +
          qpvkldv[hydroID] +
          qpfistv[hydroID] +
          qpk[hydroID]+
          qpintl[hydroID]+
          qpintp[hydroID]+
          qpfll[hydroID]+
          qpflp[hydroID]+
          qpfist[hydroID]+
          qpprl[hydroID]+
          qpprp[hydroID]+
          qpzl[hydroID]+
          qpzp[hydroID]+
          qpstvl[hydroID]+
          qpstvp[hydroID]+
          qpstvn[hydroID]+
          qpshiftl[hydroID]+
          qpshiftp[hydroID]+
          qpshl[hydroID]+
          qpshp[hydroID]+
          qpshn[hydroID]+
          qpnk[hydroID];
    return sum;
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
      koef_sk,
      koef_sint,
      koef_sfl,
      koef_sst,
      koef_skl,
      koef_sstv,
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
      koef_sk,
      koef_sint,
      koef_sfl,
      koef_sst,
      koef_skl,
      koef_sstv,
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
      koef_sk,
      koef_sint,
      koef_sfl,
      koef_sst,
      koef_skl,
      koef_sstv,
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
      koef_sk,
      koef_sint,
      koef_sfl,
      koef_sst,
      koef_skl,
      koef_sstv,
      qpvkldv[3],
      qpfistv[3]
      );

//    qpnk[0] = (landinggea.GK_nk1) ? landinggea.V_nk * ts * koef_snk : 0.0;
//    qpnk[2] = (landinggea.GK_nk2) ? landinggea.V_nk * ts * koef_snk : 0.0;

//    if(!landinggea.gk_oovsh)
//    {
//        static double deltashlp{landinggea.delta_sh_l};
//        static double deltashpp{landinggea.delta_sh_p};
//        static double deltashnp{landinggea.delta_sh_n};
//        static double deltashiftlp{landinggea.delta_shift_l};
//        static double deltashiftpp{landinggea.delta_shift_p};
//        static double deltastvl{landinggea.delta_stv_l};
//        static double deltastvp{landinggea.delta_stv_p};
//        static double deltastvn{landinggea.delta_stv_n};

//        qpshl[1] = abs(landinggea.delta_sh_l - deltashlp) * koef_ssh;
//        qpshp[1] = abs(landinggea.delta_sh_p - deltashpp) * koef_ssh;
//        qpshn[1] = abs(landinggea.delta_sh_n - deltashnp) * koef_ssh;
//        qpshiftl[1] = abs(landinggea.delta_shift_l - deltashiftlp) * koef_sm;
//        qpshiftp[1] = abs(landinggea.delta_shift_p - deltashiftpp) * koef_sm;
//        qpstvl[1] = abs(landinggea.delta_stv_l - deltastvl) * koef_sstvsh;
//        qpstvp[1] = abs(landinggea.delta_stv_p - deltastvp) * koef_sstvsh;
//        qpstvn[1] = abs(landinggea.delta_stv_n - deltastvn) * koef_sstvsh;

//        deltashlp = landinggea.delta_sh_l;
//        deltashpp = landinggea.delta_sh_p;
//        deltashnp = landinggea.delta_sh_n;
//        deltashiftlp = landinggea.delta_shift_l;
//        deltashiftpp = landinggea.delta_shift_p;
//        deltastvl = landinggea.delta_stv_l;
//        deltastvp = landinggea.delta_stv_p;
//        deltastvn = landinggea.delta_stv_n;
//    }
//    else
//    {
//        qpshl[1] = 0.0;
//        qpshp[1] = 0.0;
//        qpshn[1] = 0.0;
//        qpshiftl[1] = 0.0;
//        qpshiftp[1] = 0.0;
//        qpstvl[1] = 0.0;
//        qpstvp[1] = 0.0;
//        qpstvn[1] = 0.0;
//    }

    static double deltazlp{wingsmech.delta_z_l};
    static double deltazpp{wingsmech.delta_z_p};
    static double deltaprlp{wingsmech.delta_pr_l};
    static double deltaprpp{wingsmech.delta_pr_p};
    qpzl[0] = abs(wingsmech.delta_z_l - deltazlp) * koef_sz;
    qpzp[3] = abs(wingsmech.delta_z_p - deltazpp) * koef_sz;
    qpprl[1] = abs(wingsmech.delta_pr_l - deltaprlp) * koef_spr;
    qpprp[2] = abs(wingsmech.delta_pr_p - deltaprpp) * koef_spr;

    deltazlp = wingsmech.delta_z_l;
    deltazpp = wingsmech.delta_z_p;
    deltaprlp = wingsmech.delta_pr_l;
    deltaprpp = wingsmech.delta_pr_l;

    static double X_L_prev{wingsmech.X_L};
    static double X_P_prev{wingsmech.X_P};
    qppchkl[0] = abs(wingsmech.X_L - X_L_prev) * koef_spchk;
    qppchkp[0] = abs(wingsmech.X_P - X_P_prev) * koef_spchk;
    qppchkl[1] = abs(wingsmech.X_L - X_L_prev) * koef_spchk;
    qppchkp[1] = abs(wingsmech.X_P - X_P_prev) * koef_spchk;
    qppchkl[2] = abs(wingsmech.X_L - X_L_prev) * koef_spchk;
    qppchkp[2] = abs(wingsmech.X_P - X_P_prev) * koef_spchk;
    qppchkl[3] = abs(wingsmech.X_L - X_L_prev) * koef_spchk;
    qppchkp[3] = abs(wingsmech.X_P - X_P_prev) * koef_spchk;
    X_L_prev = wingsmech.X_L;
    X_P_prev = wingsmech.X_P;


    qp1sum = qpsumF(0);
    qp2sum = qpsumF(1);
    qp3sum = qpsumF(2);
    qp4sum = qpsumF(3);

}

