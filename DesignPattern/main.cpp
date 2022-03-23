#include "builderPattern.cpp"
#include "FactoryPattern.cpp"
#include "prototypePattern.cpp"
#include "singletonePattern.cpp"
#include "adapterPattern.cpp"
#include "BridgePattern.cpp"
#include "FlyweightPattern.cpp"
#include "compositePattern.cpp"
#include "StrategyPattern.cpp"

using namespace Flyweight;

int main()
{	
	VendingMachine* machine = new VendingMachine();

	machine->changeBeverage(new Coffe);
	machine->makeBeverage();

	machine->changeBeverage(new COKE);
	machine->makeBeverage();

	machine->changeBeverage(new Juice);
	machine->makeBeverage();

	delete machine;
	machine = nullptr;
	return 0;
}