#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define pi 3.141592653589

typedef struct
{
    float x, y;
}punct;
punct A, B, C, D;

void citire()
{
    ifstream f("date.in");
    f >> A.x >> A.y;
    f >> B.x >> B.y;
    f >> C.x >> C.y;
    f >> D.x >> D.y;
    f.close();
}

//distanta dintre doua puncte
float dist(punct A, punct B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

//produsul scalar
float dotProduct(punct A, punct B, punct C, punct D)
{
    float x1 = B.x - A.x;
    float y1 = B.y - A.y;
    float x2 = D.x - C.x;
    float y2 = D.y - C.y;
    return x1 * x2 + y1 * y2;
}

// cos (A) = <AB, AC> / ||AB||.||AC||
float cosinus(punct A, punct B, punct C)
{
    float prod = dotProduct(A, B, A, C);
    float dist1 = dist(A, B);
    float dist2 = dist(A, C);
    return acos(prod / (dist1 * dist2));
}

int main()
{

    citire();
    // cosA2+cosA4
    double A1 = cosinus(C,A,B);
    double A3 = cosinus(A,B,D);
    double A2 = cosinus(B, A, C);
    double A4 = cosinus(D, A, C);
    if((A1 + A2 + A3 + A4)- 360 <= 0.001)
    if(A2 + A4 - pi < 0.01 && A2 + A4 - pi > -0.01)
        cout<<"punctul D este pe cercul circumscris \n";
    else
        if(A2 + A4 > pi )
            cout<<"punctul D este in interiorul cercului circumscris \n";
         else
            cout<<"punctul D este in exteriorul cercului circumscris \n";

    else cout<<"Patrulaterul nu este convex\n";

    return 0;
}
