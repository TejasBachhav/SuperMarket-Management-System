/*
 * Developer's Name : Tejas.B
 * Administrator Email : admin@email.com
 * Administrator Password : Tejas
 */

#include <iostream>
#include <fstream>

using namespace std ;

class shopping
{
	private :
		int pcode ;
		float price ;
		float dis ;
		string pname ;
		
	public :
		void menu() ;
		void administrator() ;
		void customer() ;
		void add() ;
		void edit() ;
		void rem() ;
		void list() ;
		void receipt() ;
} ;

void shopping :: menu()
{
	m :
	
	int choice ;
	string email ;
	string password ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\tSupermarket Main Menu - Tejas	\n" ;
	cout << "\n ---------------------------------------------------------------\n\n" ;
	
	cout << "\t1] Administrator\n\n" ;
	cout << "\t2] Customer\n\n" ;
	cout << "\t3] Exit\n\n" ;
	
	cout << "\t Please Enter your login option :\t" ;
	cin >> choice ;
	
	
	switch (choice)
	{
		case 1 :
			cout << "\n PLease login \n" ;
			cout << " Enter Email :\t" ;
			cin >> email ;
			cout << "\n Enter Password :\t" ;
			cin >> password ;
			
			if((email == "admin@email.com") && (password == "Tejas"))
			{
				administrator() ;
			}
			
			else
			{
				cout << "\n------------------------------------------------------\n" ;
				cout << "\n\t\tInvalid Email or Password\n" ;
				cout << "\n------------------------------------------------------\n" ;
				goto m ;
			}
			break ;
			
		case 2 :
			customer() ;
			break ;
		
		case 3 :
			cout << "\n------------------------------------------------------\n" ;
			cout << "\n\t\tThank You !! - Tejas\n" ;
			cout << "\n------------------------------------------------------\n" ;
			exit(0) ;
			break ;
			
		default :
			cout << "\n------------------------------------------------------\n" ;
			cout << "\n	 Invalid Choice please select from the given choice	 \n" ;
			cout << "\n------------------------------------------------------\n" ;
			goto m ;
	}
}

void shopping :: administrator()
{
	m :
	
	int choice ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t	Administrator Menu" ;
	cout << "\n\n ---------------------------------------------------------------\n" ;
	cout << "\n\t1] Add the product" ;
	cout << "\n\t2] Modify the product" ;
	cout << "\n\t3] Delete the product" ;
	cout << "\n\t4] Back to Main Menu" ;
	
	cout << "\n\n Please Enter your choice :\t" ;
	cin >> choice ;
	
	switch (choice)
	{
		case 1 :
			add() ;
			break ;
		
		case 2 :
			edit() ;
			break ;
			
		case 3 :
			rem() ;
			break ;
			
		case 4 :
			menu() ;
			break ;
		
		default :
			cout << "\n------------------------------------------------------\n" ;
			cout << "\n	 Invalid Choice please select from the given choice	 \n" ;
			cout << "\n------------------------------------------------------\n" ;
			goto m ;
	}
}


void shopping :: customer()
{
	m :
	
	int choice ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t	Customer Menu" ;
	cout << "\n\n ---------------------------------------------------------------\n" ;
	
	cout << "\n\t1] Buy product" ;
	cout << "\n\t2] Go Back" ;
	
	cout << "\n\n Please Enter your choice :\t" ;
	cin >> choice ;

	switch (choice)
	{
		case 1 :
			receipt() ;
			break ;
		
		case 2 :
			menu() ;
			break ;
			
		default :
			cout << "\n\n\t------------------------------------------------------\n" ;
			cout << "\n\t  Invalid Choice please select from the given choice\n" ;
			cout << "\n\t------------------------------------------------------\n" ;
			goto m ;
	}
}


void shopping :: add()
{
	m :
	
	fstream data ;
	
	int c ;
	int token = 0 ;
	float p ;
	float d ;
	string n ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t Add new product" ;
	cout << "\n\n ---------------------------------------------------------------\n" ;
	cout << "\n\t Product code of the product :\t" ;
	cin >> pcode ;
	cout << "\n\t Name of the product :\t" ;
	cin >> pname ;
	cout << "\n\t Price of the product :\t" ;
	cin >> price ;
	cout << "\n\t Discount of the product :\t" ;
	cin >> dis ;
	
	data.open("Stocks.txt", ios ::in) ; // open in read-mode
	
	if(!data)
	{
		data.open("Stocks.txt", ios :: app | ios :: out) ; //  open in append-mode
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n" ;
		data.close() ;
	}
	
	else
	{
		data >> c >> n >> p >> d ;
		
		while (! data.eof())
		{
			if (c == pcode)
			{
				token++ ;
			}
			
			data >> c >> n >> p >> d ;
		}
		
		data.close() ;
		
		if (token > 0)
		{
			cout << "\n ---------------------------------------------------------------\n\n" ;
			cout << "Product Code Repeated\nPlease try again with Unique Product Code" ;
			cout << "\n\n ---------------------------------------------------------------\n\n" ;
			goto m ;
		}
	
		else
		{
			data.open("Stocks.txt", ios :: app | ios :: out) ;
			data << " " << pcode << " " << pname << " " << price << " " << dis << "\n" ;
			data.close() ;
		}
	
		cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\t Recorded Inserted" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
	}
	
	menu() ;
}


