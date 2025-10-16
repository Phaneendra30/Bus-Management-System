#include "login.h"


extern unsigned int bus_count;
extern struct bus bus_details[MAX_BUSES];




void save_bus_details(void)
{
     FILE *fp = fopen("busdetails.txt", "w");
    if (fp == NULL)
    {
        printf("❌ The file could not be opened for writing.\n");
        return;
    }

    for (int i = 0; i < bus_count; i++)
    {
        fprintf(fp, "#%d,%s,%hu,%s,%s,%s,%s,%hu,%d\n",
                i + 1,
                bus_details[i].Bus_Name,
                bus_details[i].Bus_No,
                bus_details[i].source,
                bus_details[i].destination,
                bus_details[i].departure_time,
                bus_details[i].arrival_time, 
                bus_details[i].MAX_SEATS,
                bus_details[i].passenger_Count);
    }

    fclose(fp);
    printf("💾 Data saved successfully.\n");
}


/* Function to read bus details */
void read_bus_details(void)
{
    FILE *fp;
    fp = fopen("busdetails.txt", "r");
    if (fp == NULL)
    {
        printf("❌ The file was not opened.\n");
        return;
    }

    bus_count = 0;

    while (fscanf(fp, " #%*d,%49[^,],%hu,%19[^,],%19[^,],%5[^,],%5[^,],%hu,%d%*[^#\n]",
                  bus_details[bus_count].Bus_Name,
                  &bus_details[bus_count].Bus_No,
                  bus_details[bus_count].source,
                  bus_details[bus_count].destination,
                  bus_details[bus_count].departure_time,
                  bus_details[bus_count].arrival_time,
                  &bus_details[bus_count].MAX_SEATS,
                  &bus_details[bus_count].passenger_Count) == 8)
    {
        bus_count++;
        if (bus_count >= MAX_BUSES)
            break;
    }

    fclose(fp);
    printf("✅ Loaded %d bus records from file.\n", bus_count);
}

/*Function to add new bus */
void add_bus(void)
{
    if (bus_count >= MAX_BUSES)
    {
        printf("❌ Cannot add more buses. Storage full!\n");
        return;
    }
     struct bus new_bus;

    printf("\n=== Add New Bus Details ===\n");
    printf("Enter Bus Name: ");
    scanf(" %[^\n]", new_bus.Bus_Name);
    printf("Enter Bus Number: ");
    scanf("%hu", &new_bus.Bus_No);
    printf("Enter Source: ");
    scanf(" %[^\n]", new_bus.source);
    printf("Enter Destination: ");
    scanf(" %[^\n]", new_bus.destination);
    printf("Enter Departure Time (HH:MM): ");
    scanf("%5s", new_bus.departure_time);
    printf("Enter Arrival Time (HH:MM): ");
    scanf("%5s", new_bus.arrival_time);
    printf("Enter Maximum Seats: ");
    scanf("%hu", &new_bus.MAX_SEATS);

    new_bus.passenger_Count = 0;

    bus_details[bus_count++] = new_bus;

    save_bus_details();  // <-- Save immediately after adding

    printf("\n✅ Bus details added and saved successfully!\n");

}
