#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct phoneBook{
    char name[30];
    char address[50];
    char mail[100];
    char father_name[35];
    char gender[35];
    long int mobile_number;
};
void menu();
void start();
void back();
void got();
void addmember();
void listmember();
void deletemember();
void searchmember();
void modifymember();

int main(){
    system("color 5f");
    start();
    return 0;
};
void back(){
    start();
}
void start(){
    menu();
}
void menu(){
    system("cls");
    printf("\t\t\t\t************Welcome To PhoneBook Application************\n\n\n\n");
    printf("\t\t\t\t\t1.Add Member   \t\t2.List of Member\n\n   \t\t\t\t\t3.Search Member  \t4.Delete Member\n\n \t\t\t\t\t5.Modify Member \t6.Exit\n\n");
    
    switch(getch()){
        case '1':
            addmember();
            break;
        case '2':
            listmember();
            break;
        case '3':
            searchmember();
            break;
        case '4':
            deletemember();
            break;
        case '5':
            modifymember();
            break;           
        case '6':
            exit(0);
            break;       

        default: 
            system("cls");
            printf(" Error! ");
            getch();
           
            menu();        
    }
}

void addmember(){
    system("cls");
    FILE *f;
    struct phoneBook p;
    f = fopen("DS_project","ab+");
    printf("\t\t\nEnter name: ");
    got(p.name);
    printf("\t\t\nEnter Address: ");
    got(p.address);
    printf("\t\t\nEnter E-Mail: ");
    got(p.mail);
    printf("\t\t\nEnter your gender: ");
    got(p.gender);
    printf("\t\t\nEnter Father name: ");
    got(p.father_name);
    printf("\t\t\nEnter Mobile number: ");
    got(p.mobile_number);
    fwrite(&p,sizeof(p),1,f);
    fflush(stdin);
    printf("\n\n Record saved..");

    fclose(f);  
    printf("\n\nEnter any key");

	getch();
    system("cls");
    menu();
}  
void listmember(){
    struct phoneBook p;
    FILE *f;
    f = fopen("DS_project","rb");
    if (f == NULL){
        printf(" No members are there in the list \n Add member's to search! ");
    }
    while(fread(&p,sizeof(p),1,f) == 1){
        printf("\n\n\n\t\t\t\tYour record is: \n\n ");
        printf("\t\t\t\t\nName = %s \t\t\t\t\nAdress = %s \t\t\t\t\nFather name = %s \t\t\t\t\nMobile no = %ld \t\t\t\t\nGender = %s \t\t\t\t\nE-mail = %s",p.name,p.address,p.father_name,p.mobile_number,p.gender,p.mail);
        
        getch();
        system("cls");
    }

    fclose(f);
    printf("\n Press any key to return Main menu");
    getch();
    system("cls");
    menu();
    
}

void searchmember(){
    struct phoneBook p;
    FILE *f;
    char name[100];
    f = fopen("DS_project","rb");
    printf("Enter the name of the person to search:\t");
    got(name,"\n");
    if(f == NULL){
        printf(" Add members to search! ");
    }
    while(fread(&p,sizeof(p),1,f) == 1){
        if(strcmp(p.name,name)==0){
            printf("\n\tDetail Information About %s is:\n",name);
            printf("\t\t\nName: %s\n \taddress: %s\n \tFather name: %s\n \tMobile no: %ld\n \tGender: %s\n \tE-mail: %s",p.name,p.address,p.father_name,p.mobile_number,p.gender,p.mail);
       }
        else{
            printf("file not found");
        }
    }
    fclose(f);
    printf("\n Press any key to return Main menu");
    getch();
    system("cls");
    menu();
}

void deletemember(){
    struct phoneBook p;
    FILE *f,*ft;
    int flag;
    char name[100];
    f = fopen("DS_project","rb");
    if(f == NULL){
        printf(" No member found! ");
    }
    else{
        ft=fopen("temp","wb+");
		if(ft==NULL){
            printf("file opaning error");
        }
		else{
            printf(" Enter name: ");
        got(name);

        fflush(stdin);
        while(fread(&p,sizeof(p),1,f) == 1){
            if(strcmp(p.name,name) != 0){
                fwrite(&p,sizeof(p),1,ft);
            }
            else if(strcmp(p.name,name) == 0){
                flag = 1;
            }
        }
        fclose(f);
        fclose(ft);
        if(flag != 1){
            printf(" No member is there to delete ");
            remove("temp.txt");
        }
        else{
            remove("DS_project");
            rename("temp.txt","DS_project");
            printf(" Member deleted successfully! ");
        }
        }
        
    }
    printf("\n  Press any key to return Main menu ");
    getch();
    system("cls");
    menu();
}

void modifymember(){
    int c;
    FILE *f;
    int flag=0;
    struct phoneBook p,s;
	char  name[50];
	f=fopen("DS_project","rb+");
	if(f == NULL)
		{
			printf("Member's data not added");
			exit(1);
		}
	else
	{
	    system("cls");
		printf("\n Enter member name to modify:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\n\nEnter name:");
                    got(s.name);
                    printf("\nEnter the address:");
                    got(s.address);
                    printf("\nEnter father name:");
                    got(s.father_name);
                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mobile_number);
                    printf("\nEnter Gender:");
                    got(s.gender);
                    printf("\nEnter e-mail:");
                    got(s.mail);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;
                }
                fflush(stdin);


            }
            if(flag == 1)
            {
                printf("\n your data id modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(f);
	}
	 printf("\n  Press any key to return Main menu");
	 getch();
     system("cls");
	 menu();

}
void got(char *name)
{

   int i = 0,j;
    char c,ch;
    do{
        c = getch();
            if(c != 8 && c != 13){
                *(name+i) = c;
                putch(c);
                 i++;
            }
            if(c == 8){
                if(i>0){
                        i--;
               }
                system("cls");
                for(j = 0;j < i; j++){
                    ch = *(name+j);
                    putch(ch);
                }
            }
    }
    while(c != 13);
      *(name+i) = '\0';
}


