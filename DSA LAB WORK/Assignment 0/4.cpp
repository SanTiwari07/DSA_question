#include<iostream>
using namespace std;

class complex{
    public:
    int real,img;
    complex(){}
    complex(int x , int y){
        real = x;
        img = y;
    }
    complex operator + (const complex &obj){
        complex result;
        result.img = img + obj.img;
        result.real = real + obj.real;

        return result;
    }
    complex operator - (const complex &obj){
        return complex(img - obj.img ,real - obj.real);
    }
    complex operator * (const complex &obj){
        return complex(img*obj.img, obj.real*real);
    }
    void display(){
        if(img < 0){
            cout<<real<<" - "<<-img<<"i"<<endl;
        }
        if(img > 0){
            cout<<real<<" + "<<img<<"i"<<endl;
        }
        
    }
};
int main(){
    complex c1(2,3);
    complex c2(5,6);

    complex c3 = c1+c2;

    c3.display();

    complex c4 = c1-c2;

    c4.display();

    complex c5 = c1*c2;

    c5.display();

    return 0;
}
