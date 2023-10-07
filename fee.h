
#include <iostream>
#include <fstream>
#include <format>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>
#include <algorithm>


void _updateFee_helper(){

}

struct fee
{
 string classes;//for classNo number
 string year;//for kannada
 float tuitionFee;//for english
 float sportsFee;//for science
 float uniformFee;//for maths
 float total;//for sStudy
};

void addFee()
{
    fee s1;
    fstream outfile ("feeInfo.txt",ios::app);
    std::cout<<"Class(Standard):";
    std::cin>>s1.classes;
    std::cout<<"Year:";
    std::cin>>s1.year;
    std::cout<<"SportsFee:";
    std::cin>>s1.sportsFee;
    std::cout<<"TuitionFee:";
    std::cin>>s1.tuitionFee;
    std::cout<<"UniformFee:";
    std::cin>>s1.uniformFee;
    s1.total=s1.sportsFee+s1.tuitionFee+s1.uniformFee;
    outfile<<s1.classes<<" "<<s1.year<<" "<<s1.sportsFee<<" "<<s1.tuitionFee<<" "<<s1.uniformFee<<" "<<s1.total<<endl;
    std::cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;
}

void updateFee()
{
    string classes;
    string year;
    std::cout<<"\n Enter class(STANDARD):\n";
    std::cin>>classes;

    std::cout<<"\n Enter Year:\n";
    std::cin>>year;

    fee s1;
    fstream infile ("feeInfo.txt");
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
        for(int it = 0; it < arrayTokens.size(); it++)
        {
            if(i==0 && classes==arrayTokens[it])
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            std::cout<<"SportsFee:";
            std::cin>>s1.sportsFee;
            std::cout<<"TuitionFee:";
            std::cin>>s1.tuitionFee;
            std::cout<<"UniformFee:";
            std::cin>>s1.uniformFee;
            s1.total=s1.sportsFee+s1.tuitionFee+s1.uniformFee;
            tempfile<<classes<<" "<<year<<" "<<s1.sportsFee<<" "<<s1.tuitionFee<<" "<<s1.uniformFee<<" "<<s1.total<<endl;
            std::cout<<"\n**Successfully updated**\n";

        }
        else
        {
                tempfile<<line<<endl;
        }

    }
    infile.close();
    tempfile.close();
    remove("feeInfo.txt");
    rename("tempInfo.txt","feeInfo.txt");

}

void listAllFees()
{
    ifstream file("feeInfo.txt");
    string content;
    std::cout<<endl<<"\t\t\t\t !** FEES LIST **!\t\t\n\n\n";
    std::cout << setw(15) <<"CLASS" << setw(15) << "YEAR" << setw(15) << "S.FEE" <<setw(15) <<"T.FEE"<<setw(15)<<"U.FEE"<<setw(15)<<"TOTAL"<<endl<<endl;
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        for(int it = 0; it < arrayTokens.size(); it++)
        {

                std::format("{:15}{0}", arrayTokens[it]);// prints d.

        }
        std::cout << '\n';

    }


}

void deleteFee()
{
    string classes;
    string year;
    std::cout<<"\n Enter class(STANDARD):\n";
    std::cin>>classes;

    fee s1;
    fstream infile ("feeInfo.txt");
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
        for(int it = 0; it < arrayTokens.size(); it++)
        {
            if(i==0 && classes==arrayTokens[it])
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
        else{
            std::cout<<"** successfully Deleted **\n";
        }


    }

    infile.close();
    tempfile.close();
    remove("feeInfo.txt");
    rename("tempInfo.txt","feeInfo.txt");
}
