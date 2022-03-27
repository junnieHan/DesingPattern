#include "builderPattern.cpp"
#include "FactoryPattern.cpp"
#include "prototypePattern.cpp"
#include "singletonePattern.cpp"
#include "adapterPattern.cpp"
#include "BridgePattern.cpp"
#include "FlyweightPattern.cpp"
#include "compositePattern.cpp"
#include "StrategyPattern.cpp"
#include "statePattern.h"
#include "templateMathodPattern.cpp"
#include "CMDPattern.cpp"

using namespace Flyweight;

int main()
{	
	std::shared_ptr<Invoker> invoker = std::make_shared<Invoker>();

	auto Animal = std::make_shared<AnimanlCommand>();
	auto fish = std::make_shared<FishCommand>();
	invoker->addCommand(Animal);
	invoker->addCommand(fish);

	invoker->runCommand();
	return 0;
}