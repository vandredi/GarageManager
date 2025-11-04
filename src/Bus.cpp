#include <iostream>
#include "Vehicle.h"
#include "Bus.h"
#include "Exceptions.h"
using namespace std;

Bus::Bus() : Vehicle("Неизвестно", "Неизвестно"), seats(0), total(0), destination("Неизвестно") {
    cout << "Вызван конструктор Bus по умолчанию" << endl;
}

Bus::Bus(const string &brand, const string &model, int seats, int total,
         const string &destination) : Vehicle(brand, model), seats(seats), total(total), destination(destination) {
    cout << "Вызван конструктор Bus с параметрами" << endl;
}

Bus::Bus(const Bus &other) : Vehicle(other.brand, other.model), seats(other.seats), total(other.total),
                             destination(other.destination) { cout << "Вызван конструктор копирования Bus" << endl; }

Bus::~Bus() { cout << "Вызван деструктор Bus" << endl; }

Bus &Bus::operator=(const Bus &other) {
    if (this != &other) {
        Vehicle::operator=(other);
        seats = other.seats;
        total = other.total;
        destination = other.destination;
    }
    return *this;
}

Bus *Bus::clone() const { return new Bus(*this); }

void Bus::save(ofstream &out) const {
    if (!out) throw FileErr("Файл недоступен для записи");
    out << getType() << endl;
    out << brand << endl;
    out << model << endl;
    out << seats << endl;
    out << total << endl;
    out << destination << endl;
}

void Bus::load(ifstream &in) {
    string line;
    getline(in, line);
    Vehicle::setBrand(line);
    getline(in, line);
    Vehicle::setModel(line);
    getline(in, line);
    setSeats(stoi(line));
    getline(in, line);
    setTotal(stoi(line));
    getline(in, line);
    setDestination(line);
}

void Bus::print() const {
    cout << "Тип: " << getType() << endl;
    cout << "Марка: " << brand << endl;
    cout << "Модель: " << model << endl;
    cout << "Количество сидячих пассажирских мест: " << seats << endl;
    cout << "Общее количество пассажирских мест: " << total << endl;
    cout << "Конечный пункт: " << destination << endl;
    cout << endl << "------------------------" << endl;
}

string Bus::getType() const { return "Автобус"; }

int Bus::getSeats() const { return seats; }
int Bus::getTotal() const { return total; }
string Bus::getDestination() const { return destination; }
void Bus::setSeats(int s) { seats = s; }
void Bus::setTotal(int t) { total = t; }
void Bus::setDestination(string d) { destination = d; }

void Bus::input() {
    cout << "Введите марку: ";
    cin >> brand;
    cout << "Введите модель: ";
    cin >> model;
    cout << "Введите количество сидячих пассажирских мест: ";
    if (!(cin >> seats) || seats <= 0)
        throw InputErr("Количество сидячих мест должно быть положительным числом");
    cout << "Введите общее количество пассажирских мест: ";
    if (!(cin >> total) || total < seats)
        throw InputErr("Общее количество мест должно быть не меньше количества сидячих");
    cout << "Введите конечный пункт маршрута: ";
    cin >> destination;
    cout << "Автобус успешно создан!" << endl;
}

void Bus::edit() {
    int choice = 0;
    do {
        cout << "1 — Изменить марку (сейчас: " << Vehicle::getBrand() << ")" << endl;
        cout << "2 — Изменить модель (сейчас: " << Vehicle::getModel() << ")" << endl;
        cout << "3 — Изменить количество мест (сейчас: " << seats << ")" << endl;
        cout << "4 — Изменить общую вместимость (сейчас: " << total << ")" << endl;
        cout << "5 — Изменить направление (сейчас: " << destination << ")" << endl;
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
                int s;
                cout << "Введите количество пассажирских мест: ";
                cin >> s;
                if (s <= 0)
                    throw InputErr("Количество мест должно быть положительным числом");
                setSeats(s);
                break;
            }
            case 4: {
                int t;
                cout << "Введите общее количество пассажирских мест: ";
                cin >> t;
                if (t < seats)
                    throw InputErr("Общее количество мест должно быть не меньше количества сидячих");
                setTotal(t);
                break;
            }
            case 5: {
                string d;
                cout << "Введите новое направление: ";
                cin.ignore();
                getline(cin, d);
                if (d.empty())
                    throw InputErr("Направление не может быть пустым");
                setDestination(d);
                break;
            }
            case 6:
                cout << "Автобус успешно изменён!" << endl;
                break;
            default:
                throw InputErr("Введите число от 1 до 6!");
        }
    } while (choice != 6);
}
