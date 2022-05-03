//
// Created by leila on 4/12/2022.
//

#include "SearchEngine.h"

SearchEngine::SearchEngine(){
    bool done = false;
    int choice;
    while(!done){
        //loop through, user can enter # to do different things, quits when they enter 7
        printMenu();
        string tempChoice;
        cout << "Enter Number: ";
        getline(cin, tempChoice); // is it bad to use cin?
        choice = stoi(tempChoice);
        switch(choice){
            case 1: {
                //menu 1 option
                //for 6000 data set it would be ../testdata
                docPars.readDirectory("../data/2018_01_112b52537b67659ad3609a234388c50a", indexer);
                cout << "Data set parsed" << endl;
                break;
            }
            case 2: {
                //menu 2 option
                docPars.readWordPersistenceFile(indexer);
                docPars.readPersonPersistenceFile(indexer);
                docPars.readOrgPersistenceFile(indexer);
                docPars.readArticleTextPersistenceFile(indexer);
                cout << "Persistence Files read" << endl;
                break;
            }
            case 3: {
                //menu 3 option
                indexer.writeWordIndexToFile();
                indexer.writePersonIndexToFile();
                indexer.writeOrgIndexToFile();
                indexer.writeArticleTextToFile();
                cout << "Indexes written to file" << endl;
                break;
            }
            case 4: {
                //menu 3 option
                string temp;
                cout << "Enter a query: ";
                getline(cin, temp);
                parseQuery(temp);
                break;
            }
            case 5: {
                //menu 4 option
                //clear the index
                indexer.getWordIndex().deleteTree();
                indexer.getPersonIndex().clearHashTable();
                indexer.getOrgIndex().clearHashTable();
                break;
            }
            case 6: {
                //menu 6 option
                //stats
                cout << "**" << docPars.getArticleCount() << " articles indexed" << endl;
                cout << "**" << indexer.getWordIndex().getNodeCount() << " words" << endl;
                cout << "**" << indexer.getPersonIndex().sizeOf() << " people" << endl;
                cout << "**" << indexer.getOrgIndex().sizeOf() << " organizations" << endl;
                break;
            }
            case 7: {
                //QUIT
                cout << "Done with Search Engine" << endl;
                cout << "Bye Bye! :)" << endl;
                done = true;
                break;
            }
            default:
                cout << "Incorrect Entry. Try Again. " << endl;
        }
    }
}

void SearchEngine::printMenu(){
    cout << "Select a number from the following menu:" << endl;
    cout << "\t1. Read from documents" << endl;
    cout << "\t2. Read from persistence file" << endl;
    cout << "\t3. Write to persistence file" << endl;
    cout << "\t4. Enter a query" << endl;
    cout << "\t5. Clear the index" << endl;
    cout << "\t6. Display Statistics" << endl;
    cout << "\t7. Quit" << endl << endl;
}


void SearchEngine::parseQuery(const string& request){
    // call function from QueryProcessor and send the request and indexer
    start = std::chrono::high_resolution_clock::now();
    query.query(request, indexer);
    query.printMatches();
    end = std::chrono::high_resolution_clock::now();
    cout << endl << query.getSize() << " articles in " << std::chrono::duration<double>(end-start).count()
         << " seconds." << endl;

    string tempChoice;
    int choice;
    bool done = false;
    while(!done) {
        cout << "\nEnter a number corresponding to a article to see the text (-1 to quit): ";
        getline(cin, tempChoice);
        choice = stoi(tempChoice);
        if(choice == -1){
            done = true;
        }
        else {
            int count = 1;
            for (auto itr = query.getMatches().begin(); itr != query.getMatches().end(); itr++, count++) {
                if (count == choice) {
                    itr->printArticleText(indexer.getArticleText());
                }
            }
        }
    }
}