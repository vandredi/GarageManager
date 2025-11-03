#include <iostream>
#include <Vehicle.h>
#include <Bus.h>

#include "Exceptions.h"
using namespace std;

Bus::Bus(): Vehicle("Неизвестно", "Неизвестно"), seats(0), total(0), destination("Неизвестно") {cout << "Вызван конструктор Bus по умолчанию" << endl;}
Bus::Bus(const string& brand, const string& model,int seats, int total,const string& destination): Vehicle(brand, model), seats(seats), total(total), destination(destination) {cout << "Вызван конструктор Bus с параметрами" << endl;}
Bus::Bus(const Bus& other) : Vehicle(other.brand, other.model), seats(other.seats), total(other.total), destination(other.destination) {cout << "Вызван конструктор копирования Bus" << endl;}
Bus::~Bus(){ cout << "Вызван деструктор Bus" << endl;}

Bus* Bus::clone() const { return new Bus(*this);}
void Bus::save(ofstream& out) const {
    if (!out) throw FileErr("Файл недоступен для записи");
    out << getType() << " " << brand << " " << model << " " << seats << " " << total << " " << destination << endl;
}
void Bus::load(ifstream& in) {
    if (!in) throw FileErr("Файл недоступен для чтения");
    in >> brand >> model >> seats >> total >> destination;
}
void Bus::print() const {
    cout << "Тип: " << getType() << endl;
    cout << "Марка: " << brand << endl;
    cout << "Модель: " << model << endl;
    cout << "Количество сидячих пассажирских мест: " << seats  << endl;
    cout << "Общее количество пассажирских мест: " << total <<  endl;
    cout << "Конечный пункт: "<< destination << endl;
    cout << endl << "------------------------" << endl;
}
string Bus::getType() const {return "Bus";}

int Bus::getSeats() const {return seats;}
int Bus::getTotal() const {return total;}
string Bus::getDestination() const {return destination;}
void Bus::setSeats(int s) {seats = s;}
void Bus::setTotal(int t) {total = t;}
void Bus::setDestination(string d) {destination = d;}