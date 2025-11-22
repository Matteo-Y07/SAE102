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

void affichVectInt(const vector<int> &vInt){
    for (const int & val : vInt)
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
    //cout << "Hello World!" << endl;
    //vector<participant> vParticipant (19);
    /* on va detecter les glaces preférées des votants
    * tout en virant les commentaires
    */

    /* on vote sur 4 glaces */
    vector <string> vGlacePref;
    for (unsigned i (0); i < 4; ++i)
        vGlacePref.push_back(litUneString());

/* debug */

    //On lit les datas du clavier, et on les stocke
    vector<participant> vParticipant;
    vector<int> vVotes(4, 0);

    while (true){
        string nom (litUneString());
        if (nom == "-") break;
        string prenom  (litUneString());
        int numGlace (litUnEntier());
        vParticipant.push_back(participant{nom, prenom, numGlace});
        vVotes[numGlace-1] += 1;
    }

    cout << "====Resultats tour 1====" << endl;
    affichVectString (vGlacePref);
    affichVectInt(vVotes);


    vector<int> vMax(2, 0);
    vector<int> vIndicesMax(2, 0);
    int indicemax = 0;
    for (int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            if (vVotes[j] > vMax[i]){
                vMax[i] = vVotes[j];
                indicemax = j;
            }
        }
        vVotes[indicemax] = -1;
        vIndicesMax[i] = indicemax;
    }

    cout << "Second tour entre " << vGlacePref[vIndicesMax[0]] << " et " << vGlacePref[vIndicesMax[1]] << endl;
    cout << "====Resultats tour 2====" << endl;

    for (size_t i=0; i<4; i++){
        vVotes[i] = 0;
    }

    while (true){
        string nom (litUneString());
        if (nom.empty()) break;
        string prenom  (litUneString());
        int numGlace (litUnEntier());
        vParticipant.push_back(participant{nom, prenom, numGlace});
        vVotes[numGlace-1] += 1;
    }

    int max=-1;
    for(int j=0; j<4; j++){
        if (vVotes[j] > max){
            max=vVotes[j];
            indicemax = j;
        }
    }

    cout << vGlacePref[vIndicesMax[0]] << "\t" << vGlacePref[vIndicesMax[1]] << endl;
    cout << vVotes[vIndicesMax[0]] << "\t" << vVotes[vIndicesMax[1]] << endl;
    cout << "Le gagnant du vote est donc : " << vGlacePref[indicemax] << endl;


    return 0;
}
