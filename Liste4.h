#ifndef LISTE4_H_INCLUDED
#define LISTE4_H_INCLUDED

#include "Studente.h"
using namespace std;

template<typename T>
class Nodo_DL{
public:
    T value;
	Nodo_DL<T>* pre=nullptr, *succ=nullptr;
	Nodo_DL(T x):value(x){}

	T getValue()const{return value;}
	Nodo_DL<T> * getPre() const { return pre; }
	Nodo_DL<T> * getSucc() const { return succ; }


	void setValue(T x) { this->value = x; }
	void setPrev(Nodo_DL<T> *prev) { this->pre = prev; }
	void setNext(Nodo_DL<T> *next) { this->succ = next; }
};

template<typename T>
class ListaDL{
	Nodo_DL<T>* testa, *coda;
	int l;
public:
	ListaDL() {testa=nullptr; coda=nullptr;}

	Nodo_DL<T>* getTesta(){return testa;}
    Nodo_DL<T>* getCoda(){return coda;}

    int getLung() const{return this->l;}

    void insert_A(T x){
        Nodo_DL<T>* newNode=new Nodo_DL<T>(x);
        Nodo_DL<T>* iter=this->testa;
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

	void insert_B(T x){
        Nodo_DL<T>* newNode=new Nodo_DL<T>(x);
        newNode->value=x;
        newNode->pre=nullptr;    //essendo in testa, non avr� nessun elemento alla mia sinistra
        newNode->succ=this->testa;
        this->testa=newNode;
        this->coda=newNode;
	}


	void insert(T x) {
        Nodo_DL<T>* newNodo = new Nodo_DL<T>(x);
        newNodo->setPrev(nullptr);    //essendo in testa, non avr� nessun elemento alla mia sinistra
        newNodo->setNext(this->testa);
        this->testa = newNodo;
        l++;
    }

    friend ostream& operator<<(ostream& out, const ListaDL<T>& ls){
        Nodo_DL<T>* primo;
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

#endif // LISTE4_H_INCLUDED
