#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
 
void output_n(std::ostream& _out, std::istream& _in){
    if(_in.fail() || _in.eof())
        return;
 
    std::istreambuf_iterator<char> p(_in), e;
    std::ostreambuf_iterator<char> d(_out);
    while((p != e) && !_in.fail()){
        _out << ' ';
        while((p != e) && (*p != '\n'))
            *d++ = *p++;
 
        if(p != e)
            *d++ = *p++;
    }
    _out.flush();
}
 
int main(void){
    //для примера ввод из строки вывод в консоль
    char s[] = "hello\nwtf\nhuina\nkak zaibalsa\nya progat na c++\n";
    std::istringstream sp(s);
    output_n(std::cout, sp);
 
    //ввод/вывод из файла
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    output_n(fout, fin);
    fin.close();
    fout.close();
    return 0;
}