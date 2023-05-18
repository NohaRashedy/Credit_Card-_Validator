#include <iostream>
#include <regex>
#include<ctime>
#include<iomanip>
#include<sstream>
#include<string>

using namespace std;
bool checkExpirationDate(int expMonth, int expYear);
bool numberVailation(string name , string number);
bool checkdateformat(string &ExpDate , int &Expmonth , int &Expyear);
bool typeValidation(string type);


int main()
{
     char repeat;

    cout<<setw(70)<<"Validate your credit card";
    do{
    string number ,name , ExpDate , Syear , Smonth;
    bool flag1=1, flag2=1 , flag3=1;
    int year , month;
    cout<<endl<<endl<<endl;
    cout<<"The program validate the following Cards"<<endl<<setw(18)<<"VIZA"<<endl<<setw(19)<<"Meeza"<<endl<<setw(24)<<"Mastercard"<<endl<<setw(30)<<"American Express"<<endl<<endl;
    cout <<"Enter your Visa type"<< endl;
    getline(cin,name);
    //this block to validate the type is exist
    while(flag2){
    if(typeValidation(name)){
        flag2=0;
    }
    else{
        flag2 =1 ;
         cout<<"Please enter the type from the list, Don't miss the spelling "<<endl;
                getline(cin,name);
    }
    }

    cout <<"Enter your Visa Number"<< endl;
    cin>>number;
    //this block to validate that there is 16 digits entered
    while(flag1){
        if (number.size()==16){
            flag1 = 0;
        }
        else{
            flag1 =1;
            cout<<"Please enter 16 digits"<<endl;
            cin>>number;
        }
    }
    // this block to ensure it's a well-built Expiration  date
    cout <<"Enter the expiration date with the format MM / YY"<< endl;
    cin>>ExpDate;
    month=stoi(ExpDate.substr(0,2));
    year=stoi(ExpDate.substr(3,2));
    while(flag3){
    if(checkdateformat(ExpDate , month , year)==0){
        cout<<"The entered format is wrong, please enter it with the Formate MM/YY , don't miss the / :D"<<endl;
        cin>>ExpDate;
        flag3 = 1;
    }
    else
        flag3 =0;
    }

if(numberVailation(name , number)&& checkExpirationDate(month,year)){
    cout<<"it's a Valid credit card";
    }
else
{
    if(!checkExpirationDate(month,year))
        cout<<"It's expired"<<endl;
    else
        cout<<"You have entered a wrong number please remember the start of available types "<<endl<<"50 for Meeza"<<endl<<"5[1:5] for Mactercard"<<endl<<"4[0:9] for VIZA"<<endl<<"3[0:9] for American Express"<<endl;

}
cout<<"Do you want to repeat the process? enter y/n"<<endl;
    cin>>repeat;
    }
    while(repeat=='y');


    return 0;
}


bool checkExpirationDate(int expMonth, int expYear) {
    time_t now = time(0);
    tm* currentDate = localtime(&now);
    int currentMonth = currentDate->tm_mon + 1;
    int currentYear = currentDate->tm_year %100;
    return (expYear > currentYear || (expYear == currentYear && expMonth >= currentMonth));
}

bool checkdateformat(string &ExpDate , int &Expmonth , int &Expyear){
if(ExpDate.size()!=5 ||  ExpDate[2]!='/')
    return 0;
if(Expmonth<1 || Expmonth > 12)
    return 0;

}


bool numberVailation(string name , string number)
{
    if(name=="Mastercard"){
 regex pattern("^5[1-5][0-9]{14}$");
 if(regex_match(number, pattern)==1)
    return 1;
    else
    return 0;
 }
 else if(name=="Meeza"){
 regex pattern("^5[0][0-9]{14}$");
 if(regex_match(number, pattern)==1)
    return 1;
 else
    return 0;
 }
else  if(name=="VIZA"){
 regex pattern("^4[0-9]{15}$");
 if(regex_match(number, pattern)==1)
    return 1;
 else
    return 0;

 }
 else if(name=="American Express"){
 regex pattern("^3[0-9]{15}$");
 if(regex_match(number, pattern)==1)
    return 1;
 else
    return 0;

}
}
bool typeValidation(string type){
    bool res;
string NamesList[4]={"VIZA","Meeza" ,"Mastercard","American Express"};
for(int k =0 ; k< 4; k++){
    if(type == NamesList[k]){
        res = 1;
        break;
}
else
    res = 0;
    continue;
}
return res;
}


