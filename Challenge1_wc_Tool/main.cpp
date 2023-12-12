#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int countWords(const string& filePath)
{
    ifstream myFile(filePath);
    string myString;
    int count=0;
    if(myFile.is_open()){
        while(myFile.good()){
            myFile>>myString;
            count++;
        }
    }
    return count;
}

int countLines(const string& filePath)
{
    ifstream myFile(filePath);
    string myLine;
    int count=0;
    if(myFile.is_open()){
        while(myFile){
            getline(myFile,myLine);
            count++;
        }
    }

    return count-1;

}

int countBytes(const string& filePath){
    ifstream myFile(filePath,ios::binary);
    myFile.seekg(0,ios::end);
    return myFile.tellg();
}

int countCharacters(const string& filePath)
{
    ifstream myFile(filePath);
    char c;
    int count=0;
    if(myFile.is_open()){
        while(myFile.get(c)){
            count++;
        }
    }

    return count;
}



void wcToolProgram(int argc, char const *argv[])
{
    if(argc>2){
    
    string filePath=argv[argc-1];
    ifstream myFile(filePath);

    for (size_t i = 1; i < argc-1; i++)
    {
        string s=argv[i];
        switch (s[1])
        {
        case 'c':
            cout << countBytes(filePath) << " ";
            break;
        case 'w':
            cout << countWords(filePath) << " ";
            break;
        case 'l':
            cout << countLines(filePath) << " ";
            break;
        case 'm':
            cout << countCharacters(filePath) << " ";
            break;
        default:
            cout<<"INVALID ARGUMENTS"<<" ";
        }
    }
    cout<<filePath<<endl;

}else if(argc==2){
    string filePath = argv[argc - 1];
    ifstream myFile(filePath);
    cout << countBytes(filePath) <<" "<<countWords(filePath)<<" "<<countLines(filePath)<<" "<<countCharacters(filePath)<<" "<<filePath<<endl;
}else{
    cout<<"Please provide File Path"<<endl;
}
}

int main(int argc, char const *argv[])
{
    wcToolProgram(argc,argv);
    return 0;
}
