#include <string>
using namespace std;
#ifndef UNTITLED_STUDENTSCLASSESCLASS_H
#define UNTITLED_STUDENTSCLASSESCLASS_H


class studentsClassesClass {
public:
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
    static bool strcomp0(string a, string b);
    static bool strcomp1(string a, string b);
    static void ocupacaoTurma(const string cadeira, string turma, const vector<studentsClassesClass>& arr);
    static void ocupacaoUcsAno(const vector<studentsClassesClass>& arr, char ano);
    static void ocupacaoUc(const vector<studentsClassesClass>& arr, string cadeira);
    static void estudantesTurma(const vector<studentsClassesClass>& arr, string turma);
    static void estudantesEmUcsAno(const vector<studentsClassesClass>& arr, char ano);
    static void todosEstudantes(const vector<studentsClassesClass>& arr);
    static void estudantesUC(const vector<studentsClassesClass>& arr, string cadeira);
    static void turmasUC(const vector<studentsClassesClass>& arr, string uc);
};


#endif //UNTITLED_STUDENTSCLASSESCLASS_H