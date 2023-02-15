#include "Map.h"


sf::String Floor[]{
  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOASSDOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
  "OqwwwweO   OqwwwwwwwwwwwwwwwwwwwwwwwwwwwwwweZXXCqwwwwwwwwwwwwwwwwwwwwweO     OqwwwwwwwwwwwwwweO  OqwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwweO",
  "OaIsPsdOOOOOaJssIsLUIssPryKsuiiiiiiKLsUs;IsP[ss[Ps;[UsJIs[P;PsrxyKUsKsdO     OasUIsss[PssIsssdO  OasUIsIsPsss[sPsUsssIsP[sUIsPuiiiiiiiiiiosIsUs[ssIss[sdO",
  "OasIsP[ssPsJasUsPs[ssP[svnui3kkkkkklssUIssI[sPsPss[sUIPs[sPsMsvwnssUIPdO     OasIsPrxxxxysPUsdO  OasIUsryssP[UsrxxxxxxxxyKsUssjkkkkkkkkkklsPUsssIsU[s[sdO",
  "OaJKL;dOOOOOzxxxxxxxxysIsu3kkkk7,,,.ssrxxxxyQWWErxxxxxxxxxy?ssIU[PsPsLdO     OasIPsdOOOOasU[sdO  OasU[sdasssssrcOOOOOOOOzys;ssm,,,,,,,,,,.sKssrxysssUI[dO",
  "OaM<>?dO   OOOOOOOOOOaUsu3kkk7,.ssrxxxcOOOOaASSDdOOOOOOOOOasIPIUI[Pss[dOO   OOasU[sdO  OaUss[dO  OaPsIsvnss[PsdOOOOOOOOOOzxxxxxxxxxxxxxyssUPLrcOzy[sUIPdO",
  "OzxxxxcO            Oas[jkk7,.UIsPdOOOOO   aASSDd        Oa<[UssIPs[ssveO   OqnuiosdO  OaU[PsdO  OasUPsuiioPssdOOqwwwweOOOOOOOOOOOOOOOOasI[PJdO OaLUIP;dO",
  "OOOOOOOO            OaPsm,,.sIU[ssdOO      aASSDd        Oa>UIP[sLs[PsKdO   OasjklsdO  OasPPsdO  OassssjkklsssdOOasIPsvweOOOOOOOOOOOOOqn[sPUsdO OasUI[sdO",
  "O                   Oas[rxxxxxxxxxcOO      aASSDd        OasIPssrxy[ssPdO   OaLjklLdO  OasUsIdO  Ozxxysm9klsPsdOOaPPUsssvwwwwwwwwwwwwwnssIP[sdO OzxxxxxcO",
  "O                   OaIUdOOOOOOOOOOO       aASSDd        OaMIPssvwns;IPdO   OasjklsdO  OasU[sdO  OOOOassjkl<ssdOOasUIP[sPssssIsssP[IsssP[s;UsveOOOOOOOOOO",
  "O                   OaPsdO               OOaASSDdOOOOO   OzxxxysIsuiossdO   OaKjkl;dO  Oas[PIdO     OaIsjkls>rcOOzxxxxxxxxxxxxxxxxxxxysIL[P[PsvwwwwwwwweO",
  "O        OOOOOOOOOOOOas[dO     OOOOOOOOOOOOaASSDvwwweO   OOOOOasLsjklssdO   OasjklsdO  OzyLs;dO     Oassjkls?dO OOOOOOOOOOOOOOOOOOOOOassPssPIPsIsP[sJsIdO",
  "O        OqwwwwwwwwwwnssdO   OOOqwwwwwwwwwwnASSDsIsPdOO      OasPsjkls[dOOOOOasm,.rcO  OOasIPdOO    Oassjkl>sdO OqwwwwwwwwwwwwwwwwwwwnsLrxxxxxxysIU[PsKdO",
  "O      OOOasUI[LsssuiiosdO  OOqwnsssP[ssP[ssASRCIsUPveOOOOOO OaKssjklssvwwwwwnsI[sdOO   OasIsveOOOOOOassm,.srcO OasUIsPss[sUsPsUsI[ssIs;dOOOOOOasUPssI[dO",
  "O      OqwnsIPsPs;u3kklsdO  OqnssIssPss[KssQNSDssPsssvwwwweOOOasJsjkls;sUI[sIssIPsdO    OasUIPvwwwwwwnsPsIsrcO  Oas[sLPUs;IsPsIs[sLsU[LsdO    OaIUP[ssPdO",
  "O      OassLP;s[Lu3k7,.sdO  Oass[sPss[sUILsASSDJsUsPKPss;LdOOOasssm,.sIUPsKsP[sIUsdO    OasIUsPssP[ssIsPssrcO   OaIsPKsrxxxxxysIPsuiiosKdOOOOOOasP[s;UsdO",
  "O      OaULsIJssu3k7.sPsdO  Oas?P[sIsKssP[sASSDL[s;LL[UsssdOOOzxxxxxxxxxxxxxxxxxxxcO    OzxxxxxxxysrxysssrcO    OaIUsPsdOOOOOasP[u3kklssvwwwwwwnrxxxxxxcO",
  "O      OassPssPsjkklsPMsdO  OassP>ssIU[LsssZXXCssPP[sPsI;sveOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOzxcOzxxxcO    OqnsUIPsdO   Oas[sjkkklssssssssssdOOOOOOOO",
  "OOOOOOOOaIsJsU;sjk7.ss[sdO  OasIs[[PIssUIIPsIssUsIsP[ssIPssdOOOOOOOOOOOOOOOOOOOOOOOOOOOOewwwwwweOOOOOOOOOOOOOOOqnUPssP[dO  OOasPsjkkk1iiiiiiiiiivwwwwwweO",
  "OqwwwwwwnsssLs[sjklssIPsdO  Oas>IssPsKs;sMsQWWEssKsL;sP[s[szwwwwwwwwwwwwwwwwwwwwwwwwwwwwnsLLs>svwwwwwwwwwws;ssqnsUsP[ssveOOOqnsIsjkkkkkkkkkkkkkkkkkkkksdO",
  "OaMUIsKP[L[P;PssjklsUsKsdOOOOasMsP[[PsIU<ssASSDsrxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxyssIsP[sIsssdOOOOzxysU[sPPsvwwwnsUssjkkkkkk7,,,,,,,rxxxxxxcO",
  "iiiiiiiiiiiiiiii3klsPsMsdssssasUIsssUI[UL[sASSDsdOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOzxxxxxxxxxxxcO   OOzy;sLuiioKsUsP[ssm,,,,,,.sPsIss[dOOOOOOOO",
  "kkkkkkkkkkkkkkkkkklsLUssdOOOOassIsI[PIUs<>?ASSDrcOOOOOOOOO                                  OOOOOOOOOOOOOOO     Oassu3kklsKsUIs[sPIUssIsP[ssIUssdOOOOOOOO",
  ",,,,,,,,,,,,,,,,9klKKIJKdO  OasIPP[sss[KsPsASSDdOO         OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO                O    OanUsjkk7.sssrxxxxxxxxxxxxxxxxxxxcO     OO",
  "Ozxxxxxxysss>s>sjkl;Ps[sdO  OasI[sUssIs[MsQNSSDd  OOOOOOOOOOqwwwwwwwwwwwwwwwwwwwwwwwwwwweOOOOOOOOOOOOOOO  O    OaLPsjk7.s;srcOOOOOOOOOOOOOOOOOOOOO     OO",
  "OOOOOOOOzxxxxxysjk1ioMs>dO  OasIsrxxyssP<sASSSDd  OqwwwwwwwwnsssssUsIIss[sPsssIss[sUs[ssvwwwwwwwwwwwwweO  O    Oa[su3klssLsdO                          OO",
  "O      OOOOOOOasjkkk1oPsdO  OasP[dOOasUIPsASSSDd  OaUsss[Ps;sKsuiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiosdO  O    OaPPjkklssIsdOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
  "O            Oasm,9kklIsdO  OassPdeqasUIssASSSDd  OasIsPLsLuiii3kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk1odO  O    OasIjkklsPssvwwwwwwwwwwwwwwwwwwwwwwwwwweOO",
  "O OOOOOO     OaUssm9kl;[dO  Oay>ssvnsI[Ps>ASSSDd  Oa;[s[KIsjkkkkk7,,,,,,,,,,,,,,9kk7,,,,,,rxxxxxxy,9kldO  OOOOOOaUsjk7.s[JssUPssKsILs[sP;sUsIs;srxyLsKdOO",
  "O OqwweO     OaIsPu3k1oLdO  OOzxxxxxxxxxxyASSSDd  OasPKPKUsjk7,,,.sssUIPsssPssssjkklsUIs[PdOOOOOOaJjkldO       OaLUm,.ssIsrxxxxxxxxxxxxxxxxxxxxxcOauiodOO",
  "O OassdOOOOOOOasPsjkkklKdOOO OOOOOOOOOOOOaASSSDd  OaIsUssPu3klsKsLsPsryss[s[sPssjk7.sPsIsIdO    OasjkldO       OaPKsUIs[PrcOOOOOOOOOOOOOOOOOOOOOOOajkldOO",
  "O OassvesIPsssa[Psm9kklLvweO             aASSSDd  OasI[Psu3kklsJsPsLrczy;sIKsPsu3klsKsP[[sdO    OasjkldO       OasP[sssrxcO                   OqwwnjkldOO",
  "O OzxxxcOOOOOOasIssm9klsIsdO        OOO  aASSSDd  OaILP[sjkk7.;sIP[sdOOassUPUsu3kklssIssPsdO    OaKjkldO       Oas[ssIrcOOOOOOOOOOOOOOOOOOOOOOOassu3kldOO",
  "O OOOOOOO    OzxxxyUjk1oPsdO        OsO  aASSRC   OasUsPKjk7.sL[PssKveqns[sPssjkk7.sIIPs[sdO    OasjkldO       OzxxxxxcOO Oqwwwwwwwwwwwwwwwwwwwnui3kkldOO",
  "O            OOOOOzyjkkl;LdO        OsO  aASSD   OOas[Isu3klsUIPsKPIsvnss[s;su3kklsKUI;UPsdO    OaKjkldO       OOOOOOOOO  OaUIsP[LILuiiiiiiiiiii3kkk7.dOO",
  "O                OOam9klIsdOOOOOOOOOOsOOOaASSDOOOOqnPssu3kk1iiosP[ssIPsIsLsui3kkklssPLIssPdO    OaLjkldO       O          OasUIPsuii3kkkkkkkkkkkkk7,.sdOO",
  "O                 OasjklsPvwwwwwwwwwwwwwwnASSDqwwwnssui3kkkkkk1iiiiiiiiiiii3kkk7,ss[sPPUsrcO    OasjkldOOOOOOOOOOOOOOOOOOOOasKsLu3kkkkk7,,,,,,,,,,.s[[dOO",
  "O        OOOOOOOOOOa>jk1iiiiiiiiiiiiiii1ssZXXCsIsuiii3kkk7,9kkkkkkkkkkkkkkkkkkklsJPsKUILsdOO    Oa;jk1vwwwwwwwwwwwwwwwwwwwwniiii3kk7,,,.s;sJUsP[UIsIP;dOO",
  "O        OqwwwwwwwwnsjkkkkkkkkkkkkkkkkklssI[PsU[sjkkkkk7,.sm,,,,,,,,,,,,,,,,,,,.ssI[sPs[sdO     Oasjkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk7.ssUsIsP[sIP[sIU;UsdOO",
  "O        OzxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxyQWWErxxm,,,,,.xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxcO     OzxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxcOO",
  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOaASSDdOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
};
int lengthFloor = sizeof(Floor) / sizeof(Floor[0]);

