#ifndef LISTE2_H_INCLUDED
#define LISTE2_H_INCLUDED

#include "Studente.h"
using namespace std;

class Nodo {
public:
	Studente value;    //passo come valore una variabile di tipo Giocatore
	Nodo* pre=nullptr,*succ=nullptr;
};


class ListaSL{
    Nodo* testa;
public:
    ListaSL(){testa=nullptr;}

    void insert_A(Studente x){
        Nodo* newNode=new Nodo;
        Nodo* iter=this->testa;
        newNode->value=x;
        if(this->testa==nullptr || this->testa->value>x){
            newNode->succ=this->testa;
            this->testa=newNode;
        }
        else {
            while((iter->succ!=nullptr) && (x > iter->succ->value)){
                iter=iter->succ;
            }
            newNode->succ=iter->succ;
            iter->succ=newNode;
        }
    }

    friend ostream& operator<<(ostream& out, const ListaSL& list){
        Nodo* iter=list.testa;
        while(iter!=nullptr){
            out<<iter->value<<" \t- - > "<<iter->succ->value<<endl;
            iter=iter->succ;
        }
        out<<"nullptr"<<endl;
        return out;
    }

};

class ListaDL{
	Nodo* testa, *coda;
public:
	ListaDL() {testa=nullptr; coda=nullptr;}

	void insert_B(Studente x){
        Nodo* newNode=new Nodo;
        newNode->value=x;
        newNode->pre=nullptr;    //essendo in testa, non avrò nessun elemento alla mia sinistra
        newNode->succ=this->testa;
        this->testa=newNode;
        this->coda=newNode;
	}

    Nodo* estraiInTesta_A(){
        Nodo* app = testa;
        if(app == NULL) return NULL;
        testa = testa->succ;
        return app;
    }

    Nodo* estraiInCoda(){
        Nodo* iter= testa;
        if(iter == nullptr)return nullptr;
        while(iter!=nullptr)iter=iter->succ;
        return iter;
    }

    friend ostream& operator<<(ostream& out, const ListaDL& ls){
        Nodo* primo;
        for(primo=ls.testa; primo!=nullptr; primo = primo->succ){
            out << primo->value << endl;
            out << "\t --> ";
            if(primo->succ!=nullptr)out << primo->succ->value;
            else out << "NULL";
            out << endl;
            out << "\t <-- ";
            if(primo->pre!=nullptr)out << primo->pre->value;
            else out << "NULL";
            out << endl << endl;
        }
    return out;
    }
};

#endif // LISTE2_H_INCLUDED
