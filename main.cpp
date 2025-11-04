#include <iostream>
#include <windows.h>
#include "include/Exceptions.h"
#include "include/Keeper.h"
#include "include/Car.h"
#include "include/Moto.h"
#include "include/Bus.h"
#include "include/Vehicle.h"
using namespace std;

void menu() {
    Keeper keeper;
    int choice, second_choice;
    cout << "Меню" << endl;
    cout << "1 – Добавление объекта" << endl;
    cout << "2 – Удаление объекта" << endl;
    cout << "3 – Изменение объекта" << endl;
    cout << "4 – Вывод объектов на экран" << endl;
    cout << "5 – Сохранение состояния гаража в файл" << endl;
    cout << "6 – Загрузка состояния гаража из файла" << endl;
    cout << "7 – Выход из программы" << endl;

    do {
        cout << endl;
        cout << "Выберите действие: ";
        if (!(cin >> choice)) throw InputErr("Некорректный ввод главного меню");

        switch (choice) {
            case 1: {
                cout << "Что вы хотите добавить в гараж?" << endl;
                cout << "1 – Автомобиль" << endl;
                cout << "2 – Мотоцикл" << endl;
                cout << "3 – Автобус" << endl;
                cout << "4 – Вернуться обратно" << endl;
                if (!(cin >> second_choice)) throw InputErr("Некорректный ввод при добавлении объекта");

                switch (second_choice) {
                    case 1: {
                        Car *car = new Car();
                        car->input();
                        keeper.append(car);
                        break;
                    }
                    case 2: {
                        Moto *moto = new Moto();
                        moto->input();
                        keeper.append(moto);
                        break;
                    }
                    case 3: {
                        Bus *bus = new Bus();
                        bus->input();
                        keeper.append(bus);
                        break;
                    }
                    case 4:
                        break;
                    default:
                        throw InputErr("Выберите число от 1 до 4 при добавлении объекта");
                }
                break;
            }

            case 2: {
                if (keeper.getSize() == 0) throw KeeperErr("Гараж пуст");
                keeper.printKeeper();
                cout << "Введите индекс объекта для удаления (начиная с 1): ";
                size_t index;
                if (!(cin >> index)) throw InputErr("Некорректный ввод индекса для удаления");
                if (index < 1 || index > keeper.getSize()) throw KeeperErr("Некорректный индекс!");
                keeper.remove(index - 1);
                break;
            }
            case 3: {
                if (keeper.getSize() == 0) throw KeeperErr("Гараж пуст");
                keeper.printKeeper();
                cout << "Введите индекс объекта для изменения (начиная с 1): ";
                size_t index;
                if (!(cin >> index)) throw InputErr("Некорректный ввод индекса для удаления");
                if (index < 1 || index > keeper.getSize()) throw KeeperErr("Некорректный индекс!");
                keeper.edit(index - 1);
                break;
            }
            case 4:
                if (keeper.getSize() == 0)
                    cout << "Гараж пуст." << endl;
                else
                    keeper.printKeeper();
                break;

            case 5: {
                string filename;
                cout << "Введите имя файла для сохранения из папки проекта: ";
                cin >> filename;
                keeper.saveKeeper(filename);
                break;
            }

            case 6: {
                string filename;
                cout << "Введите имя файла для загрузки из папки проекта: ";
                cin >> filename;
                keeper.loadKeeper(filename);
                break;
            }

            case 7:
                cout << "Выход..." << endl;
                break;

            default:
                throw InputErr("Введите число от 1 до 7!");
        }
    } while (choice != 7);
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    wcout.imbue(locale(""));
    menu();
    return 0;
}
