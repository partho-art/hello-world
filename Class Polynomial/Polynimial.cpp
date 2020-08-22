#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial {
    public:
    int *degCoeff;      // Name of array (Don't change this)
    int capacity;
    // Complete the class
    public:
    Polynomial(){
        degCoeff = new int[5]; 
        capacity = 5 ; 
        for(int i= 0 ;i<5;i++){
            degCoeff[i]=0;
        }    
    }
    Polynomial(Polynomial const &p){
        capacity = p.capacity ; 
        degCoeff=new int[capacity];
        for(int i = 0 ; i < capacity ; i++){
            degCoeff[i] = p.degCoeff[i]; 
        }
    }
    void setCoefficient(int deg , int coeff){
        if(deg>=capacity){
            int *newdegCoeff = new int[deg+1]; 
            for(int i = 0 ; i< capacity ; i++){
                newdegCoeff[i] = degCoeff[i] ;
            }
            for(int i=capacity ; i<deg ; i++){
                newdegCoeff[i]=0;
            }
            delete[] degCoeff; 
            degCoeff = newdegCoeff; 
            capacity = deg+1 ; 
        }
        degCoeff[deg] = coeff ;     
    }
    Polynomial operator+(Polynomial p){
        Polynomial p3 ;
        p3.capacity = (capacity>=p.capacity)?capacity:p.capacity ; 
        delete [] p3.degCoeff ; 
        p3.degCoeff = new int[p3.capacity]; 
        for(int i = 0 ; i<p3.capacity ; i++){
            if(capacity>p.capacity){
               if(i<p.capacity){
                   p3.degCoeff[i]= degCoeff[i] + p.degCoeff[i];
               }
               else 
                   p3.degCoeff[i] = degCoeff[i]; 
            }
            else{
                if(i<capacity)
                    p3.degCoeff[i]=degCoeff[i] + p.degCoeff[i]; 
                else 
                    p3.degCoeff[i]=p.degCoeff[i]; 
            }
        }
        return p3; 
        
    }

    Polynomial operator-(Polynomial p){
        Polynomial p3 ;
        p3.capacity = (capacity>=p.capacity)?capacity:p.capacity ; 
        delete [] p3.degCoeff ; 
        p3.degCoeff = new int[p3.capacity]; 
        for(int i = 0 ; i<p3.capacity ; i++){
            if(capacity>p.capacity){
               if(i<p.capacity){
                   p3.degCoeff[i]= degCoeff[i] - p.degCoeff[i];
               }
               else 
                   p3.degCoeff[i] = degCoeff[i]; 
            }
            else{
                if(i<capacity)
                    p3.degCoeff[i]=degCoeff[i] - p.degCoeff[i]; 
                else 
                    p3.degCoeff[i]= -1*(p.degCoeff[i]); 
            }
        }
        return p3; 
        
    }
    Polynomial operator*(Polynomial p){
        Polynomial p3 ;
        p3.capacity = capacity + p.capacity ; 
        delete [] p3.degCoeff ; 
        p3.degCoeff = new int[p3.capacity]; 
        for(int i = 0 ; i<p3.capacity ; i++){
            p3.degCoeff[i] = 0;
        }
            for(int i = 0 ; i<p.capacity ; i++){
                for(int j= 0 ; j<capacity ; j++){
                    p3.degCoeff[i+j] += p.degCoeff[i]*degCoeff[j];  
                }
            }
        return p3 ; 
    }
    void operator=(Polynomial p){
        capacity = p.capacity ; 
        degCoeff=new int[capacity];
        for(int i = 0 ; i < capacity ; i++){
            degCoeff[i] = p.degCoeff[i]; 
        }        
    } 
    void print(){
        for(int i = 0 ;i<capacity ; i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i<<" "; 
            }
        }
        cout<<endl;
    }
};


/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations





//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
