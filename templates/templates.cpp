#include <fstream>
#include <iostream>
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

	template <typename T>
	T static ReadAllText(string fileName)
	{
		T objectToRead;

		ifstream file(fileName.c_str());

		file >> objectToRead;

		file.close();

		return objectToRead;
	}
};

class Config
{
public:
	string WebServiceUrl;

	string RegistrationKey;
	
	friend ostream& operator<<(ostream& os, const Config& config) {
		os << config.WebServiceUrl << endl << config.RegistrationKey << endl;

		return os;
	}

	friend istream& operator>>(istream& is, Config& config) {
		is >> config.WebServiceUrl >> config.RegistrationKey;

		return is;
	}
};

int main()
{
	Config config;

	config.RegistrationKey = "Test";
	config.WebServiceUrl = "testt";

	File::WriteAllText("Test", config);
	
	Config readConfig;

	readConfig = File::ReadAllText<Config>("Test");

	cout << readConfig.WebServiceUrl << "-" << readConfig.RegistrationKey;

}