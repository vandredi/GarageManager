#include "exceptions.h"
using namespace std;

FileErr::FileErr(const string &message) : runtime_error("Ошибка файла: " + message) {
}

InputErr::InputErr(const string &message) : runtime_error("Неверный ввод: " + message) {
}

KeeperErr::KeeperErr(const string &message) : runtime_error("Ошибка при работе с контейнером: " + message) {
}
