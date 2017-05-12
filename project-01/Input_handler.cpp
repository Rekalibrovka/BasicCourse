// Kuanysh Kairbek
// 256285
// kuanysh.kairbek@student.tut.fi

#include "Input_handler.hh"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>

using product_list = map<string,double>;
using location_list = map<string, product_list>;
using shopsDB = map<string, location_list>;

Input_handler::Input_handler() //constructor with file read and record it to data_
{
    string line;
    ifstream myfile ("products.txt");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            istringstream ss(line);
            string token[4];
            for(int i = 0; i < 4 ; i++) {
                getline(ss, token[i], ';');
            }

            if(data_[token[0]][token[1]].find(token[2]) == data_[token[0]][token[1]].end()) { // check for copy
                data_[token[0]][token[1]].insert(make_pair(token[2], stod(token[3])));        // add record
            } else {
                data_[token[0]][token[1]][token[2]] = stod(token[3]);                         // replace the price
            }
        }
        myfile.close();
/*
// DEBUG INFO
        for( auto i : data_) {
            cout << i.first << endl;
            for( auto j : i.second) {
                cout << "  " << j.first << endl;
                for (auto k : j.second) {
                   cout << "    " << k.first << " " << k.second << endl;
                }
            }
        }
*/
    } else
        cout << "Error: the input file can not be read.";
}

void Input_handler::command(string input) { // commands handler function
    string token[4];
    istringstream ss(input);
    for(int i = 0; i < 4 ; i++) {
        getline(ss, token[i], ' '); // split input string into words (command and parameters)
    }

    while(true) {
        if (token [0] == "chains") {
            if ((token[1] != "") | (token[2] != "")) {
                cout << "Error: Wrong number of parameters." << endl;
                break;
            } else {
                chains_print();
                break;
            }
        } else if (token [0] == "stores") {
            if ((token[1] == "") | (token[2] != "")) {
                cout << "Error: Wrong number of parameters." << endl;
                break;
            } else {
                stores_print(token[1]);
                break;
            }
        } else if (token [0] == "cheapest") {
            if ((token[1] == "") | (token[2] != "")) {
                cout << "Error: Wrong number of parameters." << endl;
                break;
            } else {
                cheapest_print(token[1]);
                break;
            }
        } else if (token [0] == "selection") {
            if ((token[1] == "") | (token[2] == "") | (token[3] != "")) {
                cout << "Error: Wrong number of parameters." << endl;
                break;
            } else {
                selection_print(token[1], token[2]);
                break;
            }
        } else {
            cout << "Error: Wrong command." << endl;
            break;
        }
    }
}


void Input_handler::chains_print() { // chains names print function
    for (auto i : data_) {
        cout << i.first << endl;
    }
}

void Input_handler::stores_print(string chain_name) { // location print function
    shopsDB::iterator it = data_.find(chain_name);
    if (it != data_.end()) {
        for (auto i : it->second) {
             cout << i.first << endl;
        }
    } else {
        cout << "Error: Chain is not found" << endl;
    }
}

// go through all elements and compare with 'max' value
// if value less than current min_price is found
// change flag to 'true' and record chain with location into 'temp_set'

void Input_handler::cheapest_print(string product_name) { // min price for given product
    double min_price = 1000000.0; // 'max' value for comparison
    set <pair<string, string>> temp_set;
    bool found = false;
    for (auto i : data_) {
        for (auto j : i.second) {
            for (auto k : j.second) {
                if(k.first == product_name) {
                    found = true;
                    if (k.second < min_price) {
                        temp_set.clear(); // if new cheapest found -> clear set and record new
                        min_price = k.second;
                        temp_set.insert(make_pair(i.first, j.first));
                    } else if (k.second == min_price) {
                        temp_set.insert(make_pair(i.first, j.first)); // if price is the same -> add values to set
                    }
                }
            }
        }
    }
    if (found) {
        cout << min_price << endl;
        for (auto i : temp_set)
            cout << i.first << " " << i.second << endl;
    } else {
        cout << "This product is not available anywhere." << endl;
    }

}

void Input_handler::selection_print(string chain_name, string store_location) { // products available in the shop
    bool exist = false;
    for (auto i : data_) {
        for (auto j : i.second) {
            for (auto k : j.second) {
                if (i.first == chain_name && j.first == store_location) { // for all products in the shop in given location
                    exist = true;
                    cout << k.first << " " << k.second << endl;           // print product names with prices
                }
            }
        }
    }
    if (!exist) {
        cout << "Error: Not found." << endl;
    }
}
