#include <iostream>
//사용 할 수 없는 class를 사용 할 수 있게 해주낟.
//Adapter Pattern

namespace AdapterPtn
{
	class Animal
	{
	public:
		Animal() {};
		virtual ~Animal() = default;

		virtual void Walk() = 0;
	};

	class Dog :public Animal
	{
	public:
		void Walk() override { std::cout << "Dog Walking" << std::endl; };
	};

	class Fish
	{
	public:
		void Swim() { std::cout << "Fish Swimming" << std::endl; };
	};

	//Adapter Class
	class FishAdapter :public Animal
	{
	private:
		Fish* m_pFish;
	public:
		FishAdapter() :m_pFish(new Fish) {};
		~FishAdapter() {
			if (m_pFish)
			{
				delete m_pFish;
				m_pFish = nullptr;
			}
		};

		void Walk() override { m_pFish->Swim(); };
	};

	class AnimalFactory
	{
	public:
		static std::shared_ptr<Animal> createAnimal(int nType)
		{
			std::shared_ptr<Animal> pAnmial;
			switch (nType)
			{
			case 0: {pAnmial = std::make_shared<Dog>();}break;
			case 1: {pAnmial = std::make_shared<FishAdapter>(); }break;
			default:
				break;
			}

			return pAnmial;
		}
		
	};

	class AnimalBase :AnimalFactory
	{
	private:
		std::shared_ptr<Animal> m_pAnimal;
	public:
		AnimalBase(int nType): m_pAnimal{AnimalFactory::createAnimal(nType)}
		{};

		void walk() { m_pAnimal->Walk(); };
	};

	
}