#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <set>
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

void studentsClassesClass::removerEstudante(const string nome, const string cadeira, vector<studentsClassesClass>& arr){
    int i=0;
    for (const auto& x: arr){
        if (x.StudentName == nome && x.UcCode == cadeira){
            arr[i].ClassCode = "NoClass";
            i++;
        }
        i++;
    }
    cout << "The student has been removed from current class." << endl;
}

void studentsClassesClass::adicionarEstudante(const string nome, const string cadeira, const string turma, vector<studentsClassesClass>& arr){
    int i=0;
    for (const auto& x: arr){
        if (x.StudentName == nome && x.ClassCode == "NoClass" && x.UcCode == cadeira){
            arr[i].ClassCode = turma;
            i++;
        }
        i++;
    }
    cout << "The student has been added to new class " << turma << " for UC " << cadeira << endl;
}

bool studentsClassesClass::diferencaDeAlunosTurma(const string cadeira, const vector<studentsClassesClass>& arr){
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
    if ( maior - menor < 50) return true;
    return false;
}

void studentsClassesClass::pedidoAlteracaoHorario(const std::string nome, const std::string cadeira,const std::string novaTurma,vector<studentsClassesClass> &arr) {
    int Cap = 50;
    int n_alunosTurma = ocupacaoTurma(cadeira, novaTurma, arr);
    for (const auto& x : arr){
        if (x.StudentName == nome && x.UcCode == cadeira) {
            if (n_alunosTurma < Cap && diferencaDeAlunosTurma(cadeira, arr)) {
                removerEstudante(nome,cadeira,arr);
                adicionarEstudante(nome,cadeira,novaTurma,arr);
            }
            if (diferencaDeAlunosTurma(cadeira, arr) == 0 && n_alunosTurma >= Cap) cout << "Não deu para trocares de turma pois causa desequilibrio e a turma também não tinha vagas.";
            else{
                if (diferencaDeAlunosTurma(cadeira, arr) == 0) cout << "Não deu para trocares de turma pois causa desequilibrio entre turmas.";
                if (n_alunosTurma >= Cap) cout<< "Não deu para trocares de turma pois a turma não tem vagas.";
            }

        }
    }
}

queue<studentsClassesClass> fila;

void studentsClassesClass::alteraçaoVariasTurmas(vector<studentsClassesClass> &arr){
    studentsClassesClass x;
    bool flag = 1;
    cout << "Qual é o teu nome?" << endl;
    cin >> x.StudentName;
    while(flag) {
        cout << "Qual é a UC?" << endl;
        cin >> x.UcCode;
        cout << "E qual é a nova turma?" << endl;
        cin >> x.ClassCode;
        cout << "O teu pedido foi adicionado a fila";
        cout << "Queres mudar mais alguma? Carrega '1' para 'Sim' ou '0' para não" << endl;
        cin >> flag;
        fila.push(x);
    }
}
void studentsClassesClass:: verificarFinalDoDia(vector<studentsClassesClass> &arr) {
    if (fila.empty()) cout << "Não houve pedidos de alteração de horário hoje." << endl;
    else {
        while (!fila.empty()) {
            pedidoAlteracaoHorario(fila.front().StudentName, fila.front().UcCode, fila.front().ClassCode, arr);
            fila.pop();
        }
    }
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
    cout << "Number of people attending UCs belonging to year " << ano << ": " << acc;
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
    set<string> v;
    for (const auto& x: arr){
        if (!(find(v.begin(), v.end(), x.StudentName) != v.end())){
            v.insert(x.StudentName);
        }

    }
    cout << "All the students that are assigned to at least one UC are: ";
    for (auto x: v){
        cout << sep << " " << x;
        sep = ",";
    }
    cout << endl;
}



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
