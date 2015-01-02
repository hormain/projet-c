#include "classcpoa.hpp"
#include <iostream>
using namespace std;
string Personne::getid(){
return this.id;
}

string Personne::getmdp(){
return this.mdp;
}

string Personne::getNom(){
return this.nom;
}
void Personne::setNom(string s){
this.nom=s;
}
string Personne::getPrenom(){
return this.prenom;
}
void Personne::setPrenom{string s){
this.prenoms;
}

string Personne::getAdresse(){
return this.adresse;
}
void Personne::setAdresse(string s){
this.adresse=s;
}
string Personne::getEmail(){
return this.email;
}
void Personne::setemail(string s){
this.email=s;
}
string Personne::getRole(){
return this.role;
}
void Personne:: setRole(string s){
this.role=s;
}
//classe systeme 

void Systeme::Systeme(){
authentification=0;
p=0;

}
void Systeme::authentifier(string id,string mdp){

//a corriger et a mettre les bonnes fonctions pour recup l'ojbet a l'endroit de la liste et le suivant de la liste

	list<Personne> tmp(this.lp);
		for(std::list<Personne>::iterator it=tmp.begin();it!=tmp.end();++it){
			if(id==(*it).getid()){
				if(mdp==(*it).getmdp()){
				this.authentifier=1;
				p=tmp.front();
				}else{ printf("mdp incorecte");
				}
			}else{ 
				pritnf("id inexistant");
			}
		}
		delete(tmp);
}
int Systeme::getId(string nom){
	string res="id pas trouver";
	list<Personne> tmp(this.lp);
	for(std::list<Personne>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(nom=(*it).getNom()){
		res=(*it).getId();
		}
	}
	delete(tmp);
	return res;
}

int Systeme::estauthentifier(){
	return this.authentification==1;
}
Personne Systeme::getutilisateur(){
	return this.p;
}
void Systeme::AjouterCours(std::string nom,int id, date datedebut, date datefin, date datefininscription, Enseignant e){
	Cours c=new Cours(nom,id,datedebut,datefin,datefininscription,e);
	lc.push_front(c);
}
void Systeme::AjouterFichier(File f,Cours c){
	list<Cours> tmp(lc);
	for(std::list<Cours>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it==c){
		(*it).AjoutFichier(f);
		}
	}
	delete(tmp);
}
void Systeme::AjouterURL(std::string titre, std::string nom, Cours c){
	list<Cours> tmp(lc);
	for(std::list<Cours>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it==c){
			(*it).AjoutURL(nom,titre);
		}

	}
}
void Systeme::AjouterDevoir(string s, Date d, Cours c, string nom){
	list<Cours> tmp(lc);
	for(std::list<Cours>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it==c){
			(*it).AjouterDevoir(s,d,nom);
		}

	}
}
int Systeme::VerifierFichier(File f, Cours c){
	list<Cours> tmp=new list(lc);
	for(std::list<Cours>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it==c){
			c.verifierRessource(f);
		}
	}
}

