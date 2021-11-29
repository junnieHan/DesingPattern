#include <string.h>
#include <iostream>
//Builder Pattern�� �ܼ��ϰ� ���� ��ü�� ������ ������ �ٸ� Ŭ������ ����(CatBuilder)
//�ڱ��ڽ��� Return �Ͽ� �帧�� ������ �����ϴ�.

//class Cat
//{
//public:
//	explicit Cat(const int nHeight, const int nWeight, const std::string color):m_nHeight{nHeight}, m_nWeight{nWeight}, m_color{color}
//	{};
//
//	void print()
//	{
//		std::cout << m_nHeight << "cm" << m_nWeight << "kg" << m_color << std::endl;
//	};
//
//private:
//	int m_nHeight{ 0 };
//	int m_nWeight{ 0 };
//	std::string m_color;
//};
//
//class CatBuilder
//{
//public:
//	CatBuilder() = default;
//
//	CatBuilder& setHeight(int nHeight)
//	{
//		m_nHeight = nHeight;
//		return *this;
//	}
//	CatBuilder& setWeight(int nWeight)
//	{
//		m_nWeight = nWeight;
//		return *this;
//	}
//	CatBuilder& setColor(std::string color)
//	{
//		m_color = color;
//		return *this;
//	}
//
//	std::shared_ptr<Cat> Build() 
//	{
//		return cat = std::make_shared<Cat>(m_nHeight, m_nWeight, m_color);
//	}
//
//private:
//	std::shared_ptr<Cat> cat;
//
//	int m_nHeight{ 0 };
//	int m_nWeight{ 0 };
//	std::string m_color;
//};
//
////�Ʒ��� ���� �ǵ��� �˷� �� �� �ְ�, ó���� �������� argument�� init�� �ϰ� ���� �� �� �ִ�.
//
//class WhiteBuilder:public CatBuilder
//{
//public:
//	WhiteBuilder() 
//	{
//		__super::CatBuilder();
//		setColor("white");
//	};
//};
//
//class BlackBuilder :public CatBuilder
//{
//public:
//	BlackBuilder() {
//		__super::CatBuilder();
//		setColor("black");
//	};
//};
//
//Main
// 	std::unique_ptr<CatBuilder> cat_builder = std::make_unique<CatBuilder>();
// 	cat_builder->setHeight(30);
// 	cat_builder->setWeight(7);
// 	cat_builder->setColor("Gray");
// 	std::shared_ptr<Cat> cat = cat_builder->Build();
// 	cat->print();

	//�帲�� ���� 
// 	std::unique_ptr<CatBuilder> cat_builder = std::make_unique<CatBuilder>();
// 	std::shared_ptr<Cat> cat = cat_builder->setHeight(30).setWeight(7).setColor("Gray").Build();
// 	cat->print();

//�Ʒ��� ���� �ǵ��� �˷� �� �� �ִ�.. �� ���� ����� �ִ����� ����..
//std::unique_ptr<WhiteBuilder> white_cat = std::make_unique<WhiteBuilder>();
//std::unique_ptr<BlackBuilder> black_cat = std::make_unique<BlackBuilder>();
//std::shared_ptr<Cat> WhiteCat = white_cat->setHeight(30).setWeight(5).Build();
//std::shared_ptr<Cat> BlackCat = black_cat->setHeight(40).setWeight(8).Build();
//WhiteCat->print();
//BlackCat->print();