sf::String mapOne[]{
  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
  "O      O   O                                OOOO                       O     O                O  O                                                      O",
  "O      OOOOO            OO                                    OOO      O     O                O  O                                                      O",
  "O                       OO                                    OOO65    O     O                O  O     OO                                               O",
  "O      OOOOO                                OOOO                       O     O      OOOO      O  O     OO       OOOOOOOO                                O",
  "O      O   OOOOOOOOOO                  OOOOOOOOOOOOOOOOOOO             OO   OO      O  O      O  O     OO      OOOOOOOOOO                      O        O",
  "O      O            O              OOOOO                 O              O   O       O  O      O  O             OO      OOOOOOOOOOOOOOOO       O O       O",
  "OOOOOOOO            O              OO                    O              O   O       O  O      O  O             OO        OOOOOOOOOOOOO        O O       O",
  "O                   O              OO                    O      OOO     O   O       O  O      O  O             OO                             O O       O",
  "O                   O    OOOOOOOOOOO                     O      OOO     O   O       O  O      O  OOOO          OO                              OOOOOOOOOO",
  "O                   O    O               OOOOOOOOOOOOO   O              O   O       O  O      O     O          OO                                       O",
  "O        OOOOOOOOOOOO    O     OOOOOOOOOOOO OOOO     O   OOOOO          O   O       O  O      O     O         O OOOOOOOOOOOOOOOOOOOOO                   O",
  "O        O               O   OOO            OOOO     OO      O          OOOOO       O  OO     OO    O         O O                                       O",
  "O      OOO               O  OO              OOOO      OOOOOO O                     OO   O      OOOOOO         O O                        OOOOOO         O",
  "O      O                 O  O              OOOO            OOO                     O    O                    O  O                        O    O         O",
  "O      O                 O  O              OOOO            OOO                     O    O                   O   O                        OOOOOO         O",
  "O      O                 O  O              OOOO            OOO                     O    O                  O    O       OOOOO                           O",
  "O      O                 O  O              OOOO             OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO   O     O    O        O   O                    OOOOOOOO",
  "OOOOOOOO                 O  O                               OOOOOOOOOOOOOOOOOOOOOOOOOOOO        OOOOOOOOOOOOOOO         O  OO                        NNNO",
  "O                        O  O              OOOO                                                                          OOO                         NNNO",
  "O       N                OOOO              OOOO                                                           OOOO                                       NNNO",
  "O       N                                  OOOO  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO             O   OO                                 OOOOOOOO",
  "O       N                OOOO              OOOO  OOOOOOOOO                                  OOOOOOOOOOOOOOO     O                                OOOOOOOO",
  "O       N                O  O              OOOOOOO         OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO                O    O                                 O      O",
  "O                        O  O             OOOOO   OOOOOOOOOO                             OOOOOOOOOOOOOOO  O    O             OOOOOOOOOOOOOOOOOOOOO      O",
  "OOOOOOOO                 O  O    OOOO     OOOOO   O                                                    O  O    O            O                           O",
  "O      OOOOOOO           O  O    OOOO     OOOOO   O                                                    O  O    O            OOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
  "O            O           O  O    OOOO     OOOOO   O                                                    O  O    O                                        O",
  "O OOOOOO     O           O  O     OO      OOOOO   O                                                    O  OOOOOO                                        O",
  "O O    O     O           O  OO            OOOOO   O                                        OOOOOO      O       O                                 O      O",
  "O O    OOOOOOO           OOO OOOOOOOOOOOOOOOOO    O                  OO                    O    O      O       O           OOOOOOOOOOOOOOOOOOOOOOO      O",
  "O O                        O                      O                 OOOO                   O    O      O       O          O                   O         O",
  "O O     OOOOOO             O        OOO           O                 OOOO                   O    O      O       O        OOOOOOOOOOOOOOOOOOOOOOO         O",
  "O OOOOOOO    O             O        O O           O                 OOOO                   O    O      O       O       OO O                             O",
  "O            OOOOO         O        O O          OO                  OO                    O    O      O       OOOOOOOOO  O                             O",
  "O                OO        OOOOOOOOOO OOOOOOOOOOOO                                         O    O      O       O          O                             O",
  "O                 O                       OOOO                                             O    O      OOOOOOOOOOOOOOOOOOOO                             O",
  "O        OOOOOOOOOO                       OOOO                                            OO    O                                                       O",
  "O        O                                                                                O     O                                                       O",
  "O        O                                OOOO                                            O     O                                                       O",
  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
};

