#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*p=NULL;

int search(int item)
{
	struct node *r;
	r=p;
	while(r!=NULL)
	{
		if(r->data==item)
		{
			return r;
		}
		r=r->next;
	}
	return NULL;
}

void InsertAtBeg(int num)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	if(p==NULL)
	{
		temp->next=NULL;
		p=temp;
	}
	else
	{
		temp->next=p;
		p=temp;
	}
}

void InsertAtEnd(int num)
{
	struct node *temp,*r;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	r=p;
	if(p==NULL)
	{
		temp->next=NULL;
		p=temp;
	}
	else
	{
		while(r->next!=NULL)
		{
			r=r->next;
		}
		temp->next=NULL;
		r->next=temp;
	}
}

void InsertAfterNode(int num, int num1)
{
	struct node *temp,*loc;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	loc=search(num1);
	if(p==NULL || loc==NULL)
	{
		printf("No Node Found");
	}
	else if(loc->next==NULL)
	{
		temp->next=NULL;
		loc->next=temp;
	}
	else
	{
		temp->next=loc->next;
		loc->next=temp;
	}
}

void display()
{
	struct node *r;
	r=p;
	if(p==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		while(r!=NULL)
		{
			printf("\n%d",r->data);
			r=r->next;
		}
	}
}


void DeletionAtBeg()
{
	struct node *temp;
	temp=p;
	if(p==NULL)
	{
		printf("Link List is empty");
	}
	else
	{
		p=temp->next;
		free(temp);
	}
}

void DeletionAtEnd()
{
	struct node *temp,*r;
	temp=p;
	r=temp->next;
	if(p==NULL)
	{
		printf("\nLink List is Empty");
	}
	else if(r==NULL)
	{
		p=NULL;
		free(temp);
	}
	else
	{
		while(r->next!=NULL)
		{
			temp=temp->next;
			r=r->next;
		}
		temp->next=NULL;
		free(r);
	}
}

void DeletionAfterNode(int num, int num1)
{
	struct node *temp,*loc;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	loc=search(num1);
	if(p==NULL || loc==NULL)
	{
		printf("No Node Found");
	}
	else if(loc->next==NULL)
	{
		temp->next=NULL;
		loc->next=temp;
	}
	else
	{
		temp->next=loc->next;
		loc->next=temp;
	}
}


int main()
{
	int ch,n,a=1,na;
	while(a=1){
		printf("\nEnter the choice");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1: printf("\nEnter the number to be added at the begnning");
					scanf("%d",&n);
					InsertAtBeg(n);
					break;
			case 2: printf("\nEnter the number to be added at the end");
					scanf("%d",&n);
					InsertAtEnd(n);
					break;
			case 3: printf("\nEnter the number to be added after a given node");
					scanf("%d",&n);
					printf("\nEnter the position of a given node");
					scanf("%d",&na);
					InsertAfterNode(n,na);
					break;
			case 4: DeletionAtBeg();
					break;
			case 5: DeletionAtEnd();
					break;
			case 6: display();
					break;
					
		}
	}
	return 0;
}
