#ifndef TRANSPORTCOMPANY_UNIVERSALTRANSPORT_H
#define TRANSPORTCOMPANY_UNIVERSALTRANSPORT_H

#include "Transport.h"
#include "Cargo.h"
#include "Passenger.h"

class UniversalTransport : public Transport {
private:
    int _passenger_capacity;
    int _passenger_total;
    double _cargo_capacity;
    double _cargo_total;

public:
    UniversalTransport(const string &name, TransportType type, int passengerCapacity, double cargoCapacity) : Transport(
            name, type), _passenger_capacity(passengerCapacity), _cargo_capacity(cargoCapacity) {
        _passenger_total = 0;
        _cargo_total = 0;
    }

    int getPassengerCapacity() const {
        return _passenger_capacity;
    }

    int getPassengerTotal() const {
        return _passenger_total;
    }

    double getCargoCapacity() const {
        return _cargo_capacity;
    }

    double getCargoTotal() const {
        return _cargo_total;
    }

    bool addObject(Object *object) override {
        auto cargo = dynamic_cast<Cargo*>(object);
        if (cargo) {
            auto total = _cargo_total + cargo->getWeight();

            if (total > _cargo_capacity) return false;

            _cargo_total += cargo->getWeight();
            _objects->push_back(object);
            return true;
        } else {
            auto passenger = dynamic_cast<Passenger*>(object);
            if (passenger == nullptr) return false;

            auto total = _passenger_total + 1;

            if (total > _passenger_capacity) return false;

            _objects->push_back(object);
            _passenger_total += 1;
            return true;
        }
    }

};


#endif //TRANSPORTCOMPANY_UNIVERSALTRANSPORT_H
