#include "Clock.hh"
#include "Fractional.hh"

void clock_func() {
    int h1,m1,h2,m2, diff;

    //setting up timers (separator space)
    cout << "Set the time of timer 1: " << endl;
    cin >> h1; cin >> m1;
    Clock timer1(h1, m1);

    cout << "Set the time of timer 2: " << endl;
    cin >> h2; cin >> m2;
    Clock timer2(h2, m2);

    //show the difference
    diff = timer2.get_time() - timer1.get_time();
    if (diff > 0)
        cout << "Difference (min): " << diff << endl;
    else
        cout << "Difference (min): " << 1440 + diff << endl;
}

void fract_func(){
    int a,b, c,d;

    cout << "Set 1st fraction: " << endl;
    cin >> a; cin >> b;
    cout << endl;
    Fractional fract1(a, b);
    fract1.print();

    cout << "Set 2nd fraction: " << endl;
    cin >> c; cin >> d;
    cout << endl;
    Fractional fract2(c, d);
    fract2.print();

    cout << "Sum is ";
    fract1.add(fract2).print();
    cout << "Sub is ";
    fract1.minus(fract2).print();
    cout << "Mult is ";
    fract1.mult(fract2).print();
    cout << "Div is ";
    fract1.divide(fract2).print();

    cout << "Problem 1 solution" << endl;

    Fractional fa = Fractional(4,5);
    Fractional fb = Fractional(5,8);
    Fractional fc = Fractional(1,8);
    Fractional fd = Fractional(2,3);
    Fractional fe = Fractional(1,7);

    fa.minus(fb.add(fc)).divide(fd.mult(fe)).print();
}

int main() {
    //clock_func();
    fract_func();
}

