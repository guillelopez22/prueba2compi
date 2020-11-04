#ifndef _EXPR_PARSER_H
#define _EXPR_PARSER_H

#include <iostream>
#include <string>
#include <istream>
#include <iosfwd>
#include "lexer.h"

class Parser {
public:
    void parse() {
        curr_token = lexer.getNextToken();
        input();
    }

    Parser(Lexer &lexer) : lexer(lexer) {}
private:
    Lexer &lexer;
    Token curr_token;

    void input();
    void stmt_list();
    void stmt_listp();
    void stmt();
    void assign();
    void fun_decl();
    void arg();
    void expr();
    void exprp();
    void term();
    void termp();
    void factor();
};

#endif
