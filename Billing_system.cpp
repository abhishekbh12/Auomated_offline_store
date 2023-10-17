#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

class Shopping {
    private:
        int prod_id;
        int price;
        float discount;
        string product;

    public:
        void menu();
        void administrator();
        void custumer();
        void add_prod();
        void edit_prod();
        void rem();
        void list_prod(vector<int>& prods);
        void reciept();
        
};

void Shopping::menu() {
    fi:
    int choice;
    string email;
    string password;
	
	cout << "\t1] Administrator\n\n" ;
	cout << "\t2] Customer\n\n" ;
	cout << "\t3] Exit\n\n" ;
	
	cout << "\t Please Enter your login option :\t" ;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout << "\n PLease login \n" ;
		cout << " Enter Email :\t" ;
        cin>>email;
        cout << "\n Enter Password :\t" ;
        cin>>password;
        if (email=="abhi@gmail.com" && password=="abhi@123") {
            administrator();
        }
        else {
            cout << "\n------------------------------------------------------\n" ;
			cout << "\n\t\tInvalid Email or Password\n" ;
            cout << "\n\t\tPlease Enter correct email and password \n" ;
			cout << "\n------------------------------------------------------\n" ;
        }
        break;
    case 2:
        custumer();
        break;
    case 3:
        cout << "\n------------------------------------------------------\n" ;
		cout << "\n\t\tThank You for Shopping at BigBazaar!! - Abhishek\n" ;
        cout << "\n\t\tVisit Again\n" ;
		cout << "\n------------------------------------------------------\n" ;
        exit(0);
    default:
        cout << "\n------------------------------------------------------\n" ;
		cout << "\n	 Invalid Option, please select from the given options \n" ;
		cout << "\n------------------------------------------------------\n" ;
        cout<<"Please select from the given options:\n";
    }
goto fi;
}

void Shopping::administrator() {
    fi:
    int choice;
    cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t	Administrator Menu" ;
	cout << "\n\n ---------------------------------------------------------------\n" ;
	cout << "\n\t1] Add new product" ;
	cout << "\n\t2] Modify the product" ;
	cout << "\n\t3] Delete the product" ;
	cout << "\n\t4] Back to Main Menu" ;
	
	cout << "\n\n Please Enter your choice :\t" ;
    cin>>choice;

    switch (choice) 
    {
    case 1:
        add_prod();
        break;
    case 2:
        edit_prod();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "\n------------------------------------------------------\n" ;
		cout << "\n	 Invalid Choice please select from the given choice	 \n" ;
		cout << "\n------------------------------------------------------\n" ;
        break;
    }
    goto fi;

}

void Shopping::custumer() {
    fi:
    int choice;
    vector<int> prods;
    cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t	Customer Menu" ;
	cout << "\n\n ---------------------------------------------------------------\n" ;
	cout << "\n\t1) Buy product" ;
    cout << "\n\t2) Show Products" ;
	cout << "\n\t3) Go Back" ;
	
	cout << "\n\n Please Enter your choice :\t" ;
    cin>>choice;
    switch (choice)
    {
    case 1:
        reciept();
        break;
    case 2:
        list_prod(prods);
        break;
    case 3:
        menu();
        break;
    default:
        cout << "\n\n\t------------------------------------------------------\n" ;
		cout << "\n\t  Invalid Choice please select from the given choice\n" ;
		cout << "\n\t------------------------------------------------------\n" ;
        break;
    }
    goto fi;
}


