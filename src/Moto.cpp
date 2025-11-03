#include <iostream>
#include <Vehicle.h>
#include <Moto.h>
#include "Exceptions.h"

using namespace std;

Moto::Moto(): Vehicle("Неизвестно", "Неизвестно"), engine(0.0), power(0), terrain(0) {cout << "Вызван конструктор Moto по умолчанию" << endl;}
Moto::Moto(const string& brand, const string& model,float engine, float power, int terrain): Vehicle(brand, model), engine(engine), power(power), terrain(terrain) {cout << "Вызван конструктор Moto с параметрами" << endl;}
Moto::Moto(const Moto& other) : Vehicle(other.brand, other.model), engine(other.engine), power(other.power), terrain(other.terrain) {cout << "Вызван конструктор копирования Moto" << endl;}
Moto::~Moto(){ cout << "Вызван деструктор Moto" << endl;}

Moto* Moto::clone() const { return new Moto(*this);}
void Moto::save(ofstream& out) const {
    if (!out) throw FileErr("Файл недоступен для записи");
    out << getType() << " " << brand << " " << model << " " << engine << " " << power << " " << terrain << endl;
}
void Moto::load(ifstream& in) {
    if (!in) throw FileErr("Файл недоступен для чтения");
    in >> brand >> model >> engine >> power >> terrain;
}
void Moto::print() const {
    cout << "Тип: " << getType() << endl;
    cout << "Марка: " << brand << endl;
    cout << "Модель: " << model << endl;
    cout << "Объем двигателя: " << engine << " см^3" << endl;
    cout << "Мощность двигателя: " << power << " л.с." << endl;
    cout << "Тип местности: "<< printTerrain() << endl;
    cout << endl << "------------------------" << endl;
}
string Moto::getType() const {return "Moto";}

float Moto::getEngine() const {return engine;}
float Moto::getPower() const {return power;}
int Moto::getTerrain() const {return terrain;}
void Moto::setEngine(float e) {engine = e;}
void Moto::setPower(float p) {power = p;}
void Moto::setTerrain(int t) {terrain = t;}

string Moto::printTerrain() const{
    switch (terrain) {
        case 1: return  "Городская";
        case 2: return "Внедорожная";
        case 3: return "Смешанная";
        default: return "Неизвестно";
    }
}
