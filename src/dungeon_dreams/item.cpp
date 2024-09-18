#include "item.h"
#include <iostream>

using namespace std;

Item::Item(string name, string type, string description, string icon)
: name(name), type(type), description(description), icon(icon) { }

void Item::useItem(const string& type) {
    if (type == "consumable"){
        // do something
    }else if(type == "equippable"){
        // do something
    }
    //do something else
}
