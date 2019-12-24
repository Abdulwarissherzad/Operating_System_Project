#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>

#define LINE_MAX 1000

using namespace std;
unsigned int num[3];
FILE *fp ;
 char line[LINE_MAX];
struct node
{
 int id;
 int bt;
 int art;
 int prior;
 int wtt = 0;
 struct node *next;
};
void RR(struct node *header);
struct node *deleteBack(struct node *header);
struct node * createNode(int id,int bt,int art,int prior);
struct node * insertBack(struct node *header, int id,int bt,int art,int prior);
struct node * insertFront(struct node *header, int id,int bt,int art,int prior);
struct node * insertAfter(struct node *afterNode, int id,int bt,int art,int prior);
int * select(struct node *afterNode ,int position,int *some1,int *some2,int *some3,int *some4);
void swapLL(struct node **header,int x,int y);
int selectEx(struct node *header ,int position,int some);
void display(struct node *header);
int siz(struct node *header);
void FCFS(struct node *heade);
void RoundRobin(struct node *heade);
void ShortestPreempt(struct node *heade);
void ShortestNonPreemt(struct node *header);
void PriorPreempt(struct node *heade);
void PriorNonPreempt(struct node *header);
void deletenode(struct node *&first, int data);
struct node *sortMassivbt(struct node *header)
{struct node *temp=header;
struct node *temp2=NULL;
int time=0;
int kk  = siz(temp);
for(int p = 0 ; p<10000;p++){
temp=header;
while(temp!=NULL)
    {
        if(temp->bt==time)  temp2=insertBack(temp2,temp->id,temp->bt,temp->art,temp->prior);
        temp=temp->next;
    }
        time++;
}
return temp2;
}
  char *in = NULL;
  char *output = NULL;
