/**
 *  @date : 22 octobre 2024
 *  @author : Alain Casali
 *  @Brief : une prmière réponse à la SAE 1.02 de 24/25
**/
#include <iostream>
#include <vector>
#include <algorithm>

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
    vector<string> candidats;
    vector<int> pointsVotes(4, 0);

    for (int i=0; i<4; i++) {
        candidats.push_back(litUneString());
    }

    while (true) {
        string nom = litUneString();
        if (nom.empty()) break;
        string prenom = litUneString();
        for (int i=0; i<4; i++) {
            int vote = litUnEntier();
            pointsVotes[vote-1] += 3-i;
        }
    }
    
    int max = pointsVotes[0];
    int indiceMax = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0 ; j < 4; j++) {
            if (pointsVotes[j] > max) {
                max = pointsVotes[j];
                indiceMax = j;
            }
        }
        cout << "top " << i+1 << " : " << candidats[indiceMax] << " avec " << pointsVotes[indiceMax] << " points" << endl;
        max = -1;
        pointsVotes[indiceMax] = -1;
    }
    return 0;
}