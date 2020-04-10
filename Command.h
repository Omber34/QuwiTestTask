#pragma once
class Command
{
public:
	virtual void execute() = 0;
};

template<typename Func>
class TemplateCommand
	: public Command
{
	Func func;
public:
	TemplateCommand(Func func)
		: func(func)
	{}

	void execute() override
	{
		func();
	}
};