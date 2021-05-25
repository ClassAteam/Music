//expected signals from ISU

struct SH_ISU
{
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
    bool wrapsign{};// sign of landing wheels wrapping

};
