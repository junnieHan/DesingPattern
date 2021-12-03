#include <iostream>
// Factory Pattern
// 부모(상위) 클래스에 알려지지 않은 구체 클래스를 생성하는 패턴이며, 자식(하위) 클래스가 어떤 객체를 생성할지를 결정하도록 하는 패턴.
// 생성하고자 하는 객체를 추상클래스로 정의하고 , 추상 클래스의 수정 없이 파생 클래스를 확장 가능하도록하는 패턴(추상 팩토리 패턴)
//  Factory Pattern은 Template Method의 생성 패턴 버전으로 볼 수 있음.
// 하나의 클래스로 여러가지 타입의 객체(자식)을 찍어내어 리턴하는 함수를 가진 하나의 공장(부모 클래스)를 만든다.
//  사용 이유: 
// 1. 어떤 obj를 만들 때 생성과정이 복잡 또는 타입의 객체가 다양할 경우 Factory 함수를 이용해 간단하게 생성 할 수 있게 해준다.
// 2. 여러 자식 타입들에게서 중복되는 내용을 제거 할 수 있음.


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
	//
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
	Cat() { printf("Cat 생성"); };
	void speak() override
	{
		printf("Meow~");
	}
};

class Dog : public Animal
{
public:
	Dog() { printf("Dog 생성"); };

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

//Abstract class
class Button
{
protected:
	virtual void click();
};

class DarkButton:Button
{
public:
	void click() override
	{
		printf("Dark Button");
	} 
};

class WhiteButton :Button
{
public:
	void click() override
	{
		printf("White Button");
	}
};