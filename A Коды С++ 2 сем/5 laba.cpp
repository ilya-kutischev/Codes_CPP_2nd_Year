#include <iostream>
using namespace std;

const int LEN = 80;
class instrument {
private:

    char name[LEN];
    char prois[LEN];

public:

    // instrument() {
    //     
    // };
    //
    virtual void putdata() const {
        cout << "\n  Фамилия: " << name;
        cout << "\n  Производитель инструмента: " << prois;

    }
    virtual void getdata() {
        cout << "\n  Введите фамилию владельца инструмента: "; cin >> name;
        cout << "\n  Производитель инструмента: "; cin >> prois;
    }
    virtual void get_name() const {
        cout << "\nИнструмент\n";
    }
    virtual void show() {
        get_name();
        putdata();
    }

};


class Kick :
    public instrument {
private:
    int amount;
public:
    void get_name() const {
        cout << "\nУдарный\n";
    }

    void getdata() {
        instrument::getdata();

        cout << "\n  Количество барабанов: "; cin >> amount;
    }
    void putdata() const {
        instrument::putdata();

        cout << "\n  Количество струн: " << amount;
    }
    void show() {
        get_name();
        putdata();
    }
};

class String : public instrument {
private:
    int amount; // кол-во струн

public:
    void getdata() {
        instrument::getdata();

        cout << "\n  Количество струн: "; cin >> amount;
    }
    void putdata() const {
        instrument::putdata();

        cout << "\n  Количество струн: " << amount;
    }
    void get_name() const {
        cout << "\nСтрунный\n";
    }
    void show() {
        get_name();
        putdata();
    }
};


class Horn : public instrument {
private:
    char data[LEN]; // длина канала

public:
    void getdata() {
        instrument::getdata();
        cout << "\n  Длина канала духового инструмента: "; cin >> data;
    }

    void putdata() const {
        instrument::putdata();
        cout << "\n  Длина канала духового инструмента: " << data;
    }

    void get_name() const {
        cout << "\nДуховой\n";
    }
    void show() {
        get_name();
        putdata();
    }

};




int main() {
    system("chcp 1251");
    system("cls");
    //Создать массив объектов 
    instrument* o[4];
    o[0] = new Horn();
    o[1] = new String();
    o[2] = new Kick();
    o[3] = new instrument();
    for (int i = 0; i < 4; i++) {
        o[i]->getdata();
    }

    //Выдать состав оркестра
    for (int i = 0; i < 4; i++) {
        o[i]->show();
    }
    //  o[0]->get_name();
    //  o[1]->get_name();
    //  o[2]->get_name();
    //  o[3]->get_name();
}