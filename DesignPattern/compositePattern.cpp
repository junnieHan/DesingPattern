#include <iostream>
#include <vector>

// component Class Abstract
class Fish
{
public:
	~Fish() {};
	virtual void Swimming() = 0;
};

// Leaf
class GoldFish :public Fish
{
public:
	void Swimming() override
	{
		printf("Gold fish is swimming \n");
	}
};

class TropicalFish : public Fish
{
public:
	void Swimming() override
	{
		printf("Tropical fish is swimming \n");
	}
};

// composite
class FishGroup:public Fish
{
private:
	std::vector<Fish*> m_vecFish;

public:
	void addFish(Fish* fish)
	{
		m_vecFish.emplace_back(fish);
	}

	void Swimming() override
	{
		printf("Fishes Swimming Start! \n");
		for (auto& fish : m_vecFish)
		{
			fish->Swimming();
		}
	}

};

//GoldFish* GF1 = new GoldFish();
//GoldFish* GF2 = new GoldFish();
//GoldFish* GF3 = new GoldFish();
//
//TropicalFish* TF1 = new TropicalFish();
//TropicalFish* TF2 = new TropicalFish();
//TropicalFish* TF3 = new TropicalFish();
//
//FishGroup FG1;
//FishGroup FG2;
//
//FG1.addFish(GF1);
//FG1.addFish(GF2);
//FG1.addFish(GF3);
//
//FG2.addFish(TF1);
//FG2.addFish(TF2);
//FG2.addFish(TF3);
//
//FG1.addFish(&FG2);
//FG1.Swimming();
//
//delete GF1;
//GF1 = nullptr;
//
//delete GF2;
//GF2 = nullptr;
//
//delete GF3;
//GF3 = nullptr;
//
//delete TF1;
//TF1 = nullptr;
//delete TF2;
//TF2 = nullptr;
//delete TF3;
//TF3 = nullptr;