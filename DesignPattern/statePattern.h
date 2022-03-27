#pragma once


//class State
//{
//public:
//	virtual ~State() {};
//	virtual void status() = 0;
//	virtual void changeStatus(TraficLight*) = 0;
//};
//
//class TraficLight
//{
//public:
//	TraficLight();
//	~TraficLight();
//
//	void change(State* state);
//	void speak();
//	void wait();
//
//private:
//	State* m_state;
//};
//
//class RedLight : public State
//{
//public:
//	void status() override;
//	void changeStatus(TraficLight* light) override;
//};
//
//class YellowLight : public State
//{
//public:
//	void status() override;
//	void changeStatus(TraficLight* light) override;
//};
//
//class GreenLight : public State
//{
//public:
//	void status() override;
//	void changeStatus(TraficLight* light) override;
//};