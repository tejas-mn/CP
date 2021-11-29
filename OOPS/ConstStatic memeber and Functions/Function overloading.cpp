#include<iostream>
#define pi 3.1428

using namespace std;


class A
{
    public:
            int Area(int length,int breadth)
            {
                return length*breadth;
            }
            float Area(float radius)
            {
                return pi*radius*radius;
            }

            float Area(int length ,int breadth, int height)
            {
                return length*breadth*height;
            }
};

int main()
{
    A a;

    cout<<"Area of circle: "<<a.Area(2.5)<<endl;
    cout<<"Area of Rectangle: "<<a.Area(2,3)<<endl;
    cout<<"Area of Cuboid: "<<a.Area(2,2,2)<<endl;

    return 0;
}
