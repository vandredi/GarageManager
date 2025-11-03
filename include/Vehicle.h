#ifndef GARAGEMANAGER_VEHICLE_H
#define GARAGEMANAGER_VEHICLE_H
#include <string>
#include <fstream>
class Vehicle {
    protected:
        std::string brand;
        std::string model;
    public:
        Vehicle();
        Vehicle(const std::string& brand, const std::string& model);
        Vehicle(const Vehicle& other);
        virtual ~Vehicle();

        virtual Vehicle* clone() const = 0;
        virtual void save(std::ofstream& out) const = 0;
        virtual void load(std::ifstream& in) = 0;
        virtual void print() const = 0;
        virtual std::string getType() const = 0;

        std::string getBrand() const;
        std::string getModel() const;
        void setBrand(const std::string& b);
        void setModel(const std::string& m);
        static Vehicle* createFromFile(std::ifstream& in);

};


#endif //GARAGEMANAGER_VEHICLE_H