#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Box {
private:
    unsigned int length, width, height;
public:
    Box() {
        length = 0;
        width = 0;
        height = 0;
    }
    Box(unsigned int newLength, unsigned int newWidth, unsigned int newHeight) {
        length = newLength;
        width = newWidth;
        height = newHeight;
    }
    Box (const Box &p) {
        length = p.length;
        width = p.width;
        height = p.height;
    }
    unsigned getVolume() {
        return this->height * this->length * this->width;
    }

    Box& operator=(const Box &p) {
        length = p.length;
        width = p.width;
        height = p.height;
        return *this;
    }
    void scale(unsigned scaleValue) {
        length *= scaleValue;
        width *= scaleValue;
        height *= scaleValue;
    }

    Box& operator*(int scale){
        length *= scale;
        width *= scale;
        height *= scale;
        return *this;
    }
    bool isBigger(const Box &p) {
        if (length*width*height > p.length*p.width*p.height) return true;
        return false;
    }
    bool isSmaller(const Box &p) {
        if (length*width*height < p.length*p.width*p.height) return true;
        return false;
    }
    bool operator==(const Box &p) {
        vector<unsigned int> a; a.push_back(length); a.push_back(width); a.push_back(height);
        vector<unsigned int> b; b.push_back(p.length); b.push_back(p.width); b.push_back(p.height);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a[0] == b[0] and a[1] == b[1] and a[2] == b[2]) return true;
        else return false;
    }
};

class Cube {
private:
    unsigned int a;
public:
    Cube() {
        a = 0;
    }
    Cube(unsigned int length) {
        a = length;
    }
    Cube(const Cube &p){
        a = p.a;
    }
    int getLength() {
        return a;
    }
    operator Box() const{
        return {a, a, a};
    };
};

int main()
{
    Cube newCube = Cube(5);
    Box newBox = newCube;

    cout << endl;

    Box Box1 = Box(20, 10, 4);
    Box Box2 = Box(10, 5, 2);
    Box2 * 2;
    Box2.getVolume();
    cout << Box2.isBigger(Box1) << endl;
    cout << Box2.isSmaller(Box1) << endl;
    cout << (Box1 == Box2) << endl;

    Cube cube(5);
    Box box = cube;
    cout << box.getVolume() << endl;
    return 0;
}
