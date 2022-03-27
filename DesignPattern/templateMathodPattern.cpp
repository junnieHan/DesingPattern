//template Method Pattern
// 정의: base class에 Template가 될 수 있는 함수를 구현하고 , child class base 함수를 override해서 변경해서 사용한다.
// base Method는 public
#include <iostream>

class BasicRamenRecipe
{
public:
	virtual ~BasicRamenRecipe() {};
	virtual void boilWater() { printf("boil Water \n"); };
	virtual void addRamen() { printf("add Ramen \n"); };
	virtual void addTopping() { printf("add Egg \n"); };
	virtual void cook() {
		boilWater();
		addRamen();
		addTopping();
	};
};

class SomeoneRecipe :public BasicRamenRecipe
{
public:
	void addTopping() override { printf("add Green Onion \n"); };
};

class AnyoneRecipe :public BasicRamenRecipe
{
public:
	void addTopping() override { printf("add tuna \n"); };
};