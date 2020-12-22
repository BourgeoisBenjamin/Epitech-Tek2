/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(my_cat, test00, .init = redirect_all_std)
{
    const char *argv[] = {"./my_cat", ".fileTU"};
    int argc = 2;
    my_cat(argc, (char**)argv);
    fflush(stdout);
    cr_assert_stdout_eq_str("Le Lorem Ipsum est simplement du faux texte "
                            "employé dans la composition et la mise en page "
                            "avant impression. Le Lorem Ipsum est le faux "
                            "texte standard de l'imprimerie depuis les années"
                            " 1500, quand un imprimeur anonyme assembla "
                            "ensemble des morceaux de texte pour réaliser un "
                            "livre spécimen de polices de texte. Il n'a pas "
                            "fait que survivre cinq siècles, mais s'est aussi"
                            " adapté à la bureautique informatique, sans que "
                            "son contenu n'en soit modifié. Il a été "
                            "popularisé dans les années 1960 grâce à la vente"
                            " de feuilles Letraset contenant des passages du "
                            "Lorem Ipsum, et, plus récemment, par son "
                            "inclusion dans des applications de mise en page "
                            "de texte, comme Aldus PageMaker.");
}

Test(my_cat, test01, .init = redirect_all_std)
{
    const char *argv[] = {"./my_cat", ".fileTUR"};
    int argc = 2;
    my_cat(argc, (char**)argv);
    fflush(stdout);
    cr_assert_stderr_eq_str("my_cat: .fileTUR: No such file or directory\n");
}

Test(my_cat, test02, .init = redirect_all_std)
{
    const char *argv[] = {"./my_cat", ".fileTUR"};
    int argc = 1;
    my_cat(argc, (char**)argv);
    fflush(stdout);
    cr_assert_stderr_eq_str("my_cat: Usage: ./my_cat file [...]\n");
}