#include <iostream>
#include "Studente.h"
#include "Liste4.h"
#include "Richieste.h"

using namespace std;

int main(){

    ListaDL<Studente> ld_A, ld_B;
    ListaDL<Gruppo> lista;

    cout<<"I)PUNTO: "<<endl;
    cout<<endl;

    carica_A("Studenti.txt",&ld_A);
    cout<<ld_A<<endl;

    carica_B("Studenti.txt",&ld_B);
    cout<<ld_B<<endl;

    cout<<endl;
    cout<<"II)PUNTO: "<<endl;
    cout<<endl;

    make_groups(&ld_A, &ld_B, &lista);

	stampaGruppi(&lista);

    return 0;
}
