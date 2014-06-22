#include<stdio.h>
#include<stdlib.h>
#include "yasergraph.h"
void Welcome();
void Get_function();
void Get_function_dependent();
void Index();	
void Independent();
void Dependent();
void Addition();
void Multiplication();
void General();
void Shifting(int );
void Folding(int );
void Scaling(int);
void Display();
int *signal;
int *signal1;				//for signal value
int number,number1;			//number of signals
int final[17];				//final value for graph
int final1[17];				//final value for second signal graph
int key=0;				//for Index function which one to choose independent r dependent
int result[17];
int check=0;				//for folding process
main()
{

	int choose;
	int con;
	
	do
	{
		Welcome();
		printf("\n\tEnter Your Choice \n\t1.Dependent Variable\n\t2.Independent Variable\n\t\t");
		scanf("%d",&choose);

		switch(choose)
		{
			case 1:
				Dependent();
				break;
			case 2:
				Independent();
				break;
			default:
				printf("\n\tWrong Choice ");
		}
		printf("\n\t If u want to continue press 1 or else press 2\n\t\t");
		scanf("%d",&con);
	}while(con==1);
}

void Welcome()
{
	system("clear");
	printf( "                                               \n"
                "                                               \n"
                "                WELCOME                        \n"
                "                  TO                           \n"
                "         BASIC SIGNAL OPERATION                \n"
                "                                               \n"
                "                                               \n"
                "                                               \n");
}

void Get_function_dependent()
{
	printf("\n\tEnter the number of First signal\n\t\t");
        scanf("%d",&number);                            //For number of signals
        signal=(int *)malloc(number*sizeof(int));
	int i;                                          //dummy variable for "FOR LOOP"
        printf("\n\tEnter the signal\n\t\t");
        for(i=0;i<number;i++)
                scanf("%d",&signal[i]);                 //Getting the signals
	printf("\n\tEnter the number of Second signal\n\t\t");
        scanf("%d",&number1);                            //For number of signals
        signal1=(int *)malloc(number1*sizeof(int));
        printf("\n\tEnter the signal\n\t\t");
        for(i=0;i<number1;i++)
                scanf("%d",&signal1[i]);                 //Getting the signals
	key=1;
}

void Get_function()
{
	printf("\n\tEnter the number of signal\n\t\t");
   	scanf("%d",&number);                            //For number of signals
        signal=(int *)malloc(number*sizeof(int));
        int i;                                          //dummy variable for "FOR LOOP"
        printf("\n\tEnter the signal\n\t\t");
        for(i=0;i<number;i++)
                scanf("\t\t%d",&signal[i]);                 //Getting the signals
        printf("\n\tYour Signal");
        printf("\n\t{");
        for(i=0;i<number;i++)
        {
                printf("%d",signal[i]);
                if(i!=number-1)
                        printf(",");
        }
        printf("}\n");
}

//To find Index Value

void Index()
{
	int index;
	printf("\n\t Enter the index value\n\t\t");
	scanf("%d",&index);
	int m,i,j;
	m=index-1;
	for(i=m,j=8;i<number;i++,j++)			//Aft Zero Crossing
	{
		final[j]=signal[i];
	}
	for(;j<=17;j++)					//Padding Zeros
	{
		final[j]=0;
	}
	for(i=m-1,j=7;i>=0;i--,j--)			//Before Zero Crossing
	{
		final[j]=signal[i];
	}
	for(;j>=0;j--)					//Padding zeros
	{
		final[j]=0;
	}
	if(key==1)
	{
		int index1;
		printf("\n\t Enter the Index value for Second Signal\n\t\t");
		scanf("%d",&index1);
	        int m,i,j;
	        m=index1-1;
	        for(i=m,j=8;i<number1;i++,j++)		//Aft Zero Crossing for second signal
	        {
	                final1[j]=signal1[i];
	        }
	        for(;j<=17;j++)				//Padding Zeros for second signal
	        {
	                final1[j]=0;
	        }
	        for(i=m-1,j=7;i>=0;i--,j--)		//Before Zero Crossing for second signal
	        {
	                final1[j]=signal1[i];
	        }
		for(;j>=0;j--)				//Padding zeros for second signal
	        {
	                final1[j]=0;
	        }
		key=0;
		
	}

}

void Dependent()
{
	int u,i;
	printf("\n\tEnter your Choice\n\t1.Signal Addition\n\t2.Constant Multiplication\n\t\t");
	scanf("%d",&u);
	switch(u)
	{
		case 1:
			Get_function_dependent();
			Index();
			Addition();
			Function(final);
			Display();
			break;
		case 2:
			Get_function();
			Index();
			Multiplication();
			Function(final);
                        Display();
			break;
		default:
			printf("\n\tWrong Choice\n\t");
		
	}
}


void Multiplication()
{
	int i,data;
	printf("\n\tEnter a value that to be multiplied\n\t");
	scanf("%d",&data);
	for(i=0;i<17;i++)
		final[i]=data*final[i];
}


void Addition()
{
	int i;
	for(i=0;i<17;i++)
		final[i]=final[i]+final1[i];
}


void Independent()
{
        int u,k;
        printf("\n\tEnter your Choice\n\t1.Shifting\n\t2.Folding\n\t3.Scaling\n\t4.General\n\t\t");
        scanf("%d",&u);
        switch(u)
        {
                case 1:
			Get_function();
                        Index();
			printf("\n\tThis is your format\n\t\t x[n-k]");
			printf("\n\tEnter k=");
        		scanf("%d",&k);
			Shifting(k);
			Function(final);
			Display();
			break;
		case 2:
			Get_function();
                        Index();
			Folding(-1);	
			check=0;
			Function(final);
			Display();
			break;
		case 3:
			Get_function();
                        Index();
			printf("\n\tEnter a number for Scaling");
                        scanf("%d",&k);
			Scaling(k);
			Function(final);
			Display();
			break;
		case 4:
			Get_function();
			Index();
			General();
			Function(final);
			Display();
			break;
		default:
                        printf("\n\tWrong Choice\n\t");
	}
}


void General()
{	
	int A,K,B;
	printf("\n\tThis is your format");
	printf("\n\t        X[an-k]");
	printf("\n\tEnter a=");
	scanf("%d",&A);
	printf("\n\tEnter k=");
	scanf("%d",&K);
	Shifting(K);
	Folding(A);
	if(check==1)
	{
		A=-A;
		check=0;
	}
	Scaling(A);
	
}
//Shifting

void Shifting(int k)
{
	int i;
		if(k<=0)
		{
			for(i=0;i<17;i++)
				final[i]=final[i-k];			
		}
		if(k>0)
		{
			for(i=16;i>=0;i--)
				final[i]=final[i-k];
		}
}
//Folding

void Folding(int a)
{
	int i,j,temp;
		if(a<0)
		{
			for(i=0,j=16;i<9,j>=8;i++,j--)
			{
				temp=final[i];
				final[i]=final[j];
				final[j]=temp;
			}
			check=1;
		}
			
}
//scaling
void Scaling(int a)
{
	int i,f;
		if(a>1)
		{
			f=8;
                        for(i=7;i>=0;i--)
			{
				f=f-a;
				final[i]=final[f];
			}
			f=8;
			for(i=9;i<=16;i++)
			{
				f=f+a;
				final[i]=final[f];
			}
		}
}
	
void Display()
{
	int i;
	printf("\n\t**********Result*************\n\n");
	printf("\n\t\t{");
	for(i=0;i<17;i++)
		printf("%d,",final[i]);
	printf("}\n\n");
	printf("\n\t*****************************");
}
//End of program