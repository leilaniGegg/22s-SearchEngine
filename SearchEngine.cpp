//
// Created by leila on 4/12/2022.
//

#include "SearchEngine.h"

void SearchEngine::processCorpus(const string& directoryName){
    docPars.open_dir_using_filesystem(directoryName, indexer);
}