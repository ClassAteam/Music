#pragma once
#include "bss.h"
#include "exchange.h"
#include "uks.h"

extern bss bss_inst;
extern uks uks_inst;

class bailout_int
{
public:
    bool
        //input SIO
        s13_10010{},//vilkyuchatel' POKIN' S-T SHTURMAN
        s14_10010{},//vilkyuchatel' POKIN' S-T OPERATOR
        s15_10010{},//vilkyuchatel' BLOKIROVKA POKIDANIYA LEVOGO LETCHIKA
        s12_10020{},//viklyuchatel' kresla levogo letchika(kraynee perednee polozhenie)
        s13_10020{},//viklyuchatel' kresla pravogo letchika(kraynee perednee polozhenie)
        KVZLL{},//priznak konzevogo viklyuchatelya zagolovnika levogo letchika
        KVZPL{},//priznak konzevogo viklyuchatelya zagolovnika pravogo letchika
        KVZSHO{},//priznak konzevogo viklyuchatelya zagolovnika shturmana operatora
        KVZSHN{},//priznak konzevogo viklyuchatelya zagolovnika shturmana navigatora
        KVRKLL{},//priznak konzevogo viklyuchatelya ruchki katapultirovaniya levogo letchika
        KVRKPL{},//priznak konzevogo viklyuchatelya ruchki katapultirovaniya pravogo letchika
        KVRKSHO{},//priznak konzevogo viklyuchatelya ruchki katapultirovaniya shturmana operatora
        KVRKSHN{};//priznak konzevogo viklyuchatelya ruchki katapultirovaniya shturmana navigatora
    bool
        //output SAS

        //output SIO
        H1_10010{},//priznak signala na svetodiod ISPRAVNOST' TSEPEY KRESLA LEV LETCHIKA
        H2_10010{},//priznak signala na svetodiod ISPRAVNOST' TSEPEY KRESLA PRAVOGO LETCHIKA
        H3_10010{},//priznak signala na svetodiod ISPRAVNOST' PIROPATRONI ISPRAVNI LEV LETCH
        H4_10010{},//priznak signala na svetodiod ISPRAVNOST' PIROPATRONI ISPRAVNI PRAV LETCH
        H8_10010{},//priznak signala na svetodiod ISPRAVNOST' TSEPEY KRESLA OPER
        H9_10010{},//priznak signala na svetodiod ISPRAVNOST' TSEPEY KRESLA SHTURM
        H10_10010{},//priznak signala na svetodiod PIROPATRONI ISPRAVNI KRESLA SHTURMANA
        H11_10010{},//priznak signala na svetodiod PIROPATRONI ISPRAVNI KRESLA OPER
        PSPKLL{},//priznak signala peremesheniya kresla levogo letchika(vpered-nazad)
        PSPKPL{},//priznak signala peremesheniya kresla pravogo letchika(vpered-nazad)
        PSRKVLL{},//priznak signala pregulirovaniya kresla levogo letchika po visote
        PSRKVPL{},//priznak signala pregulirovaniya kresla pravogo letchika po visote
        PSRKVSHO{},//priznak signala pregulirovaniya kresla shturmana operatora po visote
        PSRKVSHN{};//priznak signala pregulirovaniya kresla shturmana navigatora po visote

    bool
        PRM1{},//priznak katapultirovaniya s rabochego mesta levogo letchika
        PRM2{},//priznak katapultirovaniya s rabochego mesta pravogo letchika
        PRM3{},//priznak katapultirovaniya s rabochego mesta shturmana operatora
        PRM4{},//priznak katapultirovaniya s rabochego mesta shturmana navigatora
        PPRM1{},//priznak pokidaniya rabochego mesta levogo letchika
        PPRM2{},//priznak pokidaniya rabochego mesta pravogo letchika
        PPRM3{},//priznak pokidaniya rabochego mesta shturmana operatora
        PPRM4{},//priznak pokidaniya rabochego mesta shturmana navigatora
        s9_10010{},//knopka KONTROL' (ispravnost' piropatronov)
        s10_10010{},//knopka KONTROL' (ispravnost' tespey kresla)
        s18_2930{};//knopka PROVERKA (na shitke nazemnoy podgotovki levom)
    double
        throw_tick{};


    virtual void updateLogic();
    void bailout_1_2();
};
