#include <iostream>

using namespace std;

int main() {
    int number1 = 0; //initialization
    int number2 = 111;
    int *pointer1 = new int;
    int *pointer2 = new int(222);
    *pointer1 = 1; //initialization

    cout << number1 << " "
       << number2 << " "
       << *pointer1 << " "
       << *pointer2 << endl;

    *pointer1 = 333; //usage of pointer after delete
    delete pointer1; //delete after all operations
    delete pointer2;
}
