#include <iostream>
using namespace std;

//Factory creates products
// abstract product class
class vehicle
{	
	public:
    int wheels;
	virtual int cost() = 0;
};

// concrete product class
class bike : public vehicle
{	
	public:
	int cost() override{	
		wheels = 2;
		return 100;
	}

};

class car : public vehicle
{
	public:
	int cost() override{
		wheels = 4;
		return 200;
	}
};

class truck : public vehicle
{
	public:
	int cost() override{
		wheels = 6;
		return 300;
	}
};

// abstract creator class
class vehicleFactory{
	public:
	virtual vehicle* createVehicle() = 0;		
};

// concrete creator class
class bikeFactory : public vehicleFactory{
	public:
	 vehicle* createVehicle() override{
		return new bike();
	}
};

class carFactory : public vehicleFactory{
	public:
	 vehicle* createVehicle() override{
		return new car();
	}
};
    
class truckFactory : public vehicleFactory{
	public:
	 vehicle* createVehicle() override{
		return new truck();
	}    
};

    
int main()
{
	vehicleFactory*  bFactory = new bikeFactory();
	vehicle* bik = bFactory->createVehicle();
	
	cout << "bike cost = " << bik->cost() << " " << bik->wheels << endl;
	
    vehicleFactory*  cFactory = new carFactory();
	vehicle* c = cFactory->createVehicle();
	
	cout << "car cost = " << c->cost() << " " << c->wheels << endl;
    
    vehicleFactory*  tFactory = new truckFactory();
	vehicle* t = tFactory->createVehicle();
	
	cout << "truck cost = " << t->cost() << " " << t->wheels << endl;
	return 0;
}