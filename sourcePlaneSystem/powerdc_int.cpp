#include "powerdc_int.h"

void powerdc_int::updateLogic()
{
    powerdc_1();
    powerdc_2_3();
    powerdc_4();
    powerdc_5_6();
    powerdc_7();
    powerdc_8();
    powerdc_9_10();
    powerdc_11();
    powerdc_12();
    powerdc_13();
    powerdc_16();
    powerdc_14();
    powerdc_15();
    powerdc_20();
    powerdc_21();
}

double powerdc_int::ea1{25.5};
double powerdc_int::ea2{25.5};
double powerdc_int::uak1{25.5};
double powerdc_int::uak2{25.5};
double powerdc_int::iak1{};
double powerdc_int::iak2{};
double powerdc_int::ra1{};
double powerdc_int::ra2{};
bool powerdc_int::prg1{};
bool powerdc_int::prg2{};
bool powerdc_int::prg3{};
bool powerdc_int::prg4{};
bool powerdc_int::prgvsu{};
bool powerdc_int::ppgvsu27{};
bool powerdc_int::plp27{};
bool powerdc_int::ppp27{};
bool powerdc_int::pss27{};
bool powerdc_int::pvkgvsu27{};
bool powerdc_int::purg27lk1{};
bool powerdc_int::purg27pk1{};
bool powerdc_int::purg27pk3{};
bool powerdc_int::purg27lk4{};
bool powerdc_int::purg27pk4{};
bool powerdc_int::purg27lk5{};
bool powerdc_int::purg27pk5{};
bool powerdc_int::purg27lk6{};
bool powerdc_int::purg27lk7{};
bool powerdc_int::purg27pk7{};
bool powerdc_int::purg27lk9{};
bool powerdc_int::purg27pk9{};
bool powerdc_int::apdvsu_35{};
bool powerdc_int::apdvsu_49{};
double powerdc_int::ushpzl{};
double powerdc_int::ushpzp{};
double powerdc_int::inpp27{};
double powerdc_int::irap1{};
double powerdc_int::irap2{};
double powerdc_int::insh1dpl{};
double powerdc_int::insh2dpl{};
double powerdc_int::insh1dpp{};
double powerdc_int::insh2dpp{};
double powerdc_int::inshal27{};
double powerdc_int::inshap27{};
double powerdc_int::insh1l{};
double powerdc_int::insh1p{};
double powerdc_int::insh2l{};
double powerdc_int::insh2p{};
double powerdc_int::inshp[2][3]{};
double powerdc_int::inshav[4][3]{};
double powerdc_int::inshzvsu{};
double powerdc_int::insl27{};
double powerdc_int::insp27{};
double powerdc_int::insho1l{};
double powerdc_int::insho1p{};
double powerdc_int::insho2l{};
double powerdc_int::insho2p{};
double powerdc_int::kg1_27{};
double powerdc_int::kg2_27{};
double powerdc_int::kg3_27{};
double powerdc_int::kg4_27{};
double powerdc_int::nvsu{};
double powerdc_int::pbgvsu{};
double powerdc_int::ugrvsu{};
double powerdc_int::uo1ak{};
double powerdc_int::uo2ak{};
double powerdc_int::ipr{};
double powerdc_int::ur1ak{};
double powerdc_int::ur2ak{};
double powerdc_int::uz1ak{};
double powerdc_int::uz2ak{};
double powerdc_int::uls27{};
double powerdc_int::ups27{};
double powerdc_int::ugvsu27{};
double powerdc_int::ugrvsu27{};
double powerdc_int::ivgvsu27{};
double powerdc_int::ingvsu_27{};
double powerdc_int::divgvsu27{};
double powerdc_int::kak{};
double powerdc_int::urap1{};
double powerdc_int::urap2{};
double powerdc_int::fg_27[]{};
double powerdc_int::ng1_27{};
double powerdc_int::ng2_27{};
double powerdc_int::ng3_27{};
double powerdc_int::ng4_27{};
double powerdc_int::ngvsu_27{};
double powerdc_int::ivg1_27{};
double powerdc_int::ivg2_27{};
double powerdc_int::ivg3_27{};
double powerdc_int::ivg4_27{};
double powerdc_int::ivgvsu_27{};
double powerdc_int::ing1_27{};
double powerdc_int::ing2_27{};
double powerdc_int::ing3_27{};
double powerdc_int::ing4_27{};
double powerdc_int::ingrap_27{};
double powerdc_int::divg1_27{};
double powerdc_int::divg2_27{};
double powerdc_int::divg3_27{};
double powerdc_int::divg4_27{};
double powerdc_int::divgvsu_27{};
double powerdc_int::ug1_27{};
double powerdc_int::ug2_27{};
double powerdc_int::ug3_27{};
double powerdc_int::ug4_27{};
double powerdc_int::ugvsu_27{};
double powerdc_int::ug1r_27{};
double powerdc_int::ug2r_27{};
double powerdc_int::ug3r_27{};
double powerdc_int::ug4r_27{};
double powerdc_int::ugvsur_27{};
double powerdc_int::ug1z_27{};
double powerdc_int::ug2z_27{};
double powerdc_int::ug3z_27{};
double powerdc_int::ug4z_27{};
double powerdc_int::ugvsuz_27{};
double powerdc_int::ugP_27[5][3]{};
bool powerdc_int::purglk1{};
bool powerdc_int::purglk2{};
bool powerdc_int::purglk3{};
bool powerdc_int::purglk4{};
bool powerdc_int::purglk5{};
bool powerdc_int::purglk6{};
bool powerdc_int::purglk7{};
bool powerdc_int::purglk8{};
bool powerdc_int::purglk9{};
bool powerdc_int::purgpk1{};
bool powerdc_int::purgpk2{};
bool powerdc_int::purgpk3{};
bool powerdc_int::purgpk4{};
bool powerdc_int::purgpk5{};
bool powerdc_int::purgpk6{};
bool powerdc_int::purgpk7{};
bool powerdc_int::purgpk8{};
bool powerdc_int::purgpk9{};
bool powerdc_int::s14_2420{};
bool powerdc_int::prgen[5]{};
bool powerdc_int::pp400[2]{};
bool powerdc_int::purgk31{};
bool powerdc_int::purgk41{};
bool powerdc_int::pss400{};
bool powerdc_int::purgk1{};
bool powerdc_int::purgk21{};
double powerdc_int::ingvsu{};
double powerdc_int::ingrap{};
double powerdc_int::ing1{};
double powerdc_int::ing2{};
double powerdc_int::ing3{};
double powerdc_int::ing4{};
double powerdc_int::upr{};
bool powerdc_int::pvksku[4]{};

allElConsAlt powerdc_int::allElConsAlt_inst;
allElConsDir powerdc_int::allElConsDir_inst;
