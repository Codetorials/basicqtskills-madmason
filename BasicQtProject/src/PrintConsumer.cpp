
#include "PrintConsumer.h"

#include <iostream>

#include <QVariant>

namespace basicQt {



PrintConsumer::PrintConsumer(QVariant data){
    m_data = data;
}

void PrintConsumer::run(){
    std::cerr << m_data.String << std::endl;
}


}
