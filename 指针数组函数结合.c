#include <stdio.h>
#include <stdlib.h>
void initScores(int *sat, int len)
 {   int i;
    
    for(i=0;i<len;i++){
        printf("�������%d��ѧ���ķ�����",i+1);
        scanf("%d",sat);
        if(*sat >100 || *sat<0){
           printf("gundan");
           system("pause");
           exit(-1);
        }
        sat++;
    }
 }
 
 void printscores(int *sat, int len)
 {
    int i;
    
    for(i=0;i<len;i++){
        printf("��%d��ѧ���ĳɼ��ǣ�%d\n",i+1,*sat++);
    }
   
 }
 
 int getmax(int *sat, int len)
 {
    int max;
    int i;
    max = *sat;
    for(i=0;i<len;i++){
       if(max<*sat){
          max = *sat;
       }
       sat++;
    }
    return max;
 }
 
  int getmin(int *sat, int len)
 {
    int min;
    int i;
    min = *sat;
    for(i=0;i<len;i++){
       if(min>*sat){
          min = *sat;
       }
       sat++;
    }
    return min;
 }
 
float getaverage(int *sat, int len)
{
    float average;
    int i;
    int sum = 0;
    
    for(i=0;i<len;i++){
        sum = sum + *sat; 
        sat++;
    }
    
    average=(float)sum/10;
    return average;
}

void printret(int data1,int data2, float data3)
{
     printf("��߷֣�%d\n��ͷ֣�%d\nƽ���֣�%f\n",data1,data2,data3);
}
 int main()
{   int scores[10];
    int len;
    int max;
    int min;
    float average;
    
    len = sizeof(scores)/sizeof(scores[0]);
    
    initScores(scores,len);
   
    printscores(scores,len);
    
    max = getmax(scores,len);
   
    min = getmin(scores,len);
    
    average = getaverage(scores,len);
   
    printret(max, min, average);
	system("pause");
	return 0;
}
