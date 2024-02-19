#include <bits/stdc++.h>
using namespace std;

//Function to display records
void display_records(vector<vector<string>> &contact){
    int n=contact[0].size();
    cout << "\tName\t\tContact Number\t\tE-mail" << endl;
    for(int i=0;i<n;i++){
        cout << "\t" <<contact[0][i] << "\t\t" << contact[1][i] << "\t\t" <<contact[2][i]  << endl;
    }
}

//Function to Save Phone number
vector<vector<string>> save_record(vector<vector<string>> &contact){
    string name1, num, mail ;
    cout << "Enter the Name: ";
    cin >> name1;
    contact[0].push_back(name1);
    cout << "Enter the Contact number: ";
    cin >> num;
    contact[1].push_back(num);
    cout << "Enter the E-mail: ";
    cin >> mail;
    contact[2].push_back(mail);
    
    //Sorting Contact list
     for (int i = 0; i < contact[0].size(); i++) {
        for (int j = i + 1; j < contact[0].size(); j++) {
            if (contact[0][j] < contact[0][i]) {
                string temp1 = contact[0][j];
                string temp2 = contact[1][j];
                string temp3 = contact[2][j];
                contact[0][j] = contact[0][i];
                contact[1][j]= contact[1][i];
                 contact[2][j]= contact[2][i];
                contact[0][i] = temp1;
                contact[1][i]= temp2;
                contact[2][i]= temp3;
            }
        }
    }
    cout << "\n--------------CONTACT LIST AFTER SAVING------------- " <<endl;
    display_records(contact);
    return contact;
}

//Funtion to search for contact
void search_record(vector<vector<string>> &contact){
    int flag=0;
    string name;
    cout << "Enter Name/Number to be searched: ";
    cin >> name;
    int n=name.size();
    for(int i=0;i<contact[0].size();i++){
        if((contact[0][i]).substr(0,n)==name || contact[1][i].substr(0,n)==name){
            if(flag==0) cout << "\tName\t\tContact \t\tEmai-Ids" << endl;
            flag=1;
            cout << "\t" << contact[0][i] << "\t\t" << contact[1][i] << "\t\t" << contact[2][i] << endl;
        }
    }
    if(flag==0){
        cout << "Contact Not Found!!" << endl;
    }
}
   
//Function to delete a contact
vector<vector<string>> delete_record(vector<vector<string>> &contact){
    int flag=0;
    string name;
    cout << "Enter Name/Number to be deleted: ";
    cin >> name;
    for(int i=0;i<contact[0].size();i++){
            flag=1;
            if(contact[0][i]==name || contact[1][i]==name){
                contact[0].erase(contact[0].begin()+i);
                contact[1].erase(contact[1].begin()+i);
                contact[2].erase(contact[2].begin()+i);
            }
    }
    if(flag==0){
        cout << "\tWrong input!!\tContact not found: ";
    }
    cout << "\n--------------CONTACT LIST AFTER DELETION------------- " <<endl;
    display_records(contact);
    return contact;
}

//Function to modify contact
vector<vector<string>> modify_record(vector<vector<string>> &contact){
    int search,flag=0;
    cout << "To Edit Name Press 1\nTo Edit number Press 2\nTo Edit E-mail Press 3" << endl;
    cin >> search;
    if (search==1){
        string name;
        cout << "Enter Name that has to be updated: ";
        cin >> name;
        int n=name.size();
        for(int i=0;i<contact[0].size();i++){
            if((contact[0][i]).substr(0,n)==name){
                flag=1;
                string Name;
                cout << "Enter new name of " << contact[0][i] << endl;
                cin >> Name;
                contact[0][i]=Name;
            }
        }
    }
    else if (search==2){
        string number;
        cout << "Enter number that has to be updated: ";
        cin >> number;
        int n=number.size();
        for(int i=0;i<contact[0].size();i++){
            if((contact[1][i]).substr(0,n)==number){
                flag=1;
                cout << "Enter New Number of " << contact[0][i] << endl;
                string Number;
                cin >> Number;
                contact[1][i]=Number;
            }
        }
    }
     else if (search==3){
        string mail;
        cout << "Enter E-mail that has to be updated: ";
        cin >> mail;
        int n=mail.size();
        for(int i=0;i<contact[2].size();i++){
            if((contact[2][i]).substr(0,n)==mail){
                flag=1;
                string email;
                cout << "Enter new E-mail of " << contact[0][i] << endl;
                cin >> email;
                contact[2][i]=email;
            }
        }
    }
    else{
        cout << "\tWrong Input!!\n ";
    }
    if(flag==0){
        cout << "Contact Not Found!!" << endl;
    }
    else{
        //Sorting Contact list
        for (int i = 0; i < contact[0].size(); i++) {
            for (int j = i + 1; j < contact[0].size(); j++) {
                if (contact[0][j] < contact[0][i]) {
                    string temp1 = contact[0][j];
                string temp2 = contact[1][j];
                string temp3 = contact[2][j];
                contact[0][j] = contact[0][i];
                contact[1][j]= contact[1][i];
                 contact[2][j]= contact[2][i];
                contact[0][i] = temp1;
                contact[1][i]= temp2;
                contact[2][i]= temp3;
                }
            }
        }
        cout << "\n--------------CONTACT LIST AFTER UPDATION------------- " <<endl;
        display_records(contact);
    }
    return contact;
}

