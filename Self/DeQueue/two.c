// implementation of dequeue using circular singly linked list
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int size, choice, ch1, ch2;
    printf("Enter the dequeue size here : ");
    scanf("%d", &size);
    while (1)
    {
        printf("\nSelect an option to perform :\n1. Enqueue an element,\n2. Dequeue an element,\n3. Display the dequeue,\n4. exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Select an option:\n1. Enqueue at front,\n2.Enqueue at rear\n");
            scanf("%d", &ch1);
            if (ch1 == 1)
            {
                // enqueuefront(size);
            }
            else if (ch1 == 2)
            {
                // enqueuerear(size);
            }
            else
            {
                printf("Invalid option\n");
            }
            break;
        case 2:
            printf("Select an option:\n1. Dequeue at front,\n2.Dequeue at rear\n");
            scanf("%d", &ch1);
            if (ch1 == 1)
            {
                // dequeuefront(size);
            }
            else if (ch1 == 2)
            {
                // dequeuerear(size);
            }
            else
            {
                printf("Invalid option\n");
            }
            break;
        case 3:
            // display(size);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid option\n");
        }
    }
}
