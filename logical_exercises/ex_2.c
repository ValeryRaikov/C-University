#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_ORDERS 1000

typedef struct
{
    char name[100];
    double price;
    int id;
} Product;

typedef struct
{
    char address[100];
    int product_id;
} Order;

int main()
{
    Product products[MAX_PRODUCTS];
    Order orders[MAX_ORDERS];
    int num_products = 0, num_orders = 0;

    while (true)
    {
        char command[10];
        printf("Enter command:\n");
        scanf("%s", command);
        if (strcmp(command, "END") == 0)
        {
            break;
        }

        if (strcmp(command, "Product") == 0)
        {
            char name[100];
            double price;
            int id;
            scanf("%s %lf %d", name, &price, &id);

            products[num_products].price = price;
            products[num_products].id = id;
            strcpy(products[num_products].name, name);
            num_products++;

            for (int i = 0; i < num_orders; i++)
            {
                if (orders[i].product_id == id)
                {
                    printf("Client %s ordered %s\n", orders[i].address, name);
                    orders[i] = orders[num_orders - 1];
                    num_orders--;
                }
            }
        }
        else if (strcmp(command, "Order") == 0)
        {
            char address[100];
            int product_id;
            scanf("%s %d", address, &product_id);

            int found = 0;
            for (int i = 0; i < num_products; i++)
            {
                if (products[i].id == product_id)
                {
                    printf("Client %s ordered %s\n", address, products[i].name);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                orders[num_orders].product_id = product_id;
                strcpy(orders[num_orders].address, address);
                num_orders++;
            }
        }
    }

    return 0;
}
