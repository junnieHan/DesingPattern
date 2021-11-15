#include <string.h>
#include <iostream>
//Builder Pattern�� �ܼ��ϰ� ���� ��ü�� ������ ������ �ٸ� Ŭ������ ����(CatBuilder)
//�ڱ��ڽ��� Return �Ͽ� �帧�� ������ �����ϴ�.

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

//�Ʒ��� ���� �ǵ��� �˷� �� �� �ְ�, ó���� �������� argument�� init�� �ϰ� ���� �� �� �ִ�.

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