#include <stdio.h>
#include "myBank.h"

int main(){

    char t; 
    double amount;
    int account_number, interest_rate;
    int flag = 0;

    while (flag==0){
        printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        if(scanf(" %c", &t) == EOF){
            printf("Prematurely ended file\n");
            flag = 1;
            return 0;
        }

        if (t=='O'){
                printf("Please enter amount for deposit: ");
                if (scanf(" %lf",&amount)==1){
                    O(amount);
                }
                else{
                    printf("Failed to read the amount\n");
                }
        }

        else if (t=='B'){
            printf("Please enter account number: ");
            if(scanf(" %d", &account_number)==1){
                B(account_number);
            }
            else{
                printf("Failed to read the account number\n");
            }
            
        }

        else if (t=='D'){
            printf("Please enter account number: ");
            if (scanf(" %d", &account_number)==1){
                if (check_acc_number(account_number) == 1){ //account number is valid and open
                    printf("Please enter the amount to deposit: ");
                    if(scanf(" %lf", &amount)==1){
                        D(account_number, amount);
                    }
                    else{
                        printf("Failed to read the amount\n");
                    }
                }
            }

            else{
                printf("Failed to read the account number\n");
            }
        }

        else if (t=='W'){
            printf("Please enter account number: ");
            if (scanf(" %d", &account_number)==1){
                if (check_acc_number(account_number) == 1){ //account number is valid and open
                    printf("Please enter the amount to withdraw: ");
                    if(scanf(" %lf", &amount)==1){
                        W(account_number, amount);
                    }
                    else{
                        printf("Failed to read the amount\n");
                    }
                }
            }

            else{
                printf("Failed to read the account number\n");
            }
        }
            
        else if (t=='C'){
            printf("Please enter account number: ");
            if(scanf(" %d", &account_number)==1){
                C(account_number);
            }
            else{
                printf("Failed to read the account number\n");
            }
        }
            
        else if (t=='I'){
            printf("Please enter interest rate: ");
            if(scanf(" %d", &interest_rate)==1){
                I(interest_rate);
            }
            else{
                printf("Failed to read the interest rate\n");
            }  
        }
        
        else if (t=='P'){
            P();
        }
            
        else if (t=='E'){
            E();
            flag=1;
           // printf("\n");
            return 0;
        }
        
        else{
            printf("Invalid transaction type\n");
        }    
    }
    return 0;
}