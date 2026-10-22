#include <iostream>

int getSUM(int first, int last);
void COMPARE(int first, int last);
bool box(bool first, bool last);

int main() {

    std:: cout << getSUM(6,7)<<std::endl;
    COMPARE(7,11);
    box(true,false);
    return 0;
}


int getSUM(int first, int last) {
    return first + last;
}
void COMPARE(int first, int last) {
    if (first > last) {
        std::cout << first << " is greater than " << last << std::endl;
    }
    else if (last >  first) {
        std::cout << last << " is greater than " << first << std::endl;
    }
    
}
bool box(bool first, bool last) {
    std::cout << first << " AND " << last << " = " << (first && last) << std ::endl;
    std::cout << first << " OR " << last << " = " << (first || last) << std ::endl;
    std::cout << "NOT " << first << " = " << !(first) << std::endl;     
    std::cout << "NOT " << last << " = " << !(first) << std::endl;
    return true;
}