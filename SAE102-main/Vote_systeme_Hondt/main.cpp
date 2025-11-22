/**
 *  @date : 22 octobre 2024
 *  @author : Alain Casali
 *  @Brief : une prmière réponse à la SAE 1.02 de 24/25
**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

/**
 * @brief litUneString
 * @return la chaine lue sauf si :
 * (1) on une boulette sur l'entrée
 * (2) on trouve un commentaire sur l'entrée
 * le commentaire est matérialisé par la chaine "//"
 */

string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

int litUnEntier (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return stoi(uneChaine);
}

struct participant {
    string nom;
    string prenom;
    int vote;
};

bool compare2part (const participant & p1, const participant & p2){
    return p1.prenom < p2.prenom;
}

void affichVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

void affichVectParticipants (const vector<participant> & vPart){
    for (const participant & part : vPart){
        cout << part.nom << endl;
        cout << part.prenom << endl;
        cout << part.vote << endl;
    }
}

struct Quotient {
    double valeur;
    int candidat;
};

bool triDecroissant (const Quotient& a, const Quotient& b){
    return a.valeur > b.valeur;
}

void affichVectQuotient(const vector<Quotient> & vQuot) {
    for (const Quotient & q : vQuot){
        cout << q.candidat << '\t' << q.valeur << endl;
    }
}

int main()
{
    vector<string> vCandidats;
    vector<int> vVoies(4, 0);     // voix par candidat
    vector<int> vNbSieges(4,0);   // sièges attribués
    int nb_sieges = litUnEntier();

    // lecture des 4 candidats
    for (int i=0; i<4; i++) {
        vCandidats.push_back(litUneString());
    }

    // lecture des participants

    vector<participant> vParticipants;
    while (true) {
        participant participants;
        participants.nom = litUneString();
        if (participants.nom.empty()) break;
        participants.prenom = litUneString();
        participants.vote = litUnEntier();
        vParticipants.push_back(participants);
        if (participants.vote >=1 && participants.vote <=4) {
            vVoies[participants.vote-1] += 1;
        }
    }

    // affichVectParticipants(vParticipants);

    vector<Quotient> vQuotients; // On stocke chaque quotient des divisions successives
    for (int i=0; i<4; i++) {
        for (int d=1; d<=nb_sieges; d++) {
            Quotient q;
            q.valeur = (float)vVoies[i]/d;
            q.candidat = i;
            vQuotients.push_back(q);
        }
    }

    sort(vQuotients.begin(), vQuotients.end(), triDecroissant); // Tri ordre decroissant permet d'avoir juste à parcourir la table pour incrémenter le nombre de sièges
    // affichVectQuotient(vQuotients);

    // attribution des sièges
    for (int i=0; i<nb_sieges; i++) {
        vNbSieges[vQuotients[i].candidat] += 1; // On récupère l'indice du candidat voté, et on incrémente son nombre de sièges
    }

    // affichage du résultat
    for (size_t i=0; i<4; i++) {
        cout << "Nombre de sièges de " << vCandidats[i] << " : " << vNbSieges[i] << endl;
    }

    return 0;
}