int lengthMOne = sizeof(mapOne) / sizeof(mapOne[0]);

sf::String TopLayer[]{
  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOsOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
  "O      rv nO                                OOOO                       we  s O                O eO                                                      O",
  "O      OOOOO            vO                                    bOt      Odw der                Oqxe                                                      O",
  "O                       OO                                    OOy      wswa ey                q wO     rt                                               O",
  "O      aOOdO                                OOOO                       e s wwf      OOOO      wcxO     mO       OxOzOxOO                                O",
  "O      Oas aOOOssOsOO                  OrOyOOOOOuOOyOrOtOg             qOwe wh      Odww      Oqze     OO      OzOwcOeeOq                      O        O",
  "O      O dd d a d d a              OsOOOdws     d q s dd j              sqasO       OswO      ecxO             wO      OqzOxOcOOOcOOzOe       OcO       O",
  "sOOOOOOO  d  s s s dO              OO s dw a     aedwa s y              a q h       qdwe      e wq             xw       qqzOxOOxqxwxcO        zxz       O",
  "Oad  d s d d sd a saO              Oa w aesd     s awaea f      nOu     Owdey       wwsO      OwxO             cO                             cxc       O",
  "Oa ss d s d s a ss ds    OyOuOaOrOyOwdw d s     d q q ewsr      OOt     w swr       Oawe      qw eceO          qx                              zzOOxOcOzc",
  "s as da s d add da dO    O a  d adaqsa d OsOOOOOOsOOsOd aO              wdwdy       Odww      q w xwO          xc                                       O",
  "O a s sa OOdOsOOasOas    O s adOdOOaOsedOOa OOOO     awwedOOOw          Osdwq       ewwO      OwqewwO         OxOxOOeOcOqOzOqOxeOcwOz                   O",
  "a as s dsO               O  sOas            OOOO     Osq aes e          aeOsO       swwOO     Oz xexO         cxO                                       O",
  "sd sds aOa               Od OO              OOOO      OsOwOwaO                     OqqwwO      OqecOq         wxe                        rOyOuO         O",
  "O as s O                 O  O              OOOO            OwO                     awdwsO                    xw z                        xcxcxz         O",
  "s d s da                 Od O              OOOO            sdO                     Owe wq                   O ewx                        cczczc         O",
  "O sa sdf                 O aO              OOOO            qaO                     Oqqwew                  Owcczq       OOOOO                           O",
  "Oa ssadh                 Od O              OOOO             wOdOeOOsOOwOOwOeOqOwOsOOqOwdOwOewOtyy   u     tzx xe        zxxzc                    xOzOzOxc",
  "OOaddOaj                 ts a                               aOwaOswdOqaesOaedwsOOeOwdOwe     qx uxqryctryuyxwOw         xzxxc                           O",
  "O                        u aO              OOOO                                                                          cxc                            O",
  "O                        sOdO              OOOO                                                           ryur                                          O",
  "O                                          OOOO  OOOrOyOOuOrOtOyOuOOrOyOuOOaOOrOfhOOjryOrOtyu             fxcxOO                                 yOurOyOO",
  "O                        sOaO              OOOO  OsqweaOaOdwaew qse ws wsswddqadedwq esswdadOOOOxwcOOzOxhjOzx zxO                                rOOOOzOO",
  "O                        sd s              OOOOOOs w dwded srahwdedqreyssuddayersudwsdtysOqdweazsdwsesax cO xc f                                 Oc zzz c",
  "O                        Osdd             OOOOOdesOeetyajsaw                             OwOqwOOdOaxsOzdxwx c xO             OryOuOyOrOtOOhfOhOjOOxczcx O",
  "OOgOhOjO                 sadO    vOyu     OOOOOswsd                                                    Owwwc z h            Ozzzxz x cc zxzz ccx cc x czO",
  "Os ass OfOhOgO           OasO    OOmO     OOOOOassO                                                    e xOz xcO            OxcOxcOOxcxOxOOcOOzOzOxOcOzxO",
  "s aa a a s ddr           sddO    rnOO     OOOOOesqd                                                    wwweqqxxj                                        O",
  "OadOOOOO aa au           addO     OO      OOOOOdqsa                                                    uq OOOcOO                                        O",
  "d O    Oa a dt           hdssd            OOOOOwswd                                        yuOOrO      Oq q wqwr                                nO      O",
  "aad    OOOOsas           hddsOOOOOOOOOOOOOOOOOdqdqO                  OO                    ye ecO      e q zce y           OyOuOrOyOOuOOtyOfhOOOxO      O",
  "O O                        ad s s  d ae w      awae                 OexO                   w w aO      w xqecwqO          ucx c zc  z cc zccczz         O",
  "OsO     OOdgsh             Osad asdseOOdw      ssaO                 qexO                   weqexe      Oqw wcq u        txcxczOxOxzOccOzczzxOxz         O",
  "aaOaOOOOOs a a             has d dwsO s d     ae ww                 xwqc                   fds we      Oceqwz eO       uOcO                             O",
  "Oa dda s s dsOhOyO         fadsdd a q Os d    d qOO                  zw                    hwqeqe      O zq e xcOuOOtwqOc z                             O",
  "Os ad d sad s s aau        aaOdOOOdOa OasOOOOOawOs                                         weww w      qwe eezqezxwec zqxxO                             O",
  "O ss as a d ss sd s                       OOOO                                             je zqw      OOzwwexOcOeOOOqOOwcx                             O",
  "aa ad ssssOOdOdOOah                       OOOO                                            gewesqO                                                       O",
  "O dd s ddO                                                                                wwasw q                                                       O",
  "Od aa a ss                                OOOO                                            jes qwO                                                       O",
  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
};
int lengthTL = sizeof(TopLayer) / sizeof(TopLayer[0]);

