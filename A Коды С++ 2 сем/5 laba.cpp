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
        cout << "\n  �������: " << name;
        cout << "\n  ������������� �����������: " << prois;

    }
    virtual void getdata() {
        cout << "\n  ������� ������� ��������� �����������: "; cin >> name;
        cout << "\n  ������������� �����������: "; cin >> prois;
    }
    virtual void get_name() const {
        cout << "\n����������\n";
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
        cout << "\n�������\n";
    }

    void getdata() {
        instrument::getdata();

        cout << "\n  ���������� ���������: "; cin >> amount;
    }
    void putdata() const {
        instrument::putdata();

        cout << "\n  ���������� �����: " << amount;
    }
    void show() {
        get_name();
        putdata();
    }
};

class String : public instrument {
private:
    int amount; // ���-�� �����

public:
    void getdata() {
        instrument::getdata();

        cout << "\n  ���������� �����: "; cin >> amount;
    }
    void putdata() const {
        instrument::putdata();

        cout << "\n  ���������� �����: " << amount;
    }
    void get_name() const {
        cout << "\n��������\n";
    }
    void show() {
        get_name();
        putdata();
    }
};


class Horn : public instrument {
private:
    char data[LEN]; // ����� ������

public:
    void getdata() {
        instrument::getdata();
        cout << "\n  ����� ������ �������� �����������: "; cin >> data;
    }

    void putdata() const {
        instrument::putdata();
        cout << "\n  ����� ������ �������� �����������: " << data;
    }

    void get_name() const {
        cout << "\n�������\n";
    }
    void show() {
        get_name();
        putdata();
    }

};




int main() {
    system("chcp 1251");
    system("cls");
    //������� ������ �������� 
    instrument* o[4];
    o[0] = new Horn();
    o[1] = new String();
    o[2] = new Kick();
    o[3] = new instrument();
    for (int i = 0; i < 4; i++) {
        o[i]->getdata();
    }

    //������ ������ ��������
    for (int i = 0; i < 4; i++) {
        o[i]->show();
    }
    //  o[0]->get_name();
    //  o[1]->get_name();
    //  o[2]->get_name();
    //  o[3]->get_name();
}