#include <iostream>
#include <map>
#include <string>

using namespace std;

int count_names(const map<string, string>& phonebook, char initial_letter) {

    int count = 0;

    map<string, string>::const_iterator iter = phonebook.begin();

    while ( iter != phonebook.end() ) {
        if ( iter->first.at(0) == initial_letter ) {
            ++count;
        }

        ++iter;
    }

    return count;
}

int count_names_rec( map<string, string>& phonebook, char initial_letter, map<string, string>::const_iterator iter_rec, int sum ) {
    if ( iter_rec != phonebook.end() ) {
        if (iter_rec->first.at(0) == initial_letter ) {
            return 1 + count_names_rec(phonebook, initial_letter, ++iter_rec, sum);
        }
    } else {
        return 0;
    }
}

int main()
{
    map<string, string> phonebook = {
        {{"James Bond"}, {"007"}},
        {{"Doctor Strange"}, {"123456"}},
        {{"Bruse Lee"}, {"000001"}},
        {{"Bob Job"}, {"654321"}},
        {{"Jill Valentine"}, {"3333333"}}
    };

    int number = count_names(phonebook, 'B');
    cout << "Names with B: " << number << endl;

    map<string, string>::const_iterator iter_rec = phonebook.begin();

    int number_rec = count_names_rec(phonebook, 'B', iter_rec, 0);


    cout << "Names with B_rec: " << number_rec << endl;

}
