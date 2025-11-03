#include "Keeper.h"
#include <iostream>
#include "Exceptions.h"
using namespace std;
Keeper::Keeper(): vehicles(nullptr),size(0), capacity(20) {cout << "Вызван конструктор Keeper по умолчанию" << endl;}
Keeper::Keeper(Vehicle** vehicles, size_t size, size_t capacity): size(size), capacity(capacity){
    this->vehicles = new Vehicle*[capacity];
    for (size_t i = 0; i < size; i++)
        this->vehicles[i] = vehicles[i]->clone();
    cout << "Вызван конструктор Keeper с параметрами" << endl;
}
Keeper::Keeper(const Keeper& other) : size(other.size), capacity(other.capacity){
    this->vehicles = new Vehicle*[capacity];
    for (size_t i = 0; i < size; i++)
        this->vehicles[i] = other.vehicles[i]->clone();
    cout << "Вызван конструктор копирования Keeper" << endl;
}
Keeper::~Keeper() {
    for (size_t i = 0; i < size; i++)
        delete vehicles[i];
    delete[] vehicles;
    cout << "Вызван деструктор Keeper" << endl;
}

void Keeper::resize(size_t newCapacity) {
    if (newCapacity <= capacity) return;
    Vehicle** newVehicles = new Vehicle*[newCapacity];
    for (size_t i = 0; i < size; i++)
        newVehicles[i] = vehicles[i];
    delete[] vehicles;
    vehicles = newVehicles;
    capacity = newCapacity;
}

void Keeper::append(Vehicle* v) {
    if (size >= capacity)
        resize(capacity * 2);
    vehicles[size++] = v->clone();
}

void Keeper::remove(size_t index) {
    if (index >= size) return;
    delete vehicles[index];
    for (size_t i = index; i < size - 1; i++)
        vehicles[i] = vehicles[i + 1];
    size--;
}

void Keeper::edit(size_t index) {
    if (index >= size) return;
    delete vehicles[index];
    vehicles[index] = vehicles[index]->clone();
}

void Keeper::printKeeper() const {
    for (size_t i = 0; i < size; i++) {
        vehicles[i]->print();
        cout << endl;
    }
}



Vehicle* Keeper::getVehicle(int index) const {
    if (index >= size) return nullptr;
    return vehicles[index];
}
size_t Keeper::getSize() const { return size;}