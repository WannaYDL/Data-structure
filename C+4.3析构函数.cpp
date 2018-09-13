//4.3.cpp
#include<iostream>
using namespace std;
const float PI=3.141593;
const float F_PRICE=35;
const float C_PRICE=20;
class Circle{
public:
    Circle(float r);
    float c_l();
    float c_area();
private:
    float radius;
};
//类的实现
//构造函数初始化数据成员radius
Circle::Circle(float r) {
    radius=r;
    }
//计算圆的周长
float Circle::c_l() {
    return 2*PI*radius;
    }
    //计算圆的面积
float Circle::c_area() {
    return PI*radius*radius;
    }
    //主函数实现
int main()
{
    float radius;
    cout<<"Enter the radius of the pool: "; //提示用户输入半径
    cin>>radius;
    Circle pool(radius);  //泳池边界对象
    Circle poolR(radius+3);  //栅栏对象
    //计算栅栏的造价并输出
    float fenceCost=poolR.c_l()*F_PRICE;
    cout<<"Fencing Cost is $"<<fenceCost<<endl;
    //计算过道造价并输出
    float conCost=(pool.c_area()-poolR.c_area())*C_PRICE;
    cout<<"Concrete Cost is $"<<conCost<<endl;

    return 0;
}
