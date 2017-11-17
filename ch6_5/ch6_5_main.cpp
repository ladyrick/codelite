#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class Shape {
public:
    virtual void ShowArea() = 0;
};

class Circle : public Shape {
    double r;
public:
    explicit Circle(double r) : r(r) {}

    void ShowArea() override {
        cout << "circle: " << 3.14159265 * r * r << endl;
    }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}

    void ShowArea() override {
        cout << "rectangle: " << w * h << endl;
    }
};

class AreaCollect {
    vector<Shape *> v;
public:
    void Add(Shape *pshape) {
        v.push_back(pshape);
    }

    void ShowEachArea() {
        for_each(v.begin(), v.end(), mem_fun(Shape::ShowArea));
    }
};

int main() {
    AreaCollect contain;
    Shape *pc = new Circle(10.0);
    Shape *pr = new Rectangle(10, 10);
    contain.Add(pc);
    contain.Add(pr);
    contain.ShowEachArea();
    return 0;
}
