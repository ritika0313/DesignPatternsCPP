#include <iostream>
using namespace std;

// abstract product class
class vehicle
{	
	public:
 	virtual int cost() = 0;
};

// concrete product class
class amBike : public vehicle
{	
	public:
	int cost() override{		
		return 100;
	}

};

class amCar : public vehicle
{
	public:
	int cost() override{
		return 200;
	}
};

class euBike : public vehicle
{	
	public:
	int cost() override{		
		return 600;
	}

};

class euCar : public vehicle
{
	public:
	int cost() override{
		return 700;
	}
};
/*class truck : public vehicle
{
	public:
	int cost() override{
		return 300;
	}
};*/

// abstract creator (Producer) class
class vehicleProducer
{
	public:
	virtual vehicle* createBike() = 0;
	virtual vehicle* createCar() = 0;
};

// concrete creator (Factory) classes
class americaFactory : public vehicleProducer
{
	public:
	vehicle* createBike() override{
		new amBike;
	}
	
	vehicle* createCar() override{
		new amCar;
	}
};

class europeFactorty : public vehicleProducer
{
	public:
	vehicle* createBike() override{
		new euBike;
	}
	
	vehicle* createCar() override{
		new euCar;
	}
};
    
int main()
{
	vehicleProducer*  amFactory = new americaFactory();
	vehicle* amBik = amFactory->createBike();
	
	cout << "America bike cost = " << amBik->cost() << endl;
	
    vehicleFactory*  euFactory = new europeFactory();
	vehicle* c = euFactory->createCar();
	
	cout << "car cost = " << c->cost() << endl;
    
    /*vehicleFactory*  tFactory = new truckFactory();
	vehicle* t = tFactory->createVehicle();
	
	cout << "truck cost = " << t->cost() << " " << endl; */
	return 0;
}

