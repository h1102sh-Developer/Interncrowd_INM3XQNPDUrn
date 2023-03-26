 /*   WEEK 3
      TASK 3: Phone Book Directory
       Name: Harsh Shuddhalwar
       InternCrowd ID:INM3XQNPDUrn
      Domain Name: C,C++ */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct Friend
{
char name[56];
char number[56];
};
void printLine(char g,int size)
{
int i;
for(i=1;i<=size;i++) printf("%c",g);
printf("\n");
}
void addNew()
{
FILE *f;
struct Friend t,g;
char name[56];
char number[56];
printf("Enter name :  ");
fgets(name,56,stdin);
name[strlen(name)-1]='\0';
fflush(stdin);
printf("Enter Contact Number :  ");
fgets(number,56,stdin);
number[strlen(number)-1]='\0';
fflush(stdin);
char m;
printf("Save(Y/N)");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Friend not added\n");
return ;
}
strcpy(g.name,name);
strcpy(g.number,number);
f=fopen("friends.dat","ab");
fwrite(&g,sizeof(struct Friend),1,f);
fclose(f);
printf("Friend added , press enter to continue...............\n");
getchar();
fflush(stdin);
}
void showListByName()
{
FILE *f;
struct Friend t;
char name[56];
char number[56];
printf("Friend (search by name module)\n");
printf("Enter name :  ");
fgets(name,56,stdin);
name[strlen(name)-1]='\0';
fflush(stdin);
f=fopen("friends.dat","rb");
if(f==NULL)
{
printf("Invalid detail\n");
return;
}
int found=0;
char m;
while(1)
{
fread(&t,sizeof(struct Friend),1,f);
if(feof(f)) break;
if(strcasecmp(t.name,name)==0)		
{
printf("Name : %s\nPhone Number : %s\n",t.name,t.number);
found=1;
}
}
fclose(f);
if(found==0)
{
printf("Invalid name \n");
return ;
}
printf("Press enter to continue....................");
getchar();
fflush(stdin);
}
void showFullList()
{
FILE *f;
int newPage,pageSize;
int sNo;
struct Friend t;
f=fopen("friends.dat","rb");
if(f==NULL)
{
printf("Friend(List Module)\n");
printLine('-',110);
printf("%10s  %-35s  %-35s  \n","S.No.","Name","Number");
printLine('-',110);
printf("No Number added\n");
printLine('-',110);
printf("Press enter to continue....................\n");
getchar();
fflush(stdin);
return ;
}
newPage=1;
pageSize=5;
sNo=0;
while(1)
{
if(newPage==1)
{
printf("Friend(List Module)\n");
printLine('-',110);
printf("%10s  %-35s  %-35s  \n","S.No.","Name","Number");
printLine('-',110);
newPage=0;
}
fread(&t,sizeof(struct Friend),1,f);
if(feof(f)) break;
sNo++;
printf("%10d  %-35s  %-35s  \n",sNo,t.name,t.number);
if(sNo%pageSize==0)
{
printLine('-',110);
printf("Press enter to continue...................\n");
getchar();
fflush(stdin);
newPage=1;
}
}
if(sNo==0)
{
printf("No number added\n");
printLine('-',80);
printf("Press enter to continue...................\n");
getchar();
fflush(stdin);
}
if(sNo%pageSize!=0)
{
printLine('-',110);
printf("Press enter to continue...................\n");
getchar();
fflush(stdin);
}
fclose(f);
}
void updateList()
{
FILE *f,*f1,*f2;
struct Friend g,t;
char name[56];
char number[56];
printf("Friend (Update Module)\n");
printf("Enter name :  ");
fgets(name,56,stdin);
name[strlen(name)-1]='\0';
fflush(stdin);

f=fopen("friends.dat","rb");
if(f==NULL)
{
printf("Invalid detail\n");
return;
}
int found=0;
char m;
while(1)
{
fread(&t,sizeof(struct Friend),1,f);
if(feof(f)) break;
if(strcasecmp(t.name,name)==0)
{
printf("Name : %s\nNumber : %s\n",t.name,t.number);
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("Invalid details \n");
return ;
}
else
{
printf("Edit(Y/N)");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Friend not added\n");
return ;
}
printf("Enter number to be updated : ");
fgets(number,56,stdin);
number[strlen(number)-1]='\0';
fflush(stdin);
printf("Update(Y/N)");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Friend not added\n");
return ;
}
strcpy(g.name,name);
strcpy(g.number,number);
f1=fopen("friends.dat","rb");
f2=fopen("tmp.tmp","wb");
while(1)
{
fread(&t,sizeof(struct Friend),1,f1);
if(feof(f1)) break;
if(strcasecmp(t.name,name)!=0)
{
fwrite(&t,sizeof(struct Friend),1,f2);
}
else
{
fwrite(&g,sizeof(struct Friend),1,f2);
}
}
fclose(f1);
fclose(f2);
f1=fopen("friends.dat","wb");
f=fopen("tmp.tmp","rb");
while(1)
{
fread(&t,sizeof(struct Friend),1,f2);
if(feof(f2)) break;
fwrite(&t,sizeof(struct Friend),1,f1);
}
fclose(f1);
fclose(f2);
f2=fopen("tmp.tmp","w");
fclose(f2);
}
printf("Number Updated ,press enter to continue....................");
getchar();
fflush(stdin);
}
void removeFromList()
{
FILE *f,*f1,*f2;
struct Friend g,t;
char name[56];
char number[56];
printf("Friend (Delete Module)\n");
printf("Enter name of friend to delete  ");
fgets(name,56,stdin);
name[strlen(name)-1]='\0';
fflush(stdin);
f=fopen("friends.dat","rb");
if(f==NULL)
{
printf("Invalid detail\n");
return;
}
int found=0;
char m;
while(1)
{
fread(&t,sizeof(struct Friend),1,f);
if(feof(f)) break;
if(strcasecmp(t.name,name)==0)
{
printf("Name : %s\nNumber : %s\n",t.name,t.number);
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("Invalid details \n");
return ;
}
else
{
printf("Delte(Y/N)");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Friend not added\n");
return ;
}
f1=fopen("friends.dat","rb");
f2=fopen("tmp.tmp","wb");
while(1)
{
fread(&t,sizeof(struct Friend),1,f1);
if(feof(f1)) break;
if(strcasecmp(t.name,name)!=0)
{
fwrite(&t,sizeof(struct Friend),1,f2);
}
}
fclose(f1);
fclose(f2);
f1=fopen("friends.dat","wb");
f=fopen("tmp.tmp","rb");
while(1)
{
fread(&t,sizeof(struct Friend),1,f2);
if(feof(f2)) break;
fwrite(&t,sizeof(struct Friend),1,f1);
}
fclose(f1);
fclose(f2);
f2=fopen("tmp.tmp","w");
fclose(f2);
}
printf("Number Deleted ,press enter to continue....................");
getchar();
fflush(stdin);
}
int main()
{
int ch;
while(1)
{
puts("");
printf("#############################PHONEBOOK DIRECTORY##########################\n");
puts("");
printf("1. Add New\n");
printf("2. Search\n");
printf("3. List\n");
printf("4. Modify\n");
printf("5. Delete\n");
printf("6. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
addNew();
}else if(ch==2)
{
showListByName();
}else if(ch==3)
{
showFullList();
}else if(ch==4)
{
updateList();
}else if(ch==5)
{
removeFromList();
}
else if(ch==6)
{
break;
}else 
{
printf("Invalid choice \n");
return 0;
}
}
return 0;
}