sf::String mapTwo[]{
  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                O                                                 O",
  "OOOOO                                            O                                                 O",
  "O   O                                                                                              O",
  "O   O                                              O                                               O",
  "O   O                                                                                              O",
  "O   O                                                                                              O",
  "O   OOO                                                                                            O",
  "O     O                                                                                            O",
  "O     O                                                                                            O",
  "OOOOOOO          O                                                                                 O",
  "OP       N       O                                                                                 O",
  "OP       N       O                                                                                 O",
  "OP       N                                                                                   O     O",
  "OOOOOOO                                                                                            O",
  "O     O                                                                                            O",
  "O     O                                                                                            O",
  "O     O                                                                                            O",
  "O OOOOO                                                                                            O",
  "O O                                                                                                O",
  "O O                                                            O                                   O",
  "OOO                                                                                                O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                     OOO                                                          O",
  "O                                     OOO                                                      OO  O",
  "O                                      O                                                       OO  O",
  "O                                                                           OOO                OO OO",
  "O                                          O                                OOO                   OO",
  "O                                                                            O               OOOOOOO",
  "O                                                                                            O     O",
  "O                                                                                            O     O",
  "O                                                                                            OOOOOOO",
  "O                                                                                                NNO",
  "O                                                                                                NNO",
  "O                                                                                                NNO",
  "O                                                                                            OOOOOOO",
  "O                                                                                            O     O",
  "O                                                                         O                  O     O",
  "O             O                                                                              O     O",
  "O                                                                                            O     O",
  "O                                                                                            O     O",
  "O                                                                                            OOOO  O",
  "O                                                                                               O  O",
  "O                                                                                               OOOO",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                  O                               O",
  "O                                   O                                                              O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                           O      O",
  "O                   OOO                                                                            O",
  "O    O              OOO                                                                            O",
  "O    O               O                               OOO                                           O",
  "O                                                    OOO                                           O",
  "O                                          OOO OOO    O                                            O",
  "O                                          OOO OOO     OOO                                         O",
  "O                                           O   O      OOO                                         O",
  "O                                                 OOOOO O                                          O",
  "O                                               OOOOOOO                                            O",
  "O                                               OOOOOOO    OOO                                     O",
  "O                                         OOO    OOOOOO    OOO                                     O",
  "O                                         OOO    OOOOOO     O                                      O",
  "O                                          O      OOO                                              O",
  "O             O                                                                                    O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O           OOO                                                                                    O",
  "O           OOO                                                                                    O",
  "O            O                                                                                     O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                            O                     O",
  "O                                                                                                  O",
  "O                                                                                  OOO             O",
  "O                                                                                  OOO             O",
  "O                                                                                   O              O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
};
int lengthMTwo = sizeof(mapTwo) / sizeof(mapTwo[0]);

