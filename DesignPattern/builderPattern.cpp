#include <string.h>
#include <iostream>
//Builder Pattern은 단순하게 개별 객체의 생성을 별도의 다른 클래스에 위임(CatBuilder)
//복잡한 객체를 생성하는 클래스와 표현하는 클래스를 분리하여, 동일한 절차에서도 서로 다른 표현을 생성하는 방법 제공
// 쉽게 생각하면 복잡한 생성 과정의 객체를 대신 생성해주는 클래스
//자기자신을 Return 하여 흐름식 빌더가 가능하다.

namespace BuilderPtn
{
	class Cat
	{
	public:
		explicit Cat(const int nHeight, const int nWeight, const std::string color) :m_nHeight{ nHeight }, m_nWeight{ nWeight }, m_color{ color }
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

	class WhiteBuilder :public CatBuilder
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
}

//
//Main
// 	std::unique_ptr<CatBuilder> cat_builder = std::make_unique<CatBuilder>();
// 	cat_builder->setHeight(30);
// 	cat_builder->setWeight(7);
// 	cat_builder->setColor("Gray");
// 	std::shared_ptr<Cat> cat = cat_builder->Build();
// 	cat->print();

	//흐림식 빌더 
// 	std::unique_ptr<CatBuilder> cat_builder = std::make_unique<CatBuilder>();
// 	std::shared_ptr<Cat> cat = cat_builder->setHeight(30).setWeight(7).setColor("Gray").Build();
// 	cat->print();

//아래와 같이 의도를 알려 줄 수 있다.. 더 나은 방법이 있는지는 강구..
//std::unique_ptr<WhiteBuilder> white_cat = std::make_unique<WhiteBuilder>();
//std::unique_ptr<BlackBuilder> black_cat = std::make_unique<BlackBuilder>();
//std::shared_ptr<Cat> WhiteCat = white_cat->setHeight(30).setWeight(5).Build();
//std::shared_ptr<Cat> BlackCat = black_cat->setHeight(40).setWeight(8).Build();
//WhiteCat->print();
//BlackCat->print();
