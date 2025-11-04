#include <iostream>
#include "Vehicle.h"
#include "Moto.h"
#include "Exceptions.h"

using namespace std;

Moto::Moto() : Vehicle("Неизвестно", "Неизвестно"), engine(0.0), power(0), terrain(0) {
    cout << "Вызван конструктор Moto по умолчанию" << endl;
}

Moto::Moto(const string &brand, const string &model, float engine, float power, int terrain) : Vehicle(brand, model),
    engine(engine), power(power), terrain(terrain) { cout << "Вызван конструктор Moto с параметрами" << endl; }

Moto::Moto(const Moto &other) : Vehicle(other.brand, other.model), engine(other.engine), power(other.power),
                                terrain(other.terrain) { cout << "Вызван конструктор копирования Moto" << endl; }

Moto::~Moto() { cout << "Вызван деструктор Moto" << endl; }


Moto &Moto::operator=(const Moto &other) {
    if (this != &other) {
        Vehicle::operator=(other);
        engine = other.engine;
        power = other.power;
        terrain = other.terrain;
    }
    return *this;
}

Moto *Moto::clone() const { return new Moto(*this); }

void Moto::save(ofstream &out) const {
    if (!out) throw FileErr("Файл недоступен для записи");
    out << getType() << endl;
    out << brand << endl;
    out << model << endl;
    out << engine << endl;
    out << power << endl;
    out << terrain << endl;
}

void Moto::load(ifstream &in) {
    string line;
    getline(in, line);
    Vehicle::setBrand(line);
    getline(in, line);
    Vehicle::setModel(line);
    getline(in, line);
    setEngine(stof(line));
    getline(in, line);
    setPower(stof(line));
    getline(in, line);
    setTerrain(stoi(line));
}

void Moto::print() const {
    cout << "Тип: " << getType() << endl;
    cout << "Марка: " << brand << endl;
    cout << "Модель: " << model << endl;
    cout << "Объем двигателя: " << engine << " см³" << endl;
    cout << "Мощность двигателя: " << power << " л.с." << endl;
    cout << "Тип местности: " << printTerrain() << endl;
    cout << endl << "------------------------" << endl;
}

string Moto::getType() const { return "Мотоцикл"; }

float Moto::getEngine() const { return engine; }
float Moto::getPower() const { return power; }
int Moto::getTerrain() const { return terrain; }
void Moto::setEngine(float e) { engine = e; }
void Moto::setPower(float p) { power = p; }
void Moto::setTerrain(int t) { terrain = t; }

string Moto::printTerrain() const {
    switch (terrain) {
        case 1: return "Городская";
        case 2: return "Внедорожная";
        case 3: return "Смешанная";
        default: return "Неизвестно";
    }
}

void Moto::input() {
    cout << "Введите марку: ";
    cin >> brand;
    cout << "Введите модель: ";
    cin >> model;
    cout << "Введите объем двигателя (в см³): ";
    if (!(cin >> engine) || engine <= 0)
        throw InputErr("Объем двигателя должен быть положительным числом");
    cout << "Введите мощность двигателя (в л.с.): ";
    if (!(cin >> power) || power <= 0)
        throw InputErr("Мощность двигателя должна быть положительным числом");
    cout << "Выберите тип местности:" << endl;
    cout << "1 — Городская" << endl;
    cout << "2 — Внедорожная" << endl;
    cout << "3 — Смешанная" << endl;
    cout << "4 — Спортивная" << endl;
    if (!(cin >> terrain) || terrain < 1 || terrain > 3)
        throw InputErr("Тип местности должен быть числом от 1 до 4");
    cout << "Мотоцикл успешно создан!" << endl;
}

void Moto::edit() {
    int choice = 0;
    do {
        cout << "1 — Изменить марку (сейчас: " << Vehicle::getBrand() << ")" << endl;
        cout << "2 — Изменить модель (сейчас: " << Vehicle::getModel() << ")" << endl;
        cout << "3 — Изменить объем двигателя (сейчас: " << engine << ")" << endl;
        cout << "4 — Изменить мощность (сейчас: " << power << " л.с.)" << endl;
        cout << "5 — Изменить тип местности (сейчас: " << printTerrain() << ")" << endl;
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
                cout << "Введите объем двигателя (в литрах): ";
                cin >> e;
                if (e <= 0)
                    throw InputErr("Объем двигателя должен быть положительным числом");
                setEngine(e);
                break;
            }
            case 4: {
                int p;
                cout << "Введите мощность двигателя (в л.с.): ";
                cin >> p;
                if (p <= 0)
                    throw InputErr("Мощность должна быть положительным числом");
                setPower(p);
                break;
            }
            case 5: {
                int t;
                cout << "Выберите тип местности:" << endl;
                cout << "1 — Городская" << endl;
                cout << "2 — Внедорожная" << endl;
                cout << "3 — Смешанная" << endl;
                cout << "4 — Спортивная" << endl;
                cin >> t;
                if (t < 1 || t > 4)
                    throw InputErr("Тип местности должен быть числом от 1 до 4");
                setTerrain(t);
                break;
            }
            case 6:
                cout << "Мотоцикл успешно изменён!" << endl;
                break;
            default:
                throw InputErr("Введите число от 1 до 6!");
        }
    } while (choice != 6);
}
