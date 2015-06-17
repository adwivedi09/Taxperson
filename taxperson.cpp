

#include<iostream>
using namespace std;

//class TaxPerson to calculate the total cost with tax 
class TaxPerson {
    int cost_in_cents;
	int basic_lux_item;  // 1 = lux item and 0 = basic item
	float total_tax;
  public:
    TaxPerson (int,int); // constructor for the class TaxPerson
    void get(){
    	cout << cost_in_cents <<endl << basic_lux_item;
    }
    
    // tax_cal function returns -1 for the cost not being valid, -2 for the type of item being invalid and the total cost
    // based on the given conditions,
	float tax_cal (){
	float tax;
    if(cost_in_cents <= 0){
		//cout << "Enter the valid value in cents for the cost"<<endl;
		return -1;
	}
	else if(basic_lux_item != 0 && basic_lux_item != 1){
	   //cout << "The item can be either basic,i.e., a value '0' or luxury,i.e., a value '1'"<<endl<< "Invalid item value"<<endl;
	   return -2;
	}
	else{
	     if(basic_lux_item == 0){  
		   tax = 0.01*cost_in_cents;
		 }
		 else if(basic_lux_item == 1){  
		   tax = 0.09*cost_in_cents;
		 }
		total_tax = cost_in_cents + tax;
		//cout<<"The cost of the item along with the tax is:"<<total_tax<<endl;
		return total_tax;
	}
}
};
TaxPerson::TaxPerson (int cost, int item) {
  cost_in_cents = cost;
  basic_lux_item = item;
}

// main function with object of class to verify the output -- unit testing code in unittest.cpp file
/*int main(){
	
  float item_tax;
  TaxPerson person1(40,0);
  item_tax = person1.tax_cal();
  cout<<item_tax<<endl;
  
  TaxPerson person2(40,1);
  item_tax = person2.tax_cal();
  cout<<item_tax<<endl;
  
  TaxPerson person3(0,0);
  item_tax = person3.tax_cal();
  cout<<item_tax<<endl;
  
  TaxPerson person4(0,1);
  item_tax = person4.tax_cal();
  cout<<item_tax<<endl;
  
  TaxPerson person5(-40,0);
  item_tax = person5.tax_cal();
  cout<<item_tax<<endl;
  
  TaxPerson person6(-40,1);
  item_tax = person6.tax_cal();
  cout<<item_tax<<endl;
  
  TaxPerson person7(40,2);
  item_tax = person7.tax_cal();
  cout<<item_tax<<endl;
}*/
