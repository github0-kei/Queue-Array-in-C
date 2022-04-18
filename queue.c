#include <stdio.h>

int size = 10;
int queue[10];
int rear = -1;  
int front = -1;

int system();
int isEmpty();
int isFull();

int enqueue(int data)
{
    if(isFull())
        printf("Queue is full.\n");
    else
    {
        if(front == -1)
            front = 0;
    
        rear += 1;
        queue[rear] = data;
    }
}

int dequeue() 
{
    if(isEmpty())
      printf("Queue is empty.\n");
    else
    {
        front += 1;

        if(front > rear)
        {
            front -= 1;
            rear -= 1;
        }
    }
}   

int isEmpty() 
{
   if(front == -1)
      return 1;
   else
      return 0;
}

int isFull() 
{
   if(rear == size - 1)
      return 1;
   else
      return 0;
}

int clear()
{
	return front = -1, rear = -2;   
}

int head() 
{
   return queue[front];
}

int tail() 
{
   return queue[rear];
}

int main() 
{
	int repeat, choice, element, multElement, x;
	
	do
	{
		printf("QUEUE MENU\n[1] Enqueue\n[2] Dequeue\n[3] Empty\n[4] Full\n[5] Clear\n[6] Head\n[7] Tail\n[8] Print\nChoice: ");
		scanf("%d", &choice);
		
		system("cls");
		
		switch(choice)
		{
			case 1:
				system("cls");
	
				do
				{
                    if(!isFull())
                    {
                        printf("Enqueue (element): ");
                        scanf("%d", &element);
					    enqueue(element);

                        printf("Add again? (1 = YES | 0 = NO): ");
					    scanf("%d", &multElement);
                    }
                    else
                    {
                        printf("Sorry, stack is already full");
                        multElement = 0;
                    }
				}
				while(multElement == 1);
						
				break;
            case 2:
				system("cls");
				
				do
				{
					dequeue();
					
					printf("Element dequeued.\nDequeue again? (1 = YES | 0 = NO): ");
					scanf("%d", &multElement);
				}
				while(multElement == 1);	
				
				break;
            case 3:
                system("cls");
				printf("Is queue empty? %s", isEmpty() ? "Yes" : "No");
				break;
            case 4:
                system("cls");
				printf("Is queue full? %s", isFull() ? "Yes" : "No (there are 10 elements that can be accomodated)");
				break;
            case 5:
				clear();
				printf("Queue is cleared.");
				break;
            case 6:
                printf("Head: %d", head());
				break;
            case 7:
                printf("Tail: %d", tail());
				break;
            case 8:
                system("cls");

				printf("Elements in Queue: ");
				if(rear != -2)
                {
                    for(x = front; x <= rear; x++)
					    printf("%d ", queue[x]);
                }

                /*
                    For printing after clearing
                    0 - an element not added would still be printed after clearing
                    The following line of codes is a fix to this issue
                */
                else
                {
                    for(x = front; x < rear; x++)
					    printf("%d ", queue[x]);
                    
                    rear = -1;  //resetting the rear to the original value
                }
			    
				break;
			default:
				printf("Invalid choice.\n");
				break;
		}
		
		printf("\nDo you wish to go back to menu? (1 = YES | 0 = NO): ");
		scanf("%d", &repeat);
		
		system("cls");
	}
	while(repeat == 1);
	
	return 0;
}