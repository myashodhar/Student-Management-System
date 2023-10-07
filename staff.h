#include<iostream>
#include<fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>

struct staff
{
 string id;// for staff id
 string fName;//for student first name
 string lName;//for student last name
 string qualification;//for Registration No number
 string mNumber;//for class info
 string pay;//Pay of the Teacher
};


void newStaffRegistration()
{
    fstream outfile ("staffInfo.txt",ios::app);
    staff s1;
    std::cout<<"StaffId:";
    std::cin>>s1.id;
    std::cout<<"FirstName:";
    std::cin>>s1.fName;
    std::cout<<"LastName:";
    std::cin>>s1.lName;
    std::cout<<"Pay:";
    std::cin>>s1.pay;
    std::cout<<"Qualification:";
    std::cin>>s1.qualification;
    std::cout<<"Mobile Number:";
    std::cin>>s1.mNumber;
    outfile<<s1.id<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.pay<<" "<<s1.qualification<<" "<<s1.mNumber<<endl;
    std::cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;
}
void updateStaffInform()
{
    string sId;
    std::cout<<"\n Enter staff Id:\n";
    std::cin>>sId;

    staff s1;
    fstream infile ("staffInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        int i=0;
        int flag=0;
        for(const auto &it : arrayTokens)
        {
            if(i==0 && sId==it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            std::cout<<"FirstName:";
            std::cin>>s1.fName;
            std::cout<<"LastName:";
            std::cin>>s1.lName;
            std::cout<<"Pay:";
            std::cin>>s1.pay;
            std::cout<<"Qualification:";
            std::cin>>s1.qualification;
            std::cout<<"Mobile Number:";
            std::cin>>s1.mNumber;
            tempfile<<sId<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.pay<<" "<<s1.qualification<<" "<<s1.mNumber<<endl;
            std::cout<<"\n**Successfully updated**\n";

        }
        else
        {

            tempfile<<line<<endl;
        }
    }
    infile.close();
    tempfile.close();
    remove("staffInfo.txt");
    rename("tempInfo.txt","staffInfo.txt");

}
void deleteStaffInform()
{
        string sId;
    std::cout<<"\n Enter staff Id:\n";
    std::cin>>sId;

    staff s1;
    fstream infile ("staffInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        int i=0;
        int flag=0;
        for(const auto &it : arrayTokens)
        {
            if(i==0 && sId==it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            tempfile<<line<<endl;
        }
        else
        {
            std::cout<<"\n\n ** deleted successfully**\n";

        }
    }
    infile.close();
    tempfile.close();
    remove("staffInfo.txt");
    rename("tempInfo.txt","staffInfo.txt");

}

void listOfStaffs()
{

    fstream file ("staffInfo.txt");
    staff s1;
    std::cout<<endl<<"\t\t\t\t !** STAFF LIST **!\t\t\n\n\n";
    std::format("{:15}S.ID{:15}F.NAME{:15}L.NAME{:15}PAY{:15}QUALIFICATION{:15}M.NUMBER\n\n");
    
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        for(const auto &it : arrayTokens)
        {
            std::format("{:15}{0}", it);
            
        }
        std::cout<<endl;
    }
        std::cout<<endl;

}
