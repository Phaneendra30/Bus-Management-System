#include "login.h"



unsigned long int ticketnumber[1000];
unsigned int ticket_count;
extern unsigned int bus_count;
extern struct bus bus_details[MAX_BUSES];


void Ticket_Purchase(Bus_Reservation_System *reservation_system) 
{
     view_available_buses(reservation_system);
     int i,found = 0;
     srand(time(NULL)); // seed The random number generator with current time;
     int TicketNumber = (rand() % 900000) + 100000;
     unsigned short int bus_no;
     char NAME[30],  mobile[15],  Email[30], gender[10];;
     unsigned short int AGE;
    do
    {
     printf("Enter bus number: ");
     scanf("%hu",&bus_no);
     for(i = 0; i < bus_count; i++)
     {
	    if(bus_details[i].Bus_No == bus_no)
	    {
		    
                if(bus_details[i].MAX_SEATS >= bus_details[i].passenger_Count)
		 {
		    found = 1;
		    reservation_system -> passengers[reservation_system -> total_passengers].busnumber = bus_no;
		    break;

		 }
	         else
		 {
		    printf("Error: All seats are filled. No more bookings allowed.\n");
	         }
		 
	    }

     }
   if(!found)
   {
	 printf("Bus Number not found please enter valid bus number\n");
   }
   }while(found != 1);
   if(found == 1)
   {
     
     printf("Enter your name: ");
     scanf(" %[^\n]",NAME);
     strcpy(reservation_system -> passengers[reservation_system -> total_passengers].name,NAME);
     reservation_system -> passengers[reservation_system -> total_passengers].Ticket_Number = TicketNumber;
     printf("Enter your age: ");
     scanf("%hu",&AGE);
     reservation_system -> passengers[reservation_system -> total_passengers].age = AGE;
     printf("Enter your gender: ");
     scanf(" %s", gender);
     strcpy(reservation_system -> passengers[reservation_system -> total_passengers].gender, gender);
     printf("Enter your mobile number: ");
     scanf(" %s",mobile);
     strcpy(reservation_system -> passengers[reservation_system -> total_passengers].number,mobile);
     printf("Enter your email id : ");
     scanf(" %[^\n]",Email);
     //printf("Ticket number: %d\n", TicketNumber);
     reservation_system -> passengers[reservation_system -> total_passengers].Ticket_Number = TicketNumber;
     strcpy(reservation_system -> passengers[reservation_system -> total_passengers++].email,Email);
     //printf("%ld\n", reservation_system -> passengers[0].Ticket_Number);
     for(i = 0; i < 7; i++)
     {
 	     if(bus_no == bus_details[i].Bus_No)
	     {
		     bus_details[i].passenger_Count++;
	     }
     }
  





    printf("+=================================================================+\n");
    printf("|               🚌 Digital Bus Reservation Ticket                 |\n");

          for(i = 0; i < bus_count; i++)
          {
               if(bus_no == bus_details[i].Bus_No)
              {
                   // Centered welcome line
                   char welcome[100];
                   sprintf(welcome, "🚍 Well Come to %s Travels", bus_details[i].Bus_Name);
                   printf("| %-63s   |\n", welcome);

                   printf("+-----------------------------------------------------------------+\n");
                   printf("| Bus Number      : %-43hu |\n", bus_details[i].Bus_No);

                   char route[100];
                   sprintf(route, "%s → %s", bus_details[i].source, bus_details[i].destination);
                   printf("| Route           : %-43s   |\n", route);

                   printf("| Departure Time  : %-43s |\n", bus_details[i].departure_time);
                   printf("| Arrival Time    : %-43s |\n", bus_details[i].arrival_time);
                   printf("| Bus Operator    : %-43s |\n", bus_details[i].Bus_Name);

                   char boardPoint[100];
                   sprintf(boardPoint, "%s Bus Station", bus_details[i].source);
                   printf("| Boarding Point  : %-43s |\n", boardPoint);

                   printf("| Boarding Time   : %-43s |\n", bus_details[i].departure_time);
                   printf("| Note            : %-43s |\n", "Please reach 15 mins before departure");
                   printf("+-----------------------------------------------------------------+\n");
                   break;
               }
          }
   


                           printf("| Ticket Number   : %-43d |\n", TicketNumber);
                           printf("| Date of Booking : %-43s |\n", __DATE__);
			   printf("| Time of Booking : %-43s |\n", __TIME__);
                           printf("| Passenger Name  : %-43s |\n", NAME);
			   printf("| gender          : %-43s |\n", gender);
                           printf("| Age             : %-43hu |\n", AGE);
                           printf("| Email ID        : %-43s |\n", Email);
                           printf("| Fare            : %-43s   |\n", "₹500");
                           printf("+=================================================================+\n");
                           printf("|           ✨ Happy Journey & Safe Travels! ✨                    |\n");
                           printf("+=================================================================+\n");
   }

}


