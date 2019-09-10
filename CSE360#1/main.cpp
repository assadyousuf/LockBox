#include "main.h"




int main(int argc, const char * argv[]) {
    string firstword;
    string secondword;
    string currentUsername;
    string currentKeyInsideDoor;
    string s;
    vector <string> validKeyList;
    vector <string> whosInside;
    string personAtDoor;
    string owner=argv[1];
    bool keyInserted = false,keyTurned,houseEntered=false;
    bool status=false;
    
    
    for(int i=2; i<=argc-1; i++){
        validKeyList.push_back(argv[i]);
    }
    validKeyList.push_back("FIREFIGHTER_SECRET_KEY");
    
    
    while(true){
        
        getline(cin,s);
        int numOfWords=wordCounter(s);
        
        if(s==""){ //quits program
            return 0;
        }
        
        
        stringstream stream(s);
        
        stream >> firstword;
        stream >> secondword;
        
        switch(input(firstword,secondword)){
            case -1:
                cout<<"ERROR\n";
                break;
                
            case 1:
                if(numOfWords != 4){
                    cout<<"ERROR\n";
                    break;
                }
                
                stream >> currentUsername;
                stream >> currentKeyInsideDoor;
                
                
                //make srue they are not inside when inserting key
                if(checkIfInside(whosInside, currentUsername)==true){
                    cout<<"ERROR\n";
                    break;
                }
                
                else{
                    
                    cout<< "KEY " << currentKeyInsideDoor << " INSERTED BY " << currentUsername << "\n";
                    
                    personAtDoor=currentUsername;
                    keyInserted=true;
                    break;
                    
                    
                }
                
            case 2:
                
                if(numOfWords != 3){
                    cout<<"ERROR\n";
                    break;
                }
                
                stream >> currentUsername;
                
                
                
                //make sure they are not inside when turning key
                if(checkIfInside(whosInside, currentUsername)==true){
                    cout << "FAILURE " << currentUsername << " UNABLE TO TURN KEY " <<currentKeyInsideDoor << "\n";
                    break;
                }
                
                else if(currentUsername==personAtDoor && validKey(validKeyList, currentKeyInsideDoor)==true && keyInserted==true ){
                    cout << "SUCCESS " << currentUsername <<  " TURNS KEY " << currentKeyInsideDoor << "\n";
                    keyTurned=true;
                    status=true;
                    break;
                }
                
                else {
                    
                    cout << "FAILURE " << currentUsername << " UNABLE TO TURN KEY " <<currentKeyInsideDoor << "\n";
                    break;
                }
                
                
                
                
            case 3:
                
                if(numOfWords != 3){
                    cout<<"ERROR\n";
                    break;
                }
                
                stream >> currentUsername;
                
                
                
                //make srue they are not inside when entering house
                if(checkIfInside(whosInside, currentUsername)==true){
                    cout << "ACCESS " << "DENIED\n";
                    break;
                }
                
                
                else if(validKey(validKeyList,currentKeyInsideDoor) && keyTurned==true && status==true){
                    cout << "ACCESS " << "ALLOWED\n";
                    whosInside.push_back(currentUsername);
                    
                    currentKeyInsideDoor="";
                    currentUsername="";
                    keyInserted=false;
                    keyTurned=false;
                    break;
                }
                
                else {
                    
                    cout << "ACCESS " << "DENIED\n";
                    break;
                }
                
                
            case 4:
                if(numOfWords != 2){
                    cout<<"ERROR\n";
                    break;
                }
                
                if(whosInside.size()==0){
                    cout << "NOBODY HOME\n";
                    break;
                }
                
                
                printWhoIsInside(whosInside);
                break;
                
                
                
                
            case 5:
                
                if(numOfWords != 3){
                    cout<<"ERROR\n";
                    break;
                }
                
                stream >> currentUsername;
                
                
                
                if(checkIfInside(whosInside, currentUsername)==true){
                    removeFromInisdeHouse(&whosInside, currentUsername);
                    cout << "OK\n";
                    break;
                }
                
                else {
                    cout << currentUsername << "NOT HERE\n";
                    break;
                }
                
                
                
            case 6:
                
                stream >> currentUsername;
                
                
                
                if(owner==currentUsername && checkIfInside(whosInside, owner) == true){
                    
                    
                    cout << "OK\n";
                    validKeyList.clear();
                    
                    string key;
                    stream >> key;
                    validKeyList.push_back(key);
                    
                    validKeyList.push_back("FIREFIGHTER_SECRET_KEY");
                    
                    while(stream >> key){
                        validKeyList.push_back(key);
                    }
                    
                    
                    
                }
                
                else {
                    cout << "ACCESS DENIED\n";
                }
                
                
                
                
                
        }
        
        
        
    }
    
    
}


bool checkIfInside(vector <string> whosInside, string name){
    
    if(whosInside.size()==0){
        return false;
    }
    
    for(int i=0; i<=whosInside.size()-1;i++){
        
        if (whosInside.at(i)==name) {
            return true;
        }
        
    }
    
    return false;
    
    
}


bool validKey(vector <string> validKeys,string key){
    
    
    for(int i=0; i<=validKeys.size()-1;i++){
        if(validKeys.at(i)==key){
            return true;
        }
        
    }
    
    return false;
    
}

void addKeysToVector(vector <string> *list){
    
    
}

int input(string firstword,string secondword){
    
    if(firstword=="INSERT" && secondword=="KEY"){
        return 1;
    }
    
    else if(firstword=="TURN" && secondword=="KEY"){
        return 2;
    }
    
    else if(firstword=="ENTER" && secondword=="HOUSE"){
        return 3;
        
    }
    
    else if(firstword=="WHO'S" && secondword=="INSIDE?"){
        return 4;
    }
    
    else if(firstword=="LEAVE" && secondword=="HOUSE"){
        return 5;
        
    }
    
    else if(firstword=="CHANGE" && secondword=="LOCKS"){
        return 6;
        
    }
    
    
    return -1;
    
    
}

void printWhoIsInside(vector <string> whosinside){
    
    for(int i=0; i<=whosinside.size()-1;i++){
        if(i==whosinside.size()-1){
            cout << whosinside.at(i) << "\n" ;
        }
        
        else {
            cout << whosinside.at(i) << ", ";
        }
    }
    
}

void removeFromInisdeHouse(vector <string> *whosInside, string name){
    
    for(int j=0; j<whosInside->size(); j++){
        if(whosInside->at(j)==name){
            //whosInside->erase(remove(whosInside->begin(), whosInside->end(), j),whosInside->end());
            whosInside->erase(whosInside->begin()+j);
        }
    }
    
    
}

int wordCounter(string line){
    stringstream x(line);
    string counter;
    int i=0;
    
    while(x>>counter){
        i++;
    }
    
    return i;
}





