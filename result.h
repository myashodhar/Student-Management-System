#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>

struct result
{
 string rId;//for Registration No number
 string classes;//for classNo number
 string kannada;//for kannada
 string english;//for english
 string science;//for science
 string maths;//for maths
 string sStudy;//for sStudy
};


void newResultAdd()
{
    fstream outfile ("resultInfo.txt",ios::app);
    result s1;
    std::cout<<"Registration Id:";
    std::cin>>s1.rId;
    std::cout<<"Class:";
    std::cin>>s1.classes;
    std::cout<<"Kannada:";
    std::cin>>s1.kannada;
    std::cout<<"English:";
    std::cin>>s1.english;
    std::cout<<"Maths:";
    std::cin>>s1.maths;
    std::cout<<"science:";
    std::cin>>s1.science;
    std::cout<<"s.study:";
    std::cin>>s1.sStudy;
    outfile<<s1.rId<<" "<<s1.classes<<" "<<s1.kannada<<" "<<s1.english<<" "<<s1.maths<<" "<<s1.science<<" "<<s1.sStudy<<endl;
    std::cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;

}
void updateResultAdd()
{
    string rId;
    string classes;
    std::cout<<"\n Enter student registration Id:\n";
    std::cin>>rId;
    std::cout<<"\n Enter student Class:\n";
    std::cin>>classes;

    result s1;
    fstream infile ("resultInfo.txt");
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
            std::cout<<"Kannada:";
            std::cin>>s1.kannada;
            std::cout<<"English:";
            std::cin>>s1.english;
            std::cout<<"Maths:";
            std::cin>>s1.maths;
            std::cout<<"science:";
            std::cin>>s1.science;
            std::cout<<"s.study:";
            std::cin>>s1.sStudy;
            tempfile<<rId<<" "<<classes<<" "<<s1.kannada<<" "<<s1.english<<" "<<s1.maths<<" "<<s1.science<<" "<<s1.sStudy<<endl;
            std::cout<<"\n**Successfully updated**\n";

        }
        else
        {
            tempfile<<line<<endl;

        }
    }
    infile.close();
    tempfile.close();
    remove("resultInfo.txt");
    rename("tempInfo.txt","resultInfo.txt");


}
void deleteResult()
{

    string rId;
    string classes;
    std::cout<<"\n Enter student registration Id:\n";
    std::cin>>rId;
    std::cout<<"\n Enter student Class:\n";
    std::cin>>classes;

    result s1;
    fstream infile ("resultInfo.txt");
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
            std::cout<<"\n\n ** deleted successfully**\n\n";
        }
    }
    infile.close();
    tempfile.close();
    remove("resultInfo.txt");
    rename("tempInfo.txt","resultInfo.txt");
}

void overAllClassResult()
{
    string classes;
    std::cout<<"Enter the class:";
    std::cin>>classes;

    int failCount=0;
    int passCount=0;
    int totalCount=0;

    ifstream file("resultInfo.txt");
    string line;
    int check_fail=0;
    while(std::getline(file, line))
    {
            check_fail=0;
            istringstream ss(line);
            std::istream_iterator<std::string> begin(ss);
            std::istream_iterator<std::string> end;
            //putting all the tokens in the vector
            std::vector<std::string> arrayTokens(begin, end);
            int flag=0;
            int i=0;
            for(const auto &it : arrayTokens)
            {
                string p=it;
                stringstream geek(p);
                // The object has the value 12345 and stream
                // it to the integer x
                int x = 0;
                geek >> x;
                if(flag==1 && x < 35)
                {
                    check_fail=1;
                    failCount++;
                    break;
                } else {
                    continue;
                }
                if(classes==(it) && i==1)
                {
                        flag=1;
                        totalCount++;
                }
                i++;

            }
            if(check_fail==0 && flag==1)
            {
                passCount++;
            }

        }
        std::cout<<endl<<"\t\t\t\t !** CLASS "<<classes<<" RESULT**!\t\t\n\n\n";
        std::cout<<"Total No. of Failed Students:"<<failCount<<endl;
        std::cout<<"Total No. of Passed Students:"<<passCount<<endl;
        std::cout<<"Total No. of Students:"<<totalCount<<endl;
        std::cout<<"School Annual Result(%):"<<(double)(100*passCount)/totalCount<<"%";
        std::cout<<endl;

}

void schoolResult()
{
    int failCount=0;
    int passCount=0;
    int totalCount=0;
    ifstream file("resultInfo.txt");
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        int flag=0;
        int i=0;
        for(const auto &it : arrayTokens)
        {
            string p=it;
            stringstream geek(p);
            // The object has the value 12345 and stream
            // it to the integer x
            int x = 0;
            geek >> x;

            if(x<35 && i>1)
            {
                flag=1;
                failCount++;
                break;
            }
            i++;
        }
        if(flag==0)
        {
            passCount++;

        }
        totalCount++;
    }

    std::cout<<"Total No. of Failed Students:"<<failCount<<endl;
    std::cout<<"Total No. of Passed Students:"<<passCount<<endl;
    std::cout<<"Total No. of Students:"<<totalCount<<endl;
    std::cout<<"School Annual Result(%):"<<(double)(100*passCount)/totalCount<<"%";
    std::cout<<endl;
}

void studentResult()
{
    string rId;
    std::cout<<"\nEnter student Reg.ID:";
    std::cin>>rId;
    ifstream file("resultInfo.txt");
    string line;
    int s_result=1;
    string r1;
    int total=0;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        int flag=0;
        int i=0;
        for(const auto &it : arrayTokens)
        {
             string p=it;
             stringstream geek(p);
             // The object has the value 12345 and stream
             // it to the integer x
            int x = 0;
            geek >> x;
            if(flag==1)
            {
                total+=x;
            }
            if(x<35 && flag == 1)
            {
                s_result=0;
                break;
            }
            else
            {
                continue;
            }
            
            if(rId==(it) && i==0)
            {
                flag=1;
                r1=line;
                continue;
            }
            else
                break;

        }
    }
        std::cout<<endl<<"\t\t\t\t !** STUDENT RESULT **!\t\t\n\n\n";
        std::format("{:10}Reg.Id{:10}Class{:10}Kannada{:10}English{:10}Maths{:10}Science{:10}S.study"); 
        std::cout<<endl;
        istringstream ss(r1);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        for(const auto &it :  arrayTokens)
        {
            std::format("{:10}{0}", it);
        }

        if(s_result==0)
        {
            std::cout<<"**Result is Fail**";
        }
        else
        {
            std::cout<<"\n\n\tTotal Score->"<<total<<endl;
            std::cout<<"\tTotal Percentage(%)->"<<((double)total/500)*100<<"%"<<endl;
            std::cout<<"\t**Result is Pass**";
        }
        std::cout<<endl;
}
