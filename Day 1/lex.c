#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

int iskey(char buffer[])
{
	char key[2][10]={"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
	int i,flag=0;
	for(i=0; i<2;i++){
        if(strcmp(key[i], buffer) == 0){
            flag = 1;
            break;
        }
	}
	return flag;
}
void main()
{	
	char ch,buffer[10];
	int i,j,state;
	FILE *f;
	f=fopen("input.txt","r");
	if(f==NULL)
		printf("\nError opening the file");
	
while(ch!= EOF)
{
	switch(state)
	{	
		case 0:ch=fgetc(f);
			if(ch=='<')state=1;
			else if(ch=='>')state=4;
			else if(ch=='!')state=7;		
			else if(ch=='=')state=9;
			else if(isalpha(ch))
			{	buffer[0]=ch;
				state=11;
			}
			else if(isdigit(ch))
			{	buffer[0]=ch;
				state=13;
			}
			break;

		case 1:ch=fgetc(f);
			if(ch=='=')state=2;
			else
			{	state=3;
				fseek(f,-1,SEEK_CUR);
			}
			break;
		
		case 2:state=0;
			printf("\n<= Relational operator:Lessthan or Equal to");
			break;
		
		case 3:state=0;
			printf("\n< Relational operator:Lessthan");
			break;

		case 4:ch=fgetc(f);
			if(ch=='=')state=5;
			else
			{	state=6;
				fseek(f,-1,SEEK_CUR);
			}
			break;

		case 5:state=0;
			printf("\n>= Relational operator:Greaterthan or Equal to");
			break;
		
		case 6:state=0;
			printf("\n> Relational operator:Greaterthan");
			break;

		case 7:ch=fgetc(f);
			if(ch=='=')state=8;
			else
			{	state=0;
				fseek(f,-1,SEEK_CUR);
			}
			break;

		case 8:state=0;
			printf("\n!= Relational operator:Not Equal to");
			break;

		case 9:ch=fgetc(f);
			if(ch=='=')state=10;
			else
			{	state=0;
				fseek(f,-1L,SEEK_CUR);
			}
			break;

		case 10:state=0;
			printf("\n== Relational operator:Equal to");
			break;

		case 11:j=1;
			while(isalnum(ch=fgetc(f)))
			{	buffer[j++]=ch;
			}
			fseek(f,-1,SEEK_CUR);
			state=12;
			break;

		case 12:state=0;
			if(iskey(buffer)==0)
				printf("\n%s is an Identifier",buffer);
			else
				printf("\n%s is an keyword",buffer);
			memset(buffer,0,10);
			break;
			
		case 13:j=1;
			while(isdigit(ch=fgetc(f)))
			{	buffer[j++]=ch;
			}
			fseek(f,-1,SEEK_CUR);
			state=14;
			break;

		case 14:state=0;
			printf("\n%s is a Number",buffer);
			memset(buffer,0,10);
			break;

		default:state=0;
	}
}
printf("\n");
}

					
