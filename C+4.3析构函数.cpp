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
//���ʵ��
//���캯����ʼ�����ݳ�Աradius
Circle::Circle(float r) {
    radius=r;
    }
//����Բ���ܳ�
float Circle::c_l() {
    return 2*PI*radius;
    }
    //����Բ�����
float Circle::c_area() {
    return PI*radius*radius;
    }
    //������ʵ��
int main()
{
    float radius;
    cout<<"Enter the radius of the pool: "; //��ʾ�û�����뾶
    cin>>radius;
    Circle pool(radius);  //Ӿ�ر߽����
    Circle poolR(radius+3);  //դ������
    //����դ������۲����
    float fenceCost=poolR.c_l()*F_PRICE;
    cout<<"Fencing Cost is $"<<fenceCost<<endl;
    //���������۲����
    float conCost=(pool.c_area()-poolR.c_area())*C_PRICE;
    cout<<"Concrete Cost is $"<<conCost<<endl;

    return 0;
}
