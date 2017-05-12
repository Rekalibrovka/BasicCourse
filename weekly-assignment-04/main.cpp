#include <vector>

#include "Clock.hh"


void clock_sort(vector<Clock>& time_container) {
    for (int i = 1; i < time_container.size(); i++){
        if (time_container[i-1].fetch_hour() > time_container[i].fetch_hour()){
            swap(time_container[i-1],time_container[i]);
        }
        if (time_container[i-1].fetch_hour() == time_container[i].fetch_hour()){
            if (time_container[i-1].fetch_minutes() > time_container[i].fetch_minutes()){
                swap(time_container[i-1],time_container[i]);
            }
        }
    }
}


using namespace std;

int main()
{
    vector<Clock> time_container;
    int h1,m1,h2,m2;
    cout << "Set the time of timer 1: " << endl;
    cin >> h1; cin >> m1;
    Clock timer1(h1, m1);
    time_container.push_back(timer1);

    cout << "Set the time of timer 2: " << endl;
    cin >> h2; cin >> m2;
    Clock timer2(h2, m2);
    time_container.push_back(timer2);

    clock_sort(time_container);


    int i = 0;
    for (auto time_interator : time_container){
        cout << "Clock" << i << ": ";
        time_interator.print();
        i++;
    }

    return 0;
}
