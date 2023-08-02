To The Point:
4 PILLARS -----
            1.Encapsulation                          3.Inheritence
            2.Abstraction                            4.Polymorphism

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
 Example - Friend Function

class External1;
class Internal1
{
    int math;
    int oop;
    int se;
    int ds;
    int add;
public:
    void read()
    {

        cout<<"-----Enter Internal Marks:-----"<<endl;
        cout<<"Enter Maths Internals:"<<endl;
        cin>>math;
        cout<<"Enter OOP Internals:"<<endl;
        cin>>oop;
        cout<<"Enter SE Internals:"<<endl;
        cin>>se;
        cout<<"Enter DS Internals:"<<endl;
        cin>>ds;

        add=math+oop+se+ds;
        cout<<"Total in Internals="<<add<<endl;
    }

    friend int sum(Internal1,External1);
};
class External1
{
    int math;
    int oop;
    int se;
    int ds;
    int add;
public:
    void read()
    {

        cout<<"-----Enter External Marks:-----"<<endl;
        cout<<"Enter Maths Externals:"<<endl;
        cin>>math;
        cout<<"Enter OOP Externals:"<<endl;
        cin>>oop;
        cout<<"Enter SE Externals:"<<endl;
        cin>>se;
        cout<<"Enter DS Externals:"<<endl;
        cin>>ds;
        add=math+oop+se+ds;
        cout<<"Total in Externals="<<add<<endl;

    }
    friend int sum(Internal1,External1);
};
int sum(Internal1 a, External1 b)
{
    if(a.math+b.math<50)
    {
        cout<<"Math FAILED"<<endl;
    }
    else
    {
        cout<<"Math PASSED"<<endl;
    }
    if(a.oop+b.oop<50)
    {
        cout<<"OOP FAILED"<<endl;
    }
    else
    {
        cout<<"OOP PASSED"<<endl;
    }
    if(a.se+b.se<50)
    {
        cout<<"SE FAILED"<<endl;
    }
    else
    {
        cout<<"SE PASSED"<<endl;
    }
    if(a.ds+b.ds<50)
    {
        cout<<"DS FAILED"<<endl;
    }
    else
    {
        cout<<"DS PASSED"<<endl;
    }
    cout<<"Combined out of 400 Marks is:"<<a.add+b.add<<endl;
}
int main()
{
    int t;
    Internal1 x;
    External1 y;
    x.read();
    y.read();
    //cout<<"The Total Marks are:"<<sum(x,y)<<endl;
    t=sum(x,y);
    if(t>=200)
    {
        cout<<"-----OVERALL-----"<<endl;
        cout<<"The student has PASSED."<<endl;
    }
    else
    {
        cout<<"The student has FAILED."<<endl;
    }



}


Friend Class : 

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
  in simple terms any member function of class B can access private and protected data of A but member function of Class A cannot access the data of class B.
 Let us take a example of employee and sales where this relation is practically observed.On the basis of sales we are grading employee and giving incentives. 

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

  
