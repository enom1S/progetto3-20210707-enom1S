#include <iostream>
#include <iomanip>
#include "Liste4.h"
#include "Studente.h"

using namespace std;

class Gruppo {
	int id;
	ListaDL<Studente> membri;
	int numeroM=0;

public:
	Gruppo(int ID) :id(ID) {}

	void inserisci_membro(Nodo_DL<Studente> s) {
		this->membri.insert(s.getValue());
		this->numeroM++;
	}

	int numeriMembri() {return this->numeroM;}

	void printGroup() {
		cout << "Gruppo numero) " << this->id << " Studenti: " << this->numeriMembri() << endl;
		Nodo_DL<Studente>* current = this->membri.getTesta();
		double somma = 0;

		while (current != NULL) {
			cout << "Matricola: " << current->getValue().getMatricola() << " Cognome: " << current->getValue().getCognome() << " Media: " <<current->getValue().getMedia() << endl;
			somma += current->getValue().getMedia();
			current = current->getSucc();
		}

		cout << "Media voti del gruppo: " <<setprecision(3)<< somma / this->numeroM << endl;

		return;
	}
};
