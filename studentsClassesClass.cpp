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

void studentsClassesClass::pedidoAlteracaoHorario(const string nome, const int Cap, const string cadeira, const string novaTurma, const vector<studentsClassesClass>& arr){
    int n_alunosTurma = ocupacaoTurma(cadeira, novaTurma, arr);
    for (const auto& x : arr){
        if (x.StudentName == nome && x.UcCode == cadeira) {
            if (n_alunosTurma < Cap && diferençaDeAlunosTurma(cadeira, arr)) {
                //removerEstudante();
                //adicionarEstudante();
                x.ClassCode = novaTurma;
                cout << "Feito, trocaste de turma";
            }
            if (diferençaDeAlunosTurma(cadeira, arr) == 0 && n_alunosTurma >= Cap) cout << "Não deu para trocares de turma pois causa desiquilibrio e a turma também não tinha vagas.";
            if (diferençaDeAlunosTurma(cadeira, arr) == 0) cout << "Não deu para trocares de turma pois causa desiquilibrio entre turmas.";
            if (n_alunosTurma >= Cap) cout<< "Não deu para trocares de turma pois a turma não tem vagas.";
        }
    }
}

bool studentsClassesClass::diferençaDeAlunosTurma(const string cadeira, const vector<studentsClassesClass>& arr){
    vector<string> v;
    int maior = INT_MIN;
    int menor = INT_MAX;

    for (const auto& x: arr){
        if (x.UcCode.compare(cadeira) == 0 && !(find(v.begin(), v.end(), x.ClassCode) != v.end()) ){
            v.push_back(x.ClassCode);
        }
    }
    sort(v.begin(), v.end(), strcomp0);
    for (const auto& y: v) {
        if (ocupacaoTurma(cadeira, y, arr) > maior) maior = ocupacaoTurma(cadeira, y, arr);
        if (ocupacaoTurma(cadeira, y, arr) < menor) menor = ocupacaoTurma(cadeira, y, arr);
    }
    if ( maior - menor < 4) return true;
    return false;
}

///Numero de estudantes numa turma x (Ocuupação da turma)

int studentsClassesClass::ocupacaoTurma(const string cadeira, string turma, const vector<studentsClassesClass>& arr){
    int acc=0;
    for (const auto& x:arr){
        int i = x.UcCode.compare(cadeira);
        int j = x.ClassCode.compare(turma);
        if (i==0 && j==0){
            acc++;
        }
    }

    //cout << "Number of people in class " << turma << " for UC " << cadeira << ": " << acc << endl;

    return acc;
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
        cout << "There is no Uc with that code.";
    }
    else{
        cout << "The classes belonging to UC " << uc << " are";
        for (const auto& n: v){
            cout << sep << " " << n;
            sep = ",";
        }
        cout << ". " << sum << " classes in total.";
    }
}
