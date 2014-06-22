#include<stdio.h>
void Function(int input[])
{

	int l,r;							//l for longitude		r for row



// To Find The largest and smallest number in the input signal

	int check,large,small,n=17;
	int l1,s1;
	large=input[0];
	small=input[0];
	for(check=0;check<n;check++)
	{
		if(input[check]>=large)
		{
			large=input[check];
			l1=check;
		}
		if(input[check]<=small)
		{
			s1=check;
			small=input[check];
		}
	}






//For Positive side of Graph


	for(l=input[l1];l>0;l--)					//for Yaxis Maximum
	{
		for(r=0;r<=162;r++)					// For Xaxis
		{
			if(r==1&&input[0]>=l)
				printf("|");
			else if(r==11&&input[1]>=l)
				printf("|");
                        else if(r==21&&input[2]>=l)
                                printf("|");
                        else if(r==31&&input[3]>=l)
                                printf("|");
                        else if(r==41&&input[4]>=l)
                                printf("|");
                        else if(r==51&&input[5]>=l)
                                printf("|");
                        else if(r==61&&input[6]>=l)
                                printf("|");
                        else if(r==71&&input[7]>=l)
                                printf("|");
                        else if(r==81&&input[8]>=l)
                                printf("|");
                        else if(r==91&&input[9]>=l)
                                printf("|");
                        else if(r==101&&input[10]>=l)
                                printf("|");
                        else if(r==111&&input[11]>=l)
                                printf("|");
                        else if(r==121&&input[12]>=l)
                                printf("|");
                        else if(r==131&&input[13]>=l)
                                printf("|");
                        else if(r==141&&input[14]>=l)
                                printf("|");
                        else if(r==151&&input[15]>=l)
                                printf("|");
                        else if(r==161&&input[16]>=l)
                                printf("|");


			else if(r==162)
				printf("\n");
			else
				printf(" ");
			
		}
	}



// For Base line of Xaxis and its value



	int i,j,h=0;
	int num=-8;
	int xaxis=1;
//	printf("Enter the  X axis unit(only 17 is limited)\n");
//	scanf("%d",&xaxis);
	printf(" ");
	for(i=0;i<=160;i++)
	{
		printf("_");						//for  Xaxis line
	}
	printf("\n ");
	for(i=0;i<=160;i++)
	{
		if(i==h)
		{
			printf("|");					//for Values
			h=h+10;
		}
		else
		{
			printf(" ");
		}
	}
	printf("\n");
	if(num>0)
		printf(" ");
	int k=0,p=0,g=0;
	int googly;
	for(j=0;j<=160;j++)
	{
        	if(j==k)
                {
			googly=num*xaxis;
                	printf("%d",googly);
                        k=k+10;
			num=num+1;
			if((googly<0&&googly>-9)||googly>9)
				p=1;					//flag
			if(googly<=-10)				
				g=1;					//flag
                }
		else
		{
			printf(" ");
			if(p==1)
			{
				j=j+1;
				p=0;
			}
			if(g==1)
			{
				j=j+2;
				g=0;
			}
		}
	}
	printf("\n");




//For Negative Side of the graph




	for(l=0;l>input[s1];l--)
        {
                for(r=0;r<=162;r++)
                {
                        if(r==1&&input[0]<l)
                                printf("|");
                        else if(r==11&&input[1]<l)
                                printf("|");
                        else if(r==21&&input[2]<l)
                                printf("|");
                        else if(r==31&&input[3]<l)
                                printf("|");
                        else if(r==41&&input[4]<l)
                                printf("|");
                        else if(r==51&&input[5]<l)
                                printf("|");
                        else if(r==61&&input[6]<l)
                                printf("|");
                        else if(r==71&&input[7]<l)
                                printf("|");
                        else if(r==81&&input[8]<l)
                                printf("|");
                        else if(r==91&&input[9]<l)
                                printf("|");
                        else if(r==101&&input[10]<l)
                                printf("|");
                        else if(r==111&&input[11]<l)
                                printf("|");
                        else if(r==121&&input[12]<l)
                                printf("|");
                        else if(r==131&&input[13]<l)
                                printf("|");
                        else if(r==141&&input[14]<l)
                                printf("|");
                        else if(r==151&&input[15]<l)
                                printf("|");
                        else if(r==161&&input[16]<l)
                                printf("|");
			
			
                        else if(r==162)
                                printf("\n");
                        else
                                printf(" ");

                }
        }
}
