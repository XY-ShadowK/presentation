#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
BITMAPFILEHEADER bmpFileHeader;
BITMAPINFOHEADER bmpInfoHeader;
unsigned char *originBmpData,*mirrorHorizontallyBmpData,*mirrorVerticallyBmpData,*colorReverseBmpData;
bool readBmp(char* fileName)
{
	FILE *fp=fopen(fileName,"rb");
	if(fp==NULL){
		cout<<"open bmp file as rb failure!"<<endl;
		return false;
	}
	fread(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,fp);
	fread(&bmpInfoHeader,sizeof(BITMAPINFOHEADER),1,fp);
	int imageByteSize=bmpInfoHeader.biSizeImage;
	originBmpData=new unsigned char[imageByteSize];
	mirrorHorizontallyBmpData=new unsigned char[imageByteSize];
	mirrorVerticallyBmpData=new unsigned char[imageByteSize];
	colorReverseBmpData=new unsigned char[imageByteSize];
	fread(originBmpData,sizeof(unsigned char),imageByteSize,fp);
	fclose(fp);
	return true;
}
bool writeBmp(char* fileName,unsigned char* bmpData)
{
	FILE *fp=fopen(fileName,"wb");
	if(fp==NULL){
		cout<<"open bmp file as wb failure!"<<endl;
		return false;
	}
	int imageByteSize=bmpInfoHeader.biSizeImage;
	fwrite(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,fp);
	fwrite(&bmpInfoHeader,sizeof(BITMAPINFOHEADER),1,fp);
	fwrite(bmpData,sizeof(unsigned char),imageByteSize,fp);
	fclose(fp);
	return true;
}
void mirror()
{
	int height=bmpInfoHeader.biHeight;
	int width=bmpInfoHeader.biWidth;
	int imageByteSize=bmpInfoHeader.biSizeImage;
	memset(mirrorHorizontallyBmpData,0,sizeof(unsigned char)*imageByteSize);
	memset(mirrorVerticallyBmpData,0,sizeof(unsigned char)*imageByteSize);
	memset(colorReverseBmpData,0,sizeof(unsigned char)*imageByteSize);
	int lineWidthByteSize=width*3;
	int lineByteSize=lineWidthByteSize+(lineWidthByteSize%4?4-lineWidthByteSize%4:0);
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			for(int k=0;k<3;k++){
				*(mirrorHorizontallyBmpData+i*lineByteSize+lineWidthByteSize-j*3-3+k)=*(originBmpData+i*lineByteSize+j*3+k);
				*(mirrorVerticallyBmpData+(height-i-1)*lineByteSize+j*3+k)=*(originBmpData+i*lineByteSize+j*3+k);
				*(colorReverseBmpData+i*lineByteSize+j*3+k)=255-*(originBmpData+i*lineByteSize+j*3+k);
			}
		}
	}
}
int main()
{
	char originBmpFileName[100];
	cout<<"input the original 24bit bmp file name:";
	gets(originBmpFileName);
	if(!readBmp(originBmpFileName)){
		cout<<"read bmp file failure!"<<endl;
		return -1;
	}
	mirror();
	char fileNameMirrorHorizontallyBmp[]="mirrorHorizontallyBmp.bmp";
	char fileNameMirrorVerticallyBmp[]="mirrorVerticallyBmp.bmp";
	char fileNameColorReverseBmp[]="colorReverseBmp.bmp";
	if(!writeBmp(fileNameMirrorHorizontallyBmp,mirrorHorizontallyBmpData)){
		cout<<"write mirrorHorizontallyBmp file failure!"<<endl;
		return -1;
	}
	if(!writeBmp(fileNameMirrorVerticallyBmp,mirrorVerticallyBmpData)){
		cout<<"write mirrorVerticallyBmp file failure!"<<endl;
		return -1;
	}
	if(!writeBmp(fileNameColorReverseBmp,colorReverseBmpData)){
		cout<<"write colorReverseBmp file failure!"<<endl;
		return -1;
	}
	delete []originBmpData;
	delete []mirrorHorizontallyBmpData;
	delete []mirrorVerticallyBmpData;
	delete []colorReverseBmpData;
	cout<<"mirror over!"<<endl;
	return 0;
}
