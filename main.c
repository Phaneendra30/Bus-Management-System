#include "login.h"



void dot_pattern();
unsigned int flag;

struct bus bus_details[MAX_BUSES];
unsigned int bus_count;

int main() 
{
    Bus_Reservation_System reservation_system = {0};
    reservation_system.total_passengers = 0;
    reservation_system.max_logins = 0;
    load_login_details(&reservation_system);
    unsigned short int choice0;
    dot_pattern();
    
    read_bus_details(); 
    printf("Welcome to Bus Hub\n");
   do
   { 
    dot_pattern();
    printf("1. 🔐 Sign Up\n");
    printf("2. 🔓 Sign In\n");
    dot_pattern();
    printf("Enter your choice: ");
    scanf("%hu", &choice0);
     if(choice0 == 1) 
    {
      signup(&reservation_system);  
    } 
    else if (choice0 == 2) 
    {
        flag = signin(&reservation_system);  
    } 
    else 
    {
        printf("❌ Invalid choice. Exiting.\n");
        return 1;
    }
   }while(flag != 1);
     
     if(flag)
    {	     
       unsigned short int choice;
       do{
        dot_pattern();  // Print a visual divider
        printf("========== BUS MANAGEMENT ==========\n");
        dot_pattern();

        printf("1. 🎟️ Ticket Purchase\n");
        printf("2. ❌ Cancel Ticket\n");
        printf("3. 🚌 View Available Buses\n");
        printf("4. 💾 add new bus\n");
	printf("5. ✅ Confirm and Exit\n");

        dot_pattern();
        printf("Enter your choice: ");
        scanf("%hu", &choice);

          switch (choice) 
	{
            case 1:
		   Ticket_Purchase(&reservation_system);
                break;
            case 2:
                Cancel_Ticket(&reservation_system);
                break;
            case 3:
                view_available_buses(&reservation_system);
                break;
            case 4: 
		     add_bus();
		     break;
           case 5:
                printf("✅ Confirming and exiting...\n");
		save_bus_details();
                save_details_to_file(&reservation_system);
                break;
         default:
                printf("❌ Invalid choice. Please try again.\n");
        }

    }while(choice != 5);
 }

    return 0;
}
    
void dot_pattern()
{
	for(int i = 0;i < 50;i++)
	{
		printf(".");
	}
	printf("\n");
}
         





		  




	 

