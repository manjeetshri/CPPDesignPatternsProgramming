#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ICustomer{
    public:
        virtual void GetCustomerName()=0;
        virtual void GetAddress()=0;
        virtual void GetPayMethod()=0;
        virtual void update(float price)=0;
};

class IProduct{
    
    public:
        virtual void Attach(ICustomer*ptr)=0;
        virtual void Detach(ICustomer*ptr)=0;
        virtual void notify()=0;
        virtual void getName()=0;
        virtual void getSize()=0;
        virtual void getColour()=0;
};



class Product: public IProduct
{
    std::vector<ICustomer*>CustomerList;
    float price;
    public:
        void Attach(ICustomer* ptr)
        {
            CustomerList.push_back(ptr);  
        }
        void Detach(ICustomer* ptr)
        {
            CustomerList.erase(std::remove(CustomerList.begin(),CustomerList.end(),ptr),CustomerList.end());
        }
        void getName()
        {
            cout << "I am Product." << endl;
        }
        void getSize()
        {
            cout << "I am 32 waist Jeans." << endl;
        }
        void getColour()
        {
            cout << "I am a Blue colour Jeans." << endl;
        }
        void setPrice(float settingprice)
        {
            price = settingprice;
        }
        void getPrice() const
        {
            cout << "Product price is "<< price << "." << endl;
        }
        void notify()
        {
            for(auto& i : CustomerList)
                i->update(price);
        }
        void changePrice(float newprice)
        {
            price = newprice;
            notify();
        }
};

class Customer: public ICustomer
{
    public:
        void GetCustomerName()
        {
            cout << "I am Customer." << endl;
        }
        void GetAddress()
        {
            cout << "I live in Pune." << endl;
        }
        void GetPayMethod()
        {
            cout << "I pay through UPI." << endl;
        }
        void update(float price)
        {
            cout << "Price is changed to " << price <<"."<< endl;
        }
        
};


int main()
{
    Customer C1,C2,C3;
    Product P1;
    P1.Attach(&C1);
    P1.Attach(&C2);
    P1.setPrice(51.00);
    P1.getPrice();
    P1.changePrice(45.00);


    return 0;
}