#include <iostream>

// 구조: client <-> proxy object <-> object
//사용이유: 1. object가 resource가 클 때 사용, 2. object 수정 없이 부수적인 내용을 추가시(ex, log 추가기능)
// 사용규칙: object랑 proxy object 함수는 동일해야함.

namespace proxy
{
// 부수적인 내용 추가시
	class DataBase
	{
	public:
		void Connection() { printf("Connection"); };
		void getData() { printf("getData"); };
	};

	//proxy 
	class ProxyDatabase
	{
	private:
		DataBase* m_db;

	public: ProxyDatabase():m_db(new DataBase) {};
		  ~ProxyDatabase() {
			  delete m_db;
			  m_db = nullptr;
		  };

		  void logStart() { printf("Start"); };
		  void logEnd() { printf("End"); };

		  // 생성할 Object에 부수적인 내용을 ProxyPattern에서 대신 해준다는 생각으러
		  // 여기서 주요점은 생성할 obj에 함수를 동일하게 구현(must는 아님)
		  void Connection() {
			  logStart();
			  m_db->Connection();
			  logEnd();
		   }

		  void getData()
		  {
			  logStart();
			  m_db->getData();
			  logEnd();
		  }
	};

	// InterFace class를 추가하면 생성할 obj와 proxyobj를 구현 할 함수를 실수 없이 구현 할 수 있다.
	class Interface
	{
		virtual void Connection() = 0;
		virtual void getData() = 0;
	};

	class IFDatabas:public Interface
	{
	public:
		void Connection() override
		{
			printf("Connection");
		};
		void getData() override
		{
			printf("getData");
		};
	};

	class proxyIFDatabase :public Interface
	{
	public:
	private:
		DataBase* m_db;

	public: proxyIFDatabase() :m_db(new DataBase) {};
		  ~proxyIFDatabase() {
			  delete m_db;
			  m_db = nullptr;
		  };

		  void logStart() { printf("Start"); };
		  void logEnd() { printf("End"); };

		  void Connection() {
			  logStart();
			  m_db->Connection();
			  logEnd();
		  }

		  void getData()
		  {
			  logStart();
			  m_db->getData();
			  logEnd();
		  }
	};
}