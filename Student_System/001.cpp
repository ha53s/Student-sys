/*
Hams Almansori   
Ghada Alghamdi   
Maryam Alothman  
Madhawi Aloneizi         

 */

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <time.h>
#include <windows.h>
using namespace std;


//Global variables 
const int limit = 100;
int NumOfRec=10;
string Data="Data.txt";
string Report="Statical_Report.txt";
int counter[6] ={0}; // counters for statical file 

//STUDENT INFORMATION STRUCTURES
struct Major_Info
{
        int Level;
        string Major;
        string Degree;
};


struct Student_Info 
{
   string Student_name;
   int Student_ID;
   double GPA;
   Major_Info Collage; 
   };


//FUNCTIONS PROTOTYPE      
void menu();
void add(Student_Info Students[]) ;
int  search( int &exist, Student_Info Students[]);
void update (Student_Info Students[]);
void delete1(Student_Info Students[]);
void sort (Student_Info Students[]);
void display(Student_Info Students[] , int num , int NumOfRec) ;
void display();
void loadData ( Student_Info Students[]) ;
void DatatoFile( Student_Info Students[]);
void statical_report ();



//MAIN BODY
int main()
{
system("Color 75"); //system font and background -- for design only
Student_Info Students[limit]; 
loadData  (Students) ;
display(); //overload function
int choice;
display (Students, 0, NumOfRec ) ;
counter[5]--; // we decrement one because we call display function
menu(); // MENU FUNC
cout<<"\n Enter Number Here >>>> ";
cin>> choice;

while (choice!=7)
{
switch(choice)
{
       case 1:add(Students) ;
       break;
       
       case 2: 
	   {
	   	int exist=-1;
	   	search( exist , Students);
      	if(exist>-1)
         {   display (Students, exist , exist+1) ;
counter[5]--; // we decrement one because we call display function
}
        else
            cout<<"\n ERROR! The Student Was Not Found :("; 	   
	   }
       break;
       
       case 3: {  update (Students); }

       break;
       
       case 4: delete1(Students);
       break;
       
       case 5: sort (Students);
       break;
       case 6: display (Students, 0 , NumOfRec) ;
       break;
       
       default:
         cout<<"\n ERROR! Make Sure The Number Is Correct :( ";
   }
 cout<<endl<<endl;
 menu(); // MENU FUNC
 cout<<"\n Enter Number Here >>>> ";
 cin>> choice;
   }
DatatoFile(Students) ; 
statical_report ();
return 0;}


//FUNCTIONS BODY  


void menu()
{
Sleep(500); //system pause
cout<<"Choose from the following services by entering the number: "<<endl;
cout<<".........................................................."<<endl;
cout<<">> Add a new student. (1) "<<endl;
cout<<">> Search for a student. (2)"<<endl;
cout<<">> Update a students info. (3)"<<endl;
cout<<">> Delete a student. (4)"<<endl;
cout<<">> Sort students. (5)"<<endl;
cout<<">> Display students. (6)"<<endl;
cout<<">> Exit (7)"<<endl;
}

void add(Student_Info Students[]) 
{counter[0]++;//add_counter 
if(NumOfRec<limit)
{
cout<<">> Enter Student Name is: ";
cin>>Students[NumOfRec].Student_name;
cout<<">> Enter Student  ID: ";
cin>>Students[NumOfRec].Student_ID;
cout<<">> Enter student GPA: ";
cin>>Students[NumOfRec].GPA;
cout<<">> Enter student level : ";
cin>>Students[NumOfRec].Collage.Level;
cout<<">> Enter student major: ";
cin>>Students[NumOfRec].Collage.Major;
cout<<">> Enter student Degree: ";
cin>>Students[NumOfRec].Collage.Degree;
NumOfRec++;
DatatoFile(Students) ; }

else
cout<<"\n Records Are Full :(."<<endl;

}


int search( int &exist , Student_Info Students[])
{counter[1]++;//search_counter
    int ID;
    cout<<">> Enter The Student's ID:";
    cin>>ID;
    for(int i=0 ; i<NumOfRec ;i++)
        if(Students[i].Student_ID==ID){
        	exist=i; }
return (exist);
}


void update ( Student_Info Students[])
{ counter[2]++;//update_counter
    
    int updateID, updateGpa, upadteLevel;
    string updatename, updateMajor, updateDegree;
 
    int found=-1;
    search (found, Students);
    counter[1]--; // we decrement one because we call Search function
    if(found>-1){
            
            cout<<">> Enter the Student Name is: ";
            cin>> updatename;
            Students[found].Student_name = updatename;
            
            cout<<">> Enter the Student ID: ";
            cin>> updateID;
            Students[found].Student_ID= updateID;
            
            cout<<">> Enter the Student GPA: ";
            cin>> updateGpa;
            Students[found].GPA= updateGpa;
            
            cout<<">> Enter the Student collage level: ";
            cin>> upadteLevel;
            Students[found].Collage.Level=upadteLevel;
           
            cout<<">> Enter the Student collage major: ";
            cin>>updateMajor;
            Students[found].Collage.Major=updateMajor;
           
            cout<<">> Enter the Student collage Degree ";
            cin>>updateDegree;
            Students[found].Collage.Degree=updateDegree ;
        
          cout<<"\n\t\t\t Updated Succesfully :)."<<endl; 
		  DatatoFile(Students) ;  }
    else
        cout<<"\n Student Was Not Found :(."<<endl;
}
 
    
void delete1(Student_Info Students[])
{
counter[3]++;//delete_counter
int deleted;
bool found=0; 
cout<<">> Enter ID of Student To Delete: ";
		cin>> deleted;

			    for(int i=0 ; i<NumOfRec;i++)
			    {
        if(Students[i].Student_ID==deleted)
			{found=1;
				Students[i].Student_name=Students[i+1].Student_name;
  				Students[i].Student_ID=Students[i+1].Student_ID;
				Students[i].GPA=Students[i+1].GPA;
				Students[i].Collage.Level=Students[i+1].Collage.Level;
				Students[i].Collage.Major=Students[i+1].Collage.Major;
				Students[i].Collage.Degree=Students[i+1].Collage.Degree;
				NumOfRec--;	
				cout<<"\n Deleted Successfully :). "<<endl;	
			}}	
			if (!found)
			cout<<"\n Student Was Not Found :(."<<endl;
			else
			DatatoFile(Students) ; 

}


