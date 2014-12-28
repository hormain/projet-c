#include <stdbool.h>

class Personne;
class Enseignant;
class Etudiant;
class Aministrateur;
class Systeme;
class Cours;
class Devoir;
class Note;
class Rendu;
class Ressource;
class URL;
class Fichier;

typedef struct String{
        char* s;
        }string;

// liste de personne 

typedef struct listp{
        Personne perso;
        struct listp* next;
        }listperso;
listperso listpvide(){
        listperso p;
        return p;
        }

void add(Personne p ,listperso l){
        listperso n=(listperso)malloc(sizeof(listperso));
        n.perso=p;
        n->next=l;
        }
listperso next(listperso l){
        return l.(*next);
        }
int size(listperso l){
    int i=0;
    while((l->next)!=null){
                         i=i+1;
                         l=next(l);
                         }
    return i;
}
// liste d'étudiant

typedef struct liste{
        Etudiant etud;
        struct liste* next;
        }listetud;
listetud listevide(){
        etud=null;
        }

void add(Etudiant e ,listetud l){
        listetud n=(listetud)malloc(sizeof(listetud));
        n.etud=e;
        n->next=l;
        }
listetud next(listetud l){
        return l.(*next);
        }
int size(listetud l){
    int i=0;
    while((l->next)!=null){
                         i=i+1;
                         l=next(l);
                         }
    return i;
}
// liste de cours 

typedef struct listc{
        Cours cours;
        struct listc* next;
        }listcours;
listint listcvide(){
        cours=null;
        }

void add(Cours c,listint l){
        listcours n=(listcours)malloc(sizeof(listcours));
        n.cours=c;
        n->next=l;
        }
listcours next(listcours l){
        return l.(*next);
        }
int size(listcours l){
    int i=0;
    while((l->next)!=null){
                         i=i+1;
                         l=next(l);
                         }
    return i;
}
// liste de devoir

typedef struct listd{
        Devoir devoir;
        struct listd* next;
        }listdev;
listdev listdvide(){
        devoir=null;
        }

void add(Devoir dev,listdev l){
        listdev n=(listdev)malloc(sizeof(listdev));
        n.devoir=dev;
        n->next=l;
        }
listdev next(listdev l){
        return l.(*next);
        }
int size(listdev l){
    int i=0;
    while((l->next)!=null){
                         i=i+1;
                         l=next(l);
                         }
    return i;
}
// liste de rendu de devoir

typedef struct listr{
        Rendu rendu;
        struct listr* next;
        }listrendu;
listrendu listrvide(){
        rendu=null;
        }

void add(Rendu r,listrendu l){
        listrendu n=(listrendu)malloc(sizeof(listrendu));
        n.rendu=r;
        n->next=l;
        }
listrendu next(listrendu l){
        return l.(*next);
        }
int size(listrendu l){
    int i=0;
    while((l->next)!=null){
                         i=i+1;
                         l=next(l);
                         }
    return i;
}
// liste de ressource

typedef struct listre{
        Ressource ressource;
        struct listre* next;
        }listressource;
listressource listresvide(){
        ressource=null;
        }

void add(Ressource r,listressource l){
        listressource n=(listressource)malloc(sizeof(listressource));
        n.ressource=r;
        n->next=l;
        }
listressource next(listressource l){
        return l.(*next);
        }
int size(listressource l){
    int i=0;
    while((l->next)!=null){
                         i=i+1;
                         l=next(l);
                         }
    return i;
}
//liste de note

typedef struct listno{
        Note note;
        struct listno* next;
        }listnote;
listnote listnvide(){
        note=null;
        }

void add(Note no,listnote l){
        listnote n=(listnote)malloc(sizeof(listnote));
        n.note=no;
        n->next=l;
        }
listressource next(listressource l){
        return l.(*next);
        }
int size(listressource l){
    int i=0;
    while((l->next)!=null){
                         i=i+1;
                         l=next(l);
                         }
    return i;
}
