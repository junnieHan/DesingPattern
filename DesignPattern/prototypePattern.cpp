//prtotypePattern
//구조: client 
//Client -> Protype Class <- obj or obj .......(Deep Copy)
// copy가 되기 전 까지 상태를 가지는 것이 prtotype class
// 추상 팩토리 패턴과는 반대로, 
// 장점:
// 1. 존재하는 객체를 복사하여 , 해당 객체에 맞게 Customize를 하는 것
// 2. 생성할 객체가 runtime에서 생성 시 좋음
// 3. 
// C++은 생성할 class 마다 복사 객체를 지정해줘야하는 단점이 존재. 
// 개선 방법: 직렬화 하는 것도 하나의 방법 or 
#include<iostream>

//protype  class
class Birds
{
public:
	virtual void cry() = 0;
	virtual void Color() = 0;
	virtual Birds* clone() = 0;
};

//concreate prototype은
// 간단하게 스케치라고 생각하자 예를 들면 Chkien의 울음소리는 동일하지만, color가 다르다.
class Chiken : public Birds
{
public:
	Chiken(const std::string& color){
		strCrying = "GGogio";
		m_strColor = color;
	}
	
	void cry() override { printf(strCrying.c_str()); }// 공통 내용;
	void Color() override{ printf(m_strColor.c_str()); }
	Birds* clone() override
	{
		return new Chiken(strCrying);
	}

private:
	std::string strCrying;
	std::string m_strColor;

};

//client가 꼭 있어야 하는지는 의문이다.
//이팩토리에서 다 생성 후 하는 방식 도 있지만 .... 그게 옳은걸까는 추후 공부가 더 필요
class BirdsFactory
{
public:
	BirdsFactory(Birds* birds) :bird(birds) {};

	Birds* MakeBird()
	{
		return bird->clone();
	}
private:
	Birds* bird;

};