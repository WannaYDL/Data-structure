#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout<<"A()"<<endl;
	}
	~A()
	{
	    cout<<"~A"<<endl;
	}

public:
	int pub;
protected:
	int pro;
private:
	int pri;
};

class B: public A
{
public:

	B()
	{
		cout<<"B()"<<endl;
	}
	~B()
	{
	    cout<<"~B"<<endl;
	}


};
class C{
public:
    C(){
        cout<<"C()"<<endl;
    }
    ~C(){
        cout<<"~C"<<endl;}
        };
int main()
{
    B a;
    C b;
    return 0;
}



