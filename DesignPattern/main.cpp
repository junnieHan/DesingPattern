#include "builderPattern.cpp"
#include "FactoryPattern.cpp"
#include "prototypePattern.cpp"
#include "singletonePattern.cpp"
#include "adapterPattern.cpp"

int main()
{	
	AdapterPtn::AnimalBase animal(1);
	animal.walk();
}