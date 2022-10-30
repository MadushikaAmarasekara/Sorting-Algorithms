#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

typedef struct node* st;

st start=NULL;
st createnode()
{
	int value;
	st newnode=(st)malloc(sizeof(st));
	
	newnode->data=value;
	newnode->next=NULL;
}

st insert(st start)
{
	st t,temp;
	int value;
	t=createnode();
	printf("\nEnter number  : ");
	scanf("%d",&value);
	if(start==NULL)
	{
		start=t;
		t->data=value;
		t->next=NULL;
	}
	
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	temp->next=t;
	t->data=value;
	t->next=NULL;
	
	return start;
}

st sort(st start)
{
	st pre,ptr;
	int temp;
	pre=start;
	while(pre!=NULL)
	{
		ptr=pre->next;
		
		while(ptr!=NULL)
		{
			if(pre->data>=ptr->data)
			{
				temp=pre->data;
				pre->data=ptr->data;
				ptr->data=temp;
			}
			ptr=ptr->next;
		}
		pre=pre->next;
		
	}
	
	return start;
}

st display(st start)
{
	st ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
			start=sort(start);
	}
	printf("\n");
	printf("Largest Element:");
	while(ptr!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=NULL;
	
		printf("\n%d",ptr->data);
	
	return start;
}
int main()
{
	int choice;
	printf("Dynamic Memory Allocation :\n");
	
	do {
			
		printf("\n\t1. Add New Number");
		printf("\n\t2. Show All The Numbers");
		printf("\n");
		
		
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: start = insert(start);
					break;
			case 2: start = display(start);
					break;
				}
	}
	while(choice!=3);
	
return start;	
}


