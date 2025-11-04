#include "Keeper.h"
#include <iostream>
#include "Exceptions.h"
#include "Car.h"
#include "Moto.h"
#include "Bus.h"
#include <filesystem>
#include <string>

using namespace std;

Keeper::Keeper() : vehicles(nullptr), size(0), capacity(20) {
    vehicles = new Vehicle *[capacity];
    cout << "Вызван конструктор Keeper по умолчанию" << endl;
}

Keeper::Keeper(Vehicle **vehicles, size_t size, size_t capacity) : size(size), capacity(capacity) {
    this->vehicles = new Vehicle *[capacity];
    for (size_t i = 0; i < size; i++)
        this->vehicles[i] = vehicles[i]->clone();
    cout << "Вызван конструктор Keeper с параметрами" << endl;
}

Keeper::Keeper(const Keeper &other) : size(other.size), capacity(other.capacity) {
    this->vehicles = new Vehicle *[capacity];
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
    Vehicle **newVehicles = new Vehicle *[newCapacity];
    for (size_t i = 0; i < size; i++)
        newVehicles[i] = vehicles[i];
    delete[] vehicles;
    vehicles = newVehicles;
    capacity = newCapacity;
}

void Keeper::append(Vehicle *v) {
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
    Vehicle *v = vehicles[index];
    v->edit();
}

void Keeper::printKeeper() const {
    for (size_t i = 0; i < size; i++) {
        vehicles[i]->print();
        cout << endl;
    }
}

string getFullPath(const string &filename) {
    namespace fs = filesystem;
    fs::path projectRoot = fs::path(__FILE__).parent_path().parent_path(); // ../ от src/
    return (projectRoot / filename).string();
}


void Keeper::saveKeeper(const string &filename) const {
    ofstream out(getFullPath(filename));
    if (!out) throw FileErr("Файл недоступен для записи");
    for (size_t i = 0; i < size; i++) {
        vehicles[i]->save(out);
    }
    out.close();
    cout << "Keeper успешно сохранён в файл: " << filename << " (сохранено объектов: " << size << ")" << endl;
}

void Keeper::loadKeeper(const string &filename) {
    ifstream file(getFullPath(filename));
    if (!file.is_open()) {
        throw FileErr("Ошибка открытия файла");
        return;
    }

    for (size_t i = 0; i < size; i++)
        delete vehicles[i];
    size = 0;
    string type;
    while (getline(file, type)) {
        if (type.empty()) continue;

        Vehicle *v = nullptr;

        if (type == "Машина") {
            v = new Car();
        } else if (type == "Мотоцикл") {
            v = new Moto();
        } else if (type == "Автобус") {
            v = new Bus();
        } else continue;

        v->load(file);
        if (size >= capacity) resize(capacity * 2);
        vehicles[size++] = v;
    }

    file.close();
    cout << "Keeper успешно загружен из файла: " << filename
            << " (загружено объектов: " << size << ")" << endl;
}


Vehicle *Keeper::getVehicle(int index) const {
    if (index >= size) return nullptr;
    return vehicles[index];
}

size_t Keeper::getSize() const { return size; }
