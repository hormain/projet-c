#import <stdlib.h>
#import <stdio.h>
#include <list>
#include <string>
#include <ctime>
//a changer tout els type  string et list en std::
//pas compiler
using namespace std;
class Personne{
      std::string id;
      std::string mdp;
      std::string nom;
      std::string prenom;
      std::string adresse;
      std::string email;
      std::string role;
      public 
      virtual std::string getid();
      virtual std::string getmdp();
      virtual std::string getNom();
      virtual void setNom(std::string n){;
      virtual std::string getPrenom();
      virtual void setPrenom(std::string s);
      virtual std::string getAdresse();
      virtual void setAdresse(std::string s);
      virtual std::string getEmail();
      virtual void setEmail(std::string s);
      virtual std::string getRole();
      virtual void setRole(std::string s);
	  void ~Personne(){
		delete(id);	
		delete(mdp);
		delete(nom);
		delete(prenom);
		delete(adresse);
		delete(email);
		delete(role);
	  }
      };
 class Administrateur : public Personne{

      public 
      void Administrateur(std::string id, std::string mdp, std::string nom, std::string prenom, std::string adresse, std::string email){
           p.id=id;
           p.mdp=mdp;
           p.setNom(nom);
           p.setPrenom(prenom);
           p.setAdresse(adresse);
           p.setEmail(email);
           p.setRole("Administrateur");
      }
	  void ~Administrateur(){
		this.~Personne();
	  }
      virtual std::string getid();
      virtual std::string getmdp();
      virtual std::string getNom();
      virtual setNom(std::string n);
      virtual getPrenom();
      virtual setPrenom(std::string s);
      virtual getAdresse();
      virtual setAdresse(std::string s);
      virtual getEmail();
      virtual setEmail(std::string s);
      virtual getRole();
      virtual setRole(std::string s);
      };
      
class Etudiant : public Personne{
      std::list<Cours> lc;
      public
      void Etudiant(std::string id, std::string mdp, std::string nom, std::string prenom, std::string adresse, std::string email){
           p.id=id;
           p.mdp=mdp;
           p.setNom(nom);
           p.setPrenom(prenom);
           p.setAdresse(adresse);
           p.setEmail(email);
           p.setRole("Etudiant");
           lc=std::list<Cours>();
      }
      void ~Etudiant(){
		ths.~Personne();
		delete(lc);
	  }
      virtual string getid();
      virtual string getmdp();
      virtual getNom();
      virtual void setNom(std::tring n);
      virtual getPrenom();
      virtual setPrenom(std::string s);
      virtual getAdresse();
      virtual setAdresse(std::string s);
      virtual getEmail();
      virtual setEmail(std::string s);
      virtual getRole();
      virtual setRole(std::string s);
      };
class Enseignant : public Personne{
      std::list<Cours> lc;
      public
      void Enseignant(std::string id, std::string mdp, std::string nom, std::string prenom, std::string adresse, std::string email){
           p.id=id;
           p.mdp=mdp;
           p.setNom(nom);
           p.setPrenom(prenom);
           p.setAdresse(adresse);
           p.setEmail(email);
           p.setRole("Enseignant");
           lc=std::list<Cours>();
      }
	  void ~Enseignant(){
		delete(lc);
		this.~Personne();
 	  }
      virtual std::string getmdp();
      virtual getNom();
      virtual void setNom(std::string n);
      virtual getPrenom();
      virtual setPrenom(std::string s);
      virtual getAdresse();
      virtual setAdresse(std::string s);
      virtual getEmail();
      virtual setEmail(std::string s);
      virtual getRole();
      virtual setRole(std::string s);
      };
class Systeme{
      int authentification;
      Personne p;
      std::list<Personne> lp;
      std::list<Cours> lc;
      public 
      void Systeme();
	  void ~Systeme(){
		delete(authentification);
		delete(p);
		delete(lp);
		delete(lc);
	  }

