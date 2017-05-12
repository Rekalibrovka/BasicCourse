// Kuanysh Kairbek
// 256285
// kuanysh.kairbek@student.tut.fi

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <set>

#include "Input_handler.hh"

using namespace std;

int main() {
    cout << setprecision(2) << fixed; // set precision of printed prices to show cents
    Input_handler input_handler;
    string input;
    while (true) {                    // read input and parse it to command handler function
        cout << "product search> ";
        getline(cin, input);
        if (input == "quit")
            break;
        input_handler.command(input);
    }
    return 0;
}