void oneMore(struct node *header);
void AddNumb(struct node *header,int fromWhere,int numb,int what);
struct node *sortMassiv(struct node *header)
{struct node *temp=header;
struct node *temp2=NULL;
int time=0;
int kk  = siz(temp);
for(int p = 0 ; p<10000;p++){
temp=header;
while(temp!=NULL)
    {
        if(temp->art==time)  temp2=insertBack(temp2,temp->id,temp->bt,temp->art,temp->prior);
        temp=temp->next;
    }
        time++;
}
return temp2;
}
int main(int argc, char **argv)
{
   char *aflag = NULL;
  int index;
  int c;  
  //for input and out file
in  = "input.txt";
output = "output.txt";
int  opterr = 0;
while ((c = getopt (argc, argv, "f:o:")) != -1)
    switch (c)
      {
      case 'f':
        in = optarg;
        break;
      case 'o':
        output = optarg;
        break;
      case '?':
        if (optopt == 'o')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
  printf ("f = %s, output = %s\n",in, output);
  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
    fp = fopen(output, "w");
fprintf(fp,"");
fclose(fp);
struct node *header = NULL;int inc = 1;
 if ((fp = fopen(in, "r")) == NULL)
    {printf("Cannot open file");return 0;}
 while (fgets(line, LINE_MAX, fp) != NULL) {
    sscanf(line,"%d:%d:%d\n",&num[0],&num[1],&num[2]);
   header=insertBack(header, inc,num[0], num[1],num[2]);
   inc++;
   }
  fclose(fp);
    int switcher = 0 , vibor,preemnotpreem;
   while(switcher ==0)
    {
    	printf("\n\n\n\nPlease choose a scheduling method\n");
    	        printf("1:-First come First Served method\n");
    	    	printf("2:-Shortest job first method\n");
    	    	printf("3:-Priority method\n");
                printf("4:-Round Robing method\n");
                printf("5:-Exit\n");
                scanf("%d",&vibor);
                switch(vibor)
                {
                	case 1: printf("This algoritm  has just Non-Preemprive scheduling method\n");
                	FCFS(header);
                	break;
                	case 2: printf("Make a choise :\n");
                	printf("1:- For Preemptive method\n");
                	printf("2:- For non-preemptive method\n");
                	scanf("%d",&preemnotpreem);
                	switch(preemnotpreem)
                	{
                		case 1: printf("Preemptive method\n");
                		ShortestPreempt(header);
  break;
                		case 2: printf("Non-preemtive method\n");
                		ShortestNonPreemt(header);
                                                     break;
                        default : printf("Wrong choise");   	break;
					}
					break;
					case 3: printf("Make a choise :\n");
                	printf("1:- For Preemptive method\n");
                	printf("2:- For non-preemptive method\n");
                	scanf("%d",&preemnotpreem);
                	switch(preemnotpreem)
                	{
                		case 1: printf("Preemptive method\n");
                		PriorPreempt(header);
                		  break;
                		case 2: printf("Non-preemtive method\n");
                         PriorNonPreempt(header);
                		  break;
                        default : printf("Wrong choise");   	break;
					}
					break;
					case 4: printf("This algoritm  has just Preemprive scheduling method");
					RR(header);
					break;
					case 5: printf("Exit successfull done"); switcher++;
					break;
					default:printf("Wrong choise!!!");
				}
	}
}
void oneMore(struct node *header)
{
    int bt,art,prior;
    printf("\nWrite burst time : ");
    scanf("%d",&bt);
        printf("\nWrite arrival time : ");
            scanf("%d",&art);
            printf("\nWrite priority :");
                scanf("%d",&prior);
                header= insertBack(header,siz(header)+1,bt,art,prior);
}
void PriorNonPreempt(struct node *heade)
{int l = 0 ,i=0;char newV;
while(l==0)
{
    printf("Do you want add new variables? y/n");
    scanf("%c",&newV);
   if(newV=='y') oneMore(heade);
   else if(newV=='n') break;
   else {printf("\nWrong choise select again\n");}
}
    int sz  = siz(heade),waitingTime = 0;//Reding from LinkList
    struct node *header=NULL;
    for(i = 1;i<=sz;i++)
    {
    header=insertBack(header,selectEx(heade,i,0),selectEx(heade,i,1),selectEx(heade,i,2),selectEx(heade,i,3));
}
int temprar=0,wt=0;
double average ;
int j = 0 ;
fp = fopen(output, "a");
fprintf(fp,"\Priority scheduling non-preemptive ");
fclose(fp);
header=sortMassiv(header);
int counter =0 , timer=0,smallest;
struct node *proc = NULL;
struct node *proceds = header;
struct node *header2 = NULL;
struct node *tmp = proceds;
for(i = 1;i<=sz;i++)
    {
    header2=insertBack(header2,selectEx(tmp,i,0),selectEx(tmp,i,1),selectEx(tmp,i,2),selectEx(tmp,i,3));
}
display(header2);
for(timer=0;counter!=sz;timer++)
{
smallest=sz+2;
    for(i = 1;i<=sz;i++)
    {
        if(selectEx(proceds,i,2) <= timer )
		{
		if(selectEx(proceds,i,3)<selectEx(proceds,smallest,3) )
		{
		if(selectEx(proceds,i,1)>0)
        {
            smallest=i;
           printf("\nSmallest = %d\n",smallest);
        }
		}
		}
    }
           timer+=smallest;
   proc=insertBack(proc,selectEx(proceds,smallest,0),selectEx(proceds,smallest,1),selectEx(proceds,smallest,2),selectEx(proceds,smallest,3));
       AddNumb(proceds,smallest,0,1);
    if(selectEx(proceds,smallest,1)==0)
    {
        counter++;
    }
}
printf("\n");
display(proc);
fp = fopen(output, "a");
printf("P%d = %d ms\n",selectEx(proc,1,0),0);
fprintf(fp,"P%d = %d ms\n",selectEx(proc,1,0),0);
fclose(fp);
for( i = 1 ; i <sz;i++)
{
temprar+=selectEx(proc,i,1);
{
waitingTime=temprar-selectEx(proc,i+1,2);
wt+=waitingTime;
fp = fopen(output, "a");
printf("P%d = %d ms\n",selectEx(proc,i+1,0),waitingTime);
fprintf(fp,"P%d = %d ms\n",selectEx(proc,i+1,0),waitingTime);
fclose(fp);
}}
average = (double)wt/(i);
fp = fopen(output, "a");
fprintf(fp,"Average waiting time = %f",average);
fclose(fp);
printf("Average waiting time = %f",average);
}
void PriorPreempt(struct node *heade)
{
int l = 0 ,i=0;char newV;
while(l==0)
{
    printf("Do you want add new variables? y/n");
    scanf("%c",&newV);
   if(newV=='y') oneMore(heade);
   else if(newV=='n') break;
   else {printf("\nWrong choise select again\n");}
}
    int sz  = siz(heade),waitingTime = 0;
    struct node *header=NULL;
    for(i = 1;i<=sz;i++)
    {
    header=insertBack(header,selectEx(heade,i,0),selectEx(heade,i,1),selectEx(heade,i,2),selectEx(heade,i,3));
}
int temprar=0,wt=0;
double average ;
int j = 0 ;
header=sortMassiv(header);
int counter =0 , timer=0,smallest;
struct node *proc = NULL;
struct node *proceds = header;
struct node *header2 = NULL;
for(i = 1;i<=sz;i++)
    {
    header2=insertBack(header2,selectEx(proceds,i,0),selectEx(proceds,i,1),selectEx(proceds,i,2),selectEx(proceds,i,3));
}
for(timer=0;counter!=sz;timer++)
{
smallest=sz+2;
    for(i = 1;i<=sz;i++)
    {
        if(selectEx(proceds,i,2) <= timer )
		{
		if(selectEx(proceds,i,3)<selectEx(proceds,smallest,3) )
		{
		if(selectEx(proceds,i,1)>0)
        {
            smallest=i;    
        }}}
    }
    AddNumb(proceds,smallest,selectEx(proceds,smallest,1)-1,1);
   proc=insertBack(proc,selectEx(proceds,smallest,0),selectEx(proceds,smallest,1),selectEx(proceds,smallest,2),selectEx(proceds,smallest,3));
    if(selectEx(proceds,smallest,1)==0)
    {   counter++;
    }
}
printf("\n");
int nums[4];
int sz2=siz(proc);
int k = 0 ;
int newLL[sz2+1][5];
j = 1;
int increm  = 1 ;
int wat =0 ,kk=0;
int uu = 0 ,ext = 0,kot=0,sumAll=0;
 fp = fopen(output, "a");
fprintf(fp,"\nPrior Preemptive\n");
fclose(fp);
for(i = 1 ; i <=sz;i++)
{
for(j = 1 +uu ; j<=sz2;j++){
if(selectEx(proc,j,1)==0)
{
if(selectEx(proc,j,1)==0)
{
int a =1;
k=j-selectEx(proc,j,2)-selectEx(header2,selectEx(proc,j,0),1);
a++;
            printf("i%d = %d ms\n",selectEx(proc,j,0),k);
            uu=j;
            sumAll+=k;
             fp = fopen(output, "a");
fprintf(fp,"i%d = %d ms\n",selectEx(proc,j,0),k);
fclose(fp);
            break;}
        }}
}
double answer = (double)sumAll/(sz);
 fp = fopen(output, "a");
fprintf(fp,"Average waiting time   = %f",answer);
fclose(fp);
printf("Average waiting time   = %f",answer);
}
void ShortestPreempt(struct node *heade)
{ int l = 0 ,i=0;char newV;
while(l==0)
{
    printf("Do you want add new variables? y/n");
    scanf("%c",&newV);
   if(newV=='y') oneMore(heade);
   else if(newV=='n') break;
   else {printf("\nWrong choise select again\n");}
}
    int sz  = siz(heade),waitingTime = 0;
    struct node *header=NULL;
    for(i = 1;i<=sz;i++)
    {
    header=insertBack(header,selectEx(heade,i,0),selectEx(heade,i,1),selectEx(heade,i,2),selectEx(heade,i,3));
}
int temprar=0,wt=0;
double average ;
int j = 0 ;
header=sortMassiv(header);
int counter =0 , timer=0,smallest;
struct node *proc = NULL;
struct node *proceds = header;
struct node *header2 = NULL;
struct node *tmp = proceds;
for(i = 1;i<=sz;i++)
    {
    header2=insertBack(header2,selectEx(tmp,i,0),selectEx(tmp,i,1),selectEx(tmp,i,2),selectEx(tmp,i,3));
}
display(header2);
for(timer=0;counter!=sz;timer++)
{
smallest=sz+2;
    for(i = 1;i<=sz;i++)
    {
        if(selectEx(proceds,i,2) <= timer )
		{
		if(selectEx(proceds,i,1)<selectEx(proceds,smallest,1) )
		{
		if(selectEx(proceds,i,1)>0)
        {
            smallest=i;
           printf("\nSmallest = %d\n",smallest);
        
       }}}}
    AddNumb(proceds,smallest,selectEx(proceds,smallest,1)-1,1);
   proc=insertBack(proc,selectEx(proceds,smallest,0),selectEx(proceds,smallest,1),selectEx(proceds,smallest,2),selectEx(proceds,smallest,3));
    if(selectEx(proceds,smallest,1)==0)
    {   counter++;
    }
}
printf("\n");
display(proc);
int nums[4];
int sz2=siz(proc);
int k = 0 ;
int newLL[sz2+1][5];
j = 1;
int increm  = 1 ;
int wat =0 ,kk=0;
int uu = 0 ,ext = 0,kot=0,sumAll=0;
 fp = fopen(output, "a");
fprintf(fp,"\nShortest Job First Preemptive\n");
fclose(fp);
for(i = 1 ; i <=sz;i++)
{
for(j = 1 +uu ; j<=sz2;j++){
if(selectEx(proc,j,1)==0)
{
if(selectEx(proc,j,1)==0)
{
int a =1;
k=j-selectEx(proc,j,2)-selectEx(header2,selectEx(proc,j,0),1);
a++;
            printf("i%d = %d ms\n",selectEx(proc,j,0),k);
            uu=j;
            sumAll+=k;
             fp = fopen(output, "a");
fprintf(fp,"i%d = %d ms\n",selectEx(proc,j,0),k);
fclose(fp);
            break;}
        }}
}
double answer = (double)sumAll/(sz);
 fp = fopen(output, "a");
fprintf(fp,"Average waiting time   = %f",answer);
fclose(fp);
printf("Average waiting time   = %f",answer);
}
void ShortestNonPreemt(struct node *heade)
{int l = 0 ,i=0;char newV;
while(l==0)
{
    printf("Do you want add new variables? y/n");
    scanf("%c",&newV);
   if(newV=='y') oneMore(heade);
   else if(newV=='n') break;
   else {printf("\nWrong choise select again\n");}
}
    int sz  = siz(heade),waitingTime = 0;
    struct node *header=NULL;
    for(i = 1;i<=sz;i++)
    {
    header=insertBack(header,selectEx(heade,i,0),selectEx(heade,i,1),selectEx(heade,i,2),selectEx(heade,i,3));
}
int temprar=0,wt=0;
double average ;
int j = 0 ;
fp = fopen(output, "a");
fprintf(fp,"\nShortest Job first non-preemptive ");
fclose(fp);
header=sortMassiv(header);
int counter =0 , timer=0,smallest;
struct node *proc = NULL;
struct node *proceds = header;
struct node *header2 = NULL;
struct node *tmp = proceds;
for(i = 1;i<=sz;i++)
    {
    header2=insertBack(header2,selectEx(tmp,i,0),selectEx(tmp,i,1),selectEx(tmp,i,2),selectEx(tmp,i,3));
}
display(header2);
for(timer=0;counter!=sz;timer++)
{
smallest=sz+2;
    for(i = 1;i<=sz;i++)
    {
        if(selectEx(proceds,i,2) <= timer )
		{
		if(selectEx(proceds,i,1)<selectEx(proceds,smallest,1) )
		{
		if(selectEx(proceds,i,1)>0)
        {
            smallest=i;
           printf("\nSmallest = %d\n",smallest);
        }}}}
           timer+=smallest;
   proc=insertBack(proc,selectEx(proceds,smallest,0),selectEx(proceds,smallest,1),selectEx(proceds,smallest,2),selectEx(proceds,smallest,3));
       AddNumb(proceds,smallest,0,1);
    if(selectEx(proceds,smallest,1)==0)
    {
        counter++;  }
}
printf("\n");
fp = fopen(output, "a");
printf("P%d = %d ms\n",selectEx(proc,1,0),0);
fprintf(fp,"\nP%d = %d ms\n",selectEx(proc,1,0),0);
fclose(fp);
for( i = 1 ; i <sz;i++)
{
temprar+=selectEx(proc,i,1);
{
waitingTime=temprar-selectEx(proc,i+1,2);
wt+=waitingTime;
printf("P%d = %d ms\n",selectEx(proc,i+1,0),waitingTime);
fp = fopen(output, "a");
fprintf(fp,"P%d = %d ms\n",selectEx(proc,i+1,0),waitingTime);
fclose(fp);
}}
average = (double)wt/(i);
fp = fopen(output, "a");
fprintf(fp,"Average waiting time = %f",average);
fclose(fp);
printf("Average waiting time = %f",average);}
void RoundRobin(struct node *heade)
{
struct node *header=NULL;
    int l = 0 ;char newV;
while(l==0)
{
    printf("Do you want add new variables? y/n \n");
    scanf("%c",&newV);
   if(newV=='y') oneMore(heade);
   else if(newV=='n') break;
   else {printf("\nWrong choise select again\n");}
}
printf("\nWrite quantum for each process\n");
int quant;
scanf("%d",&quant);
	int sz  = siz(heade),waitingTime = 0;
    int selectMass[4],LL[sz][5];
int i = 0,temprar=0,wt=0;
    for(i = 1;i<=sz;i++)
    {
    header=insertBack(header,selectEx(heade,i,0),selectEx(heade,i,1),selectEx(heade,i,2),selectEx(heade,i,3));
}
double average ;
int exit = 0 ;
struct node *proc =header;
int j = 0 ;
int numb;
proc=sortMassiv(proc);
    display(proc);
 int wtt =0 ;
    struct node *processes = NULL;
    int maxi = 0;
    for(i = 1 ; i <sz;i++)
    {
        if(selectEx(proc,i,1)>selectEx(proc,i+1,1)) maxi = selectEx(proc,i,1);
        }
      int d = 0 ,kolvo =0 ,waiting =0 ;
    for(int d = maxi ; d>=0;d-=quant)
        {kolvo++;
        for(i = 1; i<=sz;i++)
        {
            if(selectEx(proc,i,1)!=0)
            {
                if(selectEx(proc,i,1)==quant)
                {
                       AddNumb(proc,i,0,1);
                    processes = insertBack(processes,selectEx(proc,i,0),selectEx(proc,i,1),selectEx(proc,i,2),selectEx(proc,i,3));
                  for(wtt=1;wtt<=sz;wtt++)
                  {
                      if(wtt==i);
                      else
                      {
                          if(selectEx(proc,wtt,1)==0);
                          else
                          {
                            AddNumb(proc,i,selectEx(proc,wtt,4)+quant,4);
                          }
                      }
                  }
                   waiting+=quant;
                }
                else if(selectEx(proc,i,1)>quant)
                          { 
                          AddNumb(proc,i,selectEx(proc,i,1)-quant,1);
                    processes = insertBack(processes,selectEx(proc,i,0),selectEx(proc,i,1),selectEx(proc,i,2),selectEx(proc,i,3));
                                      waiting+=quant;
                       for(wtt=1;wtt<=sz;wtt++)
                  {
                      if(wtt==i);
                      else
                      {
                          if(selectEx(proc,wtt,1)==0);
                          else
                          {
                          AddNumb(proc,wtt,selectEx(proc,wtt,4)+quant,4);
                          }
                      }
                  }
                }
                else if(selectEx(proc,wtt,1)<quant)
                {                  
                         waiting+=  selectEx(proc,i,1);
                      for(wtt=1;wtt<=sz;wtt++)
                  {
                      if(wtt==i);
                      else
                      {
                          if(selectEx(proc,wtt,1)==0);
                          else
                          {
                            AddNumb(proc,wtt,selectEx(proc,wtt,4)+selectEx(proc,i,1),4);
                          }
                      }
                  }
                        AddNumb(proc,i,0,1);
                    processes = insertBack(processes,selectEx(proc,i,0),selectEx(proc,i,1),selectEx(proc,i,2),selectEx(proc,i,3));
                }
            }
        } 
                         maxi-=quant;
}
printf("\nTurnAround Waiting time = %d\n",waiting);
fp = fopen(output, "a");
            fprintf(fp,"\nRound Robin Scheduling\n");
fclose(fp);
int avsum = 0 ;
display(proc);
    for(i = 1; i  <=sz;i++)
        {
            printf("\nP%d = %d \n",selectEx(proc,i,0),selectEx(proc,i,4)-selectEx(proc,i,2));
            fp = fopen(output, "a");
            fprintf(fp,"\nP%d = %d \n",selectEx(proc,i,0),selectEx(proc,i,4)-selectEx(proc,i,2));
fclose(fp);
            avsum+=selectEx(proc,i,4)-selectEx(proc,i,2);
        }
double averag = (double)avsum/(i-1);
printf("\nAverage Waiting time : %f" , averag);
fp = fopen(output, "a");
fprintf(fp,"\nAverage Waiting time : %f" , averag);
fclose(fp);
}
void FCFS(struct node *heade)
{ int l = 0 ;char newV;
while(l==0)
{
    printf("Do you want add new variables? y/n");
    scanf("%c",&newV);
   if(newV=='y') oneMore(heade);
   else if(newV=='n') break;
   else {printf("\nWrong choise select again\n");}
}
int sz  = siz(heade),waitingTime = 0;
    struct node *header=NULL;
    for(int i = 1;i<=sz;i++)
    {
    header=insertBack(header,selectEx(heade,i,0),selectEx(heade,i,1),selectEx(heade,i,2),selectEx(heade,i,3));
}
int  j;
fp = fopen(output, "a");
fprintf(fp,"\nFCFS  \n");
fclose(fp);
display(header);
header=sortMassiv(header);
display(header);
printf("P1 = 0 ms\n");
fp = fopen(output, "a");
fprintf(fp,"\nFirst Come Fist Served\n");
fprintf(fp,"P1 = 0 ms\n");
fclose(fp);
int temprar=0,wt=0,i=0;
for( i = 1 ; i <sz;i++)
{
temprar+=selectEx(header,i,1);
{
waitingTime=temprar-selectEx(header,i+1,2);
wt+=waitingTime;
printf("P%d = %d ms\n",selectEx(header,i+1,0),waitingTime);
fp = fopen(output, "a");
fprintf(fp,"P%d = %d ms\n",selectEx(header,i+1,0),waitingTime);
fclose(fp);
}}
double average;
average = (double)wt/(i);
fp = fopen(output, "a");
fprintf(fp,"Average waiting time = %f",average);
fclose(fp);
printf("Average waiting time = %f",average);
}
void deletenode(struct node *&first, int data)
{
    struct node * current = first;
    struct node * prev = (node *)malloc(sizeof(node));
    while(current!=NULL)
    {
        if(current->art!=data)
        {
            prev=current;
            current = current->next;
        }
        else
        {
            prev->next = current->next;
            delete current;
            break;
        }
    }
}
