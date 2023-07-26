#include <iostream>

#include "./lib/Order.h"
#include "./lib/CargoTransport.h"

using namespace std;

int main() {

    auto truck = new CargoTransport("KAMAZ", TransportType::Car, 5000);
    auto order = new Order(truck, "point 1", "point 2");

    auto transportTemp = order->getTransport();
    cout << order->getStart() << " -> " << order->getFinish() << transportTemp->getName() << endl;
    cout << "objects = " << transportTemp->getObjects()->size() << endl;
    delete transportTemp;

    truck->addObject(new Cargo("cargo", 4000));

    auto transportTemp2 = order->getTransport();
    cout << "objects = " << transportTemp2->getObjects()->size() << endl;
    cout << "object = " << dynamic_cast<Cargo*>(transportTemp2->getObjects()->at(0))->getName() << endl;
    delete transportTemp2;

    return 0;
}
