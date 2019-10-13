// Copyright year qingxuan pei pqx97@bu.edu
// Copyright year cagri yoruk cyoruk@bu.edu
#include <vector>
using namespace std;
//include "polyops.cpp"
typedef vector<double> Poly;

Poly add_poly(const Poly &a,const Poly &b) {
    vector<double> a1;
    vector<double> b1;
    vector<double> vec;
    int len1 = a.size();
    int len2 = b.size();
    if (len1 < len2) {
        for (int i = 0; i < len2; i++) {
            a1.push_back(b.at(i));
        }
        for (int i = 0; i < len1; i++) {
            b1.push_back(a.at(i));
        }
        int swap1 = len1;
        len1 = len2;
        len2 = swap1;
    }
    else {
        for (int i = 0; i < len1; i++) {
            a1.push_back(a.at(i));
        }
        for (int i = 0; i < len2; i++) {
            b1.push_back(b.at(i));
        }
    }
    for(int i = 0;i < len2;i++){
        double sum = a1.at(i) + b1.at(i);
        vec.push_back(sum);
    }
    for(int i = len2;i<len1;i++){
        vec.push_back(a1.at(i));
    }
    while(vec.at(vec.size()-1) == 0 and vec.size()>1){
        vec.pop_back();
    }
    return vec;
}

Poly multiply_poly(const Poly &a,const Poly &b) {
    int len1 = a.size();
    int len2 = b.size();
    double sum = 0;
    Poly m;
    for(int i = 0;i<len1 + len2 - 1; i++){
        m.push_back(0);
    }
    //vector < vector<double> > vec;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (i + j < len1 + len2 - 1) {
                double right = a.at(i) * b.at(j);
                m.at(i + j) += right;
            }
        }
    }
    while(m.at(m.size()-1) == 0 and m.size()>1){
        m.pop_back();
    }
    return m;
    /*

    
    for (int i = 0; i < len1 + len2 - 1; i++) {
        m.pop_back();
        return m;
    }
       */
}
int main()
{ 

  int Alen,Blen;

  cin >> Alen >> Blen;

  Poly A(Alen,0),B(Blen,0);

  for (auto& e : A)
     cin >> e;
  
  for (auto& e : B)
     cin >> e;

  for (auto e : add_poly(A,B))
     cout << e << " ";
  cout << endl;


  for (auto e : multiply_poly(A,B))
     cout << e << " ";
  cout << endl;  


}
