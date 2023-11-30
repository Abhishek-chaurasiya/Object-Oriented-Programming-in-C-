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

Inheritance - allows us to reuse classes by having other classes inherit their members.
Constructor initialization - From top to bottom in inheritance chain
class Person{
private:
	string name;
	int age;

public:
	Person(string name,int age){
		this->name = name;
		this->age = age;
	}
	void getName(){
		cout<<name<<endl;
	}
};

class Employee:public Person{
private:
	string dep;
	int salary;
public:
	Employee(string dep,int salary,string name,int age):Person(name,age){
		this->dep = dep;
		this->salary = salary;
	}
	void getEmployeeDetail(){
		cout<<dep<<endl;
		cout<<salary<<endl;
	}
};

void solve(){
	
	Employee e1("cse",100000,"abhishek",22);
	e1.getName();
	e1.getEmployeeDetail();

}
It is worth mentioning that constructors can only call constructors from their immediate parent/base class.Consequently, the C constructor could not call or pass parameters to the A constructor directly. The C constructor can only call the B constructor (which has the responsibility of calling the A constructor).

Summary
When constructing a derived class, the derived class constructor is responsible for determining which base class constructor is called. If no base class constructor is specified, the default base class constructor will be used. In that case, if no default base class constructor can be found (or created by default), the compiler will display an error. The classes are then constructed in order from most base to most derived.	

***As a quick refresher, public members can be accessed by anybody. Private members can only be accessed by member functions of the same class or friends. This means derived classes can not access private members of the base class directly!

C++ has a third access specifier that we have yet to talk about because it’s only useful in an inheritance context. The protected access specifier allows the class the member belongs to, friends, and derived classes to access the member. However, protected members are not accessible from outside the class.

class Base
{
public:
    int var_public {}; // can be accessed by anybody
protected:
    int var_protected {}; // can be accessed by Base members, friends, and derived classes
private:
    int var_private {}; // can only be accessed by Base members and friends (but not derived classes)
};

class Derived: public Base
{
public:
    Derived()
    {
        var_public = 1; // allowed: can access public base members from derived class
        var_protected = 2; // allowed: can access protected base members from derived class
        var_private = 3; // not allowed: can not access private base members from derived class
    }
};


Method overriding: function having same prototype in inherited class
occurs when a subclass (child class) has the same method as the parent class. 

	
Virtual Functions:
-General: Pointer of type (int) can only contains the address of integer variable 
 ex - int *ptr; 
      int a = 5;
      ptr = &a; // allowed
      float b = 5.0;
      ptr = &b; // not allowed

But in case of inheritance Base class pointer can point to the object of any of its descendents class but converse is not true. but why ? - basically when derived class is made it is made up of two parts one its own methods and variables and other is inherited.

When we create a derived object, it contains a Base part(which is constructed first) and a Derived part(which is constructed second).	
	
class Animal{
private:
	string name;

public:
	Animal(string name){
		this->name = name;
	}
	string getName(){
		return name;
	}
	string speak(){
		return "????";
	}
};

class Cat:public Animal{
private:
	
public:
	Cat(string name):Animal(name){
	
	}
	// method overriding
	string speak(){
		return "meow";
	}
	
};
class Dog:public Animal{
private:
	
public:
	Dog(string name):Animal(name){
	
	}
	// method overriding
	string speak(){
		return "Woof";
	}
	
};



void solve(){
	
	Cat c1("jelly");
	cout<<c1.getName()<<endl;
	cout<<c1.speak()<<endl;
    
    Dog d1("major");
	cout<<d1.getName()<<endl;
	cout<<d1.speak()<<endl;

	Animal *ptr = &c1;
	// This is problem 
	cout<<ptr->speak()<<endl;
	ptr = &d1;
	cout<<ptr->speak()<<endl; 

}

We see the same issue here. Because ptr is an Animal pointer, it can only see the Animal portion of the class. Consequently, pAnimal->speak() calls Animal::speak() rather than the Dog::Speak() or Cat::speak() function.

Now you might be saying, “The above examples seem kind of silly. Why would I set a pointer or reference to the base class of a derived object when I can just use the derived object?” It turns out that there are quite a few good reasons.
	
1.First, let’s say you wanted to write a function that printed an animal’s name and sound. Without using a pointer to a base class, you’d have to write it using overloaded functions, like 
 this:
void report(const Cat& cat)
{
    std::cout << cat.getName() << " says " << cat.speak() << '\n';
}

void report(const Dog& dog)
{
    std::cout << dog.getName() << " says " << dog.speak() << '\n';
}	

Not too difficult, but consider what would happen if we had 30 different animal types instead of 2. You’d have to write 30 almost identical functions! Plus, if you ever added a new type of animal, you’d have to write a new function for that one too. This is a huge waste of time considering the only real difference is the type of the parameter.

However, because Cat and Dog are derived from Animal, Cat and Dog have an Animal part. Therefore, it makes sense that we should be able to do something like this:

void report(const Animal& rAnimal)
{
    std::cout << rAnimal.getName() << " says " << rAnimal.speak() << '\n';
}	
This would let us pass in any class derived from Animal, even ones that we created after we wrote the function! Instead of one function per derived class, we get one function that works with all classes derived from Animal!

The problem is, of course, that because rAnimal is an Animal reference, rAnimal.speak() will call Animal::speak() instead of the derived version of speak().

2.Second, let’s say you had 3 cats and 3 dogs that you wanted to keep in an array for easy access. Because arrays can only hold objects of one type, without a pointer or reference to a base class, you’d have to create a different array for each derived type, like this:
	void solve(){
	
	// Cat c1("jelly");
	// cout<<c1.getName()<<endl;
	// cout<<c1.speak()<<endl;
    
        //  Dog d1("major");
	// cout<<d1.getName()<<endl;
	// cout<<d1.speak()<<endl;
    
    vector<Dog> dogs= {{"amar"}, {"akbar"},{"anthony"}};
    for(auto &dog:dogs){
    	cout<<dog.getName()<<endl;
    }
    
    vector<Cat> cats= {{"emma"}, {"belly"},{"jaction"}};
    for(auto &cat:cats){
    	cout<<cat.getName()<<endl;
    }

}
Now, consider what would happen if you had 30 different types of animals. You’d need 30 arrays, one for each type of animal!

However, because both Cat and Dog are derived from Animal, it makes sense that we should be able to do something like this:

void solve(){
	
	// Cat c1("jelly");
	// cout<<c1.getName()<<endl;
	// cout<<c1.speak()<<endl;
    
 //    Dog d1("major");
	// cout<<d1.getName()<<endl;
	// cout<<d1.speak()<<endl;
    
    // vector<Dog> dogs= {{"amar"}, {"akbar"},{"anthony"}};
    // for(auto &dog:dogs){
    // 	cout<<dog.getName()<<endl;
    // }
    
    // vector<Cat> cats= {{"emma"}, {"belly"},{"jaction"}};
    // for(auto &cat:cats){
    // 	cout<<cat.getName()<<endl;
    // }

    Cat c1("emma");
    Cat c2("belly");
    Cat c3("jaction");

    Dog d1("amar");
    Dog d2("akbar");
    Dog d3("anthony");

    vector<Animal*> animals = { &c1,&c2,&c3,&d1,&d2,&d3};
    for(auto animal:animals){
    	cout<<animal->getName()<<endl;
    }

}	
