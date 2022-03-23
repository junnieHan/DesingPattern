//strategy Pattern
// runtime중에 알고리즘을 선택 할 수 있게 하는 행위패턴
//특정 알고리즘을 정의, 각 알고리즘 캡슐화
// 특징: 유연하고 재사용 가능하게하는 패턴 (open-close랑 비슷한 개념)
#include <iostream>

//Interface

class Beverage
{
public:
	~Beverage() {};
	virtual void make() = 0;

};

class Coffe :public Beverage
{
public:
	void make () override
	{
		printf("make Coffe Method \n");
	}
};

class Juice : public Beverage
{
public:
	void make() override
	{
		printf("make Juice Method \n");
	}
};

class COKE : public Beverage
{
public:
	void make() override
	{
		printf("make Coke Method \n");
	}
};

class VendingMachine
{
private:
	Beverage* m_pBevrage;

public:
	VendingMachine() {};
	~VendingMachine() { if (m_pBevrage) delete m_pBevrage; };

	void changeBeverage(Beverage* pbeverage) {
		
		if (m_pBevrage)
		{
			delete m_pBevrage;
			m_pBevrage = nullptr;
		}
		
		m_pBevrage = pbeverage;
	};

	void makeBeverage() { m_pBevrage->make(); };
};

//int main()
//{
//	VendingMachine* machine = new VendingMachine();
//
//	machine->changeBeverage(new Coffe);
//	machine->makeBeverage();
//
//	machine->changeBeverage(new COKE);
//	machine->makeBeverage();
//
//	machine->changeBeverage(new Juice);
//	machine->makeBeverage();
//
//	delete machine;
//	machine = nullptr;
//	return 0;
//}