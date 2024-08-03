#include "random_vector.h"
// TODO: add any include you might require
#include<cstdlib>

RandomVector::RandomVector(int size, double max_val) { 
  // TODO: Write your code here
  for (int i=1; i<=size; ++i){
    vect.push_back((double)rand()/(max_val*RAND_MAX));  
  }
}

void RandomVector::print(){
  // TODO: Write your code here
  for (auto &elem: vect){
    std::cout << elem << " ";
  }
  std::cout << std::endl;    
}

double RandomVector::mean(){
  // TODO: Write your code here
  double sum=0;
  for (unsigned int i=0; i<vect.size();++i){
    sum+=vect.at(i);
  }
  return sum/vect.size();
}

double RandomVector::max(){
  // TODO: Write your code here
  double vect_max=vect.at(0);
  for (unsigned int i=0; i<vect.size()-1;++i){
    if(vect.at(i)>vect_max){
      vect_max=vect.at(i);
    }
  }
  return vect_max;
}


double RandomVector::min(){
  //TODO:  Write your code here
  double vect_min=vect.at(0);
  for (unsigned int i=0; i<vect.size();++i){
    if(vect.at(i)<vect_min){
      vect_min=vect.at(i);
    }
  }
  return vect_min;
}

void RandomVector::printHistogram(int bins){
  // TODO: Write your code here
  double temp;
  unsigned int diff=int((max()-min())/bins);

  //Increasing Sorted Vector
  for (unsigned int i=0; i<vect.size()-1;++i){
    for (unsigned int j=i+1; j<vect.size();++i){
      if(vect.at(j)<vect.at(i)){
        temp=vect.at(i);
        vect.at(i)=vect.at(j);
        vect.at(j)=temp;
      }
    }
  }
  print();
  for(unsigned int i=0;i<vect.size()-1;++i){
    for(unsigned int j=i*diff;j<min()+(i+1)*diff;++i){
      std::cout<<"***"<<std::endl;
    }
    std::cout<<'\t';
  }  
}
