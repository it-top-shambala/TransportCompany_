#include <iostream>

#include "./lib/Order.h"
#include "./lib/CargoTransport.h"
#include "./lib/TransportBuilder.h"

using namespace std;

int main() {

    auto transportBuilder = new TransportBuilder();
    transportBuilder->setName("KAMAZ");
    transportBuilder->setType(TransportType::Car);
    transportBuilder->setVariety(TransportVariety::Universal);
    transportBuilder->setCargoCapacity(5000);
    transportBuilder->setPassengerCapacity(5);
    auto truck = transportBuilder->Build();
    auto order = new Order(truck, "point 1", "point 2");

    auto transportTemp = order->getTransport();
    cout << order->getStart() << " -> " << order->getFinish() << " : " << transportTemp->getName() << endl;
    cout << "objects = " << transportTemp->getObjects()->size() << endl;

    truck->addObject(new class Cargo("cargo", 4000));
    truck->addObject(new class Passenger("passenger"));

    auto transportTemp2 = order->getTransport();
    cout << "objects = " << transportTemp2->getObjects()->size() << endl;
    cout << "object = " << dynamic_cast<class Cargo*>(transportTemp2->getObjects()->at(0))->getName() << endl;
    cout << "object = " << dynamic_cast<class Passenger*>(transportTemp2->getObjects()->at(1))->getName() << endl;

    return 0;
}