void Shopping::add_prod() {
    fi:
    fstream data;
    int c;
    int token=0;
    float p, d;
    string n;
    cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t Add new product" ;
	cout << "\n\n ---------------------------------------------------------------\n" ;
	cout << "\n\t Product code of the product :\t" ;
	cin >> prod_id ;
	cout << "\n\t Name of the product :\t" ;
	cin >> product ;
	cout << "\n\t Price of the product :\t" ;
	cin >> price ;
	cout << "\n\t Discount of the product :\t" ;
	cin >> discount ;

    data.open("database.txt",  ios::in);
    if (!data) {
        data.open("database.txt", ios::app| ios::out);
        data<<" "<<prod_id<<" "<<product<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else {
        data>>c>>n>>p>>d;
        while(!data.eof()) {
            if (c==prod_id) {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if (token==1) {
        cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "Product Already Present\nPlease try again with New Product Code" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
        goto fi;
    }
    else {
        data.open("database.txt", ios::app| ios::out);
        data<<" "<<prod_id<<" "<<product<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t Recorded Inserted" ;
	cout << "\n\n ---------------------------------------------------------------\n\n" ;
}

void Shopping::edit_prod() {
    fstream data, data1;
    int pkey, c;
    int token=0;
    float p;
    float d;
    string n;

    cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t Modify the record" ;
	cout << "\n\n ---------------------------------------------------------------\n\n" ;
	cout << "\t Product code :\t" ;
    cin>>pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\tFile doesn't exist" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
    }
    else {
        data1.open("database1.txt", ios::app | ios::out);
        data>>prod_id>>product>>price>>discount;
        while (!data.eof()) {
            if (pkey==prod_id) {
                cout<<"\n\tEnter the code of new product \t";
                cin>>c;
                cout<<"\n\tEnter name of the product\t";
                cin>>n;
                cout<<"\n\tEnter Price of the product \t";
                cin>>p;
                cout<<"\n\tEnter the discount \t";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout << "\n\n ---------------------------------------------------------------\n\n" ;
                cout<<"\n\tRecord edited \t";
                cout << "\n\n ---------------------------------------------------------------\n\n" ;
                token++;
            }
            else {
                data1<<" "<<prod_id<<" "<<product<<" "<<price<<" "<<discount<<"\n";
            }
            data>>prod_id>>product>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token==0) {
            cout << "\n ---------------------------------------------------------------\n\n" ;
			cout << "\t\t Record Not Found !" ;
			cout << "\n\n ---------------------------------------------------------------\n\n" ;
        }
    }
} 

void Shopping::rem() {
    fstream data, data1;
    int pkey;
    int token=0;
    cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t Delete Product" ;
	cout << "\n\n ---------------------------------------------------------------\n\n" ;
    vector<int> prods;
    list_prod(prods);
    cout << "\tEnter Product code :\t" ;
    cin>>pkey;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\t File Not Found !" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
    }
    else {
        data1.open("database1.txt", ios::out|ios::app);
        data>>prod_id>>product>>price>>discount;
        while (!data.eof()) {
            if (prod_id==pkey) {
                cout << "\n ---------------------------------------------------------------\n\n" ;
				cout << "\t\t Product Deleted Successfully" ;
				cout << "\n\n ---------------------------------------------------------------\n\n" ;
                token++;
            }
            else {
                data1<<" "<<prod_id<<" "<<product<<" "<<price<<" "<<discount<<"\n";
            }
            data>>prod_id>>product>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token==0) {
            cout << "\n ---------------------------------------------------------------\n\n" ;
			cout << "\t\t Record Not Found !" ;
			cout << "\n\n ---------------------------------------------------------------\n\n" ;
        }
    }
}

void Shopping::list_prod(vector<int>& prods) {
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n___________________________________________________________\n" ;
	cout << "Prod. No.\t\tName\t\tPrice\n" ;
	cout << "___________________________________________________________\n" ;
    data>>prod_id>>product>>price>>discount;
    while (!data.eof()) {
        prods.push_back(prod_id);
        cout<<prod_id<<"\t\t"<<product<<"\t\t"<<price<<"\n";
        data>>prod_id>>product>>price>>discount;
    }
    data.close();
}


void Shopping::reciept(){
    fi:
    fstream data;
    int arrc[100];
    int arrq[100];
    int c=0;
    char choice;
    float amt=0;
    float discount=0;
    float total=0;
    cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t RECEIPT" ;
	cout << "\n\n ---------------------------------------------------------------\n\n" ;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\tNo Stock left, Please check with Admin of store !" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
    }
    else {
        data.close();
        vector<int> prods;
        list_prod(prods);
        cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\tPlace Your Orders" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
        do {
            list_prod(prods);
            cout<<"\n\nEnter the product code\t";
            cin>>arrc[c];
            vector<int>::iterator it;
            it= find(prods.begin(),prods.end(),arrc[c]);
            if (it != prods.end()) {
                cout<<"\n\nEnter the quantity \t" ;
                cin>>arrq[c];
                for (int i=0; i<c; i++) {
                    if (arrc[i]==arrc[c]) {
                        cout << "\n ---------------------------------------------------------------\n\n" ;
					    cout << "\t\t Product already exist. Please add another products !" ;
					    cout << "\n\n ---------------------------------------------------------------\n\n" ;
                        goto fi;
                    }
                }
                c++;
            }
            else {
                cout << "\n ---------------------------------------------------------------\n\n" ;
                cout<<"Product doesn't exist\nPlease select other product from below list\t\n";
                cout << "\n ---------------------------------------------------------------\n\n" ;
                list_prod(prods);
            }
            
            cout << "\n ---------------------------------------------------------------\n\n" ;
			cout << "\t Do you want to buy another product ?\n\t Press 'y' if yes, else 'n' for no :\t" ;
            cin>>choice;
        }
        while (choice=='y') ;

        cout << "\n\n\t\t\t__________________________________RECEIPT____________________________________\n" ;
		cout << "\nProduct No\tProduct Name\tProduct Quantity\tPrice\tAmount\tAmount With Discount\n" ;
		cout << "\n\t____________________________________________________________________________________\n\n" ;
        for (int i=0 ; i<c+1; i++) {
            data.open("database.txt",ios::in);
            data>>prod_id>>product>>price>>discount;
            while (!data.eof()) {
                if (prod_id==arrc[i]) {
                    amt=price*arrq[i];
                    discount=amt-(amt*discount/100);
                    total=total+discount;
                    cout<<"\n"<<prod_id<<"\t\t"<<product<<"\t\t"<<arrq[i]<<"\t\t\t"<<price<<"\t\t"<<amt<<"\t\t"<<discount<<"\n";
                }
                data>>prod_id>>product>>price>>discount;
                
            }
            data.close();
        }
        
    }
    cout << "\n\t____________________________________________________________________________________\n\n" ;
	cout << "\n Total Amount :\t" << total ;
	cout << "\n\n\t____________________________________________________________________________________\n\n" ; 
	cout << "\n\t------------------------------------------------------\n" ;
	cout << "\n\t\tThanks for Shopping At BigBazaar !! \n" ;
    cout << "\n\t\tVisit Again \n" ;
	cout << "\n\t------------------------------------------------------\n" ;
	
	cout << "\n\n========================================================================================================================\n\n" ;
}

int main(){
    cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\tWelcome to BigBazaar	\n" ;
	cout << "\n ---------------------------------------------------------------\n\n" ;
    Shopping s;
    s.menu();
}
