#include <iostream>
#include <Vehicle.h>
#include <Car.h>
#include "Exceptions.h"

using namespace std;

Car::Car(): Vehicle("Неизвестно", "Неизвестно"), engine(0.0), color(0), transmission(0) {cout << "Вызван конструктор Car по умолчанию" << endl;}
Car::Car(const string& brand, const string& model,float engine, int color, int transmission): Vehicle(brand, model), engine(engine), color(color), transmission(transmission) {cout << "Вызван конструктор Car с параметрами" << endl;}
Car::Car(const Car& other) : Vehicle(other.brand, other.model), engine(other.engine), color(other.color), transmission(other.transmission) {cout << "Вызван конструктор копирования Car" << endl;}
Car::~Car(){ cout << "Вызван деструктор Car" << endl;}


Car* Car::clone() const { return new Car(*this);}
void Car::save(ofstream& out) const {
    if (!out) throw FileErr("Файл недоступен для записи");
    out << getType() << " " << brand << " " << model << " " << engine << " " << color << " " << transmission << endl;
}
void Car::load(ifstream& in) {
    if (!in) throw FileErr("Файл недоступен для чтения");
    in >> brand >> model >> engine >> color >> transmission;
}
void Car::print() const {
    cout << "Тип: " << getType() << endl;
    cout << "Марка: " << brand << endl;
    cout << "Модель: " << model << endl;
    cout << "Объем двигателя: " << engine << " л" << endl;
    cout << "Цвет: " << printColor() << endl;
    cout << "Тип КПП: "<< printTransmission() << endl;
    cout << endl << "------------------------" << endl;
}
string Car::getType() const {return "Car";}

float Car::getEngine() const {return engine;}
int Car::getColor() const {return color;}
int Car::getTransmission() const {return transmission;}
void Car::setEngine(float e) { engine = e;}
void Car::setColor(int c) { color = c;}
void Car::setTransmission(int t) { transmission = t;}

string Car::printColor() const{
    switch (color) {
        case 1: return "Красный";
        case 2: return "Синий";
        case 3: return "Чёрный";
        case 4: return "Белый";
        case 5: return "Жёлтый";
        default: return "Неизвестно";
    }
}
string Car::printTransmission() const{
    switch (transmission) {
        case 1: return "Механическая";
        case 2: return "Автоматическая";
        case 3: return "Вариатор";
        case 4: return "Роботизированная";
        default: return "Неизвестно";
    }
}