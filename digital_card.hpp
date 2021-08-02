/* Copyright 2021 Dinu Ion-Irinel */

#ifndef _DIGITAL_CARD_HPP_
#define _DIGITAL_CARD_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/* class of a digital_card */
class DigitalCard {

private:
    /* attributes */
    std::string first_name;
    std::string last_name;
    int age;
    std::vector<std::string> subjects;
    std::vector<std::vector<int>> marks;

public:

    // constructor
    DigitalCard() {
        this->first_name = "";
        this->last_name = "";
        this->age = 0;
        this->marks.resize(1001);
    }

    /* getters and setters */
    void SetFirstname(std::string first_name) {
        this->first_name = first_name;
    }

    std::string GetFirstname() {
        return this->first_name;
    }

    void SetLastname(std::string last_name) {
        this->last_name = last_name;
    }

    std::string GetLastname() {
        return this->last_name;
    }

    void SetAge(int age) {
        this->age = age;
    }

    int GetAge() {
        return this->age;
    }

    /* the function that add a new subject in card */
    void AddSubject(std::string new_subject) {
        /* check if the new_subject exist in subjects card */
        bool exist = false;
        for (auto subject:subjects) {
            if (subject == new_subject) {
                exist = true;
                break;
            }
        }
        /* add a new subject */
        if (exist == false) {
            subjects.push_back(new_subject);
        }
    }

    /* the function that list all subjects */
    void ListSubjects() {
        std::cout << "Your current subjects: \n";
        for (auto subject:subjects) {
            std::cout << subject << "\n";
        }
    }

    /* the function that add a new mark to a subject */
    void AddMark(std::string subject, int mark) {
        int position = 0, index = -1;
        /* find the position of the subject needed */
        for (auto current_subject:subjects) {
            if (current_subject == subject) {
                index = position;
            }
            position++;
        }
        if (index != -1) {
            marks[index].push_back(mark);
        }
    }

    /* the function that list all marks of a subject */
    void ListMarks(std::string subject) {
        int position = 0, index = -1;
        /* find the position of the subject needed */
        for (auto current_subject:subjects) {
            if (current_subject == subject) {
                index = position;
            }
            position++;
        }
        std::cout << subject << "\n";
        std::cout << "Current marks: ";
        if (index != -1) {
            /* list all marks */
            for (auto mark:marks[index]) {
                std::cout << mark << " ";
            }
            std::cout << "\n";
        }
    }
};

 /* the function that print menu and take inputs */
    void card_menu() {
        DigitalCard digital_card;
    
        /* set first_name */
        std::string first_name;
        std::cout << "Enter your firstname: ";
        std::cin >> first_name;
        std::cout << "\n";
        digital_card.SetFirstname(first_name);

        /* set last name */
        std::string last_name;
        std::cout << "Enter your lastname: ";
        std::cin >> last_name;
        std::cout << "\n";
        digital_card.SetLastname(last_name);

        /* set age */
        int age;
        std::cout << "Enter your age: ";
        std::cin >> age;
        std::cout << "\n";
        digital_card.SetAge(age);

        /* adding subjects */
        int number_subjects;
        std::cout << "Enter a number of subject that you want to add: ";
        std::cin >> number_subjects;
        std::cout << "\n";
        for (int i = 0; i < number_subjects; ++i) {
            std::string new_subject;
            std::cout << "Enter the name of the subject: ";
            std::cin >> new_subject;
            std::cout << "\n";
            digital_card.AddSubject(new_subject); 
        }

        /* adding marks */
        std::string subject;
        std::cout << "Enter the name of subject for adding marks: ";
        std::cin >> subject;
        int mark;
        std::cout << "Now, enter the mark: ";
        std::cin >> mark;
        digital_card.AddMark(subject, mark);
        
        /* clear console */
        std::cout << "\x1B[2J\x1B[H";

        /* loop menu */
        while (true) {
            std::cout << "1.Display account informations:  press 1\n";
            std::cout << "2.Add a new subject              press 2\n";
            std::cout << "3.See marks of a subject         press 3\n";
            std::cout << "4.Add a new mark                 press 4\n";
            std::cout << "5.EXIT                           press 5\n";
            int input;
            std::cin >> input;
            if (input == 1) {
                /* display all informations */
                std::cout << "Account Informations: " << "\n";
                std::cout << digital_card.GetFirstname() << "\n";
                std::cout << digital_card.GetLastname() << "\n";
                std::cout << digital_card.GetAge() << "\n";
                digital_card.ListSubjects();

            } else if (input == 2) {
                /* add a new subject */
                std::string new_subject;
                std::cout << "Enter a new subject:\n";
                std::cin >> new_subject;
                digital_card.AddSubject(new_subject);

            } else if (input == 3) {
                /* display marks */
                std::string subject;
                std::cout << "Enter the name of the subject:\n";
                std::cin >> subject;
                digital_card.ListMarks(subject);

            } else if (input == 4) {
                /* add a mark */
                std::string subject;
                int mark;
                std::cout << "Please, now enter the subject:";
                std::cin >> subject;
                std::cout <<"And now, enter a mark:\n";
                std::cin >> mark;
                digital_card.AddMark(subject, mark);
               
            } else if (input == 5) {
                /* stop the program */
                return;
            }
        }
    }

#endif // _DIGITAL_CARD_HPP_ 

