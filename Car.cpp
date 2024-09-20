#include<iostream>
using namespace std;

/*
when i start the car 
I want to check fuel after every second and reduce the fuel value by x amount
when fuel is insuffiecient engine will automatically stop.
or 
when i stop car i will stop to reduce x amount and stop not to check fuel after every second

*/

class Car {
    private:
    double fuelAmount;
    bool isCarStart = false;
    public:
    Car(){
        this->fuelAmount = 0;
        this->isCarStart = false;
    }
    Car(const double &amount){
        if(amount>0){
            this->fuelAmount = amount;
        }else{
            cout<<"fill valid value"<<endl;
        }
    }
    void startCar(){
        if( !isCarStart ){
            if( startEngine() ){
                cout<<"Car has started..."<<endl;
                isCarStart = true;
            }else{
                cout<<"Car has not started..."<<endl;
            }
        }else{
            cout<<"Car is already start..."<<endl;
        }
    }

    void stopCar(){
        if( isCarStart ){
            stopEngine();
        }else{
            cout<<"First start the car then press Stop Button..."<<endl;
        }
    }

    void driving(){
        cout<<"Car is driving..."<<endl;
    }

    private:
    bool checkFuel(){
        if(this->fuelAmount>0){
            cout<<"Car has "<<this->fuelAmount<<" liter fuel...."<<endl;
            return true;
        }else{
            cout<<"Car has not fuel..."<<endl;
            return false;
        }
    }
    bool startEngine(){
        if( checkFuel() ){
            cout<<"Engine start..."<<endl;
            return true;
        }else{
            cout<<"Engine has not started...."<<endl;
            return false;
        }
    }
    void stopEngine(){
        cout<<"Engine has stopped......"<<endl;
    }
};

int main(){

    Car Swift(50);

    Swift.stopCar();

    Swift.startCar();
    Swift.driving();
    Swift.startCar();

    Swift.stopCar();

    return 0;
}