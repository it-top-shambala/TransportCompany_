#ifndef TRANSPORTCOMPANY_TRANSPORT_H
#define TRANSPORTCOMPANY_TRANSPORT_H

#include <vector>
#include <string>

#include "Object.h"

using namespace std;

enum TransportType {
    Car, Rail, Avia
};

class Transport {
private:
    string _name;
    TransportType _type;

protected:
    vector<Object*>* _objects;

    Transport(const string &name, TransportType type) : _name(name), _type(type) {
        _objects = new vector<Object*>;
    }
    virtual ~Transport() {
        delete _objects;
    }

public:
    const string &getName() const {
        return _name;
    }

    TransportType getType() const {
        return _type;
    }

    virtual bool addObject(Object* object) = 0;
    vector<Object *> *getObjects() const {
        return _objects;
    }
};


#endif //TRANSPORTCOMPANY_TRANSPORT_H
