//SingletonePattern
//하나의 process에서 하나의 object를 통해 전역으로 사용이 필요 시 사용(ex.외부 네트워크랑 연결 시 사용)
// 오직 한 개의 클래스 인스턴스만을 갖도록 보장하고, 이에 대한 전역적인 접근점을 제공
// 주의 점: 멀티 쓰레드에서 사용 시 데이터 정보를 넣을 때 섞일 우려가 있어 Mutex Lock를 걸어 줘야한다.
#include <iostream>

namespace SingleTone
{
	class Database
	{
	private:
		static Database* database;
		std::string name;

	protected:
		Database()
		{
		};
	public:

		void getName() { std::cout << name << std::endl; }

		static Database* get()
		{
			if (database == nullptr)
				database = new Database();

			return database;
		}

		static void release()
		{
			if (database != nullptr)
			{
				delete database;
				database = nullptr;
			}
		}

		//복제/이동 생성자/연사자 제거
 		Database(Database const&) = delete;
 		Database(Database&&) = delete;
 		Database& operator=(Database const&) = delete;
 		Database& operator=(Database&&) = delete;
	};
}
//Main
// SingleTone::Database* SingleTone::Database::database = nullptr;
//SingleTone::Database* db = SingleTone::Database::get();
//SingleTone::Database* db1 = SingleTone::Database::get();
//
//if (db == db1)
//{
//	std::cout << "It's Same" << std::endl;
//}
//else
//{
//	std::cout << "It's not Same" << std::endl;
//}
//SingleTone::Database::release();