#include <stdio.h>

typedef enum
{
    passenger = 'P', sleeper = 'S', diner = 'D'
}type;

typedef struct
{
    type typ;
    int capacity;
}carriage;

typedef struct
{
    carriage carriages[10];
    int length;
}train;

void printCarriage(carriage Carriage)
{
    printf("[%c:%03d]", Carriage.typ, Carriage.capacity);
}

void printTrain(train *Train)
{
    if (Train -> length == 0)
    {
        printf("\nTrain: No Carriages!");
    }
    else
    {
        printf("\nTrain: ");

        for (int i = 0; i < Train -> length; ++i)
        {
            printf("%d:", i);
            printCarriage(Train -> carriages[i]);

            if (i != Train -> length -1)
            {
                printf("-");
            }
        }
        printf(" Length: %d", Train -> length);
    }
}

char getMenu()
{
    char input;

    printf("\nChoose Action: print train (p), new carriage (n), print stats (s) or exit (x): ");
    scanf(" %c", &input);

    while (input != 'p' && input != 'n' && input != 's' && input !='x')
    {
        printf("\nInput invalid! Try again: ");
        scanf(" %c", &input);
    }
    return input;
}

carriage getCarriage()
{
    carriage Carriage;
    char input;
    int capacity;

    printf("\nChoose type of carriage: passenger (p), sleeper (s) or diner (d):");

    while (1)
    {
        scanf(" %c", &input);

        switch (input)
        {
            case 'p':
                Carriage.typ = passenger;
                break;

            case 's':
                Carriage.typ = sleeper;
                break;

            case 'd':
                Carriage.typ = diner;
                break;

            default:
                printf("\nInput invalid! Try again:");
                continue;
        }
        break;
    }
    printf("\nChoose capacity (20 - 130):");

    while(1)
    {
        scanf("%d", &capacity);

        if (capacity >= 20 && capacity <= 130)
        {
            Carriage.capacity = capacity;
            break;
        }
        else
        {
            printf("\nInput invalid! Try again:");
        }
    }
    return Carriage;
}

int getPosition(int length)
{
    int position = 0;

    printf("\nChoose position for the new carriage (0-%d):", length);

    while (1)
    {
        scanf("%d", &position);

        if (position < 0 || position > length)
        {
            printf("\nInput invalid! Try again:");
        }
        else
        {
            break;
        }
    }
    return position;
}

int insertCarriage(train *Train, int position, carriage Carriage)
{
    if (Train -> length == 10)
    {
        return -1;
    }
    else if (position < 0 || position > 9 || position > Train->length)
    {
        return -2;
    }
    else if ((Carriage.typ == sleeper && (Train -> carriages[position].typ != passenger || Train -> carriages[position+1].typ != passenger)) ||
             (Carriage.typ == sleeper && (Train -> carriages[position].typ == sleeper)))
    {
        return -3;
    }
    else
    {
        for (int i = Train -> length; i > position; --i)
        {
            Train -> carriages[i] = Train -> carriages[i -1];
        }
        Train -> carriages[position] = Carriage;
        ++Train -> length;
    }
    return 0;
}

int sumCapacity(train *Train, type typ)
{
    int sum = 0;

    for (int i = 0; i < Train -> length; ++i)
    {
        if (Train -> carriages[i].typ == typ)
        {
            sum += Train -> carriages[i].capacity;
        }
    }
    return sum;
}

void printTrainStats(train *Train)
{
    printTrain(Train);

    printf("\nCapacities: ");
    printf("\n  Passenger: %d", sumCapacity(Train, passenger));

    if (sumCapacity(Train, passenger) < 65)
    {
        printf(" - invalid");
    }
    printf("\n  Sleeper: %d", sumCapacity(Train, sleeper));
    printf("\n  Diner: %d", sumCapacity(Train, diner));
}

int main()
{
    carriage Carriage;
    train Train;
    Train.length = 0;

    while (1)
    {
        switch (getMenu())
        {
            case 'p':
                printTrain(&Train);
                continue;

            case 'n':
                Carriage = getCarriage();
                int position = getPosition(Train.length);
                int error = insertCarriage(&Train, position, Carriage);

                if (error == -1)
                {
                    printf("\nError: Train too long!");
                }
                else if (error == -2)
                {
                    printf("\nError: Position not possible!");
                }
                else if (error == -3)
                {
                    printf("\nError: Sleeper only possible directly before two passenger carriages!");
                }
                continue;

            case 's':
                printTrainStats(&Train);
                continue;

            case 'x':
                break;

            default:
                break;
        }
        break;
    }
    return 0;
}