#include <iostream>

class Triangle{
    private:
        double totalAngle, angleA, angleB, angleC;
    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
        void typeT(double A, double B, double C);
};

float areaT(float b, float h);
float periT(float a, float b, float c);

int main(){
    Triangle set1(40, 30, 110);
    if(set1.validateTriangle()){
        std::cout << "The shape is a valid triangle.\n";
    }
    else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }
    std::cout << "Area: " << areaT(20,10) << std::endl;
    std::cout << "Perimeter: " << periT(6,7,8) << std::endl;
    Triangle angles(0,0,0);
    angles.typeT(30,40,10);
    return 0;
}

Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}
void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}
const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
}
void Triangle::typeT(double A, double B, double C){
    if ( C*C < A*A + B*B) {
        std::cout << "Type: Acute Triangle";
    }
    else if (C*C == A*A + B*B) {
        std::cout << "Type: Right Triangle";
    }
    else if (C*C > A*A + B*B) {
        std::cout << "Type: Obtuse Triangle";
    }
    else {
        std::cout << "Type: Others";
    }
}
float areaT(float b, float h) {
    return 0.5 * (b * h);
}
float periT(float a, float b, float c) {
    return a + b + c;
}
