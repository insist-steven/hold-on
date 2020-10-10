#include<stdlib.h>
#include<stdio.h>
struct test
{
    int date;
    struct test* next;

};

void printLink(struct test* head)
{
    struct test* point;
    point = head;
    while(point != NULL){
         printf("%d ",point -> date);
         point =  point -> next;
    }
         putchar('\n');
  
}
 

int searchLink(struct test* head,int date)
{   
     
     while(head != NULL){
          if(head->date == date){
                 return 1;       
          }
          head = head -> next;
     }   
      return 0;
}

struct test* insertFromfor(struct test* head,int date,struct test* new)
{
     struct test* p = head;
     if(p->date == date){
        new->next = head;
        return new;
    }
     while(p != NULL){
     
            if(p->next->date == date){
               new->next = p->next;
               p->next   = new;
               return head;
            }
        p = p->next; 
   } 
        printf("no this nodo\n");
        return head;
      


}
int insertFromBehind(struct test* head,int date,struct test* new)   
{  

     struct test* p = head;

     while(p != NULL){
        if(p->date == date){
           new->next = p->next;
           p->next = new;
           return 1;  
        }
        p = p->next; 
    }
        return 0;     
}

struct test* deletehead(struct test* head,int date)
{    
     struct test* p = head;
       if(p->date == date){
             head = p->next;
             free(p);
             return head;
    }
 
    while(p->next != NULL){
       if(p->date == date){
             p->next = p->next->next;
             return head;
      }         
       p = p->next;  
   } 
      
}

struct test* insertfromhead(struct test* head,struct test* new)
{        
    
      if(head == NULL){
            head = new;
              
      }else{
            new->next = head;                    
            head = new;
            }
   
     return head;          
}

struct test* createLink(struct test* head)
{
     struct test* new;

     while(1){
             new = (struct test*)malloc(sizeof(struct test));
             printf("put new nodo date\n");
             scanf("%d",&(new->date));
             if(new->date == 0){
                     printf("quit \n");
                     return head;
            }
             
             head = insertfromhead(head,new);

      }       
}
  
struct test* insertfromend(struct test* head,struct test* new)
{
       struct test* p = head;
       if(p == NULL){
          head = new;
          return head;
       
      }

       while(p->next != NULL){
             p = p->next;
    
      }
       p->next = new;
       return head; 

}


struct test* createLink2(struct test* head)
{
     struct test* new;

     while(1){
             new = (struct test*)malloc(sizeof(struct test));
             printf("put new nodo date\n");
             scanf("%d",&(new->date));
             if(new->date == 0){
                     free(new);
                     printf("quit \n");
                     return head;
            }

             head = insertfromend(head,new);

      }
}

int main()            
{       
           

      struct test* head = NULL;      
     
      head = createLink2(head);
      printLink(head);

      struct test t1 = {1999,NULL};
      head = insertfromhead(head,&t1);
      printLink(head);
    
     

      struct test t2 = {2000,NULL};
      head = insertfromend(head,&t2);
      printLink(head);
      

  /*   struct test* p = (struct test*)malloc(sizeof(struct test));
     struct test t2 = {2,NULL};
     struct test t3 = {3,NULL};
     struct test t4 = {4,NULL};
     
     p->date = 1;           
 
     p->next = &t2;
     t2.next = &t3;
     t3.next = &t4;
     
     head = p;
     struct test new2 = {101,NULL};
        
     head = insertFromfor(head,1,&new2);
     puts("new node\n");
     printLink(head);
        
     struct test new3 = {103,NULL};        
     head = insertFromfor(head,1,&new3);
     puts("new node\n");
     printLink(head);
   /
     head = deletehead(head,3);
     printLink(head);

   struct test new = {100,NULL};  
     printf("Use t1 print three nums\n");
     printLink(&t1); 
       
     puts("new node\n");  
     insertFromBehind(&t1,3,&new);  
     printLink(&t1);
     int ret;
     ret = searchLink(&t1,1);
     if(ret == 0){
        printf("no 1\n");
    }else{
        printf("have 1\n"); 
    }
     ret = searchLink(&t1,8);
     if(ret == 0){
        printf("no 8\n");
    }else{
        printf("have 8\n");
   
    }*/
 
          return 0;      
}

