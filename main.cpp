#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include "classesStruct.h"
#include "classesPerUC.h"
#include "StudentsClassesStruct.h"

using namespace std;

///Numero de estudantes numa turma x (Ocuupação da turma)

void ocupacaoTurma(const string cadeira, string turma, const vector<StudentsClassesStruct>& arr){
    int acc=0;
    for (const auto& x:arr){
        int i = x.UcCode.compare(cadeira);
        int j = x.ClassCode.compare(turma);
        if (i==0 && j==0){
            acc++;
        }
    }

    cout << "Number of people in class " << turma << " for UC " << cadeira << ": " << acc;
}

void ocupacaoUcsAno(const vector<StudentsClassesStruct>& arr, char ano){
    vector<string> v;
    for (const auto& x: arr){
        if(x.ClassCode.at(0) == ano && !(find(v.begin(), v.end(), x.StudentName) != v.end())){
            v.push_back(x.StudentName);
        }}
    int acc=0;
    for (auto x: v) acc++;
    cout << "Number of people attending UCs belonging to ano " << ano << ": " << acc;
    }
///Número de estudantes numa UC x (Ocupação UC)

void ocupacaoUc(const vector<StudentsClassesStruct>& arr, string cadeira){
    int sum = 0;
    for (const auto& x: arr){
        int i = x.UcCode.compare(cadeira);
        if (i == 0){
            sum++;
        }
    }
    cout << "Number of students in UC " << cadeira << ": " << sum;
}

///Estudantes em determinada turma x

void estudantesTurma(const vector<StudentsClassesStruct>& arr, string turma){
    string sep = ":";
    cout << "The students that belong to class " << turma << " are";
    for (const auto& x: arr){
        if (x.ClassCode.compare(turma) == 0){
            cout << sep << " " << x.StudentName;
            sep = ",";
        }
    }
    cout << ".";
}

void estudantesEmUcsAno(const vector<StudentsClassesStruct>& arr, char ano){
    string sep = ":";
    vector<string> v;
    for (const auto& x: arr){
            if(x.ClassCode.at(0) == ano && !(find(v.begin(), v.end(), x.StudentName) != v.end())){
                v.push_back(x.StudentName);
            }

    }
    cout << "The students that are attending UCs belonging to year " << ano << " are";
    for (auto x : v){
        cout << sep << " " << x;
        sep = ",";

    }
    cout << ".";

}

///Estudantes em determinada UC x
void estudantesUC(const vector<StudentsClassesStruct>& arr, string cadeira){
    string sep = ":";
    cout << "The students that are attending UC " << cadeira << " are";
    for (const auto& x: arr){
        if (x.UcCode.compare(cadeira) == 0){
            cout << sep << " " << x.StudentName;
            sep = ",";
        }
    }
    cout << ".";
}



///Horário de determinado estudante

void horarioEstudante(const vector<StudentsClassesStruct>& arr1, const vector<classesStruct>& arr2, string nomeEstudante){
    string turmaAtual = "";
    string cadeiraAtual = "";
    for (auto x: arr1){
        if (x.StudentName.compare(nomeEstudante)==0){
            turmaAtual = x.ClassCode;
            cadeiraAtual = x.UcCode;
            for (auto y:arr2){
                int n1=y.ClassCode.compare(turmaAtual);
                int n2=y.UcCode.compare(cadeiraAtual);
                if (n1==0 && n2==0){
                    cout << nomeEstudante << " has a " << y.Type << " class for UC " <<  y.UcCode << " from " << y.StartHour << " to " << y.StartHour + y.Duration << " on " << y.Weekday << endl;}
            }
        }

    }
}



int main() {
    ifstream myFile;
    string CurrentLine;   // string usada para ler os ficheiros

    //Passar ficheiro Classes para vetor ArrClasses

    vector<classesStruct> ArrClasses;
    classesStruct classe;

    myFile.open("C:/Users/utilizador/TrabalhoAED/classes.csv");
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
    vector<classesPerUcStruct> ArrClassesPerUc;
    classesPerUcStruct classPerUc;

    myFile.open("C:/Users/utilizador/TrabalhoAED/classes_per_uc.csv");
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

    vector<StudentsClassesStruct> ArrStudentsClasses;
    StudentsClassesStruct studentClasses;

    myFile.open("C:/Users/utilizador/TrabalhoAED/students_classes.csv");
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

    //estudantesUC(ArrStudentsClasses,"L.EIC002");
    //estudantesTurma(ArrStudentsClasses, "1LEIC05");
    //ocupacaoTurma("L.EIC002","1LEIC14",ArrStudentsClasses);
    //ocupacaoUc(ArrStudentsClasses, "L.EIC021");
    //horarioEstudante(ArrStudentsClasses,ArrClasses, "Ludovico");
    //estudantesEmUcsAno(ArrStudentsClasses, '1');
    //ocupacaoUcsAno(ArrStudentsClasses,'1');
}
