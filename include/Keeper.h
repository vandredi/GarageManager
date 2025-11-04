#ifndef GARAGEMANAGER_KEEPER_H
#define GARAGEMANAGER_KEEPER_H
#include "Vehicle.h"

class Keeper {
protected:
    Vehicle **vehicles;
    size_t size;
    size_t capacity;

public:
    Keeper();

    Keeper(Vehicle **vehicles, size_t size, size_t capacity);

    Keeper(const Keeper &other);

    ~Keeper();

    void resize(size_t newCapacity);

    void append(Vehicle *v);

    void remove(size_t index);

    void edit(size_t index);

    void printKeeper() const;

    void saveKeeper(const std::string &out) const;

    void loadKeeper(const std::string &in);

    Vehicle *getVehicle(int index) const;

    size_t getSize() const;
};
#endif //GARAGEMANAGER_KEEPER_H
