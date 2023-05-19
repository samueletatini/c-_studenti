#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct studente{
    string nome;
    string cognome;
};

void scrivistudente(){
    studente s;
    int scelta;
    cout<<"Inserisci 1 per nome, 2 per nome e cognome: ";
    cin>>scelta;
    cin.ignore();

    cout<<"Inserisci il nome dello studente: ";
    getline(cin, s.nome);

    fstream file("lista.txt", ios::out | ios::app);
    if(scelta==2){
        cout<<"Inserisci il cognome dello studente: ";
        getline(cin, s.cognome);
        file<<s.nome<<' '<<s.cognome<<'\n';
    }
    else{
        file<<s.nome<<'\n';
    }
    file.close();
}


void visualizzalista(){
    string linea;
    fstream file("lista.txt",ios::in);
    while(getline(file,linea)){
        cout<<linea<<"\n";
    }
    file.close();
}

void clear()
{
    ofstream file("lista.txt");
    file<<"";
}

int main(){
	clear();
    int scelta;
    do{
        cout<<"Inserisci 1 per scrivere uno studente sulla lista, 2 per visualizzare la lista, 0 per uscire: ";
        cin>>scelta;

        if(scelta==1){
            scrivistudente();
        }else if(scelta==2){
            visualizzalista();
        }else if(scelta!=0){
            cout<<"Scelta non valida."<<endl;
        }
    }while(scelta!=0);
    
    return 0;
}



