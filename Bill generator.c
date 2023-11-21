#include <stdio.h>
#include <string.h>

#define NUM_RESTAURANTS 10
#define MAX_RESTAURANT_NAME_LENGTH 50
#define MENU_ITEMS_PER_RESTAURANT 20
#define MAX_ITEM_NAME_LENGTH 50

// Structure to represent a menu item
typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    float price;
} MenuItem;

// Structure to represent a restaurant
typedef struct {
    char name[MAX_RESTAURANT_NAME_LENGTH];
    MenuItem menu[MENU_ITEMS_PER_RESTAURANT];
} Restaurant;

// Function to display the menu of a specific restaurant
void displayMenu(Restaurant *restaurant) {
    printf("Menu for %s\n", restaurant->name);
    for (int i = 0; i < MENU_ITEMS_PER_RESTAURANT; ++i) {
        printf("%d. %s - $%.2f\n", i + 1, restaurant->menu[i].name, restaurant->menu[i].price);
    }
}

// Function to calculate the total bill
float calculateBill(MenuItem *menu, int itemCode, int quantity) {
    float price = menu[itemCode - 1].price;
    return price * quantity;
}

int main() {
    // Initialize restaurants
    Restaurant restaurants[NUM_RESTAURANTS] = {
        {"Saravana Bhavan", {{"idly",45},{"dosa",60},{"Fired rice",75},{"Chapathi",50},{"Parotta",35},{"Panner tikka",80},{"Veg briyani",75},{"Pullav",80},{"Naan",45},{"Panner 65",80},{"Gobi 65",60},{"Peas gravy",120},{"Panner butter masala",130},{"Gobi noodles",85},{"Veg noodles", 70},{"Gobi fired rice",85},{"Chilli parotta",70},{"Kaima parotta",80},{"Garlic naan",55},{"Chola puri",50}}},
        {"Adyar Ananda Bhavan", {{"Vada pav", 15},{"Samosa", 35},{"Fired rice",75},{"Chapathi",50},{"Parotta",35},{"Panner tikka",80},{"Veg briyani",75},{"Pullav",80},{"Naan",45},{"Panner 65",80},{"Gobi 65",60},{"Peas gravy",120},{"Panner butter masala",130},{"Gobi noodles",85},{"Veg noodles", 70},{"Gobi fired rice",85},{"Chilli parotta",70},{"Kaima parotta",80},{"Garlic naan",55},{"Chola puri",50}}},
        {"Murugan Dosa Shop", {{"idly",45},{"Mini idly",50},{"Podi idly",55},{"Podi dosa",75},{"Masala dosa",80},{"Butter dosa",85},{"Onion dosa",80},{"Onion uthappam",85},{"Rava dosa",85},{"Idiyappam",40},{"Pongal",35},{"Chicken chettinadu gravy",220},{"Chicken chettinadu gravy",250},{"Bun Parotta", 15},{"Prawn gravy",210},{"Mushroom butter gravy",230},{"Chicken 65 briyani",210},{"Chicken tikka",250},{"Mutton briyani",280},{"Grilled Chicken",300}}},
        {"Ponnusamy Hotel", {{"idly",45},{"dosa",60},{"Fired rice",75},{"Chapathi",50},{"Parotta",35},{"Panner tikka",80},{"Veg briyani",75},{"Pullav",80},{"Naan",45},{"Panner 65",80},{"Gobi 65",60},{"Peas gravy",120},{"Panner butter masala",130},{"Gobi noodles",85},{"Veg noodles", 70},{"Gobi fired rice",85},{"Chilli parotta",70},{"Kaima parotta",80},{"Garlic naan",55},{"Chola puri",50} }},
        { "A2B - Adyar Ananda Bhavan", {{"Vada pav", 15},{"Samosa", 35},{"Fired rice",75},{"Chapathi",50},{"Parotta",35},{"Panner tikka",80},{"Veg briyani",75},{"Pullav",80},{"Naan",45},{"Panner 65",80},{"Gobi 65",60},{"Peas gravy",120},{"Panner butter masala",130},{"Gobi noodles",85},{"Veg noodles", 70},{"Gobi fired rice",85},{"Chilli parotta",70},{"Kaima parotta",80},{"Garlic naan",55},{"Chola puri",50} }},
        {"Anjappar Chettinad", {{"Chicken chettinadu gravy",220},{"Chicken chettinadu gravy",250},{"Bun Parotta", 15},{"Prawn gravy",210},{"Mushroom butter gravy",230},{"Chicken 65 briyani",210},{"Chicken tikka",250},{"Mutton briyani",280},{"Grilled Chicken",300},{"BBQ Chicken",350},{"Chicken Kothu parotta",200},{"Crab fry",240},{"Non-veg Meals", 120},{"Sea Foods Bucket", 250},{"Crab Masala", 130} }},
        {"Hotel Junior Kuppanna", {{"idly",45},{"dosa",60},{"Fired rice",75},{"Chapathi",50},{"Parotta",35},{"Panner tikka",80},{"Veg briyani",75},{"Pullav",80},{"Naan",45},{"Panner 65",80},{"Gobi 65",60},{"Peas gravy",120},{"Panner butter masala",130},{"Gobi noodles",85},{"Veg noodles", 70},{"Gobi fired rice",85},{"Chilli parotta",70},{"Kaima parotta",80},{"Garlic naan",55},{"Chola puri",50} }},
        {"The Raintree", {{"Chicken pizza",300},{"Panner pizza",170},{"Mushroom  pizza",210},{"Double cheesa pizza",350},{"Pepperoni pizza",200},{"Meat pizza",320},{"Margherita pizza",350},{"BBQ chicken pizza",380},{"Hawaiian pizza",250},{"Supreme pizza",400},{"Chicken sandwich",250},{"Veg sandwich",100},{"Egg sandwich",150},{"Sea food sandwich",180},{"Grilled cheese sandwich",280},{"Nuttela sandwich",200},{"Ham sandwich",120},{"Meat ball sandwich",300},{"Chicken wings",350},{"Panner Frankie", 70}}},
        {"Madras Pavilion", {{"idly",45},{"dosa",60},{"Fired rice",75},{"Chapathi",50},{"Parotta",35},{"Panner tikka",80}, {"Podi dosa",75},{"Masala dosa",80},{"Butter dosa",85},{"Naan",45},{"Panner 65",80},{"Gobi 65",60},{"Peas gravy",120},{"Panner butter masala",130},{"BBQ Chicken",350},{"Chicken Kothu parotta",200},{"Crab fry",240},{"Non-veg Meals", 120},{"Sea Foods Bucket", 250},{"Crab Masala", 130},{"Crab fry",240},{"Non-veg Meals", 120},{"Sea Foods Bucket", 250},{"Crab Masala", 130}}},
        {"Dindigul Thalappakatti", {{"Chicken chettinadu gravy",220},{"Chicken chettinadu gravy",250},{"Bun Parotta", 15},{"Prawn gravy",210},{"Mushroom butter gravy",230},{"Chicken 65 briyani",210},{"Chicken tikka",250},{"Mutton briyani",280},{"Grilled Chicken",300},{"BBQ Chicken",350},{"Chicken Kothu parotta",200},{"Crab fry",240},{"Non-veg Meals", 120},{"Sea Foods Bucket", 250},{"Crab Masala", 130},{"Kaima parotta",80},{"Garlic naan",55},{"Chola puri",50},{"Mutton briyani",280}}}
    };

    int restaurantId, itemCode, quantity;
    float totalBill = 0.0;

    // Display the list of restaurants
    printf("List of Restaurants in Tamil Nadu\n");
    for (int i = 0; i < NUM_RESTAURANTS; ++i) {
        printf("%d. %s\n", i + 1, restaurants[i].name);
    }

    // Get user input for restaurant selection
    printf("Enter the restaurant number: ");
    scanf("%d", &restaurantId);

    // Validate restaurant selection
    if (restaurantId < 1 || restaurantId > NUM_RESTAURANTS) {
        printf("Invalid restaurant selection.\n");
        return 1;
    }

    // Display the menu for the selected restaurant
    displayMenu(&restaurants[restaurantId - 1]);

    // Get user input for item code and quantity
    printf("Enter the item code: ");
    scanf("%d", &itemCode);

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // Calculate the total bill
    totalBill = calculateBill(restaurants[restaurantId - 1].menu, itemCode, quantity);

    // Display the order details and total bill
    printf("\n---------------------------\n");
    printf("        Order Details       \n");
    printf("---------------------------\n");
    printf("Restaurant: %s\n", restaurants[restaurantId - 1].name);
    printf("Item: %s\n", restaurants[restaurantId - 1].menu[itemCode - 1].name);
    printf("Quantity: %d\n", quantity);
    printf("Total Bill: $%.2f\n", totalBill);
    printf("---------------------------\n");

    return 0;
}