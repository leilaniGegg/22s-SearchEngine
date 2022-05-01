//
// Created by leila on 4/12/2022.
//

#include "SearchEngine.h"

SearchEngine::SearchEngine(){
    printMenu();
    bool done = false;
    int choice;
    while(!done){
        //loop through, user can enter # to do different things, quits when they enter 5
        string tempChoice;
        cout << "Enter Number: ";
        getline(cin, tempChoice); // is it bad to use cin?
        choice = stoi(tempChoice);
        switch(choice){
            case 1:
                //menu 1 option
                docPars.readDirectory("../testdata", indexer);
                indexer.writeWordIndexToFile();
                indexer.writePersonIndexToFile();
                indexer.writeOrgIndexToFile();
                break;
            case 2:
                //menu 2 option
                docPars.readPersistenceFile(indexer);
                cout << "Persistence File read" << endl;
                break;
            case 3: {
                //menu 3 option
                string temp;
                cout << "Enter a query: ";
                getline(cin, temp);
                parseQuery(temp);
                break;
            }
            case 4:
                //menu 4 option
                indexer.getWordIndex().deleteTree();
                break;
            case 5:
                //stats
            case 6: {
                //QUIT
                cout << "Done with Search Engine" << endl;
                done = true;
                break;
            }
            default:
                cout << "Incorrect Entry. Try Again. " << endl;
        }
        printMenu();
    }
}

void SearchEngine::printMenu(){
    cout << "Select a number from the following menu:" << endl;
    cout << "\t1. Read from documents" << endl;
    cout << "\t2. Read from persistence file" << endl;
    cout << "\t3. Enter a query" << endl;
    cout << "\t4. Clear the index" << endl;
    cout << "\t5. Display Statistics" << endl;
    cout << "\t6. Quit" << endl << endl;
}

void SearchEngine::processCorpus(const string& directoryName){
    /*docPars.readDirectory(directoryName, indexer);
    indexer.writeWordIndexToFile();
    indexer.getWordIndex().deleteTree();
    docPars.readPersistenceFile(indexer);*/
}

void SearchEngine::parseQuery(const string& request){
    // call function from QueryProcessor and send the request and indexer
    start = std::chrono::high_resolution_clock::now();
    query.query(request, indexer);
    query.printMatches();
    end = std::chrono::high_resolution_clock::now();
    cout << query.getSize() << " articles in " << std::chrono::duration<double>(end-start).count()
         << " seconds." << endl;
}