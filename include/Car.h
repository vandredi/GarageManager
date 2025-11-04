#ifndef GARAGEMANAGER_CAR_H
#define GARAGEMANAGER_CAR_H
#include <string>
#include "Vehicle.h"

class Car : public Vehicle {
    float engine;
    int color;
    int transmission;

public:
    Car();

    Car(const std::string &brand, const std::string &model,
        float engine, int color, int transmission);

    Car(const Car &other);

    virtual ~Car();

    Car &operator=(const Car &other);

    Car *clone() const override;

    virtual void save(std::ofstream &out) const override;

    virtual void load(std::ifstream &in) override;

    virtual void print() const override;

    virtual std::string getType() const override;

    float getEngine() const;

    int getColor() const;

    int getTransmission() const;

    void setEngine(float e);

    void setColor(int c);

    void setTransmission(int t);

    std::string printColor() const;

    std::string printTransmission() const;

    void input() override;

    void edit() override;
};
#endif //GARAGEMANAGER_CAR_H
