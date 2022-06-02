
namespace lasd {

/* ************************************************************************** */

template <>
class Hash<int> {

public:

  ulong operator()(const int& data) const noexcept{
      return data*data;
  }

};


template <>
class Hash<double> {

public:

  ulong operator()(const double& data) const noexcept{
      long integer = floor(data);
      long fract = pow(2, 24)*(data - integer);
      
      return integer*fract;
  }

};


template <>
class Hash<std::string> {

public:

  ulong operator()(const std::string& data) const noexcept{
      ulong hash = 0;
      for(ulong i=0; i<data.size();++i)
        hash += static_cast<ulong>(data[i]);

      return hash;
  }

};


/* ************************************************************************** */
/* ************************************************************************** */

// Auciliary Member Function

template <typename Data>
ulong HashTable<Data>::HashKey(const Data& data) const noexcept{
  return ((A*(hash(data))+B)%prime)%dim;
}


/* ************************************************************************** */

// Print Function

template <typename Data>
void MapPrint(const Data& key, void* value){
    std::cout << key << ", ";
}


template <typename Data>
void HashTable<Data>::Print() noexcept{
  std::cout<<"The elements of the Hash Table are:\n";
  this->Map(MapPrint<Data>, 0);
}

}
