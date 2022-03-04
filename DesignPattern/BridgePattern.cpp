//BridgePattern: 구현부에서 추상층을 분리하여 각자 독립적으로 사용 및 확장 가능
#include <iostream>

//Implementor(기능)
class Engine
{
public:
	virtual ~Engine() {};

	virtual void GageUp() = 0;
	virtual void GageDown() = 0;
};

class Gas :public Engine
{
public:
	void GageUp() override { printf("Gas Gage Up"); };
	void GageDown() override { printf("Gas Gage Down"); };
};

class Digel : public Engine
{
public:
	void GageUp() override { printf("Digel Gage Up"); };
	void GageDown() override { printf("Digel Gage Down"); };
};

//Abstract
// 선언부 객체를 갖는다.
class Car
{
protected:
	Engine* m_Engine;

public:
	Car(Engine* engine) :m_Engine(engine) {};
	virtual ~Car() {};

	virtual void test() {};

public:
	void Go() { m_Engine->GageUp(); };
	void Stop() { m_Engine->GageDown(); };
};

class BMW : public Car
{
public:
	BMW(Engine* engine) :Car(engine) {};
	~BMW() {};
	
	void BMWonlyFn() { printf("autonomous driving"); };
	void test() override {};
};

class Hyundai: public Car
{
public:
	Hyundai(Engine* engine) :Car(engine) {};
	~Hyundai() {};

	void HDonlyFn() { printf("A/S Good"); };
	void test() override {};
};