#include "builderPattern.cpp"
#include "FactoryPattern.cpp"
#include "prototypePattern.cpp"

int main()
{
//	std::shared_ptr<AnimalCreator> Catcreator = std::make_shared<CatCreator>();
//	auto catC = Catcreator->create();
//	catC->speak();
//
//	std::shared_ptr<AnimalCreator> Dogcreator = std::make_shared<DogCreator>();
//	auto DogC = Dogcreator->create();
//	DogC->speak();
	Birds* Yellowbird = new Chiken("Yellow");
	BirdsFactory* facotry1 = new BirdsFactory(Yellowbird);
	Yellowbird->Color();
	Yellowbird->cry();
	Birds* Darkbird = new Chiken("Dark");
	BirdsFactory* facotry2 = new BirdsFactory(Darkbird);
	Darkbird->Color();
	Darkbird->cry();

	delete facotry1;
	delete Yellowbird;

	delete facotry2;
	delete Darkbird;
	return 0;
}