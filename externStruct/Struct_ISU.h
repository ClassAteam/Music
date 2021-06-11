//expected signals from ISU

struct SH_ISU
{
    //ISU
    //1st engine rotate frequency
    double nvd1{};
    //2st engine rotate frequency
    double nvd2{};
    //3st engine rotate frequency
    double nvd3{};
    //4st engine rotate frequency
    double nvd4{};
    //VSU's rotate frequency
    double nvdVsu{};
    //air presure from additional power plug
    double Pvvsu{};
    //eng1 work clue
    bool ezr1_34{};
    //eng2 work clue
    bool ezr2_34{};
    //eng3 work clue
    bool ezr3_34{};
    //eng4 work clue
    bool ezr4_34{};
    //eng1 work clue
    bool prd1dv{};
    //eng2 work clue
    bool prd2dv{};
    //eng3 work clue
    bool prd3dv{};
    //eng4 work clue
    bool prd4dv{};
    // sign of landing wheels wrapping (should be changed for Sl i Sp)
    bool wrapsign{};
    //skorost' peremesheniya klina vozduhozabornika dvigatelya #1
    double dqkldv1{};
    //skorost' peremesheniya klina vozduhozabornika dvigatelya #2
    double dqkldv2{};
    //skorost' peremesheniya klina vozduhozabornika dvigatelya #3
    double dqkldv3{};
    //skorost' peremesheniya klina vozduhozabornika dvigatelya #4
    double dqkldv4{};
    //skorost' peremesheniya stvorok perepuska vozduha dvigatelya #1
    double dfistv1{};
    //skorost' peremesheniya stvorok perepuska vozduha dvigatelya #2
    double dfistv2{};
    //skorost' peremesheniya stvorok perepuska vozduha dvigatelya #3
    double dfistv3{};
    //skorost' peremesheniya stvorok perepuska vozduha dvigatelya #4
    double dfistv4{};

    //SUR
    //keel speed
    double ddelta_k{};
    //skorost' peremesheniya interzeptora levih
    double ddelta_int_l{};
    //skorost' peremesheniya interzeptora pravogo
    double ddelta_int_p{};
    //skorost' peremesheniya flaperonov levih
    double ddelta_fl_l{};
    //skorost' peremesheniya flaperonov pravih
    double ddelta_fl_p{};
    //skorost' peremesheniya stabilizatora
    double ddelta_fi_st{};
    //priznak signala polnogo zakritiya stvorok gruzovih otsekov
    bool PBI4M_1{};

    //priznak signala stop-kran otkrit 1 dvigatelya
    bool X1_45_7620{};
    //priznak signala stop-kran otkrit 2 dvigatelya
    bool X2_45_7620{};
    //priznak signala stop-kran otkrit 3 dvigatelya
    bool X3_45_7620{};
    //priznak signala stop-kran otkrit 4 dvigatelya
    bool X4_45_7620{};

    //IDP
    double vkx{};//skorost' dvizheniya po VPP(putevaya skorost'), m/s


};
