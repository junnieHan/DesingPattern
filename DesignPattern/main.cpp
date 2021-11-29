#include "builderPattern.cpp"
#include "FactoryPattern.cpp"

int main()
{
	std::shared_ptr<AnimalCreator> Catcreator = std::make_shared<CatCreator>();
	auto catC = Catcreator->create();
	catC->speak();

	std::shared_ptr<AnimalCreator> Dogcreator = std::make_shared<DogCreator>();
	auto DogC = Dogcreator->create();
	DogC->speak();

	return 0;
}