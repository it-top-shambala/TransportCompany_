#ifndef TRANSPORTCOMPANY_PASSENGER_H
#define TRANSPORTCOMPANY_PASSENGER_H

#include <string>

#include "Object.h"

using namespace std;

class Passenger : public Object {
private:
    string _name;

public:
    explicit Passenger(const string &name) : _name(name) {}

    const string &getName() const {
        return _name;
    }

};


#endif //TRANSPORTCOMPANY_PASSENGER_H
