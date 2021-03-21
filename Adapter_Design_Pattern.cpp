#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class IndianCharger{

    public:
        IndianCharger(){ cout << "IndianCharger" <<endl;}
};

class USACharger{

    public:
        USACharger(){ cout << "USACharger" <<endl;}
        
};

class GermanCharger{

    public:
        GermanCharger(){ cout << "GermanCharger" <<endl;}
        
};
class ChargerAdapter: public IndianCharger,public USACharger,public GermanCharger
{
    public:
        
    ChargerAdapter(IndianCharger* ind, int type) 
    {
        cout << "I am ChargerAdapter" <<endl;
        switch(type)
        {
            case 1:
                USACharger();
                break;
            case 2:
                GermanCharger();
                break;
            default:
                cout << "Can't Support" <<endl; 
        }
    }
};

int main()
{
    IndianCharger IndCharger;
    int type;
    cout << "Enter type of charger need to be converted : ";
    cin >> type;
    if(type == 1)
        ChargerAdapter CAdapter(&IndCharger,1);
    else if(type == 2)
        ChargerAdapter CAdapter(&IndCharger,2);
    else 
        ChargerAdapter CAdapter(&IndCharger,type);
    return 0;
}