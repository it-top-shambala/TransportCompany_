#ifndef TRANSPORTCOMPANY_ORDER_H
#define TRANSPORTCOMPANY_ORDER_H

#include <string>

#include "Transport.h"

using namespace std;

class Order {
private:
    Transport* _transport;
    string _start;
    string _finish;

public:
    Order(Transport *transport, const string &start, const string &finish) : _transport(transport), _start(start),
                                                                             _finish(finish) {}

    virtual ~Order() {
        delete _transport;
    }

    Transport *getTransport() const {
        return _transport->clone();
    }

    const string &getStart() const {
        return _start;
    }

    const string &getFinish() const {
        return _finish;
    }
};


#endif //TRANSPORTCOMPANY_ORDER_H
