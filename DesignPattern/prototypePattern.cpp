//prtotypePattern
//����: client 
//Client -> Protype Class <- obj or obj .......(Deep Copy)
// copy�� �Ǳ� �� ���� ���¸� ������ ���� prtotype class
// �߻� ���丮 ���ϰ��� �ݴ��, 
// ����:
// 1. �����ϴ� ��ü�� �����Ͽ� , �ش� ��ü�� �°� Customize�� �ϴ� ��
// 2. ������ ��ü�� runtime���� ���� �� ����
// 3. 
// C++�� ������ class ���� ���� ��ü�� ����������ϴ� ������ ����. 
// ���� ���: ����ȭ �ϴ� �͵� �ϳ��� ��� or 
#include<iostream>

//protype  class
class Birds
{
public:
	virtual void cry() = 0;
	virtual void Color() = 0;
	virtual Birds* clone() = 0;
};

//concreate prototype��
// �����ϰ� ����ġ��� �������� ���� ��� Chkien�� �����Ҹ��� ����������, color�� �ٸ���.
class Chiken : public Birds
{
public:
	Chiken(const std::string& color){
		strCrying = "GGogio";
		m_strColor = color;
	}
	
	void cry() override { printf(strCrying.c_str()); }// ���� ����;
	void Color() override{ printf(m_strColor.c_str()); }
	Birds* clone() override
	{
		return new Chiken(strCrying);
	}

private:
	std::string strCrying;
	std::string m_strColor;

};

//client�� �� �־�� �ϴ����� �ǹ��̴�.
//�����丮���� �� ���� �� �ϴ� ��� �� ������ .... �װ� �����ɱ�� ���� ���ΰ� �� �ʿ�
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