#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>

using namespace std;

struct Tara 
{
    string nume;
    set<string> vecini;
    string culoare;
};

void colorare(vector<Tara>& tari, const vector<string>& culori) 
{
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<string> amestecare = culori;

    for (auto& tara : tari) 
    {
        set<string> folosita;

        for (const auto& vecin : tara.vecini)
            for (const auto& altaTara : tari)
                if (altaTara.nume == vecin && !altaTara.culoare.empty())
                    folosita.insert(altaTara.culoare);

        for (const auto& culoare : amestecare)
            if (folosita.count(culoare) == 0) 
            {
                tara.culoare = culoare;
                random_shuffle(amestecare.begin(), amestecare.end());
                break;
            }
    }
}


int main()
{
        vector<Tara> tari = {
        {"A", {"B", "C", "D", "E"}},
        {"B", {"A", "D"}},
        {"C", {"A", "D", "E"}},
        {"D", {"A", "B", "C", "E"}},
        {"E", {"A", "C", "D"}},
        {"F", {"G", "H", "I", "J"}},
        {"G", {"F", "H", "I", "J"}},
        {"H", {"F", "G", "I"}},
        {"I", {"F", "G", "H", "J"}},
        {"J", {"F", "G", "I"}}
    };

    vector<string> culori = { "Rosu", "Verde", "Galben", "Crem", "Albastru", "Roz"};

     colorare(tari, culori);

        for (const auto& tara : tari)
            cout << "Tara: " << tara.nume << " |  Culoare: " << tara.culoare << endl;

        bool necolorate = false;

        for (const auto& tara : tari)
            if (tara.culoare.empty())
            {
                necolorate = true;
                break;
            }

        if (necolorate)
            cout << "Nu au fost culori suficiente pentru a colora toate tarile respectand cerinta" << endl;

    return 0;
}