void shopping :: edit()
{
	fstream data, data1 ;
	
	int pkey ;
	int token = 0 ;
	int c ;
	float p ;
	float d ;
	string n ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t Modify the record" ;
	cout << "\n\n ---------------------------------------------------------------\n\n" ;
	cout << "\t Product code :\t" ;
	cin >> pkey ;
	
	data.open("Stocks.txt", ios :: in) ;
	
	if(! data)
	{
		cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\tFile doesn't exist" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
	}
	
	else
	{
		data1.open("Stocks1.txt", ios :: app | ios :: out ) ;
		
		data >> pcode >> pname >> price >> dis ;
		
		while (! data.eof())
		{
			if (pkey == pcode)
			{
				cout << "\n\t Product's new code :\t" ;
				cin >> c ;
				cout << "\n\t Name of the product :\t" ;
				cin >> n ;
				cout << "\n\t Discount :\t" ;
				cin >> d ;
				
				data1 << " " << c << " " << n << " " << p << " " << d << "\n" ;
				cout << "\n\n ---------------------------------------------------------------\n\n" ;
				cout << "\t\t Record Updated" ;
				cout << "\n\n ---------------------------------------------------------------\n\n" ;
				
				token++ ;
			}
			
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n" ;
			}
			
			data >> pcode >> pname >> price >> dis ;
		}
		
		data.close() ;
		data1.close() ;
		
		remove("Stocks.txt") ;
		rename("Stocks1.txt", "Stocks.txt") ;
		
		if (token == 0)
		{
			cout << "\n ---------------------------------------------------------------\n\n" ;
			cout << "\t\t Record Not Found !" ;
			cout << "\n\n ---------------------------------------------------------------\n\n" ;
		}
	}
	
	menu() ;
}


void shopping :: rem()
{
	fstream data, data1 ;
	
	int pkey ;
	int token = 0 ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t Delete Product" ;
	cout << "\n\n ---------------------------------------------------------------\n\n" ;
	
	list() ;
	
	cout << "\t Product code :\t" ;
	cin >> pkey ;
	
	data.open("Stocks.txt", ios :: in) ;
	
	if (! data)
	{
		cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\t File Not Found !" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
	}
	
	else
	{
		data1.open("Stocks1.txt", ios :: app | ios :: out) ;
		data >> pcode >> pname >> price >> dis ;
		
		while (! data.eof())
		{
			if(pcode == pkey)
			{
				cout << "\n ---------------------------------------------------------------\n\n" ;
				cout << "\t\t Product Deleted Successfully" ;
				cout << "\n\n ---------------------------------------------------------------\n\n" ;
				token ++ ;
			}
			
			else
			{
				data1 << " " << pcode << " " << price << " " << dis << "\n";
			}
			
			data >> pcode >> pname >> price >> dis ;
		}
		
		data.close() ;
		data1.close() ;
		
		remove("Stocks.txt") ;
		rename("Stocks1.txt", "Stocks.txt") ;
		
		if (token == 0)
		{
			cout << "\n ---------------------------------------------------------------\n\n" ;
			cout << "\t\t Record Not Found !" ;
			cout << "\n\n ---------------------------------------------------------------\n\n" ;
		}
	}
	
	menu() ;
}


void shopping :: list()
{
	fstream data ;
	
	data.open("Stocks.txt", ios :: in) ;
	
	cout << "\n\n___________________________________________________________\n" ;
	cout << "ProNo\t\tName\t\tPrice\n" ;
	cout << "\n\n___________________________________________________________\n" ;
	
	data >> pcode >> pname >> price >> dis ;
	
	while(! data.eof())
	{
		cout << pcode << "\t\t" << pname << "\t\t" << price << "\n" ;
		data >> pcode >> pname >> price >> dis ;
	}
	
	data.close() ;
}


void shopping::receipt()
{
    fstream data;

    int arrc[100]; 
    int arrq[100]; 
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n ---------------------------------------------------------------\n\n";
    cout << "\t\t RECEIPT";
    cout << "\n\n ---------------------------------------------------------------\n\n";
    
    list();

    do
    {
        int productCode;
        cout << "\n\nEnter Product code: ";
        cin >> productCode;

 
        bool validProduct = false;
        data.open("Stocks.txt", ios::in);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == productCode)
            {
                validProduct = true;
                break;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();

        if (!validProduct)
        {
            cout << "Invalid product code. Please try again." << endl;
            continue;
        }

        int quantity;
        cout << "Enter the Product Quantity: ";
        cin >> quantity;
        cout << endl;


        arrc[c] = productCode;
        arrq[c] = quantity;
        c++;

        cout << "\n\t\t\t_________________________ORDER DETAILS_________________________\n";
        cout << "Product No\tProduct Name\tProduct Quantity\tPrice\tAmount\tAmount With Discount\n";
        cout << "\n\t____________________________________________________________________________________\n\n";

        total = 0;
        for (int i = 0; i < c; i++)
        {
            data.open("Stocks.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total += dis;

                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }

        cout << "\n\t____________________________________________________________________________________\n\n";
        cout << "Total Amount: " << total;
        cout << "\n\n\t____________________________________________________________________________________\n\n";

        cout << "Do you want to buy another product? (Press 'y' for yes, 'n' for no): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');


    char addMoreOrdersChoice;
    cout << "Administrator, do you want to add more orders? (Press 'y' for yes, 'n' for no): ";
    cin >> addMoreOrdersChoice;

    if (addMoreOrdersChoice == 'y' || addMoreOrdersChoice == 'Y')
    {
     
        receipt();
    }
    else
    {
      
        menu();
    }
}

int main()
{
	shopping Tejas ;
	
	Tejas.menu() ;

	return 0 ;
}
