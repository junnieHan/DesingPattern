//런타임에서 상태를 변경 할 수 있는 Pattern
//Strategy Pattern과 흡사하지만 차이점이 있다.
//Startegy Ptn은 concreteState들이 서로를 몰라도 되지만 상태패턴은 concreteStateClass가 서로의 상태를 알아야한다.
//또한 state는 context를 알아야한다.

// 신호등
//#include <iostream>
//#include "statePattern.h"
//
//TraficLight::TraficLight()
//{
//}
//
//TraficLight::~TraficLight()
//{
//	if (m_state)
//	{
//		delete m_state;
//		m_state = nullptr;
//	}
//
//}
//
//void TraficLight::change(State* state)
//{
//	if (m_state)
//		delete m_state;
//
//	m_state = state;
//}
//
//void TraficLight::speak()
//{
//	m_state->status();
//}
//
//void TraficLight::wait()
//{
//	m_state->changeStatus(this);
//}
//
//
//void RedLight::status()
//{
//	printf("Red Light \n");
//}
//
//void RedLight::changeStatus(TraficLight* light) 
//{
// 	printf("wait... changeGreenLight \n");
//	light->change(new GreenLight());
//	delete this;
//}
//
//void YellowLight::status()
//{
//	printf("Yellow Light \n");
//}
//
//void YellowLight::changeStatus(TraficLight* light)
//{
//	printf("wait... changeRedLight \n");
//	light->change(new RedLight());
//	delete this;
//}
//
//void GreenLight::status()
//{
//	printf("Green Light \n");
//}
//
//void GreenLight::changeStatus(TraficLight* light)
//{
//	printf("wait... changeYeloowLight \n");
//	light->change(new YellowLight());
//	delete this;
//}
