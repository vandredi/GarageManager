#ifndef GARAGEMANAGER_BUS_H
#define GARAGEMANAGER_BUS_H
#include <string>
#include <fstream>
#include <Vehicle.h>
class Bus: public Vehicle {
    int seats;
    int total;
    std::string destination;
public:
    Bus(const std::string brand = "Неизвестно",const std::string model = "Неизвестно", int seats = 0, int total = 0, std::string destination = "Неизвестно");
    virtual ~Bus();
    virtual void save(std::ofstream& out) const override;
    virtual void load(std::ifstream& in) override;
    virtual void print() const override;
    virtual std::string getType() const override;
};
#endif //GARAGEMANAGER_BUS_H
