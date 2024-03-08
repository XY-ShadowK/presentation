import os
import re
import numpy as np
import time
import requests
import csv
import pandas

from bs4 import BeautifulSoup
from fake_useragent import UserAgent
from openpyxl import Workbook, load_workbook

def getMovieLink(url,headers):
    try:
        r = requests.get(url,headers=headers,timeout=10)
        r.raise_for_status()
        r.encoding = 'utf-8'
        soup = BeautifulSoup(r.text,'html.parser')
        lsts = soup.find_all(attrs={'class':'hd'})
        hrefs = []
        for lst in lsts:
            href = lst.a['href']
            hrefs.append(href)
        return hrefs
    except:
        print('get movie links error!')

def getMovieInfo(url,headers):
    r = requests.get(url,headers=headers,timeout=10)
    r.raise_for_status()
    r.encoding = 'utf-8'
    soup = BeautifulSoup(r.text,'html.parser')
    name = soup.find(attrs={'property':'v:itemreviewed'}).text
    print('正在爬取 '+name)
    infos = soup.find(attrs={'id':'info'}).text.split('\n')[1:11]
    director = infos[0].split(': ')[1]
    scriptwriter = infos[1].split(': ')[1]
    actor = infos[2].split(': ')[1]
    moveType = infos[3].split(': ')[1]
    score = soup.find(attrs={'property':'v:average'}).text
    votes = soup.find(attrs={'property':'v:votes'}).text
    movieInfo = [name,director,scriptwriter,actor,moveType,score,votes]
    return movieInfo

def getNovelContent(url,headers):
    r = requests.get(url,headers=headers,timeout=10)
    r.raise_for_status()
    r.encoding = 'utf-8'
    soup = BeautifulSoup(r.text,'html.parser')
    title = []
    title = soup.find(attrs={'class':'z _styletitle'}).text.split('›')
    name = title[2]
    print('正在爬取 '+name)
    content = soup.find(attrs={'class':'novel_content'}).text
    ruleMatch = '[最新网址：www.wxshuku.cc]'
    content = re.sub(ruleMatch,'',content)
    return content

def saveToExcel(file,infos):
    try:
        if not os.path.exists(file):
            wb = Workbook()
            ws = wb.active
            ws.title = 'sheet1'
            ws.append(tableTitle)
            for info in infos:
                ws.append(info)
            wb.save(file)
            return True
        return False
    except:
        return False

def saveToCSV(file,infos):
    try:
        pd = pandas.DataFrame(columns=tableTitle,data=infos)
        pd.to_csv(file,header=None,index=None)
        return True
    except:
        return False
    
def saveToTxt(file,contents):
    try:
        np.savetxt(file,contents,fmt='%s',encoding='utf-8')
        return True
    except:
        return False

def crawler_doubanTOP250(headers):
    hrefs = []
    for i in range(10):
        print('正在爬取第 '+str(i+1)+' 页电影网址')
        url = 'https://movie.douban.com/top250?start={}&filter='.format(i * 25)
        hrefs.extend(getMovieLink(url,headers))
        time.sleep(5)
    movieInfos = []
    for href in hrefs:
        movieInfos.append(getMovieInfo(href,headers))
        time.sleep(0.5)
    if saveToCSV('TOP250.csv',movieInfos):
        print('save successfully!')
    else:
        print('save failedly!')

def crawler_wsshuku(headers):
    contents = []
    for i in range(80):
        url = 'http://www.wxshuku.cc/84/84717/{}.html'.format(16167683 + i)
        content = getNovelContent(url,headers)
        contents.append(content)
        time.sleep(1)
    if saveToTxt('novelContent.txt',contents):
        print('save successfully!')
    else:
        print('save failedly!')

headers_doubanTOP250_chrome = {
    "Accept" : "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
    "Accept-Encoding" : "gzip, deflate, br",
    "Accept-Language" : "zh-CN,zh-TW;q=0.9,zh-HK;q=0.8,zh;q=0.7,en;q=0.6",
    "Cookie" : 'll="108296"; bid=pjke9r1KvxI; _pk_id.100001.4cf6=b8645d55f89639b3.1697372913.; __utmz=30149280.1697372913.1.1.utmcsr=link.zhihu.com|utmccn=(referral)|utmcmd=referral|utmcct=/; __utmz=223695111.1697372913.1.1.utmcsr=link.zhihu.com|utmccn=(referral)|utmcmd=referral|utmcct=/; __yadk_uid=DosXxh4kNSVpktPodQ2YzSIlx1BRK9gw; _vwo_uuid_v2=D8989F367332B6A10108DBC2850E62083|aaf2dad022195eda6c5a55ee38dcb49c; Hm_lvt_16a14f3002af32bf3a75dfe352478639=1697372965; __utmc=30149280; __utmc=223695111; ap_v=0,6.0; _pk_ref.100001.4cf6=%5B%22%22%2C%22%22%2C1697692764%2C%22https%3A%2F%2Flink.zhihu.com%2F%3Ftarget%3Dhttps%3A%2F%2Fmovie.douban.com%2F%22%5D; _pk_ses.100001.4cf6=1; __utma=30149280.153346164.1697372913.1697642359.1697692764.4; __utmb=30149280.0.10.1697692764; __utma=223695111.667001514.1697372913.1697642359.1697692764.4; __utmb=223695111.0.10.1697692764',
    "Host" : "movie.douban.com",
    "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36"
}
headers_wsshuku_dot_cc_chrome = {
    "Accept" : "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
    "Accept-Encoding" : "gzip, deflate",
    "Accept-Language" : "zh-CN,zh-TW;q=0.9,zh-HK;q=0.8,zh;q=0.7,en;q=0.6",
    "Cookie" : "Hm_lvt_ae90f9841288e77167239b3b799d1132=1695440572,1697795243; Hm_lpvt_ae90f9841288e77167239b3b799d1132=1697795243",
    "Host" : "www.wxshuku.cc",
    "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36"
}
tableTitle = ['片名','导演','编剧','主演','类型','评分','评价人数']

# crawler_doubanTOP250(headers_doubanTOP250_chrome)
crawler_wsshuku(headers_wsshuku_dot_cc_chrome)