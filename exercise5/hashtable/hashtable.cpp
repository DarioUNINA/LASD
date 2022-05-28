
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

template <typename Data>
ulong HashTable<Data>::HashKey(const Data& data) const noexcept{
  return ((A*(hash(data))+B)%prime)%dim;
}

}
