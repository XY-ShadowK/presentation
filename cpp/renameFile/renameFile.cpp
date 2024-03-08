#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <io.h>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
const long long NAMEONLY = 1;
const long long PATHNEED = 2;
const long long SELFONLY = 1;
const long long SUBNEED = 2;
typedef struct _finddata_t fileInfo;
typedef struct tm time_st;
ifstream fin;
ofstream fout("renameFile.log",ios::app);
void getFiles(string path,long long modeReturn,long long modeSearch,string modeMatch,vector<string>& files)
{
	intptr_t handleFile = 0;
	fileInfo infoFile;
	string fileReturn,pathFind = path + "/" + modeMatch;
	handleFile = _findfirst(pathFind.c_str(),&infoFile);
	if(handleFile != -1){
		do{
			if(infoFile.attrib & _A_SUBDIR){
				if((strcmp(infoFile.name,".") != 0) && (strcmp(infoFile.name,"..") != 0)){
					if(modeSearch == SUBNEED){
						pathFind = path + "/" + infoFile.name;
						getFiles(pathFind,modeReturn,modeSearch,modeMatch,files);
					}
				}
			}
			else{
				switch(modeReturn){
					case NAMEONLY : {
						fileReturn = infoFile.name;
						break;
					}
					case PATHNEED : {
						fileReturn = path + "/" + infoFile.name;
						break;
					}
				}
				files.push_back(fileReturn);
			}
		}
		while(_findnext(handleFile,&infoFile) == 0);
		_findclose(handleFile);
	}
}
string scanTxt(string pathFile)
{
	fin.open(pathFile,ios::in);
	stringstream bufferString;
	bufferString<<fin.rdbuf();
	string txt(bufferString.str());
	fin.close();
	return txt;
}
string getFormatTime()
{
	time_t timep;
	time_st* stTime;
	char strTime[22];
	time(&timep);
	stTime = localtime(&timep);
	sprintf(strTime,"%d/%d/%d %02d:%02d:%02d",1900+stTime->tm_year,1+stTime->tm_mon,stTime->tm_mday,stTime->tm_hour,stTime->tm_min,stTime->tm_sec);
	return string(strTime);
}
int main()
{
	fout<<"[ "<<getFormatTime()<<" ]"<<" program opened."<<endl;
	string basedir,match,target,content,after,afterFile,command,filename;
	vector<string> filesFind;
	long long modeSearch;
	while(1){
		cout<<"input a string which is the absolute path of the directory that you want to search."<<endl;
		// cin>>basedir;
		getline(cin,basedir);
		// cin.ignore(2048,'\n');
		// 使用 g++ -std=c++11 编译 getline自动将结尾换行符移除?!
		fout<<"\t[ "<<getFormatTime()<<" ]"<<" base directory | "<<basedir<<endl;
		cout<<"input a string which represents the method to match files in your directory."<<endl;
		// cin>>match;
		getline(cin,match);
		// cin.ignore(2048,'\n');
		fout<<"\t[ "<<getFormatTime()<<" ]"<<" match mode | "<<match<<endl;
		cout<<"input a number which decides whether files in subdirectories will be searched.(1 means self-only and 2 means sub-need)"<<endl;
		cin>>modeSearch;
		cin.ignore(2048,'\n');
		fout<<"\t[ "<<getFormatTime()<<" ]"<<" search mode | "<<(modeSearch==1?"SELFONLY":(modeSearch==2?"SUBNEED":"ERROR_UNKNOWN_SEARCHMODE"))<<endl;
		cout<<"input a string which is what you want to change in filename."<<endl;
		// cin>>target;
		getline(cin,target);
		// cin.ignore(2048,'\n');
		fout<<"\t[ "<<getFormatTime()<<" ]"<<" target string | "<<target<<endl;
		cout<<"input a string which is what you want to change to in filename."<<endl;
		// cin>>after;
		getline(cin,after);
		// cin.ignore(2048,'\n');
		fout<<"\t[ "<<getFormatTime()<<" ]"<<" after string | "<<after<<endl;
		getFiles(basedir,PATHNEED,modeSearch,match,filesFind);
		for(string file : filesFind){
			size_t sep = file.rfind("/");
			filename = file.substr(sep+1);
			size_t start = filename.find(target);
			if(start != string::npos){
				afterFile = file;
				filename.replace(start,target.size(),after);
				afterFile.replace(sep,afterFile.size(),filename);
				command = "powershell ren " + file + " " + filename;
				// 默认cmd执行命令不在当前目录下就会报错
				system(command.c_str());
				cout<<"change filename "<<file<<" to "<<filename<<endl;
				fout<<"\t\t[ "<<getFormatTime()<<" ]"<<" change filename "<<file<<" to "<<filename<<endl;
			}
		}
	}
	return 0;
}