Cours Systeme::RechercheCours(string nom){
	list<Cours> tmp(lc);
	Cours res;
	for(std::list<Cours>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(((*it).getNom()==nom){
		res=*it;
		}
	}
	delete(tmp);
	return res;
	
}

int Systeme::VerifierCours(string s){
	list<Cours> tmp(lc);
	int res=0;
	for(std::list<Cours>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(((*it).getNom()==nom){
			res=1;
		}
	}
	delete(tmp);
	return res;
	
}
list<Cours> Systeme::ListCours(){
	return this.lc;
}
void Systeme::notifier(Cours c,string s){
	list<Etudiant> tmp(c.getParaticipant);
	for(std::list<Etudiant>::iterator it=tmp.begin();it!=tmp.end();++it){
		envoyermail(*it,s);
	}	
	delete(tmp);
}
void Systeme::notifier(Etudiant e, string s){
	envoyermail(e,s);
}
void Systeme:: notifierEnseignant(Enseignant e, string s){
	envoyermail(e,s);
}
void Systeme::envoyermail(Personne p, string s){
//fonction magique
}
list<Ressource> Systeme::AfficherRessource(Cours c){
	list<Ressource> res;
	res=c.getRessource();
	return res;
}
list<Note> Systeme::ConsulterNotes(Cours c, Devoir d){
	res =c.consulterNotes(d);
	return res;
}
list<Note> Systeme::ConsulterNotes(Cours c){
	return c.Consultertoutesnotes();
}
	
Note Systeme::ConsulterNotes(Cours c,Devoir d){
	return c.ConsulterNotes(d);
}
void Systeme::NotesDevoir(Devoir d, Cours c, Etudiant e, int i, int j){
	c.NoterDevoir(d,i,j,e);
	norifier(e,"devoir noté");
}
string Systeme::getrole(){
	return p.getRole();
}

list<Cours> Systeme::CoursenAttente(){
	list<Cours> tmp(lc);
	list<Cours> res;
	for(std::list<Cours>::iterator it=tmp.begin();it!=tmp.end();++it){
		if((*it).isEnattente()){
			res.push_front(*it);
		}
	}
	return res;
}
void Systeme::autoriserCours(Cours c){
	c.setEnattente(0);
	c.setValider(1);
	c.supprimerattente();
	notifierEnseignant(c.getResponsable(),"Cours accepte");
}

void Systeme::refuserCours(Cours c){
	c.setValider(0);
	c.setEnAttente(0);
	notifierEnseignant(c.getResponsable(),"Cours accepte");
}
void Systeme::isncription(Cours c){
	c.inscrire(p);
}
void Systeme::deinscription(Cours c){
	c.desinscrire(p);
}
int Systeme::placeattente(Cours c){
	return c.placelisteattente(p);
}
void Systeme::AjoutCours(Cours c){
	lc.push_front(c);
}
void Systeme::AjoutRessource(Cours c, Ressource r){
	c.ajouterressource(r);
}
void Systeme::PublierNote(Devoir d, Cours c){
	c.publierNote(d);
}
list<Cours> Systeme::CoursAccepter(){
	list<Cours> res;
	list<Cours> tmp(lc);
	for(std::list<Cours>::iterator it=tmp.begin();it!=tmp.end();++it){
		if((*it).isEnattente()){
			res.push_front(*it);
		}
	}
	return res;
}
int Systeme::verifierRendu(Cours c, Devoir d, Etudiant e){
	return c.verifierRendu(d,e);
}
Rendu Systeme::getRendu(Cours c, Devoir d, Etudiant e){
	return c.getRendu(d,e);
}
Devoir Systeme::rechercheDevoir(Cours c, string nom, Etudiant e){
	return c.recherchedevoir(nom,e);
}
//classe cours

void Cours(string nom,int pl,date debut,date fin,date inscription,Enseignant responsable){
this.nom=nom;
enattente=1;
ouvert=0;
date_debut=debut;
date_fin=fin;
date_inscription=inscription;
this.place=pl;
valider=0;
}
string Cours::getnom(){
return nom;
}
void Cours::setNom(string s){
this.nom=s;
}
int Cours::isEnattente(){
return this.enattente;
}
void Cours::setEnattente(int i){
this.enattente=i;
}
int Cours::isOuvert(){
return this.isouvert;
}
void Cours::setOuvert(int i){
this.isouvert=i;
}
date Cours::getDate_debut(){
return this.date_debut;
}

void Cours::setDate_debut(date dd){
this.date_debut=dd;
}
date Cours::getDate_fin(){
return date_fin;
}
void Cours::setDate_fin(date df){
this.date_fin=df;
}
list<Etudiant> Cours::getParticipant(){
return this.participant;
}
void Cours::setParticipant(list<Etudiant> e){
participant=e;
}
list<Ressource> Cours::getRessource(){
return ressource;
}
void Cours::setRessource(list<Ressource> r){
ressource=r;
}
int Cours::getplace(){
return place;
}
void Cours::setPlace(int i){
place=i;
}
Enseignant Cours::getResponsable(){
return this.responsable;
}
void Cours::setresponsable(){Enseignant e){
this..responsable=e;
}
int Cours::estPresent(Etudiant e){
	list<Etudiant> tmp(participant);
	int res=0;
	for(std::list<Etudiant>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it==e){
			res=1;
		}
	}
	return res;
}
void Cours::AjoutFichier(File f){
	Fichier fi=new Fichier(f);
	ressource.push_front(fi);
}
void Cours::AjoutUrl(string s,string u){
	URL ul=new URL(s,u);
	ressource.push_front(ul);
}
void Cours::creerDevoir(string nom, string sujet, date fin){
Devoir d=new Devoir(nom, fin, sujet){
ressource.push_front(d);
}
int Cours::chercherDevoir(Devoir d){
	list<Ressource> tmp(ressource);
	int res=0;
	for(std::list<Ressource>::iterator it=tmp.begin();it!=tmp.end();++it){
		if((*it==(Ressource)d){
		res=1;
		}
	}
	delete(tmp);
	return res;
	
}
void Cours::DeposerDevoir(Etudiant e, Fichier f, Devoir d){
	int res=chercherDevoir(d);{
	if(res){
		d.RendreDevoir(f,e);
	}
}
list<Note> Cours::Consultertoutesnotes(){
	list<Note> res;
	list<Devoir> d;
	list<Ressource> tmp(ressource);
	list<list<Rendu>> llr;
	for(std::list<Ressource>::iterator it=tmp.begin();it!=tmp.end();++it){
		if((*it).getTypeRessource().compare("Devoir")){
			d.push_front(*it);
		}
	}
	for(std::list<Devoir>::iterator it2=d.begin();it2!=d.end();++it2){
		llr.push_front((*it).afficherNoter());
	}
	for(std::list<list<Rendu>>::iterator it3=llr.begin();it3!=llr.end();++it3){	
		if((*it3).estpublier(){
			for(std::list<Rendu>::iterator it4=(*it3).begin();it4!=(*it3).end();++it4){
			res.push_front((*it4).getNote());
			}
		}
	}
	delete(tmp);
	delete(llr);
	delete(d);
	return res;
}
Note Cours::Consulternotes(Devoir d, Personne p){
	Note res;
	list<Ressource> tmp(ressource);
	if(d.estpublier()){
	for(std::list<Ressource>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it==d){
			res=((Devoir)*it).afficherNotes(p);
		}
	}
	}
	delete(tmp);
	return res;
}
void Cours noterDevoir(Devoir d, int note, int bareme, Etudiant e){
	list<Ressource> tmp(ressource);
	for(std::list<Ressource>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it==d){
			((Devoir)*it).NoteDevoir(e,bareme,note);
		}
	}
}

int Cours::ChercherEtudiant(Etudiant e){
	list<Etudiant> tmp();
	int res=0;
	for(std::list<Etudiant>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it)==e){
			res=1;
		}
	return res;
}
int Cours::placelisteattente(Etudiant e){
	int res;
	int i=0;
	list<Etudiant> tmp(participant);
	for(std::list<Etudiant>::iterator it=tmp.begin();it!=tmp.end();++it){
		i++;
		if(*it==e){
			if((i-place)<0){
				res=0;
			}else{
		res=i-place;
			}
		}	
	}
	return res;
}

int Cours::estlisteattente(Etudiant e){
list<Personne> tmp(lp);
	enattente=1;
	for(std::list<Personne>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it==e){
			if(placelisteattente(e)<0){
			enattente=1;
			}
		}
	return enattente;
	}
}
void Cours::setValider(int e){
	this.valider=e;
}
void Cours::supprimerattente(){
enattente=0;
}
int Cours::CoursfermeeInscription(){

}
void Cours::inscrire(Personne p){
	participant.push_back((Etudiant)p);
}

void Cours::desinscrire(Personne p){
	participant.erase((Etudiant)p);
}

int Cours::verfierDate(){

}

void Cours::Ajouterressource(Ressource r){
	ressource.push_front(r);
}

Ressource Cours::rechercheRessource(Ressource r){
	list<Ressource> tmp(ressource);
	Ressource res;
	for(std::list<Ressource>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it==r){
		res=*it;
		}
	}
	return res;
}

