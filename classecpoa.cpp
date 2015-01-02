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
int VerifierFichier(File f, Cours c){
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
void envoyermail(Personne p, string s){
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

int Cours::ChercherEtudiant(Etudiant e){
	list<Etudiant> tmp();
	int res=0;
	for(std::list<Etudiant>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it)==e){
			res=1;
		}
	return res;
}
int Cours::estlisteattente(Etudiant e){
list<Personne> tmp(lp);
	int res=0;
	for(std::list<Personne>::iterator it=tmp.begin();it!=tmp.end();++it){
		if(*it).){
			res=1;
		}
	return res;