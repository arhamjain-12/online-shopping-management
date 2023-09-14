#include<iostream>
#include<fstream>
using namespace std;

string z[]={"Plain shirt","Printed shirt","Check shirt"};
int z1[]={450, 650,500};
string y[]={"Round neck T-shirt","Polo T-shirt","Hooded T-shirt"};
int y1[]={550, 800,400};
string x[]={"Jeans","Trousers","Chinos"};
int x1[]={1000, 700,1500};
string u[]={"Shirt","T-shirt","Pants"};
int Total=0;
int size1,b;
int l=0;
char p=true;

class customer_details{
	public:
		string name,contact_no,age,gender;
		void add_customer_details(){
			cout<<"\nEnter the name of customer: ";
			cin>>name;
			cout<<"Enter the contact number of "<<name<<": ";
			cin>>contact_no;
			cout<<"Enter the age of "<<name<<": ";
			cin>>age;
			ofstream fout("d:/03-09.txt");
			fout<<"\nName: "<<name<<"\nContant number: "<<contact_no<<"\nAge: "<<age;
			fout.close();
		}
		void get_customer_details(){
			cout<<"\nName of customer: "<<name<<"\ncontact number of "<<name<<": "<<contact_no<<"\nAge of "<<name<<": "<<age<<"Gender: "<<gender;
		}
};
class shirts:public customer_details{
	public:
		void buy_shirts(){
			size1=sizeof(z)/sizeof(z[0]);
			for(int i=0;i<size1;i++){
				cout<<"\n"<<i+1<<"."<<z[i]<<"\nPrice of Shirts: "<<z1[i]<<"\n";
			}
			cout<<"\n"<<"\nWhich Shirt you want to buy(enter serial number): ";
			cin>>b;
			if(b<size1){
				Total=Total+z1[b-1];
				ofstream fout("d:/03-09.txt",ios_base::app);
				fout<<"\n"<<z[b-1]<<"\t"<<z1[b-1];
				fout.close();
			}
			else{
				cout<<"\nInvalid input\n";
			}
		}
};

class t_shirt:public shirts{
	public:
		void buy_t_shirts(){
			size1=sizeof(y)/sizeof(y[0]);
			for(int i=0;i<size1;i++){
				cout<<"\n"<<i+1<<"."<<y[i]<<"\nPrice of the T-shirt: "<<y1[i]<<"\n";
			}
			cout<<"\n"<<"\nWhich T-shirt you want to buy(enter serial number): ";
			cin>>b;
			if(b<size1){
				Total=Total+y1[b-1];
				ofstream fout("d:/03-09.txt",ios_base::app);
				fout<<"\n"<<y[b-1]<<"\t"<<y1[b-1];
				fout.close();
			}
			else{
				cout<<"\nInvalid input\n";
			}
		}	
};

class pants:public t_shirt{
	public:
		void buy_pants(){
			size1=sizeof(x)/sizeof(x[0]);
			for(int i=0;i<size1;i++){
				cout<<"\n"<<i+1<<"."<<x[i]<<"\nPrice of the Pants: "<<x1[i]<<"\n";
			}
			cout<<"\n"<<"\nWhich pants you want to buy(enter serial number): ";
			cin>>b;
			if(b<size1){
				Total=Total+x1[b-1];
				ofstream fout("d:/03-09.txt",ios_base::app);
				fout<<"\n"<<x[b-1]<<"\t"<<x1[b-1];
				fout.close();
			}
			else{
				cout<<"\nInvalid input\n";
			}
		}
};
class all:public pants{
	public:
		string t;
		string a;
		void get_all(){
			while(p==true){
				
				int size=sizeof(u)/sizeof(u[0]);
				for (int j=0;j<size;j++){
					cout<<"\n"<<j+1<<"."<<u[j];
				}
				cout<<"\n4.Exit and get Total bill"<<"\n";
				cout<<"\nWhich type of cloth you want to buy: ";
				cin>>a;
				if (a=="1"){
					buy_shirts();
				}
				else if(a=="2"){
					buy_t_shirts();
				}
				else if (a=="3"){
					buy_pants();
				}
				else if (a=="4"){
					for (int i=0;i<26;i++){
						cout<<"*";
					}
					cout<<" Details  ";
					for (int i=0;i<26;i++){
						cout<<"*";
					}
					ofstream fout("d:/03-09.txt",ios_base::app);
					fout<<"\n"<<"Total amount to be paid: "<<"\t"<<Total;
					fout.close();
					p=false;
					}
				else{
					cout<<"Invalid input";
				}
				
				}
			}
		
};

int main(){
	for (int i=0;i<26;i++){
		cout<<"*";
	}
	cout<<" Cloth Shop ";
	for (int i=0;i<26;i++){
		cout<<"*";
	}
	cout<<"\n";
	all r;
	r.add_customer_details();
	r.get_all();
	
	

	ifstream inputFile("d:/03-09.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open the file." << endl;
    }
    string fileContent((istreambuf_iterator<char>(inputFile)),(istreambuf_iterator<char>()));
    inputFile.close();
    cout << fileContent <<endl;
    return 0;
}