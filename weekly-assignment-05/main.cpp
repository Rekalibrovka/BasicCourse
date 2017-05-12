#include <iostream>
#include <string>
#include <map>

using namespace std;

using GameResults = map<int, string>;
using OlympicSet = map<string, GameResults>;

void add_record ( OlympicSet& games, string game, int place, string name ) {
    //
    if ( games.find(game) == games.end() ) {
        games.insert( { game, {} } );
    }
    if ( games.at(game).find(place) == games.at(game).end() ) {
        games.at(game).insert( { place, name } );
    } else {
        games.at(game).at(place) = name;
    }
}


void print(OlympicSet& games){
    for (auto game : games){
        cout << game.first << endl;

        for (auto results : game.second){
            cout  << "  " << results.first << " : " << results.second << endl;
        }
    }
}

int main()
{
    OlympicSet Olympics = {
        {"Javelin", {{1, "James Masters"}, {6, "John Williams"}, }},
        {"Pole Jump", {{1, "Jamie Jumper"}, {9, "Sopie Poppenkorkken"}, }},
        {"Marathon", {{1, "Markus Aurelius"}, {5, "Simon Steel"}, }},
    };

    print(Olympics);

    add_record(Olympics,"Beer Pong", 1, "John Week");
    add_record(Olympics, "Javelin", 2, "Zul'gin");
    print(Olympics);

    return 0;

}
