#include <string.h>
#include <iostream>
//Builder Pattern은 단순하게 개별 객체의 생성을 별도의 다른 클래스에 위임(CatBuilder)
//자기자신을 Return 하여 흐름식 빌더가 가능하다.

class Cat
{
public:
	explicit Cat(const int nHeight, const int nWeight, const std::string color):m_nHeight{nHeight}, m_nWeight{nWeight}, m_color{color}
	{};

	void print()
	{
		std::cout << m_nHeight << "cm" << m_nWeight << "kg" << m_color << std::endl;
	};

private:
	int m_nHeight{ 0 };
	int m_nWeight{ 0 };
	std::string m_color;
};

class CatBuilder
{
public:
	CatBuilder() = default;

	CatBuilder& setHeight(int nHeight)
	{
		m_nHeight = nHeight;
		return *this;
	}
	CatBuilder& setWeight(int nWeight)
	{
		m_nWeight = nWeight;
		return *this;
	}
	CatBuilder& setColor(std::string color)
	{
		m_color = color;
		return *this;
	}

	std::shared_ptr<Cat> Build() 
	{
		return cat = std::make_shared<Cat>(m_nHeight, m_nWeight, m_color);
	}

private:
	std::shared_ptr<Cat> cat;

	int m_nHeight{ 0 };
	int m_nWeight{ 0 };
	std::string m_color;
};

//아래와 같이 의도를 알려 줄 수 있고, 처음에 생성자의 argument를 init을 하고 시작 할 수 있다.

class WhiteBuilder:public CatBuilder
{
public:
	WhiteBuilder() 
	{
		__super::CatBuilder();
		setColor("white");
	};
};

class BlackBuilder :public CatBuilder
{
public:
	BlackBuilder() {
		__super::CatBuilder();
		setColor("black");
	};
};