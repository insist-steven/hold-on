#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int score;
    char *name;
};

int main()
{
	int i;
    struct Student stus[2];
    struct Student maxStu;
    struct Student minStu;
    
    for(i=0;i<sizeof(stus)/sizeof(stus[0]);i++){
        printf("�������%d��ѧ�������֣�\n",i+1);
        stus[i].name = (char*)malloc(123);
        scanf("%s",stus[i].name);
        
        printf("�������%d��ѧ���ķ�����\n",i+1);
        scanf("%d",&stus[i].score);
    }
        
        for(i=0;i<sizeof(stus)/sizeof(stus[0]);i++){
            printf("��%d����ѧ�������ֺͷ�����\n",i+1);
            printf("%s:%d\n",stus[i].name,stus[i].score);
        }
        
        maxStu = minStu = stus[0];
        for(i=0;i<sizeof(stus)/sizeof(stus[0]);i++){
           if(maxStu.score<stus[i].score){
              maxStu = stus[i];
           }
           if(minStu.score>stus[i].score){
              minStu = stus[i];
           }               
        }
        printf("����߷ֵ��ǣ�%s:%d\n",maxStu.name,maxStu.score);
	system("pause");
	return 0;
}
