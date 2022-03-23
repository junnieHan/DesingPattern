// ��� ����: �ټ��� object ���� ������ �޸𸮸� ����ϴ�(�޸𸮰� ū) Property�� �и��Ͽ�  �޸� ����� ���� �� ���
// object�� ���� �� �Ӽ��� ���´�.
#include <iostream>
#include <string>
#include <map>

//���� ��� �������� DNA�� �뷮�� ũ���� DNA�� �����ϴٰ� �����ϰ�, DNA�� ���� ������.
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