int Cours::verifierRessource(Ressource r){
list<Ressource> tmp(ressource);
	int res=0;
	for(std::list<Ressource>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it==r){
		res=1;
		}
	}
	return res;
}

void Cours::publierNote(Devoir d){
	d.publierNote();
}

list<Note> Cours::ConsulterNote(Devoir d){
	list<Note> res;
	list<Ressource> tmp(ressource);
	list<Rendu> lr;
	if(d.estpublier){
		for(std::list<Ressource>::iterator it=tmp.begin();it!=tmp.end();++it){
			if(*it==d){
			lr=d.affichernote();
			}
		}
		for(std::list<Rendu>::iterator it2=lr.begin();it2!=tlr.end();++it2){
			res=(*it).getNote();
		}
	}
	return res;
}

int Cours::verifierRendu(Devoir d, Etudiant e){
return d.verifierRendu(e);
}
Rendu  Cours::getRendu(Devoir d, Etudiant e){
return d.getRendu(e);
}

Devoir Cours::rechercheDevoir(string s, Etudiant e){
	list<Ressource> tmp(ressoruce);
	list<Devoir> ld;
	int res=0;
	for(std::list<Ressource>::iterator it=tmp.begin();it!=tmp.end();++it){
		if((*it).getTypeRessource.compare("Devoir"){
			ld.push(*it);
		}
	}
	for(std::list<Devoir>::iterator it2=ld.begin();it2!=ld.end();++it2){
		if((*it2).getNom().compare(s)){
		res=1;
		}
	}
	return res;
}











