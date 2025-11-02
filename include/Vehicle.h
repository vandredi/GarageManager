#ifndef GARAGEMANAGER_VEHICLE_H
#define GARAGEMANAGER_VEHICLE_H
#include <string>
#include <fstream>
class Vehicle {
    protected:
        std::string brand;
        std::string model;
    public:
        Vehicle(const std::string& brand = "Неизвестно", const std::string& model = "Неизвестно");
        virtual ~Vehicle();
        virtual void save(std::ofstream& out) const = 0;
        virtual void load(std::ifstream& in) = 0;
        virtual void print() const = 0;
        virtual std::string getType() const = 0;
        static Vehicle* createFromFile(std::ifstream& in);

};


#endif //GARAGEMANAGER_VEHICLE_H