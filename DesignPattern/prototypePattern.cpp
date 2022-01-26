#include <iostream>

namespace ProtoType
{
	class Habitat
	{
	public:
		std::string getHabit() { return m_contury; }
		void setHabit(std::string str) { m_contury = str; }

	private:
		std::string m_contury;

	};

	class Bird
	{
	private:
		std::string m_WingColor;
		std::string m_EyesColor;
		std::string m_beakColor;
		Habitat* habit;

	public:
		explicit Bird(std::string strWing, std::string strEye, std::string strbeak)
			:m_WingColor{ strWing }, m_EyesColor{ strEye }, m_beakColor{ strbeak }, habit{ new Habitat }
		{
		}
		//복제 생성자

		explicit Bird(const Bird& bird) :habit{ new Habitat }
		{}
		Bird& operator=(const Bird& bird)
		{
			// 같은 값이 들어올 경우 예외처리
			if (this == &bird)
				return *this;

			m_WingColor = bird.m_WingColor;
			m_beakColor = bird.m_beakColor;
		}

		~Bird() = default;


	public:
		void getBirdInfo() {
			std::cout << "WingColor:" + m_WingColor << "EyeColor:" + m_EyesColor
				<< "BeakColor:" + m_beakColor << std::endl;
		}
		void getBirdContury() { std::cout << habit->getHabit() << std::endl; }
		void setBirdContury(std::string str) { habit->setHabit(str); }

	};
}
//main
//ProtoType::Bird K_Chiken("Brown", "Black", "Black");
//ProtoType::Bird J_Chiken(K_Chiken);
//K_Chiken.setBirdContury("Korea");
//J_Chiken.setBirdContury("Japan");
//K_Chiken.getBirdContury();
//K_Chiken.getBirdInfo();
//J_Chiken.getBirdContury();
//J_Chiken.getBirdInfo();