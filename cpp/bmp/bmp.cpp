/** 
* ������: Mirror.cpp 
* ��  ��: ʵ�ֻҶ�ͼ���ˮƽ����ʹ�ֱ���� 
*         ����ͼƬtest.bmp���ڹ���Ŀ¼�� 
*/  
#include <iostream>  
#include <windows.h>  
#include <fstream>  
#include <cstring>  
using namespace std;  
BITMAPFILEHEADER bmpFileHeader; //bmp�ļ�ͷ  
BITMAPINFOHEADER bmpInfoHeader; //bmp��Ϣͷ
unsigned char *pBmpData;    //bmpλͼ����     
unsigned char *pXBmpData;  //ˮƽ����bmpλͼ����  
unsigned char *pYBmpData;  //��ֱ����bmpλͼ����  
/** 
* ������: readBmp 
* ��  ��: fileName -- ָ���ļ�����ָ�� 
* ��  ��: ��ȡ��Ҫ�����ͼƬ����Ϣ���ɹ�����TRUE 
*/  
bool readBmp(char *fileName)  
{  
    FILE *fp = fopen(fileName,"rb");  //�Զ����ƶ���ʽ��  
    if (NULL == fp)  
    {     
        cout<<"open failure!"<<endl;  
        return FALSE;  
    }  
    //���ͼƬ����  
    fread(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,fp);
    fread(&bmpInfoHeader,sizeof(BITMAPINFOHEADER),1,fp);
    int imgSize = bmpInfoHeader.biSizeImage;  
    pBmpData = new unsigned char[imgSize];  
    //��Ϊ��Сû�иı䣬����һ������  
    pXBmpData = new unsigned char[imgSize];  
    pYBmpData = new unsigned char[imgSize];  
    fread(pBmpData,sizeof(unsigned char),imgSize,fp);  
    fclose(fp); //�ر��ļ�  
    return TRUE;  
}  
/** 
* ������: mirror 
* ��  ��: ��ͼƬ����ˮƽ�ʹ�ֱ������� 
*/  
void mirror()  
{
    int height = bmpInfoHeader.biHeight;
    int width = bmpInfoHeader.biWidth;
    int imgSize = bmpInfoHeader.biSizeImage;
    memset(pXBmpData,0,sizeof(unsigned char )*imgSize);
    memset(pYBmpData,0,sizeof(unsigned char )*imgSize);
    int lineByte = (width * 24 + 31) / 32 * 4;  //ÿ�����ص��ֽ���
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
* ������: writeBmp 
* ��  ��: fileName -- ������֮���bmpͼ�� 
* ��  ��: д���ļ����ݵ���Ӧ���ļ��� 
*/  
bool writeBmp(char *fileName,unsigned char *bmpData)  
{  
    FILE *fp = fopen(fileName,"wb"); //�Զ�����д��ʽ��  
    if (NULL == fp)  
    {  
        cout<<"open failure!"<<endl;  
        return FALSE;  
    }  
    int imgSize = bmpInfoHeader.biSizeImage;  
    //д������  
    fwrite(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,fp);  
    fwrite(&bmpInfoHeader,sizeof(BITMAPINFOHEADER),1,fp);  
    fwrite(bmpData,sizeof(unsigned char),imgSize,fp);  
    fclose(fp);  //�ر��ļ�  
    return TRUE;  
}  
/** 
* ������: work 
* ��  ��: ��Ҫ���� 
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
    //�ͷ�  
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
