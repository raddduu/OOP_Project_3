#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>

class animal{
public:
    virtual void reading(std::istream& in){in>>name>>age>>weight;}
    virtual void display(std::ostream& out){out<<name<<" is "<<age<<" years old and weights "<<weight<<" kg ";}
    std::tuple<std::string,double,double> get_base_data()   {return {name,age,weight};}
protected:
    std::string name;
    double age,weight;
};

class lion: public animal{
public:
    std::string getTitle()   {if (gender==0)   return "lion";  return "lioness";}
    std::string getPronoun()   {if (gender==0)   return "He";  return "She";}
    void reading(std::istream& in)   {animal::reading(in);   in>>gender>>boss;}
    void display(std::ostream& out)
    {
        animal::display(out);
        out<<"and is a "<<this->getTitle()<<". ";
        if (boss == 1)  out<<this->getPronoun()<<" is also the head of the pack.\n";
        else out<<"\n";
    }
    void food_prefference(std::string food)
    {
        if (food == "meat") std::cout<<"Lions like this food!\n";
        else std::cout<<"Lions don't eat this food!\n";
    }
private:
    bool gender,boss;
};

class monkey: public animal{
public:
    std::string getTitle()   {return "monkey";}
    std::string getPronoun()   {if (gender==0)   return "He";  return "She";}
    void reading(std::istream& in)   {animal::reading(in);   in>>gender>>nr_bananas;}
    void display(std::ostream& out)
    {
        animal::display(out);
        out<<"and is a "<<this->getTitle()<<". "<<this->getPronoun()<<" eats "<<nr_bananas<<" a day!\n";
    }
    void food_prefference(std::string food)
    {
        if (food == "fruits") std::cout<<"Monkeys like this food!\n";
        else std::cout<<"Monkeys don't eat this food!\n";
    }
private:
    int nr_bananas;
    bool gender;
};

class cameleon: public animal{
public:
    std::string getTitle()   {return "cameleon";}
    std::string getPronoun()   {return "It";}
    void reading(std::istream& in)   {animal::reading(in);   in>>nr_colors;}
    void display(std::ostream& out)
    {
        animal::display(out);
        out<<"and is a "<<this->getTitle()<<". "<<this->getPronoun()<<" can take up to "<<nr_colors<<" colors!\n";
    }
    void food_prefference(std::string food)
    {
        if (food == "vegetables") std::cout<<"Cameleons like this food!\n";
        else std::cout<<"Cameleons don't eat this food!\n";
    }
private:
    int nr_colors;
};

std::istream& operator >> (std::istream& in, animal& a)   {a.reading(in); return in;}
std::ostream& operator << (std::ostream& out, animal& a)    {a.display(out); return out;}
bool operator == (animal& a1, animal& a2)   {return a1.get_base_data() == a2.get_base_data();}

/*template<class type>void dynamic_display(type* ptr)
{
    domicile* ptr_h = dynamic_cast<domicile*>(ptr_b);
}*/

template <class object>class database{
public:
    void add_obj(object obj)    {objects.push_back(obj);}
    void remove_obj(animal obj)
    {
        for (int i = 0; i < objects.size(); i++)
        {
            if (objects[i] == obj)
            {
                objects.erase(objects.begin()+i);
                break;
            }
        }
    }

    void display_obj()
    {
        for (int i = 0; i < objects.size(); i++)    std::cout<<objects[i];
    }

protected:
    std::vector<object> objects;
};

database<lion> zoo_lions;
database<monkey> zoo_monkeys;
database<cameleon> zoo_cameleons;

void read()
{
    int n;

    std::cout<<"Please enter how many lions do you want to add: "; std::cin>>n;

    for (int i = 0; i < n; i++)
    {
        lion a;
        std::cin>>a;
        zoo_lions.add_obj(a);
    }

    std::cout<<"Please enter how many monkeys do you want to add: "; std::cin>>n;

    for (int i = 0; i < n; i++)
    {
        monkey a;
        std::cin>>a;
        zoo_monkeys.add_obj(a);
    }

    std::cout<<"Please enter how many cameleons do you want to add: "; std::cin>>n;

    for (int i = 0; i < n; i++)
    {
        cameleon a;
        std::cin>>a;
        zoo_cameleons.add_obj(a);
    }
}

void remove_animals()
{
    int n;

    std::cout<<"Please enter the number of animals that you want to evict from the zoo: ";  std::cin>>n;

    for (int i = 0; i < n; i++)
    {
        animal aux;
        std::cout<<"Enter the name, age and weight of the animal that you want to delete: ";    std::cin>>aux;
        zoo_lions.remove_obj(aux);
        zoo_monkeys.remove_obj(aux);
        zoo_cameleons.remove_obj(aux);
    }
}

