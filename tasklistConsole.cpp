/******************************
    Author: Michael Giardina
    Date created: 04 Aug 2022
    Date updated: 07 Aug 2022
    Purpose: A program that allows the user to 
                create a list of tasks that
                must be done
    Language: C++ 12.1.0
    Known bugs: 
        None
******************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class tasks
{
    public:
        void addTask()
        {
            //Ask the user for input
            cout << "Please enter the task you want to add: ";
            
            //Use ignore to ensure the first word is not skipped
            cin.ignore();

            //Get the input from the user and store it in a vector
            getline(cin, task);
            taskList.push_back(task);

            return;
        }

        void displayTask()
        {

            //Make sure the vector is not empty
            if (!taskList.empty())
            {
                //Create a loop to go through the vector and 
                //  print out it's contents
                for (i = 0; i < taskList.size(); ++i)
                {
                    cout << i + 1 << "." << taskList[i] << "\n";
                }
            }
            else
            {
                cout << "You have no chores yet";
            }
            
            return;
        }

        void removeTask()
        {
            //Ask the user for an input, this will be the number that is removed 
            //  from the vector
            cout << "Please enter the number for the task that was completed: ";
            
            //Make sure the input is an integer
            while (!(cin >> completed))
            {
                cout << "That is not a valid integer\n";
                cin.clear();
                cin.ignore(100, '\n');
                return;
            }

            if (completed < taskList.size() + 1 && completed > 0)
            {
                cout << taskList[completed - 1] << " has been removed from the list\n";
                //Use erase to remove the task from the vector
                taskList.erase(taskList.begin() + completed - 1);
            }
            else 
            {
                cout << "That is not a valid choice\n";
            }

            return;
        }

        void startUp()
        {
            //Initialize the file
            ifstream file("taskList.txt");

            //While there are still lines to read, push the line
            //  to the end of a vector
            while (getline(file, input))
            {
                taskList.push_back(input);
            }

            return;
        }

        void ending()
        {
            //Initialize the file
            ofstream file("taskList.txt");

            //Create a for loop to iterate through the file and 
            //  store it's contents into a file
            for(i = 0; i < taskList.size(); ++i)
            {
                file << taskList[i] << "\n";
            }
            
            //Close the file
            file.close();

            return;
        }
        
    private:
        vector <string> taskList;
        string task;
        string input;
        int completed = 0;
        int i = 0;
};

int main (void)
{
    string choice;
    tasks tasks;
    string input;
    
    tasks.startUp();

    cout << "What would you like to do?\n";

    do{
        cout << "1)Add task\n2)Display list\n3)Remove task\n4)Quit\n";

        cin >> choice;
     
        if (choice == "1")
            tasks.addTask();
        else if (choice == "2")
            tasks.displayTask();
        else if (choice == "3")
            tasks.removeTask();
        else if (choice == "4")
        {
            cout << "\nHave a great day!\n";
            tasks.ending();
        }
        else 
        {
            cout << "That is not a valid choice, please try again\n";
        }

        cout << "\n****************************************************\n";
    } while (choice != "4");

    return 0;
}