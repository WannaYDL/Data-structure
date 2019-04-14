#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
/*
<begin,1>   <if,2>
<then,3>    <while,4>
<do,5>      <end,6>
<letter(letter|digit)*,10>  <digit digit*,11>
<+,13>      <-,14>
<*,15>      </,16>
<:,17>      <:=,18>
<<,20>      <<>,21>
<<=,22>     <>,23>
<>=,24>     <=,25>
<;,26>      <(,27>
<),28>      <#,0>
*/

char resourceProject[1000]; //源程序存放处
char token[20]={0};         //每次扫描的时候存储已经扫描到的结果
int syn = -1                //种别码
int pProject = 0;           //源程序指针，指向待扫描位置

//全局变量，关键字，其种别码为其索引号加一
static char reserveWord[6][10]={
    "begin","if","then","while","do","end"
};

//界符和运算符表
static char operOrDelimiter[16][5]={
    "+","-","*","/",":",":=","<","<>","<=",">",">=","=",";","(",")","#"
};
//界符和运算符的种别码
static int operValue[16]={13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,0};
//标识符表
static char IDentifierTbl[1000][50] = { "" };

//查找保留字
int searchReserve(char reserveWorld[][10],char s[])
{
    for(int i=0;i<6;i++){
        if(strcmp(reserveWord[i],s)== 0){
            //若查找成功返回种别码
            return i+1;
        }
    }
    return -1;
}
//判断是否为字母
bool IsLetter(char letter)
{
    if(letter>='a'&&letter<='z'||letter=='_'){
        return true;
    }
    else
        return false;
}
//判断是否为数字
bool IsDigit(char digit)
{
    if(digit>='0'&&digit<='9'){
        return true;
    }
    else
        return false;
}
//编译预处理
void filterResource(char r[],int pProject)
{
    char tempString[1000];//存放剔除
    int count =0;
    for(int i=0;i<=pProjec;i++){
        if(r[i]!='\n'&&r[i]!='\t'&&r[i]!='\v'&&r[i]!='\r'){
            tempString[count++]=r[i];
        }
    }
    tempString[count] = '\0';
    strcpy(r,tempString);
}
//分析子程序





























