#include <iostream>
using namespace std;

// Client -> Director -> Builder -> Concrete Builder -> Product

//product class - there can be multiple variants of burger
class Burger
{
	private:

  	string sauce;
	string patty;
	string bread;

	public:

	void selectSauce(string Sauce)
	{
		sauce = Sauce;
	}
	void selectPatty(string Patty)
	{
		patty = Patty;
	}
	void selectBread(string Bread)
	{
		bread = Bread;
	}    
	void displayBurger()
	{
		cout << "burger ordered: " <<sauce <<" "<< patty <<" " <<bread << endl;
	}
	Burger()
	{
		cout<<"Burger is created"<< endl;
	}
};


class BurgerBuilder
{
	public:
	virtual void makeSauce(string sauce) = 0;
	virtual void makePatty(string patty) = 0;
	virtual void grillBread(string bread) = 0;
	virtual Burger getBurger() = 0;
};

class ConcreteBurgerBuilder : public BurgerBuilder
{
	Burger burger;
	
	public:
	void makeSauce(string Sauce)
	{
		burger.selectSauce(Sauce);
	}
	
	void makePatty(string Patty)
	{
		burger.selectPatty(Patty);
	}
	
	void grillBread(string Bread)
	{
		burger.selectBread(Bread);
	}
	
	Burger getBurger() override
	{
		return burger;
	}
};


class BurgerDirector
{
	virtual Burger BurgerAssembler(BurgerBuilder& builder)=0;
};

class veggieBurgerDirector : BurgerDirector
{
	public:
	//steps
	Burger BurgerAssembler(BurgerBuilder& builder) override
	{
        builder.makeSauce("sweetOnion");
		builder.makePatty("Veggie");
		builder.grillBread("Wheat");
		return builder.getBurger();
	}
};
 
class hamBurgerDirector : BurgerDirector
{
	public:
    Burger BurgerAssembler(BurgerBuilder& builder) override
	{
        builder.makeSauce("BarbeQue");
		builder.makePatty("Ham");
		builder.grillBread("White");
		return builder.getBurger();
	}
};

int main()
{
	/* 
	   --> create objects of director, concrete builder and product
	   --> call director function using director object and passing c.builder object as argument
	   --> catch the returned object i.e the product (burger) into product object
	   --> use the product object to display the product specifications
	*/
		
	veggieBurgerDirector directorV;
	ConcreteBurgerBuilder veggieBurgerBuilder;		
	Burger veggieB = directorV.BurgerAssembler(veggieBurgerBuilder);
	veggieB.displayBurger();
    
    hamBurgerDirector directorH;
    ConcreteBurgerBuilder hamBurgerBuilder;
	Burger hamB = directorH.BurgerAssembler(hamBurgerBuilder);
	hamB.displayBurger();
	
	return 0;
}