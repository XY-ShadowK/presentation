/** 
* 程序名: Mirror.cpp 
* 功  能: 实现灰度图像的水平镜像和垂直镜像 
*         测试图片test.bmp放在工程目录下 
*/  
#include <iostream>  
#include <windows.h>  
#include <fstream>  
#include <cstring>  
using namespace std;  
BITMAPFILEHEADER bmpFileHeader; //bmp文件头  
BITMAPINFOHEADER bmpInfoHeader; //bmp信息头
unsigned char *pBmpData;    //bmp位图数据     
unsigned char *pXBmpData;  //水平镜像bmp位图数据  
unsigned char *pYBmpData;  //垂直镜像bmp位图数据  
/** 
* 函数名: readBmp 
* 参  数: fileName -- 指向文件名的指针 
* 功  能: 读取将要处理的图片的信息，成功返回TRUE 
*/  
bool readBmp(char *fileName)  
{  
    FILE *fp = fopen(fileName,"rb");  //以二进制读方式打开  
    if (NULL == fp)  
    {     
        cout<<"open failure!"<<endl;  
        return FALSE;  
    }  
    //获得图片数据  
    fread(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,fp);
    fread(&bmpInfoHeader,sizeof(BITMAPINFOHEADER),1,fp);
    int imgSize = bmpInfoHeader.biSizeImage;  
    pBmpData = new unsigned char[imgSize];  
    //因为大小没有改变，所以一起处理了  
    pXBmpData = new unsigned char[imgSize];  
    pYBmpData = new unsigned char[imgSize];  
    fread(pBmpData,sizeof(unsigned char),imgSize,fp);  
    fclose(fp); //关闭文件  
    return TRUE;  
}  
/** 
* 函数名: mirror 
* 功  能: 对图片进行水平和垂直镜像操作 
*/  
void mirror()  
{
    int height = bmpInfoHeader.biHeight;
    int width = bmpInfoHeader.biWidth;
    int imgSize = bmpInfoHeader.biSizeImage;
    memset(pXBmpData,0,sizeof(unsigned char )*imgSize);
    memset(pYBmpData,0,sizeof(unsigned char )*imgSize);
    int lineByte = (width * 24 + 31) / 32 * 4;  //每行像素的字节数
    cout<<lineByte<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
        	for(int k=0;k<3;k++){
        	    *(pXBmpData+i*lineByte+width*3-j*3-3+k)=*(pBmpData+i*lineByte+j*3+k);
        	    *(pYBmpData+(height-i-1)*lineByte+j*3+k)=*(pBmpData+i*lineByte+j*3+k);
			}
        }
    }
}
/** 
* 函数名: writeBmp 
* 参  数: fileName -- 处理完之后的bmp图像 
* 功  能: 写入文件数据到相应的文件中 
*/  
bool writeBmp(char *fileName,unsigned char *bmpData)  
{  
    FILE *fp = fopen(fileName,"wb"); //以二进制写方式打开  
    if (NULL == fp)  
    {  
        cout<<"open failure!"<<endl;  
        return FALSE;  
    }  
    int imgSize = bmpInfoHeader.biSizeImage;  
    //写入数据  
    fwrite(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,fp);  
    fwrite(&bmpInfoHeader,sizeof(BITMAPINFOHEADER),1,fp);  
    fwrite(bmpData,sizeof(unsigned char),imgSize,fp);  
    fclose(fp);  //关闭文件  
    return TRUE;  
}  
/** 
* 函数名: work 
* 功  能: 主要处理 
*/  
void work()  
{  
    char readFileName[] = "test.bmp";  
    if (!readBmp(readFileName))  
    {  
        cout<<"read failure!"<<endl;  
        return ;  
    }  
    mirror();  
    char writeFileNameX[] = "X.bmp";  
    char writeFileNameY[] = "Y.bmp";  
    if (!writeBmp(writeFileNameX,pXBmpData))  
    {  
        cout<<"X write failure!"<<endl;  
        return ;  
    }  
    if (!writeBmp(writeFileNameY,pYBmpData))  
    {  
        cout<<"Y write failure!"<<endl;  
        return ;  
    }  
    char writeFileNameT[] = "t.bmp";
    writeBmp(writeFileNameT,pBmpData);
    //释放  
    delete []pBmpData;  
    delete []pXBmpData;  
    delete []pYBmpData;  
    cout<<"mirror success!"<<endl;  
  
}  
int main()  
{  
    work();  
    return 0;  
}  
