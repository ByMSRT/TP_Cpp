#include "../hpp/Exceptions.hpp"

const char* EmptyPotion::what() const throw(){
    return "Trying to drink an empty potion!";
}

const char* IllegalFury::what() const throw(){
    if(entering){
        return "Cannot enter fury twice !";
    }
    else {
        return "Cannot leave fury if not in fury !";
    }
}

const char* UnknownJob::what() const throw(){
    return "Class haven't been recognized, available classes : Barbarian / Mage / Priest";
}
