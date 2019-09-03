/*
* Author : Mahdi Alikhasi
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct maskan{
	int masahatSakht;
	int gheimatPaye;
	char *address;
} maskan;
typedef struct vila{
	int (*calGheimat)(struct vila *);
	int type; //if type == 0 it's a vila
	maskan base;
	int masahatHayat;
	int tedadTabaghat;
	//int FGheimat;
} vila;
typedef struct aparteman{
	int (*calGheimat)(struct aparteman *);
	int type; //if type == 1 it's a aparteman
	maskan base;
	int tabaghe;
	bool asansor;
} aparteman;

typedef struct ejare{
	void * maskan;
	//bool type;
	int mizanKomision;
	int mizanRahn;
	int mizanEjare;
	int modatEjare;
	int (*CalRahn)(struct ejare*);
	int (*CalEjare)(struct ejare*);
	int (*CalFinal)(struct ejare*);
	int Final;
} ejare;

typedef struct forosh{
	void * maskan;
	int mizanKomision;
	char * etelaat;
	int (*CalFinal)(struct forosh*);
	int Final;
} forosh;

typedef struct node{
	void *current;
	struct node *next;	
} node;

node *Vhead = 0;
node *Ahead = 0;

vila newVila(int masahatSakht, int gheimatPaye, char * address, int masahatHayat, int tedadTabaghat){
	int calGheimatV(vila * vila);
	vila *V1 = (vila *)calloc(1,sizeof(vila));
	V1->calGheimat = calGheimatV;
	V1->base.masahatSakht = masahatSakht;
	V1->base.gheimatPaye = gheimatPaye;
	V1->base.address = (char *)calloc(strlen(address) + 1,sizeof(char));
	strcpy(V1->base.address,address);
	V1->masahatHayat = masahatHayat;
	V1->tedadTabaghat = tedadTabaghat;
	V1->calGheimat(V1);
	V1->type = 0;
	//V1->FGheimat = V1->calGheimat(V1);
	if(Vhead == 0){
		Vhead = (node *)calloc(1,sizeof(node));
		Vhead->current = V1;
		Vhead->next = 0;
	}else{
		node * a = (node *)calloc(1, sizeof(node));
		a->current = V1;
		a->next = Vhead;
		Vhead = a;
	}
	return *V1;
}
aparteman newAparteman(int masahatSakht, int gheimatPaye, char * address,int tabaghe, bool asansor){
	int calGheimatA(aparteman * apa);
	aparteman *A1 = (aparteman *)calloc(1,sizeof(aparteman));
	A1->calGheimat = calGheimatA;
	A1->base.masahatSakht = masahatSakht;
	A1->base.gheimatPaye = gheimatPaye;
	A1->base.address = (char *)calloc(strlen(address) + 1,sizeof(char));
	strcpy(A1->base.address,address);
	A1->tabaghe = tabaghe;
	A1->asansor = asansor;
	A1->calGheimat(A1);
	A1->type = 1;
	if(Ahead == 0){
		Ahead = (node *)calloc(1,sizeof(node));
		Ahead->current = A1;
		Ahead->next = 0;
	}else{
		node * a = (node *)calloc(1, sizeof(node));
		a->current = A1;
		a->next = Ahead;
		Ahead = a;
	}
	return *A1;
}
ejare newEjare(void * maskan,int mizanKomision, int mizanRahn, int mizanEjare, int modatEjare){
	int Rahn(ejare * ej);
	int Eja(ejare * ej);
	int Final(ejare * ej);
	ejare *E1 = (ejare *)calloc(1,sizeof(ejare));
	E1->maskan = maskan;
	E1->mizanKomision = mizanKomision;
	E1->mizanRahn = mizanRahn;
	E1->mizanEjare = mizanEjare;
	E1->modatEjare = modatEjare;
	E1->CalRahn = Rahn;
	E1->CalEjare = Eja;
	E1->CalFinal = Final;
	E1->CalRahn(E1);
	E1->CalEjare(E1);
	E1->CalFinal(E1);
	return *E1;
}
forosh newForosh(void * maskan,int mizanKomision, char * etelaat){
	int Finalf(forosh * fo);
	forosh * F1 = (forosh *)calloc(1,sizeof(forosh));
	F1->maskan = maskan;
	F1->mizanKomision = mizanKomision;
	F1->etelaat = (char *)calloc(strlen(etelaat) + 1, sizeof(char));
	strcpy(F1->etelaat, etelaat);
	F1->CalFinal = Finalf;
	F1->CalFinal(F1);
	return *F1;
}
void showVila(vila v){
	printf("Masahate Sakht:: %d\nGheimate Paye:: %d\nAddress:: %s\nMasahate Hayat:: %d\nTedade Tabaghat:: %d\n\n", v.base.masahatSakht, v.base.gheimatPaye, v.base.address, v.masahatHayat, v.tedadTabaghat);
}
void showAparteman(aparteman a){
	printf("Masahate Sakht:: %d\nGheimate Paye:: %d\nAddress:: %s\nTabaghe chandome:: %d\nAsansor dare ya na:: %s\n\n", a.base.masahatSakht, a.base.gheimatPaye, a.base.address, a.tabaghe, (a.asansor ? "Dare" : "Nadare"));	
}
void showEjare(ejare e){
	puts("\tMoshakhasate Maskan::\n");
	if(((vila *)e.maskan)->type == 0){
		showVila(*(vila *)(e.maskan));
	}else{
		showAparteman(*(aparteman *)(e.maskan));
	}
	printf("Mizane Komision:: %d\nMizane Rahn:: %d\nMizane Ejare:: %d\nModate Ejare::%d \nHazine Nahayi:: %d\n\n", e.mizanKomision, e.mizanRahn, e.mizanEjare, e.modatEjare, e.Final);
}
void showForosh(forosh f){
	puts("\tMoshakhasate Maskan::\n");
	if(((vila *)f.maskan)->type == 0){
		showVila(*(vila *)(f.maskan));
	}else{
		showAparteman(*(aparteman *)(f.maskan));
	}
	printf("Mizane Komision:: %d\nEtelaate Dg:: %s\nHazine Nahayi:: %d\n\n", f.mizanKomision, f.etelaat, f.Final);
}

void searchByPrice(int UPrice,int LArea){
	node * curr = Vhead;
	int i = 1;
	while(curr != 0){
		if(((vila *)(curr->current))->base.gheimatPaye <= UPrice && ((vila *)(curr->current))->base.masahatSakht >= LArea){
			printf("Maskane shomare:: %d \tNoe Villai\n",i);
			showVila((*(vila *)(curr->current)));
			i++;
		}
		curr = curr->next;
	}
	curr = Ahead;
	while(curr != 0){
		if(((aparteman *)(curr->current))->base.gheimatPaye <= UPrice && ((aparteman *)(curr->current))->base.masahatSakht >= LArea){
			printf("Maskane shomare:: %d \tNoe Apartemani\n",i);
			showAparteman((*(aparteman *)(curr->current)));
			i++;
		}
		curr = curr->next;
	}
}
void SearchByAddress(char *st){
	node * curr = Vhead;
	int i = 1;
	while(curr != 0){
		if(strstr(((vila *)(curr->current))->base.address, st) != 0){
			printf("Maskane shomare:: %d \tNoe Villai\n",i);
			showVila((*(vila *)(curr->current)));
			i++;
		}
		curr = curr->next;
	}
	curr = Ahead;
	while(curr != 0){
		if(strstr(((aparteman *)(curr->current))->base.address, st) != 0){
			printf("Maskane shomare:: %d \tNoe Apartemani\n",i);
			showAparteman((*(aparteman *)(curr->current)));
			i++;
		}
		curr = curr->next;
	}	
}
int main(){
	vila V1 = newVila(100, 100, "Hamin taraf", 100, 2); //create new Vila
	showVila(V1); //show info of vila
	
	aparteman A1 = newAparteman(200, 200, "Oun taraf", 5, true); //create new Aparteman
	showAparteman(A1); //show info of Aparteman

	ejare E1 = newEjare(&V1, 100, 200, 300, 4);  //create new Ejare
	showEjare(E1); //show info of Ejare
	
	forosh F1 = newForosh(&A1, 100, "Ye chizi"); //create new Forush
	showForosh(F1); //show info of Forush

	vila V2 = newVila(100, 100, "Hamin Atraf", 100, 1); //create new Vila
	vila V3 = newVila(100, 100, "Hamin Atraf", 100, 3); //create new Vila
	vila V4 = newVila(100, 100, "Hamin Atraf", 100, 3); //create new Vila

	aparteman A2 = newAparteman(200, 600, "Oun taraf", 6, true);
	aparteman A3 = newAparteman(200, 600, "Oun taraf", 7, true);
	aparteman A4 = newAparteman(200, 600, "Oun taraf", 8, true);

	searchByPrice(400,50); //serach type 1
	SearchByAddress("taraf"); //search type 2
}

//Function Decliration here
//So the user cant use it in main and forced to use new functions
//new Functions are sth like constructors
int calGheimatV(vila * vila){
	return vila->base.gheimatPaye * (vila->base.masahatSakht + vila->masahatHayat * 3 / 10);
}
int calGheimatA(aparteman * apa){
	return apa->base.gheimatPaye * apa->base.masahatSakht;
}
int Rahn(ejare * ej){
	ej->mizanRahn = ((vila *)ej->maskan)->calGheimat(ej->maskan) * 5 / 100;
	return ej->mizanRahn;
}
int Eja(ejare * ej){
	ej->mizanEjare = ((vila *)ej->maskan)->calGheimat(ej->maskan) * 1 / 100;
	return ej->mizanEjare;
}
int Final(ejare * ej){
	ej->Final = ej->CalEjare(ej) * ej->modatEjare + ej->CalRahn(ej) + ej->mizanKomision * ej->CalRahn(ej);
	return ej->CalEjare(ej) * ej->modatEjare + ej->CalRahn(ej) + ej->mizanKomision * ej->CalRahn(ej);
}
int Finalf(forosh * fo){
	fo->Final = ((vila *)fo->maskan)->calGheimat(fo->maskan) * ( 1 + fo->mizanKomision);
	return ((vila *)fo->maskan)->calGheimat(fo->maskan) * ( 1 + fo->mizanKomision);
}