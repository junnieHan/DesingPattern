#include <iostream>

enum ANIMAL_TYPE
{
	CAT =1, DOG =2
};

class Animal
{
public:
	virtual void speak() = 0;
};

class AnimalCreator
{
public:
	virtual std::shared_ptr<Animal> create()
	{
		return this->factory();
	}

protected:
	virtual std::shared_ptr<Animal> factory() = 0;
};

class Cat :public Animal
{
public:
	Cat() { printf("Cat 持失"); };
	void speak() override
	{
		printf("Meow~");
	}
};

class Dog : public Animal
{
public:
	Dog() { printf("Dog 持失"); };

	void speak() override
	{
		printf("Bark");
	}
};

class CatCreator:public AnimalCreator
{
public:
	virtual std::shared_ptr<Animal> factory() 
	{
		return std::make_shared<Cat>();
	}
};

class DogCreator :public AnimalCreator
{
public:
	virtual std::shared_ptr<Animal> factory()
	{
		return std::make_shared<Dog>();
	}
};