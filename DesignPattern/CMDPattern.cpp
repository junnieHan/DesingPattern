//����� �߻�ȭ�Ͽ� ��ü�� �ٷ��.
//����: Invoker�� receiver�� �������� �����Ͽ� receiver�� ������ �ص� ȣ���ϴ� �����ڴ� �״�� ��� ����, ����� object�� ����� ���� ����
//���: ���� �� ����� ĸ��ȭ
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

