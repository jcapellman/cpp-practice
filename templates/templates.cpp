#include <fstream>

#include <string>

using namespace std;

class File {
public:
	template <typename T>
    bool static WriteAllText(string fileName, T objectToWrite)
	{
		ofstream file(fileName.c_str());

		file << objectToWrite;
		
		file.close();

		return true;
	}
};

class Config
{
public:
	string WebServiceUrl;

	string RegistrationKey;
	
	friend ostream& operator<<(ostream& os, const Config& config);
};

ostream& operator<<(ostream& os, const Config& config)
{
	os << config.WebServiceUrl << endl << config.RegistrationKey << endl;

	return os;
}

int main()
{
	Config config;

	config.RegistrationKey = "Test";
	config.WebServiceUrl = "testt";

	File::WriteAllText("Test", config);
	
}