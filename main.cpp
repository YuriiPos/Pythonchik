#include <iostream>

using namespace std;

class Date {
public:
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
};

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
    void AddEvent(const Date& date, const string& event);
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

    /* ??? */ Find(const Date& date) const;

    void Print() const;
};

/*
- добавление события:	Add Дата Событие
- удаление события:	Del Дата Событие
- удаление всех событий за конкретную дату:	Del Дата
- поиск событий за конкретную дату:	Find Дата
- печать всех событий за все даты:	Print
 */

enum class Type {
    ADD,
    DEL,
    FIND,
    PRINT
};

int main() {
    Database db;
    string command;
    Type t;
    while (getline(cin, command)) {
        // Считай команды с потока ввода и обработай каждую
        switch (t) {
            case Type::ADD: {
        db.AddEvent();
                break;
            }
            case Type::DEL: {
                db.DeleteDate();
                db.DeleteEvent();
                break;
            }
            case Type::FIND: {
                db.Find();
                break;
            }

            case Type::PRINT: {
                db.Print();
                break;
            }
        }
    }

    return 0;
}
