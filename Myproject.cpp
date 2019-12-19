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
    int sz  = siz(heade),waitingTime = 0;
    struct node *header=NULL;
    for(i = 1;i<=sz;i++)
    {
    header=insertBack(header,selectEx(heade,i,0),selectEx(heade,i,1),selectEx(heade,i,2),selectEx(heade,i,3));
}
