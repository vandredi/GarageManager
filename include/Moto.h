#ifndef GARAGEMANAGER_MOTO_H
#define GARAGEMANAGER_MOTO_H
#include <string>
#include "Vehicle.h"

class Moto : public Vehicle {
    float engine;
    float power;
    int terrain;

public:
    Moto();

    Moto(const std::string &brand, const std::string &model,
         float engine, float power, int terrain);

    Moto(const Moto &other);

    virtual ~Moto();

    Moto &operator=(const Moto &other);

    Moto *clone() const override;

    virtual void save(std::ofstream &out) const override;

    virtual void load(std::ifstream &in) override;

    virtual void print() const override;

    virtual std::string getType() const override;

    float getEngine() const;

    float getPower() const;

    int getTerrain() const;

    void setEngine(float e);

    void setPower(float p);

    void setTerrain(int t);

    void input() override;

    std::string printTerrain() const;

    void edit() override;
};
#endif //GARAGEMANAGER_MOTO_H
