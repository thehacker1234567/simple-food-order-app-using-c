
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
int sum;
int ch,quan;
char i1[30],s1[5];
struct Node
{

	char itemid[5];
	char item[30];
	int rate;
	int quantity;
	struct Node*next;
};
struct Node* head = NULL;
void slv();
void taaza();
void southindian();
void northindian();
void anna();
void fastfood();
void select();
void dal();
void punj();
void domi();
void payment();




void push(struct Node** head_ref,char i1[],int quan,char s1[],int price)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* 2. put in the data */
	new_node->rate =price ;
	new_node->quantity=quan;
	strcpy(new_node->item,i1);
	strcpy(new_node->itemid,s1);

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}
void printlist()
{
     sum=0;
     struct Node *temp = head;
	while(temp!=NULL)
	{
		printf("%s\t\t%s\t\t%d\t\t%d\t\t\n",temp->itemid,temp->item,temp->quantity,temp->rate*temp->quantity);
		sum=sum+(temp->rate*temp->quantity);
		//node = node->next;
		temp = temp->next;
	}

}

void payment()
{
	int c,c2;
	char itid[5];
	printf("the items in your cart is \n");
	printlist();
	printf("grand total=%d\n",sum);
	printf("if u want to proceed to payment press 1 or delete any item press 0\n");
	scanf("%d",&c);
	if(c==1)
	{
		printf("the modes of payment are \n");
		printf("1:DEBIT CARD\n2:CREDIT card\n3:COD\n");
		printf("enter your choice \n");
		scanf("%d",&c2);
		switch(c2)
		{

		case 1:
		case 2:printf("u r being redirected to payment page dont refresh\n");
			printf("payment succesfull\n");
			printf("our delivery agent will get food to your location within 30 min\n");
			printf("thank u for shopping\n");
			exit(0);
			break;

		case 3:

			printf("our delivery agent will get food to your location within 30 min\n");
			printf("thank u for shopping\n");
			exit(0);
			break;
		default:printf("invalid choice\n");
		}
	}
	else if(c==0)
	{
		printf("enter the item id that has to be deleted\n");
		scanf("%s",&itid);
		deletenode(itid);
	}
}
void deletenode(char itid[])
{
		struct Node *temp = head, *prev,*temp2 = head;
		if (temp != NULL &&  !(strcmp(itid,temp->itemid)))
		{
			if(temp->quantity>1)
				temp->quantity=temp->quantity--;
			else
			{

                head = temp->next;
				free(temp);
				return;

			}
		}
		while(temp!=NULL)
		{
		    if(!strcmp(itid,temp->itemid))
            {
			if((temp->quantity)>1)
				temp->quantity=temp->quantity-1;
			else{
				while(temp2->next != temp)
                    temp2 = temp2->next;
                 temp2->next = temp->next;
                 free(temp);
			}
        }
        temp = temp->next;
		}
		 //if (temp == NULL)return;


    // Unlink the node from linked list
    //prev->next = temp->next;

    //free(temp);
	payment();
		// Free memory
}

