//��Ÿ�ӿ��� ���¸� ���� �� �� �ִ� Pattern
//Strategy Pattern�� ��������� �������� �ִ�.
//Startegy Ptn�� concreteState���� ���θ� ���� ������ ���������� concreteStateClass�� ������ ���¸� �˾ƾ��Ѵ�.
//���� state�� context�� �˾ƾ��Ѵ�.

// ��ȣ��
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
