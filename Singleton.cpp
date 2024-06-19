#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
	//1. make the instance static- so that only one instance exists per class
	//make instance private so that it cannot be created publically by any object
	static Singleton* ptr;
	// mutex to make thread safe to be used in getter/instantiation function, one mutex is needed per class
	static mutex mtx;
	
	//2. make costructor and destructor as private
	Singleton(){};
	~Singleton(){};
	//3. delete copy constructor and assignment constructor
	Singleton(Singleton &other) = delete;	 
	void operator = (const Singleton&) = delete;
	
	public:
	//4. create a public static getter function that can be accessesed from anywhere without creating the object of the class
	static Singleton* getPtr()
	{
		if(ptr == nullptr)
		{
			mtx.lock();
			if(ptr == nullptr)
			{
				//create instance
				ptr = new Singleton();			
			}
			mtx.unlock();
		}
		return ptr;			
	}

}

//data type class::variable-name = initial value
Singleton *Singleton::ptr = nullptr;
mutex Singleton::mtx;

int main()
{
	//to instantiate the static member pointer
	//data-type variable-name = class-name::function-name
	Singleton* ptr1 = Singleton::getPtr();
	
	ptr1->getPtr();
		
	return 0;	
}
