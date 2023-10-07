#include<iostream>
#include<fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>

struct student
{
 string rId;//for Registration No number
 string fName;//for student first name
 string lName;//for student last name
 string classes;//for class info
 string mNumber;//for Mobile number
};


void newStudentRegistration()
{
    fstream outfile ("studentInfo.txt",ios::app);
    student s1;
    std::cout<<"Registration Id:";
    std::cin>>s1.rId;
    std::cout<<"FirstName:";
    std::cin>>s1.fName;
    std::cout<<"LastName:";
    std::cin>>s1.lName;
    std::cout<<"Class:";
    std::cin>>s1.classes;
    std::cout<<"Mobile Number:";
    std::cin>>s1.mNumber;
    outfile<<s1.rId<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.classes<<" "<<s1.mNumber<<endl;
    std::cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;
}

void updateStudentInform()
{
    string rId;
    std::cout<<"\n Enter student registration Id:\n";
    std::cin>>rId;

    student s1;
    fstream infile ("studentInfo.txt");
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
            if(i==0 && rId==it)
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
            std::cout<<"Class:";
            std::cin>>s1.classes;
            std::cout<<"Mobile Number:";
            std::cin>>s1.mNumber;
            tempfile<<rId<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.classes<<" "<<s1.mNumber<<endl;
            std::cout<<"\n**Successfully updated**\n";
        }
        else
        {
            tempfile<<line<<endl;
        }
    }
    infile.close();
    tempfile.close();
    remove("studentInfo.txt");
    rename("tempInfo.txt","studentInfo.txt");

}

void deleteStudentInform()
{
    string rId;
    std::cout<<"\n Enter student registration Id:\n";
    std::cin>>rId;

    student s1;
    fstream infile ("studentInfo.txt");
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
            if(i==0 && rId==it)
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
            std::cout<<"\n **Deleted successfully**\n";
        }
    }
    infile.close();
    tempfile.close();
    remove("studentInfo.txt");
    rename("tempInfo.txt","studentInfo.txt");



}


void listOfStudents()
{
    ifstream file("studentInfo.txt");
    string content;
    std::cout<<endl<<"\t\t\t\t !** STUDENT LIST **!\t\t\n\n\n";
    std::format("{:15}REG.ID:{:15}F.NAME{:15}L.NAME{:15}CLASS{:15}M.NUMBER\n\n");
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
        std::cout << '\n';

    }


}
