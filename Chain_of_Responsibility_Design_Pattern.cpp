#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define CURRENCY_DISPENSED  1
#define INVALID_REQUEST     0

class IRequest{
    protected:
        int money_Request;
        IRequest*pNext;
    public:

        virtual void setNext(IRequest*pNext1)=0;
        virtual int run(int mR)
        {
            return INVALID_REQUEST;
        }
};


class Request100: public IRequest
{

    public:
        Request100()
        {
            money_Request=100;
            pNext=nullptr;
        }

        void setNext(IRequest*pNext1)
        {
         this->pNext = pNext1;   
        }
        
        int run(int mR)
        {
            if(money_Request == mR)
            {
                cout << "Right slot.So dispensing the money." << endl;
                return CURRENCY_DISPENSED;
            }
            else
            {
                cout << "Not in the Right slot.So moving to next slot...." << endl;
                if(pNext != nullptr)
                    pNext->run(mR);
                return INVALID_REQUEST;                
            }
        }

};

class Request200: public IRequest
{

    public:
        Request200()
        {
            money_Request=200;
            pNext=nullptr;            
        }

        void setNext(IRequest*pNext1)
        {
         this->pNext = pNext1;   
        }
        
        int run(int mR)
        {
            if(money_Request == mR)
            {
                cout << "Right slot.So dispensing the money." << endl;
                return CURRENCY_DISPENSED;
            }
            else
            {
                cout << "Not in the Right slot.So moving to next slot...." << endl;
                if(pNext != nullptr)
                    pNext->run(mR);
                return INVALID_REQUEST;                
            }
        }

};

class Request500: public IRequest
{

    public:
        Request500()
        {
            money_Request=500;
            pNext=nullptr;            
        }

        void setNext(IRequest*pNext1)
        {
         this->pNext = pNext1;   
        }
        
        int run(int mR)
        {
            if(money_Request == mR)
            {
                cout << "Right slot.So dispensing the money." << endl;
                return CURRENCY_DISPENSED;
            }
            else
            {
                cout << "Not in the Right slot.So moving to next slot...." << endl;
                if(pNext != nullptr)
                    pNext->run(mR);
                return INVALID_REQUEST;                
            }
        }

};

class Request2000: public IRequest
{

    public:
        Request2000()
        {
            money_Request=2000;
            pNext=nullptr;            
        }

        void setNext(IRequest*pNext1)
        {
         this->pNext = pNext1;   
        }
        
        int run(int mR)
        {
            if(money_Request == mR)
            {
                cout << "Right slot.So dispensing the money." << endl;
                return CURRENCY_DISPENSED;
            }
            else
            {
                cout << "Not in the Right slot.So moving to next slot...." << endl;
                if(pNext != nullptr)
                    pNext->run(mR);
                return INVALID_REQUEST;                
            }
        }

};
int main()
{
    //Initializing slots of currency in an ATM
    IRequest *p1 = new Request100;
    IRequest *p2 = new Request200;
    IRequest *p3 = new Request500;
    IRequest *p4 = new Request2000;
    
    //Creating chain of responsibility between slots
    p1->setNext(p2);
    p2->setNext(p3);
    p3->setNext(p4);
    
    //Raising currency dispense request
   int moneydespense_ =  p1->run(3000);
   if(0 == moneydespense_)
    cout << "Invalid amount entered,only amount of 100,200,500 and 2000 can be dispensed. " <<endl;
    return 0;
}