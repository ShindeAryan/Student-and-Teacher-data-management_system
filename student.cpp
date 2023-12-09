#include<iostream>;
#include<fstream>
#include<regex>
#include"student.h";

void user::set_name(std::string name)
{
	this->name = name;
}

void user::set_username(std::string username)
{
	this->username = username;
}

void user::set_email_id(std::string email_id)
{
	this->email_id = email_id;

}

void user::set_password(std::string password)
{
	this->password = password;
}

std::string user::get_username()
{
	return this->username;
}

std::string user::get_email_id()
{
	return this->email_id;
}

std::string user::get_password()
{
	return this->password;
}

std::string user::get_name()
{
	return this->name;
}

int Teacher::getId()
{
    return this->id;
}

void Teacher::setId(int id)
{
    this->id = id;
}

int Teacher::getNo_of_students()
{
    return this->no_of_students;
}

void Teacher::setNo_of_students(int no_of_students)
{
    this->no_of_students = no_of_students;
}

std::string Teacher::getDesignation()
{
    return this->designation;
}

void Teacher::setDesignation(std::string designation)
{
    this->designation = designation;
}

std::string Teacher::getClass_name()
{
    return this->class_name;
}

void Teacher::setClass_name(std::string class_name)
{
    this->class_name = class_name;
}

int student::GetRoll_no(){
    return roll_no;
}

void student::SetRoll_no(int roll_no) {
    this->roll_no = roll_no;
}

std::string student::GetClass1(){
    return class1;
}

void student::SetClass1(std::string class1) {
    this->class1 = class1;
}

std::string student::GetDivision(){
    return division;
}

void student::SetDivision(std::string division) {
    this->division = division;
}

int student::GetPrn_no(){
    return prn_no;
}

void student::SetPrn_no(int prn_no) {
    this->prn_no = prn_no;
}