sf::String mapThree[]{
  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
  "OO                                                                                       OOOOOOO   O",
  "O O                                                                                     OO     O   O",
  "O  OOOOO                                  OOOOOOOOOOOOOOOOOOO         OOOOOOOOOOOOOOOOOOO      O   O",
  "O  OPPPOOO   OOOOO                     OOOOO            OOOOOO        O                        O   O",
  "O  O     OOOOO  OO                  OOOOO                    O        O                        O   O",
  "O  O             OOOOOOOOOOOOOOOOOOOOO                       O        O                        O   O",
  "O  O              O                                          OOOOOOOOOO                        O   O",
  "O  O                                                                                           O   O",
  "O  O                                                                    OOOOOOOOOOOOOOO        O   O",
  "O  O                                                                   O              O        O   O",
  "O  OO            OOOOOOOOOOOOOOO                OOOO                  O               O        O   O",
  "O   OO          O              OO               OOOO                 O               O         O   O",
  "O     O        O                OO              OOOO                 O               O         O   O",
  "O      OOOOOOOOO                 O              OOOO                 O              O          O   O",
  "O                                O                                   O             O           O   O",
  "O                                O                                   O       OOOOOO            O   O",
  "O                                 O                                  O      OO                 O   O",
  "O                                  O                                 O      O                  O   O",
  "O                                   O                                O      O                  O   O",
  "O                                    O                              O       O                  O   O",
  "O            OOOOOOOOOOOOOO           O                            O        O                  O   O",
  "O            O            O            O                          O         O                  O   O",
  "O           O              O            OOOOOOOOO          OOOOOOO          O                  O   O",
  "O          O               OO                   O          O                O                  O   O",
  "O         O                 O                   OOOOOOOOOOOO                O                  O   O",
  "O        O                  O                   OOOOOOOOOOOO                O                  O   O",
  "O       O                   O                   O          O             OOOO                  O   O",
  "O      O                     O                 O           O            OO         OOOOO       O   O",
  "O     O                       O               O            O            O          OOOOO       O   O",
  "O    O          O              O             O             O            O          OOOOO       O   O",
  "O   O          OOO              O            O             O            O          OOOOO       O   O",
  "O   O         OOOOO              O           O            O             O          OOOOO       O   O",
  "O   O        OOOOOOO              OOOOOO     O           O              O                      O   O",
  "O   O         OOOOO                    OO    O           O     OOOOOOOOO                       O   O",
  "O   O          OOO                      O    O           O    O                               O    O",
  "O   O           O                       O    O            OOOO                                O    O",
  "O   O                                   OOOOOO                                                O    O",
  "O   O                                                                                         O    O",
  "O   O                                                                                         O    O",
  "O   OO                      OOOOOOOOOO                            OO                          O    O",
  "O     O                    O          O                          O O            OOOO          O    O",
  "O      O                  O           OOOOOO             OOOOOOOO  O            OOOO          O    O",
  "O       O                O                 O             O         O            OOOO          O    O",
  "O        O              O                  O             O        O             OOOO          O    O",
  "O         O            O                   O             O        O                          O     O",
  "O          O          O                    O             O        O                         O      O",
  "O           O        O                     O             O        O                        O       O",
  "O           O       O                      O            OO        O                       O        O",
  "O           O      O                       O           O           O                     O         O",
  "O           O      O                       O          O             O                   O          O",
  "O           O      O                       OOOOOOOOOOO               OOOOOOOOOOOOOOOOOOOO          O",
  "O           O      O                       OOOOOOOOOOO                                             O",
  "O           O      O                       O         O                                             O",
  "O          O       O OOOOOOOOOOOOOOOOOOOOOOO         OOOOOOOO                                      O",
  "O         O        OOO                                O     O                                      O",
  "O        O                                                   O                                     O",
  "O       O                                                     O                                    O",
  "O      O                                                       OOOOOOOOOOOOOOOOOOOOOOOOO           O",
  "O     O                                                                                 O          O",
  "O     O                                                                                  O         O",
  "O     O                                                                                   O        O",
  "O     O     OOOOOOOOOOOOOOOOOOO                                                            O       O",
  "O     O     OOOOOOOOOOOOOOOOOOO                                                             O      O",
  "O     O     OOOOOOOOOOOOOOOOOOO                                                              O     O",
  "O     O     OOOOOOOOOOOOOOOOOOO                                                               O    O",
  "O     O     OOOOOOOOOOOOOOOOOOO                                                                O   O",
  "O     O                                                                                        O   O",
  "O     O                                                                                        O   O",
  "O     O                                                                                        O   O",
  "O     O                                                                                        O   O",
  "O     O                                                                                        O   O",
  "O     O                                                                                        O   O",
  "O     OO                               OOOO        OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       O   O",
  "O       O                             O   O        O                                   OO      O   O",
  "O        O                           O    O        O                                    O      O   O",
  "O         O                         O     O        O                                    O      O   O",
  "O          O                       O      O        O                                    O      O   O",
  "O           OOOOOOOOOOOOOOOOOOOOOOOO      O        O                                    O      O   O",
  "O                                         O        O                                    O      O   O",
  "O                                         O        O          OOOOOOOOOOOOOOOOOOOOOOO   O      O   O",
  "O                                         O        O          O                     OOOOO      O   O",
  "O                                         O        O         O                                 O   O",
  "O    OOOOOOOOOOOO                         O        O        O                                  O   O",
  "O    O          OO                        O       O        O                                   O   O",
  "O    O           OO                       OOOOOOOOO        O                                   O   O",
  "O    O            OO                                       O                                   O   O",
  "O    O             OO                                      O                                   O   O",
  "O    O              OO                                     O                                   O   O",
  "O    O               OO                                   O                                    O   O",
  "O    O                 OOOOOOOOOOOOOOO                   O                                     O   O",
  "O    O                                OOO               O                                      O   O",
  "O    O                                  OOOOOOOOOOOOOOOO                                     OO    O",
  "O    OO                                                         OOOOOOOOOOOOOOOOOOOOOOOOOOOOO      O",
  "O     OOOOOOOOOOOOOOOOOOOOOOOOOOOO                         OOOOOO                                  O",
  "O                                O                        OO                                       O",
  "O                                OOOOOOOOOOOOOOOOOOOOOOOOOOO                                       O",
  "O                                                                                                  O",
  "O                                                                                                  O",
  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
};