/* Function to read data from file */
void read_data()
{


	FILE *fptr;
	fptr = fopen("save_ticket.txt", "r");
	if(fptr == NULL)
	{
             perror("File could'nt be opened\n");
             return;
	}
	ticket_count = 0;

	while(fscanf(fptr, "%ld", &ticketnumber[ticket_count]) != EOF)
	{
		ticket_count++;
	}

       fclose(fptr);

    // print stored numbers
    printf("Ticket Numbers:\n");
    for (int j = 0; j < ticket_count; j++) {
        printf("%ld\n", ticketnumber[j]);
    }

}


//Function for ticket cancellation;
void Cancel_Ticket(Bus_Reservation_System *reservation_system) 
{
    read_data();
    unsigned long int Cancle_Ticket;
    printf("====Cancle Ticket====\n");
    printf("Enter Your Ticket Number:\n");
    scanf("%ld", &Cancle_Ticket);
    int i, found = 0, bus_no = 0;
    printf("Enter your Bus Number: ");
    scanf("%d", &bus_no);
    FILE *fptr, *temp;
    fptr = fopen("save_ticket.txt", "r");
    if(!fptr)
    {
             perror("File could'nt be opened\n");
             return;
    } 

    // Open a temporary file for writing
    temp = fopen("temp.txt", "w");
    if (temp == NULL) 
    {
	perror("File could'nt be opened\n");
        return;
    }
    unsigned long int num;
    while(fscanf(fptr, "%ld", &num) != EOF)
    {
	    if(num != Cancle_Ticket)
	    {
		    fprintf(temp, "%ld\n", num);
            }
	    else
	    {
		    found = 1;
	    }
    } 

    fclose(fptr);
    fclose(temp);

    //Replace original file with updated temp file
    remove("save_ticket.txt");
    rename("temp.txt", "save_ticket.txt");

    if(!found)
    {
	    printf("sorry Ticket Number not found\n");
    }
    else
    {
	    printf("Your ticket has been cancelled successfully\n");
    }
    for(i = 0; i < bus_count; i++)
    {
	    if(bus_details[i].Bus_No == bus_no)
	    {   
		    bus_details[i].passenger_Count--;
		    break;
	    }
   }
}

void view_available_buses(Bus_Reservation_System *reservation_system) 
{
    char From_city[30], To_city[30];
    printf("[ 🚌 ] Enter From city: ");
    scanf(" %s", From_city);
    printf("Enter To city [ 🚌 ] : ");
    scanf(" %s",  To_city);
    int i;
    printf(" ===Available Buses=== \n");
    int found = 0;
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("| %-27s | %-6s | %-12s | %-12s | %-15s | %-12s |\n",
           "BUS NAME", "BUS NO", "SOURCE", "DESTINATION", "DEPARTURE", "ARRIVAL");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < bus_count; i++)
    {
        // case-insensitive match
        if (strcasecmp(bus_details[i].source, From_city) == 0 &&
            strcasecmp(bus_details[i].destination, To_city) == 0)
        {
            printf("| %-27s | %-6hu | %-12s | %-12s | %-15s | %-12s |\n",
                   bus_details[i].Bus_Name,
                   bus_details[i].Bus_No,
                   bus_details[i].source,
                   bus_details[i].destination,
                   bus_details[i].departure_time,
                   bus_details[i].arrival_time);
            found++;
        }
    }
   printf("----------------------------------------------------------------------------------------------------------------\n");
   if(!found)
   {
	   printf("❌ No buses found for route %s ➜ %s\n", From_city, To_city); 
   }

}

void save_details_to_file(Bus_Reservation_System *reservation_system) 
{

      
         FILE *fptr;
         //file pointer referse to the pointer pointing to a specific location in the file. this file pointer is used for all file operations such as file open, write, read, close file etc
         fptr = fopen("save_ticket.txt", "a");
         if(!fptr)
         {
                 perror("File could'nt be opened\n");
                 return;
         }

         //fprintf(fptr, "#%d\n", reservation_system -> total_passengers);
         for(int i = 0; i < reservation_system -> total_passengers; i++)
         {
             fprintf(fptr, "%ld\n", reservation_system -> passengers[i].Ticket_Number);
         }
         fclose(fptr);
}


