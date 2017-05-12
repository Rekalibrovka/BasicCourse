// Kuanysh Kairbek
// 256285
// kuanysh.kairbek@student.tut.fi

#ifndef INPUT_HANDLER_HH
#define INPUT_HANDLER_HH

#include <string>
#include <map>
#include <set>

using namespace std;

using product_list = map<string,double>;
using location_list = map<string, product_list>;
using shopsDB = map<string, location_list>;


class Input_handler
{
public:
    Input_handler();
    void command(string input);

private:
    shopsDB data_;
    void chains_print();
    void stores_print(string chain_name);
    void cheapest_print(string product_name);
    void selection_print(string chain_name, string store_location);
};

#endif // INPUT_HANDLER_HH
