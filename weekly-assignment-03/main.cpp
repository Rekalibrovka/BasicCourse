#include "splitter.hh"

int main()
{
    Splitter splitter_object;
    splitter_object.set_string_to_split(string_to_split);
    splitter_object.split(':');
    cout << "fields: " << "" << endl;
    return 0;
}
