//명령을 추상화하여 객체를 다룬다.
//목적: Invoker와 receiver의 의존성을 제거하여 receiver이 변경을 해도 호출하는 수신자는 그대용 사용 가능, 명령을 object로 만들어 재사용 가능
//방법: 실행 될 기능을 캡슐화
#include <iostream>
#include <vector>

// Abstract Class 
class Command
{
public:
	~Command() {};
	virtual void execute() = 0;
};

//receiver
class Lion
{
public:
	void show() { printf("show Lion sit"); };
};

//concrete Command
class AnimanlCommand : public Command
{
private:
	std::shared_ptr<Lion> m_lion;
public:

	AnimanlCommand() {};
	~AnimanlCommand() = default;
	AnimanlCommand(std::shared_ptr<Lion> lion)
	{
		m_lion = lion;
	};
	void execute() override { m_lion->show(); };
};

//
class Dolphin
{
public:
	void show() { printf("dolphin Jump"); };
};

class FishCommand : public Command
{
private:
	std::shared_ptr<Dolphin> m_dolphin;
public:
	FishCommand() {};
	~FishCommand() = default;
	FishCommand(std::shared_ptr<Dolphin> dolphin)
	{
		m_dolphin = dolphin;
	};
	void execute()override { m_dolphin->show(); };
};

//Invoker
class Invoker
{
private:
	std::vector<std::shared_ptr<Command>> m_vecCommand;

public:
	void addCommand(std::shared_ptr<Command> cmd) {
		m_vecCommand.emplace_back(cmd);
	};

	void runCommand() {
		for (const auto& cmd : m_vecCommand)
		{
			cmd->execute();
		}
	};
};


//std::shared_ptr<Invoker> invoker = std::make_shared<Invoker>();
//
//auto Animal = std::make_shared<AnimanlCommand>();
//auto fish = std::make_shared<FishCommand>();
//invoker->addCommand(Animal);
//invoker->addCommand(fish);
//
//invoker->runCommand();