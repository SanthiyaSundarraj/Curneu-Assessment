#include <iostream>
#include <string>

//Here the rapidjson library is used to handle the json file in cpp 
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filereadstream.h"
int main(int argc, char* argv[])
{
	//Adding the path of json file to json_path string
    	std::string json_path= "/Users/Home/Desktop/sample.json";
    	std::cerr << "Writing Parameters in \n\n" << std::endl;
    
    	//Initialising the document named doc
    	rapidjson::Document doc;
    	doc.SetObject();
    	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
    
    	//declaring object B and Setting it
 	rapidjson::Value B(rapidjson::kArrayType);
    	B.SetObject();
    	
    	//declaring object A1 and Setting it
 	rapidjson::Value A1(rapidjson::kArrayType);
   	A1.SetObject();
   	
   	//Adding the members to object A1
   	A1.AddMember("userID", "IND0001", allocator);
	A1.AddMember("Email","balaji@curneu.com", allocator);
   	A1.AddMember("Country", "India", allocator);
    	A1.AddMember("HospitalName", "CMC", allocator);
    	A1.AddMember("Password", "K@123", allocator);
    	A1.AddMember("UserGender", "Male", allocator);
    	A1.AddMember("UserName", "BalajiSivakumar", allocator);
    
    	//Adding the object A1 and B as member of B and doc respectively 
    	B.AddMember("userBasicDetails",A1, allocator); 
    	doc.AddMember("balaji.sivakumar@curneu.com", B, allocator);
     
     //opening the json file in write mode and writing the doc object
	FILE* fp = fopen(json_path.c_str(), "w"); 
    	char writeBuffer[65536];
    	rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
    	rapidjson::PrettyWriter<rapidjson::FileWriteStream> writer(os);
    	doc.Accept(writer);
    	fclose(fp); //File closing
    	
    	//End
 	std::cerr << "Json file created and written successfully!!\n\n" << std::endl;
    	return 0;
}
