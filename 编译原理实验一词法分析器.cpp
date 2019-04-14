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

char resourceProject[1000]; //Դ�����Ŵ�
char token[20]={0};         //ÿ��ɨ���ʱ��洢�Ѿ�ɨ�赽�Ľ��
int syn = -1                //�ֱ���
int pProject = 0;           //Դ����ָ�룬ָ���ɨ��λ��

//ȫ�ֱ������ؼ��֣����ֱ���Ϊ�������ż�һ
static char reserveWord[6][10]={
    "begin","if","then","while","do","end"
};

//������������
static char operOrDelimiter[16][5]={
    "+","-","*","/",":",":=","<","<>","<=",">",">=","=",";","(",")","#"
};
//�������������ֱ���
static int operValue[16]={13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,0};
//��ʶ����
static char IDentifierTbl[1000][50] = { "" };

//���ұ�����
int searchReserve(char reserveWorld[][10],char s[])
{
    for(int i=0;i<6;i++){
        if(strcmp(reserveWord[i],s)== 0){
            //�����ҳɹ������ֱ���
            return i+1;
        }
    }
    return -1;
}
//�ж��Ƿ�Ϊ��ĸ
bool IsLetter(char letter)
{
    if(letter>='a'&&letter<='z'||letter=='_'){
        return true;
    }
    else
        return false;
}
//�ж��Ƿ�Ϊ����
bool IsDigit(char digit)
{
    if(digit>='0'&&digit<='9'){
        return true;
    }
    else
        return false;
}
//����Ԥ����
void filterResource(char r[],int pProject)
{
    char tempString[1000];//����޳�
    int count =0;
    for(int i=0;i<=pProjec;i++){
        if(r[i]!='\n'&&r[i]!='\t'&&r[i]!='\v'&&r[i]!='\r'){
            tempString[count++]=r[i];
        }
    }
    tempString[count] = '\0';
    strcpy(r,tempString);
}
//�����ӳ���





























