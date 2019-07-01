#include <algorithm>
#include <string>
#include <fstream>
#include <stdio.h>

#include "Collection.hpp"

extern Memory memory;
int Collection::insert(const std::string &key, const std::string &value)
{
    int64_t size = (key.length()+value.length())*sizeof(char);
    if(!memory.can_allocate(size))
        return -1;
    memory.allocate(size);
    KeyValue p(key, value);
    collection.push_back(p);
    return 0;
}

void Collection::sort()
{
    std::sort(collection.begin(), collection.end());
}

static int getNext(std::ifstream &rfile, KeyValue &kvp)
{
    std::string key;
    if(getline(rfile, key, ' ')) {
        std::string value;
        getline(rfile, value);
        kvp.setKey(key);
        kvp.setValue(value);
        return 0;
    }
    rfile.close();
    return -1;
}

void Collection::KWayMerge()
{
    std::vector<std::ifstream> streams;
    streams.resize(partnum);
    for(int i = 0; i < partnum; i++) {
        streams[i].open("/tmp/part-"+std::to_string(i));
        KeyValue kvp;
        if(getNext(streams[i], kvp) != -1) {
            std::cout << "Pushing into pq" << std::endl;
            pq.push({kvp, i});
        }
    }

    std::string fname = "/tmp/final"; // + std::to_string(partnum++);
    std::ofstream ofs;
    ofs.open (fname, std::ofstream::out | std::ofstream::app);

    while(!pq.empty()) {
        auto pkv = pq.top();
        pq.pop();
        std::cout << pkv.first.getKey() << " " << pkv.second << std::endl;
        ofs << pkv.first.getKey() << " " << pkv.first.getValue() << std::endl;
        if(getNext(streams[pkv.second], pkv.first) != -1)
            pq.push(pkv); 
    }

    for(int i = 0; i < partnum; i++)
       remove(("/tmp/part-"+std::to_string(i)).c_str());

    ofs.close();
}

void Collection::write()
{
    std::string fname = "/tmp/part-" + std::to_string(partnum++);
    std::ofstream ofs;
    ofs.open (fname, std::ofstream::out | std::ofstream::app);

    for(auto kvp:collection) {
        ofs << kvp.getKey() << " " << kvp.getValue() << std::endl;
        memory.release(kvp.getSize());
    }

    ofs.close();
    collection.clear();
}
