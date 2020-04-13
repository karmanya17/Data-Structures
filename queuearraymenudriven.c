
    #include <stdio.h>
    #include<stdlib.h>
    #define MAX 50

    void insert();
    void delete();
    void peek();
    void display();
    void count1();
    int queue_array[MAX];
    int rear = - 1;
    int front = - 1;
    int count=0;

    void main()
    {
        int choice;
        while (1)
        {
            printf("\n \n");
            printf("1.Insert element to queue \n");
            printf("2.Delete element from queue \n");
            printf("3.Display first elemet from queue \n");
            printf("4.Display all elements of queue \n");
            printf("5.Count elements \n");
            printf("6.Quit \n");
	    printf("Enter your choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
		case 1:insert();
			break;
                case 2:delete();
			break;
	        case 3:peek();
   			break;
                case 4:display();
			break;
		case 5:count1();
			break;
                case 6:exit(0);
	                break;
		default:
                	printf("Wrong choice \n");
            }
        }
    } 

    void count1()
    {
    printf("Number of elements in Queue is %d \n",count);
    }

    void insert()
    {
        int add_item;
        if (rear == MAX - 1)
        printf("Queue Overflow \n");
        else
        {
            if (front == - 1)
            front = 0;
            printf("Inset the element in queue : ");
            scanf("%d", &add_item);
            rear = rear + 1;
            queue_array[rear] = add_item;
            count++;
        }
    }

    void peek()
    {
        if (front == - 1)
        {
            printf("Queue Underflow \n");
            return ;
        }
        else
        {
            printf("First element in Queue= : %d\n", queue_array[front]);
        }
    }

    void delete()
    {
        if (front == - 1 )
        {
            printf("Queue Underflow \n");
            return ;
        }
        else
        {
            printf("Element deleted from queue is : %d\n", queue_array[front]);
            front = front + 1;
            count--;
        }
    }

    void display()
    {
        int i;
        if (front == - 1)
            printf("Queue is empty \n");
        else
        {
            printf("Queue is : \n");
            for (i = front; i <= rear; i++)
		{
                printf("%d ", queue_array[i]);
		}
            printf("\n");
        }
    }
