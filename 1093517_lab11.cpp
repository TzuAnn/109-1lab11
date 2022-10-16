#include<iostream>
#include<fstream>
#include<ctime>
#include <string>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std ;
string firstname ;
string lastname ;
double actbalance ;
int n = 0 ;
void displayFile()
{
string str1;
string str2;
string fileN = "clientFile.txt";
ifstream fptr;
fptr.open(fileN);
double balance;
int numAct = 0;
time_t transTime;
if ( !fptr ) {
cerr << "File could not be opened" << endl;
exit( 1 );
}
while(fptr >> str1 >> str2 >> balance >> transTime) 
{
    

    cout << setw(15) << str1 << ' ' << setw(15) << str2 << ' '
    << setw(7) << balance << " " << ctime(&transTime);
    numAct++;
}
cout << "Number of records in the file " << fileN << ": " << numAct << endl;
}
void createRecord(ofstream &fptr, string firstN, string lastN, double actBal)
{
    time_t currentTime;
    time (&currentTime);
    while ( cin >> firstname >> lastname >> actbalance ) 
    {
        fptr << firstname <<' '<< lastname <<' '<< actbalance <<' '<< currentTime << endl;
    }
        

    
}
void removeDuplicateRecords(fstream &fptr, const string fileN)
{
    time_t currentTime ;
    int counter = 0 ;
    string first[1000] ;   
    string last[1000] ;
    int balance[1000] ;
    time_t current[1000] ;
    vector <int> key ;
    while ( fptr >> firstname >> lastname >> actbalance >> currentTime )
    {
        
        first[counter] = firstname ;
        last[counter] = lastname ;
        balance[counter] = actbalance ;
        current[counter] = currentTime ;
        counter++ ; 
    }
    for ( int i = 0 ; i < counter ; i++ )
    {
        for ( int n = i+1 ; n < counter ; n++ )
        {
            if ( first[i] == first[n] && last[i] == last[n] )
            {
                key.push_back(i);
                
            }
        }
        
    }
    fptr.close();
    ofstream ofptr("clientFile.txt",ios::out);
    for ( int j = 0 ; j < counter ; j++ )
    {
        bool skip = false;
        for ( int i = 0 ; i < key.size() ; i++ )
        {
            if ( j == key[i] )
            {
                skip=true;
                break ;
            }
        }
        if(skip == true )
        {
            continue ;
        }
        else 
        {
            ofptr << first[j] << ' ' << last[j] << ' ' << balance[j] <<' '<< current[j] << endl ;
        }
    }
    

}
int main()
{
    ofstream outClientFile ;
    ifstream inClientFile( "clientFile.txt" ) ;
    if ( !inClientFile )
    {
        outClientFile.open( "clientFile.txt" ) ;
        cout << "Creating a new file:  " << endl ;
    }
    else 
    {
        outClientFile.open( "clientFile.txt", ios::app ) ;
        cout << "Existing file content: " << endl ;
        displayFile() ;
    }
    cout << "enter the first name, last name and balance" << endl << "enter end-of-file to end input.\n? " ;
    int account ;
    fstream clientFile( "clientFile.txt" ) ;
    string fileN1 = "clientFile.txt" ;
        createRecord(outClientFile,firstname,lastname,actbalance ) ;
        removeDuplicateRecords (clientFile, fileN1) ;
        displayFile();
    outClientFile.close() ;
}