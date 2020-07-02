#ifndef CHANGER_FUNCTIONS_H
#define CHANGER_FUNCTIONS_H

#endif // CHANGER_FUNCTIONS_H
#include "mainwindow.h"
#include "ui_mainwindow.h"

bool finding(QString S, QString findS){
    bool Res = false;
    int i = 0;
    QString buf = "";
    while(i < S.size()) {
        for (int j = 0; j < findS.size(); j++)
            buf += S[i + j];

        if (buf == findS) Res = true;

        buf = "";
        i++;
    }
//test
    return(Res);
}



QString change(QString user_text, QString find_word, QString change_word) {
    QString new_text = user_text;
    QString buf1 = "", buf2 = "", buf3 = "";
    QString Result = "";
    int i = 0;

    while (i < new_text.size()) {
        buf1 = ""; buf2 = ""; buf3 = "";
        bool f = false;
        int j = 0;
        int p = 0;
        for (j = 0; j < find_word.size(); j++)
            if (i + j < new_text.size()) {
                buf1 = buf1 + new_text[i + j];
                p++;
                f = true;
            }

        if (buf1 == find_word) {
            for (int k = 0; k < i; k++)
                buf2 = buf2 + new_text[k];

            for (int k = i + p; k < new_text.size(); k++)
                buf3 = buf3 + new_text[k];

            new_text = buf2 + change_word + buf3;
            i = i + change_word.size();
            }

            i++;
        }

    return(new_text);
}
