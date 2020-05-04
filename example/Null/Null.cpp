#include "../IApplication.h"

class NullApplication : public IApplication
{
public:
	NullApplication() : IApplication(std::string("Null"))
	{

	}
};

int main()
{
	NullApplication app;
	app.Init();

	app.GetEngine()->Test();

	return 0;
}
