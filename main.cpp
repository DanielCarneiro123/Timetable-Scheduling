#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <cstring>
#include "studentsClassesClass.h"
#include "classesPerUcClass.h"
#include "classesClass.h"

using namespace std;

///Horário de determinado estudante

void horarioEstudante(const vector<studentsClassesClass>& arr1, const vector<classesClass>& arr2, string nomeEstudante) {
    string turmaAtual;
    string cadeiraAtual;
    vector<classesClass> v1;
    vector<classesClass> v2;
    vector<classesClass> v3;
    vector<classesClass> v4;
    vector<classesClass> v5;
    for (auto x: arr1) {
        if (x.StudentName.compare(nomeEstudante) == 0) {
            turmaAtual = x.ClassCode;
            cadeiraAtual = x.UcCode;
            for (auto y: arr2) {
                int n1 = y.ClassCode.compare(turmaAtual);
                int n2 = y.UcCode.compare(cadeiraAtual);
                if (n1 == 0 && n2 == 0) {
                    if (y.Weekday.compare("Monday") == 0) {
                        v1.push_back(y);
                        sort(v1.begin(), v1.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Tuesday") == 0) {
                        v2.push_back(y);
                        sort(v2.begin(), v2.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Wednesday") == 0) {
                        v3.push_back(y);
                        sort(v3.begin(), v3.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Thursday") == 0) {
                        v4.push_back(y);
                        sort(v4.begin(), v4.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Friday") == 0) {
                        v5.push_back(y);
                        sort(v5.begin(), v5.end(), classesClass::intcomp);
                    }

                }

            }
        }

    }
    if (v1.size() + v2.size() + v3.size()+v4.size()+v5.size()==0) cout << "There is no student with the name " << nomeEstudante << ".";

    for (const auto &n: v1) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v2) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v3) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v4) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v5) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
}



int main() {
    classesClass classesClass1;
    classesPerUcClass classesPerUcClass1;
    studentsClassesClass studentsClassesClass1;

    ifstream myFile;
    string CurrentLine;   // string usada para ler os ficheiros

    //Passar ficheiro Classes para vetor ArrClasses

    vector<classesClass> ArrClasses;
    classesClass classe;

    myFile.open("C:/Users/User/Desktop/projeto aed/classes.csv");
    getline(myFile,CurrentLine);
    string tempClassString; // string criada para poder copiar ints como classes.StartHour e classe.Duration para uma string

    while(getline(myFile,CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, classe.ClassCode, ',');
        getline(inputString, classe.UcCode, ',');
        getline(inputString, classe.Weekday, ',');

        getline(inputString, tempClassString, ',');
        classe.StartHour=atoi(tempClassString.c_str());

        tempClassString="";
        getline(inputString, tempClassString, ',');
        classe.Duration=atoi(tempClassString.c_str());

        getline(inputString,classe.Type,',');

        ArrClasses.push_back(classe);

        CurrentLine = "";
    }
    myFile.close();
    CurrentLine = "";

    //Passar ficheiro ClassesPerUc para vetor ArrClassesPerUc
    vector<classesPerUcClass> ArrClassesPerUc;
    classesPerUcClass classPerUc;

    myFile.open("C:/Users/User/Desktop/projeto aed/classes_per_uc.csv");
    getline(myFile,CurrentLine);
    while(getline(myFile,CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, classPerUc.UcCode, ',');
        getline(inputString, classPerUc.ClassCode, ',');
        ArrClassesPerUc.push_back(classPerUc);

        CurrentLine= "";
    }
    myFile.close();
    CurrentLine = "";

    //Passar ficheiro StudentsClasses para vetor ArrStudentsClasses

    vector<studentsClassesClass> ArrStudentsClasses;
    studentsClassesClass studentClasses;

    myFile.open("C:/Users/User/Desktop/projeto aed/students_classes.csv");
    getline(myFile,CurrentLine);

    while(getline(myFile,CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, studentClasses.StudentCode, ',');
        getline(inputString, studentClasses.StudentName, ',');
        getline(inputString, studentClasses.UcCode, ',');
        getline(inputString, studentClasses.ClassCode, ',');
        ArrStudentsClasses.push_back(studentClasses);

        CurrentLine= "";

    }

    //studentsClassesClass1.turmasUC(ArrStudentsClasses,"L.EIC012");
    //studentsClassesClass1.estudantesTurma(ArrStudentsClasses, "1LEIC05");
    //studentsClassesClass1.ocupacaoTurma("L.EIC002","1LEIC14",ArrStudentsClasses);
    //studentsClassesClass1.ocupacaoUc(ArrStudentsClasses, "L.EIC021");
    //horarioEstudante(ArrStudentsClasses,ArrClasses, "Rodrigo");
    //studentsClassesClass::estudantesEmUcsAno(ArrStudentsClasses, '1');
    //studentsClassesClass1.ocupacaoUcsAno(ArrStudentsClasses,'1');
    //classesPerUcClass1.todasUcs(ArrClassesPerUc);
    //studentsClassesClass1.todosEstudantes(ArrStudentsClasses);
    //studentsClassesClass::pedidoAlteracaoHorario("Iara",50,"L.EIC002","1LEIC08",ArrStudentsClasses);
    studentsClassesClass::removerEstudante("Jose Jesualdo", "L.EIC023", "3LEIC08", ArrStudentsClasses);
}
