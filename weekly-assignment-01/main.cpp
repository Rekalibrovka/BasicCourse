#include <iostream>
#include <string>
using namespace std;

void greeting(string name)
{
    cout << "Hello, " << name <<"!" << endl;
}

int main()
{
    string name;
    cout << "What is your name? " << endl;
    cin >> name;
    greeting(name);
    return 0;
}