string exit(){
    return "no";
}


int main() {
    vector<string> name={ 
    "Aarav","Aditi","Advait","Akshay","Aradhya","Aishwar","Ananya","Aniket","Aarushi","Arjun","Bhavya","Dhruv","Diya","Ishan","Isha","Kavya","Kiara","Krish","Mahi","Mira","Navya","Neil","Nisha","Nihari","Omkar","Pari","Parth","Prisha","Rahul","Rhea","Ritvik","Riya","Rohan","Saanvi","Samarth","Samaira","Shaan","Shanaya","Shiv","Siya","Soham","Sonia","Tanvi","Tanya","Utkarsh","Vansh","Vivaan","Yash","Yuvraj","Zara"};

    vector<string> number={"1234567890","2345678901","3456789012","4567890123","5678901234","6789012345", "7890123456","8901234567", "9012345678","0123456789","1023456789","1123456789", "1223456789", "1323456789", "1423456789",
    "1523456789", "1623456789", "1723456789", "1823456789", "1923456789",
    "2023456789", "2123456789", "2223456789", "2323456789", "2423456789",
    "2523456789", "2623456789", "2723456789", "2823456789", "2923456789",
    "3023456789", "3123456789", "3223456789", "3323456789", "3423456789",
    "3523456789", "3623456789", "3723456789", "3823456789", "3923456789",
    "4023456789", "4123456789", "4223456789", "4323456789", "4423456789",
    "4523456789", "4623456789", "4723456789", "4823456789","4923456789"};
    
    vector<string> email = {"aarav@gmail.com","aditi@gmail.com","advait@gmail.com","akshay@gmail.com","aaradhya@gmail.com", "aishwarya@gmail.com","ananya@gmail.com","aniket@gmail.com","aarushi@gmail.com","arjun@gmail.com","bhavya@gmail.com","dhruv@gmail.com","diya@gmail.com","ishan@gmail.com","isha@gmail.com","kavya@gmail.com","kiara@gmail.com","krish@gmail.com","mahi@gmail.com","mira@gmail.com","navya@gmail.com","neil@gmail.com","nisha@gmail.com","niharika@gmail.com","om@gmail.com","pari@gmail.com","parth@gmail.com","prisha@gmail.com","rahul@gmail.com","rhea@gmail.com","ritvik@gmail.com","riya@gmail.com","rohan@gmail.com","saanvi@gmail.com","samarth@gmail.com","samaira@gmail.com","shaan@gmail.com","shanaya@gmail.com","shiv@gmail.com","siya@gmail.com",    "soham@gmail.com","sonia@gmail.com","tanvi@gmail.com","tanya@gmail.com","utkarsh@gmail.com","vaishnavi@gmail.com","vivaan@gmail.com","yash@gmail.com","yuvraj@gmail.com","zara@gmail.com"};
    vector<vector<string>> contact={name,number,email};
    cout<<"............................................\n";
        cout<<"           PHONE BOOK MANAGEMENT\n";
        cout<<"............................................\n\n";
        cout<<"::::::::::::::: PROGRAM MENU :::::::::::::::\n";
        cout<<"1. Save New Phone Contact\n";
        cout<<"2. Display All Saved Records\n";
        cout<<"3. Search Contact\n";
        cout<<"4. Delete Contact\n";
        cout<<"5. Modify Existing Contact\n\n";
        int choice;
        cout<<" USER PLEASE ENTER THE CHOICE MENTIONED ABOVE : ";
        cin>>choice;
        switch (choice){
            case 1:contact=save_record(contact);break;
            case 2:display_records(contact);break;
            case 3:search_record(contact);break;
            case 4:contact=delete_record(contact);break;
            case 5:contact=modify_record(contact);break;
            default : cout<<"WRONG INPUT"; 
        }
        string ans="yes";
        cout << "\nPress Yes to continue or No to exit : ";
        cin >> ans;
        while (ans=="yes" || ans=="Yes" || ans=="YES"){
            cout<<"::::::::::::::: PROGRAM MENU :::::::::::::::\n";
            cout<<"1. Save New Phone Contact\n";
            cout<<"2. Display All Saved Records\n";
            cout<<"3. Search Contact\n";
            cout<<"4. Delete Contact\n";
            cout<<"5. Modify Existing Contact\n";
            cout<<"6. Exit\n\n";
            int choice;
            cout<<"PLEASE ENTER THE CHOICE TO PERFORM OPERATION YOU LIKE : ";
            cin>>choice;
            switch (choice){
                case 1:contact=save_record(contact);break;
                case 2:display_records(contact);break;
                case 3:search_record(contact);break;
                case 4:contact=delete_record(contact);break;
                case 5:contact=modify_record(contact);break;
                case 6:ans=exit();break;
                default : cout<<"WRONG INPUT"; 
            }
        }
    return 0;
}
