#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void GeneratePassword(int len);
int randomNum(int range);
void help(void);
string checkNumver(string x);


int main(int argc, char *argv[]){

     if(argc > 2)
     {
          cout<<"Error in command line input.Too many arguments given.\nUse '-h or --help' for help note"<<endl;
          return 1;
     }
     else if(argc == 2)
     {

        if(strcmp(argv[1], "-h") == 0){
           help();
         }
         else if(strcmp(argv[1], "--help") == 0){
            help();
         }
         else
         {
              string len = argv[1];
              if(checkNumver(len)=="true")//check agument is number or not
              {
                  int num =atoi(len.c_str()); //convert string to number
                   if(num<6)
                    {
                    cout<<"Password lenght should be greater than 6.";
                    }
                    else
                    {
                        GeneratePassword(num); //generate password
                    }

              }
              else
              {
                   cout<<"Error: Argument should be number!!"<<endl;
               }


         }

     }
     else{

        cout<<"Error in command line input.\nToo few arguments given.\nUse '-h or --help' for help note"<<endl;
     }



    return 0;
}
//random number generate function
int randomNum(int range){

    return ( rand() % range );
}

//secure password generate function
void GeneratePassword(int len)
{

    string theLetters = "abcdefghijklmnopqrstuvwxyz";
    string theSymbols = "?+-*/;:{]}[~!@#$%^&()";
	string StrongPasswordArray ="";

	int capitalise,i;
	srand (time(NULL));
	for ( i = 0; i < len; i++) {
		capitalise = randomNum(6);
		if (capitalise == 0) {
			StrongPasswordArray += toupper(theLetters[randomNum(26)]);
		}
		else {
			StrongPasswordArray += theLetters[randomNum(26)];
		}
	}
	// adding symbols in password
	int numberOfSym = randomNum(5);
	int positionForSym, theSym;
	for (i = 0; i < numberOfSym; i++) {
		positionForSym = randomNum(26);
		theSym = randomNum(21);
		 StrongPasswordArray[positionForSym] = theSymbols[theSym];
	}
   	//adding numbers in password
	int numberOfDigits = randomNum(5) +1;
	int positionForNumeric, theNumber;
	for (i = 0; i < numberOfDigits; i++) {
		positionForNumeric = randomNum(26);
		theNumber = randomNum(9);
        theNumber +=48;
		 StrongPasswordArray[positionForNumeric] = (char)theNumber;
	}
    cout<<StrongPasswordArray<<endl;



}

void help(void) //information
{
     cout<<"|===============================================|"<<endl;
     cout<<"|           Help Note Of S_EDcrypt              |"<<endl;
     cout<<"|===============================================|"<<endl;
     cout<<" This 'SecPass' is a Easy Secure Password generating program."<<endl;
     cout<<"++++++++++++++++++"<<endl;
     cout<<"Usage:"<<endl;
     cout<<"--------------"<<endl;
     cout<<"./secPass <length>" <<endl;
     cout<<"+++++++++++++++++++++700+++++++++++++++++++++++++++"<<endl;
     cout<<"Product Info:"<<endl;
     cout<<"--------------"<<endl;
     cout<<"Name: secPass"<<endl;
     cout<<"Version:1.13.11"<<endl;
     cout<<"Source Codes: https://github.com/hrshadhin/seccurePassword"<<endl;
     cout<<"--------------------------------"<<endl;

     cout<<"This Program is made by H.R.Shadhin :#$"<<endl;
     cout<<"Email: hrshadhin.i386@gmail.com"<<endl;
     cout<<"Social Media: t@hrshadhin <> g@HabiburRahmanShadhin"<<endl;
     cout<<"++++++++++++++++++++++++0++++++++++++++++++++++++++++++"<<endl;


}
//numver checking function
string checkNumver(string x){
    int len = x.size(),i;
    string rs ="";
    for(i=0;i<len;i++){
        if(isdigit(x[i])){
            rs="true";
        }
        else
        {
             return rs="false";
        }
    }
    return rs;
}