void slv()
{
    system("cls");
	while(1)
	{
		printf("ITEMID\t\tITEM\t\t\tcost\n");
		printf("s1\t\tMASALA DOSA\t\t25\n");
		printf("s2\t\tIDLI\t\t10\n");
		printf("s3\t\tPONGAL\t\t20\n");
		printf("s4\t\tRICE BATH\t\t20\n");
		printf("5\t\tcontinue in south indian\n");
		printf("6\t\tswitch the cuisine\n");
		printf("7\t\tcheckout\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("u selected MASALA DOSA\n");
				printf("Enter the quantity\n");
				scanf("%d",&quan);
				 strcpy(i1,"MASALA DOSA");
				 strcpy(s1,"s1");

				push(&head,i1,quan,s1,25);
			break;
			case 2:printf("u selected IDLI \n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"IDLI");

				strcpy(s1,"s2");
				push(&head,i1,quan,s1,10);
			break;
			case 3:printf("u selected PONGAL");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"PONGAL");

				strcpy(s1,"s3");

				push(&head,i1,quan,s1,20);
			break;
			case 4:printf("u selected ricebath\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"RICE BATH");
				strcpy(s1,"s4");



				push(&head,i1,quan,s1,20);
			break;
			case 5:southindian();
				break;
			case 6:select();
				break;
			case 7:payment();
				break;
			default:printf("invalid option\n");
		}
	}
}
void taaza()
{
    system("cls");
	int ch;
	while(1)
	{
		printf("ITEMID\t\tITEM\t\t\tcost\n");
		printf("t1\t\tVEG PULAV\t\t25\n");
		printf("t2\t\tAKKI ROTI\t\t20\n");
		printf("t3\t\tBISI BELE BATH\t\t30\n");
		printf("t4\t\tKESARI BATH\t\t20\n");
		printf("t5\t\tPOORI SAGU\t\t30\n");
		printf("6\t\tcontinue in south indian\n");
		printf("7\t\tswitch the cuisine\n");
		printf("8\t\tcheckout\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("u selected VEG PULAV\n");
				printf("Enter the quantity\n");
				scanf("%d",&quan);
				 strcpy(i1,"VEG PULAV");
				 strcpy(s1,"t1");

				push(&head,i1,quan,s1,25);
			break;
			case 2:printf("u selected AKKI ROTI \n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"AKKI ROTI");
				strcpy(s1,"t2");
				push(&head,i1,quan,s1,20);
			break;
			case 3:printf("u selected BISI BELE BATH\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"BISI BELE BATH");
				strcpy(s1,"t3");
				push(&head,i1,quan,s1,30);
			break;
			case 4:printf("u selected KESARI BATH\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"KESARI BATH");
				strcpy(s1,"t4");
				push(&head,i1,quan,s1,20);
			break;
			case 5:printf("u selected POORI SAGU\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"POORI SAGU");
				strcpy(s1,"t5");
				push(&head,i1,quan,s1,30);
			break;
			case 6:southindian();
				break;
			case 7:select();
				break;
			case 8:payment();
				break;
			default:printf("invalid option\n");
		}
	}
}
void anna()
{
    system("cls");
	int ch;
	while(1)
	{
		printf("ITEMID\t\tITEM\t\t\tcost\n");
		printf("a1\t\tBHARJARI UDUPI BHOJANA\t\t200\n");
		printf("a2\t\tPULIYOGARE\t\t35\n");
		printf("a3\t\tUPMA\t\t28\n");
		printf("a4\t\tJOLADA ROTI\t\t25\n");
		printf("a5\t\tONION DOSA\t\t30\n");
		printf("6\t\tcontinue in south indian\n");
		printf("7\t\tswitch the cuisine\n");
		printf("8\t\tcheckout\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("u selected BHARJARI UDUPI BHOJANA\n");
				printf("Enter the quantity\n");
				scanf("%d",&quan);
				 strcpy(i1,"BHARJARI UDUPI BHOJANA");
				 strcpy(s1,"a1");

				push(&head,i1,quan,s1,200);
			break;
			case 2:printf("u selected PULIYOGARE \n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1," PULIYOGARE");
				strcpy(s1,"a2");
				push(&head,i1,quan,s1,35);
			break;
			case 3:printf("u selected UPMA\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"UPMA");
				strcpy(s1,"a3");
				push(&head,i1,quan,s1,28);
			break;
			case 4:printf("u selected JOLADA ROTI\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"JOLADA ROTI");
				strcpy(s1,"a4");
				push(&head,i1,quan,s1,25);
			break;
			case 5:printf("u selected ONION DOSA\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"ONION DOSA");
				strcpy(s1,"a5");
				push(&head,i1,quan,s1,30);
			break;
			case 6:southindian();
				break;
			case 7:select();
				break;
			case 8:payment();
				break;
			default:printf("invalid option\n");
		}
	}
}
void southindian()
{
    system("cls");
	int ch,ch1;
	while(1)
	{
		printf("These are the restaurants that offer u tasty and delicious southindian dishes\n");
		printf("1:SLV DAKSHINA GRAND\n2:TAAZA THINDI\n3:ANNA KUTEERA\n4:change the cuisine\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		fflush;
		switch(ch)
		{
			case 1:slv();
				break;
			case 2:taaza();
				break;
			case 3:anna();
				break;


			case 4:select();
				break;
			default:printf("invalid option\n");

		}
	}
}
void select()
{


    system("cls");
	while(1)
	{
		printf("enter your choice\n");
		printf("select your favaorite cuisine\n");
		printf("1:NORTH INDIAN\n2:SOUTH INDIAN\n3:FAST FOOD\n4:exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:northindian();
				break;
			case 2:southindian();
				break;

			case 3:fastfood();
				break;
			case 4:exit(0);
			default:printf("invalid choice\n");
		}
	}
}
void main()

{
    system("cls");
	int ch;
	char name[20];
	unsigned long int mnum;
	printf("WELCOME TO ONLINE FOOD ORDERING SYSTEM\n");
	printf("------------------------------------------\n");
	printf("OFFER\n");
	printf("order for 500 and get 10 percent discount\n");
	printf("enter your name\n");
	gets(name);
	printf("enter your mobile number\n");
	scanf("%lu",&mnum);
	select();
}



void northindian()
{
    system("cls");
	int ch;
	while(1)
	{
		printf("These are the restaurants that offer u tasty and delicious northindian dishes\n");
		printf("1:DAL TADKA\n2:PUNJABI SPICY\n3:change the cuisine\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		fflush;
		switch(ch)
		{
			case 1:dal();
				break;
			case 2:punj();
				break;



			case 3:select();
				break;
			default:printf("invalid option\n");

		}
	}
}
void dal()
{
        system("cls");

	int ch;
	while(1)
	{
		printf("ITEMID\t\tITEM\t\t\tcost\n");
		printf("d1\t\tROTI AND DHAL FRY\t\t60\n");
		printf("d2\t\tPANEER BUTTER MASALA\t\t95\n");
		printf("d3\t\tCHOLE BATTURA\t\t40\n");
		printf("d4\t\tRAJASTHANI BIRYANI\t\t120\n");
		printf("d5\t\tPALAK PANEER\t\t75\n");
		printf("6\t\tcontinue in north indian\n");
		printf("7\t\tswitch the cuisine\n");
		printf("8\t\tcheckout\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("u selected ROTI AND DHAL FRY\n");
				printf("Enter the quantity\n");
				scanf("%d",&quan);
				 strcpy(i1,"ROTI AND DHAL FRY");
				 strcpy(s1,"d1");

				push(&head,i1,quan,s1,60);
			break;
			case 2:printf("u selected PANEER BUTTER MASALA\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"PANEER BUTTER MASALA");
				strcpy(s1,"d2");
				push(&head,i1,quan,s1,95);
			break;
			case 3:printf("u selected CHOLE BATTURA\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"CHOLE BATTURA");
				strcpy(s1,"d3");
				push(&head,i1,quan,s1,40);
			break;
			case 4:printf("u selected RAJASTHANI BIRYANI\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"RAJASTHANI BIRYANI");
				strcpy(s1,"d4");
				push(&head,i1,quan,s1,120);
			break;
			case 5:printf("u selected PALAK PANEER\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"PALAK PANEER");
				strcpy(s1,"d5");
				push(&head,i1,quan,s1,75);
			break;
			case 6:northindian();
				break;
			case 7:select();
				break;
			case 8:payment();
				break;
			default:printf("invalid option\n");
		}
	}
}
void punj()
{
        system("cls");

	int ch;
	while(1)
	{
		printf("ITEMID\t\tITEM\t\t\tcost\n");
		printf("pu1\t\tSPICY PUNJABI BIRYANI\t\t150\n");
		printf("pu2\t\tVEG SPICY CURRY\t\t95\n");
		printf("pu3\t\tMESSI ROTI\t\t28\n");
		printf("pu4\t\tSWEET LASSI\t\t15\n");

		printf("5\t\tcontinue in north indian\n");
		printf("6\t\tswitch the cuisine\n");
		printf("7\t\tcheckout\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("u SPICY PUNJABI BIRYANI \n");
				printf("Enter the quantity\n");
				scanf("%d",&quan);
				 strcpy(i1,"SPICY PUNJABI BIRYANI");
				 strcpy(s1,"pu1");

				push(&head,i1,quan,s1,150);
			break;
			case 2:printf("u selected VEG SPICY CURRY\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"VEG SPICY CURRY");
				strcpy(s1,"pu2");
				push(&head,i1,quan,s1,95);
			break;
			case 3:printf("u selected MESSI ROTI\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"MESSI ROTI");
				strcpy(s1,"pu3");
				push(&head,i1,quan,s1,28);
			break;
			case 4:printf("u selected SWEET LASSI\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"SWEET LASSI");
				strcpy(s1,"pu4");
				push(&head,i1,quan,s1,15);
			break;

			case 5:northindian();
				break;
			case 6:select();
				break;
			case 7:payment();
				break;
			default:printf("invalid option\n");
		}
	}
}
void fastfood()
{
        system("cls");

	int ch;
	while(1)
	{
		printf("These are the restaurants that offer u tasty and delicious fastfood\n");
		printf("1:DOMINOS\n2:change the cuisine\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		fflush;
		switch(ch)
		{
			case 1:domi();
				break;






			case 2:select();
				break;
			default:printf("invalid option\n");

		}
	}
}
void domi()
{
        system("cls");

	int ch;
	while(1)
	{
		printf("ITEMID\t\tITEM\t\t\tcost\n");
		printf("do1\t\tVEG PIZZA\t\t200\n");
		printf("do2\t\tMEXICAN PIZZA\t\t250\n");
		printf("do3\t\tCHCOLATE LAVA CKE\t\t95\n");
		printf("4\t\tcontinue in fastfood\n");
		printf("5\t\tswitch the cuisine\n");
		printf("6\t\tcheckout\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("u selected VEG PIZZA\n");
				printf("Enter the quantity\n");
				scanf("%d",&quan);
				 strcpy(i1,"VEG PIZZA");
				 strcpy(s1,"do1");

				push(&head,i1,quan,s1,200);
			break;
			case 2:printf("u selected MEXICAN PIZZA\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				strcpy(i1,"MEXICAN PIZZA");
				strcpy(s1,"do2");
				push(&head,i1,quan,s1,250);
			break;
			case 3:printf("u selected CHOCOLATE LAVA CAKE\n");
				printf("enter the quantity\n");
				scanf("%d",&quan);
				scanf(i1,"CHOCOLATE LAVA CAKE");
				strcpy(s1,"do3");
				push(&head,i1,quan,s1,95);
			break;
			case 4:fastfood();
				break;
			case 5:select();
				break;
			case 6:payment();
				break;
			default:printf("invalid function\n");
		}
	}
}
/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */































