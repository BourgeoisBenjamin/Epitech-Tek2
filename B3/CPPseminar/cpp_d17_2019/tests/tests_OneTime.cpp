/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(OneTime, test00, .init=redirect_all_std)
{
    Cesar c;
    OneTime o("DedeATraversLesBrumes");
    OneTime t("TheCakeIsALie");
    encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
    decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !");
    encryptString(c, "KIKOO");
    encryptString(c, "LULZ XD");
    decryptString(c, "Ziqivun ea Ndcsg.Wji !");
    encryptString(t, "Prend garde Lion, ne te trompes pas de voie !");
    encryptString(o, "De la musique et du bruit !");
    encryptString(t, "Kion li faras? Li studas kaj programas!");
    decryptString(t, "Iyipd kijdp Pbvr, xi le bvhttgs tik om ovmg !");
    decryptString(o, "Gi pa dunmhmp wu xg tuylx !");
    decryptString(t, "Dpsp vm xaciw? Pk cxcvad otq rrykzsmla!");
    cr_assert_stdout_eq_str("Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !\n"
                            "Je clair Luc, ne pas ? Ze woudrai un kekos !\n"
                            "NMPUV\n"
                            "OYQF FM\n"
                            "Welcome to Zombo.Com !\n"
                            "Iyipd kijdp Pbvr, xi le bvhttgs tik om ovmg !\n"
                            "Gi pa dunmhmp wu xg tuylx !\n"
                            "Dpsp vm xaciw? Pk cxcvad otq rrykzsmla!\n"
                            "Prend garde Lion, ne te trompes pas de voie !\n"
                            "De la musique et du bruit !\n"
                            "Kion li faras? Li studas kaj programas!\n");
}
