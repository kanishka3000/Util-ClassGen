#include <iostream>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <string.h>
using namespace std;
int main(int iCount, char* zArgs[])
{
	if (iCount < 1)
	{
		cout << "Specify class name" << endl;
		return 0;
	}
	char zName [100];
	snprintf(zName,99, "%s.%s",zArgs[1],"h");
	ofstream oOutputFile;
	oOutputFile.open(zName);
	oOutputFile << "#ifndef " << "__" << zArgs[1] << "__\n";
	oOutputFile << "#define " << "__" << zArgs[1] << "__\n";
	memset(zName,0,sizeof(zName));
	getlogin_r(zName, 99);	
	
	oOutputFile << "//Author: " << zName << "\n";
	oOutputFile << "class " << zArgs[1] << "\n";
	oOutputFile << "{\n";
	oOutputFile << "public: \n";
	oOutputFile << "\t" <<zArgs[1] << "();  \n";
	oOutputFile << "\t ~"<< zArgs[1] << "();  \n";
	

	oOutputFile << "private: \n";
	oOutputFile << "}; \n";
	oOutputFile << "#endif " << "//__" << zArgs[1] << "__\n";;
	oOutputFile.close();
	cout << "Header Generated" <<  endl;;

	snprintf(zName,99, "%s.%s",zArgs[1],"cpp");
	oOutputFile.open(zName);
	
	oOutputFile << "#include <" << zArgs[1] << ".h> \n";
	
	oOutputFile << zArgs[1] << "::" << zArgs[1] << "() \n";
	oOutputFile << "{\n ";
	oOutputFile << "} \n\n";
	oOutputFile << zArgs[1] << "::~" << zArgs[1] << "() \n";
	oOutputFile << "{\n";
	oOutputFile << "} \n";
	oOutputFile.close();


}