      void authentifier(std::string id, std::string mdp);
      int getId(std::string nom);
      int estauthentifier();
      Personne getutilisateur();
      void AjouterCours(std::string nom,int id, time_t datedebut, time_t datefin, time_t datefininscription, Enseignant e);
      void AjouterFichier(File f, Cours c);
      void AjouterURL(std::string titre, std::string nom, Cours c);
      void AjouterDevoir(std::string s, time_t d, Cours c, std::string nom);
      int VerifierFichier(File f,Cours c);
      Cours RechercheCours(std::string nom);
      int VerifierCours(std::string s);
      std::list<Cours> ListCours();
      void notifier(Cours c, std::string nom);
      void notifier(Etudiant e, std::string s);
      void notifierEnseignant(Enseignant e,std::string s);
      void envoyermail(Personne p, std::string s);
      std::list<Ressource> AfficherRessource(Cours c);
      void deposerDevoir(Cours c, Fichier f, Devoir d);
      std::list<Note> ConsulterNotes(Cours c);
      std::list<Note> ConsulterNotes(Devoir d, Cours c);
      Note ConsulterNotes(Cours c, Devoir d);
      void NoterDevoir(Devoir d, Cours c, Etudiant e, int i, int j);
      std::string getrole();
      std::list<Cours> CoursenAttente();
      void autoriserCours(Cours c);
      void refuserCorus(Cours c);
      void inscription(Cours c);
      void desinscription(Cours c);
      int placeattente(Cours c);
      void AjoutCours(Cours c);
      void AjoutreRessource(Cours c, Ressource r);
      void PublierNote(Devoir d, Cours c);
      std::list<Cours> CoursAccepter();
      verifierRendu(Cours c, Devoir d, Etudiant e);
      Rendu getRendu(Corus c, Devoir d, Etudiant e);
      int verifierDate(Cours c);
      recherchedevoir(Cours c, std::string s, Etudiant e);
      };
      
class Cours{
      std::string nom;
      int enattente;
      int ouvert;
	  Enseignant responsable;
      time_t date_debut;
      time_t date_fin;
      time_t date_inscription ;
      int place;
      int valider;
	  std::list<Etudiant> participant;
      std::list<Ressource> ressource;
      public
      Cours(std::string n,int i,time_t dd, time_t df,Enseignant e);
	  void ~Cours(){
		delete(nom);
		delete(enattente);
		delete(ouvert);
		delete(date_debut);
		delete(date_fin);
		delete(date_inscription);
		delete(place);
		delete(valider);
		delete(participant);
		delete(ressource);
		delete(responsable);
	  }
      std::string getNom();
      void setNom(std::string s);           }
      int isEnattente();
      void setEnattente(int b);
      int isOuvert();
      void setOuvert(int b);
      time_t getDate_debut();
      void setDate_debut(time_t dd);
      time_t getDate_fin();
      void setDate_fin(time_t df);
      std::list<Etudiant> getParticipant();
      void setParticipant(std::list<Etudiant> le);
      std::list<Ressource> getRessource();
      void setRessource(std::list<Ressource> lr);
      int getPlace();
      void setPlace(int i);
      Ensignant getResponsable();
      void setRespondable(Enseignant e);
      int estPresent(Personne p);
	  void AjoutFichier(File f);
      void AjoutURL(std::string nom, std::string url);
      void creerDevoir(std::string nom, std::string sujet, time_t fin);
      int chercherDevoir(Devoir d);
      void DeposeDevoir(Etudiant e,Fichier f, Devoir d);
      std::list<Note> Consultertoutesnotes();
      Note Consulternotes(Devoir d, Personne p);
      void NoterDevoir(Devoir d, int note, int baremme, Etudiant e);
      int ChercherEtudiant(Etudiant e);
      int estlisteattente(Etudiant e);
      int placelisteattente[Etudiant e);
      void setValider(int b);
      void supprimerattente();
      int CoursfermeeInscription();
      void inscrire(Personne p);
      void desincrire(Perosnne p);
      int verifierDate();
      void Ajouterressource(Ressource r);
      Ressource rechercheRessource(Ressource r);
      int verifierRessource(Ressource r);
      void publierNote(Devoir d);
      std::list<Note> Consulternotes(Devoir d);
      int VerifierRendu(Devoir d, Etudiant e);
      Rendu GetRendu(Devoir d, Etudiant e);
      Devoir recherchedevoir(std::string s, Etudiant e);
      };
class Ressource{
      std::string nom;
      std::string type;
      public
      virtual std::string getnom(){
		return nom;
	  }
      virtual std::string getTypeRessource(){
		return type;
	  }
	  void ~Ressource(){
		delete(nom);
		delete(type);
	  }

      };
      
class URL : public Ressource{
      std::string lien;
      public 
      void URL(std::string nom, std::string url);
      virtual std::string getnom();
      virtual std::string getTypeRessource();
	  void ~URL(){
		delete(url);
		this.~Ressource();
	  }
      };
class Fichier : public Ressource{
      File fichier;
      public
      void Fichier(File f);
      virtual std::string getnom();
      virtual std::string getTypeRessource();
	  void ~Fichier(){
		delete(fichier);
		this.~Ressource();
	  }
      };
      
class Devoir : public Ressource{
      time_t datefin;
      std::string sujet;
      int affichenote;
      std::liste<Rendu> rendu;
      public 
      void Devoir(std::string nom, time_t fin, std::string sujet);
      void RendreDevoir(Fichier f, Etudiant e);
      void NoteDevoir(Etudiant e, int note, int bareme);
      void publierNote();
      std::liste<Rendu> affichernotes();
      virtual std::string getnom();
      virtual std::string getTypeRessource();
      Note affichernotes(Etudiant p);
      int verifierRendu(Etudiant e);
      Rendu getRendu(Etudiant e);
	  int estpublier();
	  void ~Devoir(){
		this.~Ressource();
		delete(datefin);
		delete(sujet);
		delete(affichenote);
		delete(rendu);
	  }
      };
class Rendu{
      Etudiant redacteur;
      Fichier f;
      Note n;
      public 
      void Rendu(Fichier f, Etudiant e);
      Etudiant getEtudiant();
      void SetNote(int note);
      void setBareme(int b);
      Note getNote();
      int getBareme();
      Fichier getFichier();
	  void ~Rendu(){
		delete(redacteur);
		delete(f);
		delete(n);
	  }
      };
class Note{
	  int note;
	  int bareme;
  	  void Note();
	  void Note(int b, int n){note=n;bareme=b;}
	  void setNote(int n){ note=n; }
	  int getNote(){ return note; } 
	  void setBareme(int b){ bareme=b;}
	  int getBareme(){ return bareme;}
	  void ~Note(){
		delete(note);
		delete(bareme);
	  }
	  };
