#include "builderPattern.cpp"
#include "FactoryPattern.cpp"
#include "prototypePattern.cpp"
#include "singletonePattern.cpp"
#include "adapterPattern.cpp"
#include "BridgePattern.cpp"

int main()
{	
	Digel* digel = new Digel;
	
	std::shared_ptr<BMW> bmw = std::make_shared<BMW>(digel);
	bmw->Go();
	bmw->Stop();
	bmw->BMWonlyFn();

	
	return 0;
}