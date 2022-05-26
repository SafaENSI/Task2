// ********Second working day - Task 2*********** //
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


// CheckPSWD function returns true if there is a valid paswword else false*
// it retuns also the counter of the valid password in the first and second interpretation
bool CheckPSWD(string str,int& count_1,int& count_2)
{
    //Split the giving str string with format : min-max char: password
    bool ret= false;
    int start =0;
    int tt= str.find(" ");
    int tt1= str.find("-");
    int tt2= str.find(":");
    //convert the string str variable to have an int value
    int min=  stoi(str.substr(start,start-tt1)) ;
    //cout << min << " = min  et "  << password[min-1]<< endl;
    int max = stoi(str.substr(tt1+1,tt)) ;;
    //cout << max << " = max et "  << password[max-1]<< endl;
    char checkCharacter=  (str.substr(tt+1, 1))[0];
    string password=str.substr(tt2+2) ;
    int count = 0; // count the occuracy of the checkCharacter
    //Find the Frequency of checkCharacter in the String
    for (int i = 0; i < password.size(); i++)
    {
        if (password[i] ==  checkCharacter)
        {
            count++;
        }
    }
// check if the password is valid according to the first policies
    if ( count >= min && count <= max)
    {

        // cout << str << " is a valid password according to the first interpretation of the policies " << endl;
        count_1++;
        ret = true;
    }
    else
    {
        /* Nothing to do */
    }
// check if the password is valid according to the second policies
    if (((password[min-1]== checkCharacter) && (password[max-1]!= checkCharacter))
            ||((password[min-1]!= checkCharacter) && (password[max-1]== checkCharacter)))
    {
        //cout << str << " is a valid password according to the second interpretation of the policies " << endl;
        count_2++;
        ret = true;
    }
    else
    {
        // For debug: cout << str << " is not a valid password according to the second interpretation of the policies " << endl;
        /* nothing to do */
    }
    return ret;

}
int main()
{
    ifstream File;
    File.open("d2.txt");
    std::vector<string> vect_psw;
    string line;

    if(!File) //Always test the file open.
    {
        std::cout<<"Error opening output file"<<std::endl;
        system("pause");
        return -1;
    }

    while (std::getline(File, line))
    {
        vect_psw.push_back(line);
    }
    File.close();

    int count_1 =0; // number of valid password according to the fist implementation
    int count_2 =0; // number of valid password according to the second implementation
    for (int i = 0; i < vect_psw.size(); i++)
    {
        CheckPSWD(vect_psw[i],count_1,count_2);
    }

    cout << "Numbers of valid passwords according to the first interpretation of the policies "<< count_1 << endl;
    cout << "Numbers of valid passwords according to the new interpretation of the policies "<< count_2 << endl;

    return 0;
}