int lengthMThree = sizeof(mapThree) / sizeof(mapThree[0]);

// -------------------------------------------------------------------------------------------------------------------//

BaseTile::BaseTile() :CurrentChar(' ') {}

BaseTile::BaseTile(std::string fileName) : CurrentChar(' ') {
  Init(fileName);
}

void BaseTile::Init(std::string fileName) {
  texture.loadFromFile(fileName);
  tileSprite.setTexture(texture);
  //tileSprite.setTextureRect(IntRect(16, 16, 16, 16));
}
void BaseTile::setTilePos(Coord pos) {
  tileSprite.setPosition(pos.x, pos.y);
}
void BaseTile::setTilePos(float x, float y) {
  tileSprite.setPosition(x, y);
}
void BaseTile::SetTileScale(float x, float y) {
  tileSprite.scale(Vector2f(x, y));
}
char BaseTile::GetCh()const { return CurrentChar; }

Sprite& BaseTile::getTilSprite() { return tileSprite; }

bool BaseTile::isNotSame(char ch) {
  if (CurrentChar != ch) {
    CurrentChar = ch;
    return true;
  }
  else return false;
}

inline BaseTile::~BaseTile() {}

#define CHECK if(isNotSame(ch))

ForestTileSet::ForestTileSet() :BaseTile("PixiVan Forest (Beta)\\Ground Tileset.png") {}

ForestTileSet::ForestTileSet(std::string fileName) :BaseTile(fileName) {}

bool ForestTileSet::SetTextureRectByChar(char ch) {
  switch (ch) {
  case'q':CHECK tileSprite.setTextureRect(IntRect(0, 0, 16, 16));   return true;
  case'w':CHECK tileSprite.setTextureRect(IntRect(16, 0, 16, 16));  return true;
  case'e':CHECK tileSprite.setTextureRect(IntRect(32, 0, 16, 16));  return true;
  case'a':CHECK tileSprite.setTextureRect(IntRect(0, 16, 16, 16));  return true;
  case's':CHECK tileSprite.setTextureRect(IntRect(16, 16, 16, 16)); return true;
  case'd':CHECK tileSprite.setTextureRect(IntRect(32, 16, 16, 16)); return true;
  case'z':CHECK tileSprite.setTextureRect(IntRect(0, 32, 16, 16));  return true;
  case'x':CHECK tileSprite.setTextureRect(IntRect(16, 32, 16, 16)); return true;
  case'c':CHECK tileSprite.setTextureRect(IntRect(32, 32, 16, 16)); return true;
  case'r':CHECK tileSprite.setTextureRect(IntRect(0, 80, 16, 16));  return true;
  case't':CHECK tileSprite.setTextureRect(IntRect(16, 80, 16, 16)); return true;
  case'y':CHECK tileSprite.setTextureRect(IntRect(32, 80, 16, 16)); return true;
  case'f':CHECK tileSprite.setTextureRect(IntRect(0, 96, 16, 16));  return true;
  case'g':CHECK tileSprite.setTextureRect(IntRect(16, 96, 16, 16)); return true;
  case'h':CHECK tileSprite.setTextureRect(IntRect(32, 96, 16, 16)); return true;
  case'v':CHECK tileSprite.setTextureRect(IntRect(0, 112, 16, 16)); return true;
  case'b':CHECK tileSprite.setTextureRect(IntRect(16, 112, 16, 16)); return true;
  case'n':CHECK tileSprite.setTextureRect(IntRect(32, 112, 16, 16)); return true;
  case'u':CHECK tileSprite.setTextureRect(IntRect(0, 160, 16, 16)); return true;
  case'i':CHECK tileSprite.setTextureRect(IntRect(16, 160, 16, 16)); return true;
  case'o':CHECK tileSprite.setTextureRect(IntRect(32, 160, 16, 16)); return true;
  case'j':CHECK tileSprite.setTextureRect(IntRect(0, 176, 16, 16)); return true;
  case'k':CHECK tileSprite.setTextureRect(IntRect(16, 176, 16, 16)); return true;
  case'l':CHECK tileSprite.setTextureRect(IntRect(32, 176, 16, 16)); return true;
  case'm':CHECK tileSprite.setTextureRect(IntRect(0, 192, 16, 16)); return true;
  case',':CHECK tileSprite.setTextureRect(IntRect(16, 192, 16, 16)); return true;
  case'.':CHECK tileSprite.setTextureRect(IntRect(32, 192, 16, 16)); return true;
  case'7':CHECK tileSprite.setTextureRect(IntRect(176, 160, 16, 16)); return true;
  case'8':CHECK tileSprite.setTextureRect(IntRect(192, 160, 16, 16)); return true;
  case'9':CHECK tileSprite.setTextureRect(IntRect(208, 160, 16, 16)); return true;
  case'4':CHECK tileSprite.setTextureRect(IntRect(176, 176, 16, 16)); return true;
  case'5':CHECK tileSprite.setTextureRect(IntRect(192, 176, 16, 16)); return true;
  case'6':CHECK tileSprite.setTextureRect(IntRect(208, 176, 16, 16)); return true;
  case'1':CHECK tileSprite.setTextureRect(IntRect(176, 192, 16, 16)); return true;
  case'2':CHECK tileSprite.setTextureRect(IntRect(192, 192, 16, 16)); return true;
  case'3':CHECK tileSprite.setTextureRect(IntRect(208, 192, 16, 16)); return true;
  case' ':
  case'O':
    CHECK tileSprite.setTextureRect(IntRect(16, 96, 16, 16)); return true;
  default:
    return false;
  }
}

