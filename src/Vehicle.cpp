#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Moto.h"
#include "Bus.h"
#include "Exceptions.h"
using namespace std;

Vehicle::Vehicle() : brand("Неизвестно"), model("Неизвестно") {
    cout << "Вызван конструктор Vehicle по умолчанию" << endl;
}

Vehicle::Vehicle(const string &brand, const string &model) : brand(brand), model(model) {
    cout << "Вызван конструктор Vehicle с параметрами" << endl;
}

Vehicle::Vehicle(const Vehicle &other) : brand(other.brand), model(other.model) {
    cout << "Вызван конструктор копирования Vehicle" << endl;
}

Vehicle::~Vehicle() { cout << "Вызван деструктор Vehicle" << endl; }

Vehicle &Vehicle::operator=(const Vehicle &other) {
    if (this != &other) {
        brand = other.brand;
        model = other.model;
    }
    return *this;
}

string Vehicle::getBrand() const { return brand; }
string Vehicle::getModel() const { return model; }
void Vehicle::setBrand(const string &b) { brand = b; }
void Vehicle::setModel(const string &m) { model = m; }

Vehicle *Vehicle::createFromFile(ifstream &in) {
    string type;
    if (!(in >> type))
        throw FileErr("Файл пустой или некорректный");

    Vehicle *v = nullptr;
    if (type == "Машина") {
        v = new Car();
    } else if (type == "Мотоцикл") {
        v = new Moto();
    } else if (type == "Автобус") {
        v = new Bus();
    } else {
        throw FileErr("Тип " + type + " не поддерживается");
    }

    try {
        v->load(in); // <- теперь вызывается перед возвратом
    } catch (...) {
        delete v;
        throw FileErr("Строка некорректная");
    }

    return v;
}
