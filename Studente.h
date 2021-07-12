#ifndef STUDENTE_H_INCLUDED
#define STUDENTE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Studente{
    string matricola, cognome, nome, citta;
    double media;
public:
    Studente(string _m, string _c, string _n, string _citt, double _med):matricola(_m),cognome(_c),nome(_n),citta(_citt),media(_med){}
    Studente():Studente(" "," "," "," ",0.0){}

    //FUNZIONI GET
    string getMatricola(){return matricola;}
    string getCognome(){return cognome;}
    string getNome(){return nome;}
    string getCitta(){return citta;}
    double getMedia(){return media;}

    //FUNZIONI SET
    void setMatricola(string _m){this->matricola=_m;}
    void setCognome(string _c){this->cognome=_c;}
    void setNome(string _n){this->nome=_n;}
    void setCitta(string _citt){this->citta=_citt;}

    friend ostream& operator<<(ostream& out, const Studente& st){
        out<<st.media<<") "<<"Numero di Matricola: "<<st.matricola<<", Cognome: "<<st.cognome<<", Nome: "<<st.nome<<", Citta': "<<st.citta<<endl;
        return out;
    }

    bool operator>=(const Studente& st)const{return (this->media>=st.media);}
    bool operator<(const Studente& st)const{return (this->media<st.media);}
    bool operator>(const Studente& st)const{return (this->media>st.media);}
};


#endif // STUDENTE_H_INCLUDED
