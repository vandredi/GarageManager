#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Exceptions.h"

using namespace std;

Car::Car() : Vehicle("Неизвестно", "Неизвестно"), engine(0.0), color(0), transmission(0) {
    cout << "Вызван конструктор Car по умолчанию" << endl;
}

Car::Car(const string &brand, const string &model, float engine, int color, int transmission) : Vehicle(brand, model),
    engine(engine), color(color), transmission(transmission) { cout << "Вызван конструктор Car с параметрами" << endl; }

Car::Car(const Car &other) : Vehicle(other.brand, other.model), engine(other.engine), color(other.color),
                             transmission(other.transmission) { cout << "Вызван конструктор копирования Car" << endl; }

Car::~Car() { cout << "Вызван деструктор Car" << endl; }

Car &Car::operator=(const Car &other) {
    if (this != &other) {
        Vehicle::operator=(other);
        engine = other.engine;
        color = other.color;
        transmission = other.transmission;
    }
    return *this;
}

Car *Car::clone() const { return new Car(*this); }

void Car::save(ofstream &out) const {
    if (!out) throw FileErr("Файл недоступен для записи");
    out << getType() << endl;
    out << brand << endl;
    out << model << endl;
    out << engine << endl;
    out << color << endl;
    out << transmission << endl;
}

void Car::load(ifstream &in) {
    string line;
    getline(in, line);
    Vehicle::setBrand(line);
    getline(in, line);
    Vehicle::setModel(line);
    getline(in, line);
    setEngine(stof(line));
    getline(in, line);
    setColor(stoi(line));
    getline(in, line);
    setTransmission(stoi(line));
}

void Car::print() const {
    cout << "Тип: " << getType() << endl;
    cout << "Марка: " << brand << endl;
    cout << "Модель: " << model << endl;
    cout << "Объем двигателя: " << engine << " л" << endl;
    cout << "Цвет: " << printColor() << endl;
    cout << "Тип КПП: " << printTransmission() << endl;
    cout << endl << "------------------------" << endl;
}

string Car::getType() const { return "Машина"; }

float Car::getEngine() const { return engine; }
int Car::getColor() const { return color; }
int Car::getTransmission() const { return transmission; }
void Car::setEngine(float e) { engine = e; }
void Car::setColor(int c) { color = c; }
void Car::setTransmission(int t) { transmission = t; }

string Car::printColor() const {
    switch (color) {
        case 1: return "Красный";
        case 2: return "Синий";
        case 3: return "Чёрный";
        case 4: return "Белый";
        case 5: return "Жёлтый";
        default: return "Неизвестно";
    }
}

string Car::printTransmission() const {
    switch (transmission) {
        case 1: return "Механическая";
        case 2: return "Автоматическая";
        case 3: return "Вариатор";
        case 4: return "Роботизированная";
        default: return "Неизвестно";
    }
}

void Car::input() {
    cout << "Введите марку: ";
    cin >> brand;

    cout << "Введите модель: ";
    cin >> model;

    cout << "Введите объем двигателя (в литрах): ";
    if (!(cin >> engine) || engine <= 0)
        throw InputErr("Объем двигателя должен быть положительным числом");

    cout << "Выберите цвет автомобиля:" << endl;
    cout << "1 — Красный" << endl;
    cout << "2 — Синий" << endl;
    cout << "3 — Чёрный" << endl;
    cout << "4 — Белый" << endl;
    cout << "5 — Жёлтый" << endl;
    if (!(cin >> color) || color < 1 || color > 5)
        throw InputErr("Цвет автомобиля должен быть числом от 1 до 5");

    cout << "Выберите тип коробки передач:" << endl;
    cout << "1 — Механическая" << endl;
    cout << "2 — Автоматическая" << endl;
    cout << "3 — Вариатор" << endl;
    cout << "4 — Роботизированная" << endl;
    if (!(cin >> transmission) || transmission < 1 || transmission > 4)
        throw InputErr("Тип КПП должен быть числом от 1 до 4");
    cout << "Автомобиль успешно создан!" << endl;
}

void Car::edit() {
    int choice = 0;
    do {
        cout << "1 — Изменить марку (сейчас: " << Vehicle::getBrand() << ")" << endl;
        cout << "2 — Изменить модель (сейчас: " << Vehicle::getModel() << ")" << endl;
        cout << "3 — Изменить объем двигателя (сейчас: " << engine << ")" << endl;
        cout << "4 — Изменить цвет (сейчас: " << printColor() << ")" << endl;
        cout << "5 — Изменить коробку передач (сейчас: " << printTransmission() << ")" << endl;
        cout << "6 — Выход из редактирования" << endl;
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string b;
                cout << "Введите новую марку: ";
                cin >> b;
                setBrand(b);
                break;
            }
            case 2: {
                string m;
                cout << "Введите новую модель: ";
                cin >> m;
                setModel(m);
                break;
            }
            case 3: {
                float e;
                cin >> e;
                cout << "Введите объем двигателя (в литрах): ";
                if (e <= 0)
                    throw InputErr("Объем двигателя должен быть положительным числом");
                setEngine(e);
                break;
            }
            case 4: {
                int c;
                cin >> c;
                cout << "Выберите цвет автомобиля:" << endl;
                cout << "1 — Красный" << endl;
                cout << "2 — Синий" << endl;
                cout << "3 — Чёрный" << endl;
                cout << "4 — Белый" << endl;
                cout << "5 — Жёлтый" << endl;
                if (c < 1 || c > 5)
                    throw InputErr("Цвет автомобиля должен быть числом от 1 до 5");
                setColor(c);
                break;
            }
            case 5: {
                int t;
                cin >> t;
                cout << "Выберите тип коробки передач:" << endl;
                cout << "1 — Механическая" << endl;
                cout << "2 — Автоматическая" << endl;
                cout << "3 — Вариатор" << endl;
                cout << "4 — Роботизированная" << endl;
                if (t < 1 || t > 4)
                    throw InputErr("Тип КПП должен быть числом от 1 до 4");
                setTransmission(t);
                break;
            }
            case 6:
                cout << "Автомобиль успешно изменён!." << endl;
                break;
            default:
                throw InputErr("Введите число от 1 до 5!");
        }
    } while (choice != 6);
}
