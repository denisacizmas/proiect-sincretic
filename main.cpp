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

    return 0;
}