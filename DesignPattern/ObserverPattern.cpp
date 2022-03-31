//옵저버들을 관찰해야하는 객체 등록하여 상태변화가 있을 시 옵저버에게 알려주는 class
//event가 발생하는 class에 옵저버를 container형식으로 담아준다.
#include <iostream>
#include <vector>

class BaseObserver
{
public:
	using Ptr = std::shared_ptr<BaseObserver>;
	~BaseObserver() {};
	virtual void updatge(std::string strEvent) = 0;
};

class Observer1 : public BaseObserver
{
public:
	void updatge(std::string strEvent) override {
		printf("Event1:%s \n", strEvent.c_str());
	}
};

class Observer2 : public BaseObserver
{
public:
	void updatge(std::string strEvent) override {
		printf("Event2:%s \n", strEvent.c_str());
	}
};

class Event
{
	std::vector<BaseObserver::Ptr> m_vecObservers;
public:
	void registerObserver(BaseObserver::Ptr observer)
	{
		m_vecObservers.emplace_back(observer);
	}

	void notifyObserver() {
		for (const auto& observer: m_vecObservers)
		{
			observer->updatge("Accident");
		}
	}

	void claerObserver()
	{
		m_vecObservers.clear();
	}
};

//auto event = std::make_shared<Event>();
//auto observer1 = std::make_shared<Observer1>();
//auto observer2 = std::make_shared<Observer2>();
//
//event->registerObserver(observer1);
//event->registerObserver(observer2);
//
//event->notifyObserver();
//
//event->claerObserver();