void display_animals()
{
    int c;

    while (1)
    {
        std::cout<<"What animals would you like to display?\n1.Lions\n2.Monkeys\n3.Cameleons\n4.Exit\nYour choice(number from 1 to 4): ";   std::cin>>c;

        switch (c)
        {
            case 1:
                zoo_lions.display_obj();
                break;
            case 2:
                zoo_monkeys.display_obj();
                break;
            case 3:
                zoo_cameleons.display_obj();
                break;
            case 4:
                return;
            default:
                std::cout<<"Please enter a valid choice!\n";
                break;
        }
    }

}

class zoo_manager{
public:
    std::string get_name();
    int get_salary();
    void set_salary(int);
    void set_name(std::string);
    static zoo_manager* instance(); ///static method to create the instance unless it already exists
private:
    std::string name;
    int salary;
    static zoo_manager *unique_instance;
    zoo_manager(std::string,int);   ///private constructor
};

zoo_manager *zoo_manager::unique_instance = 0;

zoo_manager::zoo_manager(std::string n = "no_name", int s = 0)
{
    name = n;
    salary = s;
}

zoo_manager* zoo_manager::instance()
{
    if (!unique_instance)
        unique_instance = new zoo_manager;
    return unique_instance;
}

std::string zoo_manager::get_name()
{
    return name;
}

int zoo_manager::get_salary()
{
    return salary;
}

void zoo_manager::set_name(std::string n)
{
    name = n;
}

void zoo_manager::set_salary(int s)
{
    salary = s;
}

class Alarm{
public:
	void alarmOn()
	{
		std::cout << "Alarm is on and house is secured\n";
	}

	void alarmOff()
	{
		std::cout << "Alarm is off and you can go into the house\n";
	}
};

class Ac
{
public:
	void acOn()
	{
		std::cout << "Ac is on\n";
	}

	void acOff()
	{
		std::cout << "AC is off\n";
	}
};

class Tv
{
public:
	void tvOn()
	{
		std::cout << "Tv is on\n";
	}

	void tvOff()
	{
		std::cout << "TV is off\n";
	}
};

class zoo_facade{
public:
	void feed(std::string food)
	{
		l.food_prefference(food);
		m.food_prefference(food);
		c.food_prefference(food);
	}
private:
    lion l;
	monkey m;
	cameleon c;
};

int main()
{
    ///interactive menu to test the database template class

    int c,ok=1;

    std::cout<<"Welcome to the zoo!Here we have lions, monkeys and cameleons! What do you want to do?\n1.Add animals\n2.Remove animals\n3.Display animals\n4.Exit\n";

    while(ok)
    {
        std::cout<<"Enter your choice: ";    std::cin>>c;

        switch (c)
        {
            case 1:
                read();
                break;
            case 2:
                remove_animals();
                break;
            case 3:
                display_animals();
                break;
            case 4:
                ok = 0;
                break;
            default:
                std::cout<<"Enter a valid choice!";
                break;
        }
    }

    ///testing the singleton design pattern: unique address in spite of modifying data => unique instance

    std::cout<<zoo_manager::instance()->get_name()<<" is the current zoo manager and he earns "<<zoo_manager::instance()->get_salary()<<"$ per month\n";

    std::cout<<zoo_manager::instance()<<"\n";

    zoo_manager::instance()->set_name("John Smith");

    std::cout<<zoo_manager::instance()->get_name()<<" is the current zoo manager and he earns "<<zoo_manager::instance()->get_salary()<<"$ per month\n";

    std::cout<<zoo_manager::instance()<<"\n";

    zoo_manager::instance()->set_salary(5000);

    std::cout<<zoo_manager::instance()->get_name()<<" is the current zoo manager and he earns "<<zoo_manager::instance()->get_salary()<<"$ per month\n";

    std::cout<<zoo_manager::instance()<<"\n";

    zoo_manager::instance()->set_name("Harry Jackson");
    zoo_manager::instance()->set_salary(4000);

    std::cout<<zoo_manager::instance()->get_name()<<" is the current zoo manager and he earns "<<zoo_manager::instance()->get_salary()<<"$ per month\n";

    std::cout<<zoo_manager::instance()<<"\n";

    ///testing the facade design pattern:   one method instead of multiple cases

    zoo_facade zf;

	zf.feed("meat");
	zf.feed("fruits");
	zf.feed("vegetables");

    return 0;
}
