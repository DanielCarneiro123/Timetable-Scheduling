#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <cstring>
#include <set>
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

    myFile.open("../classes.csv");
    getline(myFile, CurrentLine);
    string tempClassString; // string criada para poder copiar ints como classes.StartHour e classe.Duration para uma string

    while (getline(myFile, CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, classe.ClassCode, ',');
        getline(inputString, classe.UcCode, ',');
        getline(inputString, classe.Weekday, ',');

        getline(inputString, tempClassString, ',');
        classe.StartHour = atoi(tempClassString.c_str());

        tempClassString = "";
        getline(inputString, tempClassString, ',');
        classe.Duration = atoi(tempClassString.c_str());

        getline(inputString, classe.Type, ',');
        if (classe.Type.back() == '\r') classe.Type.pop_back();
        ArrClasses.push_back(classe);

        CurrentLine = "";
    }
    myFile.close();
    CurrentLine = "";

    //Passar ficheiro ClassesPerUc para vetor ArrClassesPerUc
    vector<classesPerUcClass> ArrClassesPerUc;
    classesPerUcClass classPerUc;

    myFile.open("../classes_per_uc.csv");
    getline(myFile, CurrentLine);
    while (getline(myFile, CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, classPerUc.UcCode, ',');
        getline(inputString, classPerUc.ClassCode, ',');
        if (classe.ClassCode.back() == '\r') classe.ClassCode.pop_back();
        ArrClassesPerUc.push_back(classPerUc);
        CurrentLine = "";
    }
    myFile.close();
    CurrentLine = "";

    //Passar ficheiro StudentsClasses para vetor ArrStudentsClasses

    vector<studentsClassesClass> ArrStudentsClasses;
    studentsClassesClass studentClasses;

    myFile.open("../students_classes.csv");
    getline(myFile, CurrentLine);

    while (getline(myFile, CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, studentClasses.StudentCode, ',');
        getline(inputString, studentClasses.StudentName, ',');
        getline(inputString, studentClasses.UcCode, ',');
        getline(inputString, studentClasses.ClassCode, ',');
        if (classe.ClassCode.back() == '\r') classe.ClassCode.pop_back();
        ArrStudentsClasses.push_back(studentClasses);
        CurrentLine = "";
    }


    string stringResposta;
    int intResposta;
    while (stringResposta != "q"){
        cout << "=========================What action do you wish to do?===========================" << endl;
        cout << "Actions related to students (Students in UCs, Classes,...) - [PRESS 1]" << endl;
        cout << "Actions related to UCs (Occupation of UC,Classes Per UC, All UCs,...) - [PRESS 2]" << endl;
        cout << "Actions related to Classes (Occupation of Class,...) - [PRESS 3]" << endl;
        cout << "Request to Change Schedule - [PRESS 4]" << endl;
        cout << "If the day has come to an end - [PRESS f]" << endl;
        cout << "If you want to exit the menu - [PRESS q]" << endl;
        cout << "==================================================================================" << endl;
        cin >> stringResposta;
        if (stringResposta == "q") break;
        if (stringResposta == "f") studentsClassesClass::verificarFinalDoDia(ArrStudentsClasses);
        if (stringResposta == "1"){
            intResposta=0;
            cout << "=================What action do you wish to do?===================" << endl;
            cout << "If you want to see which students are in a certain class [PRESS 1]" << endl;
            cout << "If you want to see all students [PRESS 2]" << endl;
            cout << "If you want to see all students belonging to a year [PRESS 3]" << endl;
            cout << "If you want to see all students from an UCs [PRESS 4]" << endl;
            cout << "If you want to see the schedule of a student [PRESS 5]" << endl;
            cout << "If the day has come to an end - [PRESS f]" << endl;
            cout << "If you want to exit the menu - [PRESS q]" << endl;
            cout << "==================================================================" << endl;

            cin >> stringResposta;
            if (stringResposta == "q") break;
            if (stringResposta == "f") studentsClassesClass::verificarFinalDoDia(ArrStudentsClasses);
            if (stringResposta == "1"){
                cout << "Which class do you want see? || FORMAT:1LEIC01";
                cin >> stringResposta;
                studentsClassesClass::estudantesTurma(ArrStudentsClasses, stringResposta);
            }
            if (stringResposta == "2"){
                studentsClassesClass::todosEstudantes(ArrStudentsClasses);
            }
            if (stringResposta == "3"){
                cout << "Which year do you want see?";
                cin >> intResposta;
                studentsClassesClass::estudantesEmUcsAno(ArrStudentsClasses, intResposta);
            }
            if (stringResposta == "4"){
                cout << "Which UC do you want see?";
                cin >> stringResposta;
                studentsClassesClass::estudantesUC(ArrStudentsClasses, stringResposta);
            }
        }
        if (stringResposta == "2"){
            stringResposta = "0";
            cout << "=====================What action do you wish to do?=======================" << endl;
            cout << "If you want to see which students are in UCs from a certain year [PRESS 1]" << endl;
            cout << "If you want to see all UCs [PRESS 2]" << endl;
            cout << "If you want to see all students belonging to an UC [PRESS 3]" << endl;
            cout << "If the day has come to an end - [PRESS f]" << endl;
            cout << "If you want to exit the menu - [PRESS q]" << endl;
            cout << "==========================================================================" << endl;
            cin >> stringResposta;
            if (stringResposta == "q") break;
            if (stringResposta == "f") studentsClassesClass::verificarFinalDoDia(ArrStudentsClasses);
            if (intResposta == 1){
                cin >> intResposta;
                studentsClassesClass::ocupacaoUcsAno(ArrStudentsClasses, intResposta);
            }
            if (intResposta == 2){
                classesPerUcClass::todasUcs(ArrClassesPerUc);
            }
            if (intResposta == 3){
                cin >> stringResposta;
                studentsClassesClass::ocupacaoUc(ArrStudentsClasses, stringResposta);
            }
        }
        if (intResposta == 3){
            cin >> stringResposta;
            studentsClassesClass::turmasUC(ArrStudentsClasses, stringResposta);
        }
        if (intResposta == 4){
            studentsClassesClass::alteraçaoVariasTurmas(ArrStudentsClasses);
        }
    }

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
//studentsClassesClass::pedidoAlteracaoHorario("Iara", "L.EIC002", "1LEIC08", ArrStudentsClasses);
//removerEstudante("Jose Jesualdo", "L.EIC023", "3LEIC08", ArrStudentsClasses);
//studentsClassesClass::alteraçaoVariasTurmas(ArrStudentsClasses);
