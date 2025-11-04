#ifndef GARAGEMANAGER_EXCEPTIONS_H
#define GARAGEMANAGER_EXCEPTIONS_H
#include <stdexcept>
#include <string>

class FileErr : public std::runtime_error {
public:
    explicit FileErr(const std::string &message);
};

class InputErr : public std::runtime_error {
public:
    explicit InputErr(const std::string &message);
};

class KeeperErr : public std::runtime_error {
public:
    explicit KeeperErr(const std::string &message);
};
#endif //GARAGEMANAGER_EXCEPTIONS_H