LakeTileSet::LakeTileSet() :BaseTile("PixiVan Forest (Beta)\\Water Tileset.png") {};

LakeTileSet::LakeTileSet(std::string FileName) : BaseTile(FileName) {}

bool LakeTileSet::SetTextureRectByChar(char ch) {
  switch (ch)
  {
  case'Q':CHECK tileSprite.setTextureRect(IntRect(0, 0, 16, 16));  return true;
  case'W':CHECK tileSprite.setTextureRect(IntRect(16, 0, 16, 16)); return true;
  case'E':CHECK tileSprite.setTextureRect(IntRect(32, 0, 16, 16)); return true;
  case'A':CHECK tileSprite.setTextureRect(IntRect(0, 16, 16, 16)); return true;
  case'S':CHECK tileSprite.setTextureRect(IntRect(16, 16, 16, 16)); return true;
  case'D':CHECK tileSprite.setTextureRect(IntRect(32, 16, 16, 16)); return true;
  case'Z':CHECK tileSprite.setTextureRect(IntRect(0, 32, 16, 16)); return true;
  case'X':CHECK tileSprite.setTextureRect(IntRect(16, 32, 16, 16)); return true;
  case'C':CHECK tileSprite.setTextureRect(IntRect(32, 32, 16, 16)); return true;
  case'R':CHECK tileSprite.setTextureRect(IntRect(80, 16, 16, 16)); return true;
  case'Y':CHECK tileSprite.setTextureRect(IntRect(96, 16, 16, 16)); return true;
  case'V':CHECK tileSprite.setTextureRect(IntRect(80, 32, 16, 16)); return true;
  case'N':CHECK tileSprite.setTextureRect(IntRect(96, 32, 16, 16)); return true;
  default:
    return false;
    break;
  }
}

GrassTileSet::GrassTileSet() :BaseTile("PixiVan Forest (Beta)\\Animated\\Ambience\\Animated Grass.png") {}

GrassTileSet::GrassTileSet(std::string fileName) : BaseTile(fileName) {}

bool GrassTileSet::SetTextureRectByChar(char ch) {
  switch (ch)
  {
  case'U':CHECK tileSprite.setTextureRect(IntRect(0, 0, 16, 16)); return true;
  case'I':CHECK tileSprite.setTextureRect(IntRect(0, 16, 16, 16)); return true;
  case'[':CHECK tileSprite.setTextureRect(IntRect(0, 32, 16, 16)); return true;
  case'P':CHECK tileSprite.setTextureRect(IntRect(16, 16, 16, 16)); return true;
  case'J':CHECK tileSprite.setTextureRect(IntRect(0, 64, 16, 16)); return true;
  case'K':CHECK tileSprite.setTextureRect(IntRect(16, 64, 16, 16)); return true;
  case'L':CHECK tileSprite.setTextureRect(IntRect(32, 64, 16, 16)); return true;
  case';':CHECK tileSprite.setTextureRect(IntRect(48, 64, 16, 16)); return true;
  case'M':CHECK tileSprite.setTextureRect(IntRect(0, 80, 16, 16)); return true;
  case'<':CHECK tileSprite.setTextureRect(IntRect(16, 80, 16, 16)); return true;
  case'>':CHECK tileSprite.setTextureRect(IntRect(32, 80, 16, 16)); return true;
  case'?':CHECK tileSprite.setTextureRect(IntRect(48, 80, 16, 16)); return true;
  default:
    return false;
    break;
  }
}

TreeTileSet::TreeTileSet() : BaseTile("PixiVan Forest (Beta)\\Trees.png") {}

TreeTileSet::TreeTileSet(std::string fileName) :BaseTile(fileName) {}

bool TreeTileSet::SetTextureRectByChar(char ch) {
  switch (ch)
  {
  case'q':CHECK tileSprite.setTextureRect(IntRect(0, 0, 69, 111)); return true;
  case'w':CHECK tileSprite.setTextureRect(IntRect(69, 0, 69, 111)); return true;
  case'e':CHECK tileSprite.setTextureRect(IntRect(138, 0, 69, 111)); return true;
  case'a':CHECK tileSprite.setTextureRect(IntRect(0, 111, 69, 111)); return true;
  case's':CHECK tileSprite.setTextureRect(IntRect(69, 111, 69, 111)); return true;
  case'd':CHECK tileSprite.setTextureRect(IntRect(138, 111, 69, 111)); return true;
  case'z':CHECK tileSprite.setTextureRect(IntRect(0, 222, 69, 111)); return true;
  case'x':CHECK tileSprite.setTextureRect(IntRect(69, 222, 69, 111)); return true;
  case'c':CHECK tileSprite.setTextureRect(IntRect(138, 222, 69, 111)); return true;
  default:
    return false;
    break;
  }
}

RockTileSet::RockTileSet() : BaseTile("Pixivan Forest (Beta)\\Rocks.png") {}

RockTileSet::RockTileSet(std::string FileName) :BaseTile(FileName) {}

bool RockTileSet::SetTextureRectByChar(char ch) {
  switch (ch)
  {
  case'r': CHECK tileSprite.setTextureRect(IntRect(0, 0, 16, 16)); return true;
  case't': CHECK tileSprite.setTextureRect(IntRect(16, 0, 16, 16)); return true;
  case'y': CHECK tileSprite.setTextureRect(IntRect(32, 0, 16, 16)); return true;
  case'u': CHECK tileSprite.setTextureRect(IntRect(48, 0, 16, 16)); return true;
  case'f': CHECK tileSprite.setTextureRect(IntRect(0, 16, 16, 16)); return true;
  case'g': CHECK tileSprite.setTextureRect(IntRect(16, 16, 16, 16)); return true;
  case'h': CHECK tileSprite.setTextureRect(IntRect(32, 16, 16, 16)); return true;
  case'j': CHECK tileSprite.setTextureRect(IntRect(48, 16, 16, 16)); return true;
  case'v': CHECK tileSprite.setTextureRect(IntRect(0, 32, 32, 32)); return true;
  case'b': CHECK tileSprite.setTextureRect(IntRect(32, 32, 32, 32)); return true;
  case'n': CHECK tileSprite.setTextureRect(IntRect(0, 64, 32, 32)); return true;
  case'm': CHECK tileSprite.setTextureRect(IntRect(32, 64, 32, 32)); return true;
  default:
    return false;
    break;
  }
}

