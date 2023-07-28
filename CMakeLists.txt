cmake_minimum_required(VERSION 3.25)
project(TransportCompany)

set(CMAKE_CXX_STANDARD 17)

add_executable(TransportCompany main.cpp lib/Object.h lib/Cargo.h lib/Transport.h lib/CargoTransport.h lib/Order.h lib/TransportBuilder.h lib/PassengerTransport.h lib/Passenger.h lib/UniversalTransport.h)
