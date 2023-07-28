#ifndef TRANSPORTCOMPANY_CARGO_H
#define TRANSPORTCOMPANY_CARGO_H

#include <string>

#include "Object.h"

using namespace std;

class Cargo : public Object {
private:
    string _name;
    double _weight;

public:
    Cargo(const string &name, double weight) : _name(name), _weight(weight) {}

    const string &getName() const {
        return _name;
    }

    double getWeight() const {
        return _weight;
    }
};


#endif //TRANSPORTCOMPANY_CARGO_H
