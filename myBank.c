#include <stdio.h>
#include <stdlib.h>
double accounts[2][50];

void O(double amount){ //Open account
    int flag=0; //flag=true
    int i=0;
    int new_acc_number=0;
    if (amount>=0){
        while(flag==0 && i<50){
            if (accounts[1][i] == 0){
                new_acc_number = i;
                accounts[0][i] = amount;
                accounts[1][i] = 1; //account is now open
                flag=1;
            }
            i++;
        }
        if (flag == 1){ //opened an account
            printf("New account number is: %d \n", new_acc_number+901);
        }
        else{
            printf("Sorry, there are already 50 open accounts\n");
        }
    }
    else{ //amount is less than 0
        printf("Invalid Amount\n");
    }
}
  
void B(int account_number){ //Balance
    if ((account_number-901 > 49) || (account_number-901<0)){ //acc number is not in range (range of acc numbers is between 901-950)
        printf("Invalid account number\n"); 
    }
    else if (accounts[1][account_number-901]==1) { //means account is open
        printf("The balance of account number %d is: %0.2lf\n", account_number, accounts[0][account_number-901]);  
    }
    else {
        printf("This account is closed\n");
    }
}

void D(int account_number, double amount){ //Deposit
    if (amount >= 0){
        accounts[0][account_number-901] += amount;
        printf("The new balance is: %0.2lf\n", accounts[0][account_number-901]);
    }
    else{
        printf("Cannot deposit a negative amount\n");
    }
}

void W(int account_number, double amount){ //Withdraw
    if (amount<0){
        printf("Cannot withdraw a negative amount\n");
    }
    else if (accounts[0][account_number-901]<amount){
        printf("Cannot withdraw more than the balance\n");
    }
    else{
        accounts[0][account_number-901] -= amount;
        printf("The new balance is: %0.2lf\n", accounts[0][account_number-901]);
    }
}

void C(int account_number){ //Close account
    if ((account_number-901 > 49) || (account_number-901<0)){
        printf("Invalid account number\n");
    }

    else if (accounts[1][account_number-901]==1){
        accounts[1][account_number-901]=0; //close the account;
        accounts[0][account_number-901]=0;
        printf("Closed account number %d\n", account_number);
    }

    else{
        printf("This account is already closed\n");
    }
}

void I(int interest_rate){ //Interest
        for (int i=0; i<50; i++){
            if (accounts[1][i]==1){
                accounts[0][i] = ((interest_rate+100)*(accounts[0][i]))/100;
            }
        }
        printf("\n");
}

void P(){ //Print all open accounts and their balance
    for(int i=0; i<50; i++){
        if (accounts[1][i]==1){
            printf("The balance of account number %d is: %0.2lf\n", i+901, accounts[0][i]);
        }
    }
}

void E(){ //Exit
    for(int i=0; i<50; i++){
        if (accounts[1][i]==1){
            accounts[1][i]=0;
            accounts[0][i]=0;
        }
    }
}

int check_acc_number(int account_number){
    if ((account_number-901 > 49) || (account_number-901<0)){
        printf("Invalid account number\n");
        return 0;
    }
    else if (accounts[1][account_number-901]==0) {
        printf("This account is closed\n");
        return 0;
    }
    return 1; //account number is valid and open
}