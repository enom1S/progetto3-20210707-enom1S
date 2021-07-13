#ifndef RICHIESTE_H_INCLUDED
#define RICHIESTE_H_INCLUDED

#include "Liste4.h"
#include "Studente.h"
#include "Gruppo1.h"
#include <sstream>
#include <fstream>
#include <iostream>

//PUNTO 1

void make_groups(ListaDL<Studente>* lista1, ListaDL<Studente>* lista2, ListaDL<Gruppo>* lista);
void stampaGruppi(ListaDL<Gruppo>* lista);


void delim(const string& line, string dati[6]){
    char dlmt=';';
    stringstream ss(line);
    string token;
    int i=0;
    while(getline(ss,token,dlmt)){
        dati[i]=token;
        i++;
        if(i==6)break;
    }
}

void carica_A(const string filename, ListaDL<Studente>* ld){
    ifstream file;
    string buffer[6];
    string line;
    Studente s;
    file.open(filename);
    if(!file){
        cout<<"Non esiste";
        exit(1);
    }
    else{
        cout<<"Lista A: "<<endl;
        while(getline(file,line)){
            delim(line,buffer);
            s=Studente(
                buffer[0],
                buffer[1],
                buffer[2],
                buffer[3],
                stod(buffer[4])
            );
            if(s.getMedia()>=24)ld->insert_A(s);    //inserisce nella lista tutti i valori letti dal file
            else continue;
        }
    }
    file.close();
}

void carica_B(const string filename, ListaDL<Studente>* ld) {   //lettura da file
	ifstream file;
    string buffer[6];
    string line;
    Studente s;
    file.open(filename);
    if(!file){
        cout<<"Non esiste";
        exit(1);
    }
    else{
        cout<<"Lista B: "<<endl;
        while(getline(file,line)){
            delim(line,buffer);
            s=Studente(
                buffer[0],
                buffer[1],
                buffer[2],
                buffer[3],
                stod(buffer[4])
            );
            if(s.getMedia()<24)ld->insert(s);    //inserisce nella lista tutti i valori letti dal file
            else continue;
        }
    }
    file.close();
}

//PUNTO 2

void make_groups(ListaDL<Studente>* lista1, ListaDL<Studente>* lista2, ListaDL<Gruppo>* lista) {

	int id_s = 0;    //identificatori dei gruppi
	Nodo_DL<Studente>* current1 = lista1->getTesta(); int len1 = lista1->getLung(); //prendo la lunghezza delle liste
	Nodo_DL<Studente>* current2 = lista2->getTesta(); int len2 = lista2->getLung();
	Nodo_DL<Studente>*a, *b1, *b2;
	while (len1 && len2) {  //fino quando non scorro tutto
		Gruppo temp(id_s);
		a=current1;
		if(len2 < 2)break; //fino a quando non vengono svuotati secondo i criteri richiesti
		if(len1 < 1)break;
		b1=current2;  //passa al nodo della seconda lista
		b2=current2->getSucc();   //passa al successivo del nodo precedente
		if ((b1->getValue() + b2->getValue()) >= 40) {
			temp.inserisci_membro(*b1);
			temp.inserisci_membro(*b2);
			current2 = current2->getSucc()->getSucc();
			len2 -= 2;  //scalo di due dalla lista precedente
		}
		else {
			temp.inserisci_membro(*a);
			temp.inserisci_membro(*b1);
			temp.inserisci_membro(*b2);
			current1 = current1->getSucc();
			current2 = current2->getSucc()->getSucc();
			len2 -= 2;  //scalo ugualmente, decrementando di due
			len1--;
		}
		lista->insert_coda(temp);    //stampa dei gruppi secondo i criteri
		id_s++;
	}
	Gruppo temp(id_s);   //stampa gli id

    //INSERIMENTO DEGLI STUDENTI RIMANENTI
	for(int i =0; i < len1; i++){
		a=current1;
		current1 = current1->getSucc();
		temp.inserisci_membro(*a);
	}
	for(int i =0; i < len2; i++){
		a=current2;
		current2 = current2->getSucc();
		temp.inserisci_membro(*a);
	}
	lista->insert_coda(temp);    //stampa degli esuberi
}

void stampaGruppi(ListaDL<Gruppo>* lista){

	Nodo_DL<Gruppo>* current = lista->getTesta();
	while(current != NULL){
		current->getValue().printGroup();
        current = current->getSucc();
		cout << endl;
	}
	cout << endl;
}

#endif // RICHIESTE_H_INCLUDED
