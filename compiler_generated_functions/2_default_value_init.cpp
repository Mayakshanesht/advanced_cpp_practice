# include <vector>
#include <iostream>
using namespace std;
class X {
public:
      int i;
      vector<double> v;
      double* p;
};
int main() {
X x1; // default initialization
cout<<x1.i<<'\n'<<x1.p<<endl;
//cout<<x1.v[0]<<endl;
X x2{}; // value initialization
cout<<x2.i<<'\n'<<x2.p<<endl;
return 0;
// Its always preffered to have the value initialization over the default initialization
}
