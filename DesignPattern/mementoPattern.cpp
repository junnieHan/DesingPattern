// 기억하고자하는 obj의 상태를 보관하고 필요 할 때 그상태를 가져오는 패턴
// 구조: Originator(기억하고자 하는 객체), Memento(Ori obj의 상태 보관), Createker(Memento를 담는 함수)
// Memento는 obj의 Property를 가진다.
#include <iostream>
#include <vector>

//memento
class Memento
{
	
public:
	int m_nAge{ 0 };
	int m_nHeight{ 0 };

	using Ptr = std::shared_ptr<Memento>;
	Memento(const int& age, const int& height)
	{
		m_nAge = age;
		m_nHeight = height;
	}
	~Memento() = default;
};

//Originator
class MySon
{
public:
	int m_nAge{ 0 };
	int m_nHeight{ 0 };

	MySon(const int& nAge, const int& nHeight)
	{
		m_nAge = nAge;
		m_nHeight = nHeight;
	};

	Memento::Ptr createMemento()
	{
		Memento::Ptr memento = std::make_shared<Memento>(m_nAge, m_nHeight);
		return memento;
	}

	void getProperty(Memento::Ptr memento)
	{
		m_nAge = memento->m_nAge;
		m_nHeight = memento->m_nHeight;
		printf("age:%d Height:%d \n", m_nAge, m_nHeight);
	}
};

//creataker
class MemoryContainer
{
	std::vector<Memento::Ptr> m_vecMemento;
public:
	void registerMemento(Memento::Ptr memento)
	{
		m_vecMemento.emplace_back(memento);
	}

	Memento::Ptr restoreMemento(int n)
	{
		if (m_vecMemento.size() <= n)
			return Memento::Ptr();

		return m_vecMemento.at(n);
	}
};

//MySon mySon(0, 50);
//MemoryContainer memory;
//memory.registerMemento(mySon.createMemento());
//mySon.m_nAge = 1;
//mySon.m_nHeight = 78;
//memory.registerMemento(mySon.createMemento());
//mySon.m_nAge = 2;
//mySon.m_nHeight = 100;
//memory.registerMemento(mySon.createMemento());
//
//mySon.getProperty(memory.restoreMemento(1));
//mySon.getProperty(memory.restoreMemento(0));