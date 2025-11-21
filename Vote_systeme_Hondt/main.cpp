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
    int glacePref;
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
        cout << part.glacePref << endl;
    }
}

int main()
{
    /*
faire tableau candidat
tableau nbsieges
compter les voies
( calculer max
stocke max
/nb-sieges_attribues+1
voies[indicemax] = /nb-sieges_attribues+1
nbsieges[indicemax] +=1 ) répeter nb_sieges fois
     */
    vector<string> vCandidats;
    vector<float> vVoies(4, 0);
    vector<int> vNbSieges(4,0);
    int nb_sieges=litUnEntier();
    for (int i=0; i<3; i++) {
        vCandidats.push_back(litUneString());
    }
    while (true) {
        string nom = litUneString();
        if (nom.empty()) break;
        string prenom = litUneString();
        int vote = litUnEntier();
        vVoies[vote-1] += 1;
    }
    int nb_sieges_attribues=1;
    while (nb_sieges_attribues <= nb_sieges) {
        nb_sieges_attribues += 1;
        float max=-1;
        int indicemax=0;
        for (int i=0; i<4; i++) {
            if(vVoies[i] > max) {
                max = vVoies[i];
                indicemax = i;
            }
        }
        vVoies[indicemax] = max/nb_sieges_attribues;
        vNbSieges[indicemax] += 1;
    }
    for (size_t i=0; i<3; i++) {
        cout << "Nombre de sièges de " << vCandidats[i] << " : " << vNbSieges[i] << endl;
    }
    return 0;
}