DesertMap::DesertMap() : BaseTile("Assets\\DesertMap.png") {}

DesertMap::DesertMap(std::string FileName) :BaseTile(FileName) {}

bool DesertMap::SetTextureRectByChar(char ch) {
  return false;
}

CaveMap::CaveMap() :BaseTile("Assets\\CaveWithoutLanterns.png") {}

CaveMap::CaveMap(std::string FileName) :BaseTile(FileName) {}

bool CaveMap::SetTextureRectByChar(char ch) {
  return false;
}

//-------------------------------------------------------------------------------------------------------//

Map::Map() :CurrentMapNum(), height(), width() {
  Init();
}

void Map::Init() {
  TileSet.push_back(new ForestTileSet("PixiVan Forest (Beta)\\Ground Tileset.png"));
  TileSet[0]->SetTileScale(2, 2);
  TileSet.push_back(new LakeTileSet());
  TileSet[1]->SetTileScale(2, 2);
  TileSet.push_back(new GrassTileSet());
  TileSet[2]->SetTileScale(2, 2);
  TileSet.push_back(new TreeTileSet());
  TileSet[3]->SetTileScale(1.5f, 1.5f);
  TileSet.push_back(new RockTileSet());
  TileSet[4]->SetTileScale(2, 2);
  TileSet.push_back(new DesertMap());
  TileSet[5]->SetTileScale(2, 2);
  CurrentMap = mapOne;
  height = lengthMOne * 32;
  width = mapOne->getSize() * 32;
  SpownPoint.x = 100;
  SpownPoint.y = 650;
  TileSet.push_back(new CaveMap());
}

int Map::GetCurrentMapNum()const { return CurrentMapNum; }

Coord Map::GetSpownPoint()const { return SpownPoint; }

void Map::SetSpownPoint(Coord pos) { SpownPoint = pos; }

void Map::SetNextMap() {
  extern SoundManager GlobalMusic;
  switch (CurrentMapNum)
  {
  case 0:
    GlobalMusic.StopAllSounds();
    GlobalMusic.theme2.play();
    CurrentMap = mapTwo;
    CurrentMapNum = 1;
    SpownPoint.x = 160;
    SpownPoint.y = 450;
    height = lengthMTwo * 32;
    width = mapTwo->getSize() * 32;
    CurrentMapNum = 1;
    extern float GlobalAnimationSpeed;
    GlobalAnimationSpeed = 0.07f;
    extern float GlobalSpeed;
    GlobalSpeed = 0.4f;
    break;
  case 1:
    GlobalMusic.StopAllSounds();
    GlobalMusic.theme3.play();
    CurrentMap = mapThree;
    height = lengthMTwo * 32;
    width = mapTwo->getSize() * 32;
    CurrentMapNum = 2;
    SpownPoint.x = 160;
    SpownPoint.y = 200;
    break;
  default:
    break;
  }
}

void Map::SetPreviousMap() {
  extern SoundManager GlobalMusic;
  switch (CurrentMapNum)
  {
  case 1:
    GlobalMusic.StopAllSounds();
    GlobalMusic.theme1.play();
    CurrentMap = mapOne;
    CurrentMapNum = 0;
    SpownPoint.y = 570;
    SpownPoint.x = 4500;
    height = lengthMOne * 32;
    width = mapOne->getSize() * 32;
    extern float GlobalAnimationSpeed;
    GlobalAnimationSpeed = 0.08f;
    extern float GlobalSpeed;
    GlobalSpeed = 0.5f;
    break;
  case 2:
    GlobalMusic.StopAllSounds();
    GlobalMusic.theme2.play();
    CurrentMap = mapTwo;
    height = lengthMTwo * 32;
    width = mapTwo->getSize() * 32;
    CurrentMapNum = 1;
    SpownPoint.x = 2912;
    SpownPoint.y = 1280;
    break;
  default:
    break;
  }
}

#define DRAWTILE(index) if (TileSet[index]->SetTextureRectByChar(Floor[i][j])) {TileSet[index]->setTilePos(j * 32, i * 32);window.draw(TileSet[index]->getTilSprite());}

void Map::Draw(RenderWindow& window) {
  switch (CurrentMapNum)
  {
  case 0:
    for (size_t i = 0; i < lengthFloor; i++)
    {
      for (size_t j = 0; j < Floor[i].getSize(); j++)
      {
        DRAWTILE(0)
else DRAWTILE(1)
else DRAWTILE(2)
      }
    }
    break;
  case 1:
    window.draw(TileSet[5]->getTilSprite());
    break;
  case 2:
    window.draw(TileSet[6]->getTilSprite());
  default:
    break;
  }
}

#define DRAWTOPTILE(index, posx, posy) if (TileSet[index]->SetTextureRectByChar(TopLayer[i][j])) {TileSet[index]->setTilePos(posx, posy);window.draw(TileSet[index]->getTilSprite());}

void Map::DrawTopLayer(RenderWindow& window) {
  switch (CurrentMapNum)
  {
  case 0:
    for (size_t i = 0; i < lengthTL; i++)
    {
      for (size_t j = 0; j < TopLayer[i].getSize(); j++)
      {
        DRAWTOPTILE(4, j * 32, i * 32)
else DRAWTOPTILE(3, j * 32 - 39, i * 32 - 94)
      }
    }
  case 1:break;
  case 2:break;
  default:
    break;
  }
}

Box Map::GetSizeOfMap() {
  Box temp(0, 0, height, width);
  return temp;
}

Map::~Map() {
  for (size_t i = 0; i < TileSet.size(); i++)
  {
    delete TileSet[i];
  }
}