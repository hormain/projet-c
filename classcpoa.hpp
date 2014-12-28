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
      virtual std::string getid(){
              return id;
              }
      virtual std::string getmdp(){
              return mdp;
              }
      virtual std::string getNom(){
              return nom;
              }
      virtual void setNom(String n){
              nom=n;
              }
      virtual std::string getPrenom(){
              return prenom;
              }
      virtual void setPrenom(string s){
              prenom=s;
              }
      virtual std::string getAdresse(){
              return adresse;
              }
      virtual void setAdresse(string s){
              adresse=s;
              }
      virtual std::string getEmail(){
              return email;
              }
      virtual void setEmail(string s){
              email=s;
              }
      virtual std::string getRole(){
              return role;
              }
      virtual void setRole(string s){
              role=s;
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
      virtual std::string getid();
      virtual std::string getmdp();
      virtual std::string getNom();
      virtual setNom(String n);
      virtual getPrenom();
      virtual setPrenom(string s);
      virtual getAdresse();
      virtual setAdresse(string s);
      virtual getEmail();
      virtual setEmail(string s);
      virtual getRole();
      virtual setRole(string s);
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
      virtual void setNom(String n);
      virtual getPrenom();
      virtual setPrenom(string s);
      virtual getAdresse();
      virtual setAdresse(string s);
      virtual getEmail();
      virtual setEmail(string s);
      virtual getRole();
      virtual setRole(string s);
      };
class Enseignant : public Personne{
      std::list<Cours> lc;
      public
      void Enseignant(string id, string mdp, string nom, string prenom, string adresse, string email){
           p.id=id;
           p.mdp=mdp;
           p.setNom(nom);
           p.setPrenom(prenom);
           p.setAdresse(adresse);
           p.setEmail(email);
           p.setRole("Enseignant");
           lc=std::list<Cours>();
           }
            virtual string getmdp();
      virtual getNom();
      virtual void setNom(String n);
      virtual getPrenom();
      virtual setPrenom(string s);
      virtual getAdresse();
      virtual setAdresse(string s);
      virtual getEmail();
      virtual setEmail(string s);
      virtual getRole();
      virtual setRole(string s);
      };
class Systeme{
      boolean authentification;
      Personne p;
      std::list<Personne> lp;
      std::list<Cours> lc;
      public 
      void Systeme(){
           //il faudra coder en dure ici pour peupler la lide des personne pour se ocnnecter
           lp=std::list<Personne>();
           lc=std::list<Cours>();
           }
      void authentifier(string id, string mdp);
      int getId(string nom);
      boolean estauthentifier();
      Personne getutilisateur(){
               return p;
               }
      void AjouterCours(string nom,int id, date datedebut, date datefin, date datefininscription, Enseignant e);
      void AjouterFichier(File f, Cours c);
      void AjouterURL(String titre, String nom, Cours c);
      void AjouterDevoir(String s, Date d, Cours c, String nom);
      boolean VerifierFichier(File f,Cours c);
      Cours RechercheCours(String nom);
      boolean VerifierCours(String s);
      list<Cours> ListCours();
      void notifier(Cours c, string nom);
      void notifier(Etudiant e, String s);
      void notifierEnseignant(Enseignant e,String s);
      void envoyermail(Personne p, String s);
      list<Ressource> AfficherRessource(Cours c);
      void deposerDevoir(Cours c, Fichier f, Devoir d);
      list<Note> ConsulterNotes(Cours c);
      list<Note> ConsulterNotes(Devoir d, Cours c);
      Note ConsulterNotes(Cours c, Devoir d);
      void NoterDevoir(Devoir d, Cours c, Etudiant e, int i, int j);
      String getrole();
      list<Cours> CoursenAttente();
      void autoriserCours(Cours c);
      void refuserCorus(Cours c);
      void inscription(Cours c);
      void desinscription(Cours c);
      int placeattente(Cours c);
      void AjoutCours(Cours c);
      void AjoutreRessource(Cours c, Ressource r);
      void PublierNote(Devoir d, Cours c);
      list<Cours> CoursAccepter();
      verifierRendu(Cours c, Devoir d, Etudiant e);
      Rendu getRendu(Corus c, Devoir d, Etudiant e);
      boolean verifierDate(Cours c);
      recherchedevoir(Cours c, string s, Etudiant e);
      };
      
class Cours{
      String nom;
      boolean enattente;
      boolean ouvert;
      date date_debut;
      date date_fin;
      date date_inscription ;
      int place;
      boolean valider;
      list<Ressource> ressource;
      public
      Cours(String n,int i,date dd, date df,Enseignant e);
      string getNom();
      void setNom(String s);           }
      boolean isEnattente();
      void setEnattente(boolean b);
      boolean isOuvert();
       void setOuvert(boolean b);
       date getDate_debut();
       void setDate_debut(date dd);
       date getDate_fin();
       void setDate_fin(date df);
       list<Etudiant> getParticipant();
       void setParticipant(list<Etudiant> le);
       list<Ressource> getRessource();
       void setRessource(list<Ressource> lr);
       int getPlace();
       void setPlace(int i);
       Ensignant getResponsable();
       void setRespondable(Enseignant e);
       boolean estPresent(Personne p);
       void AjoutFichier(File f);
       void AjoutURL[string nom, string url);
       void creerDevoir(String nom, string sujet, date fin);
       int chercherDevoir(Devoir d);
       void DeposeDevoir(Etudiant e,Fichier f, Devoir d);
       list<Rendu> Consultertoutesnotes();
       Note Consulternotes(Devoir d, Personne p);
       void NoterDevoir(Devoir d, int note, int baremme, Etudiant e);
       int ChercherEtudiant(Etudiant e);
       boolean estlisteattente(Etudiant e);
       int placelisteattente[Etudiant e);
       void setValider(boolean b);
       void supprimerattente();
       boolean CoursfermeeInscription();
       void inscrire(Personne p);
       void desincrire(Perosnne p);
       boolean verifierDate();
       void Ajouterressource(Ressource r);
       Ressource rechercheRessource(Ressource r);
       boolean verifierRessource(Ressource r);
       void publierNote(Devoir d);
       list<Note> Consulternotes(Devoir d);
       boolean VerifierRendu(Devoir dn Etudiant e);
       Rendu GetRendu(Devoir d, Etudiant e);
       Devoir recherchedevoir(String,Etudiant);
       };
class Ressource{
      string nom;
      string type;
      public
      virtual string getnom(){
              return nom;
              }
      virtual getTypeRessource(){
              return type;
              }
      };
      
class URL : public Ressource{
      string lien;
      public 
      void URL(String nom, String url);
      virtual String getnom();
      virtual String getTypeRessource();
      };
class Fichier : public Ressource{
      File fichier;
      public
      void Fichier(File f);
      virtual String getnom();
      virtual String getTypeRessource();
      };
      
class Devoir : public Ressource{
      date datefin;
      string sujet;
      boolean affichenote;
      liste<Rendu> rendu;
      public 
      void Devoir(String nom, date fin, string sujet);
      void RendreDevoir(Fichier f, Etudiant e);
      void NoteDevoir(Etudiant e, int note, int bareme);
      void publierNote();
      liste<Rendu> affichernotes();
      virtual string getnom();
      virtual string getTypeRessource();
      Note affichernotes(Etudiant p);
      boolean verifierrendu(Etudiant e);
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
