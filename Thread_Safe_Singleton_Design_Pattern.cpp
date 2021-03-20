#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex m1;

class Logger{
    public:
        static Logger*getInstance()
        {
            if(instance_ == nullptr)
            {
                std::lock_guard<mutex> lock(m1);
                if(instance_ == nullptr)
                {
                    instance_ = new Logger();
                    cout << "Creating Logger object for the first time." << endl;
                }
                else
                {
                   cout << "Logger object already initiated so we are returning the same object." << endl; 
                }
            }
            return instance_;
        }
        void PrintLog(string& str)
        {
            cout << str << endl;
        }
       static  void LogWork(string& str)
        {
            Logger::getInstance()->PrintLog(str);
        }
    private:
        static Logger* instance_;
        Logger()
        {
            cout << "Logger object initiated through default constructor." << endl;
        }
        Logger(const Logger& L1)
        {
            cout << "Logger object initiated through copy constructor." << endl;
        }
        Logger& operator = (const Logger& L1)
        {
            if( &L1 == this )
            {
                cout << "Logger object already initiated so we are returning the same object." << endl;
                return *this;
            }
            instance_ = L1.instance_;
            return *this;
        }

};
Logger* Logger::instance_ = nullptr;
int main()
{
    std::string str1("Thread1 : I am Singleton Design Pattern.");
    std::string str2("Thread2 : I am Double Check Lock Singleton Design Pattern.");
    thread t1(&Logger::LogWork,std::ref(str1));
    thread t2(&Logger::LogWork,std::ref(str2));
    
    t1.join();
    t2.join();

    return 0;
}