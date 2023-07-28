#ifndef TRANSPORTCOMPANY_TRANSPORTBUILDER_H
#define TRANSPORTCOMPANY_TRANSPORTBUILDER_H

#include <string>

#include "Transport.h"
#include "CargoTransport.h"
#include "PassengerTransport.h"
#include "UniversalTransport.h"

using namespace std;

enum TransportVariety {
    Cargo, Passenger, Universal
};

class TransportBuilder {
private:
    string _name;
    TransportType _type;
    TransportVariety _variety;
    double _cargo_capacity;
    int _passenger_capacity;

public:
    TransportBuilder() = default;

    void setName(const string &name) {
        _name = name;
    }

    void setType(TransportType type) {
        _type = type;
    }

    void setVariety(TransportVariety variety) {
        _variety = variety;
    }

    void setCargoCapacity(double cargoCapacity) {
        _cargo_capacity = cargoCapacity;
    }

    void setPassengerCapacity(int passengerCapacity) {
        _passenger_capacity = passengerCapacity;
    }

    Transport* Build() {
        switch (_variety) {
            case TransportVariety::Cargo:
                return new CargoTransport(_name, _type, _cargo_capacity);
            case TransportVariety::Passenger:
                return new PassengerTransport(_name, _type, _passenger_capacity);
            case TransportVariety::Universal:
                return new UniversalTransport(_name, _type, _passenger_capacity, _cargo_capacity);
        }
    }
};


#endif //TRANSPORTCOMPANY_TRANSPORTBUILDER_H
