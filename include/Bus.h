#ifndef GARAGEMANAGER_BUS_H
#define GARAGEMANAGER_BUS_H
#include <string>
#include <fstream>
#include <Vehicle.h>
class Bus: public Vehicle {
    int seats;
    int total;
    std::string destination;
public:
    Bus();
    Bus(const std::string& brand, const std::string& model,
        int seats, int total,const std::string& destination);
    Bus(const Bus& other);
    virtual ~Bus();

    Bus* clone() const override;
    virtual void save(std::ofstream& out) const override;
    virtual void load(std::ifstream& in) override;
    virtual void print() const override;
    virtual std::string getType() const override;

    int getSeats() const;
    int getTotal() const;
    std::string getDestination() const;
    void setSeats(int s);
    void setTotal(int t);
    void setDestination(std::string d);
};
#endif //GARAGEMANAGER_BUS_H
