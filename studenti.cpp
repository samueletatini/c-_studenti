#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct studente{
    string nome;
    string cognome;
};

void scriviStudente(){
    int numStudenti;
    cout<<"Inserisci il numero di studenti da inserire:";
    cin>>numStudenti;
    cin.ignore();

    fstream file("lista.txt",ios::out|ios::app);

    for(int i=0;i<numStudenti;i++){
        studente s;
        int scelta;
        cout<<"Inserisci 1 per nome, 2 per nome e cognome per lo studente "<<i+1<<":";
        cin>>scelta;
        cin.ignore();

        cout<<"Inserisci il nome dello studente:";
        getline(cin,s.nome);

        if(scelta==2){
            cout<<"Inserisci il cognome dello studente:";
            getline(cin,s.cognome);
            file<<s.nome<<';'<<s.cognome<<'\n';
        }
        else{
            file<<s.nome<<'\n';
        }
    }

    file.close();
}

void visualizzaLista(){
    string linea;
    fstream file("lista.txt",ios::in);
    while(getline(file,linea)){
        string nome=linea;
        string cognome="";
        int delimitatore=linea.find(';');
        if(delimitatore!=-1){
            nome=linea.substr(0,delimitatore);
            cognome=linea.substr(delimitatore+1);
        }
        cout<<"Nome:"<<nome<<", Cognome:"<<cognome<<'\n';
    }
    file.close();
}

void clear(){
    ofstream file("lista.txt");
    file<<"";
}

int main(){
    clear();
    int scelta;
    do{
        cout<<"Inserisci 1 per scrivere uno studente sulla lista, 2 per visualizzare la lista, 0 per uscire:";
        cin>>scelta;

        if(scelta==1){
            scriviStudente();
        }
        else if(scelta==2){
            visualizzaLista();
        }
        else if(scelta!=0){
            cout<<"Scelta non valida."<<endl;
        }
    }while(scelta!=0);

    return 0;
}
