#ifndef GARAGEMANAGER_CAR_H
#define GARAGEMANAGER_CAR_H
#include <string>
#include <fstream>
#include <Vehicle.h>
class Car: public Vehicle {
    float engine;
    int color;
    int transmission;
    public:
    Car(const std::string brand = "Неизвестно",const std::string model = "Неизвестно", float engine = 0.0, int color = 0, int transmission = 0);
    virtual ~Car();
    virtual void save(std::ofstream& out) const override;
    virtual void load(std::ifstream& in) override;
    virtual void print() const override;
    virtual std::string getType() const override;
};
#endif //GARAGEMANAGER_CAR_H


