#include <iostream>
#include <vector>
#include <algorithm>
#include "studentsClassesClass.h"
using namespace std;

///funcao para comparar strings
bool studentsClassesClass::strcomp0(string a, string b){
    return a<b;
}
///funcao para comparar ints
bool studentsClassesClass::strcomp1(string a, string b) {
    return a > b;
}


///Numero de estudantes numa turma x (Ocuupação da turma)

void studentsClassesClass::ocupacaoTurma(const string cadeira, string turma, const vector<studentsClassesClass>& arr){
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
///Numero de pessoas a ir a UCs do ano x

void studentsClassesClass::ocupacaoUcsAno(const vector<studentsClassesClass>& arr, char ano){
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

void studentsClassesClass::ocupacaoUc(const vector<studentsClassesClass>& arr, string cadeira){
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

void studentsClassesClass::estudantesTurma(const vector<studentsClassesClass>& arr, string turma){
    string sep = ":";
    vector<string> names;
    cout << "The students that belong to class " << turma << " are";
    for (const auto& x: arr){
        if (x.ClassCode.compare(turma) == 0){
            names.push_back(x.StudentName);
        }
    }
    sort(names.begin(), names.end(), strcomp0);
    for (const auto& n: names){
        cout << sep << " " << n;
        sep = ",";
    }
    cout << ".";
}
///Estudantes que têm UCs do ano x

void studentsClassesClass::estudantesEmUcsAno(const vector<studentsClassesClass>& arr, char ano){
    string sep = ":";
    vector<string> v;
    for (const auto& x: arr){
        if(x.ClassCode.at(0) == ano && !(find(v.begin(), v.end(), x.StudentName) != v.end())){
            v.push_back(x.StudentName);
        }

    }
    sort(v.begin(), v.end(), strcomp0);
    cout << "The students that are attending UCs belonging to year " << ano << " are";
    for (auto x : v){
        cout << sep << " " << x;
        sep = ",";

    }
    cout << ".";

}
void studentsClassesClass::todosEstudantes(const vector<studentsClassesClass>& arr){
    string sep = ":";
    vector<string> v;
    for (const auto& x: arr){
        if (!(find(v.begin(), v.end(), x.StudentName) != v.end())){
            v.push_back(x.StudentName);
        }

    }
    sort(v.begin(), v.end(), strcomp0);
    cout << "All the students that are assigned to at least one UC are: ";
    for (auto x: v){
        cout << sep << " " << x;
        sep = ",";

    }}

///Estudantes em determinada UC x
void studentsClassesClass::estudantesUC(const vector<studentsClassesClass>& arr, string cadeira){
    string sep = ":";
    vector<string> v;
    cout << "The students that are attending UC " << cadeira << " are";
    for (const auto& x: arr){
        if (x.UcCode.compare(cadeira) == 0){
            v.push_back(x.StudentName);
        }
    }
    sort(v.begin(), v.end(), strcomp1);
    for (const auto& n: v){
        cout << sep << " " << n;
        sep = ",";
    }
    cout << ".";
}

///turmas de cada UC
void studentsClassesClass::turmasUC(const vector<studentsClassesClass>& arr, string uc){
    string sep = ":";
    int sum = 0;
    vector<string> v;
    for (const auto& x: arr){
        if (x.UcCode.compare(uc) == 0 && !(find(v.begin(), v.end(), x.ClassCode) != v.end()) ){
            v.push_back(x.ClassCode);
            sum++;
        }
    }
    sort(v.begin(), v.end(), strcomp0);
    if (sum == 0){
        cout << "It doesn´t exist any UC with that code.";
    }
    else{
        cout << "The classes that are attending UC " << uc << " are";
        for (const auto& n: v){
            cout << sep << " " << n;
            sep = ",";
        }
        cout << ". " << sum << " classes in total.";
    }

}