void sort (Student_Info Students[]) 
{counter[4]++;//sort_counter
Student_Info temp;
	if(NumOfRec<2)
    	cout<<"\n Nothing To Sort.";
	else {
	
    	for(int i=0; i<NumOfRec-1;i++){
        	for(int j=0; j<NumOfRec-1;j++){
            	if (Students[j].Student_ID>Students[j+1].Student_ID){
                	temp=Students[j];
                	Students[j]=Students[j+1];
                	Students[j+1]=temp;
            	}
        	}}
    DatatoFile(Students) ;	}

	 

}


void display(){
	cout<<"\n\n\t\t\t~~~~~~ Welcome to the Student Services System ~~~~~~\t\t\t\n\n"<<endl;
	Sleep(2000);//system pause
	cout<<"\t\t\t We wish you a pleasant experiance! \3 \t\t\t\n"<<endl;
	Sleep(2000);//system pause
	cout<<"\t\t\t Please don't forget to exit the program so everything is saved correctly. \t\t\t\n"<<endl;
    Sleep(2000);//system pause
}

void display ( Student_Info Students[], int  num , int NumOfRec)
{
counter[5]++;//display_counter
cout<<endl<<"List Of Students"<<endl; 
cout<<"============================================================"<<endl;
for(int i=num ; i<NumOfRec ;i++)
{
cout<<">> Student Name: "<<Students[i].Student_name<<endl;
Sleep(100);
cout<<">> Student ID: "<<Students[i].Student_ID<<endl;
Sleep(100);
cout<<">> Student GPA: "<<Students[i].GPA<<endl;
Sleep(100);
cout<<">> Student Collage Level: "<<Students[i].Collage.Level<<endl;
Sleep(100);
cout<<">> Student Collage Major: "<<Students[i].Collage.Major<<endl;
Sleep(100);
cout<<">> Student Collage Degree: "<<Students[i].Collage.Degree<<endl;
Sleep(100);
cout<<"-----------------------------------------------------------"<<endl;
}
cout<<"==========================================================="<<endl<<endl<<endl;
}


void loadData ( Student_Info Students[])
{
ifstream DataFile;
DataFile.open(Data.c_str(), ios::in);
if(DataFile.is_open() == true || DataFile.is_open())
{
  int i=0;
        while(!DataFile.eof()) {
            getline(DataFile, Students[i].Student_name);
            DataFile>>Students[i].Student_ID;
            DataFile>>Students[i].GPA;
            DataFile>>Students[i].Collage.Level;
            DataFile.ignore();
            getline(DataFile, Students[i].Collage.Major);
            getline(DataFile, Students[i].Collage.Degree);
            i++;}
        NumOfRec =i-1;
       DataFile.close();
	   }
else 
cout<< "\n ERROR! Load Uncompleted :(.\n";
 }


void  DatatoFile (Student_Info Students[])
{ofstream DataFile;
DataFile.open(Data.c_str(), ios::out);

if(DataFile.is_open() == true || DataFile.is_open() ) {
for (int i=0;i<NumOfRec;i++){
    DataFile<<Students[i].Student_name<<endl;
    DataFile<<Students[i].Student_ID<<endl;
    DataFile<<Students[i].GPA<<endl;
    DataFile<<Students[i].Collage.Level<<endl;
    DataFile<<Students[i].Collage.Major<<endl;
    DataFile<<Students[i].Collage.Degree<<endl;
}
DataFile.close();
cout << "\n Data Saved Successfully :).\n";}
else 
cout<< "\n ERROR! Save was Uncompleted :(.\n";
}



 void statical_report ()
{
ofstream ReportFile; 	
time_t t;	
t= time(NULL);
char *time=ctime(&t);
ReportFile.open(Report.c_str(), ios::app);
if (ReportFile.is_open() == true)
{   ReportFile<<endl;
	ReportFile<<"The user ask to display data: "<<counter[5]<<" times"<<endl;
	ReportFile<<"The user ask to sort data: "<<counter[4] <<" times"<<endl;
	ReportFile<<"The user ask to add data: "<<counter[0]<<" times"<<endl;
	ReportFile<<"The user ask to add Update data: "<<counter[2]<<" times"<<endl;
	ReportFile<<"The user ask to delete data: "<<counter[3]<<" times"<<endl;
	ReportFile<<"The user ask to search data: "<<counter[1] <<" times"<<endl;
	ReportFile<<"The Date of Last update: "<<time<<endl;
}
else
cout<< "\n ERROR! Failed to Save Last Modifications :(.\n";
ReportFile.close();
}



