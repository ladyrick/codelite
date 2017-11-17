#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

typedef void (*pFunc)();

class Func {
public:
    static vector<pFunc> vfunc;

    Func() {
    }

    Func(pFunc f) {
        vfunc.push_back(f);
    }
};

vector<pFunc> Func::vfunc;
#define REG(func) Func f_##func(func)

void e1() {
    ofstream fout("test.txt");
    for (int i = 0; i < 10; i++) {
        fout << i << endl;
        cout << i << endl;
    }
    fout.close();
}
//REG(e1);

void e2() {
    ifstream fin("test.txt");
    if (!fin.good()) {
        cout << "fin not good" << endl;
        return;
    }
    char Buf[100];
    while (fin.getline(Buf, 100)) {
        cout << Buf << endl;
    }
    fin.close();
}
//REG(e2);

struct STU {
    char str[10];
    int grade;
};

void e3() {
    STU stu1 = {"Alice", 100};
    STU stu2 = {"Bob", 150};
    ofstream fout("binary.txt", ios::binary);
    fout.write((const char *) &stu1, sizeof(STU));
    fout.write((const char *) &stu2, sizeof(STU));
    fout.close();
}
//REG(e3);

void e4() {
    STU stu1, stu2;
    ifstream fin("binary.txt", ios::binary);
    fin.read((char *) &stu1, sizeof(STU));
    fin.read((char *) &stu2, sizeof(STU));
    cout << stu1.str << '\t' << stu1.grade << endl;
    cout << stu2.str << '\t' << stu2.grade << endl;
    fin.close();
}
//REG(e4);

void e5() {
    ifstream fin("test.txt");
    if (fin.good()) {
        cout << fin.rdbuf();
    } else {
        cout << "File doesn't exist." << endl;
    }
    fin.close();
}
//REG(e5);

void e6() {
    fstream fio;
    fio.open("seek.txt", ios::in | ios::out | ios::trunc);
    fio << "Hello";
    fio.seekp(0, ios::beg);
    fio << "h";
    fio.seekg(1, ios::cur);
    cout << fio.rdbuf() << endl;
    fio.close();
}
//REG(e6);

void e7() {
    int n;
    float f;
    string str = "123 456.789";

    istringstream sin(str);
    sin >> n;
    sin >> f;
    char strout[100];
    ostringstream sout(strout);
    sout << f << ' ' << n << endl;
    cout << sout.str();
}
//REG(e7);

void e8() {
    stringstream sio;
    sio << 123 << "asd" << '$' << 3.14 << endl;
    string str;
    sio >> str;
    cout << str << endl;
    sio.seekp(0, ios::beg);
    sio << 456;
    cout << sio.str();
    sio.seekg(-3, ios::end);
    sio >> str;
    cout << str << endl;
    ostringstream sout("asd");
    sout.seekp(-2, ios::end);
    sout << str;
    cout << sout.str() << endl;
    cout << "rdbuf:" << sout.rdbuf() << endl;
    cout.clear();
    cout << sout.str() << endl;
}
//REG(e8);

void e9() {
    cout << "1234567890";
    cout.seekp(0, ios::beg);
    cout.clear();
    cout << "abc";
}
//REG(e9);

istream &operator>>(istream &is, STU &stu) {
    is >> stu.str >> stu.grade;
    return is;
}

ostream &operator<<(ostream &os, STU &stu) {
    os.setf(ios::left);
    os << "name: " << setw(10) << stu.str << "grade: " << stu.grade << endl;
    os.unsetf(ios::left);
    return os;
}

ostream &operator<<(ostream &os, const STU &stu) {
    os.setf(ios::left);
    os << "const name: " << setw(10) << stu.str << "grade: " << stu.grade << endl;
    os.unsetf(ios::left);
    return os;
}

void constShow(const STU stu) {
    cout << stu;
}

void e10() {
    string data = "Alice 100 Bob 150";
    STU stu1, stu2;
    istringstream sin(data);
    sin >> stu1 >> stu2;
    cout << stu1 << stu2;
    constShow(stu1);
    constShow(stu2);
}

REG(e10);

int main(int argc, char *argv[]) {
    vector<pFunc>::iterator it;
    vector<pFunc> &f = Func::vfunc;
    for (it = f.begin(); it != f.end(); it++) {
        (*it)();
    }
    return 0;
}
