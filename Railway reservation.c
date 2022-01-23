#include<stdio.h>
#include<conio.h>
int first=5,second=5,third=5;
struct node
{
int ticketno;
int phoneno;
char name[100];
char address[100];
char From[100];
char To[100]
}s;
FILE *fPointer;
char readFile[200];
void booking()
{
    printf("From:");
    scanf("%s",s.From);
    printf("To:");
    scanf("%s",s.To);
    printf("enter your details");
    printf("\nname:");
    scanf("%s",s.name);
    printf("phonenumber:");
    scanf("%d",&s.phoneno);
    printf("address:");
    scanf("%s",s.address);
    printf("\nticketnumber only 1-10:");
    scanf("%d",&s.ticketno);
    fprintf(fPointer,"From:%s\n",s.From);
    fprintf(fPointer,"To:%s\n",s.To);
    fprintf(fPointer,"Seatnumber:%d\n",s.ticketno);
    printf("HAPPY JOURNEY\n");
}
void availability()
{
    
    int c;
    printf("availability cheking");
    printf("\n1.first class\n2.second class\n3.thired class\n");
    printf("enter the option");
    scanf("%d",&c);
    switch(c)
    {
       case 1:if(first>0)
       {
           printf("seat available\n");
           first--;
       }
       else
       {
       printf("seat not available");
       }
       break;
       
       case 2:   if(second>0)
       {
           
          printf("seat available\n");
          second--;
          }
          else
          {
          printf("seat not available");
          }
          break;
          
          case 3:if(third>0)
          {
              
              printf("seat available\n");
              third--;
          }
          else
          {
              
              printf("seat not available");
          }
          break;
          default:
          break;
    }
}

void cancel()
{
    int c;
    printf("cancel\n");
    printf("which class you want to cancel");
    printf("\n1.first class\n2.second class\n3.thired class\n");
    printf("enter the option");
    scanf("%d",c);
    switch(c)
    {
        
        case 1:
        first++;
        break;
        case 2:
        second++;
        break;
        case 3:
        third++;
        break;
        
        default:
        break;
    }
    printf("ticket is canceled");
}

int main()
{
    
   int n;
   fPointer = fopen("Reservation","a+");
   printf("welcome to railway ticket reservation\n");
   printf("1.booking\n2.availability cheking\n3.cancel\nenter your option:");
   scanf("%d",&n);
   switch(n)
   {
       
      case 1: booking();
      break;
      case 2: availability();
      break;
      case 3: cancel();
      break;
      default:
      break;
   }
   fseek(fPointer,0,SEEK_SET);
   while(!feof(fPointer))
   {
       
       fgets(readFile,sizeof(readFile),fPointer);
       readFile[strcspn(readFile,"\n")] = 0;
       puts(readFile);
    }
    
    getch();
    fclose(fPointer);
}