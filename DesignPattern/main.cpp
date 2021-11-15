#include "builderPattern.cpp"

int main()
{
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
	std::unique_ptr<WhiteBuilder> white_cat = std::make_unique<WhiteBuilder>();
	std::unique_ptr<BlackBuilder> black_cat = std::make_unique<BlackBuilder>();
	std::shared_ptr<Cat> WhiteCat = white_cat->setHeight(30).setWeight(5).Build();
	std::shared_ptr<Cat> BlackCat = black_cat->setHeight(40).setWeight(8).Build();
	WhiteCat->print();
	BlackCat->print();

	return 0;
}