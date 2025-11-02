#ifndef GARAGEMANAGER_MOTO_H
#define GARAGEMANAGER_MOTO_H
#include <string>
#include <fstream>
#include <Vehicle.h>
class Moto: public Vehicle {
    float engine;
    float power;
    int terrain;
public:
    Moto(const std::string brand = "Неизвестно",const std::string model = "Неизвестно", float engine = 0.0, float power = 0.0, int terrain = 0);
    virtual ~Moto();
    virtual void save(std::ofstream& out) const override;
    virtual void load(std::ifstream& in) override;
    virtual void print() const override;
    virtual std::string getType() const override;
};
#endif //GARAGEMANAGER_MOTO_H
