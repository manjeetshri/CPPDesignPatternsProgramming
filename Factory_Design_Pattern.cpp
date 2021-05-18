#include<iostream>
using namespace std;

class ToyFactory
{
    public:
    virtual string getToy()=0;
    virtual void setToy()=0;
};

class Car:public ToyFactory
{
    string toyname;
public:
    string getToy()
    {
        cout<<"In getToy() : "<<toyname<<endl;
    }
    void setToy()
    {
        toyname = "Car";
        cout<<"In Car::setToy()"<<endl;
    }
};

class Doll:public ToyFactory
{
    string toyname;
public:
    string getToy()
    {
        cout<<"In getToy() : "<<toyname<<endl;
    }
    void setToy()
    {
        toyname = "Doll";
        cout<<"In Doll::setToy()"<<endl;
    }
};

class Toy
{

public:
    static ToyFactory *createToy(int ToyType)
    {
        ToyFactory* t = NULL;

        switch(ToyType)
        {
        case 1:
                t = new Car();
                break;
        case 2:
                t = new Doll();
                break;
        }
        return t;
    }
};
int main()
{
    int Toytype;
    cout<<"Welcome to ToyFactory.Press 1 to Car or 2 to Doll."<<endl;
    //while(1)
    //{
        cout<<"Enter Toy type : "<<endl;
        cin >> Toytype;

        ToyFactory *t1 = Toy::createToy(Toytype);
        if(t1)
        {
            t1->setToy();
            t1->getToy();
            delete t1;
        }
        else{
            cout<<"Invalid Toy type."<<endl;
            //break;
        }
    //}
    return 0;
}