bool user::login(std::string file_name)
{
    std::string searchName, searchPass;
    std::cout << "----------LOGIN---------" <<std::endl;
    /*;*/

    std::cout << "Enter Your User Name :: ";
    std::getline(std::cin, searchName);
    std::cout << "Enter Your Password :: ";
    std::getline(std::cin, searchPass);

    /*std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/

    std::ifstream file;
    file.open(file_name);
    bool flag = false;

    while (!file.eof()) {

        std::getline(file, name, '*');
        std::getline(file, username, '*');
        std::getline(file, email_id, '*');
        std::getline(file, password, '\n');
     

        if (username == searchName) {
            if (password == searchPass) {
                flag = true;
                break;
            }
            else {

                //std::cin.clear();
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid password\nPress any enter key to return.......";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                file.close();
                return flag;
             

            }
        }
    }

    if (flag == true) {
        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "logged in successfully\npress any key to continue.........";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        load_data();
    }
    else {
        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid user credentials \npress any key to continue.........";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        load_data();
    }
    
    file.close();
    return flag;
}

bool validate_email(std::string email)
{
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email, pattern);
}

void user::signup(std::string file_name)
{
    std::cout << "Enter Your Name :: ";
    std::getline(std::cin,name);
    std::cout << "Enter Your User Name :: ";
    std::getline(std::cin, username);
    bool flag = false;
    do {
        std::cout << "Enter Your Email Address :: ";
        std::getline(std::cin, email_id);

        flag = validate_email(email_id);
        if (flag == false) {
            std::cout << "Enter valid email address";
        }
    } while (flag != true);
    std::cout << "Enter Your Password :: ";
    std::getline(std::cin, password);

    std::fstream file;
    file.open(file_name, std::ios::out | std::ios::app);
    file <<name<<"*"<< username << "*" << email_id << "*" << password << "\n";
    set_data();
    file.close();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void user::forgot_password(std::string file_name)
{
}

void Teacher::load_data()
{
    std::string file_name = get_username() + ".txt";
    data.open(file_name, std::ios::in);

    std::string id1,no_students;
    std::getline(data,id1, '*');
    std::getline(data,no_students,'*');
    std::getline(data, designation, '*');
    std::getline(data, class_name, '\n');

    id = std::stoi(id1);
    no_of_students = std::stoi(no_students);

    std::cout << id << " " << no_of_students << " " << designation << " " << class_name << std::endl;
    data.close();
    

}

void Teacher::set_data()
{
    std::string file_name = get_username() + ".txt";
    data.open(file_name, std::ios::out);

    std::cout << "\nEnter id::";
    std::cin >> id;
    std::cout << "Enter your designation ::";
    std::cin >> designation;
    std::cout << "Enter no of students ::";
    std::cin >> no_of_students;
    std::cout << "Enter your home class ::";
    std::cin >> class_name;

    data << id << "*" << no_of_students << "*" << designation << "*" << class_name << "\n";

    data.close();

}

void Teacher::display_data()
{
    std::cout << "name :" << get_name() << std::endl;
    std::cout << "email_id :" << get_email_id() << std::endl;
    std::cout << "id :" << getId() << std::endl;
    std::cout << "designation :" << getDesignation()<< std::endl;
    std::cout << "number of students :" << getNo_of_students() << std::endl;
    std::cout << "Home class :" << getClass_name() << std::endl;


}

void Teacher::update_data()
{
    int choice;
    do {
       system("cls");
       std::cout << "Select which field you want to update" << std::endl;
       std::cout << "1 :: name\n";
       std::cout << "2 :: id\n";
       std::cout << "3 :: designation\n";
       std::cout << "4 :: no of students\n";
       std::cout << "5 :: Home class\n";
       std::cout << "6 :: Exit\n";
       std::cout << "Enter choice ::";
       std::cin >> choice;

       std::string new_name;
       int new_id;
       int new_no_of_students;
       std::string new_designation;
       std::string new_class_name;

       switch (choice) {
            case 1:
                std::cout << "\nEnter new name ::";
                std::cin >> new_name;
                set_name(new_name);
                break;

            case 2:
                std::cout << "\nEnter new id ::";
                std::cin >> new_id;
                setId(new_id);
                break;


            case 3:
                std::cout << "\nEnter new designation ::";
                std::cin >> new_designation;
                setDesignation(new_designation);
                break;

            case 4:
                std::cout << "\nEnter new no of students ::";
                std::cin >> new_no_of_students;
                setNo_of_students(new_no_of_students);
                break;
            
            case 5:
                std::cout << "\nEnter new Home class ::";
                std::cin >> new_class_name;
                setClass_name(new_class_name);
                break;
            case 6:
                std::cout << "data updated successfully\n";
                break;
            default:
                std::cout << "Invalid choice\n";
       }

    } while (choice != 6);

    std::string file_name = get_username() + ".txt";
    data.open(file_name, std::ios::out);
    data <<get_name()<< "*" << id << "*" << no_of_students << "*" << designation << "*" << class_name << "\n";
    data.close();


}

void student::load_data()
{
    std::string file_name = get_username() + ".txt";
    data.open(file_name, std::ios::in);

    std::string roll1, prn1;
    std::getline(data, roll1, '*');
    std::getline(data, class1, '*');
    std::getline(data, division, '*');
    std::getline(data, prn1, '\n');

    roll_no = std::stoi(roll1);
    prn_no = std::stoi(prn1);

    std::cout << roll_no << " " << class1 << " " << division << " " << prn_no << std::endl;
    data.close();

}

void student::set_data()
{
    std::string file_name = get_username() + ".txt";
    data.open(file_name, std::ios::out);

    std::cout << "\nEnter roll_no::";
    std::cin >> roll_no;
    std::cout << "Enter your class name ::";
    std::cin >> class1;
    std::cout << "Enter division ::";
    std::cin >> division;
    std::cout << "Enter your PRN number ::";
    std::cin >> prn_no;

    data << roll_no << "*" << class1 << "*" <<division << "*" << prn_no << "\n";

    data.close();
}

void student::display_data()
{
    std::cout << "name :" << get_name() << std::endl;
    std::cout << "email_id :" << get_email_id() << std::endl;
    std::cout << "roll no :" << GetRoll_no() << std::endl;
    std::cout << "class name :" << GetClass1() << std::endl;
    std::cout << "Division :" << GetDivision() << std::endl;
    std::cout << "PRN no :" << GetPrn_no() << std::endl;
}

void student::update_data()
{
    int choice;
    do {
        system("cls");
        std::cout << "Select which field you want to update" << std::endl;
        std::cout << "1 :: name\n";
        std::cout << "2 :: Roll no\n";
        std::cout << "3 :: class\n";
        std::cout << "4 :: Division\n";
        std::cout << "5 :: PRN no\n";
        std::cout << "6 :: Exit\n";
        std::cout << "Enter choice ::";
        std::cin >> choice;

        std::string new_name;
        int new_roll;
        int new_prn;
        std::string new_class_name;
        std::string new_division;

        switch (choice) {
        case 1:
            std::cout << "\nEnter new name ::";
            std::cin >> new_name;
            set_name(new_name);
            break;

        case 2:
            std::cout << "\nEnter new roll_no ::";
            std::cin >> new_roll;
            SetRoll_no(new_roll);
            break;


        case 5:
            std::cout << "\nEnter new PRN no ::";
            std::cin >> new_prn;
            SetPrn_no(new_prn);
            break;

        case 4:
            std::cout << "\nEnter new Division ::";
            std::cin >> new_division;
            SetDivision(new_division);
            break;

        case 3:
            std::cout << "\nEnter new class ::";
            std::cin >> new_class_name;
            SetClass1(new_class_name);
            break;
        case 6:
            std::cout << "data updated successfully\n";
            break;
        default:
            std::cout << "Invalid choice\n";
        }

    } while (choice != 6);

    std::string file_name = get_username() + ".txt";
    data.open(file_name, std::ios::out);
    data<<get_name()<< "*" << roll_no << "*" << class1 << "*" << division << "*" << prn_no << "\n";
    data.close();
}

void dashboard(user* u1) {

    int choice = 0;

    do {
        system("cls");
        std::cout << "choose any operation " << std::endl;
        std::cout << "\n1 :: display data\n";
        std::cout << "2 :: update data \n";
        std::cout << "3 :: logout\n\n";

        std::cout << "Enter your choice ::";
        std::cin >> choice;

        switch (choice) {

        case 1:

            u1->display_data();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nPress any enter key to return.......";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;

        case 2:
            u1->update_data();
            break;
        case 3:
            std::cout << "Logging out......";
            std::cout << "\nPress any enter key to return.......";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid number";
            std::cout << "\nPress any enter key to return.......";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }

    } while (choice != 3);


}

void teacher_portal(user *u1) {

    int choice=0;
    u1 = new Teacher();

    do {
        system("cls");
        std::cout << "choose any operation " << std::endl;
        std::cout<< "\n1 :: login\n";
        std::cout << "2 :: signup\n";
        std::cout << "3 :: return to menu\n\n";

        std::cout << "Enter your choice ::";
        std::cin >> choice;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        bool flag;
        switch (choice) {

               case 1:
                
                   flag=u1->login(Teacher::credential_file_name);
                   if (flag) {
                       dashboard(u1);
                   }

                   break;

               case 2:
                   u1->signup(Teacher::credential_file_name);
                   break;
               case 3:    
                   delete u1;
                   break;
               default:
                   std::cout << "Invalid choice" << std::endl;
                   std::cout << "press any key to continue.........";
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (choice != 3);

}

void student_portal(user * u1){


    int choice = 0;
    u1 = new student();
    bool flag = false;

    do {
        system("cls");
        std::cout << "choose any operation " << std::endl;
        std::cout << "\n1 :: login\n";
        std::cout << "2 :: signup\n";
        std::cout << "3 :: return to menu\n\n";

        std::cout << "Enter your choice ::";
        std::cin >> choice;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {

        case 1:

            flag = u1->login(student::credential_file_name);
            if (flag) {
                dashboard(u1);
            }

            break;

        case 2:
            u1->signup(student::credential_file_name);
            break;
        case 3:
            delete u1;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            std::cout << "press any key to continue.........";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (choice != 3);

}

