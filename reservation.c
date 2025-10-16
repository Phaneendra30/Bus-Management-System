#include "login.h"


int user_name_validation(char* temp,Bus_Reservation_System* reservation_system);
int password_validation(char *temp,Bus_Reservation_System *reservation_system);
void signup(Bus_Reservation_System* reservation_system)
{
	
	char temp[20];
	int validation;
	do
	{
	   printf("Enter user name :\n");
	   scanf(" %[^\n]s",temp);
	   validation = user_name_validation(temp,reservation_system);
	   switch(validation)
	   {
		   case 0:
			   printf("Invalid username, username Should start with alphabets\n");
			   break;
		   case 1:
			   printf("Invalid username, username length should be ranges from 5 to 15 characters\n");
			   break;
		   case 2: printf("Invalid username, space character is not allowed\n");
			   break;
		   case 3:
			   strcpy(reservation_system->signup[reservation_system->max_logins].username,temp);
           }
	}while(validation != 3);
	char password[15];
	int password_validation1;
	do
	{
		printf("Enter your password :\n");
		scanf(" %[^\n]s",password);
		password_validation1 = password_validation(password,reservation_system);
		switch(password_validation1)
		{
			case 1:
				printf("Invalid password, password should contain atleast 12 characters\n");
				break;
		        case 2:
				printf("Invalid password, It should contain atleast one lowercase, one uppercase, one digit and one s                                pecial character\n");              
				break;
                        case 3:
			       printf("space character is not allowed\n");
				break;
                        case 4:
				strcpy(reservation_system -> signup[reservation_system->max_logins++].password,password);
		}
        }while(password_validation1 != 4);
	//dot_pattern();
	save_login_details(reservation_system);
	printf("your login details created successfully\n");
	//dot_pattern();
}
int user_name_validation(char* temp,Bus_Reservation_System* reservation_system)
{
     
     int i = 0,validation = 0;
     if(!isalpha(temp[0]))
     {
	     return 0;
     }
     else
     {
	     if(strlen(temp) > 5 && strlen(temp) < 15)
	     {
		     validation = 1;
	     }
	     else
	     {
		     return 1;
	     }
	     if(validation == 1)
	     {
		    while(temp[i]!='\0')
		    {
			    if(isspace(temp[i]))
			    {
				    return 2;
			    }
			    else
			    {
				    validation = 2;
			    }
			    i++;
		    }
	     }
	     
	     
     }
     if(validation == 2)  
     { 
	     return 3;
     }
}
int password_validation(char *temp,Bus_Reservation_System *reservation_system)
{
     unsigned short int digit_flag,lowercase_flag,uppercase_flag,alnum_flag;
     int i = 0,validation;
     if(strlen(temp) < 12)
     {
	     return 1;
     }
     else
     {
	     while(temp[i] != '\0')
	     {
		     if(isspace(temp[i]))
		     {
		          return 3;
		     }
		     if(isalnum(temp[i]))
		     {
		        alnum_flag = 1;
		     }
		     if(islower(temp[i]))
		     {
		         lowercase_flag = 1;
		     }
		      if(isupper(temp[i]))
                     {
                         uppercase_flag = 1;
                     }
		     if(isdigit(temp[i]))
		     {
		        digit_flag = 1;
		     }
		     i++;
	    }
            if(alnum_flag == 1 && lowercase_flag == 1 && uppercase_flag == 1 && digit_flag == 1)
	    {
	          validation = 1;
	    }
	    else
	    {
	       return 2;
	    }
	     
   }
       if(validation == 1)
       { 
             return 4;
       }
}     
unsigned short int  signin(Bus_Reservation_System *reservation_system)
{	
	
  char username[30];
  int flag, flag_1, i, j;  
  do
  {
    flag = 0;   // assume not found yet

    printf("Enter username:\n");
    scanf(" %s", username);

    for(j = 0; j < reservation_system -> max_logins; j++)
    {
	 
        if(strcmp(username, reservation_system -> signup[j].username) == 0)
        {
            flag = 1;   
            break;
        }
    }

    if(flag == 0)
    {
        printf("Invalid username. Try again.\n");
    }

} while(flag != 1);
 

     char password[20];
     
     do
     {
	     flag_1 = 0;
	     printf("Enter password : ");
	     scanf(" %s",password);
	      for(i = 0; i < reservation_system -> max_logins; i++)
             {
                     if(strcmp(reservation_system -> signup[i].password, password) == 0)
                     {
                        flag_1 = 1;
			break;
                     }
             }
	     if(!flag_1)
	     {
		      printf("Invalid password please try again\n");
	     }
     }while(!flag_1);
    
     if(flag && flag_1)
     {
	     return 1;
     }
     
}
		  












