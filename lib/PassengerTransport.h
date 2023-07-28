#ifndef TRANSPORTCOMPANY_PASSENGERTRANSPORT_H
#define TRANSPORTCOMPANY_PASSENGERTRANSPORT_H

#include "Transport.h"
#include "Passenger.h"

class PassengerTransport : public Transport {
private:
    int _passenger_capacity;
    int _passenger_total;

public:
    PassengerTransport(const string &name, TransportType type, int passengerCapacity) : Transport(name, type),
                                                                                           _passenger_capacity(
                                                                                                   passengerCapacity) {
        _passenger_total = 0;
    }

    ~PassengerTransport() override = default;

    double getPassengerCapacity() const {
        return _passenger_capacity;
    }

    double getPassengerTotal() const {
        return _passenger_total;
    }

    bool addObject(Object *object) override {
        auto passenger = dynamic_cast<Passenger*>(object);
        if (passenger == nullptr) return false;

        auto total = _passenger_total + 1;

        if (total > _passenger_capacity) return false;

        _objects->push_back(object);
        _passenger_total += 1;
        return true;
    }

};


#endif //TRANSPORTCOMPANY_PASSENGERTRANSPORT_H
