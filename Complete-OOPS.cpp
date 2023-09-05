To The Point:
4 PILLARS -----
            1.Encapsulation                          3.Inheritence
            2.Abstraction                            4.Polymorphism
1.Encapsulation is the process of combining data and functions into a single unit called class. In Encapsulation, the data is not accessed directly; it is accessed through the functions 
  present inside the class. In simpler words, attributes of the class are kept private and public getter and setter methods are provided to manipulate these attributes. Thus, encapsulation 
  makes the concept of data hiding possible. (Data hiding: a language feature to restrict access to members of an object, reducing the negative effect due to dependencies. e.g. "protected", 
  "private" feature in C++).
   Data hiding can be thought as a subset of Encapsulation.
   Data hiding only hides class data components, whereas data encapsulation 
   hides class data parts and private methods as well.
2. Abstraction refers to the act of representing essential features without 
   including the background details(class definition)
   Data abstraction is implemented by creating objects of the class definition.
   Objects are the basic run time entities in oop system.

3. The idea of inheritance is simple, a class is based on another class and uses data and implementation of the other class. And the purpose of inheritance is Code Reuse.
4. Polymorphism is the ability to present the same interface for differing underlying forms (data types). With polymorphism, each of these classes will have different underlying data. A point shape needs only two coordinates (assuming it's in a two-dimensional space of course). A circle needs a center and radius. A square or rectangle needs two coordinates for the top left and bottom right corners and (possibly) a rotation. An irregular polygon needs a series of lines.


	

What is the use of friend function?
- Special function for specific use
- Defined outside of class scope.
- Not a member function of that class.
- Yet has the right to access the the private and public member of that class
- Standalone function or entire class may be declared to be friend of class
- Often appropriate when a member function cannot be used for certain operations.

Let us see using a example of Internal and External marks of student and how we combine them using friend function.
How useful it is. Why we actually need friend function. Think of it as a thirdy party you give him resource he will do 
the task for you. Remember - Friend functions in C++ provide access to private or protected members of a class from outside the class scope.
 Example - Friend Function:
  https://ideone.com/mlclZw


Example - Friend Class : 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Alpha {
private:
	int data;
public:
	Alpha(): data(3) { };
	friend class Beta;
};

class Beta { // can access all private of Alpha
public:
	void func1(Alpha alpha) {
    	cout << alpha.data << "\n";
	}
};


int main() {
	Alpha alpha;
	Beta beta;
	beta.func1(alpha);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
In C++, when a class is declared as a friend of another class, it means that the friend class has access to the private and 
protected members of the class it is a friend of. In this case, Beta is a friend of Alpha, so it can access the private member
data of the Alpha class.

Important Properties:
- Friendship is granted, not taken
- For class B to be friend of class (A->B), class A must explicitly declare that class B is its friend.
- Friendship relationship is neither symmetric or transitive.  
- If class A is friend of class B,class B is friend of class C,You cannot say that class B is friend of A or class C is friend of B, or class A is friend of C.
- Somewhat unidirection type
- To access private members of the class A in friend class of B,an object of class A is required in function of friend class B.
  Let me clear this point 
  Class B; 

  Class A{
    int a;
    friend class B;
    // class B is friend of class A
  }
  Class B{
    // but class A is not friend of B
    int x;
    methods
  }
  Remembe Friendship is granted, not taken

  in simple terms any member function of class B can access private and protected data of A but member function of Class A cannot access the data of class B.
 Let us take a example of employee and sales where this relation is practically observed.On the basis of sales we are grading employee and giving incentives. 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class sales;
class Employee
{
    string employee_name;
    int employee_id;
    string employee_dept;
    int monthly_salary;

public:
    void read_data()
    {
        cout<<"Enter Employee Name:"<<endl;
        cin>>employee_name;
        cout<<"Enter Employee ID:"<<endl;
        cin>>employee_id;
        cout<<"Enter Employee Department:"<<endl;
        cin>>employee_dept;
        cout<<"Enter Employee Monthly Salary:"<<endl;
        cin>>monthly_salary;
    }
    void display_data()
    {
        cout<<"-----EMPLOYEE DETAILS:-----"<<endl;
        cout<<"The Employee name is:"<<employee_name<<endl;
        cout<<"The employee ID is:"<<employee_id<<endl;
        cout<<"The Employee Dept. is:"<<employee_dept<<endl;
        cout<<"The Monthly salary of the Employee is:"<<monthly_salary<<endl;

    }
    friend class sales;
};
class sales
{
    int sales_in_month;
    int incentive_gain;
    string performance_indicator;

public:
    void read_data()
    {
        cout<<"Enter the Employee's Monthly Sales:"<<endl;
        cin>>sales_in_month;
    }
    void calculate_incentive(Employee e)
    {
        if(sales_in_month>=50&&sales_in_month<=100)
        {
            e.monthly_salary+=0.1*e.monthly_salary;
            cout<<"Salary with incentive is:"<<e.monthly_salary<<endl;
        }
        else if(sales_in_month>100&&sales_in_month<=150)
        {
            e.monthly_salary+=0.2*e.monthly_salary;
            cout<<"Salary with incentive is:"<<e.monthly_salary<<endl;
        }
        else
        {
            e.monthly_salary+=0.3*e.monthly_salary;
            cout<<"Salary with incentive is:"<<e.monthly_salary<<endl;
        }
    }
    void display_performance(Employee e)
    {
        if (sales_in_month<50)
        {
            cout<<"Employee Performance= POOR"<<endl;
        }
        else if(sales_in_month>=50&&sales_in_month<=100)
        {
            cout<<"Employee Performance= SATISFACTORY"<<endl;
        }
        else if(sales_in_month>100&&sales_in_month<=150)
        {
            cout<<"Employee Performance= GOOD"<<endl;
        }
        else
        {
            cout<<"Employee Performance= EXCELLENT"<<endl;
        }
    }
};


void solve(){
    Employee e1;
    sales s1;
    e1.read_data();
    e1.display_data();
    s1.read_data();
    s1.calculate_incentive(e1);
    s1.display_performance(e1);
}
Like for a particular sale we can easily deduce which employee has performed how well.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
"this" pointer
- To understand this pointer it is important to know how objects look 
  at functions and data members of class.
- Each object gets its own copy of the data member.
- All-access the same function definition as present in the code segment.
- Meaning each object gets its own copy of data members and all objects
  share a single copy of member functions.
 ook . Then now question is that if only one copy of each member function 
 exists and is used by mulitple objects, how are the proper data members 
 are accessed and updated?

 Answer - The compiler supplies an implicit pointer along with the names 
 of the functions as 'this'




