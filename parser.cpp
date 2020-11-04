
#include <iostream>
#include <fstream>
#include "lexer.h"
#include <string>

Lexer lexer;
Token curr_token;

void input() {
    stmt_list();
}

void stmt_list() {
    stmt();
    stmt_listp();
}

void stmt_listp() {
    if (curr_token == Token::Semicolon){
        curr_token = lexer.getNextToken();
        stmt();
        if (curr_token == Token::Semicolon) {
            stmt_listp();
        }
    } else {    
    }
}

void stmt() {
    if (curr_token == Token::Ident){
        assign();
    } else if(curr_token == Token::KwPrint) {
        curr_token = lexer.getNextToken();
        expr();
    } else {
        fun_decl();
    }
}

void assign() {
    if (curr_token == Token::Number) {
        curr_token = lexer.getNextToken();
        if (curr_token == Token::OpAssign) {
            curr_token = lexer.getNextToken();
        }
        expr();
    }
}

void fun_decl() {
    if (curr_token == Token::Ident) {
        curr_token = lexer.getNextToken();
        if (curr_token == Token::OpenPar) {
            curr_token = lexer.getNextToken();
            arg();
        }
        if (curr_token == Token::ClosePar) {
            curr_token = lexer.getNextToken();
            if (curr_token == Token::OpAssign) {
                curr_token = lexer.getNextToken();
                expr();
            }
        } else {
            throw std::string("Error");
        }
    }
}

void arg() {
    if (curr_token == Token::Number) {
        curr_token = lexer.getNextToken();
    } else if (curr_token == Token::Ident) {
        curr_token = lexer.getNextToken();
    } else {
        throw std::string("Error");
    }
}

void expr() {
    term();
    exprp();
}

void exprp() {
    if (curr_token == Token::OpAdd) {
        curr_token = lexer.getNextToken();
        term();
        exprp();
    }else {

    }
}

void term() {
    factor();
    termp();
}

void termp() {
    if (curr_token == Token::OpMul) {
        curr_token = lexer.getNextToken();
        factor();
        termp();
    } else {

    }
}

void factor() {
    if (curr_token == Token::Ident) {
        curr_token = lexer.getNextToken();
    } else if (curr_token == Token::Number) {
        curr_token = lexer.getNextToken();
    } else if (curr_token == Token::OpenPar) {
        curr_token = lexer.getNextToken();
        expr();
        if (curr_token == Token::ClosePar) {
            curr_token = lexer.getNextToken();
        } else {
            throw std::string("Error");
        }
    }
}