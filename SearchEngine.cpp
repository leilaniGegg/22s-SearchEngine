//
// Created by leila on 4/12/2022.
//

#include "SearchEngine.h"

SearchEngine::SearchEngine(){
    printMenu();
    bool done = false;
    int choice;
    /*while(!done){
        //loop through, user can enter # to do different things, quits when they enter 5
        cout << "Please select an option from the menu." << endl;
        string tempChoice;
        getline(cin, tempChoice); // is it bad to use cin?
        choice = stoi(tempChoice);
        switch(choice){
            case 1:
                //menu 1 option
                break;
            case 2:
                //menu 2 option
                break;
            case 3:
                //menu 3 option
                break;
            case 4:
                //menu 4 option
                indexer.getWordIndex().deleteTree();
                break;
            case 5:
                //QUIT
                cout << "Done with Search Engine" << endl;
                done = true;
                break;
        }
        printMenu();
    }*/
}

void SearchEngine::printMenu(){
    cout << "Select a number from the following menu:" << endl;
    cout << "\t1. Read from documents" << endl;
    cout << "\t2. Read from persistence file" << endl;
    cout << "\t3. Enter a query" << endl;
    cout << "\t4. Clear the index" << endl;
    cout << "\t5. Quit" << endl << endl;
}

void SearchEngine::processCorpus(const string& directoryName){
    //docPars.readDirectory(directoryName, indexer);
    //indexer.writeWordIndexToFile();
    //indexer.getWordIndex().deleteTree();
    docPars.readPersistenceFile(indexer);
}

void SearchEngine::parseQuery(const string& request){
    // call function from QueryProcessor and send the request and indexer
    query.query(request, indexer);
    query.printMatches();
}