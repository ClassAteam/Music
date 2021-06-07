//expected signals from ISU

struct SH_ISU
{
    //ISU
    double nvd1{};//1st engine rotate frequency
    double nvd2{};//2st engine rotate frequency
    double nvd3{};//3st engine rotate frequency
    double nvd4{};//4st engine rotate frequency
    double nvdVsu{};//VSU's rotate frequency
    double Pvvsu{};//air presure from additional power plug
    bool ezr1_34{};//eng1 work clue
    bool ezr2_34{};//eng2 work clue
    bool ezr3_34{};//eng3 work clue
    bool ezr4_34{};//eng4 work clue
    bool prd1dv{};//eng1 work clue
    bool prd2dv{};//eng2 work clue
    bool prd3dv{};//eng3 work clue
    bool prd4dv{};//eng4 work clue
    // sign of landing wheels wrapping (should be changed for Sl i Sp)
    bool wrapsign{};
    double dqkldv1{};//skorost' peremesheniya klina vozduhozabornika dvigatelya #1
    double dqkldv2{};//skorost' peremesheniya klina vozduhozabornika dvigatelya #2
    double dqkldv3{};//skorost' peremesheniya klina vozduhozabornika dvigatelya #3
    double dqkldv4{};//skorost' peremesheniya klina vozduhozabornika dvigatelya #4
    double dfistv1{};//skorost' peremesheniya stvorok perepuska vozduha dvigatelya #1
    double dfistv2{};//skorost' peremesheniya stvorok perepuska vozduha dvigatelya #2
    double dfistv3{};//skorost' peremesheniya stvorok perepuska vozduha dvigatelya #3
    double dfistv4{};//skorost' peremesheniya stvorok perepuska vozduha dvigatelya #4
    //SUR
    double ddelta_k{};//keel speed
    double ddelta_int_l{};//skorost' peremesheniya interzeptora levih
    double ddelta_int_p{};//skorost' peremesheniya interzeptora pravogo
    double ddelta_fl_l{};//skorost' peremesheniya flaperonov levih
    double ddelta_fl_p{};//skorost' peremesheniya flaperonov pravih
    double ddelta_fi_st{};//skorost' peremesheniya stabilizatora
    bool PBI4M_1{};//priznak signala polnogo zakritiya stvorok gruzovih otsekov


};
