#ifndef TRANSPORTCOMPANY_CARGOTRANSPORT_H
#define TRANSPORTCOMPANY_CARGOTRANSPORT_H

#include "Transport.h"
#include "Cargo.h"

class CargoTransport : public Transport {
private:
    double _cargo_capacity;
    double _cargo_total;
public:
    CargoTransport(const string &name, TransportType type, double cargoCapacity) : Transport(name, type),
                                                                                   _cargo_capacity(cargoCapacity) {
        _cargo_total = 0;
    }

    bool addObject(Object *object) override {
        auto cargo = dynamic_cast<Cargo*>(object);
        auto total = _cargo_total + cargo->getWeight();

        if (total > _cargo_capacity) return false;

        _cargo_total += cargo->getWeight();
        _objects->push_back(object->clone());
        return true;
    }
};


#endif //TRANSPORTCOMPANY_CARGOTRANSPORT_H
