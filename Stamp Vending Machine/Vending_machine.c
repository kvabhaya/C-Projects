#include <stdio.h>

int main()
{
        printf("-----------------------------------------------\n\n");
        printf("------Welcome to Stamp Vending Machine!!!------\n\n");
        printf("-----------------------------------------------\n\n");
        int stamp,coin,change,flag;
        int stamp25=20,stamp15=20,stamp10=20,coin50=10,coin25=10,coin10=10,coin5=10;
        do{
            printf("Prices of Stamps:\nYou Have below Choices\n\t\tRs.25 stamp\n\t\tRs.15 stamp\n\t\tRs.10 stamp\n");
            printf("Enter Your Preferred Choice as 25 or 15 or 10:\n");
            scanf("\t\t%d",&stamp);
            printf("\n");
            printf("Amounts of Coins That You Can Entered:\nYou Have below Choices\n\t\tRs.50\n\t\tRs.25\n\t\tRs.10\n\t\tRs.5\n");
            printf("Enter Your Preferred Choice as 50 or 25 or 10 or 5:\n");
            scanf("\t\t%d",&coin);
            printf("\n");
            if(coin!=50&&coin!=25&&coin!=10&&coin!=5)
            {
                printf("-----------------------------------------------\n");
                printf("You Entered Wrong Coin Value\n");
                printf("-----------------------------------------------\n");
                printf("Do You Want To Continue?\n");
                printf("if YES press 1 and if NO press 0 \n");
                scanf("%d",&flag);
                printf("-----------------------------------------------\n");
                continue;
            }
            else{
                if (stamp<=coin)
                {
                    if (stamp25<=0||stamp15<=0||stamp10<=0)
                    {
                        printf("-----------------------------------------------\n");
                        printf("No Stamps Available\n");
                        printf("-----------------------------------------------\n\n");
                        printf("Do You Want To Continue?\n");
                        printf("if YES press 1 and if NO press 0 \n");
                        scanf("%d",&flag);
                        printf("-----------------------------------------------\n");
                        continue;
                    }
                    else
                    {
                        if(stamp==25||stamp==15||stamp==10)
                        {
                            switch(stamp)
                            {
                                case 25: stamp25--; break;
                                case 15: stamp15--; break;
                                case 10: stamp10--; break;
                            }
                        }
                        else
                        {
                            printf("-----------------------------------------------\n");
                            printf("You Entered Wrong Stamp Value\n");
                            printf("-----------------------------------------------\n");
                            printf("Do You Want To Continue?\n");
                            printf("if YES press 1 and if NO press 0 \n");
                            scanf("%d",&flag);
                            printf("-----------------------------------------------\n");
                            continue;
                        }
                    }
                    if(coin50<=0||coin25<=0||coin10<=0||coin5<=0)
                    {
                        printf("-----------------------------------------------\n");
                        printf("No Coins Available\n");
                        printf("-----------------------------------------------\n\n");
                        printf("Do You Want To Continue?\n");
                        printf("if YES press 1 and if NO press 0 \n");
                        scanf("%d",&flag);
                        printf("-----------------------------------------------\n");
                        continue;
                    }
                    if(coin==50||coin==25||coin==10||coin==5)
                    {
                        switch(coin)
                        {
                            case 50: coin50++; break;
                            case 25: coin25++; break;
                            case 10: coin10++; break;
                            case 5: coin5++; break;
                        }
                    }
                    change=coin-stamp;
                    printf("\n\n");
                    printf("Your Balance is: %d\n\n",change);
                    switch(change)
                        {
                            case 40:
                                printf("Your Can Get Your Balance as below\n");
                                printf("\t\t25 Coins:1\n\t\t10 Coins:1\n\t\t05 Coins:1\n");
                                --coin25;
                                --coin10;
                                --coin5;
                                break;
                            case 35:
                                printf("Your Can Get Your Balance as below\n");
                                printf("\t\t25 Coins:1\n\t\t10 Coins:1\n");
                                --coin25;
                                --coin10;
                                break;
                            case 25:
                                printf("Your Can Get Your Balance as below\n");
                                printf("\t\t25 Coins:1\n");
                                --coin25;
                                break;
                            case 15:
                                printf("Your Can Get Your Balance as below\n");
                                printf("\t\t10 Coins:1\n\t\t05 Coins:1\n");
                                --coin10;
                                --coin5;
                                break;
                            case 10:
                                printf("Your Can Get Your Balance as below\n");
                                printf("\t\t10 Coins:1\n");
                                --coin10;
                                break;
                            case 0:
                                printf("You Haven't any Balance\n");
                                break;
                        }
                        printf("-----------------------------------------------\n\n");
                        printf("available quantity of stamp,\n\t\t25 Stamps=%d\n\t\t15 Stamps=%d\n\t\t10 Stamps=%d\n\n",stamp25,stamp15,stamp10);
                        printf("-----------------------------------------------\n\n");
                        printf("available quantity of coins,\n\t\t50 Coins=%d\n\t\t25 Coins=%d\n\t\t10 Coins=%d\n\t\t05 Coins=%d\n",coin50,coin25,coin10,coin5);
                        printf("\n\n");

                        printf("Do You Want To Continue?\n");
                        printf("if YES press 1 and if NO press 0 \n");
                        scanf("%d",&flag);
                }
                else
                {
                    if(stamp==25||stamp==15||stamp==10){
                        printf("-----------------------------------------------\n");
                        printf("Insufficient Amount Tendered...\n");
                        printf("-----------------------------------------------\n\n");
                        printf("Do You Want To Continue?\n");
                        printf("if YES press 1 and if NO press 0 \n");
                        scanf("%d",&flag);
                    }
                    else
                    {
                        printf("-----------------------------------------------\n");
                        printf("You Entered Wrong Stamp Value\n");
                        printf("-----------------------------------------------\n\n");
                        printf("Do You Want To Continue?\n");
                        printf("if YES press 1 and if NO press 0 \n");
                        scanf("%d",&flag);
                    }

                }
            }
    }while(flag==1);
}


