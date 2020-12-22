/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** TODO: add description
*/

#include "Parser.hpp"

Parser::Parser()
{
    _result = 0;
}

Parser::~Parser()
{
    this->reset();
}

int Parser::prevOperator(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

int Parser::applyOperation(int a, int b, char op)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return a % b;
    }
    return 0;
}

void Parser::evaluate_expr(const std::string &expr, size_t *i)
{
    size_t val = 0;
    size_t val1 = 0;
    size_t val2 = 0;
    char op;

    if (expr[*i] == '(')
        _operators.push(expr[*i]);
    else if (std::isdigit(expr[*i])) {
        val = 0;
        while (*i < expr.length() && std::isdigit(expr[*i])) {
            val = (val*10) + (expr[*i] - '0');
            *i = *i + 1;
        }
        *i = *i - 1;
        _operands.push(val);
    } else if (expr[*i] == ')') {
        while (!_operators.empty() && _operators.top() != '(') {
            val2 = _operands.top();
            _operands.pop();
            val1 = _operands.top();
            _operands.pop();
            op = _operators.top();
            _operators.pop();
            _operands.push(applyOperation(val1, val2, op));
        }
        if (!_operators.empty())
            _operators.pop();
    } else {
        while (!_operators.empty() && prevOperator(_operators.top())
        >= prevOperator(expr[*i])) {
            val2 = _operands.top();
            _operands.pop();
            val1 = _operands.top();
            _operands.pop();
            op = _operators.top();
            _operators.pop();
            _operands.push(applyOperation(val1, val2, op));
        }
        _operators.push(expr[*i]);
    }
}

void Parser::feed(const std::string &expr)
{
    size_t i = 0;
    size_t val1 = 0;
    size_t val2 = 0;
    char op;

    for (i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') continue;
        this->evaluate_expr(expr, &i);
    }
    while (!_operators.empty() && _operators.top() != '(') {
        val2 = _operands.top();
        _operands.pop();
        val1 = _operands.top();
        _operands.pop();
        op = _operators.top();
        _operators.pop();
        _operands.push(applyOperation(val1, val2, op));
    }
    _result += _operands.top();
}

int Parser::result() const
{
    return _result;
}

void Parser::reset()
{
    while (!_operands.empty()) {
        _operands.pop();
    }
    while (!_operators.empty()) {
        _operators.pop();
    }
    _result = 0;
}