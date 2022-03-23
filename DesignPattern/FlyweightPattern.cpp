// 사용 목적: 다수의 object 사용시 동일한 메모리를 사용하는(메모리가 큰) Property를 분리하여  메모리 사용을 줄일 때 사용
// object의 공통 된 속성을 묶는다.
#include <iostream>
#include <string>
#include <map>

//예를 들어 강아지의 DNA가 용량이 크지만 DNA가 동일하다고 가정하고, DNA를 따로 빼낸다.
using namespace std;

namespace Sample
{
	class Cat
	{
	private:
		string m_strName;
		int m_nAge{ 0 };
		string  m_strGender;
		string m_strDNA;

	public:
		explicit Cat(string name, int age, string gender, string dna)
			:m_strName(name), m_nAge(age), m_strGender(gender), m_strDNA(dna) {};

		void info() {
			string strAge = to_string(m_nAge);
			printf(m_strName.c_str(), strAge.c_str(), m_strGender.c_str(), m_strDNA.c_str());
		}

	};
}

namespace Flyweight
{
	//abstract class
	class catFlyweight
	{
	public:
		virtual string getDNA() = 0;
	};

	class catFlyConcurrent:public catFlyweight
	{
	private:
		string m_strDNA;

	public:
		catFlyConcurrent(string dna) :m_strDNA(dna) {};

		string getDNA()
		{
			return m_strDNA;
		}
	};

	class catFacotry
	{
	private:
		string m_strName;
		string m_strAge;
		string  m_strGender;

		map<string, catFlyweight*> m_mapDNA;

	public:
		catFacotry(string name, string age, string gender) :m_strAge(age), m_strName(name), m_strGender(gender) {};

		catFlyweight* getDNAInfo(string str) {
			if (m_mapDNA.find(str) == m_mapDNA.end())
				m_mapDNA[str] = new catFlyConcurrent(str);

			return m_mapDNA[str];
		};

		void info(string dna) {
			cout << m_strName.c_str() << m_strAge.c_str() << m_strGender.c_str() << dna.c_str()<< endl;
		}
	};
}

