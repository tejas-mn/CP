#include<iostream>
using namespace std;

/*Class Definition*/

class ATM
{
    private:
        int code;
        int balance;

    public:
        long card_no;

        /*Member function to set data*/
        void setData()
        {
            code=1212;
            balance=25000;
            card_no=12345;
        }

        int checkCode(int);
        void showBal();
        void withdraw(int);

};

/*Member Function to check code*/

int ATM::checkCode(int c)
{
    return (code==c)? 1 : 0;
}

/*Member Function to show Balance*/

void ATM::showBal()
{
    cout<<"Current balance is "<<balance<<"\n";
}

/*Member Function to Withdraw*/

void ATM::withdraw(int amt)
{
    if(balance>=amt)
    {
        balance=balance-amt;
        cout<<"Withdraw successful! Current Balance="<<balance<<"\n";
    }
    else
    {
        cout<<"Withdraw Failed!! Insufficient Balance";
    }
}


int main()
{
    int userCode,ch,amt;

    ATM  a;

    a.setData();

    cout<<"Enter your code: "<<"\n";
    cin>>userCode;

    if(a.checkCode(userCode))
    {
        cout<<"1:Check Balance"<<endl;
        cout<<"2:Withdraw"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1: a.showBal();
                    break;

            case 2: cout<<"Enter the amount to withdraw"<<endl;
                    cin>>amt;
                    a.withdraw(amt);
                    break;

            default:cout<<"Invalid choice"<<endl;
        }
    }
    else
    {
        cout<<"Incorrect Code!!"<<endl;
    }

    return 0;
}
