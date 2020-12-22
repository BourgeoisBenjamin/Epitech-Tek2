/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D16_2019_PARSER_HPP
#define CPP_D16_2019_PARSER_HPP

#include <string>
#include <stack>

class Parser
{
    public:
        Parser();
        ~Parser();
        void feed(const std::string &);
        int result() const;
        void reset();

    private:
        std::stack<int> _operands;
        std::stack<char> _operators;
        int _result;
        int prevOperator(char op);
        int applyOperation(int a, int b, char op);
        void evaluate_expr(const std::string &expr, size_t *i);
};

#endif //CPP_D16_2019_PARSER_HPP
