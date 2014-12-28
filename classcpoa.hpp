#import <stdlib.h>
#import <stdio.h>
#include <list>

//a changer tout els type  string et list en std::

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
      void authentifier(std::string id, std::string mdp);
      int getId(std::string nom);
      int estauthentifier();
      Personne getutilisateur();
      void AjouterCours(std::string nom,int id, date datedebut, date datefin, date datefininscription, Enseignant e);
      void AjouterFichier(File f, Cours c);
      void AjouterURL(std::string titre, std::tring nom, Cours c);
      void AjouterDevoir(std::string s, Date d, Cours c, std::string nom);
      int VerifierFichier(File f,Cours c);
      Cours RechercheCours(std::string nom);
      boolean VerifierCours(std::string s);
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
      date date_debut;
      date date_fin;
      date date_inscription ;
      int place;
      int valider;
      std::list<Ressource> ressource;
      public
      Cours(std::string n,int i,date dd, date df,Enseignant e);
      std::string getNom();
      void setNom(std::string s);           }
      int isEnattente();
      void setEnattente(int b);
      int isOuvert();
       void setOuvert(int b);
       date getDate_debut();
       void setDate_debut(date dd);
       date getDate_fin();
       void setDate_fin(date df);
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
       void AjoutURL[std::string nom, std::string url);
       void creerDevoir(std::string nom, std::string sujet, date fin);
       int chercherDevoir(Devoir d);
       void DeposeDevoir(Etudiant e,Fichier f, Devoir d);
       std::list<Rendu> Consultertoutesnotes();
       Note Consulternotes(Devoir d, Personne p);
       void NoterDevoir(Devoir d, int note, int baremme, Etudiant e);
       int ChercherEtudiant(Etudiant e);
       int estlisteattente(Etudiant e);
       int placelisteattente[Etudiant e);
       void setValider(boolean b);
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
       int VerifierRendu(Devoir dn Etudiant e);
       Rendu GetRendu(Devoir d, Etudiant e);
       Devoir recherchedevoir(std::string s, Etudiant e);
       };
class Ressource{
      std::string nom;
      std::string type;
      public
      virtual std::string getnom();
      virtual std::string getTypeRessource();
      };
      
class URL : public Ressource{
      std::string lien;
      public 
      void URL(std::string nom, std::string url);
      virtual std::string getnom();
      virtual std::string getTypeRessource();
      };
class Fichier : public Ressource{
      File fichier;
      public
      void Fichier(File f);
      virtual std::string getnom();
      virtual std::string getTypeRessource();
      };
      
class Devoir : public Ressource{
      date datefin;
      std::string sujet;
      int affichenote;
      std::liste<Rendu> rendu;
      public 
      void Devoir(std::string nom, date fin, std::string sujet);
      void RendreDevoir(Fichier f, Etudiant e);
      void NoteDevoir(Etudiant e, int note, int bareme);
      void publierNote();
      std::liste<Rendu> affichernotes();
      virtual std::string getnom();
      virtual std::string getTypeRessource();
      Note affichernotes(Etudiant p);
      int verifierrendu(Etudiant e);
      Rendu getRendu(Etudiant e);
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
      };
