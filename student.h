#pragma once
#include<string>
#include<fstream>

class user {

	private:
		std::string name;
		std::string username;
		std::string email_id;
		std::string password;

	public:

		void set_name(std::string name);
		void set_username(std::string username);
		void set_email_id(std::string email_id);
		void set_password(std::string password);

		std::string get_username();
		std::string get_email_id();
		std::string get_password();
		std::string get_name();

		bool login(std::string file_name);
		void signup(std::string file_name);
		void forgot_password(std::string file_name);
		virtual void load_data()=0;
		virtual void set_data() = 0;
		virtual void display_data()=0;
		virtual void update_data()=0;

};


class Teacher : public user {

	private:
		int id;
		int no_of_students;
		std::string designation;
		std::string class_name;
		std::fstream data;

	public:
		inline static const std::string credential_file_name="teacher_credentials.txt";
		void load_data();
		void set_data();
		void display_data();
		void update_data();
		int getId();
		void setId(int);
		int getNo_of_students();
		void setNo_of_students(int);
		std::string getDesignation();
		void setDesignation(std::string);
		std::string getClass_name();
		void setClass_name(std::string);

};

class student :public user {

	private:
		int roll_no;
		std::string class1;
		std::string division;
		int prn_no;
		std::fstream data;

    public:
		inline static const std::string credential_file_name = "student_credentials.txt";
		void load_data();
		void set_data();
		void display_data();
		void update_data();
		int GetRoll_no();
		void SetRoll_no(int roll_no);
		std::string GetClass1();
		void SetClass1(std::string class1);
		std::string GetDivision();
		void SetDivision(std::string division);
		int GetPrn_no();
		void SetPrn_no(int prn_no);

};






