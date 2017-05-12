#ifndef FRACTIONAL_HH
#define FRACTIONAL_HH

#include <iostream>

using namespace std;

class Fractional
{
public:
    Fractional(int numerator = 0, int denominator = 1);

    Fractional add (Fractional val); // sum
    Fractional minus ( Fractional val); // sub
    Fractional mult (Fractional val); // mult
    Fractional divide (Fractional val); // div

    void print() const;

private:
    int numerator_;
    int denominator_;
};

Fractional::Fractional(int numerator, int denominator) {
    numerator_ = numerator;
    denominator_ = denominator;
}

Fractional Fractional::add(Fractional val){
    int a = numerator_;
    int b = denominator_;
    int c = val.numerator_;
    int d = val.denominator_;

    return  Fractional(a*d+b*c,b*d);
}

Fractional Fractional::minus(Fractional val){
    int a = numerator_;
    int b = denominator_;
    int c = val.numerator_;
    int d = val.denominator_;

    return  Fractional(a*d-b*c,b*d);
}

Fractional Fractional::mult(Fractional val){
    int a = numerator_;
    int b = denominator_;
    int c = val.numerator_;
    int d = val.denominator_;

    return  Fractional(a*c,b*d);
}

Fractional Fractional::divide(Fractional val){
    int a = numerator_;
    int b = denominator_;
    int c = val.numerator_;
    int d = val.denominator_;

    return  Fractional(a*d,b*c);
}

void Fractional::print() const {
    int numerator = numerator_;
    int denominator = denominator_;
    cout << numerator << "/" << denominator << endl;
}

#endif // FRACTIONAL_HH
